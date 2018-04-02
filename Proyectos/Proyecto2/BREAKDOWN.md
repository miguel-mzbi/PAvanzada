# Proyecto 2 Breakdown

Miguel Angel Montoya Z.

## Step 1

I had to investigate the [Thompson Construction Algorithm](https://en.wikipedia.org/wiki/Thompson%27s_construction) to create the NFA.

NFA's keywords:

* Concatenation: E = E1E2 and there exist D1 and D2 such that D = D1D2 and Ei matches Di.
* Union: E = (E1| E2|...| EN) and one of the Ei matches E.
* Kleene: E = (E1)* and there exist D1, D2, ..., DN for some non-negative integer N such that D = D1D2...DN and E1 matches each of the Di. In particular, note that (E1)* matches the empty string.
* Transition: Available movement between two states. In NFAs, there are epsilon (ε) transitions, this means that you can move to another state without consuming a symbol.

Thompson's algorithm works as follows:

1. Read the REGEX from left to right. Build an operands stack (Containing already built NFAs) and operator stack (Containing symbols)
2. If and operand symbol comes up, consume it and build its basic NFA.
    1. Build an NFA with 2 vertices (Initial and final).
    2. Add a transition from the initial to the final state that consumes the operand.
    3. Push into the operands stack
3. If an operation symbol, that isn't a closing parenthesis, push it to the operators stack.
4. If a closing parenthesis appears, pop operators in the stack until an open parenthesis appears. Count the operations and execute code if its concatenation symbols or union symbols:
    * If concatenation, pop 2 operands (NFAs) and concatenate them. Repeat until the operator counter (The number of operators you popped of the stack) reaches 0:
        1. Make a new epsilon ε-transition between the final state of A and the initial state of B.
        2. Set the final stet of B as the final state for this new NFA.
        3. Push into the operands stack.
    * Else if union, pop n operands (NFAs) and put them into an array, and make union. n is the counter of operator you found earlier:
        1. Make two new states (Initial and final).
        2. Make an ε-transition from the new initial state to each of the popped initial states.
        3. Make an ε-transition from each of the final states of the array, to the new final state.
        4. Push into the operands stack.
    * On either case, if the next symbol of the REGEX is a kleene symbol, do the following after previous operations are done.:
        1. Pop the first operand (NFA) in the stack.
        2. Add two new states (Initial and final).
        3. Make an ε-transition from the new initial the the NFA's initial state.
        4. Make an ε-transition from the NFA's final state to the nnew final state.
        5. Make an ε-transition from the NFA's final state to the NFA's initial state.
        6. Make an ε-transition from the new initial state to the new final state.
        7. Push into the operands stack.
5. Do until no more symbols are left.
6. Return the (In theory) unique item in the operands stack. This would be the final NFA.

## Step 2

The process to test if a string is valid is far simpler.

* Start with the set of possible states containing only the initial state (q).
* For each character C in the string:
  * For each of the last possible states:
    * Find all the states that can be reached by ε-transitions then a transition on C.
    * Add these to the new set of all possible states.

This provides a set of states, that might oor might not contain the final state. But this doesn't mean the string shouldn't be accepted. This means that there might be n ε-transitions to execute to reach the final state:

* From the last set of possible states:
  * If the accepting state (f) is reached from any of these states by ε-transitions then the NFA (and the regular expression) match.

## Modification of input

Because some difficulties on development. I modified the requirements for the input. Concatenations need parenthesis to work. 123 won't work, (123) will work.

### Sample

Input |
---|
h |
8 |
1 1000 |
(0)\*1(0)\* |
379009 379009 |
(379009) |
1 10000 |
((12))\*((34))\* |
4 5 |
(45) |
1 100 |
((0\|1))* |
1 50 |
((01)\|(23)\|(45)\|(67)\|(23)) |
1 1000000000000000000 |
((0\|1\|2\|3\|4\|5\|6\|7\|8\|9))* |
1 1000 |
1((56)\|(((7\|8))\*9)\*) |