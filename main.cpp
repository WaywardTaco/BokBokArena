
#include <vector>

#include "BokBok.cpp"
#include "BraisedBokBok.cpp"
#include "FriedBokBok.cpp"
#include "RoastBokBok.cpp"

using namespace std;

int main()
{
    vector<BokBok*> chickens;

    chickens.push_back(new FriedBokBok("Santana", 10, 90, 10, 10));
    chickens.push_back(new BraisedBokBok("Wolfey", 90, 10, 10, 10));
    chickens.push_back(new RoastBokBok("Chickie", 10, 10, 90, 10));

    for(int i = 0; i < chickens.size(); i++)
        chickens[i]->displayStats();
    
    int choice;

    while(true){

        cout << "Choose your BokBok!" << endl;
        for(int i = 0; i < chickens.size(); i++)
            cout << "[" << i + 1 << "] " << chickens[i]->getName() << " (" << chickens[i]->getType() << ")" << endl;

        cout << "Choice: "; cin >> choice;

        if(choice > 0 && choice <= chickens.size())
            break;
        
        cout << "Error! Pick another Bok!" << endl;

    }

    BokBok* yourBok = chickens[choice - 1];

    cout << "You chose " << yourBok->getName() << "!" << endl;

    while(true){
        cout << "Choose your BokBok Bad Guy!" << endl;
        for(int i = 0; i < chickens.size(); i++)
            if(i + 1 != choice)
                cout << "[" << i + 1 << "] " << chickens[i]->getName() << " (" << chickens[i]->getType() << ")" << endl;

        cout << "Choice: "; cin >> choice;

        if(chickens[choice - 1] != yourBok)
            break;
        
        cout << "Error! Please choose a different Bok!" << endl;
    }

    BokBok* opponent = chickens[choice - 1];

    while(yourBok->getHP() > 0 && opponent->getHP() > 0){
        
        while(true){
            cout << "Choose a move!" << endl;
            for(int i = 0; i < yourBok->getSkillCount(); i++)
                cout << "[" << i + 1 << "] " << yourBok->getSkill(i + 1)->getName() << endl;

            cout << "Choice: "; cin >> choice;

            if(choice > 0 && choice <= yourBok->getSkillCount())
                break;

            cout << "Error! Please choose something else!" << endl;
        }

        int opponentAtk = rand() % opponent->getSkillCount() + 1;

        if(yourBok->getSPD() >= opponent->getSPD()){
            yourBok->attackUsing(opponent, *(yourBok->getSkill(choice)));
            opponent->attackUsing(yourBok, *(opponent->getSkill(opponentAtk)));
        } else {
            opponent->attackUsing(yourBok, *(opponent->getSkill(opponentAtk)));
            yourBok->attackUsing(opponent, *(yourBok->getSkill(choice)));
        }
    }

    if(yourBok->getHP() > 0)
        cout << "Your " << yourBok->getName() << " won!" << endl;
    else
        cout << "You lost to the opposing " << opponent->getName() << "!" << endl;

    return 0;

}