#include <iostream>
#include <fstream>
#include <string>

#include "Board.h"
#include "player.h"
#include "Split.h"

#define RED "\033[48;2;230;10;10m"
#define GREEN "\033[48;2;34;139;34m"  /* Grassy Green (34,139,34) */
#define BLUE "\033[48;2;10;10;230m"
#define PINK "\033[48;2;255;105;180m"
#define BROWN "\033[48;2;139;69;19m"
#define PURPLE "\033[48;2;128;0;128m"
#define ORANGE "\033[48;2;230;115;0m" /* Orange (230,115,0) */
#define GREY "\033[48;2;128;128;128m" /* Grey (128,128,128) */
#define RESET "\033[0m"

using namespace std;

Board::Board()
{
    _player_count = 0;
    _playing = true;
    _turns = 0;
}

players Board::getPlayer(int player_index) {
    return _players[player_index];
}

int Board::getPlayerCount() const {
    return _player_count;
}

int Board::getPlayerLand(int player_index) {
    return _players[player_index].getLand();
}

int Board::getPlayerCharacter(int player_index) {
    return _players[player_index].getCharacter();
}

int Board::getPlayerAdvisor(int player_index) {
    return _players[player_index].getAdvisor();
}

int Board::getPlayerPosition(int player_index) {
    return _players[player_index].getPosition();
}

Tile Board::getTile(int lane, int position) const {
    return _tiles[lane][position];
}

int Board::getTurns() const {
    return _turns;
}

bool Board::getPlaying() {
    return _playing;
}

/*
    SETTERS
*/

void Board::setPlayerCount(int player_count) {
    _player_count = player_count;
}

void Board::setPlayerLand(int player_index, int land) {
    _players[player_index].setLand(land);
}

void Board::setPlayerCharacter(int player_index, int character_index) {
    _players[player_index].setCharacter(character_index);
}

void Board::setPlayerAdvisor(int player_index, int advisor_index) {
    _players[player_index].setAdvisor(advisor_index);
}

void Board::setPlaying(bool isPlaying) {
    _playing = isPlaying;
}

void Board::setPlayerPosition(int player_index, int position) {
    _players[player_index].setPosition(position);
}

void Board::addTurn(int turns) {
    _turns += turns;
}

void Board::addPlayerPosition(int player_index, int amount) {
    _players[player_index].addPosition(amount);
}

void Board::initializeBoard()
{
    // Seed random number generator in your main function once

    for (int i = 0; i < 2; i++)
    {
        initializeTiles(i); // This ensures each lane has a unique tile distribution
    }
}
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
void Board::initializeTiles(int player_index)
{
    Tile temp;
    int green_count = 0;
    int total_tiles = _BOARD_SIZE;
    // Keep track of green tile positions to ensure we place exactly 30 greens
    for (int i = 0; i < total_tiles; i++)
    {
        if (i == total_tiles - 1)
        {
            // Set the last tile as Orange for "Pride Rock"
            temp.color = 'O';
        }
        else if (i == 0)
        {
            // Set the last tile as Orange for "Pride Rock"
            temp.color = 'Y';
        }
        else if (green_count < 30 && (rand() % (total_tiles - i) < 30 -
                                                                       green_count))
        {
            temp.color = 'G';
            green_count++;
        }
        else
        {
            // Randomly assign one of the other colors: Blue, Pink, Brown, Red, Purple
            int color_choice = rand() % 5;
            switch (color_choice)
            {
            case 0:
                temp.color = 'B'; // Blue
                break;
            case 1:
                temp.color = 'P'; // Pink
                break;
            case 2:
                temp.color = 'N'; // Brown
                break;
            case 3:
                temp.color = 'R'; // Red
                break;
            case 4:
                temp.color = 'U'; // Purple
                break;
            }
        }
        // Assign the tile to the board for the specified lane
        _tiles[player_index][i] = temp;
    }
}

Board::Board(int player_count)
{
    if (player_count > _MAX_PLAYERS)
    {
        _player_count = _MAX_PLAYERS;
    }
    else
    {
        _player_count = player_count;
    }
    // Initialize player position
    for (int i = 0; i < _player_count; i++)
    {
        _player_position[i] = 0;
    }
    // Initialize tiles
    initializeBoard();
}

/*
Gets the players on a tile.
Returns 1 if only player 1 is on the tile
Returns 2 if only player 2 is on the tile
Returns 3 if both players are on the tile
*/
int Board::getPlayersOnTile(int pos, int bc)
{
    int occupied = 0;
    for (int i = 0; i < _player_count; i++) {
        players player = _players[i];
        if (player.getPosition() == pos && player.getLand() == bc)
        {
            occupied += (i + 1);
        }
    }
   
    return occupied;
}
void Board::displayTile(int boardchoice, int pos)
{
    string space = "|";
    string color = "";
    int occupying = getPlayersOnTile(pos, boardchoice);
    // Template for displaying a tile: <line filler space> <color start> |<player symbol or blank space>| <reset color> <line filler space> <endl>
    // Determine color to display
    if (_tiles[boardchoice][pos].color == 'R')
    {
        color = RED;
    }
    else if (_tiles[boardchoice][pos].color == 'G')
    {
        color = GREEN;
    }
    else if (_tiles[boardchoice][pos].color == 'B')
    {
        color = BLUE;
    }
    else if (_tiles[boardchoice][pos].color == 'U')
    {
        color = PURPLE;
    }
    else if (_tiles[boardchoice][pos].color == 'N')
    {
        color = BROWN;
    }
    else if (_tiles[boardchoice][pos].color == 'P')
    {
        color = PINK;
    }
    else if (_tiles[boardchoice][pos].color == 'O')
    {
        color = ORANGE;
    }
    else if (_tiles[boardchoice][pos].color == 'Y')
    {
        color = GREY;
    }

    if (occupying == 1) { // Player 1 is on the ti;e
        space.append("1");
    } else if (occupying == 2) { // Player 2 is on the tile
        space.append("2");
    } else if (occupying == 3) { // Both players are on the tile
        space.append("1 & 2");
    }
    else {
        space.append(" ");
    }
    cout << color << space.c_str() << "|";
}

void Board::displayTrack(int player_index)
{
    for (int i = 0; i < _BOARD_SIZE; i++)
    {
        displayTile(player_index, i);
    }
    cout << endl;
}
void Board::displayBoard()
{
    for (int i = 0; i < 2; i++)
    {
        if (i == 0) {
            cout << "Cub Training:" << endl;
        }
        else {
            cout << "Pride Lands:" << endl;
        }
        displayTrack(i);
        if (i == 0)
        {
            cout << endl; // Add an extra line between the two lanes
        }
    }
}

void Board::chooseAdvisor(int player_index, bool adv)
{
    ifstream advisorlist("advisor.txt");
    string list;
    string info[2];
    string advisors[6] = {"Rafiki", "Nala", "Sarabi", "Zazu", "Sarafina"};
    int choice;
    if(adv == true)
    {
        cin >> choice;
        while(choice == _players[player_index].getAdvisor())
        {
            cout << "Both players can not choose the same advisor: Choose again" << endl;
            cin >> choice;
        }
        for(int i = 1;i<choice;i++)
        {
            getline(advisorlist,list);

        }
        getline(advisorlist,list);
        split(list, '-', info, 2);
        _players[player_index].setAdvisor(choice);
       // if(choice == 6)
    }
}

void quitGame() {
    cout << "Are you sure you want to quit? (Y/N)" << endl;
    char input;
    cin >> input;
    if (input == 'Y') { // If yes they want to quit
        exit(0); // Exit game
    }
    // Do nothing if not 
}

void Board::rollDice() {
    int playerTurn = getTurns() % getPlayerCount();

    int amount = 1 + (rand() % 5);
    addPlayerPosition(playerTurn, amount); // Move player

    Tile landedOn = getTile(getPlayerLand(playerTurn), getPlayerPosition(playerTurn)); // Get what tile the player landed on
    switch (landedOn.color) {
    case 'R':
        // Graveyard tile logic
        break;
    case 'G':
        // Green tile logic
        break;
    case 'B':
        // Oasis tile logic
        break;
    case 'U':
        // Challenge tile logic
        break;
    case 'N':
        // Hyena tile logic
        break;
    case 'P':
        // Advisor tile logic
        break;
    case 'O':
        // Pride rock logic
        break;
    }
}

void Board::mainMenu() {
    while (getPlaying()) { // While the game is running
        int playerTurn = getTurns() % getPlayerCount();


        cout << endl << endl << endl << endl << endl; // Put spaces between the last play, could make this clear the screen possibly.
        displayBoard(); // Display the board
        cout << endl << endl; // Put some spaces

        bool advisorOption = false;
        if (getPlayerAdvisor(playerTurn) > 0) { // Check if the player has an advisor assigned to them
            advisorOption = true;
        }

        if (getTile( // Find tile info for current position
            getPlayerLand(playerTurn), // Get what land the player is currently in
            getPlayerPosition(playerTurn) // Get the position of where the player is in the land 
        ).color == 'P') { // See if the color is P, as advisor tiles are pink
            advisorOption = true;
        }

        cout << "Main Menu - Choose an Option Player " << (playerTurn + 1) << ":" << endl;
        cout << " 1. Check player progress" << endl;
        cout << " 2. Review Character" << endl;
        cout << " 3. Check Position" << endl;

        if (advisorOption == true) {
            cout << " 4. Check Advisor" << endl;
            cout << " 5. Roll Dice" << endl;
            cout << " 6. Quit" << endl;
        }
        else {
            cout << " 4. Roll Dice" << endl;
            cout << " 5. Quit" << endl;
        }

        char mainMenuInput;
        cin >> mainMenuInput;

        switch (mainMenuInput) {
        case '1':
            // Call function to print player strength,wisdom,stamina, ect
            break;
        case '2':
            // Call function to print players character name and age
            break;
        case '3':
            displayBoard(); // This is dumb
            break;
        case '4':
            if (advisorOption) {
                // Call funciton to print advisors' name and special ability
            }
            else {
                rollDice(); // Call function to roll dice and move player
                addTurn(1); // Increment the turn only after you roll the dice
            }
            break;
        case '5':
            if (advisorOption) {
                rollDice(); // Call function to roll dice and move player
                addTurn(1); // Increment the turn only after you roll the dice
            }
            else {
                quitGame();
            }
            break;
        case '6':
            if (advisorOption) {
                quitGame();
                break;
            }
        default:
            cout << "Please enter a valid option." << endl;
        }
    }
}