//
// Created by tiferka on 16.08.24.
//


#ifndef INFOTECS_PROCESSSTREAM_H
#define INFOTECS_PROCESSSTREAM_H

#include <cctype>
#include <algorithm>

#define EXIT '#'
#include "Stream.h"

class ProcessStream : public Stream {
public:
    /**Принимает строку, которую введет пользователь.
     * Должна быть проверка, что строка состоит только из цифр и не превышает 64 символа.
     * После проверки строка должна быть отсортирована по убыванию
     * и все элементы, значение которых чётно, заменены на латинские буквы «КВ»
     */
    std::string process(std::string &string) override;
};


///Класс ошибки, который выбрасывается если строка больше 64 символов
class MyInvalidArgumentLen : public std::invalid_argument {
public:
    // Конструктор, принимающий строковое сообщение
    [[maybe_unused]] explicit MyInvalidArgumentLen(const std::string &message)
            : std::invalid_argument(message) {}

    // Конструктор, принимающий C-строку
    explicit MyInvalidArgumentLen(const char *message)
            : std::invalid_argument(message) {}
};
///Класс ошибки, который выбрасывается если строка содержит не те символы
class MyInvalidArgumentDigit : public std::invalid_argument {
public:
    // Конструктор, принимающий строковое сообщение
    [[maybe_unused]] explicit MyInvalidArgumentDigit(const std::string &message)
            : std::invalid_argument(message) {}

    // Конструктор, принимающий C-строку
    explicit MyInvalidArgumentDigit(const char *message)
            : std::invalid_argument(message) {}
};


#endif //INFOTECS_PROCESSSTREAM_H
