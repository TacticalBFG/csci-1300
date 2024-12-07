#pragma once
#include <string>
#include <vector>

using namespace std;

class Advisor
{
private:
	string name;
	string ability;

public:
	string getName() const;
	string getAbility() const;

	void printStats();

	Advisor();
	Advisor(string, string);
};
