#include "NFAExecution.h"

int exists(DynTransArray a, transition t) {
    for(int i = 0; i < a.used; i++) {
        //printDebug("~~~~~~~~~~~~~~~  %i == %i && %i == %i\n", t.vertexFrom, a->array[i].vertexFrom, t.vertexTo, a->array[i].vertexTo);
        if(t.vertexFrom == a.array[i].vertexFrom && t.vertexTo == a.array[i].vertexTo) {
            printDebug("FOUND!\n");
            return 1;
        }
    }
    return 0;
}

void findVertices(NFA a, DynVertexArray *results, int origin, char symbol) {
    DynTransArray transitions = a.transitions;
    int transitionsNum = a.transitions.used;
    
    DynVertexArray vertexStack;
    initVertexArray(&vertexStack, a.vertices.used);
    
    DynTransArray testedTransitions;
    initTransitionArray(&testedTransitions, 50);

    pushVertex(&vertexStack, origin);
    while(vertexStack.used > 0) {
        int currentVertex = popVertex(&vertexStack);       

        for(int i = 0; i < transitionsNum; i++) {
            transition currTransition = transitions.array[i];

            if(currTransition.vertexFrom != currentVertex) {
                continue;
            }
            int ex = exists(testedTransitions, currTransition);
            if(ex) {
                continue;
            }
            else if(currTransition.transitionSymbol == empty) {
                pushTransition(&testedTransitions, currTransition);
                printDebug("\t\tEpsilon from %i to %i\n", currentVertex, currTransition.vertexTo);
                pushVertex(&vertexStack, currTransition.vertexTo);
            }
            else if(currTransition.transitionSymbol == symbol) {
                pushTransition(&testedTransitions, currTransition);
                printDebug("\t\tFound from %i to %i\n", currentVertex, currTransition.vertexTo);
                pushVertex(results, currTransition.vertexTo);
            }
        }
    }
}

int findEnd(NFA a, int origin) {
    int finalState = a.finalState;
    if(origin == finalState) return 1;

    DynTransArray transitions = a.transitions;
    int transitionsNum = a.transitions.used;
    
    
    DynVertexArray vertexStack;
    initVertexArray(&vertexStack, a.vertices.used);

    pushVertex(&vertexStack, origin);
    int w = 0;

    printDebug("SEARCHING FOR END USING EPSILON TRANSITIONS\n");
    while(vertexStack.used > 0) {
        int currentVertex = popVertex(&vertexStack);
        for(int i = 0; i < transitionsNum; i++) {
            transition currTransition = transitions.array[i];
            if(currTransition.vertexFrom != currentVertex) continue;
            if(currTransition.vertexTo == finalState) {
                printDebug("\tFound from %i to %i:\n", currentVertex, currTransition.vertexTo);
                return 1;
            }
            else if(currTransition.transitionSymbol == empty) {
                printDebug("\tEpsilon from %i to %i\n", currentVertex, currTransition.vertexTo);
                pushVertex(&vertexStack, currTransition.vertexTo);
            }
        }
        w++;
    }
    return 0;
}

int executeNFA(NFA a, char *test) {
    // printf("Testing %s\t", test);
    DynTransArray transitions = a.transitions;
    DynVertexArray vertices = a.vertices;
    int testLen = strlen(test);
    int finalState = getFinalState(&a);

    DynVertexArray toTest;
    initVertexArray(&toTest, vertices.used);
    pushVertex(&toTest, 0);
    
    for(int i = 0; i < testLen; i++) {
        DynVertexArray temp;
        initVertexArray(&temp, vertices.used);

        printDebug("---- It i. %i:  C:%c\n", i, test[i]);
        int s = toTest.used;
        for(int j = 0; j < s; j++) {
            int t = popVertex(&toTest);
            pushVertex(&temp, t);
        }
        int r = temp.used;
        for(int j = 0; j < r; j++) {
            printDebug("\tIt j. %i:   ", j);
            int v = popVertex(&temp);
            printDebug("V: %i\n", v);
            findVertices(a, &toTest, v, test[i]);
        }
        freeVertexArray(&temp);
        printDebug("\tRES: ");
        for(int i = 0; i < toTest.used; i++) {
            printDebug("%i ", toTest.array[i]);
        }
        printDebug("\n");
    }

    for(int i = 0; i < toTest.used; i++) {
        if(findEnd(a, toTest.array[i])) {
            // printf("VALID!\n");
            return 1;
        }
    }
    // printf("NOT ACCEPTED!\n");
    return 0;
}