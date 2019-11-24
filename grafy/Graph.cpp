#include "Graph.h"

Graph::Graph() {
    this->identifier == "";
    this->size = 0;
    this->zone = nullptr;
}
Graph::Graph(std::string id, int size, int **distances) {
    this->identifier = id;
    this->size = size;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (distances[i][j] != distances[j][i]) {
                printf("This is not undirected graph!");
                return;
            }
        }
        if (distances[i][i] != 0) {
            printf("Graph [%d,%d] == %d %s is broken", i, i, distances[i][i], this->identifier.c_str());
            return;
        }
    }
    this->zone = distances;
}
Graph::~Graph() {
    if (this->identifier != "") {
        printf("Graph %s [*]\n", this->identifier.c_str());
    }
}

std::vector<int> Graph::getNeighbours(int node) {
    std::vector<int> neighbours;
    for (int i = 0; i < this->size; i++) {
        if (this->zone[node][i] != 0)
            neighbours.push_back(i);
    }
    return neighbours;
}

std::vector<std::vector<int>> Graph::getAllPaths(int a, int b) {
    std::vector<std::vector<int>> paths, endedPaths;
    std::vector<int> start{a};
    paths.push_back(start);
    int limit = 0;
    while (paths.size() && limit < 1000) {
        std::vector<std::vector<int>> buffer;
        limit++;
        int ps = paths.size();
        // loop through paths
        for (std::vector<std::vector<int>>::iterator path = paths.begin(); path != paths.end(); path++) {
            if ((*path).back() == b) { // path reached destination
                endedPaths.push_back(*path);
                paths.erase(path--);
                continue;
            }
            // get node neighbours
            std::vector<int> neighbours = this->getNeighbours((*path).back());
            // remove reverse nodes and looping nodes
            for (std::vector<int>::iterator nb = neighbours.begin(); nb != neighbours.end(); nb++) {
                if (*nb == (*path).back()) { // reverse direction
                    // https://www.techiedelight.com/remove-elements-vector-inside-loop-cpp/
                    neighbours.erase(nb--);
                } else {
                    for (std::vector<int>::iterator node = (*path).begin(); node != (*path).end(); node++) {
                        if (*nb == *node) {
                            neighbours.erase(nb--);
                            continue;
                        }
                    }
                }
            }
            if (!neighbours.empty()) {
                for (int i = 1; i < neighbours.size(); i++) {
                    std::vector<int> tmp(*path);
                    tmp.push_back(neighbours[i]);

                    if (neighbours[i] == b) {
                        endedPaths.push_back(tmp);
                    }
                    else {
                        buffer.push_back(tmp);
                    }
                }
                (*path).push_back(neighbours[0]);
            } else {
                paths.erase(path--);
            }
        }
        if (!buffer.empty()) {
            paths.insert(paths.end(), buffer.begin(), buffer.end());
        }
    }
    return endedPaths;
}

int Graph::minDistance(int a, int b) {
    std::vector<std::vector<int>> paths = this->getAllPaths(a, b);
    int min = 0;
    for (int i = 0; i < paths.size(); i++) {
        int currentLength = 0;
        for (int j = 1; j < paths[i].size(); j++) {
            currentLength += this->zone[paths[i][j-1]][paths[i][j]];
        }
        if (min == 0 || currentLength < min) {
            min = currentLength;
        }
    }
    return min;
}

int Graph::maxDistance(int a, int b) {
    std::vector<std::vector<int>> paths = this->getAllPaths(a, b);
    int max = 0;
    for (int i = 0; i < paths.size(); i++) {
        int currentLength = 0;
        for (int j = 1; j < paths[i].size(); j++) {
            currentLength += this->zone[paths[i][j-1]][paths[i][j]];
        }
        if (currentLength > max) {
            max = currentLength;
        }
    }
    return max;
}

void Graph::printZone() {
    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
            printf(j == 0 ? "[%d " : (j == this->size - 1 ? "%d]\n" : "%d "), this->zone[i][j]);
        }
    }
}

void Graph::describe() {
    printf("Graph %s: \n", this->identifier.c_str());
    this->printZone();
    printf("\n");
}