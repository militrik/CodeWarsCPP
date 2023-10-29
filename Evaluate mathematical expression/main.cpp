#include <iostream>

#include <string>
#include <regex>
#include <iomanip>

#define number (?:-?\d+(?:\.\d+)?)


std::string to_precised_string(double res, int i) {
    std::stringstream ss;
    ss << std::fixed << std::setprecision(i) << res;
    std::cout << ss.str() << std::endl;
    return ss.str();
}

double calc(std::string expression) {
    expression.erase(std::remove_if(expression.begin(), expression.end(), isspace), expression.end());
    std::cout << expression << std::endl;
    std::smatch match;
    std::regex pattern;
    // parentheses
    pattern = std::regex(R"((.*?)\(([^\(\)]+)\)(.*))");
    if (std::regex_search(expression, match, pattern)) {
        //std::cout << match[2].str() << std::endl;
        double res = calc(match[2].str());
        //std::cout << res << std::endl;
        expression = match[1].str() + to_precised_string(res, 18) + match[3].str();
        double r = calc(expression);
        return r;
    }
    // signs
    pattern = std::regex(R"((.*?)([\+\-]{2,})(.*))");
    if (std::regex_search(expression, match, pattern)) {
        std::string str = match[2].str();
        char currentSign = '+';
        for (char c: str) {
            if (c == '-')
                currentSign = currentSign == '+' ? '-' : '+';
        }
        expression = match[1].str() + currentSign + match[3].str();
        std::cout << expression << std::endl;
        double r = calc(expression);
        //std::cout << r << std::endl;
        return r;
    }
    // mul div
    pattern = std::regex(R"((.*?)((?:\d+(?:\.\d+)?))([\*|\/])((?:[\+\-]?\d+(?:\.\d+)?))(.*))");
    if (std::regex_search(expression, match, pattern)) {
        std::cout << stod(match[2].str()) << "\t" << stod(match[4].str()) << std::endl;
        double res = match[3].str() == "*" ? stod(match[2].str()) * stod(match[4].str()) : stod(match[2].str()) /
                                                                                           stod(match[4].str());
        std::string str = match[1].str() + to_precised_string(res, 18) + match[5].str();
        double r = calc(str);
        //std::cout << r << std::endl;
        return r;
    }
    // sum sub
    pattern = std::regex(R"((.*?)((?:-?\d+(?:\.\d+)?))([\+|\-])((?:-?\d+(?:\.\d+)?))(.*))");
    if (std::regex_search(expression, match, pattern)) {
        double res = match[3].str() == "+" ? stod(match[2].str()) + stod(match[4].str()) : stod(match[2].str()) -
                                                                                           stod(match[4].str());
        std::string str = match[1].str() + to_precised_string(res, 18) + match[5].str();
        double r = calc(str);
        //std::cout << r << std::endl;
        return r;
    }
    // nothing
    std::cout << "Final number : " << expression << std::endl;
    return std::stod(expression);
}


int main() {
    std::cout << calc("(-69)+(89*49--(4))*(-38/-((((-67+64))))-78)") << std::endl;
    std::cout << calc("85+-70/46/74/-24-90*71--7") << std::endl;
    std::cout << calc("( --(- -( - -10   ) ) ) ") << std::endl;
    std::cout << calc("-29--98-47/88*-38/-41+86-4") << std::endl;
    std::cout << calc("-(58) + (45 * 65 - (59)) - (88 - -(((-(-89 + -57)))) - 84)") << std::endl;
    std::cout << calc("--9.000000000000000000 + 147312.000000000000000000") << std::endl;
    std::cout << calc("-1") << std::endl;
    std::cout << calc("-(-1)") << std::endl;
    std::cout << calc("-1") << std::endl;
    std::cout << calc("2 + 3 * 4 / 3 - 6 / 3 * 3 + 8") << std::endl;
    std::cout << calc("(1 + 1)") << std::endl;
    std::cout << calc("1 + 1") << std::endl;
    std::cout << calc("8/16") << std::endl;
    std::cout << calc("3 -(-1)") << std::endl;
    std::cout << calc("2 + -2") << std::endl;
    std::cout << calc("10- 2- -5") << std::endl;
    std::cout << calc("(((10)))") << std::endl;
    std::cout << calc("3 * 5") << std::endl;
    std::cout << calc("7 * -(6 / 3)") << std::endl;
    std::cout << calc("42 * -43 * -71 * 10 * 37 - 62 / -18 * -43") << std::endl;
    std::cout << calc("-48 / 71 + -62 - -71 / -81 / 49 * -20 - -70") << std::endl;
    std::cout << calc("-71 / (78 / (-55 - -46)) * (-27 / -((((-71 - -85)))) + 92)") << std::endl;
    std::cout << calc("-(71) / (78 / -55 - -(46)) * (-27 / -((((-71 - -85)))) + 92)") << std::endl;
    return 0;
}
