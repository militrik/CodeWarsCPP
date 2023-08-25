#include <algorithm>
#include <string>
#include <vector>

std::vector<std::string> get_pins(std::string observed) {
    do {
        for (int i = 0; i < N; ++i) {
            std::cout << combination[i] << " ";
        }
        std::cout << "\n";
    } while (std::next_permutation(combination.begin(), combination.end()));
}

int main() {

    std::vector<int> nums = {1, 2, 4, 1, 2, 4};
    get_pins(nums);

    return 0;
}
