#include "lsh.h"
#include "pHash.h"
#include <bitset>
#include <chrono>
#include <random>
#include <sstream>

void lsh::initMinHashVectors()
{
    this->minHashVectors.resize(this->l);
    std::mt19937 rng(std::random_device().operator()());
    for (auto&& i : minHashVectors) {
        i.resize(this->hashSize);
        std::iota(i.begin(), i.end(), 1);
        std::shuffle(i.begin(), i.end(), rng);
    }
}
void lsh::initHashTables()
{
    this->hashTables.resize(b);
}

lsh::lsh(size_t b, size_t n, size_t l, size_t hashSize)
    : b(b)
    , n(n)
    , l(l)
    , hashSize(hashSize)
{
    this->initMinHashVectors();
    this->initHashTables();
}

std::vector<int> lsh::minHash(uint64_t hash)
{
    std::bitset<64> hashBits = hash;
    std::vector<int> sig;
    sig.reserve(32);

    {
        bool foundMatch;
        size_t index;
        size_t i;
        for (auto&& minHashVector : this->minHashVectors) {
            foundMatch = false;
            index = 1;
            while (!foundMatch) {
                for (i = 0; i < minHashVector.size(); i++) {
                    if (minHashVector[i] != index)
                        continue;

                    if (hashBits.test(i) == 1) {
                        sig.push_back(i);
                        foundMatch = true;
                        break;
                    }
                }
                index++;
            }
        }
    }
    return sig;
}

std::string vecToString(const std::vector<int>, std::vector<int>::iterator begin,
    std::vector<int>::iterator end)
{
    std::stringstream ss;
    std::copy(begin, end, std::ostream_iterator<int>(ss));
    return ss.str();
}

void lsh::insert(uint64_t hash, std::string filename)
{
    auto sig = this->minHash(hash);
    int subVecSize = sig.size() / this->b;
    std::string subVec;
    size_t index = 0;
    for (size_t i = 0; i < this->b; i++) {
        subVec = vecToString(sig, sig.begin() + index, sig.begin() + index + subVecSize);
        this->hashTables[i][subVec].push_back(filename);
        index += subVecSize;
    }
}

std::vector<std::string> lsh::check(uint64_t hash)
{
    auto sig = this->minHash(hash);
    int subVecSize = sig.size() / this->b;
    std::string subVec;
    size_t index = 0;
    std::vector<std::string> matches;
    std::unordered_map<std::string, unsigned int> candPairs;
    lsh::hashTable_t::iterator it;
    for (size_t i = 0; i < this->b; i++) {
        subVec = vecToString(sig, sig.begin() + index, sig.begin() + index + subVecSize);
        it = this->hashTables[i].find(subVec);
        if (it != this->hashTables[i].end())
            for (auto&& j : it->second) {
                auto it2 = candPairs.find(j);
                if (it2 != candPairs.end()) {
                    it2->second++;
                } else {
                    candPairs.insert(std::make_pair(j, 1));
                }
            }
        index += subVecSize;
    }

    for (auto&& i : candPairs) {
        if (i.second > this->n) {
            matches.push_back(i.first);
        }
    }

    return matches;
}

std::vector<std::string> lsh::insertAndCheck(uint64_t hash, std::string filename)
{
    auto ret = this->check(hash);
    this->insert(hash, filename);
    return ret;
}
