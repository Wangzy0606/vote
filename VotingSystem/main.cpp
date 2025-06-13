#include "vote.h"
#include <iostream>
#include <string>

int main() {
    std::string path;
    std::cout << "Введите путь к файлу со списком фамилий: ";
    std::cin >> path;

    enrolled(path);

    std::string input;
    while (true) {
        std::cout << "Введите фамилию (или 'end' для завершения): ";
        std::cin >> input;
        if (input == "end") break;
        unenrolled(input);
    }

    print_results();
    return 0;
}
