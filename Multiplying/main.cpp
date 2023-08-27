#include <iostream>
#include <string>

using namespace std;

string multiply(string a, string b) {
    int len1 = a.length();
    int len2 = b.length();
    std::string result(len1 + len2, '0');

    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            int mul = (a[i] - '0') * (b[j] - '0');
            int sum = mul + (result[i + j + 1] - '0');
            result[i + j + 1] = (sum % 10) + '0';
            result[i + j] += sum / 10;
        }
    }
    result.erase(0, result.find_first_not_of('0'));
    return result.empty() ? "0" : result;
}

int main() {
    cout << multiply("2", "3") << "\t\t6" << endl;
    cout << multiply("30", "69") << "\t\t2070" << endl;
    cout << multiply("11", "85") << "\t\t935" << endl;

    cout << multiply("2", "0") << "\t\t0" << endl;
    cout << multiply("0", "30") << "\t\t0" << endl;
    cout << multiply("0000001", "3") << "\t\t3" << endl;
    cout << multiply("1009", "03") << "\t\t3027" << endl;

    cout << multiply("98765", "56894") << "\t\t5619135910" << endl;;
    cout << multiply("1020303004875647366210", "2774537626200857473632627613")
         << "\t\t2830869077153280552556547081187254342445169156730" << endl;
    cout << multiply("58608473622772837728372827", "7586374672263726736374")
         << "\t\t444625839871840560024489175424316205566214109298" << endl;
    cout << multiply("9007199254740991", "9007199254740991") << "\t\t81129638414606663681390495662081" << endl;


    return 0;
}
