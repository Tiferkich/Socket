//
// Created by tiferka on 18.08.24.
//

#ifndef INFOTECS_SOCKET_H
#define INFOTECS_SOCKET_H

#include <iostream>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "../Connector.h"


/**
 * Класс через который мы отправляем и получаем данные, работает через сокеты
 */
class Socket : public Connector {
private:
    std::string IP = "127.0.0.1";
    int PORT = 6666;
    struct sockaddr_in serv_addr{};
    int sock = 0; ///< Дескриптор сокета
public:

    Socket() = default;

    [[maybe_unused]] explicit Socket(const std::string &ip, int port = 8080);

    ///Создает соединение
    int createConnection();

    /// Отправяет данные
    /// \param [in] data - данные на отправку
    int sendData(std::string &data) override;

    std::string readData() override;

    ~Socket() override {
        close(sock);
    }
    ///Содержит метод createConnection(), но обработанный, то есть можно сделать переподключение,
    /// при прохождении какого то времени выбрасывается код ошибки
    int makeConnect() override;

    [[maybe_unused]] [[nodiscard]] const std::string &getIp() const;

    [[maybe_unused]] [[nodiscard]] int getPort() const;

    [[maybe_unused]] Socket &setIp(const std::string &ip);

    [[maybe_unused]] Socket &setPort(int port);
};


#endif //INFOTECS_SOCKET_H
