#include "Link.h"

template <class T>
Link<T>::Link(T data)
{
    this->data = data;
    this->next = nullptr;
}

template <class T>
void Link<T>::setData(T Data)
{
    this->data = data;
}

template <class T>
T Link<T>::getData()
{
    return this->data;
}

template <class T>
void Link<T>::setNext(std::unique_ptr<Link<T>> &&next)
{
    this->next = next;
}

template<class T>
Link<T> *Link<T>::getNext()
{
    return this->getNext->get();
}