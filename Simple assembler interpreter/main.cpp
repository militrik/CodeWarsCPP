#include <iostream>

#include <unordered_map>
#include <vector>
#include <string>

bool isNumber(const std::string& str) {
    for (char c : str) {
        if (!isdigit(c) && c != '-' && c != '.')
            return false;
    }
    return true;
}

std::unordered_map<std::string, int> assembler(const std::vector<std::string>& program) {
    std::unordered_map<std::string, int> regs;
    std::vector<int> integers;

    for (auto programIt = program.begin(); programIt != program.end(); ++programIt) {
        const std::string& input = *programIt;
        std::vector<std::string> command;

        size_t pos = 0;
        while (pos < input.size()) {
            size_t spacePos = input.find(' ', pos);
            if (spacePos == std::string::npos)
                spacePos = input.size();
            command.emplace_back(input.substr(pos, spacePos - pos));
            pos = spacePos + 1;
        }

        const std::string& cmd = command[0];

        if (cmd == "mov") {
            const std::string& dest = command[1];
            const std::string& src = command[2];
            regs[dest] = isNumber(src) ? std::stoi(src) : regs[src];
        } else if (cmd == "inc") {
            regs[command[1]]++;
        } else if (cmd == "dec") {
            regs[command[1]]--;
        } else if (cmd == "jnz") {
            const std::string& val1 = command[1];
            const std::string& val2 = command[2];
            const int num1 = isNumber(val1) ? std::stoi(val1) : regs[val1];
            const int num2 = isNumber(val2) ? std::stoi(val2) : regs[val2];
            if (num1 != 0)
                programIt = std::next(programIt, num2 - 1);
        }
    }

    return regs;
}


int main() {
    std::vector<std::string> program{"mov a 1","mov b 1","mov c 0","mov d 26","jnz c 2","jnz 1 5","mov c 7","inc d","dec c","jnz c -2","mov c a","inc a","dec b","jnz b -2","mov b c","dec d","jnz d -6","mov c 18","mov d 11","inc a","dec d","jnz d -2","dec c","jnz c -5"};


    std::unordered_map<std::string, int> myMap = assembler(program);


    for (const auto &pair: myMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
