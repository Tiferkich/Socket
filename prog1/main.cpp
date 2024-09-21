#include "FirstProgramme/FirstProgramme.h"
#include <csignal>

void sigpipe_handler(int signum) {
    std::cerr << "Получен сигнал SIGPIPE" << std::endl;
}

int main() {
    signal(SIGPIPE, sigpipe_handler);
    FirstProgramme firstProgramme;
    firstProgramme.startProgramme();
    return 0;
}
