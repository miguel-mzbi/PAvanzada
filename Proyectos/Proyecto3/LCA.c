#include "LCA.h"
#include "queue.h"

// DEBUG functionality. Prints connections table.
void printConnectionsDEBUG(unsigned int n, unsigned int **connections) {
    char *isDebug;
    isDebug = getenv("DEBUG");
    if(isDebug != NULL && !strcasecmp(isDebug, "y")) {
        fprintf(stderr, "CONNECTIONS:\n");
        for(int i = 1; i <= n; i++) {
            fprintf(stderr, "%i (%i nodes): ", i, connections[i][0]);
            for(int j = 1; j <= connections[i][0]; j++) {
                fprintf(stderr, "%i ", connections[i][j]);
            }
            fprintf(stderr, "\n");
        }
    }
}

// DEBUG functionality. Prints depths.
void printDepthsDEBUG(unsigned int n, unsigned int *depth) {
    char *isDebug;
    isDebug = getenv("DEBUG");
    if(isDebug != NULL && !strcasecmp(isDebug, "y")) {
        fprintf(stderr, "Depths:\n");
        for(int i = 1; i <= n; i++) {
            fprintf(stderr, "%i: %u\n", i, depth[i]);
        }
    }
}

// DEBUG functionality. Prints depths.
void printParentsDEBUG(unsigned int n, unsigned int *parents) {
    char *isDebug;
    isDebug = getenv("DEBUG");
    if(isDebug != NULL && !strcasecmp(isDebug, "y")) {
        fprintf(stderr, "Parents:\n");
        for(int i = 1; i <= n; i++) {
            fprintf(stderr, "%i: %u\n", i, parents[i]);
        }
    }
}

// Creates a single connection at connections.
// It works from a to b and from b to a.
void insertConnection(unsigned int a, unsigned int b, unsigned int **connections) {
    connections[a][0]++;
    connections[a][connections[a][0]] = b;
    connections[b][0]++;
    connections[b][connections[b][0]] = a;
}

// Build connections for each node. Each row in connections represents a node.
// The first position (0) at the array is the number of connections it contains.
// Followed by the node number that connects.
void buildConnections(FILE *file, unsigned int n, unsigned int **connections) {
    // Connections from node 0 non-existent.
    connections[0] = NULL;
    // Set up counter of connections per node. Init at 0.
    // Set up storage of origin and destination of connections.
    unsigned int a[n+1], b[n+1];
    unsigned int counter[n+1];
    for(int i = 1; i <= n; i++) {
        counter[i] = 0;
    }
    // Fill counters of node's connections.
    for(int i = 1; i < n; i++) {
        unsigned int aT, bT;
        fscanf(file, "%u %u\n", &aT, &bT);
        // Store connection's orgin and destination.
        a[i] = aT;
        b[i] = bT;
        printDebug("A: %u, B: %u\n", a[i], b[i]);
        // Increase by 1 each
        counter[aT]++;
        counter[bT]++;
    }
    // Allocate memory for each node connections at the connections table.
    // Item 0 of each array is the counter of connections the node has.
    for(int i = 1; i <= n; i++) {
        connections[i] = (unsigned int *) malloc((counter[i]+1) * sizeof(unsigned int));
        connections[i][0] = 0;
    }
    // Insert single connection to connections.
    for(int i = 1; i < n; i++) {
        insertConnection(a[i], b[i], connections);
    }
    printConnectionsDEBUG(n, connections);
}

void BFS(unsigned int root, unsigned int n, unsigned int ** connections,
unsigned int * parents, unsigned int *depth) {
    // Create queue for BFS.
    Queue* queue = createQueue(1000);
    // Visits array holds which nodes have been visited.
    unsigned int visits[n+1];
    for(int i = 1; i <= n; i++) {
        visits[i] = 0;
    }
    // Visited holds the number of nodes that have been visited.
    // Root node counts as visited.
    unsigned int visited = 1;
    visits[root] = 1;
    enqueue(queue, root);
    // While not all nodes have been visited.
    while(visited != n) {
        unsigned int frontNode = front(queue);
        unsigned int nodeConnections = connections[frontNode][0];
        // Iterate through first row of connections
        for(int i = 1; i <= nodeConnections; i++) {
            unsigned int currentConnection = connections[frontNode][i];
            // If current node hasn't been visited.
            // Set it's depth and parent. 
            // Insert to queue.
            if(visits[currentConnection] == 0) {
                enqueue(queue, currentConnection);
                depth[currentConnection] = depth[frontNode] + 1;
                parents[currentConnection] = frontNode;
                visits[currentConnection] = 1;
                visited++;
            }
        }
        // Dequeue and go to next
        dequeue(queue);
    }
    printDepthsDEBUG(n, depth);
    printParentsDEBUG(n, parents);
}

// Look for LCA in any subtree. 
// If the LCA is located in node 1's subtree or is the node 1, it will return 0 
// and will force a specific lookup in that subtree (finalTryLCA function).
// Else, the return statement will be the LCA.
unsigned int tryLCA(unsigned int root, unsigned int a, unsigned int b, unsigned int *parents, unsigned int *depth, unsigned int n) {
    // If a or b is the root, per definition, the LCA is the root.
    if(root == a || root == b) {
        return root;
    }
    // Create array for couloring
    unsigned int colors[n+1];
    for(int i = 1; i <= n; i++) {
        colors[i] = WHITE;
    }
    // Variables for iteration
    unsigned int nextA = a;
    unsigned int nextB = b;
    // Color those nodes as visited.
    colors[nextA] = BLACK;
    colors[nextB] = BLACK;
    // When both nexts are equal, means that that node is the potential LCA.
    // Will only be valid if any or both of the child nodes is not located in the
    // node 1 subtree.
    while(!(nextA == nextB && depth[nextA] == depth[nextB])) {
        // If A is further down
        if(depth[nextA] > depth[nextB]) {
            nextA = parents[nextA];
        }
        // If B is firther down
        else if(depth[nextA] < depth[nextB]) {
            nextB = parents[nextB];
        }
        // If both are at the same depth
        else {
            nextA = parents[nextA];
            nextB = parents[nextB];
        }
        // Colors both new nodes
        colors[nextA] = BLACK;
        colors[nextB] = BLACK;
    }
    // Varaibles for root testing and result storage.
    unsigned int currentRoot = root;
    unsigned int result = 0;
    // If the query's root is the node 1, and was visited,
    // Means that node 1 is the LCA.
    if(currentRoot == 1 && colors[currentRoot] == BLACK) {
        result = 1;
    }
    // If the query's root is the node 1,
    // then the ancestor found at the iteration, is the LCA
    else if(currentRoot == 1) {
        result = nextA;
    }
    else {
        // Tests the root's parents.
        // If we reach node 1, and no tested parent has been visited before,
        // means that the LCA is inside node 1's subtree.
        // inRoot1 variable stores if the LCA is in the node 1 subtree.
        unsigned int inRoot1 = 1;
        while(currentRoot != 1) {
            // If the root was visited trying to ascend to root 1,
            // means that the root is the LCA.
            if(colors[currentRoot] == BLACK) {
                result = currentRoot;
                // The LCA is not in the node 1 subtree.
                inRoot1 = 0;
                break;
            }
            // Moves to the parent of the root.
            currentRoot = parents[currentRoot];
        }
        // If the LCA is in node 1's subtree,
        // then the ancestor found at the iteration, is the LCA
        if(inRoot1) {
            result = nextA;
        }
    }
    return result;
}