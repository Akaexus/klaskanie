#ifndef GRAFY_LIST_H
#define GRAFY_LIST_H
#include "Graph.h"

struct GraphStackElement {
    Graph graph;
    GraphStackElement* prev;
};

class List {
    public:
        List();
        void add(Graph g);
        Graph pop();
        Graph findMax(int a, int b);
        void printAll();
    private:
        GraphStackElement *e;
};


#endif //GRAFY_LIST_H
