//
// Created by tiferka on 16.08.24.
//

#ifndef INFOTECSPROG2_ANALYZER_H
#define INFOTECSPROG2_ANALYZER_H

#define EXIT '#'

#include <iostream>
#include <string>

/**
 * \brief Интерфейс анализатора
 * \details Нужен для расширения функционала, допустим захотим анализировать данные по-другому
 */
class Analyzer {
public:
    virtual std::string analyze(const std::string &data) = 0;

    virtual ~Analyzer() = default;
};


#endif //INFOTECSPROG2_ANALYZER_H
