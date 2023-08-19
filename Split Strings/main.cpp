#include <iostream>

#include <string>
#include <vector>

std::vector<std::string> solution(const std::string &s) {
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
    std::vector<std::string> vector = solution("HelloWorld");
    for (auto v: vector) {
        std::cout << v << std::endl;
    }
    return 0;
}
