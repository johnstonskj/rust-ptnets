
const STRING_CHAR = /([^\x00-\x08\x0B-\x1F\x7F"\\\\])|\\\\(["\\\\abefnrtv\/]|u\{[0-9a-fA-F]{2,6}\})/;

function keyword(str) {
    return token(
        prec(2, str)
    );
}

function operator(str) {
    return token(
        prec(1, str)
    );
}

module.exports = grammar({
    name: 'ptnet',

    //word: $ => $.name,

    // -----------------------------------------------------------------------
    // Whitespace
    // -----------------------------------------------------------------------

    extras: $ => [
        /\s/,
        $.line_comment
    ],

    rules: {
        // -----------------------------------------------------------------------
        // Top-Level
        // -----------------------------------------------------------------------
        source_file: $ => $._top_level,

        _top_level: $ => choice(
            $.net_def,
            $.marking_def,
        ),

        // -----------------------------------------------------------------------
        // Identifier/Name
        // -----------------------------------------------------------------------

        name: $ => /[a-zA-Zα-ωΑ-Ωµ_][a-zA-Zα-ωΑ-Ωµ0-9_]*/,

        _name_list: $ => seq(
            field('name', $.name),
            repeat(
                seq(
                    ',',
                    field('name', $.name),
                )
            ),
        ),

        // -----------------------------------------------------------------------
        // Net
        // -----------------------------------------------------------------------
        net_def: $ => seq(
            keyword('net'),
            field('name', $.name),
            $._net_body,
        ),

        _net_body: $ => seq(
            $._block_start,
            optional($.label_property),
            optional($.defaults),
            optional($._token_def),
            repeat($._node_or_arc),
            optional($.initial_marking_def),
            $._block_end
        ),

        _block_start: $ => token('{'),
        _block_end: $ => token('}'),

        defaults: $ => seq(
            keyword('defaults'),
            $._block_start,
            repeat1($._default_constraints),
            $._block_end
        ),

        _default_constraints: $ => choice(
            $.capacity_constraint,
            $.duration_constraint,
            $.priority_constraint,
            $.weight_constraint,
        ),

        _token_def: $ => seq(
            keyword('tokens'),
            $._token_set
        ),

        _token_set: $ => choice(
            $.token_set_boolean,
            $.token_set_natural,
            $.token_set_positive,
            $.token_set_def
        ),

        token_set_boolean: $ => 'B',
        token_set_natural: $ => 'N',
        token_set_positive: $ => 'N+',

        token_set_def: $ => seq(
            $.name,
            operator('='),
            choice(
                $.tuple_type,
                $.set_type
            )
        ),

        tuple_type: $ => seq(
            '(',
            $.name,
            repeat1(
                seq(
                    ',',
                    $.name
                )
            ),
            ')'
        ),

        set_type: $ => seq(
            '{',
            $.name,
            repeat1(
                seq(
                    ',',
                    $.name
                )
            ),
            '}'
        ),

        _node_or_arc: $ => choice(
            $.subnet_def,
            $.place_def,
            $.transition_def,
            $.arc_def,
        ),

        initial_marking_def: $ => seq(
            keyword('initial'),
            $.marking_def,
        ),

        // -----------------------------------------------------------------------
        // Sub-nets
        // -----------------------------------------------------------------------
        subnet_def: $ => seq(
            keyword('net'),
            field('name', $.name),
            $._subnet_body,
        ),

        _subnet_body: $ => seq(
            $._block_start,
            optional($.label_property),
            optional($.defaults),
            optional($.public_places),
            repeat($._node_or_arc),
            $._block_end
        ),

        public_places: $ => seq(
            keyword('public'),
            $.name,
            repeat(
                seq(
                    ',',
                    $.name
                )
            )
        ),

        // -----------------------------------------------------------------------
        // Places
        // -----------------------------------------------------------------------
        place_def: $ => seq(
            keyword('place'),
            $._name_list,
            optional(
                field(
                    'body',
                    $.place_body
                )
            )
        ),

        place_body: $ => seq(
            $._block_start,
            optional($.label_property),
            optional($.capacity_constraint),
            $._block_end
        ),

        // -----------------------------------------------------------------------
        // Transitions
        // -----------------------------------------------------------------------
        transition_def: $ => seq(
            keyword('transition'),
            $._name_list,
            optional(
                field(
                    'body',
                    $.transition_body
                )
            )
        ),

        transition_body: $ => seq(
            $._block_start,
            optional($.label_property),
            optional($.duration_constraint),
            optional($.priority_constraint),
            $._block_end
        ),

        // -----------------------------------------------------------------------
        // Arcs
        // -----------------------------------------------------------------------
       arc_def: $ => seq(
           keyword('arc'),
            $.arc_expression,
            optional(
                field(
                    'body',
                    $.arc_body
                )
            )
       ),

        arc_expression: $ => choice(
            seq(
                field('source', $.arc_name_or_expression),
                repeat(
                    seq(
                        ',',
                        field('source', $.arc_name_or_expression),
                    )
                ),
                repeat1(
                    seq(
                        $._arc_type,
                        field('target', $.arc_name_or_expression),
                        repeat(
                            seq(
                                ',',
                                field('target', $.arc_name_or_expression),
                            )
                        )
                    )
                )
            ),
        ),

        arc_name_or_expression: $ => choice(
            $.name,
            seq(
                '(',
                $.arc_expression,
                ')',
            )
        ),

        arc_body: $ => seq(
            $._block_start,
            optional($.label_property),
            optional($.weight_constraint),
            $._block_end
        ),

        _arc_type: $ => choice(
            $.normal_arc,
            $.inhibitor_arc,
            $.reset_arc
        ),

        normal_arc: $ => token('->'),

        inhibitor_arc: $ => token('-inhibitor>'),

        reset_arc: $ => token('-reset>'),

        // -----------------------------------------------------------------------
        // Properties and Constraints
        // -----------------------------------------------------------------------
        label_property: $ => seq(
            'label',
            operator('='),
            $.quoted_string
        ),
        weight_constraint: $ => seq(
            'weight',
            operator('='),
            $.value_expr
        ),

        priority_constraint: $ => seq(
            'priority',
            operator('='),
            $.unsigned
        ),

        capacity_constraint: $ => seq(
            'capacity',
            operator('='),
            $.value_expr
        ),

        duration_constraint: $ => seq(
            'duration',
            operator('='),
            choice(
                $.duration_immediate,
                $.duration_fixed,
                $.duration_interval,
            )
        ),

        duration_immediate: $ => '!',

        duration_fixed: $ => $.positive_unsigned,

        duration_interval: $ => seq(
            choice('[', '('),
            field('lower', $.positive_unsigned),
            ',',
            field('upper', $.positive_unsigned),
            choice(']', ')')
        ),

        // -----------------------------------------------------------------------
        // Marking
        // -----------------------------------------------------------------------
        marking_def: $ => seq(
            keyword('marking'),
            $._block_start,
            repeat1($.marking_assignment),
            $._block_end
        ),

        marking_assignment: $ => seq(
            field('place_name', $.name),
            operator('='),
            field('marking', $.value_expr)
        ),

        value_expr: $ => seq(
            field('value', $._value),
            optional(
                seq(
                    '*',
                    field('count', $.unsigned)
                )
            )
        ),

        _value: $ => choice(
            $.boolean,
            $.unsigned,
            $.infinity,
            $.quoted_string
            //$.tuple_value,
            //$.set_value
        ),

        boolean: $ => choice(
            keyword('true'),
            keyword('false')
        ),

        infinity: $ => keyword('inf'),

        unsigned: $ => /0|[1-9][0-9]*/,

        positive_unsigned: $ => /[1-9][0-9]*/,

        quoted_string: $ => token(
            seq(
                token.immediate('"'),
                repeat(STRING_CHAR),
                token.immediate('"'),
            )
        ),

        // -----------------------------------------------------------------------
        // Comments
        // -----------------------------------------------------------------------

        line_comment: $ => token(
            prec(
                0,
                seq(
                    '//',
                    /.*/
                )
            )
        )
    }
});
