/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector> 

using namespace std;

class Character {
    float Health;
    float Damage;
    float Defend;
    
  
public:     
    
    void setHealth(float Health)
    {
        this->Health = Health;
    }
    
    void setDamage(float Damage)
    {
        this->Damage = Damage;
    }
    
    void setDefend(float Defend)
    {
        this->Defend = Defend;
    }
    
    void takeDamage(float Damage) {
    Health -= Damage;
    if (Health < 0)
       {
        Health = 0;
       }
    }
    
    float getHealth()
    {
        return this->Health;
    }
    
    float getDamage()
    {
        return this->Damage;
    }
    
    float getDefend()
    {
        return this->Defend;
    }
    
};

class Combat {
    
    vector <string> result;
    vector <string> actions;

public:
    
    void setFight(Character human, Character monstr)
{
       int round = 1;
       int maxRounds = 3;
        while (human.getHealth() > 0 && monstr.getHealth() > 0 && round <= maxRounds) {
        // Ходит первый игрок
        int attack1 = human.getDamage();
        int defend2 = monstr.getDefend();
        int damage1 = attack1 - defend2;
        if (damage1 > 0) {
            monstr.takeDamage(damage1);
            actions.push_back("Игрок 1 атакует Игрока 2  " + to_string(damage1) + " урон.");
            result.push_back("Игрок 2 проиграл " + to_string(damage1) + " здоровье.");
        } else {
            actions.push_back("Игрок 1 атакует Игрока 2, но это не имеет никакого эффекта.");
            result.push_back("");
        }
        
        int attack2 = monstr.getDamage();
        int defend1 = human.getDefend();
        int damage2 = attack2 - defend1;
        
        if(damage2 > 0) {
            
            human.takeDamage(damage2);
            actions.push_back("Игрок 2 атакует Игрока 1" + to_string(damage2) + " урон.");
            result.push_back("Игрок 1 проиграл " + to_string(damage2) + " здоровье.");
        } else {
            actions.push_back("Игрок 2 атакует Игрока 1, но это не имеет никакого эффекта.");
            result.push_back("");
        }
        round++;
    }
    
    if (human.getHealth() > monstr.getHealth()) {
        actions.push_back("Игрок 1 выйграл!");
        result.push_back("");
    } else if (monstr.getHealth() > human.getHealth()) {
        actions.push_back("Игрок 2 выйграл!");
        result.push_back("");
    } else {
        actions.push_back("Ничья!");
        result.push_back("");
    }
}    
    void getResults() {
        // Вывод результатов боя
        for (int i = 0; i < actions.size(); i++) {
            cout << result[i] << endl;
            cout << actions[i] << endl;
        }
    }
};

int main()
{
    Character human;
    
    human.setHealth(100);
    human.setDamage(65.5);
    human.setDefend(7);
    
    Character monstr;
    
    monstr.setHealth(200);
    monstr.setDamage(25);
    monstr.setDefend(15);
    
    
    return 0;
}

