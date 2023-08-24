#include <iostream>
#include <vector>

std::vector<std::vector<int>> rotateMatrix(const std::vector<std::vector<int>> &matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    std::vector<std::vector<int>> rotated(cols, std::vector<int>(rows));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            rotated[cols - j - 1][i] = matrix[i][j];
        }
    }
    return rotated;
}

std::vector<int> snail(const std::vector<std::vector<int>> &snail_map) {
    std::vector<std::vector<int>> matrix = snail_map;
    std::vector<int> result;

    while (!matrix.empty()) {
        result.insert(result.end(), matrix[0].begin(), matrix[0].end());
        matrix.erase(matrix.begin());
        matrix = rotateMatrix(matrix);
    }
    return result;
}

int main() {
    std::vector<std::vector<int>> originalMatrix = {
            {1, 2, 3},
            {8, 9, 4},
            {7, 6, 5}
    };

    // Вивід оригінальної матриці
    std::cout << "Original Matrix:\n";
    int rows = originalMatrix.size();
    int cols = originalMatrix[0].size();

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << originalMatrix[i][j] << " ";
        }
        std::cout << "\n";
    }

    std::vector<int> r = snail(originalMatrix);
    for (auto e: r) {
        std::cout << e << " ";
    }

    return 0;
}
