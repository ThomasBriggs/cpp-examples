#pragma once

#include "Vertex.h"
#include <unordered_map>

class Graph
{
public:
    typedef std::unordered_map<int, Vertex> vertex_list_t;
private:
    vertex_list_t vertex_list;
public:
    Graph();
    void addVertex(int data);
    void removeVertex(int v);
    void addEdge(int v1, int v2);
    void removeEdge(int v1, int v2);
    void addDoubleEdge(int v1, int v2);
    void removeDoubleEdge(int v1, int v2);
    bool adjacent(int v1, int v2);
    vertex_list_t& getVertexList();
};

Graph::Graph() {}

void Graph::addVertex(int data)
{
    vertex_list.emplace(data, Vertex(data));
}

// void Graph::removeVertex(int v)
// {
//     for (auto &&i : vertex_list)
//     {
//         if (i.second.adjacent(vertex_list[v]))
//             i.second.removeEdge(vertex_list[v]);
//     }

//     vertex_list.erase(v);
// }


void Graph::addEdge(int v1, int v2)
{
    vertex_list[v1].addEdge(vertex_list[v2]);
}

void Graph::removeEdge(int v1, int v2)
{
    vertex_list[v1].removeEdge(vertex_list[v2]);
}

void Graph::addDoubleEdge(int v1, int v2)
{
    vertex_list[v1].addEdge(vertex_list[v2]);
    vertex_list[v2].addEdge(vertex_list[v1]);
}

void Graph::removeDoubleEdge(int v1, int v2)
{
    vertex_list[v1].removeEdge(vertex_list[v2]);
    vertex_list[v2].removeEdge(vertex_list[v1]);
}


bool Graph::adjacent(int v1, int v2)
{
    return vertex_list[v1].adjacent(vertex_list[v2]);
}



