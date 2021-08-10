#pragma once

#include "Node.h"

class Automaton
{
private:
    std::unique_ptr<Node> start_node;
    int size;
public:
    Automaton(char data);
    void addTransition(Node::transition_t transition);
};

Automaton::Automaton(char data)
{
    start_node = std::make_unique<Node>(data);
    size = 1;
}

void Automaton::addTransition(Node::transition_t t)
{
   this ->start_node->addConnection(t);
}

