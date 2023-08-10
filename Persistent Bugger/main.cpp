#include <iostream>

int persistence(long long n) {
    // your code here
    int cnt = 0;
    while (n / 10) {
        std::string numberStr = std::to_string(n);
        long long mul = 1;
        for (char digitChar: numberStr) {
            int digit = digitChar - '0';
            mul *= digit;
        }
        n = mul;
        cnt++;
    }
    return cnt;
}

int main() {
    std::cout << persistence(25) << std::endl;
    return 0;
}
