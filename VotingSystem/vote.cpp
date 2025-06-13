#include "vote.h"
#include "hash.h"
#include <unordered_set>
#include <unordered_map>
#include <fstream>
#include <iostream>

static std::unordered_set<size_t> voted;
static std::unordered_map<size_t, std::string> hash_to_name;
static int duplicates = 0;

void enrolled(const std::string& filepath) {
    std::ifstream in(filepath);
    std::string name;
    while (getline(in, name)) {
        size_t h = custom_hash(name);
        if (voted.count(h) == 0) {
            voted.insert(h);
            hash_to_name[h] = name;
        } else {
            ++duplicates;
        }
    }
}

void unenrolled(const std::string& surname) {
    size_t h = custom_hash(surname);
    if (voted.count(h) == 0) {
        voted.insert(h);
        hash_to_name[h] = surname;
    } else {
        ++duplicates;
    }
}

void print_results() {
    std::cout << "Количество голосующих: " << voted.size() << "\n";
    std::cout << "Количество дубликатов: " << duplicates << "\n";
    std::cout << "Фамилии голосующих:\n";
    for (const auto& [h, name] : hash_to_name) {
        std::cout << "- " << name << "\n";
    }
}
