#include <iostream>

#include <string>
#include <vector>
#include <map>
#include <numeric>

std::string traverse_TCP_states(const std::vector<std::string> &events) {

    std::map<const std::string, std::map<const std::string, const std::string>> tcpMap = {
            {"CLOSED",      {
                                    {"APP_PASSIVE_OPEN", "LISTEN"},
                                    {"APP_ACTIVE_OPEN", "SYN_SENT"}
                            }},
            {"LISTEN",      {
                                    {"RCV_SYN",          "SYN_RCVD"},
                                    {"APP_SEND",        "SYN_SENT"},
                                    {"APP_CLOSE", "CLOSED"}
                            }},
            {"SYN_RCVD",    {
                                    {"APP_CLOSE",        "FIN_WAIT_1"},
                                    {"RCV_ACK",         "ESTABLISHED"}
                            }},
            {"SYN_SENT",    {
                                    {"RCV_SYN",          "SYN_RCVD"},
                                    {"RCV_SYN_ACK",     "ESTABLISHED"},
                                    {"APP_CLOSE", "CLOSED"}
                            }},
            {"ESTABLISHED", {
                                    {"APP_CLOSE",        "FIN_WAIT_1"},
                                    {"RCV_FIN",         "CLOSE_WAIT"}
                            }},
            {"FIN_WAIT_1",  {
                                    {"RCV_FIN",          "CLOSING"},
                                    {"RCV_FIN_ACK",     "TIME_WAIT"},
                                    {"RCV_ACK",   "FIN_WAIT_2"}
                            }},
            {"CLOSING",     {
                                    {"RCV_ACK",          "TIME_WAIT"}
                            }},
            {"FIN_WAIT_2",  {
                                    {"RCV_FIN",          "TIME_WAIT"}
                            }},
            {"TIME_WAIT",   {
                                    {"APP_TIMEOUT",      "CLOSED"}
                            }},
            {"CLOSE_WAIT",  {
                                    {"APP_CLOSE",        "LAST_ACK"}
                            }},
            {"LAST_ACK",    {
                                    {"RCV_ACK",          "CLOSED"}
                            }},
    };

    return accumulate(events.cbegin(), events.cend(), std::string{"CLOSED"},
                      [&](const std::string &currentState, const std::string &event)-> std::string {
                          return tcpMap.count(currentState) && tcpMap[currentState].count(event)
                                 ? tcpMap[currentState][event] : "ERROR";
                      });
}

int main() {

    std::cout << traverse_TCP_states({"APP_ACTIVE_OPEN", "RCV_SYN_ACK", "RCV_FIN"}) << "\tCLOSE_WAIT" << std::endl;
    std::cout << traverse_TCP_states({"APP_PASSIVE_OPEN", "RCV_SYN", "RCV_ACK"}) << "\tESTABLISHED" << std::endl;
    std::cout << traverse_TCP_states({"APP_ACTIVE_OPEN", "RCV_SYN_ACK", "RCV_FIN", "APP_CLOSE"}) << "\tLAST_ACK"
              << std::endl;
    std::cout << traverse_TCP_states({"APP_ACTIVE_OPEN"}) << "\tSYN_SENT" << std::endl;
    std::cout << traverse_TCP_states({"APP_PASSIVE_OPEN", "RCV_SYN", "RCV_ACK", "APP_CLOSE", "APP_SEND"}) << "\tERROR"
              << std::endl;

    return 0;
}
