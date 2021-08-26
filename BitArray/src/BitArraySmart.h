#include <memory>
#include <cmath>
#include <cstring>

class BitArraySmart
{
private:
    size_t m_size;
    std::unique_ptr<uint32_t[]> array;

    inline static size_t arraySize(size_t s)
    {
        return (s >> 5) + (s % 32 > 0);
    }

    inline static uint32_t shiftAmount(size_t i)
    {
        return (32 - (i % 32) - 1);
    }

    inline static size_t block(size_t i) { return i >> 5; };

    inline void _setBit(size_t i)
    {
        array.get()[block(i)] |= 1 << shiftAmount(i);
    }

    inline void _unsetBit(size_t i)
    {
        array.get()[block(i)] &= ~(1 << shiftAmount(i));
    }

public:
    BitArraySmart(size_t size)
    {
        this->m_size = size;
        this->array = std::make_unique<uint32_t[]>(arraySize(size));
        std::memset(this->array.get(), 0b00000000, sizeof(array[0]) * arraySize(size));
    }

    inline size_t size() { return this->m_size; }

    inline bool getBit(size_t i)
    {
        return (array[block(i)] & (1 << shiftAmount(i))) > 0;
    }

    inline void setBit(size_t i, bool n)
    {
        n ? _setBit(i) : _unsetBit(i);
    }
};

