#include <iostream>


class Machine {
public:
    int weight = 1;

    unsigned int command(unsigned int cmd, unsigned int num) {
        return num * weight;
    };

    void response(bool res) {
        weight++;
    };
};


int main() {

    Machine machine;

    unsigned int cmd_to_learn = 78;
    unsigned int action_associated_to_cmd = 3;

    for (unsigned int i = 0; i < 20; ++i) {
        unsigned int result = machine.command(cmd_to_learn, i); // i is not random for simplicity
        machine.response(result == get_action(action_associated_to_cmd)(i));
    }

    unsigned int final_test_number = 56;
    Assert::That(machine.command(cmd_to_learn, final_test_number),
                 Equals(get_action(action_associated_to_cmd)(final_test_number)));


    std::cout << "Hello, World!" << std::endl;
    return 0;
}
