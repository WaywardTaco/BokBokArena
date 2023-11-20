
#include "BokBok.cpp"

class RoastBokBok : public BokBok {

public:
    using BokBok::BokBok;

    RoastBokBok(  string param_name,
                    int param_hp,
                    int param_atk,
                    int param_def,
                    int param_spd)
        : BokBok(param_name, param_hp, param_atk, param_def, param_spd){
        this->type = "Roast BokBok";

        addSkill(new Skill("Quick Roast"));
        addSkill(new Skill("Skewer", 3));
        addSkill(new Skill("Charcoal Spin", -2));
    };
};