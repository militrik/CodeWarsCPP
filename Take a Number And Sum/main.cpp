#include <iostream>

#include <vector>
#include <numeric>
#include <cmath>

std::vector<unsigned int> sumDigPow(unsigned int a, unsigned int b) {
    //your code here
    std::vector<unsigned int> vector;
    while (a <= b) {
        std::string string = std::to_string(a);
        int iteratorCnt = 0;
        int res = std::accumulate(string.begin(), string.end(), 0, [&iteratorCnt](unsigned int sum, char c) {
            iteratorCnt++;
            return sum + pow(c - '0', iteratorCnt);
        });
        if (a == res)
            vector.push_back(a);
        a++;
    }
    return vector;
}

int main() {
    std::vector vec = sumDigPow(1, 10000);
    for (auto v: vec) {
        std::cout << v << std::endl;
    }
    return 0;
}
