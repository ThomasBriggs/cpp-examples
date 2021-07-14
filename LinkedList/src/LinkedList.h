#include "Link.h"

class LinkedList
{
private:
    std::unique_ptr<Link> head;
    Link *tail;

    Link *getLinkAt(int index)
    {
        if (this->head == nullptr)
        {
            return nullptr;
        }
        Link *currentLink = this->head.get();
        for (size_t i = 0; i < index; i++)
        {
            currentLink = currentLink->getNext();
            if (currentLink == nullptr)
            {
                return nullptr;
            }
        }
        return currentLink;
    }

public:
    LinkedList()
    {
        this->head = nullptr;
        this->tail = nullptr;
    }

    void append(int data)
    {
        if (this->head == nullptr)
        {
            this->head = std::make_unique<Link>(data);
            this->tail = this->head.get();
        }
        else
        {
            this->tail->setNext(std::make_unique<Link>(data));
            this->tail = this->tail->getNext();
        }
    }

    int get(int index)
    {
        Link *link = getLinkAt(index);
        if (link == nullptr)
        {
            return -1;
        }
        else
        {
            return link->getData();
        }
    }

    void insert(int index, int data)
    {
        if (index == 0)
        {
            if (this->head == nullptr)
            {
                append(data);
            }
            else
            {
                auto temp = std::make_unique<Link>(data);
                temp->setNext(std::move(this->head));
                this->head = std::move(temp);
            }
        }
        else
        {
            Link *prevLink = getLinkAt(index - 1);
            if (prevLink != nullptr)
            {
                if (prevLink == this->tail)
                {
                    append(data);
                }
                else
                {
                    auto newLink = std::make_unique<Link>(data);
                    newLink->setNext(prevLink->replace(std::move(newLink)));
                }
            }
        }
    }

    int getHead()
    {
        return this->head->getData();
    }

    int getTail()
    {
        return this->tail->getData();
    }
};