//
// Created by tiferka on 18.08.24.
//

#ifndef INFOTECSPROG2_CONNECTOR_H
#define INFOTECSPROG2_CONNECTOR_H

#include <string>
#include <chrono>
#include <cmath>
#include <thread>
#define SECOND_TO_EXIT 30

/**
 * Интерфейс нужный для передачи данных, каким либо способом
 */
class Connector {
public:
    [[maybe_unused]] virtual std::string readData() = 0;

    virtual int sendData(std::string &data) = 0;

    virtual int makeConnect() = 0;

    virtual ~Connector() = default;
};


#endif //INFOTECSPROG2_CONNECTOR_H
