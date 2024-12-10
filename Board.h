#ifndef BOARD_H
#define BOARD_H
#include "player.h"
#include "Tile.h"
// class Board
// {
// private:
// static const int _BOARD_SIZE = 52;
// Tile _tiles[2][_BOARD_SIZE];
// static const int _MAX_PLAYERS = 2;
// int _player_count;
// int _player_position[_MAX_PLAYERS];
// void displayTile(int player_index, int pos);
// void initializeTiles(int player_index);
// bool isPlayerOnTile(int player_index, int pos);
// public:
// Board();
// Board(int player_count);
// void displayTrack(int player_index);
// void initializeBoard();
// void displayBoard();
// bool movePlayer(int player_index);
// int getPlayerPosition(int player_index) const;
// };
class Board
	{
private:
	static const int _BOARD_SIZE = 52;
	Tile _tiles[2][_BOARD_SIZE];
	static const int _MAX_PLAYERS = 2;
	int _player_count;
	int _player_position[_MAX_PLAYERS];
	players _players[_MAX_PLAYERS];
	bool _playing;
	int _turns;

public:
	Board();
	Board(int player_count);

	int getPlayerCount() const;
	players getPlayer(int player_index);
	int getPlayerLand(int player_index);
	int getPlayerCharacter(int player_index);
	int getPlayerAdvisor(int player_index);
	int getPlayerPosition(int player_index);
	Tile getTile(int lane, int position) const;
	int getTurns() const;
	bool getPlaying();

	void setPlayerCount(int player_count);
	void setPlayerLand(int player_index, int land);
	void setPlayerCharacter(int player_index, int character_index);
	void setPlayerAdvisor(int player_index, int advisor_index);
	void setPlaying(bool isPlaying);
	void setPlayerPosition(int player_index, int position);

	void addTurn(int amount);
	void addPlayerPosition(int player_index, int amount);

	void displayTile(int player_index, int pos);
	void initializeTiles(int player_index);
	int getPlayersOnTile(int pos, int bc);
	void displayTrack(int player_index);
	void initializeBoard();
	void displayBoard();
	bool movePlayer(int player_index);
	char color; 
	int boardnumber = 0;

	void characterOptions();

	void chooseAdvisor(int player_index, bool adv);

	void mainMenu();
	void rollDice();



};
#endif
