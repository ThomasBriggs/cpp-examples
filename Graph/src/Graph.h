#pragma once

#include "Vertex.h"
#include <vector>

class Graph
{
public:
    typedef std::vector<Vertex> vertex_list_t;
    typedef vertex_list_t::iterator iterator;
private:
    vertex_list_t vertex_list;
public:
    Graph();
    void addVertex(int data);
    void removeVertex(iterator v);
    void addEdge(iterator v1, iterator v2);
    void removeEdge(iterator v1, iterator v2);
    void addDoubleEdge(iterator v1, iterator v2);
    void removeDoubleEdge(iterator v1, iterator v2);
    iterator getVertex(int index);
    bool adjacent(const iterator v1, const iterator v2) const;
    vertex_list_t& getVertexList();
};

Graph::Graph() {}

void Graph::addVertex(int data)
{
    vertex_list.emplace_back(data);
}

void Graph::removeVertex(iterator v)
{
    for (auto &&i : vertex_list)
    {
        if (i.adjacent(*v))
            i.removeEdge(*v);
    }
    vertex_list.erase(v);
}


void Graph::addEdge(iterator v1, iterator v2)
{
    (*v1).addEdge(*v2);
}

void Graph::removeEdge(iterator v1, iterator v2)
{
    v1->removeEdge(*v2);
}

void Graph::addDoubleEdge(iterator v1, iterator v2)
{
    v1->addEdge(*v2);
    v2->addEdge(*v1);
}

void Graph::removeDoubleEdge(iterator v1, iterator v2)
{
    v1->removeEdge(*v2);
    v2->removeEdge(*v1);
}


bool Graph::adjacent(iterator v1, iterator v2) const
{
    return v1->adjacent(*v2);
}

Graph::vertex_list_t& Graph::getVertexList()
{
    return this->vertex_list;
}

Graph::iterator Graph::getVertex(int index)
{
    return vertex_list.begin()+index;
}



