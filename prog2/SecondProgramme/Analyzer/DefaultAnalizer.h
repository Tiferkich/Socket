//
// Created by tiferka on 16.08.24.
//

#ifndef INFOTECSPROG2_DEFAULTANALIZER_H
#define INFOTECSPROG2_DEFAULTANALIZER_H

#include "Analyzer.h"


class DefaultAnalizer : public Analyzer {

/**
 * \param data - Данные для обработки
 * Если data больше 2-ух символов и если оно кратно 32 выводит сообщение о
 * полученных данных, иначе выводится сообщение об ошибке. Далее программа
 * продолжает ожидать данные.
 */
    std::string analyze(const std::string &data) override;

};


#endif //INFOTECSPROG2_DEFAULTANALIZER_H
