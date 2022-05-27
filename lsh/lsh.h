#include <cstddef>
#include <cstdint>
#include <unordered_map>
#include <list>
#include <vector>
#include <string>

class lsh
{
private:
    const size_t b;
    const size_t n;
    const size_t l;
    const size_t hashSize;
    typedef std::vector<std::vector<unsigned int>> minHashVectors_t;
    lsh::minHashVectors_t minHashVectors;

    typedef std::unordered_map<std::string, std::list<std::string>> hashTable_t;
    typedef std::vector<hashTable_t> hashTables_t;
    lsh::hashTables_t hashTables;

    void initMinHashVectors();
    void initHashTables();
    std::vector<int> minHash(uint64_t hash);


public:
    lsh(size_t b, size_t n, size_t l, size_t hashSize);
    void insert(uint64_t hash, std::string filename);
    std::vector<std::string> check(uint64_t hash);
    std::vector<std::string> insertAndCheck(uint64_t hash, std::string filename);

};