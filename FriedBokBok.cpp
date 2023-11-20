
#include "BokBok.cpp"

class FriedBokBok : public BokBok{

public:
    using BokBok::BokBok;

    FriedBokBok (  string param_name,
                    int param_hp,
                    int param_atk,
                    int param_def,
                    int param_spd)
        : BokBok(param_name, param_hp, param_atk, param_def, param_spd){
        this->type = "Fried BokBok";

        addSkill(new Skill("Food Poisoning", -3));
        addSkill(new Skill("Inflict Acne"));
        addSkill(new Skill("Scorched Oil", 5));
    };
};