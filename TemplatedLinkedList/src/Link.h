#ifndef LINK_H
#define LINK_H
#include <memory>

template <class T>
class Link
{
private:
    T data;
    std::unique_ptr<Link<T>> next;

public:
    Link(T data);
    T getData();
    void setData(T Data);

    void setNext(std::unique_ptr<Link<T>> &&link);
    Link<T> *getNext();
};

#include "Link.cpp"
#endif