# Proyecto 2

Miguel Angel Montoya Z.

## Problem A. Integeregex

In this problem, a valid regular expression is one of the following. In the following descriptions, E1, E2, etc. denote (not necessarily different) valid regular expressions.

- A decimal digit: that is, one of 0 1 2 3 4 5 6 7 8 9.
- Concatenation: E1E2.
- Disjunction: (E1|E2 |...|EN), for at least two expressions. Note that the outer parentheses are required.
- Repetition: (E1)*. Note that the outer parentheses are required.

``` text
For example, 7, 23, (7)*, (45)*, (1|2|3), ((2)*|3), (1|2|3), and ((0|1))* are valid expressions. (7), 4|5, 4*, (1|), and (0|1)* are not.
```

We say that an expression E matches a string of digits D if and only if at least one of the following is true:

- E = D.
- E = E1E2 and there exist D1 and D2 such that D = D1D2 and Ei matches Di.
- E = (E1| E2|...| EN) and one of the Ei matches D.
- E = (E1)* and there exist D1, D2, ..., DN for some non-negative integer N such that D = D1D2...DN and E1 matches each of the Di. In particular, note that (E1)* matches the empty string.

``` text
For example, the expression ((1|2))*3 matches 3, 13, 123, and 2221123, among other strings. However, it does not match 1234, 3123, 12, or 33, among other strings.
```

Given a valid regular expression R, for how many integers between A and B, inclusive, does R match the integer's base 10 representation (with no leading zeroes)?

### Input

__INPUT WAS MODIFIED. See BREAKDOWN.md for more information.__

The first line of the input gives the number of test cases, T. T test cases follow; each consists of two lines. The first line has two positive integers A and B: the inclusive limits of the integer range we are interested in. The second has a string R consisting only of characters in the set 0123456789()|*, which is guaranteed to be a valid regular expression as described in the statement above.

### Output

For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the number of integers in the inclusive range [A, B] that the the regular expression R matches.

### Limits

- 1 ≤ T ≤ 100.
- 1 ≤ A ≤ B ≤ 1018.
- 1 ≤ length of R ≤ 30.

### Sample

__INPUT WAS MODIFIED. See BREAKDOWN.md for more information.__

Input |
---|
h |
8 |
1 1000 |
(0)\*1(0)\* |
379009 379009 |
379009 |
1 10000 |
(12)\*(34)\* |
4 5 |
45 |
1 100 |
((0\|1))* |
1 50 |
(01\|23\|45\|67\|23) |
1 1000000000000000000 |
((0\|1\|2\|3\|4\|5\|6\|7\|8\|9))* |
1 1000 |
1(56\|(((7\|8))\*9)\*) |

## Breakdown

BREAKDOWN at [BREAKDOWN.md](BREAKDOWN.md)