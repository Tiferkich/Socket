//
// Created by tiferka on 16.08.24.
//


#ifndef INFOTECS_ACCEPTEDSTREAM_H
#define INFOTECS_ACCEPTEDSTREAM_H
#include "Stream.h"

class AcceptedStream : public Stream {
public:
    /**
     *Поток должен вывести полученные данные на экран, рассчитать общую сумму всех элементов ,
     *которые являются численными значениями.
     *Полученную сумму передать в Программу №2.
     *После этого поток ожидает следующие данные.
     */
    std::string process(std::string &string) override;

};


#endif //INFOTECS_ACCEPTEDSTREAM_H
