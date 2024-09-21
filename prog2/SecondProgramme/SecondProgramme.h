//
// Created by tiferka on 16.08.24.
//

#ifndef INFOTECSPROG2_SECONDPROGRAMME_H
#define INFOTECSPROG2_SECONDPROGRAMME_H

#include "Analyzer/DefaultAnalizer.h"
#include "Socket/Socket.h"


///Основной класс программы, связывающий всю работу других классов
class SecondProgramme {
private:
    Analyzer *analyzer;
    Connector *connector;///< Конектор для подключения к другому приложению
public:

    ///Запуск программы
    int startProgramme();

    SecondProgramme() {
        analyzer = new DefaultAnalizer();
        connector = new Socket();
    }

    [[maybe_unused]] explicit SecondProgramme(Analyzer *analyzer, Connector *newCon = new Socket()) : analyzer(analyzer),
                                                                                     connector(newCon) {}

    [[maybe_unused]] [[nodiscard]] Analyzer *getAnalyzer() const;

    [[maybe_unused]] SecondProgramme &setAnalyzer(Analyzer *pAnalyzer);


    [[maybe_unused]] [[nodiscard]] Connector *getConnector() const;


    ~SecondProgramme() {
        delete analyzer;
        delete connector;
    }
};


#endif //INFOTECSPROG2_SECONDPROGRAMME_H
