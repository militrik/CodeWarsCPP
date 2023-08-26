#include <iostream>

#include <string>
#include <algorithm>
#include <list>

using namespace std;

void printMaze(std::string::iterator ptr, const std::string *maze) {
    for (std::string::const_iterator it = maze->begin(); it != maze->end(); ++it) {
        if (it == ptr) {
            std::cout << 'x';
        } else {
            std::cout << *it;
        }
    }
    std::cout << std::endl << std::endl;
}

bool path_finder(string maze) {
    const int n = std::distance(maze.begin(), std::find(maze.begin(), maze.end(), '\n'));
    const int vStep = n + 1, hStep = 1;
    std::list<std::string::iterator> list = {maze.begin()};
    //*list.back() = 'W';

    while (list.back() + 1 != maze.end()) {

        std::string::iterator pos = list.back();
        auto listPtr = std::prev(list.end());;
        printMaze(pos, &maze);
        if (*(pos + vStep) == '.') {//down
            list.push_back(pos + vStep);
        }
        if (*(pos + hStep) == '.') {//right
            list.push_back(pos + hStep);
        }
        if (*(pos - vStep) == '.') {// up
            list.push_back(pos - vStep);
        }
        if (*(pos - hStep) == '.') {//left
            list.push_back(pos - hStep);
        }

        maze[std::distance(maze.begin(), pos)] = 'W';
        if (list.empty())
            return false;
        else
            list.erase(listPtr);

    }
    return true;
}

int main() {
    std::cout << path_finder("....\n..W.\nW..W\n.W..") << true << std::endl;
    std::cout << path_finder(".W.\n.W.\n...") << true << std::endl;
    std::cout << path_finder(".W.\n.W.\nW..") << false << std::endl;
    std::cout << path_finder("......\n......\n......\n......\n......\n......") << true << std::endl;
    std::cout << path_finder("......\n......\n......\n......\n.....W\n....W.") << false << std::endl;
    std::cout << path_finder(
            "....W.....\n....W.W.WW\n..WWWWW...\n..W...W.W.\n..W.W.W.W.\n..W.W.W.W.\n..W.W.W.W.\n..W.W.W.W.\n..W.W.W.W.\n....W...W.")
              << true << std::endl;
    std::cout << path_finder(
            "....W.....\n....W.W.WW\n..WWWWW...\n..W...W.W.\n..W.W.W.W.\n..W.W.W.W.\n..W.W.W.W.\n..W.W.W.W.\n..W.W.W.WW\n....W...W.")
              << false << std::endl;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
