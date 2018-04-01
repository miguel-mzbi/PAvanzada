#include "Thompson.h"
// Initialize NFA
void initNFA(NFA *a) {
    a->finalState = 0;
    DynTransArray transitions;
    initTransitionArray(&transitions, 50);
    a->transitions = transitions;
    DynVertexArray vertices;
    initVertexArray(&vertices, 50);
    a->vertices = vertices;
}

// Returns the number of vertices in a.
int getVertexCount(NFA *nfa) {
    return nfa->vertices.used;
}

// Sets the number of vertices of the NFA.
void setVertices(NFA *nfa, int noVertices) {
    DynVertexArray *vertices =  &nfa->vertices;
    freeVertexArray(vertices);
    for(int i = 0; i < noVertices; i++) {
        insertVertexArray(&nfa->vertices, i);
    }
}

// Sets a transition of the NFA.
void setTransition(NFA *nfa, int vertexFrom, int vertexTo, char transitionSymbol) {
    transition newTransition;
    newTransition.vertexFrom = vertexFrom;
    newTransition.vertexTo = vertexTo;
    newTransition.transitionSymbol = transitionSymbol;
    insertTransitionArray(&(nfa->transitions), newTransition);
}

// Sets the final state of the NFA.
void setFinalState(NFA *nfa, int finalState) {
    nfa->finalState = finalState;
}

// Returns the index of the final state of the NFA.
int getFinalState(NFA *nfa) {
    return nfa->finalState;
}

// f(E = E1E2)
// Makes a concatenation between E1 and E2.
// Inserts an ε-transition from the final state of E1 to the initial state of E2.
NFA concatenate(NFA a, NFA b) {
    NFA final;
    initNFA(&final);
    // Add no new vertices, but new NFA must have the sum of both.
    setVertices(&final, getVertexCount(&a) + getVertexCount(&b));
    
    // All the transitions in 'a' stay in the same 'positions', but in the new NFA.
    for(int i = 0; i < a.transitions.used; i++) {
        transition newTransition = a.transitions.array[i];
        setTransition(&final, 
                    newTransition.vertexFrom,
                    newTransition.vertexTo, 
                    newTransition.transitionSymbol);
    }
    // ε-transition tha provides the 'concatenation' logic.
    setTransition(&final,
                    getFinalState(&a),
                    getVertexCount(&a), 
                    empty
                );

    int displacement = getVertexCount(&a);    
    // All the transitions in b must be displaced by the number of vertex in a.
    for(int i = 0; i < b.transitions.used; i++) {
        transition newTransition = b.transitions.array[i];
        setTransition(&final, 
                newTransition.vertexFrom + displacement,
                newTransition.vertexTo + displacement, 
                newTransition.transitionSymbol);
    } 
    // The new final state is b's final state.
    setFinalState(&final, getVertexCount(&a) + getVertexCount(&b) -1);
    return final;
}

// f(E =(E1)*)
// Kleene start (Can be 0 or many).
NFA kleene(NFA a) {
    NFA final;
    initNFA(&final);
    transition newTransition;

    // Add two new vertices (new initial and final state).
    setVertices(&final, getVertexCount(&a) +2);
    // ε-transition from new initial state to a's initial state.
    setTransition(&final, 0, 1, empty);
    // Translate each transition in a by one, to take into account new initial state.
    for(int i = 0; i < a.transitions.used; i++) {
        newTransition = a.transitions.array[i];
        setTransition(&final,
                        newTransition.vertexFrom +1,
                        newTransition.vertexTo +1,
                        newTransition.transitionSymbol);
    }
    // ε-ransition from a's final state to new final state.
    setTransition(&final,
                    getVertexCount(&a),
                    getVertexCount(&a) +1,
                    empty
                );
    // ε-transition from a's final state to a's initial state.
    // This is to apply the 'many' logic.
    setTransition(&final,
                    getVertexCount(&a),
                    1,
                    empty
                );
    // ε-transition from the new initial state to the new final state.
    // This is to apply the '0' logic.
    setTransition(&final,
                    0,
                    getVertexCount(&a) +1,
                    empty
                );
    // Sets the new final state.
    setFinalState(&final, getVertexCount(&a) +1);

    return final;
}

// f(E = (E1|E2|...|EN))
// Makes an union between all the NFA. 
// The logic is: To reach the end state, you must pass any of the Es, but no more than 1.
// Inserts an ε-transition from the initial state to each E's inital state.
// Inserts an ε-transition to the final state from each E's final state.
NFA or(DynNFAArray orSelections, int noSelections) {
    NFA final;
    initNFA(&final);
    transition newTransition;
    // Counter for the vertices that the new NFA will have. Starts with 2 (Initial and final).
    int vertexCount = 2;
    // Adds to the counter the number of vertices of each NFA.
    for(int i = 0; i < noSelections; i++) {
        vertexCount += getVertexCount(&orSelections.array[i]);
    }

    setVertices(&final, vertexCount);
    NFA temp;
    // Counter for the displacement of allocating each NFA. Starts with 1 (Only initial state).
    int displacementCounter = 1;
    // Iteration of all the NFAs in the or selection
    for(int i = 0; i < noSelections; i++) {
        setTransition(&final, 0, displacementCounter, empty);
        temp = orSelections.array[i];
        // Iteration of the transitions in temp
        for(int j = 0; j < temp.transitions.used; j++) {
            newTransition = temp.transitions.array[j];
            setTransition(&final,
                            newTransition.vertexFrom + displacementCounter,
                            newTransition.vertexTo + displacementCounter,
                            newTransition.transitionSymbol);
        }
        // Adds to the displacement the vertex count of the current temp NFA
        displacementCounter += getVertexCount(&temp);
        // Sets an ε-transition from the current selection final state to the final state.
        setTransition(&final, displacementCounter -1, vertexCount -1, empty);
    }
    setFinalState(&final, vertexCount -1);
    return final;
}

// Utility functions
int isOperator(char c) {
    if(c == '(' || c == ')' || c == '*' || c == '|' || c == '.') return 1;
    else return 0;
}

int isNumber(char c) {
    if(c == '1' || c == '2' || c == '3' || c == '4' || c == '5'
    || c == '6' || c == '7' || c == '8' || c == '9' || c == '0') return 1;
    else return 0;
}

int isParClose(char c) {
    if(c == ')' || c == '*') return 1;
    else return 0;
}

int isParOpen(char c) {
    if(c == '(') return 1;
    else return 0;
}

void insert(char *string, char *insert, int pos) {
    char buf[1024] = {};
    strncpy(buf, string, pos);
    int len = strlen(buf);
    strcpy(buf+len, insert);
    len += strlen(insert);
    strcpy(buf+len, string+pos);
    strcpy(string, buf);
}

// Transforms a REGEX into an NFA
NFA REGEXtoNFA(char *regex) {
    printf("\n\nREGEX: ");
    printf("%s\n", regex);
    int regexSize = strlen(regex);

    char prevSymbol = '&';
    char currSymbol;
    char *modREGEX = (char *) calloc(regexSize *2, sizeof(char));
    strcpy(modREGEX, regex);
    int j = 1;
    // Add initial parenthesis
    insert(modREGEX, "(", 0);
    // Add final parenthesis
    insert(modREGEX, ")", strlen(modREGEX));
    // Add a '.' to indicate concatenation
    for(int i = 0; i < regexSize; i++, j++) {
        currSymbol = regex[i];
        if((isNumber(prevSymbol) && isNumber(currSymbol))
        || (isNumber(prevSymbol) && isParOpen(currSymbol))
        || (isParClose(prevSymbol) && isNumber(currSymbol))
        || (isParClose(prevSymbol) && isParOpen(currSymbol))) {
            insert(modREGEX, ".", j);
            j++;
        }
        // Switch kleene to be an inside parenthesis operation (Like concatenation and union)
        // else if(currSymbol == '*' && prevSymbol == ')') {
        //     modREGEX[j] = ')';
        //     modREGEX[j-1] = '*';
        // }
        prevSymbol = currSymbol;
    }

    printDebug("MODIFIED REGEX:\n");
    printDebug("%s\n", modREGEX);



    // Storage of pending NFA to assign
    DynNFAArray operandsStack;
    initNfaArray(&operandsStack, regexSize);
    // Storage of pending symbols to assign
    CharStack operatorsStack;
    initCharArray(&operatorsStack, regexSize);

    int skipnext = 0;
    // Current symbol of the REGEX
    char currentSymbol;
    // Iteration through the complete modREGEX
    for(int i = 0; i < strlen(modREGEX); i++) {
        currentSymbol = modREGEX[i];
        printDebug("\n---- It. %i: ", i);
        
        if(skipnext) {
            printDebug("KLEENING");
            skipnext = 0;
            pushNFA(&operandsStack, kleene(popNFA(&operandsStack)));
            continue;
        } 

        // If the symbol is a number, setup it's basic NFA and store in the stack
        // One symbol NFA just consist of an initial state, a final state and a transition that consumes that symbol.
        if(!isOperator(currentSymbol)) {
            printDebug("NUM ---- %c\t", currentSymbol);
            NFA newNFA;
            initNFA(&newNFA);
            setVertices(&newNFA, 2);
            setTransition(&newNFA, 0, 1, currentSymbol);
            setFinalState(&newNFA, 1);
            pushNFA(&operandsStack, newNFA);
        }
        // It's an operation
        else {
            printDebug("SYM ---- %c\t", currentSymbol);
            if(currentSymbol == '(') {
                pushChar(&operatorsStack, currentSymbol);
            }
            else if(currentSymbol == '.') {
                pushChar(&operatorsStack, currentSymbol);
            }
            else if(currentSymbol == '|') {
                pushChar(&operatorsStack, currentSymbol);
            }
            // All operations are stored in the stack, except kleene, which is done inmediatly on the iteration before.
            // This is because kleene is applied to a single alredy done NFA.
            // Other operations are consumed when the closing parenthesis is evaluated.
            // Closed parenthesis evaluation
            else {
                int operationCount = 0;
                char curr;
                char operationSymbol = topChar(&operatorsStack);
                // If the parenthesis encloses nothing, delete the open parenthesis and continue.
                if(operationSymbol == '(') {
                    popChar(&operatorsStack);
                    for(int k = 0; k < operatorsStack.used; k++) {
                        printDebug("%c",operatorsStack.array[k]);
                    }
                    if(modREGEX[i+1] == '*') {
                        skipnext = 1;
                    }
                    continue;
                }
                // Count number of operations until open parenthesis
                do {
                    popChar(&operatorsStack);
                    operationCount++;
                }
                while(topChar(&operatorsStack) != '(');
                popChar(&operatorsStack);
                NFA operand1;
                NFA operand2;
                // If operations are '.' do concatenation
                if(operationSymbol == '.') {
                    for(int j = 0; j < operationCount; j++) {
                        operand2 = topNFA(&operandsStack);
                        popNFA(&operandsStack);
                        operand1 = topNFA(&operandsStack);
                        popNFA(&operandsStack);
                        NFA concat = concatenate(operand1, operand2);
                        pushNFA(&operandsStack, concat);
                    }
                }
                // If operations are '|' do union
                else if(operationSymbol == '|') {
                    DynNFAArray orSelections;
                    initNfaArray(&orSelections, operationCount +1);
                    int tempCounter = operationCount;
                    for(int j = 0; j < operationCount +1; j++) {
                        orSelections.array[tempCounter] = topNFA(&operandsStack);
                        tempCounter--;
                        popNFA(&operandsStack);
                    }
                    pushNFA(&operandsStack, or(orSelections, operationCount +1));
                }
                if(modREGEX[i+1] == '*') {
                    skipnext = 1;
                }
            }
        }
        for(int k = 0; k < operatorsStack.used; k++) {
            printDebug("%c",operatorsStack.array[k]);
        }
    }
    printDebug("\nRemaining NFAs (Must be 1): %i\n", operandsStack.used);
    NFA toReturn = popNFA(&operandsStack);
    printDebug("Total vertices: %i\nTotal transitions: %i", getVertexCount(&toReturn), toReturn.transitions.used);

    printDebug("\nNFA done.");
    return toReturn;
}