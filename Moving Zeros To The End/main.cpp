#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> move_zeroes(std::vector<int> input) {
    std::vector<int> output(input.size());

    auto new_end = std::remove(input.begin(), input.end(), 0);
    std::copy(input.begin(), new_end, output.begin());

    return output;
}

int main() {

    std::vector<int> vec = move_zeroes(std::vector<int>{1, 0, 1, 2, 0, 1, 3});
    std::for_each(vec.begin(), vec.end(), [](const int &element) {
        std::cout << element << " ";
    });
    std::cout << std::endl;

    return 0;
}
