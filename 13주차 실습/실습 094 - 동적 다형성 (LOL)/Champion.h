#ifndef UNTITLED_CHAMPION_H
#define UNTITLED_CHAMPION_H
#include "GangplankSkill.h"
#include "EzrealSkill.h"
#include <memory>

enum class CHAMPION {GANGPLANK, EZREAL};
class Champion {
public:
    void select_champion(CHAMPION champion){
        switch(champion){
            case CHAMPION::GANGPLANK:
                skill = std::make_unique<GangplankSkill>();
                break;
            case CHAMPION::EZREAL:
                skill = std::make_unique<EzrealSkill>();
        }
    }
    void q() { skill->q(); }
    void w() { skill->w(); }
    void e() { skill->e(); }
    void r() { skill->r(); }
private:
    std::unique_ptr<Skill> skill;
};

#endif //UNTITLED_CHAMPION_H
