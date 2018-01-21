# Kata 1

Miguel Angel Montoya Z.

## Problem

Given two lists A and B, and B is an anagram of A. B is an anagram of A means B is made by randomizing the order of the elements in A.

We want to find an index mapping P, from A to B. A mapping P[i] = j means the ith element in A appears in B at index j.

These lists A and B may contain duplicates. If there are multiple answers, output any of them.

For example, given

``` c
A = [12, 28, 46, 32, 50]  B = [50, 12, 32, 46, 28]
```

We should return

``` c
[1, 4, 3, 2, 0]
```

as  P[0] = 1 because the  0th element of  A appears at  B[1], and  P[1] = 4 because the  1st element of  A appears at  B[4], and so on.

Note:

- A, B have equal lengths in range [1, 100].
- A[i], B[i] are integers in range [0, 10^5].

## Breakdown

- Length of A and B are the same. Min 1, max 100.
- Range of integers are in range [0, 10⁵]
- Dulicates may map to any other answer.
- Base Case

    Lenght 1

    A = [x] B = [x]

    P[0] = 0
- Base Case with duplicates

    Lenght 2

    A = [x, x] B = [x, x]

    P[0] = 1 P[1] = 0

## Solutions

### Simple slow solution

Going trought all of A elemnts would take O(n). Searching for one element in B takes O(n), and O(n²) for all elements, giving O(n + n²) as final complexity with O(n) as space complexity for the mapper's array.

### Faster solution

Go trought B elements once -O(n)-, storing the value and index in a hash table. If the entry is already there (Duplicate) add to linked list. O(1) amortized. Total O(n)

Go trought each element in A. Searching the value in the hash table. Always fixing the linked list if necessary. O(n) amortized.

Total O(2n)