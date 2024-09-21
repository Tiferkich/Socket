//
// Created by tiferka on 16.08.24.
//

#ifndef INFOTECS_FIRSTPROGRAMME_H
#define INFOTECS_FIRSTPROGRAMME_H

#include "Streams/ProcessStream.h"
#include "Streams/AcceptedStream.h"
#include "Connector.h"
#include "Socket/Socket.h"
#include <chrono>
#include <cmath>

#define EXIT_CODE 1
#define EXIT_NOT_CONNECTED (-1)
#define SECOND_TO_EXIT 30
///Основной класс программы, связывающий всю работу других классов
class FirstProgramme {

private:
    std::string buffer; ///< Буффер для потоков
    Stream *processStream;///< Первый поток
    Stream *acceptedStream; ///< Второй поток
    Connector *connector; ///< Конектор для подключения к другому приложению
public:

    ///Запуск программы
    int startProgramme();
    ///Один из процессов программы
    std::string process();

    FirstProgramme();

    [[maybe_unused]] FirstProgramme(Stream *acceptedStream, Stream *processStream);


    [[maybe_unused]] [[nodiscard]] const std::string &getBuffer() const;

    [[maybe_unused]] [[nodiscard]] Stream *getAcceptedStream() const;

    [[maybe_unused]] [[nodiscard]] Stream *getProcessStream() const;

    [[maybe_unused]] FirstProgramme &setBuffer(const std::string &buffer);

    [[maybe_unused]] FirstProgramme &setAcceptedStream(Stream *acceptedStream);

    [[maybe_unused]] FirstProgramme &setProcessStream(Stream *processStream);

    ~FirstProgramme() {
        delete acceptedStream;
        delete processStream;
        delete connector;
    }

    [[maybe_unused]] [[nodiscard]] Connector *getConnector() const;

    [[maybe_unused]] FirstProgramme &setConnector(Connector *connector);
};


#endif //INFOTECS_FIRSTPROGRAMME_H
