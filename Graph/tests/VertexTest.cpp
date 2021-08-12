#include <gtest/gtest.h>
#include "Vertex.h"

TEST(Vertex, GetData)
{
    int i = 1;
    Vertex v(i);
    ASSERT_EQ(v.getData(), i);
}

TEST(Vertex, SetData)
{
    Vertex v(0);
    int i = 1;
    v.setData(i);
    ASSERT_EQ(v.getData(), i);
}

TEST(Vertex, AddEdge)
{
    Vertex v(1);
    Vertex v2(2);
    v.addEdge(v2);
    ASSERT_EQ(v.adjacent(v2), true);
}

TEST(Vertex, RemoveEdge)
{
    Vertex v(1);
    Vertex v2(2);
    v.addEdge(v2);
    ASSERT_EQ(v.adjacent(v2), true);
    v.removeEdge(v2);
    ASSERT_EQ(v.adjacent(v2), false);
}