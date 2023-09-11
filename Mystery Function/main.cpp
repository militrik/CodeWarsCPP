#include <iostream>
#include <vector>

using namespace std;

// Функция для генерации кода Грея для чисел типа ulong
vector<unsigned long long> generateGrayCode(int n) {
    if (n == 0) {
        vector<unsigned long long> grayCode;
        grayCode.push_back(0);
        return grayCode;
    }

    vector<unsigned long long> prevGrayCode = generateGrayCode(n - 1);
    int size = prevGrayCode.size();
    vector<unsigned long long> grayCode;

    // Добавляем элементы из предыдущего кода Грея в обратном порядке
    for (int i = size - 1; i >= 0; i--) {
        grayCode.push_back(prevGrayCode[i]);
    }

    // Добавляем к новым элементам старший бит
    unsigned long long msb = 1ULL << (n - 1);
    for (int i = 0; i < size; i++) {
        grayCode.push_back(prevGrayCode[i] | msb);
    }

    return grayCode;
}

int main() {
    int n;
    cout << "Введите количество битов: ";
    cin >> n;

    vector<unsigned long long> grayCode = generateGrayCode(n);

    cout << "Коды Грея для " << n << " битов:" << endl;
    for (int i = 0; i < grayCode.size(); i++) {
        cout << grayCode[i] << endl;
    }

    return 0;
}
