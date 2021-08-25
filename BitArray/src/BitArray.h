#include <memory>
#include <cmath>
#include <cstring>

class BitArray
{
private:
    size_t size;
    uint32_t* array;

    inline static size_t getArraySize(size_t s)
    {
        return (s >> 5) + (s % 32 > 0);
    }

    inline static uint32_t getMask(size_t i)
    {
        return (32 - (i % 32) - 1);
    }

    inline static short getBlock(size_t i) { return i >> 5; };

    inline void _setBit(size_t i)
    {
        array[getBlock(i)] |= 1 << getMask(i);
    }

    inline void _unsetBit(size_t i)
    {
        array[getBlock(i)] &= ~(1 << getMask(i));
    }

public:
    BitArray(size_t size)
    {
        this->size = size;
        this->array = new uint32_t[getArraySize(size)];
        std::memset(this->array, 0b00000000, sizeof(array[0]) * getArraySize(size));
    }

    ~BitArray()
    {
        delete [] this->array;
    }

    inline size_t getSize() { return this->size; }

    bool getBit(size_t i)
    {
        short block = i >> 5; //Divide by 32
        return ((array[block] & (1 << getMask(i))) > 0);
    }

    void setBit(size_t i, bool n)
    {
        n ? _setBit(i) : _unsetBit(i);
    }
};

