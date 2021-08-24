#include <memory>
#include <cmath>
#include <cstring>

class BitArray
{
private:
    size_t size;
    uint32_t* array;
public:
    BitArray(size_t size)
    {
        this->size = size;
        int s = std::ceil(size/(float)32);
        this->array = new uint32_t[s];
        std::memset(this->array, 1, size);
    }

    ~BitArray()
    {
        std::free(this->array);
    }

    uint32_t* getArr() { return this->array; };

    bool get(size_t n)
    {

    }
};

