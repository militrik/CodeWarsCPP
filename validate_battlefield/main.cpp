#include <iostream>

#include <vector>

bool validate_battlefield(std::vector<std::vector<int>> field) {

    //create ships masks
    std::vector<std::vector<int>> battleshipV1 = {
            {0, 0, 0},
            {0, 1, 0},
            {0, 1, 0},
            {0, 1, 0},
            {0, 1, 0},
            {0, 0, 0}
    };
    std::vector<std::vector<int>> battleshipV2 = {
            {0, 0, 0, 0, 0, 0},
            {0, 1, 1, 1, 1, 0},
            {0, 0, 0, 0, 0, 0}
    };
    std::vector<std::vector<int>> cruiserV1 = {
            {0, 0, 0},
            {0, 1, 0},
            {0, 1, 0},
            {0, 1, 0},
            {0, 0, 0}
    };
    std::vector<std::vector<int>> cruiserV2 = {
            {0, 0, 0, 0, 0},
            {0, 1, 1, 1, 0},
            {0, 0, 0, 0, 0}
    };
    std::vector<std::vector<int>> destroyerV1 = {
            {0, 0, 0},
            {0, 1, 0},
            {0, 1, 0},
            {0, 0, 0}
    };
    std::vector<std::vector<int>> destroyerV2 = {
            {0, 0, 0, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0}
    };
    std::vector<std::vector<int>> submarineV1 = {
            {0, 0, 0},
            {0, 1, 0},
            {0, 0, 0}
    };
    std::vector<std::vector<std::vector<int>>> ships = {
            battleshipV1,
            battleshipV2,
            cruiserV1,
            cruiserV2,
            destroyerV1,
            destroyerV2,
            submarineV1
    };
    std::vector<int> shipsCnt(ships.size(), 0);

    // extend standard field on 1 size from all sides
    std::vector<std::vector<int>> extendedField(10 + 1 + 1, std::vector<int>(10 + 1 + 1, 0));
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            extendedField[i + 1][j + 1] = field[i][j];
        }
    }

    // copy field with mask size and compare with mask. increment ships counter if true. repeat for all points.
    for (int shipsIndex = 0; shipsIndex < ships.size(); ++shipsIndex) {
        for (int x = 0; x < extendedField.size() - ships[shipsIndex].size() + 1; ++x) {
            for (int y = 0; y < extendedField[0].size() - ships[shipsIndex][0].size() + 1; ++y) {
                std::vector<std::vector<int>> copiedField(ships[shipsIndex].size(),
                                                          std::vector<int>(ships[shipsIndex][0].size(), 0));
                for (int i = 0; i < ships[shipsIndex].size(); i++) {
                    for (int j = 0; j < ships[shipsIndex][0].size(); j++) {
                        copiedField[i][j] = extendedField[x + i][y + j];
                    }
                }
                if (ships[shipsIndex] == copiedField)
                    shipsCnt[shipsIndex]++;
            }
        }
    }

    // interpreter result
    if (shipsCnt[0] + shipsCnt[1] == 1 &&
        shipsCnt[2] + shipsCnt[3] == 2 &&
        shipsCnt[4] + shipsCnt[5] == 3 &&
        shipsCnt[6] == 4
            )
        return true;
    else
        return false;
}

int main() {
    std::vector<std::vector<int>> field =
            {
                    std::vector<int>{1, 0, 0, 0, 0, 1, 1, 0, 0, 0},
                    std::vector<int>{1, 0, 1, 0, 0, 0, 0, 0, 1, 0},
                    std::vector<int>{1, 0, 1, 0, 1, 1, 1, 0, 1, 0},
                    std::vector<int>{1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    std::vector<int>{0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
                    std::vector<int>{0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                    std::vector<int>{0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
                    std::vector<int>{0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
                    std::vector<int>{0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                    std::vector<int>{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

            };
    std::cout << validate_battlefield(field) << std::endl;
    return 0;
}
