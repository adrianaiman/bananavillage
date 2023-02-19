// *********************************************************
// Course: TCP1101 PROGRAMMING FUNDAMENTALS
// Year: Trimester 1, 2022/23 (T2215)
// Lab: TT7L
// Names: AL_Arshad_Bin_Al_Hanisham | Adriana_Iman_binti_Noor_Azrai | Sofea_Hazreena_binti_Hasdi
// IDs: 1211103123 | 1211103196 | 1211103216
// Emails: 1211103123@student.mmu.edu.my| 1211103196@student.mmu.edu.my | 1211103216@student.mmu.edu.my
// Phones: 0164202003 | 01110241210 | 0193287357
// *********************************************************

#ifndef CASE0_H
#define CASE0_H
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <conio.h> // for setw()
#include <cstdlib>
#include <cctype>
#include <fstream>
using namespace std;

int numX;
int numY;
int zombies;
vector<pair<int, int>> zombieCoordinates;
vector<char> objects = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};


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
    int defaultNumX = 7;
    int defaultNumY = 7;
    cout << endl;

    cout << "      ####################################" << endl;
    cout << "   ##########################################" << endl;
    cout << " ############### Board Settings ###############" << endl;
    cout << "   ##########################################" << endl;
    cout << "      ####################################" << endl
         << endl;
    cout << "                Choose a level:" << endl;
    cout << "                 1. Beginner" << endl;
    cout << "             2. Default Settings" << endl;
    cout << "         3. Customize (choose board size)" << endl
         << endl;
    cout << "             Enter choice (1/2/3) =>" << endl;
    int choice;
    cin >> choice;
    cout << "press any key to continue... " << endl;
    _getch();
    system("cls");
    if (choice == 1)
    {
        // Beginner level
        numX = 5;
        numY = 5;
        grid.resize(numX, vector<char>(numY, '-'));

        // Print tutorial
        cout << endl;
        cout << "=======================================================================" << endl;
        cout << "                              TUTORIAL" << endl;
        cout << "=======================================================================" << endl;
        cout << "=> The objective of the game is to survive as long as possible." << endl;
        cout << "=> You (represented by 'A') start in the middle of the board." << endl;
        cout << "=> Zombies (represented by '1-9') will move towards you every turn." << endl;
        cout << "=> If a zombie gets next to you, it will attack and decrease your health." << endl;
        cout << "=> You can attack zombies by moving next to them and enter the direction." << endl;
        cout << "=> Attacking a zombie will decrease its health." << endl;
        cout << "=> If a zombie's health reaches 0, it will die and disappear." << endl;
        cout << "=> If your health reaches 0, you will die and the game will end." << endl;
        cout << "=> Good luck!" << endl;
        cout << "========================================================================" << endl
             << endl;

        cout << "press any key to continue... " << endl;
        _getch();
        system("cls");
    }
    else if (choice == 2)
    {
        // Default level
        numX = defaultNumX;
        numY = defaultNumY;
        grid.resize(numX, vector<char>(numY, '-'));
    }
    else
    {
        // Custom level
        cout << "Enter board size:" << endl;
        cout << "Number of rows => ";
        cin >> numX;

        while (numX % 2 == 0)
        {
            cout << "Invalid! Please enter an odd number" << endl;
            cout << "Enter number of rows => ";
            cin >> numX;
        }

        cout << "Number of columns => ";
        cin >> numY;

        while (numY % 2 == 0)
        {
            cout << "Invalid! Please enter an odd number" << endl;
            cout << "Enter number of columns => ";
            cin >> numY;
        }

        grid.resize(numX, vector<char>(numY, '-'));
    }

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

void generateZombies(int &numX, int &numY, vector<vector<char>> &grid, vector<pair<int, int>> &zombieCoordinates)
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
            int zombieX = randomIndex / numY;
            int zombieY = randomIndex % numY;
            if (grid[zombieX][zombieY] == ' ')
            {
                grid[zombieX][zombieY] = objects[generatedZombies];
                zombieCoordinates.push_back({zombieX, zombieY});
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

void displayAlienStatus(int &A_health, int A_attack_damage, int A_attack_range)
{

    cout << "Alien Status  >>>";
    cout << " ";
    cout << "Health: " << A_health;

    cout << " ";
    cout << "| Attack Damage: " << A_attack_damage;
    cout << " ";
    cout << "| Attack Range: " << A_attack_range << endl;
}

void displayZombieStatus(int zombies, int &Z_health, const int &Z_attack_damage, const int &Z_attack_range)
{
    for (int i = 0; i < zombies; i++)
    {
        cout << "Zombie Status"
             << " " << i + 1 << ">>>";
        cout << " ";
        cout << "Health: " << Z_health;
        cout << " ";
        cout << "| Attack Damage: " << Z_attack_damage;
        cout << " ";
        cout << "| Attack Range: " << Z_attack_range << endl;
    }
}

void saveGame(const vector<vector<char>> &grid, const int currentX, const int currentY, const int A_health, const int A_attack_damage, const int A_attack_range, const int zombies, const int Z_health, const int Z_attack_damage, const int Z_attack_range, const string &player, const string &saveFileName)
{
    string fileName;
    cout << "Type in filename:" << endl;
    cin >> fileName;

    ofstream file(fileName + ".txt");

    file << "------------------------------" << endl;
    file << "|       Alien vs Zombie      |" << endl;
    file << "------------------------------" << endl;
    file << endl;

    int numX = grid.size();
    int numY = grid[0].size();

    for (int i = 0; i < numX; i++)
    {
        // display upper border of the Row
        file << " ";
        file << " ";
        for (int j = 0; j < numY; j++)
        {
            file << "+-";
        }
        file << "+" << endl;
        // display row number
        file << setw(2) << i + 1;

        for (int j = 0; j < numY; j++)
        {
            file << "|" << grid[i][j];
        }
        file << "|" << endl;
    }

    file << " ";
    file << " ";
    for (int j = 0; j < numY; j++)
    {
        file << "+-";
    }
    file << "+" << endl;

    file << " ";
    file << " ";
    for (int j = 0; j < numY; ++j)
    {
        int digit = (j + 1) / 10;
        file << " ";
        if (digit == 0)
            file << " ";
        else
            file << digit;
    }
    file << endl;
    file << " ";
    file << " ";
    for (int j = 0; j < numY; ++j)
    {
        file << " " << (j + 1) % 10;
    }
    file << endl
         << endl;

    file << "Alien Status  >>> Health: " << A_health << " | Attack Damage: " << A_attack_damage << " | Attack Range: " << A_attack_range << endl;

    for (int i = 0; i < zombies; i++)
    {
        file << "Zombie Status " << i + 1 << ">>> Health: " << Z_health << " | Attack Damage: " << Z_attack_damage << " | Attack Range: " << Z_attack_range << endl;
    }

    file.close();
    cout << "Game Saved" << endl;
    system("cls");
}

void loadGame(vector<vector<char>> &grid, int &currentX, int &currentY, int &A_health, const string &player, const string &filename)
{
    std::ifstream loadfile(filename);
    if (!loadfile.is_open())
    {
        cerr << "Error: Failed to load your game" << endl;
        return;
    }
    std::string loadedPlayer;

    // Load player name
    getline(loadfile, loadedPlayer);

    // Load grid size
    int numX, numY;
    loadfile >> numX >> numY;
    grid.resize(numX);
    for (auto &row : grid)
    {
        row.resize(numY);
    }

    // Load grid
    char temp;
    for (int i = 0; i < numX; i++)
    {
        for (int j = 0; j < numY; j++)
        {
            loadfile >> temp;
            grid[i][j] = temp;
        }
    }

    // Load current position
    loadfile >> currentX >> currentY;

    // Load health
    loadfile >> A_health;

    // Display loaded game data
    cout << "Player: " << loadedPlayer << endl;
    cout << "Board:" << endl;
    for (const auto &row : grid)
    {
        for (const auto &col : row)
        {
            cout << col << " ";
        }
        cout << endl;
    }
    cout << "Current position: " << currentX << ", " << currentY << endl;
    cout << "Health: " << A_health << endl;

    loadfile.close();
}

void updateBoard(vector<vector<char>> &grid, int &currentX, int &currentY)
{
    int row, column;
    char direction;
    cout << "Enter the row and column of the symbol you want to change: ";
    cout << "Row=> " << endl;
    cin >> row;
    cout << "column=>  " << endl;
    cin >> column;
    row--;
    column--;
    cout << "Enter the direction you want to change the symbol to (e.g. '<', '^', '>', 'v'): ";
    cin >> direction;
    grid[row][column] = direction;
}

void resetGrid(vector<vector<char>> &grid, int &currentX, int &currentY)
{
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] == '.' && (i != currentX || j != currentY))
            {
                grid[i][j] = ' ';

                srand(time(NULL));

                // Generate a random game object in each cell with a dot
                for (int i = 0; i < grid.size(); i++)
                {
                    for (int j = 0; j < grid[i].size(); j++)
                    {
                        if (grid[i][j] == '.')
                        {
                            int objNo = rand() % 8;                                    // Generate a random game object index
                            char objects[] = {'<', '^', '>', 'v', 'h', 'p', 'r', ' '}; // Define the game objects
                            grid[i][j] = objects[objNo];
                        }
                    }
                }
            }
        }
    }
}

void moveCharacter(vector<vector<char>> &grid, int &currentX, int &currentY, int &A_health, int &Z_health, const int &Z_attack_damage, int &A_attack_damage, const string &player, vector<pair<int, int>> &zombieCoordinates, int &A_attack_range)
{
    string moveDirection;
    cout << "COMMANDS=> ";
    getline(cin, moveDirection);

    if (moveDirection == "w" || moveDirection == "W" || moveDirection == "^")
    {
        if (currentX > 0)
        {
            grid[currentX][currentY] = '.';
            currentX--;
            if (grid[currentX][currentY] == 'h')
            {
                cout << "Alien finds a health pack." << endl;
                cout << "Alien's health increased by 20" << endl;
                A_health += 20;
            }
            else if (grid[currentX][currentY] == 'r')
            {
                cout << "Alien finds a rock." << endl;
                cout << "Press any key to continue..." << endl;
                getch();
                int random = rand() % 2;
                if (random == 0)
                {
                    grid[currentX][currentY] = 'p';
                    cout << "A pod appears on the rock." << endl;
                    Z_health -= 10;
                }
                else
                {
                    grid[currentX][currentY] = 'h';
                    cout << "A health-pack appears on the rock." << endl;
                    A_health += 20;
                }
                getch();
                grid[currentX][currentY] = 'A';
            }
            if (grid[currentX][currentY] == '>')
            {
                cout << "Alien encounters an arrow pointing to the right" << endl;

                getch();
                A_attack_range += 1;
                currentY++;
            }
            else if (grid[currentX][currentY] == '^')
            {
                cout << "Alien encounters an arrow pointing upwards" << endl;

                getch();
                A_attack_range += 1;
                currentX--;
            }
            else if (grid[currentX][currentY] == '<')
            {
                cout << "Alien encounters an arrow pointing to the left" << endl;

                getch();
                A_attack_range += 1;
                currentY--;
            }
            else if (grid[currentX][currentY] == 'v')
            {
                cout << "Alien encounters an arrow pointing downwards" << endl;

                getch();
                A_attack_range += 1;
                currentX++;
            }

            if (grid[currentX][currentY] == 'p')
            {
                cout << "Alien finds pod ";
                cout << "zombie recieves a damage of 10 ";
                Z_health -= 10;
            }

            for (int i = 0; i < 10; i++)
            {
                if (isdigit(grid[currentX][currentY])) // Check if the current grid location contains a digit
                {
                    // Attack the zombie
                    cout << "Alien finds a zombie." << endl;
                    if (Z_health > 0) // Check if Zombie is still alive
                    {
                        cout << "Zombie receives " << A_attack_damage << " damage." << endl;
                        Z_health -= A_attack_damage; // Reduce Zombie's health
                        if (Z_health > 0)
                        {
                            cout << "Zombie is still alive." << endl;
                        }
                        else
                        {
                            cout << "Zombie is dead." << endl;
                            grid[currentX][currentY] = ' '; // Set the Zombie's location in the grid to ' ' to indicate that it's dead
                        }
                        break; // Exit the loop after attacking the Zombie
                    }
                    // Alien's turn is over
                    cout << "Alien's turn is over." << endl;
                    // Zombie's turn to move and attack
                    cout << "Zombie's turn to attack. Trail is reset." << endl;
                    resetGrid(grid, currentX, currentY);
                }
                grid[currentX][currentY] = 'A';
            }
        }
    }
    else if (moveDirection == "s" || moveDirection == "S")
    {
        if (currentX < grid.size() - 1)
        { // check if the character is not on the bottom edge
            grid[currentX][currentY] = '.';
            currentX++;
            if (grid[currentX][currentY] == 'h')
            {
                cout << "Alien finds a health pack." << endl;
                cout << "Alien's health increased by 20" << endl;
                A_health += 20;
            }
            if (grid[currentX][currentY] == 'r')
            {
                cout << "Alien finds a rock." << endl;
                cout << "Press any key to continue..." << endl;
                getch();
                // generate a random number between 0 and 1
                int random = rand() % 2;
                if (random == 0)
                {
                    grid[currentX][currentY] = 'p';

                    cout << "A pod appears on the rock." << endl;

                    Z_health -= 10;
                }
                else
                {
                    grid[currentX][currentY] = 'h';

                    cout << "A health-pack appears on the rock." << endl;

                    A_health += 20;
                }

                getch();
                grid[currentX][currentY] = 'A';
            }

            if (grid[currentX][currentY] == '>')
            {
                cout << "Alien encounters an arrow pointing to the right" << endl;

                getch();
                A_attack_range += 1;
                currentY++;
            }
            else if (grid[currentX][currentY] == '^')
            {
                cout << "Alien encounters an arrow pointing upwards" << endl;

                getch();
                A_attack_range += 1;
                currentX--;
            }
            else if (grid[currentX][currentY] == '<')
            {
                cout << "Alien encounters an arrow pointing to the left" << endl;

                getch();
                A_attack_range += 1;
                currentY--;
            }
            else if (grid[currentX][currentY] == 'v')
            {
                cout << "Alien encounters an arrow pointing downwards" << endl;

                getch();
                A_attack_range += 1;
                currentX++;
            }

            if (grid[currentX][currentY] == 'p')
            {
                cout << "Alien finds pod ";
                cout << "zombie recieves a damage of 10 ";
                Z_health -= 10;
            }

            for (int i = 0; i < 10; i++)
            {
                if (isdigit(grid[currentX][currentY])) // Check if the current grid location contains a digit
                {
                    cout << "Alien finds a zombie." << endl;
                    if (Z_health > 0) // Check if Zombie is still alive
                    {
                        cout << "Zombie receives " << A_attack_damage << " damage." << endl;
                        Z_health -= A_attack_damage; // Reduce Zombie's health
                        if (Z_health > 0)
                        {
                            cout << "Zombie is still alive." << endl;
                        }
                        else
                        {
                            cout << "Zombie is dead." << endl;
                            grid[currentX][currentY] = ' '; // Set the Zombie's location in the grid to ' ' to indicate that it's dead
                        }
                        break; // Exit the loop after attacking the Zombie
                    }
                    cout << "Alien's turn is over." << endl;
                    cout << "Zombie's turn to attack. Trail is reset." << endl;
                    resetGrid(grid, currentX, currentY);
                    return;
                }
                grid[currentX][currentY] = 'A';
            }
        }
    }
    else if (moveDirection == "a" || moveDirection == "A")
    {
        if (currentY > 0)
        { // check if the character is not on the left edge
            grid[currentX][currentY] = '.';
            currentY--;
            if (grid[currentX][currentY] == 'h')
            {
                cout << "Alien finds a health pack." << endl;
                cout << "Alien's health increased by 20" << endl;
                A_health += 20;
            }
            if (grid[currentX][currentY] == 'r')
            {
                cout << "Alien finds a rock." << endl;
                cout << "Press any key to continue..." << endl;
                getch();
                // generate a random number between 0 and 1
                int random = rand() % 2;
                if (random == 0)
                {
                    grid[currentX][currentY] = 'p';

                    cout << "A pod appears on the rock." << endl;

                    Z_health -= 10;
                }
                else
                {
                    grid[currentX][currentY] = 'h';

                    cout << "A health-pack appears on the rock." << endl;

                    A_health += 20;
                }

                getch();
                grid[currentX][currentY] = 'A';
            }
            if (grid[currentX][currentY] == '>')
            {
                cout << "Alien encounters an arrow pointing to the right" << endl;

                getch();
                A_attack_range += 1;
                currentY++;
            }
            else if (grid[currentX][currentY] == '^')
            {
                cout << "Alien encounters an arrow pointing upwards" << endl;

                getch();
                A_attack_range += 1;
                currentX--;
            }
            else if (grid[currentX][currentY] == '<')
            {
                cout << "Alien encounters an arrow pointing to the left" << endl;

                getch();
                A_attack_range += 1;
                currentY--;
            }
            else if (grid[currentX][currentY] == 'v')
            {
                cout << "Alien encounters an arrow pointing downwards" << endl;

                getch();
                A_attack_range += 1;
                currentX++;
            }

            if (grid[currentX][currentY] == 'p')
            {
                cout << "Alien finds pod ";
                cout << "zombie recieves a damage of 10 ";
                Z_health -= 10;
            }

            for (int i = 0; i < 10; i++)
            {
                if (isdigit(grid[currentX][currentY])) // Check if the current grid location contains a digit
                {
                    cout << "Alien finds a zombie." << endl;
                    if (Z_health > 0) // Check if Zombie is still alive
                    {
                        cout << "Zombie receives " << A_attack_damage << " damage." << endl;
                        Z_health -= A_attack_damage; // Reduce Zombie's health
                        if (Z_health > 0)
                        {
                            cout << "Zombie is still alive." << endl;
                        }
                        else
                        {
                            cout << "Zombie is dead." << endl;
                            grid[currentX][currentY] = ' '; // Set the Zombie's location in the grid to ' ' to indicate that it's dead
                        }
                        break; // Exit the loop after attacking the Zombie
                    }
                    cout << "Alien's turn is over." << endl;
                    cout << "Zombie's turn to attack. Trail is reset." << endl;
                    resetGrid(grid, currentX, currentY);
                    return;
                }
                grid[currentX][currentY] = 'A';
            }
        }
    }
    else if (moveDirection == "d" || moveDirection == "D")
    {
        if (currentY < grid[0].size() - 1)
        { // check if the character is not on the right edge
            grid[currentX][currentY] = '.';
            currentY++;
            if (grid[currentX][currentY] == 'h')
            {
                cout << "Alien finds a health pack." << endl;
                cout << "Alien's health increased by 20" << endl;
                A_health += 20;
            }

            if (grid[currentX][currentY] == 'r')
            {
                cout << "Alien finds a rock." << endl;
                cout << "Press any key to continue..." << endl;
                getch();
                // generate a random number between 0 and 1
                int random = rand() % 2;
                if (random == 0)
                {
                    grid[currentX][currentY] = 'p';

                    cout << "A pod appears on the rock." << endl;

                    Z_health -= 10;
                }
                else
                {
                    grid[currentX][currentY] = 'h';

                    cout << "A health-pack appears on the rock." << endl;

                    A_health += 20;
                }

                getch();
                grid[currentX][currentY] = 'A';
            }
            if (grid[currentX][currentY] == '>')
            {
                cout << "Alien encounters an arrow pointing to the right" << endl;

                getch();
                A_attack_range += 1;
                currentY++;
            }
            else if (grid[currentX][currentY] == '^')
            {
                cout << "Alien encounters an arrow pointing upwards" << endl;

                getch();
                A_attack_range += 1;
                currentX--;
            }
            else if (grid[currentX][currentY] == '<')
            {
                cout << "Alien encounters an arrow pointing to the left" << endl;

                getch();
                A_attack_range += 1;
                currentY--;
            }
            else if (grid[currentX][currentY] == 'v')
            {
                cout << "Alien encounters an arrow pointing downwards" << endl;

                getch();
                A_attack_range += 1;
                currentX++;
            }

            for (int i = 0; i < 10; i++)
            {
                if (isdigit(grid[currentX][currentY])) // Check if the current grid location contains a digit
                {
                    cout << "Alien finds a zombie." << endl;
                    if (Z_health > 0) // Check if Zombie is still alive
                    {
                        cout << "Zombie receives " << A_attack_damage << " damage." << endl;
                        Z_health -= A_attack_damage; // Reduce Zombie's health
                        if (Z_health > 0)
                        {
                            cout << "Zombie is still alive." << endl;
                        }
                        else
                        {
                            cout << "Zombie is dead." << endl;
                            grid[currentX][currentY] = ' '; // Set the Zombie's location in the grid to ' ' to indicate that it's dead
                        }
                        break; // Exit the loop after attacking the Zombie
                    }
                    cout << "Alien's turn is over." << endl;
                    cout << "Zombie's turn to attack. Trail is reset." << endl;
                    resetGrid(grid, currentX, currentY);
                    return;
                }
                grid[currentX][currentY] = 'A';
            }
        }
        else
        {
            cout << "Alien hits a border." << endl;
            resetGrid(grid, currentX, currentY);
        }
    }
    // Check if there's a '^' or 'v' in the grid, if so move the alien in that direction
    else if (grid[currentX][currentY] == '^')
    {
        if (currentX > 0)
        {
            A_attack_range += 1;
            currentX--;
        }
    }
    else if (grid[currentX][currentY] == 'v')
    {
        if (currentX < grid.size() - 1)
        {
            A_attack_range += 1;
            currentX++;
        }
    }
    else if (moveDirection == "help")
    {
        cout << " commands" << endl;
        cout << "1. w         -move up" << endl;
        cout << "2. s         -move down" << endl;
        cout << "3. a         -move left" << endl;
        cout << "4. d         -move right" << endl;
        cout << "6  arrow     -change the direction of an arrow" << endl;
        cout << "7. help      -display user commands" << endl;
        cout << "8. save      -save the game" << endl;
        cout << "9. load      -load a game" << endl;
        cout << "10 quit      -quit game" << endl;
    }
    else if (moveDirection == "save")
    {
        std::string saveFileName;
        std::cout << "Enter a name for the save file: ";
        std::cin >> saveFileName;
        saveFileName += ".txt";
        saveGame(grid, currentX, currentY, A_health, A_attack_damage, A_attack_damage, zombies, Z_health, Z_attack_damage, Z_attack_damage, player, saveFileName);
    }
    else if (moveDirection == "load")
    {
        string loadFileName;
        cout << "Enter the name of the save file: ";
        cin >> loadFileName;
        loadGame(grid, currentX, currentY, A_health, player, "saved_game.txt");
    }

    else if (moveDirection == "arrow")
    {
        updateBoard(grid, currentX, currentY);
    }

    else if (moveDirection == "quit")
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
            return;
        }
        else
            ;
        cout << "Invalid! Please state (yes/no) only" << endl;
    }

    else
    {
        cout << "Please enter a valid command or type Help for command menu" << endl;
    }

}

void moveZombies(int numX, int numY, vector<vector<char>> &grid, vector<pair<int, int>> &zombieCoordinates, int Z_attack_range, int &A_health, int Z_attack_damage, int currentX, int currentY)
{
    char objects[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int newX, newY;
    bool alien_attacked = false;

    for (int i = 0; i < zombies; i++)
    {
        int x = zombieCoordinates[i].first;
        int y = zombieCoordinates[i].second;
        int moveDirection = rand() % 4;

        switch (moveDirection)
        {
        case 0: // move up
            newX = x - 1;
            newY = y;
            break;
        case 1: // move right
            newX = x;
            newY = y + 1;
            break;
        case 2: // move down
            newX = x + 1;
            newY = y;
            break;
        case 3: // move left
            newX = x;
            newY = y - 1;
            break;
        }

        // Check if the intended move is within the grid boundaries
        if (newX >= 0 && newX < numX && newY >= 0 && newY < numY)
        {
            grid[newX][newY] = objects[i];
            zombieCoordinates[i] = make_pair(newX, newY);
            grid[x][y] = ' ';
        }
        else
        {
            // If the intended move is outside the grid boundaries, skip the zombie's turn and do nothing
            continue;
        }

        // Check if the zombie is in range to attack the alien
        int distanceX = abs(currentX - newX);
        int distanceY = abs(currentY - newY);

        if (!alien_attacked && distanceX <= Z_attack_range && distanceY <= Z_attack_range)
        {
            if (distanceX == 0 || distanceY == 0 || distanceX == distanceY)
            {
                int zombieDistanceX = abs(currentX - x);
                int zombieDistanceY = abs(currentY - y);

                if (zombieDistanceX <= Z_attack_range && zombieDistanceY <= Z_attack_range)
                {
                    A_health -= Z_attack_damage;
                    cout << "Zombie attacks Alien" << endl;
                    cout << "Alien receives a damage of " << Z_attack_damage << endl;

                    if (A_health != 0)
                    {
                        cout << "Alien is still alive" << endl;
                    }

                    alien_attacked = true;
                }
                else
                {
                    cout << "Alien is too far" << endl;
                }
            }
        }
    }
}

void gameOver(int A_health, int Z_health)
{
    if (A_health <= 0)
    {
        cout << "The Alien has died, game over!" << endl;
        cout << "Do you want to play again? y for yes and n for no (y/n)=> " << endl;
        char playAgain;
        cin >> playAgain;

        if (playAgain == 'y' || 'Y')
        {
            cout << "press any key to continue... " << endl;
            _getch();
            system("cls");
            srand(time(NULL));
            int numX, numY;
            int Z_health = 50;
            int Z_attack_range = (rand() % 5) + 1;         // random value between 1-5
            const int Z_attack_damage = (rand() % 10) + 5; // random value between 5-15

            int A_health = rand() % 101 + 100;
            ;
            int A_attack_damage = 10;
            int A_attack_range = 1;
            int currentX;
            int currentY;
            std::string player;
            vector<vector<char>> grid;

            int choice;
            bool end = false;

            while (!end)
            {
                bool gameEnd = false;

                while (!gameEnd)
                {
                    cout << "Please select an option:" << endl;
                    cout << "1. New game" << endl;
                    cout << "2. Load game" << endl;
                    cin >> choice;

                    if (choice == 2)
                    {
                        loadGame(grid, currentX, currentY, A_health, player, "saved_game.txt");
                        cout << "Game is loading..." << endl;
                    }
                    else if (choice == 1)
                    {
                        cout << "Board is generating..." << endl;
                        _getch();
                        system("cls");
                        generateBoard(numX, numY, grid);

                        if (numX % 2 == 1 && numY % 2 == 1)
                        {
                            generateInpluto(numX, numY, grid);
                        }

                        currentX = (numX - 1) / 2;
                        currentY = (numY - 1) / 2;
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

                        while (zombies > 0 && zombies < 10 && A_health > 0 && Z_health > 0)
                        {
                            displayBoard(numX, numY, grid);
                            displayAlienStatus(A_health, A_attack_damage, A_attack_range);
                            displayZombieStatus(zombies, Z_health, Z_attack_damage, Z_attack_range);
                            moveCharacter(grid, currentX, currentY, A_health, Z_health, Z_attack_damage, A_attack_damage, player, zombieCoordinates, A_attack_range);
                            moveZombies(numX, numY, grid, zombieCoordinates, Z_attack_range, A_health, Z_attack_damage, currentX, currentY);
                            cout << "Press any key to continue... " << endl;
                            _getch();
                            system("cls");
                        }

                        end = true;
                    }
                    break;
                }
                break;
            }
        }
        else
        {
            cout << "Thank you for playing!" << endl;
            getch();
            exit(0);
        }
    }
    else if (Z_health <= 0)
    {
        cout << "All zombies have been defeated, you win!" << endl;
        cout << "Do you want to play again? y for yes and n for no (y/n)=> " << endl;
        char playAgain;
        cin >> playAgain;

        if (playAgain == 'y' || 'Y')
        {
            cout << "press any key to continue... " << endl;
            _getch();
            system("cls");
            srand(time(NULL));
            int numX, numY;
            int Z_health = 50;
            int Z_attack_range = (rand() % 5) + 1;         // random value between 1-5
            const int Z_attack_damage = (rand() % 10) + 5; // random value between 5-15

            int A_health = rand() % 101 + 100;
            ;
            int A_attack_damage = 10;
            int A_attack_range = 1;
            int currentX;
            int currentY;
            std::string player;
            vector<vector<char>> grid;

            int choice;
            bool end = false;

            while (!end)
            {
                bool gameEnd = false;

                while (!gameEnd)
                {
                    cout << "Please select an option:" << endl;
                    cout << "1. New game" << endl;
                    cout << "2. Load game" << endl;
                    cin >> choice;

                    if (choice == 2)
                    {
                        loadGame(grid, currentX, currentY, A_health, player, "saved_game.txt");
                        cout << "Game is loading..." << endl;
                    }
                    else if (choice == 1)
                    {

                        cout << "Board is generating..." << endl;
                        _getch();
                        system("cls");
                        generateBoard(numX, numY, grid);

                        if (numX % 2 == 1 && numY % 2 == 1)
                        {
                            generateInpluto(numX, numY, grid);
                        }

                        currentX = (numX - 1) / 2;
                        currentY = (numY - 1) / 2;
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

                        while (zombies > 0 && zombies < 10 && A_health > 0 && Z_health > 0)
                        {
                            displayBoard(numX, numY, grid);
                            displayAlienStatus(A_health, A_attack_damage, A_attack_range);
                            displayZombieStatus(zombies, Z_health, Z_attack_damage, Z_attack_range);
                            moveCharacter(grid, currentX, currentY, A_health, Z_health, Z_attack_damage, A_attack_damage, player, zombieCoordinates, A_attack_range);
                            moveZombies(numX, numY, grid, zombieCoordinates, Z_attack_range, A_health, Z_attack_damage, currentX, currentY);
                            cout << "Press any key to continue... " << endl;
                            _getch();
                            system("cls");
                        }

                        end = true;
                        break;
                    }
                }
                break;
            }
        }
        else
        {
            cout << "Thank you for playing!" << endl;
            getch();
            exit(0);
        }
    }
}


#endif
