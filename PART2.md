# Part 2

## Video Demo

Please provide the YouTube link to your [Video Demo](https://www.youtube.com/watch?v=QywK1PlTI9w).

## Minimum Requirements

### Completed

List all the features completed.

1. add beginner level in generatevoid (tutorial)
2. save game feature user can save game and inserts their desired name of file
3. Void loadgame
4. Void movezombies, zombies move after alien one grid at a time and attacks when alien is in their attack range
5. Void updateboard (change arrow)
6. Void resetgrid (grid resets after alien hits border and zombie)
7. Function of healthpack,rock and pod
8. Function of arrow and command arrow
9. Alien attack zombie
10. Void quit gam
11. Void gameover and loop
12. Update header
13. When alien encounters arrows, alien attack range increase by 1


### To Do

List all the features not yet done. Remove this section if there is no incomplete requirements.

1. Zombie removed from board if it is defeated
2. When alien finds pod, it attacks the closest zombie
3. Defeated zombies are skipped
4. Load game to continue playing

## Additional Features

1. tutorial for beginners which includes an overview of how the game works with a basic 5x5 grid and custom zombies

## Contributions

List down the contribution of each group members.

For example:

### AL ARSHAD BIN AL HANISHAM

1. Void savegame
2. Void loadgame
3. Function of healthpack,rock and pod
4. Void gameover and loop
5. Updates void moveCharacter so that it accepts lowercase and uppercase letters

### ADRIANA IMAN BINTI NOOR AZRAI

1. Zombie movement and attack behaviour.
2. Alien attack zombie
3. Quit game
4. Compile and update header file
5. Updates void generateZombies so that each zombies generated has their own ccordinates to move
6. When alien encounters arrows, alien attack range increase by 1 in void moveCharacter

### SOFEA HAZREENA BINTI HASDI

1. add beginner level in generatevoid
2. Void updateboard (change arrow)
3. Void resetgrid. 
4. Reset the dot in the trail to random objects.
5. Function of arrow and command arrow
6. Updates void moveCharacter so that when alien hits arrow, it moves according to direction
7. add function to clear screen and getch().


## Problems Encountered & Solutions

Describe the problems encountered and provide the solutions / plan for the solutions.

Problems faced : 

1. Generating a loop to prompt the user if they would like to play again

2. Couldnt break the loop when user play again , therefore the game went on eventhough the user does not want to play anymore. 

3. Couldnt save the whole grid as a txt file

4. Couldnt load the file from the saved folder

5. Rock had issues where it could not generate random object when alien met with rock

6. Zombies cannot move in grid

7. Zombies move continuously instead of after alien's turn 

8. Display of zombie attacking alien keeps on printing even before alien moves

9. alien cannot detect what number of zombies they are attacking but both healths are affected

10. When reset the dot in the trail it change to the same type of objects.



Solution : 

1. Adding a conditional statement where both alien and zombie’s health have to be more than 0 and number of zombie input on the grid has to be in the range of 1-9. 

2. Break out of the loop by adding break statements at the end of each loop.

3. add ofstream file(fileName + ".txt") inside the save function, and add the grid manually 

4. -

5. make a random function to randomly pick between p and h 

6. Declare vectors for the zombies' coordinates when they are generated into the grid 

7. Rearrange the void functions so that zombies can move after alien

8. -

9. - 

10. add srand(time(NULL)) in the code
