//
// Created by tiferka on 18.08.24.
//

#include "Socket.h"

[[maybe_unused]] const std::string &Socket::getIp() const {
    return IP;
}

[[maybe_unused]] int Socket::getPort() const {
    return PORT;
}

[[maybe_unused]] Socket &Socket::setIp(const std::string &ip0) {
    Socket::IP = ip0;
    return *this;
}

[[maybe_unused]] Socket &Socket::setPort(int port) {
    PORT = port;
    return *this;
}

[[maybe_unused]] Socket::Socket(const std::string &ip, int port) : IP(ip), PORT(port) {}

int Socket::sendData(std::string &data) {
    const char *buffer = (data.c_str());

    ssize_t code = send(sock, buffer, strlen(buffer), 0);
    if (code == -1) {
        if (errno == EPIPE) return EPIPE;
    }
    return 0;
}

int Socket::createConnection() {
    // Создание сокета
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        throw std::runtime_error("Socket creation error");
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        throw std::runtime_error("Invalid address/ Address not supported");
    }

    // Подключение к серверу
    if (connect(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        throw std::runtime_error("Connection Failed");
    }
    return 0;
}


std::string Socket::readData() {
    return std::string();
}

int Socket::makeConnect() {
    auto start = std::chrono::system_clock::now();
    std::chrono::duration<double> seconds = start - start;
    while (seconds.count() < SECOND_TO_EXIT) {
        try {
            createConnection();
            return 0;
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
            std::cerr << "Programme will be finished after: " << std::round(SECOND_TO_EXIT - seconds.count())
                      << " seconds"
                      << std::endl;
        }
        std::this_thread::sleep_for(std::chrono::seconds(5));
        seconds = std::chrono::system_clock::now() - start;
    }
    return -1;
}
