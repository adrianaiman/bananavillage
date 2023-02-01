#ifndef CASE0_H
#define CASE0_H
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <conio.h> // for setw()
#include <cstdlib>
#include <fstream>

using namespace std;

int numX;
int numY;
int zombies;

void welcome()
{
    cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
    cout << "    $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
    cout << "       $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
    cout << "           $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl
         << endl;
    ;
    cout << "         888     88      88    888888   888    88 " << endl;
    cout << "         888     88      88    88       88 88  88 " << endl;
    cout << "        88888    88      88    88888    88  88 88  " << endl;
    cout << "       88   88   88      88    88       88   8888     " << endl;
    cout << "      88     88  888888  88    888888   88    888  VS   " << endl;
    cout << " " << endl;
    cout << "       888888   8888   888   888  88888   88  888888    " << endl;
    cout << "          88   88  88  88 8 8 88  88   8  88  88 " << endl;
    cout << "         88    88  88  88  8  88  88888   88  88888   " << endl;
    cout << "       88      88  88  88     88  88   8  88  88" << endl;
    cout << "       888888   8888   88     88  88888   88  888888" << endl;
    cout << " " << endl;
    cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
    cout << "    $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
    cout << "         $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
    cout << "              $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
    cout << " " << endl;
}
void generateBoard(int &numX, int &numY, vector<vector<char>> &grid)
{
    cout << endl;
    cout << "==============================" << endl;
    cout << "        Board Settings" << endl;
    cout << "==============================" << endl;
    cout << "Please enter odd numbers only" << endl;
    cout << "Enter number of rows=>";
    cin >> numX;

    while (numX % 2 == 0)
    {
        cout << "Invalid! Please enter an odd number" << endl;
        cout << "Enter number of rows=>";
        cin >> numX;
    }
    cout << "Enter number of column=>";
    cin >> numY;
    while (numY % 2 == 0)
    {
        cout << "Invalid! Please enter an odd number" << endl;
        cout << "Enter number of columns=>";
        cin >> numY;
    }
    grid.resize(numX, vector<char>(numY));

    // Place 'A' in the middle of the grid
    int midX = (numX - 1) / 2;
    int midY = (numY - 1) / 2;

    grid[midX][midY] = 'A';
}

void generateInpluto(int &numX, int &numY, vector<vector<char>> &grid)
{
    char objects[] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', '<', '^', '>', 'v', 'h', 'p', 'r', 'p'};
    int noOfObjects = 15; // number of objects in the objects array

    // put random characters into the vector array
    for (int i = 0; i < numX; ++i)
    {
        for (int j = 0; j < numY; ++j)
        {
            if (grid[i][j] != 'A')
            {
                int objNo = rand() % noOfObjects;
                grid[i][j] = objects[objNo];
            }
        }
    }
}

void generateZombies(int &numX, int &numY, vector<vector<char>> &grid)
{
    cout << "==============================" << endl;
    cout << "        Zombie Settings" << endl;
    cout << "==============================" << endl;
    cout << "Number of Zombies (1-9) => ";
    cin >> zombies;

    char objects[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    if (zombies > 0 && zombies < 10)
    {
        int generatedZombies = 0;
        while (generatedZombies < zombies)
        {
            int randomIndex = rand() % (numX * numY);
            int x = randomIndex / numY;
            int y = randomIndex % numY;
            if (grid[x][y] != '1', '2', '3', '4', '5', '6', '7', '8', '9')
            {
                grid[x][y] = objects[generatedZombies];
                generatedZombies = generatedZombies + 1;
            }
        }
    }
    else
    {
        cout << "Invalid!" << endl;
        cout << "Please insert the number of zombies between the range 1-9" << endl;
    }
}

void displayBoard(int &numX, int &numY, vector<vector<char>> &grid)
{
    cout << "------------------------------" << endl;
    cout << "|       Alien vs Zombie      |" << endl;
    cout << "------------------------------" << endl;
    for (int i = 0;
         i < numX; i++)
    {
        // display upper border of the Row
        cout << " ";
        cout << " ";
        for (int j = 0; j < numY; j++)
        {
            cout << "+-";
        }
        cout << "+" << endl;
        // display row number
        cout << setw(2) << i + 1;

        for (int j = 0; j < numY; j++)
        {
            cout << "|" << grid[i][j];
        }
        cout << "|" << endl;
    }

    cout << " ";
    cout << " ";
    for (int j = 0; j < numY; j++)
    {
        cout << "+-";
    }
    cout << "+" << endl;

    cout << " ";
    cout << " ";
    for (int j = 0; j < numY; ++j)
    {
        int digit = (j + 1) / 10;
        cout << " ";
        if (digit == 0)
            cout << " ";
        else
            cout << digit;
    }

    cout << endl;
    cout << " ";
    cout << " ";
    for (int j = 0; j < numY; ++j)
    {
        cout << " " << (j + 1) % 10;
    }
    cout << endl
         << endl;
}

int A_health = 100;
int A_attack_damage = 10;
int A_attack_range = 1;

void displayAlienStatus()
{
    cout << "Alien Status  >>>";
    cout << " ";
    cout << "Health: " << A_health;
    cout << " ";
    cout << "| Attack Damage: " << A_attack_damage;
    cout << " ";
    cout << "| Attack Range: " << A_attack_range << endl;
}

void displayZombieStatus(int zombies)
{
    srand(time(0)); // to generate random number
    int Z_health[zombies];
    int Z_attack_damage[zombies];
    int Z_attack_range[zombies];
    for (int i = 0; i < zombies; i++)
    {
        Z_health[i] = 250;                      // random value between 50-200
        Z_attack_damage[i] = (rand() % 20) + 5; // random value between 5-20
        if (Z_attack_damage[i] % 5 != 0)
        {
            Z_attack_damage[i] -= Z_attack_damage[i] % 5;
        }
        Z_attack_range[i] = (rand() % 5) + 1; // random value between 1-5
    }
    for (int i = 0; i < zombies; i++)
    {
        cout << "Zombie Status"
             << " " << i + 1 << ">>>";
        cout << " ";
        cout << "Health: " << Z_health[i];
        cout << " ";
        cout << "| Attack Damage: " << Z_attack_damage[i];
        cout << " ";
        cout << "| Attack Range: " << Z_attack_range[i] << endl;
    }
}

void moveCharacter(vector<vector<char>> &grid, int &currentX, int &currentY)
{
    string moveDirection;
    cout << "COMMANDS=> ";
    getline(cin, moveDirection);
    if (moveDirection == "up")
    {
        if (currentX > 0)
        {                                   // check if the character is not on the top edge
            grid[currentX][currentY] = '.'; // clear current position
            currentX--;                     // move up
            grid[currentX][currentY] = 'A'; // update new position
        }
    }
    else if (moveDirection == "down")
    {
        if (currentX < grid.size() - 1)
        { // check if the character is not on the bottom edge
            grid[currentX][currentY] = '.';
            currentX++;
            grid[currentX][currentY] = 'A';
        }
    }
    else if (moveDirection == "left")
    {
        if (currentY > 0)
        { // check if the character is not on the left edge
            grid[currentX][currentY] = '.';
            currentY--;
            grid[currentX][currentY] = 'A';
        }
    }
    else if (moveDirection == "right")
    {
        if (currentY < grid[0].size() - 1)
        { // check if the character is not on the right edge
            grid[currentX][currentY] = '.';
            currentY++;
            grid[currentX][currentY] = 'A';
        }
    }
    else if (moveDirection == "help")
    {
        cout << " commands" << endl;
        cout << "1. up        -move up" << endl;
        cout << "2. down      -move down" << endl;
        cout << "3. left      -move left" << endl;
        cout << "4. right     -move right" << endl;
        cout << "6  arrow     -change the direction of an arrow" << endl;
        cout << "7. help      -display user commands" << endl;
        cout << "8. save      -save the game" << endl;
        cout << "9. load      -load a game" << endl;
        cout << "10 quit      -quit game" << endl;
    }
    else if (moveDirection == "save")
    {
        ofstream saveFile("saved_game.txt");
        saveFile << currentX << " " << currentY << endl;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                saveFile << grid[i][j];
            }
            saveFile << endl;
        }
        saveFile.close();
        cout << "Game saved!";
    }

    else if (moveDirection == "load")
    {
        ifstream loadFile("saved_game.txt");
        if (!loadFile.is_open())
        {
            cout << "file not found" << endl;
            for (int i = 0; i < grid.size(); i++)
            {
                for (int j = 0; j < grid[i].size(); j++)
                {
                    loadFile >> grid[i][j];
                }
            }
            loadFile.close();
            cout << "Game loaded!" << endl;
        }
    }

    else if (moveDirection == "quit")
    {
        std::cout << "Thanks for playing!" << std::endl;
        return;
    }
    
    else if (moveDirection == "arrow")
    {
        // Code to change the direction of an arrow
    }
    else
    {
        cout << "Please enter a valid command or type Help for command menue" << endl;
    }


}

void resetGrid(vector<vector<char>> &grid, int &currentX, int &currentY)
{
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] == '.' && (i != currentX || j != currentY))
                grid[i][j] = ' ';
        }
    }
}


#endif
