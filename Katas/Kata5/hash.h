typedef struct e {
    void *key;
    int *value;
} Element;

typedef struct v {
    unsigned count;
    unsigned size;
    Element *elements;
} Vector;

typedef struct h {
    unsigned size;
    Vector *data;
    unsigned (*hash)(void *, unsigned);
    int (*cmpKeys)(void *, void *);
    void *(*copyKey)(void *);
    int *(*copyValue)(int *);
} Hash;

void initHash(Hash *,
            unsigned, 
            unsigned (* hash) (void *, unsigned),
            int(*cmpKeys)(void *, void *),
            void *(*copyKey)(void *),
            int *(*copyValue)(int *));
void insert(Hash *, void *, int *);
int * getVal(Hash *, void *);
void printTable(Hash *);