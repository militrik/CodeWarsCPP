#include <iostream>

#include <algorithm>
#include <vector>
#include <string>
#include <regex>
#include <numeric>


std::string join(const std::string &sep, const std::vector<std::string> &to_join) {
    std::string result;
    if (!to_join.empty()) {
        result = to_join[0];
        for (size_t i = 1; i < to_join.size(); ++i) {
            result += sep + to_join[i];
        }
    }
    return result;
}

std::vector<std::string> split(const std::string &to_split, char separator = '\n') {
    std::string separator_regex(1, separator);
    std::regex regex_pattern(separator_regex);
    std::vector<std::string> splited{
            std::sregex_token_iterator(to_split.begin(), to_split.end(), regex_pattern, -1),
            std::sregex_token_iterator()
    };
    return splited;
}

int getSquare(int x0, int y0, int x1, int y1) {
    return (x1 + 1 - x0) * (y1 + 1 - y0);
}

int getRaisinsAmount(int x0, int y0, int x1, int y1, std::vector<std::string> *vector) {
    return std::accumulate(vector->begin() + x0, vector->begin() + x1 + 1, 0, [y0, y1](int cnt, std::string str) {
        return cnt + std::count_if(str.begin() + y0, str.begin() + y1 + 1, [](char c) { return c == 'o'; });
    });
}


std::vector<std::string> cut(const std::string &cake) {
    std::vector<std::string> splited = split(cake);
    int cakeWidth = splited[0].size();
    int cakeHeight = splited.size();
    int piecesAmount = getRaisinsAmount(0, 0, splited.size() - 1, splited[0].size() - 1, &splited);
    int pieceSize = cakeWidth * cakeHeight / piecesAmount;

    int x0 = 0, y0 = 0;

    for (int x1 = x0; x1 < cakeWidth; ++x1) {
        for (int y1 = y0; y1 < cakeHeight; ++y1) {
            int square = getSquare(x0, y0, x1, y1);
            int raisinCnt = getRaisinsAmount(x0, y0, x1, y1, &splited);
            if (raisinCnt > 1)
                break;
            if (square < pieceSize) {
                continue;
            } else if (square > pieceSize) {
                // don't mark piece
                break;
            } else {
                //mark piece
                break;
            }
        }

    }

    return {};
}


int main() {
    for (auto item: cut(
            ".o.o....\n"
            "........\n"
            "....o...\n"
            "........\n"
            ".....o..\n"
            "........\n")) {
        std::cout << item << std::endl;
    }
    return 0;
}

//"........\n..o.....\n...o....\n........"