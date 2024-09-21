//
// Created by tiferka on 18.08.24.
//

#ifndef INFOTECS_SOCKET_H
#define INFOTECS_SOCKET_H

#include "../Connector.h"
#include <iostream>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

/**
 * Класс через который мы отправляем и получаем данные, работает через сокеты
 */

class Socket : public Connector {
private:
    std::string IP = "127.0.0.1";
    int PORT = 6666;
    struct sockaddr_in address{};
    int addr_len = sizeof(address);
    int server_fd = 0; ///< Дескриптор сервера
    int new_socket = 0; ///< Дескриптор клиента
public:

    Socket() = default;

    [[maybe_unused]] explicit Socket(std::string ip, int port = 8080);

    ///Создает соединение
    int createConnection();

    ///Содержит метод createConnection(), но обработанный, то есть можно сделать переподключение
    int makeConnect() override;

    /// Отправяет данные
    /// \param [in] data - данные на отправку
    int sendData(std::string &data) override;

    /// Прочитать данные
    std::string readData() override;

    ~Socket() override {
        close(server_fd);
        close(new_socket);
    }

    [[maybe_unused]] [[nodiscard]] const std::string &getIp() const;

    [[maybe_unused]] [[nodiscard]] int getPort() const;

    [[maybe_unused]] Socket &setIp(const std::string &ip);

    [[maybe_unused]] Socket &setPort(int port);
};


#endif //INFOTECS_SOCKET_H
