#include "List.h"
#include "Graph.h";

List::List() {
    this->e = nullptr;
}

void List::add(Graph g) {
    GraphStackElement *prev = this->e,
                      *current = new GraphStackElement();
    (*current).prev = prev;
    (*current).graph = g;
    this->e = current;
}

Graph List::pop() {
    Graph g = this->e->graph;
    GraphStackElement *prev = this->e->prev;
    delete this->e;
    this->e = prev;
    return g;
}

Graph List::findMax(int a, int b) {
    GraphStackElement *gse = this->e,
                      *maxGraph = nullptr;
    int max = 0;
    while (gse != nullptr) {
        int maxPathLength = (*gse).graph.maxDistance(a, b);
        if (maxPathLength > max) {
            max = maxPathLength;
            maxGraph = gse;
        }
        gse = (*gse).prev;
    }
    return (*maxGraph).graph;
}

void List::printAll() {
    GraphStackElement *gse = this->e;
    while (gse != nullptr) {
        GraphStackElement *prev = (*gse).prev;
        (*gse).graph.describe();
        gse = prev;
    }
}

