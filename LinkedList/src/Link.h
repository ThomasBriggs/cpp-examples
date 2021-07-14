#include <memory>

class Link
{
private:
    int data;
    std::unique_ptr<Link> next;

public:
    Link(int data)
    {
        setData(data);
        next = nullptr;
    }

    void setData(int data)
    {
        this->data = data;
    }

    void setNext(std::unique_ptr<Link> next)
    {
        this->next = std::move(next);
    }

    int getData()
    {
        return this->data;
    }

    Link *getNext()
    {
        return this->next.get();
    }

    std::remove_reference_t<std::unique_ptr<Link, std::default_delete<Link>> &> replace(std::unique_ptr<Link> other) {
        auto temp = std::move(this->next);
        this->next = std::move(other);
        return std::move(temp);
    }
};