//
// Created by tiferka on 18.08.24.
//

#include "Socket.h"

#include <utility>

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

[[maybe_unused]] Socket::Socket(std::string ip, int port) : IP(std::move(ip)), PORT(port) {}

int Socket::sendData(std::string &data) {
    const char *buffer = (data.c_str());
    send(new_socket, buffer, strlen(buffer), 0);
    delete buffer;
    return 0;
}

int Socket::createConnection() {
    // Создание сокета
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        throw std::runtime_error("socket failed");
    }

    // Настройка адреса
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);


    // Привязка сокета к порту
    if (bind(server_fd, (struct sockaddr *) &address, sizeof(address)) < 0) {
        close(server_fd);
        throw std::runtime_error("bind failed");
    }

    // Прослушивание портов
    if (listen(server_fd, 3) < 0) {
        close(server_fd);
        throw std::runtime_error("listen failed");
    }

    std::cout << "Server is listening on port " << PORT << std::endl;
    // Принятие входящего соединения
    if ((new_socket = accept(server_fd, (struct sockaddr *) &address, (socklen_t *) &addr_len)) < 0) {
        perror("accept failed");
        close(server_fd);
        throw std::runtime_error("Can`t get connection");
    }
    std::cout << "Connection established" << std::endl;
    return 0;
}


std::string Socket::readData() {
    char buffer[8] = {0};
    if (read(new_socket, buffer, 8) == 0) {
        throw std::runtime_error("Error connection");
    }
    std::string data(buffer);
    return data;
}

int Socket::makeConnect() {


    try {
        createConnection();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return -1;
    }
    return 0;
}
