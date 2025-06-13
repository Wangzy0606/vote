#include "hash.h"

size_t custom_hash(const std::string& surname) {
    size_t hash = 0;
    for (char ch : surname) {
        hash = hash * 31 + ch;
    }
    return hash;
}
