#include <iostream>
#include <string>

bool is_merge(const std::string& s, const std::string& part1, const std::string& part2) {
    if (s.empty() && part1.empty() && part2.empty()) {
        return true;  // All strings are empty
    }

    if (part1.empty()) {
        return s == part2;  // Check if s is equal to part2
    }

    if (part2.empty()) {
        return s == part1;  // Check if s is equal to part1
    }

    // Check if the first character of s matches either part1 or part2
    bool matchPart1 = !part1.empty() && s[0] == part1[0];
    bool matchPart2 = !part2.empty() && s[0] == part2[0];

    // Recursively check for both possibilities (using part1 or part2)
    return (matchPart1 && is_merge(s.substr(1), part1.substr(1), part2)) ||
           (matchPart2 && is_merge(s.substr(1), part1, part2.substr(1)));
}


/*    std::string string = part1 + part2;
    std::cout << string << std::endl;
    do {
        std::cout << string << std::endl;
        if (string == s) {

            //return true;
        }
    } while (std::next_permutation(string.begin(), string.end()));
    string = part1 + part2;
    do {
        std::cout << string << std::endl;
        if (string == s) {
            std::cout << string << std::endl;
            //return true;
        }
    } while (std::prev_permutation(string.begin(), string.end()));
    return false;*/



int main() {
    std::cout << true << is_merge("codewars", "code", "wars") << std::endl;
    std::cout << true << is_merge("codewars", "wars", "code") << std::endl;
    std::cout << false << is_merge("codewars", "codew", "wars") << std::endl;
    std::cout << false << is_merge("codewars", "code", "warss") << std::endl;
    std::cout << false << is_merge("codewars", "code", "code") << std::endl;
    std::cout << true << is_merge("codewars", "codewars", "") << std::endl;
    std::cout << true << is_merge("codewars", "", "codewars") << std::endl;

    std::cout << std::endl;

    std::cout << true << is_merge("acab", "ab", "ac") << std::endl;
    std::cout << true << is_merge("acab", "ac", "ab") << std::endl;
    std::cout << true << is_merge("acab", "aa", "cb") << std::endl;
    std::cout << true << is_merge("acab", "cb", "aa") << std::endl;
    std::cout << false << is_merge("acab", "ca", "ba") << std::endl;
    std::cout << false << is_merge("acab", "bc", "aa") << std::endl;
    std::cout << false << is_merge("acab", "cb", "aaa") << std::endl;


    std::cout << "Hello, World!" << std::endl;
    return 0;
}
