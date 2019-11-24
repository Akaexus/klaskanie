#include <cstdio>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <Graph.h>
#include <List.h>


Graph generateGraph(std::string id, int size, int maxDistance) {
    int **z = new int*[size];
    for(int i = 0; i < size; i++) {
        z[i] = new int[size] {0};
    }
    for(int i = 0; i < size; i++) {
        bool anyNodeConnected = false;
        for(int j = 0; j < size; j++) {
            if (i != j) {
                if (rand() % 2) { // 50% chance to be connected
                    anyNodeConnected = true;
                    int distance = rand() % maxDistance + 1;
                    z[i][j] = distance;
                    z[j][i] = distance;
                }
            }
        }
        if (!anyNodeConnected) {
            int j = i;
            do {
                j = rand() % size;
            } while(i == j);
            int distance = rand() % maxDistance + 1;
            z[i][j] = distance;
            z[j][i] = distance;
        }
    }
    Graph g = Graph(id, size, z);
    return  g;
}


int main() {
    srand(time(NULL));

    List l = List();
    for(int i = 0; i < 10; i++) {
        l.add(generateGraph("g" + std::to_string(i), 5, 20));
    }
    l.printAll();
    l.findMax(0, 3).describe();

}