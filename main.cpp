// *********************************************************
// Course: TCP1101 PROGRAMMING FUNDAMENTALS
// Year: Trimester 1, 2022/23 (T2215)
// Lab: TT7L
// Names: AL_Arshad_Bin_Al_Hanisham | MEMBER_NAME_2 | MEMBER_NAME_3
// IDs: MEMBER_ID_1 | MEMBER_ID_2 | MEMBER_ID_3
// Emails: arshadhanisham@gmail.com| MEMBER_EMAIL_2 | MEMBER_EMAIL_3
// Phones: 0164202003 | MEMBER_PHONE_2 | MEMBER_PHONE_3
// *********************************************************

// TODO: Fill in the missing information above and delete this line.

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
        cout << " 2) customize Game Settings " << endl;
        cout << " 3) Exit Game" << endl;
        cout << "=*=*=*=*=*=*=*=*=*=*=*=*" << endl;
        cout << "    BE PREPARED!!!      " << endl;
        cout << "=*=*=*=*=*=*=*=*=*=*=*=*" << endl
             << endl;
        cout << " choose your fate =>";
        cin >> decision;
        switch (decision)
        {

        case 0:
        {
            int numX, numY;
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
            generateZombies(numX, numY, grid);

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
                    displayAlienStatus();

                    displayZombieStatus(zombies);
                }
                // displayBoard(numX, numY, grid);
                // resetGrid(grid,currentX, currentY);

                moveCharacter(grid, currentX, currentY);
                cout << "Press any key to continue... " << endl;
                _getch();

                system("cls");
            }

            // return 0;
            break;
        }

        case 1:
        {
            cout << " Please wait for game to Load \n";
            break;
        }

        case 2:
        {
            cout << " How would you like to play\n ";
            break;
        }
        case 3:
        {
            cout << " Press 1 to confirm exit of the game \n";
            break;
        }
        }
        break;
    }

    while (decision != 3);
}

int main()
{

    int currentX, currentY;
    string moveDirection;

    bool playing = true;
    
    while (true)
    {
        Menu();
        if (game_generated)
        {
            break;
        }
    }

    while (playing)
    {

        if (moveDirection == "quit")
        {
            playing = false;
            std::cout << "Thanks for playing!" << std::endl;
            Menu();
        }
    }

    return 0;

    // cout << "Assignment (Part 1)" << endl;
    // cout << "Let's Get Started!" << endl;
    // pf::Pause();
}
