
#include "BokBok.cpp"

class BraisedBokBok : public BokBok {

public:
    using BokBok::BokBok;

    BraisedBokBok(  string param_name,
                    int param_hp,
                    int param_atk,
                    int param_def,
                    int param_spd) 
        : BokBok(param_name, param_hp, param_atk, param_def, param_spd){
        this->type = "Braised BokBok";

        addSkill(new Skill("Vacuum Seal", -2));
        addSkill(new Skill("Slow Burn", 0));
        addSkill(new Skill("Browning", 2));
    };
};