#include "Advisor.h"
#include <iostream>

Advisor::Advisor() {
	name = "";
	staminaBoost = 0;
	wisdomBoost = 0;
	strengthBoost = 0;
	wiseness = 0;
}

Advisor::Advisor(std::string n, std::string abil, int s, int w, int str, int wise) {
	name = n;
	staminaBoost = s;
	wisdomBoost = w;
	strengthBoost = str;
	wiseness = wise;
	ability = abil;
}

std::string Advisor::getName() const {
	return name;
}

std::string Advisor::getAbility() const {
	return ability;
}

int Advisor::getStamina() const {
	return staminaBoost;
}

int Advisor::getStrength() const {
	return strengthBoost;
}

int Advisor::getWisdom() const {
	return wisdomBoost;
}

int Advisor::getWiseness() const {
	return wiseness;
}

void Advisor::printStats() {
	std::cout << name.c_str() << " : Special Ability : " << ability.c_str() << std::endl;
	std::cout << "	Stamina Boost: " << staminaBoost << std::endl;
	std::cout << "	Strength Boost: " << strengthBoost << std::endl;
	std::cout << "	Wisdom Boost: " << wisdomBoost << std::endl;
}

Advisor advisor(std::string n, std::string abil, int s, int w, int str, int wise) {
	Advisor a(n, abil, s, w, str, wise);
	return a;
}

Advisor advisors[6] = {
	advisor("None", "",0,0,0,0),
	advisor("Rafiki", "Invisibility", 0, 100, 100, 100),
	advisor("Nala", "Night Vision", 50, 200, 0, 80),
	advisor("Sarabi", "Energy Manipulation", 100, 0, 300, 20),
	advisor("Zazu", "Weather Control", 50, 200, 0, 100),
	advisor("Sarafina", "Super Speed", 300, 50, 50, 50)
};