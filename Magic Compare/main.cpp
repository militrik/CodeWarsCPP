#include <iostream>

template<class T>
class MagicCompare {
private:
    T value;
    bool valid;

public:
    MagicCompare(const T &val) : value(val), valid(true) {}

    operator bool() const {
        return valid;
    }

    // Implement the comparison operators
    bool operator<(const T &other) const {
        return valid && (value < other);
    }

    bool operator<=(const T &other) const {
        return valid && (value <= other);
    }

    bool operator>(const T &other) const {
        return valid && (value > other);
    }

    bool operator>=(const T &other) const {
        return valid && (value >= other);
    }

    bool operator==(const T &other) const {
        return valid && (value == other);
    }

    bool operator!=(const T &other) const {
        return valid && (value != other);
    }

    // Implement the logical operators
    MagicCompare operator&&(const MagicCompare &other) const {
        return MagicCompare(value) && other;
    }

    MagicCompare operator||(const MagicCompare &other) const {
        return MagicCompare(value) || other;
    }

    MagicCompare operator!() const {
        return MagicCompare(value) && false;
    }
};


int main() {
    using MagicInt = MagicCompare<int>;
    MagicInt a = 3;
    bool res_4lta = (4 < a);
    std::cout << res_4lta << "\t" << false << std::endl;
    bool res_5gtalt7neqa = (5 > a < 7 != a);
    std::cout << res_5gtalt7neqa << "\t" << true << std::endl;
    return 0;
}
