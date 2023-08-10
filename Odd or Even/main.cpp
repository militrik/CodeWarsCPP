#include <iostream>

#include <string>
#include <vector>
#include <numeric>


std::string odd_or_even(const std::vector<int> &arr) {
    return std::accumulate(arr.begin(), arr.end(), 0) % 2 ? "odd" : "even" ; // your code here
}

int main() {
    std::cout << odd_or_even(*new std::vector<int>{3, 5, 7}) << std::endl;
    return 0;
}
