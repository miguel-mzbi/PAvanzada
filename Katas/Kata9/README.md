# Kata 9

Miguel Angel Montoya Z.

## Problem

You've built an inflight entertainment system with on-demand movie streaming.

Users on longer flights like to start a second movie right when their first one ends, but they complain that the plane usually lands before they can see the ending. So you're building a feature for choosing two movies whose total runtimes will equal the exact flight length.

Write a function that takes an integer flight_length (in minutes) and a list of integers movie_lengths (in minutes) and returns a boolean indicating whether there are two numbers in movie_lengths whose sum equals flight_length.

When building your function:

- Assume your users will watch exactly two movies
- Don't make your users watch the same movie twice
- Optimize for runtime over memory

## Breakdown

Assuming the longest flight is of 17 hours (Dubai to Panama on Emirates), that is 1020 minutes, and the properties of addition (Commutation); an array of size 1024 initialized with 0 can be used as a table, where the if the value of the index i is 1, means that a movie with length i exists.

## Solution

The solution is simple. First we must allocate the array to save the lengths of the movie as index of the table. This requires one full iteration of the array of movie lengths. After that the array will have values of 1 in the index of the movie that exists. (This is O(n))

After that, another full iteration (Worst case) is needed. This one checks if flightTime - movieTime exists (has a 1) in the table. If so, a pair exists. (This is O(n))

Giving the process a total complexity of O(2n).