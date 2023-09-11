#include <iostream>

#include <vector>
#include <algorithm>


bool areAllVectorsEmpty(const std::vector<std::vector<int>> &nestedVector) {
    for (const std::vector<int> &innerVector: nestedVector) {
        if (!innerVector.empty()) {
            return false;
        }
    }
    return true;
}

std::vector<int> the_lift(const std::vector<std::vector<int>> &queues, int capacity) {
    std::vector<std::vector<int>> floorQueues = queues;
    std::vector<int> liftQueues;
    std::vector<int> result(1, 0);
    bool isUp = true;
    int floor = 0;

    while (!areAllVectorsEmpty(floorQueues) || !liftQueues.empty()) {

        // unload if needed
        for (int liftQueueIndex = 0; liftQueueIndex < liftQueues.size(); ++liftQueueIndex) {
            if (liftQueues[liftQueueIndex] == floor) {
                liftQueues.erase(liftQueues.begin() + liftQueueIndex);
                liftQueueIndex--;
                result.push_back(floor);
            }
        }

        // loading if possible depending on direction and occupancy
        for (int floorQueueIndex = 0; floorQueueIndex < floorQueues[floor].size(); ++floorQueueIndex) {
            int human = floorQueues[floor][floorQueueIndex];
            if ((isUp ? human > floor : human < floor)) {
                result.push_back(floor);
                if (liftQueues.size() >= capacity)
                    break;
                floorQueues[floor].erase(floorQueues[floor].begin() + floorQueueIndex);
                liftQueues.push_back(human);
                floorQueueIndex--;
                result.push_back(floor);
            }

        }

        // reverse direction
        if (isUp) floor++;
        else floor--;
        if (floor >= floorQueues.size() || floor < 0) {
            if (isUp) floor--;
            else floor++;
            isUp = !isUp;
        }
    }

    // add last floor
    result.push_back(0);

    // clear duplicate sequential floors
    for (int i = 0; i < result.size()-1; ++i) {
        if (result[i] == result[i + 1]) {
            result.erase(result.begin() + i);
            i--;
        }
    }

    return result;
}


int main() {
    {
        std::vector<std::vector<int>> queues; std::vector<int> result; std::vector<int> res;

        queues = { {}, {}, {5,5,5}, {}, {}, {}, {} };
        result = {0, 2, 5, 0};
        for (auto i:result) {
            std::cout << i << "\t";
        }
        std::cout << std::endl;
        res = the_lift(queues, 5);
        for (auto i:res) {
            std::cout << i << "\t";
        }
        std::cout << std::endl;
        std::cout << std::endl;


        queues = { {}, {}, {1,1}, {}, {}, {}, {} };
        result = {0, 2, 1, 0};
        for (auto i:result) {
            std::cout << i << "\t";
        }
        std::cout << std::endl;
        res = the_lift(queues, 5);
        for (auto i:res) {
            std::cout << i << "\t";
        }
        std::cout << std::endl;
        std::cout << std::endl;

        queues = { {}, {3}, {4}, {}, {5}, {}, {} };
        result = {0, 1, 2, 3, 4, 5, 0};
        for (auto i:result) {
            std::cout << i << "\t";
        }
        std::cout << std::endl;
        res = the_lift(queues, 5);
        for (auto i:res) {
            std::cout << i << "\t";
        }
        std::cout << std::endl;
        std::cout << std::endl;

        queues = { {}, {0}, {}, {}, {2}, {3}, {} };
        result = {0, 5, 4, 3, 2, 1, 0};
        for (auto i:result) {
            std::cout << i << "\t";
        }
        std::cout << std::endl;
        res = the_lift(queues, 5);
        for (auto i:res) {
            std::cout << i << "\t";
        }
        std::cout << std::endl;
        std::cout << std::endl;


        queues = { {}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0} };
        result = {0, 6, 5, 4, 3, 2, 1, 0, 5, 4, 3, 2, 1, 0, 4, 3, 2, 1, 0, 3, 2, 1, 0, 1, 0};
        for (auto i:result) {
            std::cout << i << "\t";
        }
        std::cout << std::endl;
        res = the_lift(queues, 5);
        for (auto i:res) {
            std::cout << i << "\t";
        }
        std::cout << std::endl;
        std::cout << std::endl;

    }




    return 0;
}
