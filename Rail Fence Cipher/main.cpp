#include <iostream>

#include <string>
#include <vector>

std::string encode_rail_fence_cipher(const std::string &str, int n) {

    std::vector<std::string> encodedStrings(n);
    int index = 0;
    bool direction = false;
    for (char c: str) {
        encodedStrings[index].push_back(c);
        if (index == 0 || index == n - 1) direction = !direction;
        if (direction) index++;
        else index--;
    }

    std::string encodedString;
    for (auto s: encodedStrings) {
        encodedString += s;
    }

    return encodedString;
}

std::string decode_rail_fence_cipher(const std::string &str, int n) {
    std::vector<std::string> decodedStrings(n);
    int index = 0;
    bool direction = false;
    std::vector<int> cntSymb(n, 0);
    for (char c: str) {
        cntSymb[index]++;
        if (index == 0 || index == n - 1) direction = !direction;
        if (direction) index++;
        else index--;
    }
    int pos = 0;
    for (int i = 0; i < n; ++i) {
        decodedStrings[i] = str.substr(pos, cntSymb[i]);
        pos += cntSymb[i];
    }

    std::string decodedString;
    index = 0;
    direction = false;
    for (int i = 0; i < str.length(); ++i) {
        char c = decodedStrings[index][0];
        decodedStrings[index].erase(0, 1);
        decodedString.push_back(c);
        if (index == 0 || index == n - 1) direction = !direction;
        if (direction) index++;
        else index--;
    }

    return decodedString;
}


int main() {
    std::string string = "WEAREDISCOVEREDFLEEATONCE";
    std::cout << string << std::endl;
    string = encode_rail_fence_cipher(string, 3);
    std::cout << string << std::endl;
    string = decode_rail_fence_cipher(string, 3);
    std::cout << string << std::endl;
    return 0;
}
