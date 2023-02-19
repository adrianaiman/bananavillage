// *********************************************************
// Course: TCP1101 PROGRAMMING FUNDAMENTALS
// Year: Trimester 1, 2022/23 (T2215)
// Lab: TT7L
// Names: AL_Arshad_Bin_Al_Hanisham | Adriana_Iman_binti_Noor_Azrai | Sofea_Hazreena_binti_Hasdi
// IDs: 1211103123 | 1211103196 | 1211103216
// Emails: 1211103123@student.mmu.edu.my| 1211103196@student.mmu.edu.my | 1211103216@student.mmu.edu.my
// Phones: 0164202003 | 01110241210 | 0193287357
// *********************************************************

#include "case0.h"
#include <iostream>
#include <string>

vector<vector<char>> grid;

using namespace std;

bool game_generated = false;

void Menu()
{

    // main function
    int decision;
    do
    {
        cout << "=*=*=*=*=*=*=*=*=*=*=*=*" << endl;
        cout << "   Alien vs Zombie      " << endl;
        cout << "=*=*=*=*=*=*=*=*=*=*=*=*" << endl;
        cout << " 0) New Game" << endl;
        cout << " 1) Load Game  " << endl;
        cout << " 2) Exit Game" << endl;
        cout << "=*=*=*=*=*=*=*=*=*=*=*=*" << endl;
        cout << "    BE PREPARED!!!      " << endl;
        cout << "=*=*=*=*=*=*=*=*=*=*=*=*" << endl
             << endl;
        cout << " choose your fate =>";
        cin >> decision;
        cout << "press any key to continue... " << endl;
        _getch();

        system("cls");
        switch (decision)
        {

        case 0:
        {
            srand(time(NULL));
            int numX, numY;
            int Z_health = 50;
            int Z_attack_range = (rand() % 5) + 1;         // random value between 1-5
            const int Z_attack_damage = (rand() % 10) + 5; // random value between 5-15

            int A_health = rand() % 101 + 100;
            ;
            int A_attack_damage = 10;
            int A_attack_range = 1;
            std::string player;
            vector<vector<char>> grid;
            // welcome void
            welcome();
            cout << "                         ARE YOU READY? " << endl;
            cout << "                press any key if you are ready" << endl;
            _getch();
            system("cls");

            // board
            generateBoard(numX, numY, grid);
            if (numX % 2 == 1 && numY % 2 == 1)
            {
                generateInpluto(numX, numY, grid);
            }
            int currentX = (numX - 1) / 2;
            int currentY = (numY - 1) / 2;
            generateZombies(numX, numY, grid, zombieCoordinates);

            cout << " " << endl;
            cout << "Settings is updated" << endl;
            cout << "Number of rows=>" << numX << endl;
            cout << "Number of columns=>" << numY << endl;
            cout << "Number of zombies=>" << zombies << endl;
            cout << " " << endl;
            cout << "Press any key to continue... " << endl;
            _getch();
            system("cls");

            while (true)
            {
                if (zombies > 0 && zombies < 10)
                {
                    displayBoard(numX, numY, grid);

                    displayAlienStatus(A_health, A_attack_damage, A_attack_range);
                    displayZombieStatus(zombies, Z_health, Z_attack_damage, Z_attack_range);
                }

                moveCharacter(grid, currentX, currentY, A_health, Z_health, Z_attack_damage, A_attack_damage, player, zombieCoordinates, A_attack_range);
                _getch();
                for (int i = 0; i < zombies; i++)
                {
                    moveZombies(numX, numY, grid, zombieCoordinates, Z_attack_range, A_health, Z_attack_damage, currentX, currentY);
                }

                cout << "press any key to continue... " << endl;
                _getch();

                system("cls");
                gameOver(A_health, Z_health);
                
            }
            //return 0;
            break;
        }

        case 1:
        {
            cout << " Please wait for game to Load \n";
            break;
        }

        case 2:
        {
            cout << "Are you sure?" << endl;
            cout << "(yes/no)" << endl;
            string ans;
            cin >> ans;
            if (ans == "yes")
            {
                cout << "Thanks for playing!" << endl;
                getch();
                exit(0);
            }
            else if (ans == "no")
            {
                cout << "Press any key to continue... " << endl;
                _getch();
                system("cls");
                return;
            }
            else
                cout << "Invalid! Please state (yes/no) only" << endl;
            return;
            break;
        }
        }
        break;
    }

    while (decision != 0, 1, 2);
    cout << "Invalid! Please state (0,1,2) only" << endl;
}

int main()
{

    int currentX, currentY;
    string moveDirection;

    while (true)
    {
        Menu();
    }
    return 0;
}
