#include <memory>
#include <cmath>
#include <cstring>

class BitArray
{
private:
    size_t m_size;
    uint32_t* array;

    inline static uint32_t shiftAmount(size_t i)
    {
        return (32 - (i & 0x1F) - 1);
    }

    inline static size_t block(size_t i) { return i >> 5; };

public:
    BitArray(size_t size)
    {
        this->m_size = size;
        size_t s = (size >> 5) + ((size & 0x1F) > 0);
        this->array = new uint32_t[s];
        std::memset(this->array, 0b00000000, sizeof(array[0]) * s);
    }

    ~BitArray()
    {
        delete[] this->array;
    }

    inline size_t size() const { return this->m_size; }

    inline bool getBit(size_t i) const
    {
        return (array[block(i)] & (1 << shiftAmount(i))) > 0;
    }

    inline void set(size_t i)
    {
        array[block(i)] |= 1 << shiftAmount(i);
    }
};

