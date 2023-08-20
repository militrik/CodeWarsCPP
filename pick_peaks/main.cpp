#include <iostream>
#include <vector>

struct PeakData {
    std::vector<int> pos, peaks;
};

PeakData pick_peaks(const std::vector<int> &v) {
    PeakData temp, result;
    if (!v.empty() && v.size() != 1) {
        temp.pos.push_back(0);
        temp.peaks.push_back(v[0]);
        for (auto i = 1; i < v.size(); i++) {
            if (v[i] != temp.peaks.back()) {
                temp.pos.push_back(i);
                temp.peaks.push_back(v[i]);
            }
        }
        for (auto i = 1; i < temp.peaks.size() - 1; ++i) {
            if (temp.peaks[i - 1] < temp.peaks[i] && temp.peaks[i] > temp.peaks[i + 1]) {
                result.peaks.push_back(temp.peaks[i]);
                result.pos.push_back(temp.pos[i]);
            }
        }
    }
    return result;
}

int main() {
    //PeakData result = pick_peaks({3, 2, 3, 6, 4, 1, 2, 3, 2, 1, 2, 3});
    PeakData result = pick_peaks({2, 2, 2, 2, 2});
    //PeakData result = pick_peaks({2, 2, 2, 2, 4, 3, 1, 4, 4, 4, 3});
    std::cout << "Peak position: ";
    for (int pos: result.pos) {
        std::cout << pos << " ";
    }
    std::cout << "\nPeak value: ";
    for (int peak: result.peaks) {
        std::cout << peak << " ";
    }
    std::cout << std::endl;
    return 0;
}
