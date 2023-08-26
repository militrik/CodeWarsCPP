#include <iostream>

#include <string>
#include <algorithm>
#include <list>
#include <ctime>

using namespace std;

bool path_finder(string maze) {
    const int n = std::distance(maze.begin(), std::find(maze.begin(), maze.end(), '\n'));
    int stepArr[] = {n + 1, 1, -n - 1, -1};
    std::list<std::string::iterator> list = {maze.begin()};
    while (list.back() + 1 != maze.end()) {
        std::string::iterator pos = list.back();
        auto listPtr = std::prev(list.end());;
        for (auto step: stepArr) {
            if (*(pos + step) == '.') {
                list.push_back(pos + step);
            }
        }
        maze[std::distance(maze.begin(), pos)] = 'W';
        list.erase(listPtr);
        if (list.empty())
            return false;
    }
    return true;
}

int main() {
    std::cout << path_finder("WWWW\nWWWW\nWWWW\nWWWW") << false << std::endl;
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




    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    int n = 20;//361;  // Замініть це значення на бажану кількість рядків

    int total_chars = n * (n + 1) - 1;
    int chars_written = 0;
    std::string result;

    while (chars_written < total_chars) {
        char c = (std::rand() % 3 == 0) ? 'W' : '.';
        result += c;

        chars_written++;

        if (chars_written % (n + 1) == 0) {
            result += '\n';
        }
    }

    std::cout << result<< std::endl<< std::endl;

    std::cout << path_finder(result) << std::endl;




    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
