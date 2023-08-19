#include <iostream>
#include <vector>

bool valid_braces(std::string braces) {

    std::vector<std::pair<char, char>> bracesTable = {
            {'(', ')'},
            {'[', ']'},
            {'{', '}'},
    };
    std::vector<char> vector;

    for (char currentChar: braces) {

        if (vector.empty() || vector.back() != currentChar) {
            return false;
        } else {
            vector.pop_back();
        }

        for (auto bracesPair: bracesTable) {
            if (bracesPair.first == currentChar) {
                vector.push_back(bracesPair.second);
                continue;
            }
        }
    }


/*    for (char currentChar: braces) {
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
    }*/
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
