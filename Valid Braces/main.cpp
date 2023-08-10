#include <iostream>
#include <vector>

bool valid_braces(std::string braces) {

    std::vector<char> vector;

    for (char currentChar: braces) {
        switch (currentChar) {
            case '(':
                vector.push_back(')');
                break;
            case '[':
                vector.push_back(']');
                break;
            case '{':
                vector.push_back('}');
                break;
            default:
                if (vector.empty() || vector.back() != currentChar)
                    return false;
                vector.pop_back();
                break;
        }
    }
    return vector.empty();
}

int main() {
    std::cout << valid_braces("(){}[]") << std::endl;
    std::cout << valid_braces("([{}])") << std::endl;
    std::cout << valid_braces("(}") << std::endl;
    std::cout << valid_braces("[(])") << std::endl;
    std::cout << valid_braces("[({})](]") << std::endl;
    return 0;
}
