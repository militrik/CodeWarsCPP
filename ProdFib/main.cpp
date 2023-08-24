#include <iostream>

#include <vector>

typedef unsigned long long ull;

class ProdFib {
public:
    static std::vector<ull> productFib(ull prod) {
        ull n1 = 1, n = 2;
        while (n1 * n < prod) {
            std::swap(n1, n);
            n += n1;
        }
        if (n1*n==prod)
            return {n1, n, true};
        else
            return {n1, n, false};
    };
};

int main() {
    std::vector<ull> res = ProdFib::productFib(4895);
    for (auto item:res) {
        std::cout << item << std::endl;
    }

    return 0;
}
