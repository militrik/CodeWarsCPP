#include <iostream>
#include <string>
#include <sstream>


std::string highestScoringWord(const std::string &str) {
    std::stringstream ss(str);
    char c;
    int charsSum = 0;
    while (ss.get(c)) {
        if (c = ' '){
            charsSum = 0;
        }else{
            charsSum += (int)c;
        }
    }

}

int main() {

    std::cout << highestScoringWord("man i need a taxi up to ubud") << std::endl;
    std::cout << highestScoringWord("what time are we climbing up the volcano") << std::endl;
    std::cout << highestScoringWord("take me to semynak") << std::endl;
    std::cout << highestScoringWord("massage yes massage yes massage") << std::endl;
    std::cout << highestScoringWord("aa b") << std::endl;
    return 0;
}
