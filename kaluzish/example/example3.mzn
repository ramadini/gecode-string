%% Minizinc model for example3.txt
%% Automatically generated by kaluzish
%% Requires MiniZinc version >= 1.6
include "gecode-string-pad.mzn";
include "gecode-string-ascii.mzn";
        
int: wordlen;
set of int: widx = 1..wordlen;

var 0..wordlen: len_T3_1; array[widx] of var symbols: T3_1;
constraint str_pad(T3_1, len_T3_1);
var 0..wordlen: len_T0_1; array[widx] of var symbols: T0_1;
constraint str_pad(T0_1, len_T0_1);
var 0..wordlen: len_T2_1; array[widx] of var symbols: T2_1;
constraint str_pad(T2_1, len_T2_1);
var bool: T_2;
var 0..wordlen: len_var_0xINPUT_2; array[widx] of var symbols: var_0xINPUT_2;
constraint str_pad(var_0xINPUT_2, len_var_0xINPUT_2);
var 0..wordlen: len_T1_1; array[widx] of var symbols: T1_1;
constraint str_pad(T1_1, len_T1_1);
var int: PCTEMP_LHS_1;

%% DFAs
% \in /["']/
int: MZN_DFA_2_Q = 3;
int: MZN_DFA_2_q0 = 1; set of int: MZN_DFA_2_F = { 2 };
array[1..MZN_DFA_2_Q,1..max_symbol] of int: MZN_DFA_2_d = [|
  % State 1
    0, 0, 2, 0, 0, 0, 0, 2, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0|
  % State 2
    0, 0, 3, 0, 0, 0, 0, 3, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0|
  % State 3
    0, 0, 3, 0, 0, 0, 0, 3, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0|];

% \notin /["']/
int: MZN_DFA_1_Q = 2;
int: MZN_DFA_1_q0 = 1; set of int: MZN_DFA_1_F = { 1 };
array[1..MZN_DFA_1_Q,1..max_symbol] of int: MZN_DFA_1_d = [|
  % State 1
    1, 1, 2, 1, 1, 1, 1, 2, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1|
  % State 2
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2|];
%%% constant strings

constraint str_concat(T0_1, len_T0_1, T1_1,  len_T1_1, var_0xINPUT_2, len_var_0xINPUT_2 );
constraint str_regular(T0_1, len_T0_1, MZN_DFA_1_Q, max_symbol, MZN_DFA_1_d, MZN_DFA_1_q0, MZN_DFA_1_F);
constraint str_concat(T2_1, len_T2_1, T3_1,  len_T3_1, T1_1, len_T1_1 );
constraint PCTEMP_LHS_1 == len_T0_1;
constraint str_regular(T2_1, len_T2_1, MZN_DFA_2_Q, max_symbol, MZN_DFA_2_d, MZN_DFA_2_q0, MZN_DFA_2_F);
constraint 0 < len_T2_1;
constraint T_2 <-> PCTEMP_LHS_1 == 6;
constraint T_2 == true;

solve satisfy;

output ["var_0xINPUT_2=\""] ++ [ascii[fix(var_0xINPUT_2[i])] | i in 1..fix(len_var_0xINPUT_2)] ++ ["\"\n"];
        
