#include <iostream>
#include <vector>
#include <algorithm>

#include <vector>
#include <algorithm>

int cut_log(const std::vector<int> &p, int n) {
    std::vector<int> vector(n + 1, 0);

    for (int j = 1; j <= n; ++j) {
        int max = 0;
        for (int i = 1; i <= j; ++i) {
            max = std::max(max, p[i] + vector[j - i]);
        }
        vector[j] = max;
    }
    return vector[n];
}

int main() {
    //                    0    1    2    3    4    5    6    7... and so on
    std::vector<int> p({0, 1, 5, 8, 9, 10, 17, 17, 20, 24, // 0X's
                        30, 32, 35, 39, 43, 43, 45, 49, 50, 54, // 1X's
                        57, 60, 65, 68, 70, 74, 80, 81, 84, 85, // 2X's
                        87, 91, 95, 99, 101, 104, 107, 112, 115, 116, // 3X's
                        119, 121, 125, 129, 131, 134, 135, 140, 143, 145, // 4X's
                        151}); // 50th element

    std::cout << cut_log(p, 1) << "\t" << 1 << std::endl;
    std::cout << cut_log(p, 5) << "\t" << 13 << std::endl;
    std::cout << cut_log(p, 8) << "\t" << 22 << std::endl;
    std::cout << cut_log(p, 10) << "\t" << 30 << std::endl;
    std::cout << cut_log(p, 22) << "\t" << 65 << std::endl;

    std::cout << cut_log(p, 0) << "\t" << 0 << std::endl;
    std::cout << cut_log(p, 23) << "\t" << 69 << std::endl;
    std::cout << cut_log(p, 37) << "\t" << 112 << std::endl;
    std::cout << cut_log(p, 41) << "\t" << 125 << std::endl;

    return 0;
}




