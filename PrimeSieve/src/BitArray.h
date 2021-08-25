#include <memory>
#include <cmath>
#include <cstring>

class BitArray
{
private:
    size_t m_size;
    std::unique_ptr<uint32_t[]> array;

    inline static uint32_t shiftAmount(size_t i) { return (32 - (i & 31) - 1); }
    inline static size_t block(size_t i) { return i >> 5; };

public:
    BitArray(size_t size)
    {
        this->m_size = size;
        size_t s = (size >> 5) + ((size & 31) > 0);
        this->array = std::make_unique<uint32_t[]>(s);
        std::memset(this->array.get(), 0, sizeof(array[0]) * s);
    }

    inline size_t size() const { return this->m_size; }
    inline bool get(size_t i) const { return (array[block(i)] & (1 << shiftAmount(i))); }
    inline void set(size_t i) { array[block(i)] |= 1 << shiftAmount(i); }
};

