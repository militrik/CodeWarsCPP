#include <iostream>
#include <cmath>
#include <vector>

class IntPart {

public:
    static std::string part(long long n) {

        // create Yung square
        int yungSquareSize = sqrtl(n);
        if (yungSquareSize * yungSquareSize < n)
            yungSquareSize++;
        std::vector<std::vector<bool>> yungSquare(yungSquareSize, std::vector<bool>(yungSquareSize));


        // mark by diagonal unused cells in square
        int x = yungSquareSize - 1;
        int y = yungSquareSize - 1;
        int initX = yungSquareSize;
        int count = 0;
        while (x > 0) {
            initX--;
            x = initX;
            y = yungSquareSize - 1;
            while (x >= 0 && x < yungSquareSize && y >= 0 && y < yungSquareSize) {
                if (yungSquareSize * yungSquareSize - count <= n) {
                    x = -1;
                    break;
                }
                yungSquare[x][y] = true;
                x++;
                y--;
                count++;


                for (const auto &row: yungSquare) {
                    for (bool value: row) {
                        std::cout << (value ? "x " : ". ");
                    }
                    std::cout << std::endl;
                }
                std::cout << std::endl;


            }

        }

        // calculate max prod by rows and by columns
        int prodItemHorizontal = 1;
        for (const auto &row: yungSquare) {
            int maxItem = 0;
            for (bool value: row) {
                if (!value) {
                    maxItem++;
                }
            }
            if (maxItem)
                prodItemHorizontal *= maxItem;
        }
        int prodItemVertical = 1;
        for (int col = 0; col < yungSquareSize; ++col) {
            int maxItem = 0;
            for (int row = 0; row < yungSquareSize; ++row) {
                if (!yungSquare[row][col]) {
                    maxItem++;
                }
            }
            if (maxItem)
                prodItemVertical *= maxItem;
        }
        // get max prod
        int maxProd = (prodItemHorizontal > prodItemVertical ? prodItemHorizontal : prodItemVertical);

        // calc average
        int average = 0;
        for (int i = 1; i <= maxProd; ++i) {
            average += i;
        }
        double averageD = average / maxProd;

        // calc median
        double medianeD = 0;
        if (maxProd % 2)
            medianeD = (maxProd / 2 + 1 + maxProd / 2) / 2.0;


        return std::to_string(maxProd);
    };

};

int main() {

    std::cout << IntPart::part(8) << std::endl;
    return 0;
}
