#include <iostream>

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

enum Dirs {
    UP, RIGHT, DOWN, LEFT
} dir = RIGHT;


bool step(std::string::iterator *ptr, const int *hStep, const int *vStep, string *maze,
          Dirs dirs) {
    if (*ptr - *vStep > maze->begin() && *(*ptr - *vStep) != 'W' && dir != static_cast<Dirs>((dir + 2) % 4)) {
        *ptr -= *vStep;
        //return step(&ptr, &hStep, &vStep, &maze, dir);
    } else if (*(*ptr + *hStep) != '\n' && *(*ptr + *hStep) != 'W' && dir != static_cast<Dirs>((dir + 2) % 4)) {
        *ptr += *hStep;
        dir = static_cast<Dirs>((dir + 2) % 4);
    } else if (*ptr + *vStep < maze->end() && *(*ptr + *vStep) != 'W' && dir != static_cast<Dirs>((dir + 2) % 4)) {
        *ptr += *vStep;
        dir = static_cast<Dirs>((dir + 2) % 4);
    } else if (*(*ptr - *hStep) != '\n' && *(*ptr + *hStep) != 'W' && *ptr != maze->begin() &&
               dir != static_cast<Dirs>((dir + 2) % 4)) {
        *ptr -= *hStep;
        dir = static_cast<Dirs>((dir + 2) % 4);
    }
    return false;
}

bool path_finder(string maze) {
    const int n = std::distance(maze.begin(), std::find(maze.begin(), maze.end(), '\n'));
    const int maxPath = n * n + 1;
    const int minPath = n;
    const int vStep = n + 1, hStep = 1;
    std::string::iterator ptr = maze.begin();

    return step(&ptr, &hStep, &vStep, &maze, dir);
}

int main() {
    std::cout << path_finder(".W.\n.W.\n...") << true << std::endl;
    std::cout << path_finder(".W.\n.W.\nW..") << false << std::endl;
    std::cout << path_finder("......\n......\n......\n......\n......\n......") << true << std::endl;
    std::cout << path_finder("......\n......\n......\n......\n.....W\n....W.") << false << std::endl;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
