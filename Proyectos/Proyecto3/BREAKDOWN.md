# Proyecto 3 Breakdown

Miguel Angel Montoya Z.

## Algorithm

The algorithm works using the theory of trees.
We start by building a tree where the node 1 is the root. Store the parent and depth of each node, given thant 1 is the root. This will be done before reading any query. So regardless of the root's query, the built tree in memory will have node 1 as the root.

Given two nodes (And a root, but we will not care about that right now), we must find its LCA, using the following algorithm.

### Algorithm of ascension

Just to be clearer about how is the algorithm of ascension implemented.

If the given nodes are a and b, and have a depth of 5 and 3 (Respectively), the ascension through parents will only work (At the start) on node b, until we reach a ancestor of a at the same depth of b. Then, both "pointers" ascend until the pointed node is the same. This is the LCA (More or less, some checks are necessary).

### Different roots

If the query's root is 1, we only have to iterate (Ascend) through parents, until both the iteration of a's parents and b's parents reach the same node. That is the LCA.

The thing is, that this must change if the root isn't 1. Right? Well, no... usually. In most of the cases, the depths are maintained (Not the exact depth, but the depth of a node relative to the other). In some cases, the parent of a node is respected (Before you reach node 1, were new rules apply). But this doesn't mean that when the rules don't apply, there is nothing we can do. The only necessary thing to do is to apply a new set of small changes to the known rules.

I'm going to explain those changes now, on each of the 6 cases for the algorithm.

#### Case 1: Any of the given start nodes is the given root

If the given nodes are a and b, and the root is or b, the LCA is the root, as the rules for trees state.

#### Case 2: The given root is 1

If the given root is 1, then, the ascension algorithm is implemented. It's result will be the LCA.

#### Case 3: The given root is not 1, and both testing nodes are located in node 1's subtree

If both the nodes are inside the node 1 subtree, the rest of the tree becomes useless, as the LCA will be forcefully inside the subtree. In fact, the rules work as if the rest of the tree didn't exist (As if the nodes outside of the subtree didn't exist in the computed tree).

#### Case 4: The given root is not 1, and both testing nodes are located outside node 1's subtree

In this case, similar to the case above. The algorithm works as if the root of the tree was actually in fact 1.
In the computed tree, both given nodes are inside the give root's subtree. Even though the root isn't the given root, the rules work the same. We can consider the rest of the tree as if it didn't exist, because in the worst case, the given root will be the LCA, and no more nodes outside the subtree will be examined.

#### Case 5: The given root is not 1, and one of the testing nodes is located inside node 1's subtree

This might be one of the most complicated cases to understand at first, but in fact by far, one of the simpler ones. During the ascension of the node outside the node 1's subtree, it will pass trough the given root, and change its color. This is the crucial part. Because each node is located inside different subtrees, the LCA of each subtree wil be in fact, the given root.

### Case 6: The given root is not 1, and it's located in a depth below any give node

Another complicated case to program, but quite simple to understand. The LCA will be one of two given nodes. The algorithm takes the given root and ascends alone. When it finds a colored node (Which must be one of the original nodes), it would have found the LCA. Why? Because any path to reach the give root, will go trough the found node first, making it the LCA.