#include <iostream>

#include <string>
#include <vector>

std::string solution(int number) {
    std::vector<std::pair<std::string, int>> vector = {
            std::pair<std::string, int>{"MMM", 3000},
            std::pair<std::string, int>{"MM", 2000},
            std::pair<std::string, int>{"M", 1000},
            std::pair<std::string, int>{"CM", 900},
            std::pair<std::string, int>{"DCCC", 800},
            std::pair<std::string, int>{"DCC", 700},
            std::pair<std::string, int>{"DC", 600},
            std::pair<std::string, int>{"D", 500},
            std::pair<std::string, int>{"CD", 400},
            std::pair<std::string, int>{"CCC", 300},
            std::pair<std::string, int>{"CC", 200},
            std::pair<std::string, int>{"C", 100},
            std::pair<std::string, int>{"XC", 90},
            std::pair<std::string, int>{"LXXX", 80},
            std::pair<std::string, int>{"LXX", 70},
            std::pair<std::string, int>{"LX", 60},
            std::pair<std::string, int>{"L", 50},
            std::pair<std::string, int>{"XL", 40},
            std::pair<std::string, int>{"XXX", 30},
            std::pair<std::string, int>{"XX", 20},
            std::pair<std::string, int>{"X", 10},
            std::pair<std::string, int>{"IX", 9},
            std::pair<std::string, int>{"VIII", 8},
            std::pair<std::string, int>{"VII", 7},
            std::pair<std::string, int>{"VI", 6},
            std::pair<std::string, int>{"V", 5},
            std::pair<std::string, int>{"IV", 4},
            std::pair<std::string, int>{"III", 3},
            std::pair<std::string, int>{"II", 2},
            std::pair<std::string, int>{"I", 1},
    };

    std::string string;
    for (auto &i: vector) {
        int temp = number / i.second;
        if (temp != 0) {
            string += i.first;
        }
        number %= i.second;
    }

    return string;
}

int main() {
    std::cout << solution(3999) << std::endl;
    return 0;
}
