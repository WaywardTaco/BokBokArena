
#include <iostream>

using namespace std;

class Skill {

private:
    string name;
    int power = 0;

public:
    Skill(string skillName){
        this->name = skillName;
    }

    Skill(string skillName, int PWR){
        this->name = skillName;
        this->power = PWR;
    }

    string getName(){
        return name;
    }

    int getPWR(){
        return power;
    }
};

