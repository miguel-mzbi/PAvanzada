# Kata 7 - Coding Games - "Shadows of the Knight - Episode 1"

Miguel Angel Montoya Z.

## Problem

Batman will look for the hostages on a given building by jumping from one window to another using his grapnel gun. Batman's goal is to jump to the window where the hostages are located in order to disarm the bombs. 

Unfortunately he has a limited number of jumps before the bombs go off...

### Rules

Before each jump, the heat-signature device will provide Batman with the direction of the bombs based on Batman current position:

    U (Up)
    UR (Up-Right)
    R (Right)
    DR (Down-Right)
    D (Down)
    DL (Down-Left)
    L (Left)
    UL (Up-Left)


Your mission is to program the device so that it indicates the location of the next window Batman should jump to in order to reach the bombs' room as soon as possible.

Buildings are represented as a rectangular array of windows, the window in the top left corner of the building is at index (0,0).

## Breakdown

It's necessary to compare during each iteration the input to decide what action to do. The direction of the bomb should decide to which position to move next.

### Simple -unpractical- Solution

Depending on each input, move 1 position towards the bomb. This approach does work on cases where the number of moves are unlimited or at least very high.

This solution is O(n).

(It doesn't pass every case in CodingGames)

### Efficient Solution

Implement a binary search. For this to work, 4 new variables are needed, one for each max position to the right, left, up and down. This is because we are going to be making the possible bomb zone smaller each iteration.

For example, if the bomb is up: First, we mark out current position as the lower limit, and the move to the middle of the available vertical positions (VerticalMax + VerticalMin)/2.

This solution is O(log2(n))