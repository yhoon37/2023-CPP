#ifndef UNTITLED_GANGPLANKSKILL_H
#define UNTITLED_GANGPLANKSKILL_H
#include "Skill.h"
#include <iostream>

class GangplankSkill : public Skill{
public:
    GangplankSkill():Skill(){}
    ~GangplankSkill(){}
    void q(){std::cout << "TRIAL BY FIRE (불의 심판)" << std::endl;}
    void w(){std::cout << "PARRRLEY (혀어어어업상)" << std::endl;}
    void e(){std::cout << "REMOVE SCURVY (괴혈병 치료)" << std::endl;}
    void r(){std::cout << "POWDER KEG (화약통)" << std::endl;}
private:
};


#endif //UNTITLED_GANGPLANKSKILL_H
