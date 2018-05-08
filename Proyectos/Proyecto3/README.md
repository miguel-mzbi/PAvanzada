# Proyecto 3

Miguel Angel Montoya Z.

## Problem Lowest Common Ancestor

In a rooted tree, the lowest common ancestor (or LCA for short) of two vertices u and v is defined as the lowest vertex that is ancestor of both that two vertices.

Given a tree of N vertices, you need to answer the question of the form "r u v" which means if the root of the tree is at r then what is LCA of u and v.

### Input

The first line contains a single integer N. Each line in the next N - 1 lines contains a pair of integer u and v representing a edge between this two vertices.

The next line contains a single integer Q which is the number of the queries. Each line in the next Q lines contains three integers r, u, v representing a query.

### Output

For each query, write out the answer on a single line.

### Limits

- 1 ≤ N, Q ≤ 2 × 10^5

### Sample

Input | Output
------|-------
4     |
1 2   |
2 3   |
1 4   |
2     |
1 4 2 | 1
2 4 2 | 2

### Explanation

Explanation

- "1 4 2": If 1 is the root, it is parent of both 2 and 4 so LCA of 2 and 4 is 1.
- "2 4 2": The root of the tree is at 2, according to the definition, LCA of any vertex with 2 is 2.

## Breakdown

BREAKDOWN at [BREAKDOWN.md](BREAKDOWN.md)