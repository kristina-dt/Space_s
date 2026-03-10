#include "include/GameEngine.h"
#include "include/InformationPlayer.h"
#include <iostream>
InformationPlayer createPlayer(){
    std::string name, sex;
    int age;
    std::cout << "Creation of Character\n";
    std::cout << "==================\n\n";
    std::cout << "Write person's name: ";
    std::getline(std::cin, name);
    std::cout << "Write sex: ";
    std::getline(std::cin, sex);
    std::cout << "Write age: ";
    std::cin >> age;
    int startMoney = 1000;
    float startX = 5.0f, startY = 5.0f;
    std::cout << "Initial balance: " << startMoney << " credits\n";
    return InformationPlayer(name, sex, age, startY, startX, startMoney);
}
int main() {
    GameEngine m;
    m.drawOnce();


    return 0;
}
