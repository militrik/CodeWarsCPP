#include <iostream>

#include <string>
#include <vector>
#include <algorithm>
#include <regex>
#include <chrono>

std::string range_extraction(std::vector<int> args) {
    std::ostringstream result;
    result << std::to_string(args[0]) + ',';

    int index = 1;
    std::transform(args.begin() + 1, args.end() - 1,
                   std::ostream_iterator<std::string>(result), [&index, &args](int num) {
                int prev = args[index - 1];
                int next = args[index + 1];
                index++;
                if (std::abs(num - prev) != 1 || std::abs(num - next) != 1) {
                    return std::to_string(num) + ',';
                } else {
                    return std::string("*");
                }
            });

    result << std::to_string(args.back());
    return std::regex_replace(result.str(), std::regex(",\\*+"), "-");
}

std::string range_extraction1(std::vector<int> args) {

    std::string string = std::to_string(args[0]) + ',';
    for (int i = 1; i < args.size() - 1; ++i) {
        if (std::abs(args[i] - args[i - 1]) != 1 || std::abs(args[i] - args[i + 1]) != 1) {
            string += std::to_string(args[i]) + ",";
        } else {
            string += "*";
        }
    }
    string += std::to_string(args[args.size() - 1]);
    return std::regex_replace(string, std::regex(",\\*+"), "-");
}

int main() {
    auto start = std::chrono::high_resolution_clock::now();

    std::cout << range_extraction({-6, -3, -2, -1, 0, 1, 3, 4, 5, 7, 8, 9, 10, 11, 14, 15, 17, 18, 19, 20})
              << std::endl;
    std::cout << range_extraction({-3, -2, -1, 2, 10, 15, 16, 18, 19, 20}) << std::endl;

    // Кінець вимірювання часу
    auto end = std::chrono::high_resolution_clock::now();

    // Обчислюємо тривалість виконання коду
    std::chrono::duration<double> duration = end - start;

    // Виводимо час у секундах
    std::cout << "Час виконання: " << duration.count() << " секунд" << std::endl;

    start = std::chrono::high_resolution_clock::now();

    std::cout << range_extraction1({-6, -3, -2, -1, 0, 1, 3, 4, 5, 7, 8, 9, 10, 11, 14, 15, 17, 18, 19, 20})
              << std::endl;
    std::cout << range_extraction1({-3, -2, -1, 2, 10, 15, 16, 18, 19, 20}) << std::endl;

    // Кінець вимірювання часу
    end = std::chrono::high_resolution_clock::now();

    // Обчислюємо тривалість виконання коду
    duration = end - start;

    // Виводимо час у секундах
    std::cout << "Час виконання: " << duration.count() << " секунд" << std::endl;

    return 0;
}
