#include <iostream>

class Link
{
private:
    int data;
    Link *next;

public:
    Link(int data)
    {
        setData(data);
        next = NULL;
    }

    void setData(int data)
    {
        this->data = data;
    }

    void setNext(Link *next)
    {
        this->next = next;
    }

    int getData()
    {
        return this->data;
    }

    Link *getNext()
    {
        return this->next;
    }
};

class LinkedList
{
private:
    Link *head;
    Link *tail;

    Link *getLinkAt(int index)
    {
        if (this->head == NULL)
        {
            return NULL;
        }
        Link *currentLink = this->head;
        for (size_t i = 0; i < index; i++)
        {
            currentLink = currentLink->getNext();
            if (currentLink == NULL)
            {
                return NULL;
            }
        }
        return currentLink;
    }

public:
    LinkedList()
    {
        this->head = NULL;
        this->tail = NULL;
    }

    void append(int data)
    {
        if (this->head == NULL)
        {
            this->head = new Link(data);
            this->tail = this->head;
        }
        else
        {
            auto temp = this->tail;
            this->tail = new Link(data);
            temp->setNext(this->tail);
        }
    }

    int get(int index)
    {
        Link *link = getLinkAt(index);
        if (link == NULL)
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

        Link *newLink = new Link(data);
        if (index == 0)
        {
            if (this->head == NULL)
            {
                append(data);
            }
            else
            {
                newLink->setNext(this->head);
                this->head = newLink;
            }
        }
        else
        {
            Link *prevLink = getLinkAt(index - 1);
            if (prevLink != NULL)
            {
                if (prevLink == this->tail)
                {
                    append(data);
                }
                else
                {
                    Link *nextLink = prevLink->getNext();
                    prevLink->setNext(newLink);
                    newLink->setNext(nextLink);
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

int main(int argc, char const *argv[])
{
    using namespace std;

    auto list = LinkedList();
    list.append(10);
    list.append(20);
    list.append(30);

    list.insert(0, 99);

    for (size_t i = 0; i < 5; i++)
    {
        cout << list.get(i) << endl;
    }
    
}
