#include <iostream>
#include "beings.h"
using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    Warrior w1("Bob");
    Armor a1("a1",1,1,1);
    Armor a2("a2",2,2,2);
    Armor a3("a3",3,3,3);
    w1.addToInventory(&a1);
    w1.addToInventory(&a2);
    w1.addToInventory(&a3);
    w1.printInventory();
    return 0;
}
