#include <iostream>
#include <regex>
#include <string>
#include <iomanip>

std::string incrementString(const std::string &str) {
    std::regex pattern("^(.*?)(\\d*)$");
    std::smatch matches;
    std::stringstream oss;
    std::regex_search(str, matches, pattern);
    oss << matches[1].str();
    if (!matches[2].str().empty()) {
        oss << std::setfill('0')
            << std::setw(matches[2].length())
            << std::stoi(matches[2]) + 1;
    } else {
        oss << "1";
    }
    return oss.str();
}


int main() {
    std::cout << incrementString("foo") << std::endl;
    std::cout << incrementString("foobar000") << std::endl;
    std::cout << incrementString("foo") << std::endl;
    std::cout << incrementString("foobar001") << std::endl;
    std::cout << incrementString("foobar99") << std::endl;
    std::cout << incrementString("foobar099") << std::endl;
    std::cout << incrementString("") << std::endl;
    std::cout << incrementString("fo99obar99") << std::endl;


    return 0;
}

