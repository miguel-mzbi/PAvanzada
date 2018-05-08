#include "LCA.h"

#define FILENAME "LCA.txt"

int main(int argc, char **argv) {

    FILE *file = fopen(FILENAME, "r");
    
    // Number of vertices
    unsigned int n;
    fscanf(file, "%u\n", &n);
    printDebug("N: %u\n", n);
    // Allocate memory for connections
    unsigned int **connections = (unsigned int **) malloc((n+1) * sizeof(unsigned int *));
    // Build connections from file
    buildConnections(file, n, connections);
    // Build parents array and depth array from executing a BFS starting at node 1.
    unsigned int parents[n+1];
    unsigned int depth[n+1];
    for(int i = 1; i <= n; i++) {
        parents[i] = 0;
        depth[i] = 0;
    }
    // Realize BFS to set up parents and depth of nodes.
    // More info of the reasons for doing this in the BREAKDOWN.md
    BFS(1, n, connections, parents, depth);
    // Number of queries
    unsigned int q;
    fscanf(file, "%u", &q);
    printDebug("Q: %u\n", q);
    // Go through queries
    while(q--) {
        // Read query
        unsigned int r, u, v;
        fscanf(file, "%u %u %u\n", &r, &u, &v);
        printDebug("R: %u, U: %u, V: %u\n", r, u, v);

        // Answer storage
        unsigned int answer;
        // Try to gather LCA considering importance of root (Maybe not 1).
        // LCA may be on a subtree of node 1, or on a subtree superior to node 1.
        answer = tryLCA(r, u, v, parents, depth, n);
        if(answer != 0) {
            printf("LCA: %u\n", answer);
        }
        else {
            printf("Unexpected error. Couldn't find LCA.\n");
        }
    }
    
    fclose(file);
    return 0;
}