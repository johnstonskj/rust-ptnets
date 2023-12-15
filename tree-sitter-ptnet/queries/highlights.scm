[
 "net"
 "place"
 "transition"
 "arc"
 "defaults"
 "tokens"
 "initial"
 "marking"
 "public"
 ] @keyword

;; -----------------------------------------------------------------------
;; Net definition
;; -----------------------------------------------------------------------
(net_def
 (name) @module.definition
 [ "{" "}" ]  @punctuation.bracket)

(defaults [ "{" "}" ] @punctuation.bracket)

(subnet_def
 (name) @module.definition
 [ "{" "}" ]  @punctuation.bracket)

(public_places (name) @type)

;; -----------------------------------------------------------------------
;; Tokens
;; -----------------------------------------------------------------------
(tokens "*" @operator)

[
 (token_set_boolean)
 (token_set_integer)
 (token_set_natural)
 (token_set_positive)
 (token_set_strings)
 (unit_type)
 ] @type.builtin

(set_type [ "{" "}" ]  @punctuation.bracket (name) @type)
(set_type ","  @punctuation.separator)

(tuple_type [ "<" ">" ]  @punctuation.bracket (name) @type)
(tuple_type ","  @punctuation.separator)

;; -----------------------------------------------------------------------
;; Place definition
;; -----------------------------------------------------------------------
(place_def (name) @type.definition)
(place_def "," @punctuation.separator)

(place_body [ "{" "}" ] @punctuation.bracket)

;; -----------------------------------------------------------------------
;; Transition definition
;; -----------------------------------------------------------------------
(transition_def (name) @type.definition)
(transition_def "," @punctuation.separator)

(transition_body [ "{" "}" ] @punctuation.bracket)

;; -----------------------------------------------------------------------
;; Arc definition
;; -----------------------------------------------------------------------
(arc_expression [ (normal_arc) (inhibitor_arc) (reset_arc) ] @operator)

(arc_name_or_expression (name) @type) ;; source and targets
(arc_name_or_expression [ "(" ")" ] @punctuation.bracket) ;; source and targets

(arc_body [ "{" "}" ] @punctuation.bracket)

;; -----------------------------------------------------------------------
;; Properties and Constraints
;; -----------------------------------------------------------------------
(label_property "label" @property "=" @operator)

(capacity_constraint "capacity" @property "=" @operator)

(duration_constraint "duration" @property "=" @operator)

(priority_constraint "priority" @property "=" @operator)

(weight_constraint "weight" @property "=" @operator)

;; -----------------------------------------------------------------------
;; Marking
;; -----------------------------------------------------------------------
(marking_def [ "{" "}" ] @punctuation.bracket)

(marking_assignment (name) @type "=" @operator)

;; -----------------------------------------------------------------------
;; Values
;; -----------------------------------------------------------------------
[
 (boolean)
 (infinity)
 ] @constant.builtin

[
 (unsigned)
 (positive_unsigned)
 ] @number

(quoted_string) @string

(duration_immediate) @operator

(duration_interval [ "[" "]" "(" ")"] @punctuation.bracket)
(duration_interval ","  @punctuation.separator)

(set_value [ "{" "}" ]  @punctuation.bracket)
(set_value ","  @punctuation.separator)

(multiset_value [ "[" "]" ]  @punctuation.bracket)
(multiset_value ","  @punctuation.separator)

(counted_value (name) @type)

(tuple_value [ "<" ">" ]  @punctuation.bracket)
(tuple_value ","  @punctuation.separator)
