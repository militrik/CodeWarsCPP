#include <iostream>
#include <algorithm>
#include <sstream>

/*long nextBigger(long n) {
    std::string myString = std::to_string(n);
    //std::sort(myString.begin(), myString.end());
    std::vector<long> vector;
    long myMax=INT_FAST64_MAX;
    do {
        std::istringstream iss(myString);
        long num;
        iss >> num;
        if (num>n && num<myMax) myMax = num;
    } while (std::next_permutation(myString.begin(), myString.end()));
    //std::sort(vector.begin(), vector.end());
    //auto it = std::find(vector.begin(), vector.end(), n);
    //if (it!= vector.end() && *it < *(it+1) )
    //    return *++it;
    if (myMax>n)
        return myMax;
    else
        return -1;
}*/

/*long nextBigger(long n) {
    std::string sortedOriginal = std::to_string(n);
    std::sort(sortedOriginal.begin(), sortedOriginal.end());
    while (n++ < INT64_MAX) {
        std::string newStr = std::to_string(n);
        std::sort(newStr.begin(), newStr.end());
        if (newStr == sortedOriginal)
            return n;
    }
    return -1;
}*/

/*long nextBigger(long n) {
    // Convert the number to a vector of digits
    std::vector<int> digits;
    while (n > 0) {
        digits.push_back(n % 10);
        n /= 10;
    }
    std::reverse(digits.begin(), digits.end());

    // Find the first digit that can be swapped to create a bigger number
    int i = digits.size() - 2;
    while (i >= 0 && digits[i] >= digits[i + 1]) {
        i--;
    }

    if (i < 0) {
        // No such digit found, the number is in decreasing order
        return -1;
    }

    // Find the smallest digit to the right of digits[i] that is greater than digits[i]
    int j = digits.size() - 1;
    while (digits[j] <= digits[i]) {
        j--;
    }

    // Swap digits[i] and digits[j]
    std::swap(digits[i], digits[j]);

    // Reverse the digits to the right of i
    std::reverse(digits.begin() + i + 1, digits.end());

    // Convert the vector of digits back to a number
    long result = 0;
    for (int digit : digits) {
        result = result * 10 + digit;
    }

    return result;
}*/

#include <algorithm>
long nextBigger(long n) {

    std::string str = std::to_string(n);
    return std::next_permutation(str.begin(), str.end()) ? std::stol(str) : -1;

}

int main() {
    std::cout << nextBigger(12) << "\t\t" << 21 << std::endl;
    std::cout << nextBigger(513) << "\t\t" << 531 << std::endl;
    std::cout << nextBigger(2017) << "\t\t" << 2071 << std::endl;
    std::cout << nextBigger(414) << "\t\t" << 441 << std::endl;
    std::cout << nextBigger(144) << "\t\t" << 414 << std::endl;
    std::cout << nextBigger(10990) << "\t\t" << 19009 << std::endl;
    std::cout << nextBigger(59853) << "\t\t" << 83559 << std::endl;
    std::cout << nextBigger(59884848459853) << "\t\t" << 59884848483559 << std::endl;
    std::cout << nextBigger(1588879484005846372) << "\t\t" << 1588879484005846723 << std::endl;
    std::cout << nextBigger(2861543751719551053) << "\t\t" << 2861543751719551305 << std::endl;
    std::cout << nextBigger(3069999998866533332) << "\t\t" << 3082333356668999999 << std::endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
