# Part 1

## Video Demo

Please provide the YouTube link to your [Video Demo](https://www.youtube.com/watch?v=64AH-ano6Q0).

## Minimum Requirements

### Completed

List all the features completed.

1. menu
2. generate grid
3. generate grid customize row and column
4. generate grid with only accepting odd numbers
5. generate alien on grid to make always center
6. generate zombie on grid without overrighting the alien
7. generate zombie to display according to number of zombie asked
8. generating random objects
9. moving the alien while leaving trail 
10. moving the alien without displaying more than one grid
11. displaying alien status
12. displaying zombie status
13. print command
14. header file
15. run two different files at a time 


### To Do

List all the features not yet done. Remove this section if there is no incomplete requirements.

1. save load menu
2. exit to main menu
3. when alien attack
4. when zombie attack
5. default settings
6. zombie movement
7. health status decrease when attacked
8. game over 
9. success game 


## Additional Features

Describe the additional features that has been implemented.

## Contributions

### AL ARSHAD BIN AL HANISHAM

1. Building the main menu by using the switch case statement this will be the main function and cpp file to call out other function
2. Reformmating the grid to suit for futher progress ( void generate board and display)
3. Print the command to help the user know the input of the game
4. Moving the alien and leaving the trail

### ADRIANA IMAN BINTI NOOR AZRAI

1. Changing the code to use vector as it was easier to understand
2. Figuring out how to generate the alien to always be in the center for what ever numbers of row and colmns
3. Making sure that the alien movement only display on one board and not multiple
4. Generating the zombie on the grid without overlaying other objects ( void generate zombie)

### SOFEA HAZREENA BINTI HASDI

1. Generating the grid for the game (used class )
2. Generating the grid for the game also using vector  (used class )
3. Generating the zombie and making sure it prints according to the number of input from user ( void generate zombie)
4. Displaying the status of the alien such as its attack, range and health
5. Displaying the status of the zombie such as its attack, range and health

## Problems Encountered & Solutions

1. Use class at first then decide to use functions 
2. Fail when we try to add header(demo) but we find another solution on how to add the header by having both files in the same folder and not overwriting the files
3. Try to use system(“cls”) but fail when use getchar(), then we change it to another way to clear screen
4. Displaying characters that overlap other objects on thr grid, to solve we first check if the grid already has something inside, for example, alien
5. Experienced many segmentation errors throughout, solved it by making sure data exists in a file 
6. When moving alien, the grid reprints itself so we rearrange the main function to make sure it only prints once
