#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 173
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 87
#define ALIAS_COUNT 0
#define TOKEN_COUNT 39
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 10
#define MAX_ALIAS_SEQUENCE_LENGTH 7
#define PRODUCTION_ID_COUNT 19

enum {
  sym_name = 1,
  anon_sym_COMMA = 2,
  anon_sym_net = 3,
  anon_sym_LBRACE = 4,
  anon_sym_RBRACE = 5,
  anon_sym_defaults = 6,
  anon_sym_tokens = 7,
  sym_token_set_boolean = 8,
  sym_token_set_natural = 9,
  sym_token_set_positive = 10,
  anon_sym_EQ = 11,
  anon_sym_LPAREN = 12,
  anon_sym_RPAREN = 13,
  anon_sym_initial = 14,
  anon_sym_public = 15,
  anon_sym_place = 16,
  anon_sym_transition = 17,
  anon_sym_arc = 18,
  sym_normal_arc = 19,
  sym_inhibitor_arc = 20,
  sym_reset_arc = 21,
  anon_sym_label = 22,
  anon_sym_weight = 23,
  anon_sym_priority = 24,
  anon_sym_capacity = 25,
  anon_sym_duration = 26,
  sym_duration_immediate = 27,
  anon_sym_LBRACK = 28,
  anon_sym_RBRACK = 29,
  anon_sym_marking = 30,
  anon_sym_STAR = 31,
  anon_sym_true = 32,
  anon_sym_false = 33,
  sym_infinity = 34,
  sym_unsigned = 35,
  sym_positive_unsigned = 36,
  sym_quoted_string = 37,
  sym_line_comment = 38,
  sym_source_file = 39,
  sym__top_level = 40,
  sym__name_list = 41,
  sym_net_def = 42,
  sym__net_body = 43,
  sym__block_start = 44,
  sym__block_end = 45,
  sym_defaults = 46,
  sym__default_constraints = 47,
  sym__token_def = 48,
  sym__token_set = 49,
  sym_token_set_def = 50,
  sym_tuple_type = 51,
  sym_set_type = 52,
  sym__node_or_arc = 53,
  sym_initial_marking_def = 54,
  sym_subnet_def = 55,
  sym__subnet_body = 56,
  sym_public_places = 57,
  sym_place_def = 58,
  sym_place_body = 59,
  sym_transition_def = 60,
  sym_transition_body = 61,
  sym_arc_def = 62,
  sym_arc_expression = 63,
  sym_arc_name_or_expression = 64,
  sym_arc_body = 65,
  sym__arc_type = 66,
  sym_label_property = 67,
  sym_weight_constraint = 68,
  sym_priority_constraint = 69,
  sym_capacity_constraint = 70,
  sym_duration_constraint = 71,
  sym_duration_fixed = 72,
  sym_duration_interval = 73,
  sym_marking_def = 74,
  sym_marking_assignment = 75,
  sym_value_expr = 76,
  sym__value = 77,
  sym_boolean = 78,
  aux_sym__name_list_repeat1 = 79,
  aux_sym__net_body_repeat1 = 80,
  aux_sym_defaults_repeat1 = 81,
  aux_sym_tuple_type_repeat1 = 82,
  aux_sym_arc_expression_repeat1 = 83,
  aux_sym_arc_expression_repeat2 = 84,
  aux_sym_arc_expression_repeat3 = 85,
  aux_sym_marking_def_repeat1 = 86,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_name] = "name",
  [anon_sym_COMMA] = ",",
  [anon_sym_net] = "net",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [anon_sym_defaults] = "defaults",
  [anon_sym_tokens] = "tokens",
  [sym_token_set_boolean] = "token_set_boolean",
  [sym_token_set_natural] = "token_set_natural",
  [sym_token_set_positive] = "token_set_positive",
  [anon_sym_EQ] = "=",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [anon_sym_initial] = "initial",
  [anon_sym_public] = "public",
  [anon_sym_place] = "place",
  [anon_sym_transition] = "transition",
  [anon_sym_arc] = "arc",
  [sym_normal_arc] = "normal_arc",
  [sym_inhibitor_arc] = "inhibitor_arc",
  [sym_reset_arc] = "reset_arc",
  [anon_sym_label] = "label",
  [anon_sym_weight] = "weight",
  [anon_sym_priority] = "priority",
  [anon_sym_capacity] = "capacity",
  [anon_sym_duration] = "duration",
  [sym_duration_immediate] = "duration_immediate",
  [anon_sym_LBRACK] = "[",
  [anon_sym_RBRACK] = "]",
  [anon_sym_marking] = "marking",
  [anon_sym_STAR] = "*",
  [anon_sym_true] = "true",
  [anon_sym_false] = "false",
  [sym_infinity] = "infinity",
  [sym_unsigned] = "unsigned",
  [sym_positive_unsigned] = "positive_unsigned",
  [sym_quoted_string] = "quoted_string",
  [sym_line_comment] = "line_comment",
  [sym_source_file] = "source_file",
  [sym__top_level] = "_top_level",
  [sym__name_list] = "_name_list",
  [sym_net_def] = "net_def",
  [sym__net_body] = "_net_body",
  [sym__block_start] = "_block_start",
  [sym__block_end] = "_block_end",
  [sym_defaults] = "defaults",
  [sym__default_constraints] = "_default_constraints",
  [sym__token_def] = "_token_def",
  [sym__token_set] = "_token_set",
  [sym_token_set_def] = "token_set_def",
  [sym_tuple_type] = "tuple_type",
  [sym_set_type] = "set_type",
  [sym__node_or_arc] = "_node_or_arc",
  [sym_initial_marking_def] = "initial_marking_def",
  [sym_subnet_def] = "subnet_def",
  [sym__subnet_body] = "_subnet_body",
  [sym_public_places] = "public_places",
  [sym_place_def] = "place_def",
  [sym_place_body] = "place_body",
  [sym_transition_def] = "transition_def",
  [sym_transition_body] = "transition_body",
  [sym_arc_def] = "arc_def",
  [sym_arc_expression] = "arc_expression",
  [sym_arc_name_or_expression] = "arc_name_or_expression",
  [sym_arc_body] = "arc_body",
  [sym__arc_type] = "_arc_type",
  [sym_label_property] = "label_property",
  [sym_weight_constraint] = "weight_constraint",
  [sym_priority_constraint] = "priority_constraint",
  [sym_capacity_constraint] = "capacity_constraint",
  [sym_duration_constraint] = "duration_constraint",
  [sym_duration_fixed] = "duration_fixed",
  [sym_duration_interval] = "duration_interval",
  [sym_marking_def] = "marking_def",
  [sym_marking_assignment] = "marking_assignment",
  [sym_value_expr] = "value_expr",
  [sym__value] = "_value",
  [sym_boolean] = "boolean",
  [aux_sym__name_list_repeat1] = "_name_list_repeat1",
  [aux_sym__net_body_repeat1] = "_net_body_repeat1",
  [aux_sym_defaults_repeat1] = "defaults_repeat1",
  [aux_sym_tuple_type_repeat1] = "tuple_type_repeat1",
  [aux_sym_arc_expression_repeat1] = "arc_expression_repeat1",
  [aux_sym_arc_expression_repeat2] = "arc_expression_repeat2",
  [aux_sym_arc_expression_repeat3] = "arc_expression_repeat3",
  [aux_sym_marking_def_repeat1] = "marking_def_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_name] = sym_name,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_net] = anon_sym_net,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [anon_sym_defaults] = anon_sym_defaults,
  [anon_sym_tokens] = anon_sym_tokens,
  [sym_token_set_boolean] = sym_token_set_boolean,
  [sym_token_set_natural] = sym_token_set_natural,
  [sym_token_set_positive] = sym_token_set_positive,
  [anon_sym_EQ] = anon_sym_EQ,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_initial] = anon_sym_initial,
  [anon_sym_public] = anon_sym_public,
  [anon_sym_place] = anon_sym_place,
  [anon_sym_transition] = anon_sym_transition,
  [anon_sym_arc] = anon_sym_arc,
  [sym_normal_arc] = sym_normal_arc,
  [sym_inhibitor_arc] = sym_inhibitor_arc,
  [sym_reset_arc] = sym_reset_arc,
  [anon_sym_label] = anon_sym_label,
  [anon_sym_weight] = anon_sym_weight,
  [anon_sym_priority] = anon_sym_priority,
  [anon_sym_capacity] = anon_sym_capacity,
  [anon_sym_duration] = anon_sym_duration,
  [sym_duration_immediate] = sym_duration_immediate,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [anon_sym_marking] = anon_sym_marking,
  [anon_sym_STAR] = anon_sym_STAR,
  [anon_sym_true] = anon_sym_true,
  [anon_sym_false] = anon_sym_false,
  [sym_infinity] = sym_infinity,
  [sym_unsigned] = sym_unsigned,
  [sym_positive_unsigned] = sym_positive_unsigned,
  [sym_quoted_string] = sym_quoted_string,
  [sym_line_comment] = sym_line_comment,
  [sym_source_file] = sym_source_file,
  [sym__top_level] = sym__top_level,
  [sym__name_list] = sym__name_list,
  [sym_net_def] = sym_net_def,
  [sym__net_body] = sym__net_body,
  [sym__block_start] = sym__block_start,
  [sym__block_end] = sym__block_end,
  [sym_defaults] = sym_defaults,
  [sym__default_constraints] = sym__default_constraints,
  [sym__token_def] = sym__token_def,
  [sym__token_set] = sym__token_set,
  [sym_token_set_def] = sym_token_set_def,
  [sym_tuple_type] = sym_tuple_type,
  [sym_set_type] = sym_set_type,
  [sym__node_or_arc] = sym__node_or_arc,
  [sym_initial_marking_def] = sym_initial_marking_def,
  [sym_subnet_def] = sym_subnet_def,
  [sym__subnet_body] = sym__subnet_body,
  [sym_public_places] = sym_public_places,
  [sym_place_def] = sym_place_def,
  [sym_place_body] = sym_place_body,
  [sym_transition_def] = sym_transition_def,
  [sym_transition_body] = sym_transition_body,
  [sym_arc_def] = sym_arc_def,
  [sym_arc_expression] = sym_arc_expression,
  [sym_arc_name_or_expression] = sym_arc_name_or_expression,
  [sym_arc_body] = sym_arc_body,
  [sym__arc_type] = sym__arc_type,
  [sym_label_property] = sym_label_property,
  [sym_weight_constraint] = sym_weight_constraint,
  [sym_priority_constraint] = sym_priority_constraint,
  [sym_capacity_constraint] = sym_capacity_constraint,
  [sym_duration_constraint] = sym_duration_constraint,
  [sym_duration_fixed] = sym_duration_fixed,
  [sym_duration_interval] = sym_duration_interval,
  [sym_marking_def] = sym_marking_def,
  [sym_marking_assignment] = sym_marking_assignment,
  [sym_value_expr] = sym_value_expr,
  [sym__value] = sym__value,
  [sym_boolean] = sym_boolean,
  [aux_sym__name_list_repeat1] = aux_sym__name_list_repeat1,
  [aux_sym__net_body_repeat1] = aux_sym__net_body_repeat1,
  [aux_sym_defaults_repeat1] = aux_sym_defaults_repeat1,
  [aux_sym_tuple_type_repeat1] = aux_sym_tuple_type_repeat1,
  [aux_sym_arc_expression_repeat1] = aux_sym_arc_expression_repeat1,
  [aux_sym_arc_expression_repeat2] = aux_sym_arc_expression_repeat2,
  [aux_sym_arc_expression_repeat3] = aux_sym_arc_expression_repeat3,
  [aux_sym_marking_def_repeat1] = aux_sym_marking_def_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym_name] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_net] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_defaults] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_tokens] = {
    .visible = true,
    .named = false,
  },
  [sym_token_set_boolean] = {
    .visible = true,
    .named = true,
  },
  [sym_token_set_natural] = {
    .visible = true,
    .named = true,
  },
  [sym_token_set_positive] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_initial] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_public] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_place] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_transition] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_arc] = {
    .visible = true,
    .named = false,
  },
  [sym_normal_arc] = {
    .visible = true,
    .named = true,
  },
  [sym_inhibitor_arc] = {
    .visible = true,
    .named = true,
  },
  [sym_reset_arc] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_label] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_weight] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_priority] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_capacity] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_duration] = {
    .visible = true,
    .named = false,
  },
  [sym_duration_immediate] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_LBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_marking] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_STAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_true] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_false] = {
    .visible = true,
    .named = false,
  },
  [sym_infinity] = {
    .visible = true,
    .named = true,
  },
  [sym_unsigned] = {
    .visible = true,
    .named = true,
  },
  [sym_positive_unsigned] = {
    .visible = true,
    .named = true,
  },
  [sym_quoted_string] = {
    .visible = true,
    .named = true,
  },
  [sym_line_comment] = {
    .visible = true,
    .named = true,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym__top_level] = {
    .visible = false,
    .named = true,
  },
  [sym__name_list] = {
    .visible = false,
    .named = true,
  },
  [sym_net_def] = {
    .visible = true,
    .named = true,
  },
  [sym__net_body] = {
    .visible = false,
    .named = true,
  },
  [sym__block_start] = {
    .visible = false,
    .named = true,
  },
  [sym__block_end] = {
    .visible = false,
    .named = true,
  },
  [sym_defaults] = {
    .visible = true,
    .named = true,
  },
  [sym__default_constraints] = {
    .visible = false,
    .named = true,
  },
  [sym__token_def] = {
    .visible = false,
    .named = true,
  },
  [sym__token_set] = {
    .visible = false,
    .named = true,
  },
  [sym_token_set_def] = {
    .visible = true,
    .named = true,
  },
  [sym_tuple_type] = {
    .visible = true,
    .named = true,
  },
  [sym_set_type] = {
    .visible = true,
    .named = true,
  },
  [sym__node_or_arc] = {
    .visible = false,
    .named = true,
  },
  [sym_initial_marking_def] = {
    .visible = true,
    .named = true,
  },
  [sym_subnet_def] = {
    .visible = true,
    .named = true,
  },
  [sym__subnet_body] = {
    .visible = false,
    .named = true,
  },
  [sym_public_places] = {
    .visible = true,
    .named = true,
  },
  [sym_place_def] = {
    .visible = true,
    .named = true,
  },
  [sym_place_body] = {
    .visible = true,
    .named = true,
  },
  [sym_transition_def] = {
    .visible = true,
    .named = true,
  },
  [sym_transition_body] = {
    .visible = true,
    .named = true,
  },
  [sym_arc_def] = {
    .visible = true,
    .named = true,
  },
  [sym_arc_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_arc_name_or_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_arc_body] = {
    .visible = true,
    .named = true,
  },
  [sym__arc_type] = {
    .visible = false,
    .named = true,
  },
  [sym_label_property] = {
    .visible = true,
    .named = true,
  },
  [sym_weight_constraint] = {
    .visible = true,
    .named = true,
  },
  [sym_priority_constraint] = {
    .visible = true,
    .named = true,
  },
  [sym_capacity_constraint] = {
    .visible = true,
    .named = true,
  },
  [sym_duration_constraint] = {
    .visible = true,
    .named = true,
  },
  [sym_duration_fixed] = {
    .visible = true,
    .named = true,
  },
  [sym_duration_interval] = {
    .visible = true,
    .named = true,
  },
  [sym_marking_def] = {
    .visible = true,
    .named = true,
  },
  [sym_marking_assignment] = {
    .visible = true,
    .named = true,
  },
  [sym_value_expr] = {
    .visible = true,
    .named = true,
  },
  [sym__value] = {
    .visible = false,
    .named = true,
  },
  [sym_boolean] = {
    .visible = true,
    .named = true,
  },
  [aux_sym__name_list_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__net_body_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_defaults_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_tuple_type_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_arc_expression_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_arc_expression_repeat2] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_arc_expression_repeat3] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_marking_def_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum {
  field_body = 1,
  field_count = 2,
  field_lower = 3,
  field_marking = 4,
  field_name = 5,
  field_place_name = 6,
  field_source = 7,
  field_target = 8,
  field_upper = 9,
  field_value = 10,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_body] = "body",
  [field_count] = "count",
  [field_lower] = "lower",
  [field_marking] = "marking",
  [field_name] = "name",
  [field_place_name] = "place_name",
  [field_source] = "source",
  [field_target] = "target",
  [field_upper] = "upper",
  [field_value] = "value",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 1},
  [3] = {.index = 2, .length = 1},
  [4] = {.index = 3, .length = 2},
  [5] = {.index = 5, .length = 1},
  [6] = {.index = 6, .length = 2},
  [7] = {.index = 8, .length = 2},
  [8] = {.index = 10, .length = 1},
  [9] = {.index = 11, .length = 2},
  [10] = {.index = 13, .length = 2},
  [11] = {.index = 15, .length = 1},
  [12] = {.index = 16, .length = 1},
  [13] = {.index = 17, .length = 2},
  [14] = {.index = 19, .length = 3},
  [15] = {.index = 22, .length = 2},
  [16] = {.index = 24, .length = 2},
  [17] = {.index = 26, .length = 2},
  [18] = {.index = 28, .length = 2},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_name, 1},
  [1] =
    {field_name, 0},
  [2] =
    {field_name, 1, .inherited = true},
  [3] =
    {field_marking, 2},
    {field_place_name, 0},
  [5] =
    {field_value, 0},
  [6] =
    {field_name, 0},
    {field_name, 1, .inherited = true},
  [8] =
    {field_body, 2},
    {field_name, 1, .inherited = true},
  [10] =
    {field_body, 2},
  [11] =
    {field_source, 0},
    {field_target, 1, .inherited = true},
  [13] =
    {field_name, 0, .inherited = true},
    {field_name, 1, .inherited = true},
  [15] =
    {field_source, 1},
  [16] =
    {field_target, 1},
  [17] =
    {field_source, 0, .inherited = true},
    {field_source, 1, .inherited = true},
  [19] =
    {field_source, 0},
    {field_source, 1, .inherited = true},
    {field_target, 2, .inherited = true},
  [22] =
    {field_target, 0, .inherited = true},
    {field_target, 1, .inherited = true},
  [24] =
    {field_count, 2},
    {field_value, 0},
  [26] =
    {field_target, 1},
    {field_target, 2, .inherited = true},
  [28] =
    {field_lower, 1},
    {field_upper, 3},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 35,
  [36] = 36,
  [37] = 37,
  [38] = 38,
  [39] = 39,
  [40] = 40,
  [41] = 41,
  [42] = 42,
  [43] = 43,
  [44] = 44,
  [45] = 45,
  [46] = 45,
  [47] = 47,
  [48] = 48,
  [49] = 49,
  [50] = 50,
  [51] = 49,
  [52] = 52,
  [53] = 53,
  [54] = 54,
  [55] = 55,
  [56] = 56,
  [57] = 57,
  [58] = 58,
  [59] = 59,
  [60] = 60,
  [61] = 61,
  [62] = 62,
  [63] = 63,
  [64] = 64,
  [65] = 65,
  [66] = 66,
  [67] = 67,
  [68] = 68,
  [69] = 69,
  [70] = 70,
  [71] = 71,
  [72] = 72,
  [73] = 73,
  [74] = 74,
  [75] = 75,
  [76] = 76,
  [77] = 77,
  [78] = 78,
  [79] = 79,
  [80] = 80,
  [81] = 81,
  [82] = 82,
  [83] = 83,
  [84] = 84,
  [85] = 85,
  [86] = 86,
  [87] = 87,
  [88] = 88,
  [89] = 89,
  [90] = 90,
  [91] = 91,
  [92] = 92,
  [93] = 93,
  [94] = 94,
  [95] = 95,
  [96] = 96,
  [97] = 97,
  [98] = 98,
  [99] = 99,
  [100] = 100,
  [101] = 101,
  [102] = 102,
  [103] = 103,
  [104] = 104,
  [105] = 105,
  [106] = 106,
  [107] = 107,
  [108] = 108,
  [109] = 63,
  [110] = 110,
  [111] = 111,
  [112] = 112,
  [113] = 113,
  [114] = 114,
  [115] = 61,
  [116] = 96,
  [117] = 117,
  [118] = 118,
  [119] = 119,
  [120] = 120,
  [121] = 121,
  [122] = 122,
  [123] = 123,
  [124] = 124,
  [125] = 125,
  [126] = 126,
  [127] = 127,
  [128] = 128,
  [129] = 129,
  [130] = 130,
  [131] = 131,
  [132] = 132,
  [133] = 133,
  [134] = 134,
  [135] = 135,
  [136] = 136,
  [137] = 137,
  [138] = 138,
  [139] = 139,
  [140] = 140,
  [141] = 141,
  [142] = 142,
  [143] = 143,
  [144] = 144,
  [145] = 145,
  [146] = 146,
  [147] = 147,
  [148] = 148,
  [149] = 149,
  [150] = 150,
  [151] = 151,
  [152] = 152,
  [153] = 153,
  [154] = 154,
  [155] = 155,
  [156] = 156,
  [157] = 157,
  [158] = 158,
  [159] = 159,
  [160] = 160,
  [161] = 161,
  [162] = 162,
  [163] = 163,
  [164] = 164,
  [165] = 165,
  [166] = 166,
  [167] = 167,
  [168] = 168,
  [169] = 169,
  [170] = 165,
  [171] = 162,
  [172] = 154,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(108);
      if (lookahead == '!') ADVANCE(217);
      if (lookahead == '"') ADVANCE(3);
      if (lookahead == '(') ADVANCE(197);
      if (lookahead == ')') ADVANCE(198);
      if (lookahead == '*') ADVANCE(221);
      if (lookahead == ',') ADVANCE(187);
      if (lookahead == '-') ADVANCE(6);
      if (lookahead == '/') ADVANCE(5);
      if (lookahead == '0') ADVANCE(225);
      if (lookahead == '=') ADVANCE(196);
      if (lookahead == 'B') ADVANCE(193);
      if (lookahead == 'N') ADVANCE(194);
      if (lookahead == '[') ADVANCE(218);
      if (lookahead == ']') ADVANCE(219);
      if (lookahead == 'a') ADVANCE(167);
      if (lookahead == 'c') ADVANCE(109);
      if (lookahead == 'd') ADVANCE(125);
      if (lookahead == 'f') ADVANCE(110);
      if (lookahead == 'i') ADVANCE(156);
      if (lookahead == 'l') ADVANCE(111);
      if (lookahead == 'm') ADVANCE(115);
      if (lookahead == 'n') ADVANCE(126);
      if (lookahead == 'p') ADVANCE(153);
      if (lookahead == 't') ADVANCE(162);
      if (lookahead == 'w') ADVANCE(130);
      if (lookahead == '{') ADVANCE(189);
      if (lookahead == '}') ADVANCE(190);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(226);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 1:
      if (lookahead == '!') ADVANCE(217);
      if (lookahead == '(') ADVANCE(197);
      if (lookahead == '/') ADVANCE(5);
      if (lookahead == 'B') ADVANCE(193);
      if (lookahead == 'N') ADVANCE(194);
      if (lookahead == '[') ADVANCE(218);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(1)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(227);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 2:
      if (lookahead == '"') ADVANCE(3);
      if (lookahead == ')') ADVANCE(198);
      if (lookahead == '*') ADVANCE(221);
      if (lookahead == ',') ADVANCE(187);
      if (lookahead == '-') ADVANCE(6);
      if (lookahead == '/') ADVANCE(5);
      if (lookahead == '0') ADVANCE(225);
      if (lookahead == 'a') ADVANCE(76);
      if (lookahead == 'c') ADVANCE(10);
      if (lookahead == 'd') ADVANCE(32);
      if (lookahead == 'f') ADVANCE(11);
      if (lookahead == 'i') ADVANCE(65);
      if (lookahead == 'l') ADVANCE(13);
      if (lookahead == 'm') ADVANCE(17);
      if (lookahead == 'n') ADVANCE(33);
      if (lookahead == 'p') ADVANCE(59);
      if (lookahead == 't') ADVANCE(71);
      if (lookahead == 'w') ADVANCE(36);
      if (lookahead == '{') ADVANCE(189);
      if (lookahead == '}') ADVANCE(190);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(2)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(226);
      END_STATE();
    case 3:
      if (lookahead == '"') ADVANCE(228);
      if (lookahead == '\\') ADVANCE(9);
      if (lookahead != 0 &&
          lookahead > 8 &&
          (lookahead < 11 || 31 < lookahead) &&
          lookahead != 127) ADVANCE(3);
      END_STATE();
    case 4:
      if (lookahead == '(') ADVANCE(197);
      if (lookahead == '*') ADVANCE(221);
      if (lookahead == '/') ADVANCE(5);
      if (lookahead == '}') ADVANCE(190);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(4)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 5:
      if (lookahead == '/') ADVANCE(229);
      END_STATE();
    case 6:
      if (lookahead == '>') ADVANCE(204);
      if (lookahead == 'i') ADVANCE(63);
      if (lookahead == 'r') ADVANCE(27);
      END_STATE();
    case 7:
      if (lookahead == '>') ADVANCE(206);
      END_STATE();
    case 8:
      if (lookahead == '>') ADVANCE(205);
      END_STATE();
    case 9:
      if (lookahead == '\\') ADVANCE(96);
      END_STATE();
    case 10:
      if (lookahead == 'a') ADVANCE(75);
      END_STATE();
    case 11:
      if (lookahead == 'a') ADVANCE(62);
      END_STATE();
    case 12:
      if (lookahead == 'a') ADVANCE(97);
      END_STATE();
    case 13:
      if (lookahead == 'a') ADVANCE(22);
      END_STATE();
    case 14:
      if (lookahead == 'a') ADVANCE(25);
      END_STATE();
    case 15:
      if (lookahead == 'a') ADVANCE(67);
      if (lookahead == 'u') ADVANCE(28);
      END_STATE();
    case 16:
      if (lookahead == 'a') ADVANCE(26);
      END_STATE();
    case 17:
      if (lookahead == 'a') ADVANCE(78);
      END_STATE();
    case 18:
      if (lookahead == 'a') ADVANCE(57);
      END_STATE();
    case 19:
      if (lookahead == 'a') ADVANCE(94);
      END_STATE();
    case 20:
      if (lookahead == 'b') ADVANCE(45);
      END_STATE();
    case 21:
      if (lookahead == 'b') ADVANCE(60);
      END_STATE();
    case 22:
      if (lookahead == 'b') ADVANCE(34);
      END_STATE();
    case 23:
      if (lookahead == 'c') ADVANCE(203);
      END_STATE();
    case 24:
      if (lookahead == 'c') ADVANCE(200);
      END_STATE();
    case 25:
      if (lookahead == 'c') ADVANCE(31);
      END_STATE();
    case 26:
      if (lookahead == 'c') ADVANCE(49);
      END_STATE();
    case 27:
      if (lookahead == 'e') ADVANCE(83);
      END_STATE();
    case 28:
      if (lookahead == 'e') ADVANCE(222);
      END_STATE();
    case 29:
      if (lookahead == 'e') ADVANCE(87);
      END_STATE();
    case 30:
      if (lookahead == 'e') ADVANCE(223);
      END_STATE();
    case 31:
      if (lookahead == 'e') ADVANCE(201);
      END_STATE();
    case 32:
      if (lookahead == 'e') ADVANCE(38);
      if (lookahead == 'u') ADVANCE(79);
      END_STATE();
    case 33:
      if (lookahead == 'e') ADVANCE(86);
      END_STATE();
    case 34:
      if (lookahead == 'e') ADVANCE(58);
      END_STATE();
    case 35:
      if (lookahead == 'e') ADVANCE(69);
      END_STATE();
    case 36:
      if (lookahead == 'e') ADVANCE(44);
      END_STATE();
    case 37:
      if (lookahead == 'f') ADVANCE(224);
      if (lookahead == 'i') ADVANCE(93);
      END_STATE();
    case 38:
      if (lookahead == 'f') ADVANCE(12);
      END_STATE();
    case 39:
      if (lookahead == 'g') ADVANCE(220);
      END_STATE();
    case 40:
      if (lookahead == 'g') ADVANCE(42);
      END_STATE();
    case 41:
      if (lookahead == 'h') ADVANCE(43);
      END_STATE();
    case 42:
      if (lookahead == 'h') ADVANCE(89);
      END_STATE();
    case 43:
      if (lookahead == 'i') ADVANCE(20);
      END_STATE();
    case 44:
      if (lookahead == 'i') ADVANCE(40);
      END_STATE();
    case 45:
      if (lookahead == 'i') ADVANCE(88);
      END_STATE();
    case 46:
      if (lookahead == 'i') ADVANCE(73);
      END_STATE();
    case 47:
      if (lookahead == 'i') ADVANCE(24);
      END_STATE();
    case 48:
      if (lookahead == 'i') ADVANCE(68);
      END_STATE();
    case 49:
      if (lookahead == 'i') ADVANCE(90);
      END_STATE();
    case 50:
      if (lookahead == 'i') ADVANCE(91);
      END_STATE();
    case 51:
      if (lookahead == 'i') ADVANCE(18);
      END_STATE();
    case 52:
      if (lookahead == 'i') ADVANCE(72);
      END_STATE();
    case 53:
      if (lookahead == 'i') ADVANCE(74);
      END_STATE();
    case 54:
      if (lookahead == 'i') ADVANCE(95);
      END_STATE();
    case 55:
      if (lookahead == 'k') ADVANCE(35);
      END_STATE();
    case 56:
      if (lookahead == 'k') ADVANCE(48);
      END_STATE();
    case 57:
      if (lookahead == 'l') ADVANCE(199);
      END_STATE();
    case 58:
      if (lookahead == 'l') ADVANCE(207);
      END_STATE();
    case 59:
      if (lookahead == 'l') ADVANCE(14);
      if (lookahead == 'r') ADVANCE(52);
      if (lookahead == 'u') ADVANCE(21);
      END_STATE();
    case 60:
      if (lookahead == 'l') ADVANCE(47);
      END_STATE();
    case 61:
      if (lookahead == 'l') ADVANCE(92);
      END_STATE();
    case 62:
      if (lookahead == 'l') ADVANCE(84);
      END_STATE();
    case 63:
      if (lookahead == 'n') ADVANCE(41);
      END_STATE();
    case 64:
      if (lookahead == 'n') ADVANCE(202);
      END_STATE();
    case 65:
      if (lookahead == 'n') ADVANCE(37);
      END_STATE();
    case 66:
      if (lookahead == 'n') ADVANCE(215);
      END_STATE();
    case 67:
      if (lookahead == 'n') ADVANCE(85);
      END_STATE();
    case 68:
      if (lookahead == 'n') ADVANCE(39);
      END_STATE();
    case 69:
      if (lookahead == 'n') ADVANCE(81);
      END_STATE();
    case 70:
      if (lookahead == 'o') ADVANCE(77);
      END_STATE();
    case 71:
      if (lookahead == 'o') ADVANCE(55);
      if (lookahead == 'r') ADVANCE(15);
      END_STATE();
    case 72:
      if (lookahead == 'o') ADVANCE(80);
      END_STATE();
    case 73:
      if (lookahead == 'o') ADVANCE(66);
      END_STATE();
    case 74:
      if (lookahead == 'o') ADVANCE(64);
      END_STATE();
    case 75:
      if (lookahead == 'p') ADVANCE(16);
      END_STATE();
    case 76:
      if (lookahead == 'r') ADVANCE(23);
      END_STATE();
    case 77:
      if (lookahead == 'r') ADVANCE(8);
      END_STATE();
    case 78:
      if (lookahead == 'r') ADVANCE(56);
      END_STATE();
    case 79:
      if (lookahead == 'r') ADVANCE(19);
      END_STATE();
    case 80:
      if (lookahead == 'r') ADVANCE(50);
      END_STATE();
    case 81:
      if (lookahead == 's') ADVANCE(192);
      END_STATE();
    case 82:
      if (lookahead == 's') ADVANCE(191);
      END_STATE();
    case 83:
      if (lookahead == 's') ADVANCE(29);
      END_STATE();
    case 84:
      if (lookahead == 's') ADVANCE(30);
      END_STATE();
    case 85:
      if (lookahead == 's') ADVANCE(54);
      END_STATE();
    case 86:
      if (lookahead == 't') ADVANCE(188);
      END_STATE();
    case 87:
      if (lookahead == 't') ADVANCE(7);
      END_STATE();
    case 88:
      if (lookahead == 't') ADVANCE(70);
      END_STATE();
    case 89:
      if (lookahead == 't') ADVANCE(209);
      END_STATE();
    case 90:
      if (lookahead == 't') ADVANCE(98);
      END_STATE();
    case 91:
      if (lookahead == 't') ADVANCE(99);
      END_STATE();
    case 92:
      if (lookahead == 't') ADVANCE(82);
      END_STATE();
    case 93:
      if (lookahead == 't') ADVANCE(51);
      END_STATE();
    case 94:
      if (lookahead == 't') ADVANCE(46);
      END_STATE();
    case 95:
      if (lookahead == 't') ADVANCE(53);
      END_STATE();
    case 96:
      if (lookahead == 'u') ADVANCE(100);
      if (lookahead == '"' ||
          lookahead == '/' ||
          lookahead == '\\' ||
          lookahead == 'a' ||
          lookahead == 'b' ||
          lookahead == 'e' ||
          lookahead == 'f' ||
          lookahead == 'n' ||
          lookahead == 'r' ||
          ('t' <= lookahead && lookahead <= 'v')) ADVANCE(3);
      END_STATE();
    case 97:
      if (lookahead == 'u') ADVANCE(61);
      END_STATE();
    case 98:
      if (lookahead == 'y') ADVANCE(213);
      END_STATE();
    case 99:
      if (lookahead == 'y') ADVANCE(211);
      END_STATE();
    case 100:
      if (lookahead == '{') ADVANCE(107);
      END_STATE();
    case 101:
      if (lookahead == '}') ADVANCE(3);
      END_STATE();
    case 102:
      if (lookahead == '}') ADVANCE(3);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(101);
      END_STATE();
    case 103:
      if (lookahead == '}') ADVANCE(3);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(102);
      END_STATE();
    case 104:
      if (lookahead == '}') ADVANCE(3);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(103);
      END_STATE();
    case 105:
      if (lookahead == '}') ADVANCE(3);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(104);
      END_STATE();
    case 106:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(105);
      END_STATE();
    case 107:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(106);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 109:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'a') ADVANCE(166);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 110:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'a') ADVANCE(150);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'a') ADVANCE(120);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 112:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'a') ADVANCE(183);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 113:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'a') ADVANCE(159);
      if (lookahead == 'u') ADVANCE(127);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 114:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'a') ADVANCE(124);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 115:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'a') ADVANCE(168);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 116:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'a') ADVANCE(123);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'a') ADVANCE(181);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 118:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'a') ADVANCE(152);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'b') ADVANCE(154);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'b') ADVANCE(131);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'c') ADVANCE(203);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'c') ADVANCE(200);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'c') ADVANCE(143);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'c') ADVANCE(129);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'e') ADVANCE(134);
      if (lookahead == 'u') ADVANCE(170);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'e') ADVANCE(175);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'e') ADVANCE(222);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'e') ADVANCE(223);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'e') ADVANCE(201);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'e') ADVANCE(139);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'e') ADVANCE(151);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'e') ADVANCE(161);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'f') ADVANCE(224);
      if (lookahead == 'i') ADVANCE(179);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'f') ADVANCE(112);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 135:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'g') ADVANCE(137);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'g') ADVANCE(220);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'h') ADVANCE(176);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'i') ADVANCE(163);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'i') ADVANCE(135);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'i') ADVANCE(164);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'i') ADVANCE(160);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 142:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'i') ADVANCE(122);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'i') ADVANCE(177);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'i') ADVANCE(178);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 145:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'i') ADVANCE(118);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 146:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'i') ADVANCE(165);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 147:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'i') ADVANCE(182);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 148:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'k') ADVANCE(132);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 149:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'k') ADVANCE(141);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 150:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'l') ADVANCE(173);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 151:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'l') ADVANCE(208);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 152:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'l') ADVANCE(199);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 153:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'l') ADVANCE(114);
      if (lookahead == 'r') ADVANCE(138);
      if (lookahead == 'u') ADVANCE(119);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 154:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'l') ADVANCE(142);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 155:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'l') ADVANCE(180);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 156:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'n') ADVANCE(133);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 157:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'n') ADVANCE(216);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 158:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'n') ADVANCE(202);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 159:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'n') ADVANCE(174);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 160:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'n') ADVANCE(136);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 161:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'n') ADVANCE(171);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 162:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'o') ADVANCE(148);
      if (lookahead == 'r') ADVANCE(113);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 163:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'o') ADVANCE(169);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 164:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'o') ADVANCE(157);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 165:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'o') ADVANCE(158);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 166:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'p') ADVANCE(116);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 167:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'r') ADVANCE(121);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 168:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'r') ADVANCE(149);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 169:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'r') ADVANCE(144);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 170:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'r') ADVANCE(117);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 171:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 's') ADVANCE(192);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 172:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 's') ADVANCE(191);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 173:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 's') ADVANCE(128);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 174:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 's') ADVANCE(147);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 175:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 't') ADVANCE(188);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 176:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 't') ADVANCE(210);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 177:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 't') ADVANCE(184);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 178:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 't') ADVANCE(185);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 179:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 't') ADVANCE(145);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 180:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 't') ADVANCE(172);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 181:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 't') ADVANCE(140);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 182:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 't') ADVANCE(146);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 183:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'u') ADVANCE(155);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 184:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'y') ADVANCE(214);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 185:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == 'y') ADVANCE(212);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 186:
      ACCEPT_TOKEN(sym_name);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 187:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 188:
      ACCEPT_TOKEN(anon_sym_net);
      END_STATE();
    case 189:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 190:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 191:
      ACCEPT_TOKEN(anon_sym_defaults);
      END_STATE();
    case 192:
      ACCEPT_TOKEN(anon_sym_tokens);
      END_STATE();
    case 193:
      ACCEPT_TOKEN(sym_token_set_boolean);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 194:
      ACCEPT_TOKEN(sym_token_set_natural);
      if (lookahead == '+') ADVANCE(195);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 195:
      ACCEPT_TOKEN(sym_token_set_positive);
      END_STATE();
    case 196:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 197:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 198:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 199:
      ACCEPT_TOKEN(anon_sym_initial);
      END_STATE();
    case 200:
      ACCEPT_TOKEN(anon_sym_public);
      END_STATE();
    case 201:
      ACCEPT_TOKEN(anon_sym_place);
      END_STATE();
    case 202:
      ACCEPT_TOKEN(anon_sym_transition);
      END_STATE();
    case 203:
      ACCEPT_TOKEN(anon_sym_arc);
      END_STATE();
    case 204:
      ACCEPT_TOKEN(sym_normal_arc);
      END_STATE();
    case 205:
      ACCEPT_TOKEN(sym_inhibitor_arc);
      END_STATE();
    case 206:
      ACCEPT_TOKEN(sym_reset_arc);
      END_STATE();
    case 207:
      ACCEPT_TOKEN(anon_sym_label);
      END_STATE();
    case 208:
      ACCEPT_TOKEN(anon_sym_label);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 209:
      ACCEPT_TOKEN(anon_sym_weight);
      END_STATE();
    case 210:
      ACCEPT_TOKEN(anon_sym_weight);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 211:
      ACCEPT_TOKEN(anon_sym_priority);
      END_STATE();
    case 212:
      ACCEPT_TOKEN(anon_sym_priority);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 213:
      ACCEPT_TOKEN(anon_sym_capacity);
      END_STATE();
    case 214:
      ACCEPT_TOKEN(anon_sym_capacity);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 215:
      ACCEPT_TOKEN(anon_sym_duration);
      END_STATE();
    case 216:
      ACCEPT_TOKEN(anon_sym_duration);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == 181 ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969)) ADVANCE(186);
      END_STATE();
    case 217:
      ACCEPT_TOKEN(sym_duration_immediate);
      END_STATE();
    case 218:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 219:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 220:
      ACCEPT_TOKEN(anon_sym_marking);
      END_STATE();
    case 221:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 222:
      ACCEPT_TOKEN(anon_sym_true);
      END_STATE();
    case 223:
      ACCEPT_TOKEN(anon_sym_false);
      END_STATE();
    case 224:
      ACCEPT_TOKEN(sym_infinity);
      END_STATE();
    case 225:
      ACCEPT_TOKEN(sym_unsigned);
      END_STATE();
    case 226:
      ACCEPT_TOKEN(sym_unsigned);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(226);
      END_STATE();
    case 227:
      ACCEPT_TOKEN(sym_positive_unsigned);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(227);
      END_STATE();
    case 228:
      ACCEPT_TOKEN(sym_quoted_string);
      END_STATE();
    case 229:
      ACCEPT_TOKEN(sym_line_comment);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(229);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 2},
  [2] = {.lex_state = 2},
  [3] = {.lex_state = 2},
  [4] = {.lex_state = 2},
  [5] = {.lex_state = 2},
  [6] = {.lex_state = 2},
  [7] = {.lex_state = 2},
  [8] = {.lex_state = 2},
  [9] = {.lex_state = 2},
  [10] = {.lex_state = 2},
  [11] = {.lex_state = 2},
  [12] = {.lex_state = 2},
  [13] = {.lex_state = 2},
  [14] = {.lex_state = 2},
  [15] = {.lex_state = 2},
  [16] = {.lex_state = 2},
  [17] = {.lex_state = 2},
  [18] = {.lex_state = 2},
  [19] = {.lex_state = 2},
  [20] = {.lex_state = 2},
  [21] = {.lex_state = 2},
  [22] = {.lex_state = 2},
  [23] = {.lex_state = 2},
  [24] = {.lex_state = 2},
  [25] = {.lex_state = 2},
  [26] = {.lex_state = 2},
  [27] = {.lex_state = 2},
  [28] = {.lex_state = 2},
  [29] = {.lex_state = 2},
  [30] = {.lex_state = 2},
  [31] = {.lex_state = 2},
  [32] = {.lex_state = 2},
  [33] = {.lex_state = 2},
  [34] = {.lex_state = 2},
  [35] = {.lex_state = 2},
  [36] = {.lex_state = 2},
  [37] = {.lex_state = 2},
  [38] = {.lex_state = 2},
  [39] = {.lex_state = 2},
  [40] = {.lex_state = 2},
  [41] = {.lex_state = 2},
  [42] = {.lex_state = 2},
  [43] = {.lex_state = 2},
  [44] = {.lex_state = 2},
  [45] = {.lex_state = 2},
  [46] = {.lex_state = 2},
  [47] = {.lex_state = 2},
  [48] = {.lex_state = 2},
  [49] = {.lex_state = 2},
  [50] = {.lex_state = 2},
  [51] = {.lex_state = 2},
  [52] = {.lex_state = 2},
  [53] = {.lex_state = 2},
  [54] = {.lex_state = 2},
  [55] = {.lex_state = 0},
  [56] = {.lex_state = 0},
  [57] = {.lex_state = 2},
  [58] = {.lex_state = 2},
  [59] = {.lex_state = 2},
  [60] = {.lex_state = 2},
  [61] = {.lex_state = 2},
  [62] = {.lex_state = 2},
  [63] = {.lex_state = 2},
  [64] = {.lex_state = 2},
  [65] = {.lex_state = 2},
  [66] = {.lex_state = 2},
  [67] = {.lex_state = 2},
  [68] = {.lex_state = 2},
  [69] = {.lex_state = 2},
  [70] = {.lex_state = 1},
  [71] = {.lex_state = 2},
  [72] = {.lex_state = 2},
  [73] = {.lex_state = 2},
  [74] = {.lex_state = 2},
  [75] = {.lex_state = 2},
  [76] = {.lex_state = 2},
  [77] = {.lex_state = 2},
  [78] = {.lex_state = 2},
  [79] = {.lex_state = 2},
  [80] = {.lex_state = 2},
  [81] = {.lex_state = 2},
  [82] = {.lex_state = 2},
  [83] = {.lex_state = 2},
  [84] = {.lex_state = 2},
  [85] = {.lex_state = 2},
  [86] = {.lex_state = 2},
  [87] = {.lex_state = 1},
  [88] = {.lex_state = 0},
  [89] = {.lex_state = 4},
  [90] = {.lex_state = 2},
  [91] = {.lex_state = 2},
  [92] = {.lex_state = 2},
  [93] = {.lex_state = 2},
  [94] = {.lex_state = 2},
  [95] = {.lex_state = 2},
  [96] = {.lex_state = 2},
  [97] = {.lex_state = 4},
  [98] = {.lex_state = 2},
  [99] = {.lex_state = 2},
  [100] = {.lex_state = 2},
  [101] = {.lex_state = 2},
  [102] = {.lex_state = 0},
  [103] = {.lex_state = 4},
  [104] = {.lex_state = 4},
  [105] = {.lex_state = 0},
  [106] = {.lex_state = 0},
  [107] = {.lex_state = 4},
  [108] = {.lex_state = 0},
  [109] = {.lex_state = 4},
  [110] = {.lex_state = 0},
  [111] = {.lex_state = 4},
  [112] = {.lex_state = 0},
  [113] = {.lex_state = 4},
  [114] = {.lex_state = 4},
  [115] = {.lex_state = 4},
  [116] = {.lex_state = 4},
  [117] = {.lex_state = 4},
  [118] = {.lex_state = 4},
  [119] = {.lex_state = 0},
  [120] = {.lex_state = 0},
  [121] = {.lex_state = 0},
  [122] = {.lex_state = 0},
  [123] = {.lex_state = 0},
  [124] = {.lex_state = 0},
  [125] = {.lex_state = 4},
  [126] = {.lex_state = 0},
  [127] = {.lex_state = 2},
  [128] = {.lex_state = 0},
  [129] = {.lex_state = 0},
  [130] = {.lex_state = 0},
  [131] = {.lex_state = 0},
  [132] = {.lex_state = 0},
  [133] = {.lex_state = 0},
  [134] = {.lex_state = 0},
  [135] = {.lex_state = 0},
  [136] = {.lex_state = 0},
  [137] = {.lex_state = 0},
  [138] = {.lex_state = 0},
  [139] = {.lex_state = 4},
  [140] = {.lex_state = 0},
  [141] = {.lex_state = 4},
  [142] = {.lex_state = 0},
  [143] = {.lex_state = 4},
  [144] = {.lex_state = 4},
  [145] = {.lex_state = 0},
  [146] = {.lex_state = 0},
  [147] = {.lex_state = 4},
  [148] = {.lex_state = 2},
  [149] = {.lex_state = 0},
  [150] = {.lex_state = 4},
  [151] = {.lex_state = 0},
  [152] = {.lex_state = 0},
  [153] = {.lex_state = 0},
  [154] = {.lex_state = 2},
  [155] = {.lex_state = 0},
  [156] = {.lex_state = 0},
  [157] = {.lex_state = 0},
  [158] = {.lex_state = 1},
  [159] = {.lex_state = 0},
  [160] = {.lex_state = 4},
  [161] = {.lex_state = 0},
  [162] = {.lex_state = 0},
  [163] = {.lex_state = 1},
  [164] = {.lex_state = 0},
  [165] = {.lex_state = 0},
  [166] = {.lex_state = 0},
  [167] = {.lex_state = 0},
  [168] = {.lex_state = 0},
  [169] = {.lex_state = 0},
  [170] = {.lex_state = 0},
  [171] = {.lex_state = 0},
  [172] = {.lex_state = 2},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_name] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_net] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [anon_sym_defaults] = ACTIONS(1),
    [anon_sym_tokens] = ACTIONS(1),
    [sym_token_set_boolean] = ACTIONS(1),
    [sym_token_set_natural] = ACTIONS(1),
    [sym_token_set_positive] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_initial] = ACTIONS(1),
    [anon_sym_public] = ACTIONS(1),
    [anon_sym_place] = ACTIONS(1),
    [anon_sym_transition] = ACTIONS(1),
    [anon_sym_arc] = ACTIONS(1),
    [sym_normal_arc] = ACTIONS(1),
    [sym_inhibitor_arc] = ACTIONS(1),
    [sym_reset_arc] = ACTIONS(1),
    [anon_sym_label] = ACTIONS(1),
    [anon_sym_weight] = ACTIONS(1),
    [anon_sym_priority] = ACTIONS(1),
    [anon_sym_capacity] = ACTIONS(1),
    [anon_sym_duration] = ACTIONS(1),
    [sym_duration_immediate] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [anon_sym_marking] = ACTIONS(1),
    [anon_sym_STAR] = ACTIONS(1),
    [anon_sym_true] = ACTIONS(1),
    [anon_sym_false] = ACTIONS(1),
    [sym_infinity] = ACTIONS(1),
    [sym_unsigned] = ACTIONS(1),
    [sym_positive_unsigned] = ACTIONS(1),
    [sym_quoted_string] = ACTIONS(1),
    [sym_line_comment] = ACTIONS(3),
  },
  [1] = {
    [sym_source_file] = STATE(167),
    [sym__top_level] = STATE(157),
    [sym_net_def] = STATE(157),
    [sym_marking_def] = STATE(157),
    [anon_sym_net] = ACTIONS(5),
    [anon_sym_marking] = ACTIONS(7),
    [sym_line_comment] = ACTIONS(3),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 16,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(9), 1,
      anon_sym_net,
    ACTIONS(11), 1,
      anon_sym_RBRACE,
    ACTIONS(13), 1,
      anon_sym_defaults,
    ACTIONS(15), 1,
      anon_sym_tokens,
    ACTIONS(17), 1,
      anon_sym_initial,
    ACTIONS(19), 1,
      anon_sym_place,
    ACTIONS(21), 1,
      anon_sym_transition,
    ACTIONS(23), 1,
      anon_sym_arc,
    ACTIONS(25), 1,
      anon_sym_label,
    STATE(4), 1,
      sym_label_property,
    STATE(7), 1,
      sym_defaults,
    STATE(8), 1,
      sym__token_def,
    STATE(122), 1,
      sym_initial_marking_def,
    STATE(166), 1,
      sym__block_end,
    STATE(14), 6,
      sym__node_or_arc,
      sym_subnet_def,
      sym_place_def,
      sym_transition_def,
      sym_arc_def,
      aux_sym__net_body_repeat1,
  [54] = 14,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(9), 1,
      anon_sym_net,
    ACTIONS(13), 1,
      anon_sym_defaults,
    ACTIONS(19), 1,
      anon_sym_place,
    ACTIONS(21), 1,
      anon_sym_transition,
    ACTIONS(23), 1,
      anon_sym_arc,
    ACTIONS(25), 1,
      anon_sym_label,
    ACTIONS(27), 1,
      anon_sym_RBRACE,
    ACTIONS(29), 1,
      anon_sym_public,
    STATE(5), 1,
      sym_label_property,
    STATE(11), 1,
      sym_defaults,
    STATE(30), 1,
      sym_public_places,
    STATE(84), 1,
      sym__block_end,
    STATE(27), 6,
      sym__node_or_arc,
      sym_subnet_def,
      sym_place_def,
      sym_transition_def,
      sym_arc_def,
      aux_sym__net_body_repeat1,
  [102] = 14,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(9), 1,
      anon_sym_net,
    ACTIONS(13), 1,
      anon_sym_defaults,
    ACTIONS(15), 1,
      anon_sym_tokens,
    ACTIONS(17), 1,
      anon_sym_initial,
    ACTIONS(19), 1,
      anon_sym_place,
    ACTIONS(21), 1,
      anon_sym_transition,
    ACTIONS(23), 1,
      anon_sym_arc,
    ACTIONS(31), 1,
      anon_sym_RBRACE,
    STATE(6), 1,
      sym_defaults,
    STATE(13), 1,
      sym__token_def,
    STATE(123), 1,
      sym_initial_marking_def,
    STATE(169), 1,
      sym__block_end,
    STATE(12), 6,
      sym__node_or_arc,
      sym_subnet_def,
      sym_place_def,
      sym_transition_def,
      sym_arc_def,
      aux_sym__net_body_repeat1,
  [150] = 12,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(9), 1,
      anon_sym_net,
    ACTIONS(13), 1,
      anon_sym_defaults,
    ACTIONS(19), 1,
      anon_sym_place,
    ACTIONS(21), 1,
      anon_sym_transition,
    ACTIONS(23), 1,
      anon_sym_arc,
    ACTIONS(29), 1,
      anon_sym_public,
    ACTIONS(33), 1,
      anon_sym_RBRACE,
    STATE(16), 1,
      sym_defaults,
    STATE(32), 1,
      sym_public_places,
    STATE(62), 1,
      sym__block_end,
    STATE(33), 6,
      sym__node_or_arc,
      sym_subnet_def,
      sym_place_def,
      sym_transition_def,
      sym_arc_def,
      aux_sym__net_body_repeat1,
  [192] = 12,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(9), 1,
      anon_sym_net,
    ACTIONS(15), 1,
      anon_sym_tokens,
    ACTIONS(17), 1,
      anon_sym_initial,
    ACTIONS(19), 1,
      anon_sym_place,
    ACTIONS(21), 1,
      anon_sym_transition,
    ACTIONS(23), 1,
      anon_sym_arc,
    ACTIONS(35), 1,
      anon_sym_RBRACE,
    STATE(9), 1,
      sym__token_def,
    STATE(135), 1,
      sym_initial_marking_def,
    STATE(140), 1,
      sym__block_end,
    STATE(10), 6,
      sym__node_or_arc,
      sym_subnet_def,
      sym_place_def,
      sym_transition_def,
      sym_arc_def,
      aux_sym__net_body_repeat1,
  [234] = 12,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(9), 1,
      anon_sym_net,
    ACTIONS(15), 1,
      anon_sym_tokens,
    ACTIONS(17), 1,
      anon_sym_initial,
    ACTIONS(19), 1,
      anon_sym_place,
    ACTIONS(21), 1,
      anon_sym_transition,
    ACTIONS(23), 1,
      anon_sym_arc,
    ACTIONS(31), 1,
      anon_sym_RBRACE,
    STATE(13), 1,
      sym__token_def,
    STATE(123), 1,
      sym_initial_marking_def,
    STATE(169), 1,
      sym__block_end,
    STATE(12), 6,
      sym__node_or_arc,
      sym_subnet_def,
      sym_place_def,
      sym_transition_def,
      sym_arc_def,
      aux_sym__net_body_repeat1,
  [276] = 10,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(9), 1,
      anon_sym_net,
    ACTIONS(17), 1,
      anon_sym_initial,
    ACTIONS(19), 1,
      anon_sym_place,
    ACTIONS(21), 1,
      anon_sym_transition,
    ACTIONS(23), 1,
      anon_sym_arc,
    ACTIONS(31), 1,
      anon_sym_RBRACE,
    STATE(123), 1,
      sym_initial_marking_def,
    STATE(169), 1,
      sym__block_end,
    STATE(12), 6,
      sym__node_or_arc,
      sym_subnet_def,
      sym_place_def,
      sym_transition_def,
      sym_arc_def,
      aux_sym__net_body_repeat1,
  [312] = 10,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(9), 1,
      anon_sym_net,
    ACTIONS(17), 1,
      anon_sym_initial,
    ACTIONS(19), 1,
      anon_sym_place,
    ACTIONS(21), 1,
      anon_sym_transition,
    ACTIONS(23), 1,
      anon_sym_arc,
    ACTIONS(37), 1,
      anon_sym_RBRACE,
    STATE(119), 1,
      sym_initial_marking_def,
    STATE(155), 1,
      sym__block_end,
    STATE(15), 6,
      sym__node_or_arc,
      sym_subnet_def,
      sym_place_def,
      sym_transition_def,
      sym_arc_def,
      aux_sym__net_body_repeat1,
  [348] = 10,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(9), 1,
      anon_sym_net,
    ACTIONS(17), 1,
      anon_sym_initial,
    ACTIONS(19), 1,
      anon_sym_place,
    ACTIONS(21), 1,
      anon_sym_transition,
    ACTIONS(23), 1,
      anon_sym_arc,
    ACTIONS(37), 1,
      anon_sym_RBRACE,
    STATE(119), 1,
      sym_initial_marking_def,
    STATE(155), 1,
      sym__block_end,
    STATE(34), 6,
      sym__node_or_arc,
      sym_subnet_def,
      sym_place_def,
      sym_transition_def,
      sym_arc_def,
      aux_sym__net_body_repeat1,
  [384] = 10,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(9), 1,
      anon_sym_net,
    ACTIONS(19), 1,
      anon_sym_place,
    ACTIONS(21), 1,
      anon_sym_transition,
    ACTIONS(23), 1,
      anon_sym_arc,
    ACTIONS(29), 1,
      anon_sym_public,
    ACTIONS(33), 1,
      anon_sym_RBRACE,
    STATE(32), 1,
      sym_public_places,
    STATE(62), 1,
      sym__block_end,
    STATE(33), 6,
      sym__node_or_arc,
      sym_subnet_def,
      sym_place_def,
      sym_transition_def,
      sym_arc_def,
      aux_sym__net_body_repeat1,
  [420] = 10,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(9), 1,
      anon_sym_net,
    ACTIONS(17), 1,
      anon_sym_initial,
    ACTIONS(19), 1,
      anon_sym_place,
    ACTIONS(21), 1,
      anon_sym_transition,
    ACTIONS(23), 1,
      anon_sym_arc,
    ACTIONS(35), 1,
      anon_sym_RBRACE,
    STATE(135), 1,
      sym_initial_marking_def,
    STATE(140), 1,
      sym__block_end,
    STATE(34), 6,
      sym__node_or_arc,
      sym_subnet_def,
      sym_place_def,
      sym_transition_def,
      sym_arc_def,
      aux_sym__net_body_repeat1,
  [456] = 10,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(9), 1,
      anon_sym_net,
    ACTIONS(17), 1,
      anon_sym_initial,
    ACTIONS(19), 1,
      anon_sym_place,
    ACTIONS(21), 1,
      anon_sym_transition,
    ACTIONS(23), 1,
      anon_sym_arc,
    ACTIONS(35), 1,
      anon_sym_RBRACE,
    STATE(135), 1,
      sym_initial_marking_def,
    STATE(140), 1,
      sym__block_end,
    STATE(10), 6,
      sym__node_or_arc,
      sym_subnet_def,
      sym_place_def,
      sym_transition_def,
      sym_arc_def,
      aux_sym__net_body_repeat1,
  [492] = 10,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(9), 1,
      anon_sym_net,
    ACTIONS(17), 1,
      anon_sym_initial,
    ACTIONS(19), 1,
      anon_sym_place,
    ACTIONS(21), 1,
      anon_sym_transition,
    ACTIONS(23), 1,
      anon_sym_arc,
    ACTIONS(31), 1,
      anon_sym_RBRACE,
    STATE(123), 1,
      sym_initial_marking_def,
    STATE(169), 1,
      sym__block_end,
    STATE(34), 6,
      sym__node_or_arc,
      sym_subnet_def,
      sym_place_def,
      sym_transition_def,
      sym_arc_def,
      aux_sym__net_body_repeat1,
  [528] = 10,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(9), 1,
      anon_sym_net,
    ACTIONS(17), 1,
      anon_sym_initial,
    ACTIONS(19), 1,
      anon_sym_place,
    ACTIONS(21), 1,
      anon_sym_transition,
    ACTIONS(23), 1,
      anon_sym_arc,
    ACTIONS(39), 1,
      anon_sym_RBRACE,
    STATE(138), 1,
      sym_initial_marking_def,
    STATE(156), 1,
      sym__block_end,
    STATE(34), 6,
      sym__node_or_arc,
      sym_subnet_def,
      sym_place_def,
      sym_transition_def,
      sym_arc_def,
      aux_sym__net_body_repeat1,
  [564] = 10,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(9), 1,
      anon_sym_net,
    ACTIONS(19), 1,
      anon_sym_place,
    ACTIONS(21), 1,
      anon_sym_transition,
    ACTIONS(23), 1,
      anon_sym_arc,
    ACTIONS(29), 1,
      anon_sym_public,
    ACTIONS(41), 1,
      anon_sym_RBRACE,
    STATE(35), 1,
      sym_public_places,
    STATE(80), 1,
      sym__block_end,
    STATE(28), 6,
      sym__node_or_arc,
      sym_subnet_def,
      sym_place_def,
      sym_transition_def,
      sym_arc_def,
      aux_sym__net_body_repeat1,
  [600] = 5,
    ACTIONS(3), 1,
      sym_line_comment,
    STATE(18), 1,
      aux_sym_arc_expression_repeat3,
    STATE(113), 1,
      sym__arc_type,
    ACTIONS(45), 3,
      sym_normal_arc,
      sym_inhibitor_arc,
      sym_reset_arc,
    ACTIONS(43), 8,
      anon_sym_net,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
      anon_sym_initial,
      anon_sym_place,
      anon_sym_transition,
      anon_sym_arc,
  [625] = 5,
    ACTIONS(3), 1,
      sym_line_comment,
    STATE(18), 1,
      aux_sym_arc_expression_repeat3,
    STATE(113), 1,
      sym__arc_type,
    ACTIONS(49), 3,
      sym_normal_arc,
      sym_inhibitor_arc,
      sym_reset_arc,
    ACTIONS(47), 8,
      anon_sym_net,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
      anon_sym_initial,
      anon_sym_place,
      anon_sym_transition,
      anon_sym_arc,
  [650] = 4,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(52), 1,
      anon_sym_COMMA,
    STATE(19), 1,
      aux_sym_arc_expression_repeat2,
    ACTIONS(55), 11,
      anon_sym_net,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
      anon_sym_initial,
      anon_sym_place,
      anon_sym_transition,
      anon_sym_arc,
      sym_normal_arc,
      sym_inhibitor_arc,
      sym_reset_arc,
  [673] = 4,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(57), 1,
      anon_sym_COMMA,
    STATE(19), 1,
      aux_sym_arc_expression_repeat2,
    ACTIONS(59), 11,
      anon_sym_net,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
      anon_sym_initial,
      anon_sym_place,
      anon_sym_transition,
      anon_sym_arc,
      sym_normal_arc,
      sym_inhibitor_arc,
      sym_reset_arc,
  [696] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(61), 13,
      anon_sym_net,
      anon_sym_RBRACE,
      anon_sym_defaults,
      anon_sym_tokens,
      anon_sym_initial,
      anon_sym_public,
      anon_sym_place,
      anon_sym_transition,
      anon_sym_arc,
      anon_sym_weight,
      anon_sym_priority,
      anon_sym_capacity,
      anon_sym_duration,
  [715] = 5,
    ACTIONS(3), 1,
      sym_line_comment,
    STATE(18), 1,
      aux_sym_arc_expression_repeat3,
    STATE(113), 1,
      sym__arc_type,
    ACTIONS(45), 3,
      sym_normal_arc,
      sym_inhibitor_arc,
      sym_reset_arc,
    ACTIONS(63), 8,
      anon_sym_net,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
      anon_sym_initial,
      anon_sym_place,
      anon_sym_transition,
      anon_sym_arc,
  [740] = 4,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(57), 1,
      anon_sym_COMMA,
    STATE(20), 1,
      aux_sym_arc_expression_repeat2,
    ACTIONS(65), 11,
      anon_sym_net,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
      anon_sym_initial,
      anon_sym_place,
      anon_sym_transition,
      anon_sym_arc,
      sym_normal_arc,
      sym_inhibitor_arc,
      sym_reset_arc,
  [763] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(67), 12,
      anon_sym_COMMA,
      anon_sym_net,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
      anon_sym_initial,
      anon_sym_place,
      anon_sym_transition,
      anon_sym_arc,
      sym_normal_arc,
      sym_inhibitor_arc,
      sym_reset_arc,
  [781] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(69), 12,
      anon_sym_COMMA,
      anon_sym_net,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
      anon_sym_initial,
      anon_sym_place,
      anon_sym_transition,
      anon_sym_arc,
      sym_normal_arc,
      sym_inhibitor_arc,
      sym_reset_arc,
  [799] = 8,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(71), 1,
      anon_sym_RBRACE,
    ACTIONS(73), 1,
      anon_sym_weight,
    ACTIONS(75), 1,
      anon_sym_priority,
    ACTIONS(77), 1,
      anon_sym_capacity,
    ACTIONS(79), 1,
      anon_sym_duration,
    STATE(48), 1,
      sym__block_end,
    STATE(36), 6,
      sym__default_constraints,
      sym_weight_constraint,
      sym_priority_constraint,
      sym_capacity_constraint,
      sym_duration_constraint,
      aux_sym_defaults_repeat1,
  [829] = 8,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(9), 1,
      anon_sym_net,
    ACTIONS(19), 1,
      anon_sym_place,
    ACTIONS(21), 1,
      anon_sym_transition,
    ACTIONS(23), 1,
      anon_sym_arc,
    ACTIONS(33), 1,
      anon_sym_RBRACE,
    STATE(62), 1,
      sym__block_end,
    STATE(34), 6,
      sym__node_or_arc,
      sym_subnet_def,
      sym_place_def,
      sym_transition_def,
      sym_arc_def,
      aux_sym__net_body_repeat1,
  [859] = 8,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(9), 1,
      anon_sym_net,
    ACTIONS(19), 1,
      anon_sym_place,
    ACTIONS(21), 1,
      anon_sym_transition,
    ACTIONS(23), 1,
      anon_sym_arc,
    ACTIONS(81), 1,
      anon_sym_RBRACE,
    STATE(75), 1,
      sym__block_end,
    STATE(34), 6,
      sym__node_or_arc,
      sym_subnet_def,
      sym_place_def,
      sym_transition_def,
      sym_arc_def,
      aux_sym__net_body_repeat1,
  [889] = 8,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(9), 1,
      anon_sym_net,
    ACTIONS(19), 1,
      anon_sym_place,
    ACTIONS(21), 1,
      anon_sym_transition,
    ACTIONS(23), 1,
      anon_sym_arc,
    ACTIONS(83), 1,
      anon_sym_RBRACE,
    STATE(67), 1,
      sym__block_end,
    STATE(34), 6,
      sym__node_or_arc,
      sym_subnet_def,
      sym_place_def,
      sym_transition_def,
      sym_arc_def,
      aux_sym__net_body_repeat1,
  [919] = 8,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(9), 1,
      anon_sym_net,
    ACTIONS(19), 1,
      anon_sym_place,
    ACTIONS(21), 1,
      anon_sym_transition,
    ACTIONS(23), 1,
      anon_sym_arc,
    ACTIONS(33), 1,
      anon_sym_RBRACE,
    STATE(62), 1,
      sym__block_end,
    STATE(33), 6,
      sym__node_or_arc,
      sym_subnet_def,
      sym_place_def,
      sym_transition_def,
      sym_arc_def,
      aux_sym__net_body_repeat1,
  [949] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(85), 12,
      anon_sym_COMMA,
      anon_sym_net,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
      anon_sym_initial,
      anon_sym_place,
      anon_sym_transition,
      anon_sym_arc,
      sym_normal_arc,
      sym_inhibitor_arc,
      sym_reset_arc,
  [967] = 8,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(9), 1,
      anon_sym_net,
    ACTIONS(19), 1,
      anon_sym_place,
    ACTIONS(21), 1,
      anon_sym_transition,
    ACTIONS(23), 1,
      anon_sym_arc,
    ACTIONS(41), 1,
      anon_sym_RBRACE,
    STATE(80), 1,
      sym__block_end,
    STATE(28), 6,
      sym__node_or_arc,
      sym_subnet_def,
      sym_place_def,
      sym_transition_def,
      sym_arc_def,
      aux_sym__net_body_repeat1,
  [997] = 8,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(9), 1,
      anon_sym_net,
    ACTIONS(19), 1,
      anon_sym_place,
    ACTIONS(21), 1,
      anon_sym_transition,
    ACTIONS(23), 1,
      anon_sym_arc,
    ACTIONS(41), 1,
      anon_sym_RBRACE,
    STATE(80), 1,
      sym__block_end,
    STATE(34), 6,
      sym__node_or_arc,
      sym_subnet_def,
      sym_place_def,
      sym_transition_def,
      sym_arc_def,
      aux_sym__net_body_repeat1,
  [1027] = 7,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(87), 1,
      anon_sym_net,
    ACTIONS(92), 1,
      anon_sym_place,
    ACTIONS(95), 1,
      anon_sym_transition,
    ACTIONS(98), 1,
      anon_sym_arc,
    ACTIONS(90), 2,
      anon_sym_RBRACE,
      anon_sym_initial,
    STATE(34), 6,
      sym__node_or_arc,
      sym_subnet_def,
      sym_place_def,
      sym_transition_def,
      sym_arc_def,
      aux_sym__net_body_repeat1,
  [1055] = 8,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(9), 1,
      anon_sym_net,
    ACTIONS(19), 1,
      anon_sym_place,
    ACTIONS(21), 1,
      anon_sym_transition,
    ACTIONS(23), 1,
      anon_sym_arc,
    ACTIONS(81), 1,
      anon_sym_RBRACE,
    STATE(75), 1,
      sym__block_end,
    STATE(29), 6,
      sym__node_or_arc,
      sym_subnet_def,
      sym_place_def,
      sym_transition_def,
      sym_arc_def,
      aux_sym__net_body_repeat1,
  [1085] = 7,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(101), 1,
      anon_sym_RBRACE,
    ACTIONS(103), 1,
      anon_sym_weight,
    ACTIONS(106), 1,
      anon_sym_priority,
    ACTIONS(109), 1,
      anon_sym_capacity,
    ACTIONS(112), 1,
      anon_sym_duration,
    STATE(36), 6,
      sym__default_constraints,
      sym_weight_constraint,
      sym_priority_constraint,
      sym_capacity_constraint,
      sym_duration_constraint,
      aux_sym_defaults_repeat1,
  [1112] = 6,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(73), 1,
      anon_sym_weight,
    ACTIONS(75), 1,
      anon_sym_priority,
    ACTIONS(77), 1,
      anon_sym_capacity,
    ACTIONS(79), 1,
      anon_sym_duration,
    STATE(26), 6,
      sym__default_constraints,
      sym_weight_constraint,
      sym_priority_constraint,
      sym_capacity_constraint,
      sym_duration_constraint,
      aux_sym_defaults_repeat1,
  [1136] = 4,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(115), 1,
      anon_sym_COMMA,
    STATE(38), 1,
      aux_sym__name_list_repeat1,
    ACTIONS(118), 7,
      anon_sym_net,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_initial,
      anon_sym_place,
      anon_sym_transition,
      anon_sym_arc,
  [1155] = 4,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(120), 1,
      anon_sym_COMMA,
    STATE(43), 1,
      aux_sym__name_list_repeat1,
    ACTIONS(122), 7,
      anon_sym_net,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_initial,
      anon_sym_place,
      anon_sym_transition,
      anon_sym_arc,
  [1174] = 5,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(126), 1,
      anon_sym_LBRACE,
    STATE(72), 1,
      sym__block_start,
    STATE(73), 1,
      sym_place_body,
    ACTIONS(124), 6,
      anon_sym_net,
      anon_sym_RBRACE,
      anon_sym_initial,
      anon_sym_place,
      anon_sym_transition,
      anon_sym_arc,
  [1195] = 5,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(130), 1,
      anon_sym_LBRACE,
    STATE(44), 1,
      sym__block_start,
    STATE(74), 1,
      sym_transition_body,
    ACTIONS(128), 6,
      anon_sym_net,
      anon_sym_RBRACE,
      anon_sym_initial,
      anon_sym_place,
      anon_sym_transition,
      anon_sym_arc,
  [1216] = 5,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(134), 1,
      anon_sym_LBRACE,
    STATE(59), 1,
      sym_arc_body,
    STATE(76), 1,
      sym__block_start,
    ACTIONS(132), 6,
      anon_sym_net,
      anon_sym_RBRACE,
      anon_sym_initial,
      anon_sym_place,
      anon_sym_transition,
      anon_sym_arc,
  [1237] = 4,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(120), 1,
      anon_sym_COMMA,
    STATE(38), 1,
      aux_sym__name_list_repeat1,
    ACTIONS(136), 7,
      anon_sym_net,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_initial,
      anon_sym_place,
      anon_sym_transition,
      anon_sym_arc,
  [1256] = 9,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(25), 1,
      anon_sym_label,
    ACTIONS(75), 1,
      anon_sym_priority,
    ACTIONS(79), 1,
      anon_sym_duration,
    ACTIONS(138), 1,
      anon_sym_RBRACE,
    STATE(60), 1,
      sym_label_property,
    STATE(64), 1,
      sym__block_end,
    STATE(99), 1,
      sym_duration_constraint,
    STATE(132), 1,
      sym_priority_constraint,
  [1284] = 5,
    ACTIONS(3), 1,
      sym_line_comment,
    STATE(92), 1,
      sym_value_expr,
    ACTIONS(140), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(115), 2,
      sym__value,
      sym_boolean,
    ACTIONS(142), 3,
      sym_infinity,
      sym_unsigned,
      sym_quoted_string,
  [1304] = 5,
    ACTIONS(3), 1,
      sym_line_comment,
    STATE(92), 1,
      sym_value_expr,
    ACTIONS(144), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(61), 2,
      sym__value,
      sym_boolean,
    ACTIONS(146), 3,
      sym_infinity,
      sym_unsigned,
      sym_quoted_string,
  [1324] = 4,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(148), 1,
      anon_sym_COMMA,
    STATE(47), 1,
      aux_sym_tuple_type_repeat1,
    ACTIONS(151), 6,
      anon_sym_net,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
      anon_sym_place,
      anon_sym_transition,
      anon_sym_arc,
  [1342] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(153), 8,
      anon_sym_net,
      anon_sym_RBRACE,
      anon_sym_tokens,
      anon_sym_initial,
      anon_sym_public,
      anon_sym_place,
      anon_sym_transition,
      anon_sym_arc,
  [1356] = 5,
    ACTIONS(3), 1,
      sym_line_comment,
    STATE(95), 1,
      sym_value_expr,
    ACTIONS(140), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(115), 2,
      sym__value,
      sym_boolean,
    ACTIONS(142), 3,
      sym_infinity,
      sym_unsigned,
      sym_quoted_string,
  [1376] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(155), 8,
      anon_sym_COMMA,
      anon_sym_net,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_initial,
      anon_sym_place,
      anon_sym_transition,
      anon_sym_arc,
  [1390] = 5,
    ACTIONS(3), 1,
      sym_line_comment,
    STATE(95), 1,
      sym_value_expr,
    ACTIONS(144), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(61), 2,
      sym__value,
      sym_boolean,
    ACTIONS(146), 3,
      sym_infinity,
      sym_unsigned,
      sym_quoted_string,
  [1410] = 5,
    ACTIONS(3), 1,
      sym_line_comment,
    STATE(125), 1,
      sym_value_expr,
    ACTIONS(140), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(115), 2,
      sym__value,
      sym_boolean,
    ACTIONS(142), 3,
      sym_infinity,
      sym_unsigned,
      sym_quoted_string,
  [1430] = 4,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(157), 1,
      anon_sym_COMMA,
    STATE(47), 1,
      aux_sym_tuple_type_repeat1,
    ACTIONS(159), 5,
      anon_sym_net,
      anon_sym_RBRACE,
      anon_sym_place,
      anon_sym_transition,
      anon_sym_arc,
  [1447] = 4,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(157), 1,
      anon_sym_COMMA,
    STATE(53), 1,
      aux_sym_tuple_type_repeat1,
    ACTIONS(161), 5,
      anon_sym_net,
      anon_sym_RBRACE,
      anon_sym_place,
      anon_sym_transition,
      anon_sym_arc,
  [1464] = 6,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(163), 1,
      anon_sym_COMMA,
    STATE(22), 1,
      aux_sym_arc_expression_repeat3,
    STATE(88), 1,
      aux_sym_arc_expression_repeat1,
    STATE(113), 1,
      sym__arc_type,
    ACTIONS(45), 3,
      sym_normal_arc,
      sym_inhibitor_arc,
      sym_reset_arc,
  [1485] = 6,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(163), 1,
      anon_sym_COMMA,
    STATE(17), 1,
      aux_sym_arc_expression_repeat3,
    STATE(55), 1,
      aux_sym_arc_expression_repeat1,
    STATE(113), 1,
      sym__arc_type,
    ACTIONS(45), 3,
      sym_normal_arc,
      sym_inhibitor_arc,
      sym_reset_arc,
  [1506] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(151), 7,
      anon_sym_COMMA,
      anon_sym_net,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
      anon_sym_place,
      anon_sym_transition,
      anon_sym_arc,
  [1519] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(165), 6,
      anon_sym_net,
      anon_sym_RBRACE,
      anon_sym_initial,
      anon_sym_place,
      anon_sym_transition,
      anon_sym_arc,
  [1531] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(167), 6,
      anon_sym_net,
      anon_sym_RBRACE,
      anon_sym_initial,
      anon_sym_place,
      anon_sym_transition,
      anon_sym_arc,
  [1543] = 7,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(75), 1,
      anon_sym_priority,
    ACTIONS(79), 1,
      anon_sym_duration,
    ACTIONS(169), 1,
      anon_sym_RBRACE,
    STATE(58), 1,
      sym__block_end,
    STATE(101), 1,
      sym_duration_constraint,
    STATE(128), 1,
      sym_priority_constraint,
  [1565] = 3,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(173), 1,
      anon_sym_STAR,
    ACTIONS(171), 5,
      anon_sym_RBRACE,
      anon_sym_weight,
      anon_sym_priority,
      anon_sym_capacity,
      anon_sym_duration,
  [1579] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(175), 6,
      anon_sym_net,
      anon_sym_RBRACE,
      anon_sym_initial,
      anon_sym_place,
      anon_sym_transition,
      anon_sym_arc,
  [1591] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(177), 6,
      anon_sym_RBRACE,
      anon_sym_weight,
      anon_sym_priority,
      anon_sym_capacity,
      anon_sym_duration,
      anon_sym_STAR,
  [1603] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(179), 6,
      anon_sym_net,
      anon_sym_RBRACE,
      anon_sym_initial,
      anon_sym_place,
      anon_sym_transition,
      anon_sym_arc,
  [1615] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(181), 6,
      anon_sym_net,
      anon_sym_RBRACE,
      anon_sym_initial,
      anon_sym_place,
      anon_sym_transition,
      anon_sym_arc,
  [1627] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(183), 6,
      anon_sym_net,
      anon_sym_RBRACE,
      anon_sym_initial,
      anon_sym_place,
      anon_sym_transition,
      anon_sym_arc,
  [1639] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(185), 6,
      anon_sym_net,
      anon_sym_RBRACE,
      anon_sym_initial,
      anon_sym_place,
      anon_sym_transition,
      anon_sym_arc,
  [1651] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(187), 6,
      anon_sym_net,
      anon_sym_RBRACE,
      anon_sym_initial,
      anon_sym_place,
      anon_sym_transition,
      anon_sym_arc,
  [1663] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(189), 6,
      anon_sym_net,
      anon_sym_RBRACE,
      anon_sym_initial,
      anon_sym_place,
      anon_sym_transition,
      anon_sym_arc,
  [1675] = 5,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(191), 1,
      sym_name,
    ACTIONS(195), 1,
      sym_token_set_positive,
    ACTIONS(193), 2,
      sym_token_set_boolean,
      sym_token_set_natural,
    STATE(78), 2,
      sym__token_set,
      sym_token_set_def,
  [1693] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(197), 6,
      anon_sym_net,
      anon_sym_RBRACE,
      anon_sym_initial,
      anon_sym_place,
      anon_sym_transition,
      anon_sym_arc,
  [1705] = 7,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(25), 1,
      anon_sym_label,
    ACTIONS(199), 1,
      anon_sym_RBRACE,
    ACTIONS(201), 1,
      anon_sym_capacity,
    STATE(66), 1,
      sym__block_end,
    STATE(98), 1,
      sym_label_property,
    STATE(133), 1,
      sym_capacity_constraint,
  [1727] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(203), 6,
      anon_sym_net,
      anon_sym_RBRACE,
      anon_sym_initial,
      anon_sym_place,
      anon_sym_transition,
      anon_sym_arc,
  [1739] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(205), 6,
      anon_sym_net,
      anon_sym_RBRACE,
      anon_sym_initial,
      anon_sym_place,
      anon_sym_transition,
      anon_sym_arc,
  [1751] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(207), 6,
      anon_sym_net,
      anon_sym_RBRACE,
      anon_sym_initial,
      anon_sym_place,
      anon_sym_transition,
      anon_sym_arc,
  [1763] = 7,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(25), 1,
      anon_sym_label,
    ACTIONS(209), 1,
      anon_sym_RBRACE,
    ACTIONS(211), 1,
      anon_sym_weight,
    STATE(86), 1,
      sym__block_end,
    STATE(100), 1,
      sym_label_property,
    STATE(130), 1,
      sym_weight_constraint,
  [1785] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(213), 6,
      anon_sym_net,
      anon_sym_RBRACE,
      anon_sym_initial,
      anon_sym_place,
      anon_sym_transition,
      anon_sym_arc,
  [1797] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(215), 6,
      anon_sym_net,
      anon_sym_RBRACE,
      anon_sym_initial,
      anon_sym_place,
      anon_sym_transition,
      anon_sym_arc,
  [1809] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(217), 6,
      anon_sym_net,
      anon_sym_RBRACE,
      anon_sym_initial,
      anon_sym_place,
      anon_sym_transition,
      anon_sym_arc,
  [1821] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(219), 6,
      anon_sym_net,
      anon_sym_RBRACE,
      anon_sym_initial,
      anon_sym_place,
      anon_sym_transition,
      anon_sym_arc,
  [1833] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(221), 6,
      anon_sym_net,
      anon_sym_RBRACE,
      anon_sym_initial,
      anon_sym_place,
      anon_sym_transition,
      anon_sym_arc,
  [1845] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(223), 6,
      anon_sym_net,
      anon_sym_RBRACE,
      anon_sym_initial,
      anon_sym_place,
      anon_sym_transition,
      anon_sym_arc,
  [1857] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(225), 6,
      anon_sym_net,
      anon_sym_RBRACE,
      anon_sym_initial,
      anon_sym_place,
      anon_sym_transition,
      anon_sym_arc,
  [1869] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(227), 6,
      anon_sym_net,
      anon_sym_RBRACE,
      anon_sym_initial,
      anon_sym_place,
      anon_sym_transition,
      anon_sym_arc,
  [1881] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(229), 6,
      anon_sym_net,
      anon_sym_RBRACE,
      anon_sym_initial,
      anon_sym_place,
      anon_sym_transition,
      anon_sym_arc,
  [1893] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(231), 6,
      anon_sym_net,
      anon_sym_RBRACE,
      anon_sym_initial,
      anon_sym_place,
      anon_sym_transition,
      anon_sym_arc,
  [1905] = 5,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(235), 1,
      sym_duration_immediate,
    ACTIONS(237), 1,
      sym_positive_unsigned,
    ACTIONS(233), 2,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
    STATE(91), 2,
      sym_duration_fixed,
      sym_duration_interval,
  [1923] = 4,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(239), 1,
      anon_sym_COMMA,
    STATE(88), 1,
      aux_sym_arc_expression_repeat1,
    ACTIONS(242), 3,
      sym_normal_arc,
      sym_inhibitor_arc,
      sym_reset_arc,
  [1938] = 5,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(244), 1,
      sym_name,
    ACTIONS(246), 1,
      anon_sym_RBRACE,
    STATE(129), 1,
      sym__block_end,
    STATE(103), 2,
      sym_marking_assignment,
      aux_sym_marking_def_repeat1,
  [1955] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(248), 5,
      anon_sym_RBRACE,
      anon_sym_weight,
      anon_sym_priority,
      anon_sym_capacity,
      anon_sym_duration,
  [1966] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(250), 5,
      anon_sym_RBRACE,
      anon_sym_weight,
      anon_sym_priority,
      anon_sym_capacity,
      anon_sym_duration,
  [1977] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(252), 5,
      anon_sym_RBRACE,
      anon_sym_weight,
      anon_sym_priority,
      anon_sym_capacity,
      anon_sym_duration,
  [1988] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(254), 5,
      anon_sym_RBRACE,
      anon_sym_weight,
      anon_sym_priority,
      anon_sym_capacity,
      anon_sym_duration,
  [1999] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(256), 5,
      anon_sym_RBRACE,
      anon_sym_weight,
      anon_sym_priority,
      anon_sym_capacity,
      anon_sym_duration,
  [2010] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(258), 5,
      anon_sym_RBRACE,
      anon_sym_weight,
      anon_sym_priority,
      anon_sym_capacity,
      anon_sym_duration,
  [2021] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(260), 5,
      anon_sym_RBRACE,
      anon_sym_weight,
      anon_sym_priority,
      anon_sym_capacity,
      anon_sym_duration,
  [2032] = 5,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(262), 1,
      sym_name,
    ACTIONS(264), 1,
      anon_sym_LPAREN,
    STATE(56), 1,
      sym_arc_name_or_expression,
    STATE(159), 1,
      sym_arc_expression,
  [2048] = 5,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(201), 1,
      anon_sym_capacity,
    ACTIONS(266), 1,
      anon_sym_RBRACE,
    STATE(81), 1,
      sym__block_end,
    STATE(126), 1,
      sym_capacity_constraint,
  [2064] = 5,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(75), 1,
      anon_sym_priority,
    ACTIONS(169), 1,
      anon_sym_RBRACE,
    STATE(58), 1,
      sym__block_end,
    STATE(128), 1,
      sym_priority_constraint,
  [2080] = 5,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(211), 1,
      anon_sym_weight,
    ACTIONS(268), 1,
      anon_sym_RBRACE,
    STATE(77), 1,
      sym__block_end,
    STATE(131), 1,
      sym_weight_constraint,
  [2096] = 5,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(75), 1,
      anon_sym_priority,
    ACTIONS(270), 1,
      anon_sym_RBRACE,
    STATE(83), 1,
      sym__block_end,
    STATE(136), 1,
      sym_priority_constraint,
  [2112] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(272), 4,
      anon_sym_COMMA,
      sym_normal_arc,
      sym_inhibitor_arc,
      sym_reset_arc,
  [2122] = 4,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(274), 1,
      sym_name,
    ACTIONS(277), 1,
      anon_sym_RBRACE,
    STATE(103), 2,
      sym_marking_assignment,
      aux_sym_marking_def_repeat1,
  [2136] = 5,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(262), 1,
      sym_name,
    ACTIONS(264), 1,
      anon_sym_LPAREN,
    STATE(42), 1,
      sym_arc_expression,
    STATE(56), 1,
      sym_arc_name_or_expression,
  [2152] = 4,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(279), 1,
      anon_sym_LBRACE,
    ACTIONS(281), 1,
      anon_sym_LPAREN,
    STATE(79), 2,
      sym_tuple_type,
      sym_set_type,
  [2166] = 4,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(157), 1,
      anon_sym_COMMA,
    ACTIONS(283), 1,
      anon_sym_RBRACE,
    STATE(47), 1,
      aux_sym_tuple_type_repeat1,
  [2179] = 4,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(262), 1,
      sym_name,
    ACTIONS(264), 1,
      anon_sym_LPAREN,
    STATE(25), 1,
      sym_arc_name_or_expression,
  [2192] = 4,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(285), 1,
      anon_sym_LBRACE,
    STATE(3), 1,
      sym__block_start,
    STATE(65), 1,
      sym__subnet_body,
  [2205] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(177), 3,
      sym_name,
      anon_sym_RBRACE,
      anon_sym_STAR,
  [2214] = 4,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(157), 1,
      anon_sym_COMMA,
    ACTIONS(287), 1,
      anon_sym_RPAREN,
    STATE(47), 1,
      aux_sym_tuple_type_repeat1,
  [2227] = 3,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(244), 1,
      sym_name,
    STATE(89), 2,
      sym_marking_assignment,
      aux_sym_marking_def_repeat1,
  [2238] = 4,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(289), 1,
      anon_sym_LBRACE,
    STATE(2), 1,
      sym__block_start,
    STATE(152), 1,
      sym__net_body,
  [2251] = 4,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(262), 1,
      sym_name,
    ACTIONS(264), 1,
      anon_sym_LPAREN,
    STATE(23), 1,
      sym_arc_name_or_expression,
  [2264] = 4,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(262), 1,
      sym_name,
    ACTIONS(264), 1,
      anon_sym_LPAREN,
    STATE(102), 1,
      sym_arc_name_or_expression,
  [2277] = 3,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(291), 1,
      anon_sym_STAR,
    ACTIONS(171), 2,
      sym_name,
      anon_sym_RBRACE,
  [2288] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(260), 2,
      sym_name,
      anon_sym_RBRACE,
  [2296] = 3,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(293), 1,
      sym_name,
    STATE(41), 1,
      sym__name_list,
  [2306] = 3,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(293), 1,
      sym_name,
    STATE(40), 1,
      sym__name_list,
  [2316] = 3,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(39), 1,
      anon_sym_RBRACE,
    STATE(156), 1,
      sym__block_end,
  [2326] = 3,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(157), 1,
      anon_sym_COMMA,
    STATE(106), 1,
      aux_sym_tuple_type_repeat1,
  [2336] = 3,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(157), 1,
      anon_sym_COMMA,
    STATE(110), 1,
      aux_sym_tuple_type_repeat1,
  [2346] = 3,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(31), 1,
      anon_sym_RBRACE,
    STATE(169), 1,
      sym__block_end,
  [2356] = 3,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(35), 1,
      anon_sym_RBRACE,
    STATE(140), 1,
      sym__block_end,
  [2366] = 3,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(295), 1,
      anon_sym_LBRACE,
    STATE(111), 1,
      sym__block_start,
  [2376] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(297), 2,
      sym_name,
      anon_sym_RBRACE,
  [2384] = 3,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(299), 1,
      anon_sym_RBRACE,
    STATE(85), 1,
      sym__block_end,
  [2394] = 3,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(7), 1,
      anon_sym_marking,
    STATE(146), 1,
      sym_marking_def,
  [2404] = 3,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(270), 1,
      anon_sym_RBRACE,
    STATE(83), 1,
      sym__block_end,
  [2414] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(301), 2,
      ts_builtin_sym_end,
      anon_sym_RBRACE,
  [2422] = 3,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(268), 1,
      anon_sym_RBRACE,
    STATE(77), 1,
      sym__block_end,
  [2432] = 3,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(303), 1,
      anon_sym_RBRACE,
    STATE(82), 1,
      sym__block_end,
  [2442] = 3,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(169), 1,
      anon_sym_RBRACE,
    STATE(58), 1,
      sym__block_end,
  [2452] = 3,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(266), 1,
      anon_sym_RBRACE,
    STATE(81), 1,
      sym__block_end,
  [2462] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(305), 2,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
  [2470] = 3,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(37), 1,
      anon_sym_RBRACE,
    STATE(155), 1,
      sym__block_end,
  [2480] = 3,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(307), 1,
      anon_sym_RBRACE,
    STATE(68), 1,
      sym__block_end,
  [2490] = 3,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(309), 1,
      anon_sym_LBRACE,
    STATE(37), 1,
      sym__block_start,
  [2500] = 3,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(311), 1,
      anon_sym_RBRACE,
    STATE(153), 1,
      sym__block_end,
  [2510] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(313), 1,
      sym_name,
  [2517] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(315), 1,
      ts_builtin_sym_end,
  [2524] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(317), 1,
      sym_name,
  [2531] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(319), 1,
      anon_sym_EQ,
  [2538] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(321), 1,
      sym_name,
  [2545] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(323), 1,
      sym_name,
  [2552] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(325), 1,
      anon_sym_COMMA,
  [2559] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(327), 1,
      anon_sym_RBRACE,
  [2566] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(329), 1,
      sym_name,
  [2573] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(331), 1,
      sym_unsigned,
  [2580] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(333), 1,
      anon_sym_EQ,
  [2587] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(335), 1,
      sym_name,
  [2594] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(337), 1,
      anon_sym_EQ,
  [2601] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(339), 1,
      ts_builtin_sym_end,
  [2608] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(341), 1,
      ts_builtin_sym_end,
  [2615] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(343), 1,
      sym_unsigned,
  [2622] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(345), 1,
      ts_builtin_sym_end,
  [2629] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(347), 1,
      ts_builtin_sym_end,
  [2636] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(349), 1,
      ts_builtin_sym_end,
  [2643] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(351), 1,
      sym_positive_unsigned,
  [2650] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(353), 1,
      anon_sym_RPAREN,
  [2657] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(355), 1,
      sym_name,
  [2664] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(357), 1,
      anon_sym_EQ,
  [2671] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(359), 1,
      anon_sym_EQ,
  [2678] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(361), 1,
      sym_positive_unsigned,
  [2685] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(363), 1,
      anon_sym_EQ,
  [2692] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(365), 1,
      anon_sym_EQ,
  [2699] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(367), 1,
      ts_builtin_sym_end,
  [2706] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(369), 1,
      ts_builtin_sym_end,
  [2713] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(371), 1,
      sym_quoted_string,
  [2720] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(373), 1,
      ts_builtin_sym_end,
  [2727] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(375), 1,
      anon_sym_EQ,
  [2734] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(377), 1,
      anon_sym_EQ,
  [2741] = 2,
    ACTIONS(3), 1,
      sym_line_comment,
    ACTIONS(379), 1,
      sym_unsigned,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 54,
  [SMALL_STATE(4)] = 102,
  [SMALL_STATE(5)] = 150,
  [SMALL_STATE(6)] = 192,
  [SMALL_STATE(7)] = 234,
  [SMALL_STATE(8)] = 276,
  [SMALL_STATE(9)] = 312,
  [SMALL_STATE(10)] = 348,
  [SMALL_STATE(11)] = 384,
  [SMALL_STATE(12)] = 420,
  [SMALL_STATE(13)] = 456,
  [SMALL_STATE(14)] = 492,
  [SMALL_STATE(15)] = 528,
  [SMALL_STATE(16)] = 564,
  [SMALL_STATE(17)] = 600,
  [SMALL_STATE(18)] = 625,
  [SMALL_STATE(19)] = 650,
  [SMALL_STATE(20)] = 673,
  [SMALL_STATE(21)] = 696,
  [SMALL_STATE(22)] = 715,
  [SMALL_STATE(23)] = 740,
  [SMALL_STATE(24)] = 763,
  [SMALL_STATE(25)] = 781,
  [SMALL_STATE(26)] = 799,
  [SMALL_STATE(27)] = 829,
  [SMALL_STATE(28)] = 859,
  [SMALL_STATE(29)] = 889,
  [SMALL_STATE(30)] = 919,
  [SMALL_STATE(31)] = 949,
  [SMALL_STATE(32)] = 967,
  [SMALL_STATE(33)] = 997,
  [SMALL_STATE(34)] = 1027,
  [SMALL_STATE(35)] = 1055,
  [SMALL_STATE(36)] = 1085,
  [SMALL_STATE(37)] = 1112,
  [SMALL_STATE(38)] = 1136,
  [SMALL_STATE(39)] = 1155,
  [SMALL_STATE(40)] = 1174,
  [SMALL_STATE(41)] = 1195,
  [SMALL_STATE(42)] = 1216,
  [SMALL_STATE(43)] = 1237,
  [SMALL_STATE(44)] = 1256,
  [SMALL_STATE(45)] = 1284,
  [SMALL_STATE(46)] = 1304,
  [SMALL_STATE(47)] = 1324,
  [SMALL_STATE(48)] = 1342,
  [SMALL_STATE(49)] = 1356,
  [SMALL_STATE(50)] = 1376,
  [SMALL_STATE(51)] = 1390,
  [SMALL_STATE(52)] = 1410,
  [SMALL_STATE(53)] = 1430,
  [SMALL_STATE(54)] = 1447,
  [SMALL_STATE(55)] = 1464,
  [SMALL_STATE(56)] = 1485,
  [SMALL_STATE(57)] = 1506,
  [SMALL_STATE(58)] = 1519,
  [SMALL_STATE(59)] = 1531,
  [SMALL_STATE(60)] = 1543,
  [SMALL_STATE(61)] = 1565,
  [SMALL_STATE(62)] = 1579,
  [SMALL_STATE(63)] = 1591,
  [SMALL_STATE(64)] = 1603,
  [SMALL_STATE(65)] = 1615,
  [SMALL_STATE(66)] = 1627,
  [SMALL_STATE(67)] = 1639,
  [SMALL_STATE(68)] = 1651,
  [SMALL_STATE(69)] = 1663,
  [SMALL_STATE(70)] = 1675,
  [SMALL_STATE(71)] = 1693,
  [SMALL_STATE(72)] = 1705,
  [SMALL_STATE(73)] = 1727,
  [SMALL_STATE(74)] = 1739,
  [SMALL_STATE(75)] = 1751,
  [SMALL_STATE(76)] = 1763,
  [SMALL_STATE(77)] = 1785,
  [SMALL_STATE(78)] = 1797,
  [SMALL_STATE(79)] = 1809,
  [SMALL_STATE(80)] = 1821,
  [SMALL_STATE(81)] = 1833,
  [SMALL_STATE(82)] = 1845,
  [SMALL_STATE(83)] = 1857,
  [SMALL_STATE(84)] = 1869,
  [SMALL_STATE(85)] = 1881,
  [SMALL_STATE(86)] = 1893,
  [SMALL_STATE(87)] = 1905,
  [SMALL_STATE(88)] = 1923,
  [SMALL_STATE(89)] = 1938,
  [SMALL_STATE(90)] = 1955,
  [SMALL_STATE(91)] = 1966,
  [SMALL_STATE(92)] = 1977,
  [SMALL_STATE(93)] = 1988,
  [SMALL_STATE(94)] = 1999,
  [SMALL_STATE(95)] = 2010,
  [SMALL_STATE(96)] = 2021,
  [SMALL_STATE(97)] = 2032,
  [SMALL_STATE(98)] = 2048,
  [SMALL_STATE(99)] = 2064,
  [SMALL_STATE(100)] = 2080,
  [SMALL_STATE(101)] = 2096,
  [SMALL_STATE(102)] = 2112,
  [SMALL_STATE(103)] = 2122,
  [SMALL_STATE(104)] = 2136,
  [SMALL_STATE(105)] = 2152,
  [SMALL_STATE(106)] = 2166,
  [SMALL_STATE(107)] = 2179,
  [SMALL_STATE(108)] = 2192,
  [SMALL_STATE(109)] = 2205,
  [SMALL_STATE(110)] = 2214,
  [SMALL_STATE(111)] = 2227,
  [SMALL_STATE(112)] = 2238,
  [SMALL_STATE(113)] = 2251,
  [SMALL_STATE(114)] = 2264,
  [SMALL_STATE(115)] = 2277,
  [SMALL_STATE(116)] = 2288,
  [SMALL_STATE(117)] = 2296,
  [SMALL_STATE(118)] = 2306,
  [SMALL_STATE(119)] = 2316,
  [SMALL_STATE(120)] = 2326,
  [SMALL_STATE(121)] = 2336,
  [SMALL_STATE(122)] = 2346,
  [SMALL_STATE(123)] = 2356,
  [SMALL_STATE(124)] = 2366,
  [SMALL_STATE(125)] = 2376,
  [SMALL_STATE(126)] = 2384,
  [SMALL_STATE(127)] = 2394,
  [SMALL_STATE(128)] = 2404,
  [SMALL_STATE(129)] = 2414,
  [SMALL_STATE(130)] = 2422,
  [SMALL_STATE(131)] = 2432,
  [SMALL_STATE(132)] = 2442,
  [SMALL_STATE(133)] = 2452,
  [SMALL_STATE(134)] = 2462,
  [SMALL_STATE(135)] = 2470,
  [SMALL_STATE(136)] = 2480,
  [SMALL_STATE(137)] = 2490,
  [SMALL_STATE(138)] = 2500,
  [SMALL_STATE(139)] = 2510,
  [SMALL_STATE(140)] = 2517,
  [SMALL_STATE(141)] = 2524,
  [SMALL_STATE(142)] = 2531,
  [SMALL_STATE(143)] = 2538,
  [SMALL_STATE(144)] = 2545,
  [SMALL_STATE(145)] = 2552,
  [SMALL_STATE(146)] = 2559,
  [SMALL_STATE(147)] = 2566,
  [SMALL_STATE(148)] = 2573,
  [SMALL_STATE(149)] = 2580,
  [SMALL_STATE(150)] = 2587,
  [SMALL_STATE(151)] = 2594,
  [SMALL_STATE(152)] = 2601,
  [SMALL_STATE(153)] = 2608,
  [SMALL_STATE(154)] = 2615,
  [SMALL_STATE(155)] = 2622,
  [SMALL_STATE(156)] = 2629,
  [SMALL_STATE(157)] = 2636,
  [SMALL_STATE(158)] = 2643,
  [SMALL_STATE(159)] = 2650,
  [SMALL_STATE(160)] = 2657,
  [SMALL_STATE(161)] = 2664,
  [SMALL_STATE(162)] = 2671,
  [SMALL_STATE(163)] = 2678,
  [SMALL_STATE(164)] = 2685,
  [SMALL_STATE(165)] = 2692,
  [SMALL_STATE(166)] = 2699,
  [SMALL_STATE(167)] = 2706,
  [SMALL_STATE(168)] = 2713,
  [SMALL_STATE(169)] = 2720,
  [SMALL_STATE(170)] = 2727,
  [SMALL_STATE(171)] = 2734,
  [SMALL_STATE(172)] = 2741,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(147),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(124),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(143),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(166),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(137),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(127),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(118),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(117),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(104),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(149),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(150),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(169),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [35] = {.entry = {.count = 1, .reusable = true}}, SHIFT(140),
  [37] = {.entry = {.count = 1, .reusable = true}}, SHIFT(155),
  [39] = {.entry = {.count = 1, .reusable = true}}, SHIFT(156),
  [41] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [43] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arc_expression, 2, .production_id = 9),
  [45] = {.entry = {.count = 1, .reusable = true}}, SHIFT(113),
  [47] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_arc_expression_repeat3, 2, .production_id = 15),
  [49] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_arc_expression_repeat3, 2, .production_id = 15), SHIFT_REPEAT(113),
  [52] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_arc_expression_repeat2, 2, .production_id = 15), SHIFT_REPEAT(107),
  [55] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_arc_expression_repeat2, 2, .production_id = 15),
  [57] = {.entry = {.count = 1, .reusable = true}}, SHIFT(107),
  [59] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_arc_expression_repeat3, 3, .production_id = 17),
  [61] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_label_property, 3),
  [63] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arc_expression, 3, .production_id = 14),
  [65] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_arc_expression_repeat3, 2, .production_id = 12),
  [67] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arc_name_or_expression, 3),
  [69] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_arc_expression_repeat2, 2, .production_id = 12),
  [71] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [73] = {.entry = {.count = 1, .reusable = true}}, SHIFT(165),
  [75] = {.entry = {.count = 1, .reusable = true}}, SHIFT(164),
  [77] = {.entry = {.count = 1, .reusable = true}}, SHIFT(162),
  [79] = {.entry = {.count = 1, .reusable = true}}, SHIFT(161),
  [81] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [83] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [85] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arc_name_or_expression, 1),
  [87] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__net_body_repeat1, 2), SHIFT_REPEAT(143),
  [90] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__net_body_repeat1, 2),
  [92] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__net_body_repeat1, 2), SHIFT_REPEAT(118),
  [95] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__net_body_repeat1, 2), SHIFT_REPEAT(117),
  [98] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__net_body_repeat1, 2), SHIFT_REPEAT(104),
  [101] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_defaults_repeat1, 2),
  [103] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_defaults_repeat1, 2), SHIFT_REPEAT(165),
  [106] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_defaults_repeat1, 2), SHIFT_REPEAT(164),
  [109] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_defaults_repeat1, 2), SHIFT_REPEAT(162),
  [112] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_defaults_repeat1, 2), SHIFT_REPEAT(161),
  [115] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__name_list_repeat1, 2, .production_id = 10), SHIFT_REPEAT(160),
  [118] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__name_list_repeat1, 2, .production_id = 10),
  [120] = {.entry = {.count = 1, .reusable = true}}, SHIFT(160),
  [122] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__name_list, 1, .production_id = 2),
  [124] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_place_def, 2, .production_id = 3),
  [126] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [128] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_transition_def, 2, .production_id = 3),
  [130] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [132] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arc_def, 2),
  [134] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [136] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__name_list, 2, .production_id = 6),
  [138] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [140] = {.entry = {.count = 1, .reusable = true}}, SHIFT(109),
  [142] = {.entry = {.count = 1, .reusable = true}}, SHIFT(115),
  [144] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [146] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [148] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_tuple_type_repeat1, 2), SHIFT_REPEAT(141),
  [151] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_tuple_type_repeat1, 2),
  [153] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_defaults, 4),
  [155] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__name_list_repeat1, 2, .production_id = 1),
  [157] = {.entry = {.count = 1, .reusable = true}}, SHIFT(141),
  [159] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_public_places, 3),
  [161] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_public_places, 2),
  [163] = {.entry = {.count = 1, .reusable = true}}, SHIFT(114),
  [165] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_transition_body, 3),
  [167] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arc_def, 3, .production_id = 8),
  [169] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [171] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_value_expr, 1, .production_id = 5),
  [173] = {.entry = {.count = 1, .reusable = true}}, SHIFT(172),
  [175] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__subnet_body, 3),
  [177] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_boolean, 1),
  [179] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_transition_body, 2),
  [181] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_subnet_def, 3, .production_id = 1),
  [183] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_place_body, 2),
  [185] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__subnet_body, 6),
  [187] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_transition_body, 5),
  [189] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tuple_type, 4),
  [191] = {.entry = {.count = 1, .reusable = false}}, SHIFT(142),
  [193] = {.entry = {.count = 1, .reusable = false}}, SHIFT(78),
  [195] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [197] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_set_type, 4),
  [199] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [201] = {.entry = {.count = 1, .reusable = true}}, SHIFT(171),
  [203] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_place_def, 3, .production_id = 7),
  [205] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_transition_def, 3, .production_id = 7),
  [207] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__subnet_body, 5),
  [209] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [211] = {.entry = {.count = 1, .reusable = true}}, SHIFT(170),
  [213] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arc_body, 3),
  [215] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__token_def, 2),
  [217] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_token_set_def, 3),
  [219] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__subnet_body, 4),
  [221] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_place_body, 3),
  [223] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arc_body, 4),
  [225] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_transition_body, 4),
  [227] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__subnet_body, 2),
  [229] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_place_body, 4),
  [231] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arc_body, 2),
  [233] = {.entry = {.count = 1, .reusable = true}}, SHIFT(163),
  [235] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [237] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [239] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_arc_expression_repeat1, 2, .production_id = 13), SHIFT_REPEAT(114),
  [242] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_arc_expression_repeat1, 2, .production_id = 13),
  [244] = {.entry = {.count = 1, .reusable = true}}, SHIFT(151),
  [246] = {.entry = {.count = 1, .reusable = true}}, SHIFT(129),
  [248] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_duration_fixed, 1),
  [250] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_duration_constraint, 3),
  [252] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_capacity_constraint, 3),
  [254] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_priority_constraint, 3),
  [256] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_duration_interval, 5, .production_id = 18),
  [258] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_weight_constraint, 3),
  [260] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_value_expr, 3, .production_id = 16),
  [262] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [264] = {.entry = {.count = 1, .reusable = true}}, SHIFT(97),
  [266] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [268] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [270] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [272] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_arc_expression_repeat1, 2, .production_id = 11),
  [274] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_marking_def_repeat1, 2), SHIFT_REPEAT(151),
  [277] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_marking_def_repeat1, 2),
  [279] = {.entry = {.count = 1, .reusable = true}}, SHIFT(139),
  [281] = {.entry = {.count = 1, .reusable = true}}, SHIFT(144),
  [283] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [285] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [287] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [289] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [291] = {.entry = {.count = 1, .reusable = true}}, SHIFT(154),
  [293] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [295] = {.entry = {.count = 1, .reusable = true}}, SHIFT(111),
  [297] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_marking_assignment, 3, .production_id = 4),
  [299] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [301] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_marking_def, 4),
  [303] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [305] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [307] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [309] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [311] = {.entry = {.count = 1, .reusable = true}}, SHIFT(153),
  [313] = {.entry = {.count = 1, .reusable = true}}, SHIFT(120),
  [315] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__net_body, 4),
  [317] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [319] = {.entry = {.count = 1, .reusable = true}}, SHIFT(105),
  [321] = {.entry = {.count = 1, .reusable = true}}, SHIFT(108),
  [323] = {.entry = {.count = 1, .reusable = true}}, SHIFT(121),
  [325] = {.entry = {.count = 1, .reusable = true}}, SHIFT(158),
  [327] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_initial_marking_def, 2),
  [329] = {.entry = {.count = 1, .reusable = true}}, SHIFT(112),
  [331] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [333] = {.entry = {.count = 1, .reusable = true}}, SHIFT(168),
  [335] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [337] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [339] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_net_def, 3, .production_id = 1),
  [341] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__net_body, 7),
  [343] = {.entry = {.count = 1, .reusable = true}}, SHIFT(116),
  [345] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__net_body, 5),
  [347] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__net_body, 6),
  [349] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [351] = {.entry = {.count = 1, .reusable = true}}, SHIFT(134),
  [353] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [355] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [357] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [359] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [361] = {.entry = {.count = 1, .reusable = true}}, SHIFT(145),
  [363] = {.entry = {.count = 1, .reusable = true}}, SHIFT(148),
  [365] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [367] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__net_body, 2),
  [369] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [371] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [373] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__net_body, 3),
  [375] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [377] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [379] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_ptnet(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
