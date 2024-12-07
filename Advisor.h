#pragma once
#include <string>

class Advisor
{
private:
	std::string name;
	std::string ability;
	int staminaBoost;
	int wisdomBoost;
	int strengthBoost;
	int wiseness;

public:
	std::string getName() const;
	std::string getAbility() const;
	int getStamina() const;
	int getWisdom() const;
	int getStrength() const;
	int getWiseness() const;

	void printStats();

	Advisor();
	Advisor(std::string, std::string, int, int, int, int);
};

extern Advisor advisors[6];