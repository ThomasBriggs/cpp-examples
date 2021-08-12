#include "Graph.h"
#include <iostream>
#include <set>

int main()
{
    Graph g;
    g.addVertex(1);
    g.addVertex(2);
    g.addVertex(3);

    auto it = g.getVertex(0);
    auto it2 = g.getVertex(1);
    g.addDoubleEdge(it, it2);
    std::cout << g.adjacent(it, it2) << '\n';
    

}
