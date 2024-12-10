/*
For the player class
    1. Enter a name and give them a starting value for wisdom, strength and health
    as well as pride points, and age
    2. return those values. 
    3. Take the player to the different lands, and add points or take away points as they go along. 
    4. 

For the Board class
    1. Go through the tiles in the array with the max value as total_tiles. 
    2. Assign colors to each of the tiles. 
    3. Use the movePlayer functions and return the position of the player. 
        As well as the dice roll function to determine how many places to move. 

For the Tile class
    1. The tiles will go to different events where you can play the games and gain or lose points
    2. or you can land on another color where the player can choose to spend points to gain something. 
*/

#include <fstream> 
#include <iostream> 
#include <string>

#include "Board.h"
#include "Tile.h"
#include "player.h"
#include "Split.h"

using namespace std;

void printCharacterList() {
    ifstream characterFile;
    characterFile.open("characters.txt");

    // Check to make sure file is open
    if (!characterFile.is_open()) {
        cout << "Error opening characters file." << endl;
        return;
    }

    string line;
    int numPlayers = 0;
    getline(characterFile, line); // Skip first line because it contains formatting information
    while (getline(characterFile, line)) {
        numPlayers = numPlayers + 1;
        string characterInfo[6] = {}; // Allocate an empty array for the character's info
        split(line, '|', characterInfo, 6);

        players player; // Allocate a blank player, set all info from character info

        // Set all of the player's attributes
        player.setName(characterInfo[0]);
        player.setAge(stoi(characterInfo[1])); // stoi(string) converts a string to an integer
        player.setStrength(stoi(characterInfo[2]));
        player.setStamina(stoi(characterInfo[3]));
        player.setWisdom(stoi(characterInfo[4]));
        player.setPridePoints(stoi(characterInfo[5]));

        // Print their number, name, and stats to the output
        cout << numPlayers << ". ";
        player.printStats();
    }

    characterFile.close();
}


int main()
{
    Board b; // Initialize an emtpy board

    // Display title menu options
    cout << "-- GAME TITLE --" << endl;
    cout << "Choose a player option:" << endl;
    cout << " 1. Single Player" << endl;
    cout << " 2. 2 Players" << endl;

    // Do loop while player count is invalid
    do {
        // Take input
        char nPlayers;
        cin >> nPlayers;

        // Input logic
        switch (nPlayers) {
        case '1':
            cout << "You have chosen single player." << endl;
            b.setPlayerCount(1);
            break;
        case '2':
            cout << "You have chosen 2 players." << endl;
            b.setPlayerCount(2);
            break;
        default:
            cout << "Please choose either 1 or 2." << endl;
        }
    } while (b.getPlayerCount() == 0);

    cout << endl << endl << endl; // Add a few spaces between for readability
    
    // Ask players what land they want to go to
    for (int i = 0; i < b.getPlayerCount(); i++) {
        cout << "Where would you like to go, player " << (i + 1) << "?" << endl;
        cout << " 1. Cub Training" << endl;
        cout << " 2. Pride Lands" << endl;
    
        // Do loop while player hasn't selected a land
        do {
            char location;
            cin >> location;

            // Input logic; make sure location is valid and put player at that location
            switch (location) {
            case '1':
                cout << "You have chosen to go to Cub Training." << endl;
                b.setPlayerLand(i, 0);
                break;
            case '2':
                cout << "You have chosen to go straight to the Pride Lands." << endl;
                b.setPlayerLand(i, 1);
                break;
            default:
                cout << "Please choose either 1 or 2." << endl;
            }
           
        } while (b.getPlayerLand(i) == -1);
        
        cout << endl << endl << endl; // Add a few spaces between for readability
        cout << "Now you must choose a character: " << endl;
        printCharacterList(); // Display list of all the characters

        // Character input logic;
        do {
            char character;
            cin >> character;

            switch (character) {
            case '1':
                b.setPlayerCharacter(i, 1);
                break;
            case '2':
                b.setPlayerCharacter(i, 2);
                break;
            case '3':
                b.setPlayerCharacter(i, 3);
                break;
            case '4':
                b.setPlayerCharacter(i, 4);
                break;
            case '5':
                b.setPlayerCharacter(i, 5);
                break;
            default:
                cout << "Please choose a character 1-5." << endl;
            }
        } while (b.getPlayerCharacter(i) == 0);


    }

    b.mainMenu(); // Call main menu function to kinda "simplify" main
}