//
// Created by tiferka on 16.08.24.
//

#include <thread>
#include "FirstProgramme.h"

[[maybe_unused]] const std::string &FirstProgramme::getBuffer() const {
    return buffer;
}

[[maybe_unused]] Stream *FirstProgramme::getAcceptedStream() const {
    return acceptedStream;
}

[[maybe_unused]] Stream *FirstProgramme::getProcessStream() const {
    return processStream;
}

[[maybe_unused]] FirstProgramme &FirstProgramme::setBuffer(const std::string &buffer0) {
    FirstProgramme::buffer = buffer0;
    return *this;
}

[[maybe_unused]] FirstProgramme &FirstProgramme::setAcceptedStream(Stream *acceptedStream0) {
    FirstProgramme::acceptedStream = acceptedStream0;
    return *this;
}

[[maybe_unused]] FirstProgramme &FirstProgramme::setProcessStream(Stream *processStream0) {
    FirstProgramme::processStream = processStream0;
    return *this;
}

std::string FirstProgramme::process() {
    while (true) {
        std::string line;
        while (true) {
            try {
                std::cout << "Write " << EXIT << " to exit programme" << "\nWrite string: ";
                std::getline(std::cin, line);
                buffer = processStream->process(line);
                break;
            } catch (const MyInvalidArgumentLen &e) {
                std::cout << e.what() << std::endl;
            } catch (const MyInvalidArgumentDigit &e) {
                std::cout << e.what() << std::endl;
            } catch (const std::runtime_error &e) {
                throw e;
            }
        }
        return acceptedStream->process(buffer);
    }
}

int FirstProgramme::startProgramme() {
    std::string data;
    if (connector->makeConnect() == -1) return EXIT_NOT_CONNECTED;
    while (true) {
        try {
            data = process();
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
            data = "#";
            connector->sendData(data);
            return EXIT_CODE;
        }

        if (connector->sendData(data) == EPIPE) {
            if (connector->makeConnect() == -1) return EXIT_NOT_CONNECTED;
            connector->sendData(data);
        }
        std::cout << data << std::endl;
    }

}

[[maybe_unused]] FirstProgramme::FirstProgramme(Stream *acceptedStream, Stream *processStream) : acceptedStream(
        acceptedStream),
                                                                                                 processStream(
                                                                                                         processStream) {}

FirstProgramme::FirstProgramme() {
    connector = new Socket();
    acceptedStream = new AcceptedStream();
    processStream = new ProcessStream();
}

[[maybe_unused]] Connector *FirstProgramme::getConnector() const {
    return connector;
}

[[maybe_unused]] FirstProgramme &FirstProgramme::setConnector(Connector *connector0) {
    FirstProgramme::connector = connector0;
    return *this;
}


