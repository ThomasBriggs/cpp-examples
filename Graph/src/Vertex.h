#pragma once

#include <vector>

class Vertex
{
public:
    typedef std::vector<Vertex*> vertex_ptr_list_t;
    Vertex(int data);
    int getData() const;
    void setData(int data);
    void addEdge(Vertex& vertex) const;
    void removeEdge(Vertex& vertex) const;
    bool adjacent(Vertex& vertex) const;
    const vertex_ptr_list_t& getEdges() const;
    friend bool operator<(const Vertex& lhs, const Vertex& rhs);
    // friend bool operator==(const Vertex& rhs, const Vertex& lhs);

private:
    mutable vertex_ptr_list_t vertex_list;
    int data;
};

Vertex::Vertex(int data) : data{ data } {}

int Vertex::getData() const
{
    return this->data;
}

void Vertex::setData(int data)
{
    this->data = data;
}

void Vertex::addEdge(Vertex& v) const
{
    vertex_list.push_back(&v);
}

void Vertex::removeEdge(Vertex& v) const
{
    for (auto it = vertex_list.begin(); it != vertex_list.end(); it++)
        if (*it == &v) {
            vertex_list.erase(it);
            return;
        }
}

const Vertex::vertex_ptr_list_t& Vertex::getEdges() const
{
    return this->vertex_list;
}

bool Vertex::adjacent(Vertex& v) const
{
    for (auto&& i : vertex_list)
        if (i == &v)
            return true;
    return false;
}

bool operator<(const Vertex& v1, const Vertex& v2)
{
    return v1.data < v2.data;
}

// bool operator==(const Vertex& rhs, const Vertex& lhs)
// {
//     if (rhs.data == lhs.data && rhs.vertex_list == lhs.vertex_list)
//         return true;
//     return false;
// }





