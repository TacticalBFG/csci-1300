void Game::mainMenu() {
	board.displayBoard(players); // Display all the characters on a board
	
	Player plr = players[plrTurn];

	int lane = (int)plr.getLocation();
	int position = plr.getPosition();
	Tile tileOn = board.getTile(lane, position);

	cout << "Player " << (plrTurn + 1) << ", choose a move:" << endl;
	cout << "1. Check Player Progress" << endl;
	cout << "2. Review Character" << endl;
	cout << "3. Check Position" << endl;

	// The next move is dependent on whether the player either has an advisor or is on an advisor tile
	// If the player has an advisor or is on a tile, then the 4th option is to review advisor
	// If the player has none or isnt on a tile, the 4th option is to roll the dice.

	bool advisorOption = false;

	if (tileOn.color == 'P' || plr.getAdvisor() > 0) { // Check if the player is on an advisor tile, or if the player has an advisor assigned
		cout << "4. Check With Advisor" << endl;
		cout << "5. Roll Dice For A Move" << endl;
		cout << "6. Quit Qame" << endl;

		advisorOption = true; // Set this to true for the switch case
	}
	else { // Case for if player doesn't have an advisor and is not on an advisor tile
		cout << "4. Roll Dice For A Move" << endl;
		cout << "5. Quit Game" << endl;
	}

	char choice;
	cin >> choice;

	switch (choice) {
	case '1': {
		plr.printPrideInfo(); // Print pride points and age
		break;
	}
	case '2': {
		plr.printCharInfo(); // Print lion character info
		break;
	}
	case '3': {
		board.displayBoard(players); // This one is very redundant, not sure why its here
		break;
	}
	case '4': {
		if (advisorOption) { // Is it showing the advisor option? (Menu is shifted)
			plr.printAdvisorInfo(); // Print advisor's name and abilities
		}
		else {
			doRoll(); // Call function to do a roll
		}
		break;
	}
	case '5': {
		if (advisorOption) { // If menu shift
			doRoll() // Call function to do a roll
		}
		else {
			quitGame(); // Call funciton to quit game
		}
		break;
	}
	case '6': {
		if (advisorOption) { // If menu shift
			quitGame(); // Quit game
		}
		break;
	}
	default:
		cout << "Invalid option, please choose a number 1-6." << endl;
	}
}
