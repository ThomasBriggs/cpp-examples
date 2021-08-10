#pragma once

#include <set>
#include <memory>
#include <utility>

class Node : public std::enable_shared_from_this<Node>
{
public:
    typedef std::shared_ptr<Node> node_ptr_t;
    typedef std::pair<node_ptr_t, char> transition_t;
    typedef std::set<transition_t> connection_list_t;
    Node(int nodeId);
    void addConnection(transition_t transition);
    const char& getId();
    const connection_list_t& getConnections();

private:
    bool terminal;
    int nodeId;
    node_ptr_t node_ptr;
    connection_list_t connections;
};

Node::Node(int nodeId)
{
    this->node_ptr = shared_from_this();
    this->nodeId = nodeId;
}

void Node::addConnection(transition_t transition)
{
    connections.insert(transition);
}

const char& Node::getId()
{
    return this->nodeId;
}

const Node::connection_list_t& Node::getConnections()
{
    return this->connections;
}


