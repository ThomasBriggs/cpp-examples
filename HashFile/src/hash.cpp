#include <openssl/evp.h>
#include <fstream>
#include <vector>
#include "hash.h"
#include <iomanip>


static sha256_t hash(std::vector<uint8_t> bytes)
{
    sha256_t md;
    EVP_Digest(&bytes[0], bytes.size(), &md[0], nullptr, EVP_sha256(), nullptr);
    return md;
}

static std::vector<uint8_t> readBytes(std::filesystem::path fp)
{
    std::ifstream ifs(fp, std::ios::binary | std::ios::ate);
    std::streampos pos = ifs.tellg();
    std::vector<uint8_t> bytes(pos);
    ifs.seekg(0, std::ios::beg);
    ifs.read((char*)&bytes[0], pos);
    return bytes;
}

sha256_t hashFile(std::filesystem::path fp) { return hash(readBytes(fp)); }

std::string hashToStr(sha256_t hash)
{
    std::stringstream ss;
    for (auto&& i : hash) { ss << std::hex << std::setw(2) << std::setfill('0') << (ushort)i; }
    return ss.str();
}



