//
// Created by tiferka on 16.08.24.
//

#include "ProcessStream.h"

std::string ProcessStream::process(std::string &line) {
    if (line[0] == EXIT) throw std::runtime_error("Exit from programme");
    if (line.size() > 64) throw MyInvalidArgumentLen("Invalid size of line\n");
    for (char c: line) {
        if (!std::isdigit(c)) throw MyInvalidArgumentDigit("Invalid: the string must contain only numbers");
    }
    std::sort(line.begin(), line.end());
    std::string ans;
    for (char ch: line) {
        if ((ch - '0') % 2 == 0) ans += "КВ";
        else ans += ch;
    }

    return ans;
}
