#include <iostream>
#include <cstdlib> // rand(), srand()
#include "GameManager.h"


int main()
{
    GameManager GM; //인스턴스 생성
    srand(0);

    while (true)
    {
        cout << "1. 전투" << endl;
        cout << "2. 상점" << endl;

        int choice = 0;
        cin >> choice;
        cin.ignore();

        if (choice == 1)
        {
            GM.battle();
        }
        else if (choice == 2)
        {
            GM.visitShop();

        }
        break;
    }

    return 0;
};