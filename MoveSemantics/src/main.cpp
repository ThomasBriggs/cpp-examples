#include <string>
#include <iostream>
#include <vector>

class myString
{
public:

    char *data;
    uint32_t size;

    myString(const char *data)
    {
        std::cout << "Created a string" << '\n';
        this->size = strlen(data);
        this->data = new char[this->size];
        memcpy(this->data, data, this->size);
    }

    myString(const myString &other)
    {
        std::cout << "Copied a string" << '\n';
        this->size = other.size;
        this->data = new char[this->size];
        memcpy(this->data, other.data, this->size);
    }

    myString(myString &&other)
    {
        std::cout << "Moved a string" << '\n';
        this->size = other.size;
        this->data = other.data;

        other.size = 0;
        other.data = nullptr;
    }

    ~myString()
    {
        std::cout << "Destroyed a string" << '\n';
        delete this->data;
    }

};

std::ostream &operator<<(std::ostream &os, const myString &string)
{
    for (size_t i = 0; i < string.size; i++)
    {
        os << string.data[i];
    }
    return os;
}

int main(int argc, char const *argv[])
{
    std::vector<myString> vector;
    // myString s("Hello");
    // vector.emplace_back("Hello");
    vector.emplace_back("Hello");
    std::cout << vector.back() << '\n';
    return 0;
}
