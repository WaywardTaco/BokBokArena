
#ifndef BOKBOK
#define BOKBOK

#include <iostream>
#include <vector>
#include "Skill.cpp"

using namespace std;

class BokBok {

//attributes PROTECTED
protected:
    string  name,
            type;
    int max_HP;
    int HP;
    int ATK;
    int DEF;
    int SPD;

    vector<Skill*> skills;

public:
    // CONSTRUCTORS ARE methods that are called WHEN
    // the OBJECT is INSTANTIATED.
    BokBok(){

    };

    BokBok( string param_name,
            int param_hp,
            int param_atk,
            int param_def,
            int param_spd) {
        this->name = param_name;
        this->max_HP = param_hp;
        this->HP = param_hp;
        this->ATK = param_atk;
        this->DEF = param_def;
        this->SPD = param_spd;

        addSkill(new Skill("Kalmot"));
        addSkill(new Skill("Tuka"));
        addSkill(new Skill("Tilaok"));
    }

    //methods PUBLIC

    void displayStats() {
        cout << "BokBok name: " << name << endl;
        cout << "HP: " << HP << endl;
        cout << "ATK: " << ATK << endl;
        cout << "DEF: " << DEF << endl;
        cout << "SPD: " << SPD << endl;
    }

    void attackUsing(BokBok* target, Skill skill){
        if(this->HP <= 0)
            return;

        cout << this->name << " used " << skill.getName() << "!" << endl;
        target->takeDamage(this->ATK + skill.getPWR());
    }

    void takeDamage(int damage) {
        int hurtAmt = damage - this->DEF;

        if(hurtAmt <= 0)
            hurtAmt = 1;

        this->HP -= hurtAmt;
        cout << this->name << " took " << hurtAmt << " damage! " << this->HP << "/" << this->max_HP << "HP" << endl;
    }

    void addSkill(Skill* skill){
        skills.push_back(skill);
    }

    Skill* getSkill(int number){
        return this->skills[number - 1];
    }

    int getSkillCount(){
        return this->skills.size();
    }

    string getName() {
        return name;
    }

    string getType() {
        return type;
    }

    int getSPD() {
        return SPD;
    }

    int getHP(){
        return HP;
    }

};

#endif