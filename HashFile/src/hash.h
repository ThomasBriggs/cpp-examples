#pragma once
#include <array>
#include <cstdint>
#include <filesystem>

typedef std::array<uint8_t, 32> sha256_t;

sha256_t hashFile(std::filesystem::path fp);
std::string hashToStr(sha256_t hash);