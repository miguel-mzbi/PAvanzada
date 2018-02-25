# Kata 4

Miguel Angel Montoya Z.

## Problem

Validate if a given string is numeric.

Some examples:

``` C
"0" => true
"0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
```

Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.

## Breakdown

- Only numbers, e, periods and commas can be used.
- You can have a integer with only numbers or number and commas (Properly placed). There can't be any quantity of zeros to the left.
- A decimal number has numbers and optional commas before the only period, and only numbers after it.
- Exponential numbers are an extension of the decimal numbers. This means that the characters before the e have the same rules as the previous one, and the ones after are only numbers. (This means 2.0e10 its valid, but not 2e10)
- If commas are used, those must appear every 3 characters. (This means 1,000,000000 isn't valid, but 1,000,000,000 is)
- Accepted cases:

``` C
"1"
"1000"
"1,000"
"1000.12345"
"1,000.12345"
"1000.12345e6789"
"1,000.12345e6789"
```

## Solution

The solution is simple. The problem can be solved in O(n). Using a cycle of nested conditionals.
There are three parts in a number that can be checked independently to make sure the input is a number:

- The integer (Obligatory) part. Before the period.
- The decimal (Optional, requires previous) After the period.
- The exponent (Optional, requires previous two) After the e.