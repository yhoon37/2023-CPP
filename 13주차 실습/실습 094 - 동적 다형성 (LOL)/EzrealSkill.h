#ifndef UNTITLED_EZREALSKILL_H
#define UNTITLED_EZREALSKILL_H
#include "Skill.h"
#include <iostream>

class EzrealSkill : public Skill{
public:
    EzrealSkill():Skill(){}
    ~EzrealSkill(){}
    void q(){std::cout << "RISING SPELL FORCE (끓어오르는 주문의 힘)" << std::endl;}
    void w(){std::cout << "MYSTIC SHOT (신비한 화살)" << std::endl;}
    void e(){std::cout << "ESSENCE FLUX (정수의 흐름)" << std::endl;}
    void r(){std::cout << "ARCANE SHIFT (비전 이동)" << std::endl;}
private:

};


#endif //UNTITLED_EZREALSKILL_H
