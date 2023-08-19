#include <iostream>
#include <cmath>
#include <algorithm>
#include <numeric>

bool narcissistic(int value) {

    std::string string = std::to_string(value);
    return value == std::accumulate(string.begin(), string.end(), 0, [&string](int sum, char c) {
        return sum + pow(c - '0', string.length());
    });
}

int main() {
    std::cout << narcissistic(153) << std::endl;
    return 0;
}
