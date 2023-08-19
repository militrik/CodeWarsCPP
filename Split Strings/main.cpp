#include <iostream>

#include <string>
#include <vector>
#include <regex>
#include <chrono>

std::vector<std::string> solution(const std::string &s) {
    std::regex r{".."};
    auto str = s + '_';
    return {std::sregex_token_iterator(str.begin(), str.end(), r), std::sregex_token_iterator()};
}

std::vector<std::string> solution1(const std::string &s) {
    std::string newS;
    std::vector<std::string> vector;
    if (s.size() % 2) {
        newS = s + "_";
    } else {
        newS = s;
    }
    vector.reserve(newS.size() / 2);
    for (auto i = 0; i < newS.size() / 2; i++) {
        vector.push_back(newS.substr(i * 2, 2));
    }
    return vector;
}

int main() {
    // Початок вимірювання часу
    auto start = std::chrono::high_resolution_clock::now();

    // Ваш фрагмент коду, який ви хочете виміряти
    std::vector<std::string> vector = solution1("HelloWorld");
    for (auto v: vector) {
        std::cout << v << std::endl;
    }
    // Кінець вимірювання часу
    auto end = std::chrono::high_resolution_clock::now();

    // Обчислюємо тривалість виконання коду
    std::chrono::duration<double> duration = end - start;

    // Виводимо час у секундах
    std::cout << "Час виконання: " << duration.count() << " секунд" << std::endl;



    return 0;
}
