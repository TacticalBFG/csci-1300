#include "Advisor.h"
#include <iostream>
#include <vector>

using namespace std;

Advisor::Advisor() {
	name = "";
	ability = "";
}

Advisor::Advisor(string _name, string _ability) {
	name = _name;
	ability = _ability;
}

string Advisor::getName() const {
	return name;
}

string Advisor::getAbility() const {
	return ability;
}

void Advisor::printAdvisorInfo() {
	cout << name << ":" << endl;
	cout << "  Special Ability: " << ability << endl;
}

vector<Advisor> buildAdvisorArray() {
	Advisor none("None", "");
	Advisor rafiki("Rafiki", "Invisibility");
	Advisor nala("Nala", "Night Vision");
	Advisor sarabi("Sarabi", "Energy Manipulation");
	Advisor zazu("Zazu", "Weather Control");
	Advisor sarafina("Sarafina", "Super Speed");

	vector<Advisor> advisors = {
		none,
		rafiki,
		nala,
		sarabi,
		zazu,
		sarafina
	};

	return advisors;
}
