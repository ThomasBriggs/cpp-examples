/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: thomas
 *
 * Created on 4 March 2020, 16:00
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <type_traits>
#include <algorithm>
#include <sstream>
#include <iterator>

template<class T>
class Node
{
private:
    T value;
    Node* left;
    Node* right;

public:

    Node(T value)
    {
        setValue(value);
        left = NULL;
        right = NULL;
    }

    void setValue(T value)
    {
        this->value = value;
    }

    void setLeft(Node *left)
    {
        this->left = left;
    }

    void setRight(Node *right)
    {
        this->right = right;
    }

    T getValue()
    {
        return value;
    }

    Node* getLeft()
    {
        return left;
    }

    Node* getRight()
    {
        return right;
    }
};

template <class T>
class BinaryTree
{
private:
    int size;
    Node<T>* root;
    int mode = 0;

    void toVector(Node<T>* node, std::vector<T>* output)
    {
        if (node != NULL) {
            switch (mode) {
            case 0:
                toVector(node->getLeft(), output);
                output->push_back((node->getValue()));
                toVector(node->getRight(), output);
                break;
            case 1:
                output->push_back((node->getValue()));
                toVector(node->getLeft(), output);
                toVector(node->getRight(), output);
                break;
            case 2:
                toVector(node->getLeft(), output);
                toVector(node->getRight(), output);
                output->push_back((node->getValue()));
                break;
            default:
                break;
            }

        }
    }

public:

    const static int IN_ORDER = 0;
    const static int PRE_ORDER = 1;
    const static int POST_ORDER = 2;

    BinaryTree()
    {
        size = 0;
        root = NULL;
    }

    BinaryTree(std::vector<T> inputVect) : BinaryTree()
    {
        for (int i = 0; i < inputVect.size(); i++) {
            add(inputVect.at(i));
        }
    }

    void add(T value)
    {
        if (root == NULL) {
            root = new Node<T>(value);
        }
        else {
            add(value, root);
        }
        size++;
    }

    void add(T value, Node<T>* node)
    {
        if (value < node->getValue()) {
            if (node->getLeft() == NULL) {
                node->setLeft(new Node<T>(value));
            }
            else {
                add(value, node->getLeft());
            }
        }
        else {
            if (node->getRight() == NULL) {
                node->setRight(new Node<T>(value));
            }
            else {
                add(value, node->getRight());
            }
        }
    }

    std::vector<T> toVector()
    {
        std::vector<T> output;
        toVector(root, &output);
        return output;
    }

    std::string toString()
    {
        std::vector<T> my_vector = toVector();
        std::stringstream result;
        std::copy(my_vector.begin(), my_vector.end(), std::ostream_iterator<T>(result, ", "));
        return std::string(result.str().c_str());
    }

    void setMode(int value)
    {
        mode = value;
    }

    int getMode()
    {
        return mode;
    }

    int getSize()
    {
        return size;
    }

};

int main(int argc, char** argv)
{
    using namespace std;

    // BinaryTree<string> tree(vector<string>{"Kiki", "Haku", "San", "Chihiro", "Jiji", "Ponyo", "Satsuki"});

       BinaryTree<int> tree(vector<int>{5, 2, 4, 3, 1});

    tree.setMode(tree.PRE_ORDER);
    cout << "PRE_ORDER " << tree.toString() << endl;

    cout << endl;

    tree.setMode(tree.IN_ORDER);
    cout << "IN_ORDER " << tree.toString() << endl;

    cout << endl;

    tree.setMode(tree.POST_ORDER);
    cout << "POST_ORDER " << tree.toString() << endl;
    return 0;
}