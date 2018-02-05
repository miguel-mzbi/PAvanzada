# Kata 3

Miguel Angel Montoya Z.

## Problem

Initially, there is a Robot at position (0, 0). Given a sequence of its moves, judge if this robot makes a circle, which means it moves back to the original place.

The move sequence is represented by a string. And each move is represent by a character. The valid robot moves are R (Right), L(Left), U (Up) and D (down). The output should be true or false representing whether the robot makes a circle.

Example 1:

`Input: "UD"  Output: true`

Example 2:

`Input: "LL"  Output: false`

## Breakdown

- Must make sure the robot return to origin
- The robot doesn't move diagonally.
- If steps are considered always unitary, each left must have its right, and each up, must have its corresponding down.
- Easy solution. Just count horizontal and vertical movement independently. 
- Cases:

``` C
Input: ""
Robot did not move, output is true.

Input: "UD"
verticalC is incremented by 1 when reading 'U', and then decreased to 0 when reading 'D'. Robot returned to origin, output is true.

Input: "UDR"
verticalC is incremented by 1 when reading 'U', and then decreased to 0 when reading 'D'. horizontalC is then incremented by 1 when reding 'R' but never decremented. Robot did not returned to origin, output is false.
```

## Solution

With two variables, horizontalCount and verticalCount, one iteration trough the list would be enough to determine if the output is true. Each left and down would decrease the value of its corresponding axis, while each up and right would increment it. If both variables are 0 when the string reading is done, the output would be true.

Time complexity is O(n), because the problem requires only one iteration trough the string. With O(n) space complexity to store the string.