//
// Created by tiferka on 16.08.24.
//

#include "SecondProgramme.h"

int SecondProgramme::startProgramme() {
    std::string data;
    connector->makeConnect();
    while (true) {
        try {
            data = connector->readData();
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
            std::cout << "try make reconnection" << std::endl;
            delete connector;
            connector = new Socket();
            connector->makeConnect();
            continue;
        }
        if (data[0] == '#') break;
        std::cout << data << std::endl;
        std::cout << analyzer->analyze(data) << std::endl;
    }
    return 0;
}

[[maybe_unused]] Connector *SecondProgramme::getConnector() const {
    return connector;
}

[[maybe_unused]] SecondProgramme &SecondProgramme::setAnalyzer(Analyzer *pAnalyzer) {
    SecondProgramme::analyzer = pAnalyzer;
    return *this;
}

[[maybe_unused]] Analyzer *SecondProgramme::getAnalyzer() const {
    return analyzer;
}

