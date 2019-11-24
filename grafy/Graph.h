#include <iostream>
#include <vector>
#ifndef GRAFY_GRAPH_H
#define GRAFY_GRAPH_H


class Graph {
private:
    std::string identifier;
    int **zone;
    int size;
public:
    Graph();
    Graph(std::string id, int size, int **distances);
    ~Graph();

    std::vector<int> getNeighbours(int node);
    std::vector<std::vector<int>> getAllPaths(int a, int b);
    int minDistance(int a, int b);
    int maxDistance(int a, int b);
    void printZone();
    void describe();
};


#endif //GRAFY_GRAPH_H
