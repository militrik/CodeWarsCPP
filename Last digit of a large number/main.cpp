#include <iostream>

#include <string>

int last_digit(const std::string &str1, const std::string &str2) {
    int base = str1.back() - '0';
    int pow;
    if (str2.length() > 1)
        pow = std::stoi(str2.substr(str2.length() - 2));
    else {
        pow = str2.back() - '0';
        if (pow == 0) return 1;
    }

    pow = pow % 4;

    switch (base) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            switch (pow) {
                case 1:
                    return 2;
                case 2:
                    return 4;
                case 3:
                    return 8;
                case 0:
                    return 6;
            }
        case 3:
            switch (pow) {
                case 1:
                    return 3;
                case 2:
                    return 9;
                case 3:
                    return 7;
                case 0:
                    return 1;
            }
        case 4:
            switch (pow) {
                case 1:
                case 3:
                    return 4;
                case 2:
                case 0:
                    return 6;
            }
        case 5:
            return 5;
        case 6:
            return 6;
        case 7:
            switch (pow) {
                case 1:
                    return 7;
                case 2:
                    return 9;
                case 3:
                    return 3;
                case 0:
                    return 1;
            }
        case 8:
            switch (pow) {
                case 1:
                    return 8;
                case 2:
                    return 4;
                case 3:
                    return 2;
                case 0:
                    return 6;
            }
        case 9:
            switch (pow) {
                case 1:
                case 3:
                    return 9;
                case 2:
                case 0:
                    return 1;
            }
        default:
            return 0;
    }
}


int main() {
    std::cout << "4\t" << last_digit("4", "1") << std::endl;
    std::cout << "6\t" << last_digit("4", "2") << std::endl;
    std::cout << "9\t" << last_digit("9", "7") << std::endl;
    std::cout << "0\t" << last_digit("10", "10000000000") << std::endl;
    std::cout << "6\t" << last_digit("1606938044258990275541962092341162602522202993782792835301376",
                                     "2037035976334486086268445688409378161051468393665936250636140449354381299763336706183397376")
              << std::endl;
    std::cout << "7\t" << last_digit("3715290469715693021198967285016729344580685479654510946723",
                                     "68819615221552997273737174557165657483427362207517952651") << std::endl;

    return 0;
}
