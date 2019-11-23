#include <cstdio>
#include <iostream>
#include <vector>

void printPath(std::vector<int> v) {
    printf("[");
    for(int i = 0; i < v.size(); i++) {
        if (i!=(v.size()-1)) {
            printf("%d ", v[i]);
        } else {
            printf("%d]", v[i]);
        }
    }
}

void printPaths(std::vector<std::vector<int>> vv) {
    for (int i = 0; i < vv.size(); i++) {
        printPath(vv[i]);
        printf("\n");
    }
}
class Graph {
private:
    std::string id;
    int **zone;
    int size;
public:
    Graph(std::string id, int size, int **distances) {
        this->id = id;
        this->size = size;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (distances[i][j] != distances[j][i]) {
                    printf("This is not undirected graph!");
                    return;
                } else if (i == j && distances[i][j] != 0) {
                    printf("Graph is broken");
                    return;
                }
            }
        }
        this->zone = distances;
    }
    ~Graph() {
        printf("\n\nGraph %s [*]", this->id.c_str());
    }

    std::vector<int> getNeighbours(int node) {
        std::vector<int> neighbours;
        for (int i = 0; i < this->size; i++) {
            if (this->zone[node][i] != 0)
                neighbours.push_back(i);
        }
        return neighbours;
    }

    std::vector<std::vector<int>> calculateDistance(int a, int b) {
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
            if (buffer.size()) {
                paths.insert(paths.end(), buffer.begin(), buffer.end());
            }
        }
        return endedPaths;
    }
};


int main() {
    int size = 5;
    int zone[5][5] = {
           // 0 | 1 | 2 | 3 | 4 |
        /*0*/ 0, 10,  2,  0, 20,
        /*1*/10,  0,  7, 16,  9,
        /*2*/ 2,  7,  0,  0,  0,
        /*3*/ 0, 16,  0,  0,  8,
        /*4*/20,  9,  0,  8,  0,
    };
    int **zones = new int*[size];
    for (int i = 0; i < size; i++) {
        zones[i] = new int[size];
        for (int j = 0; j < size; j++) {
            zones[i][j] = zone[i][j];
        }
    }
    Graph g = Graph("g1", 5, zones);
    std::vector<std::vector<int>> xd = g.calculateDistance(0, 4);
    printPaths(xd);
}