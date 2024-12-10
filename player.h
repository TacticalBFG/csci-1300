/*
    Changed "getboardc" to getLand, makes more lexical sense and is easier to read
    Added things for advisor and position
*/

#include <iostream>
using namespace std;


#ifndef PLAYER_h
#define PLAYER_h

//change theme
class players{
    public:
    players();
    players(string name, int strength, int stamina, int wisdom);
    string getName();
    int getStrength() const;
    int getStamina() const;
    int getWisdom() const;
    int getPridePoints() const;
    int getAge() const;
    int getPosition(); // Added getPosition
    int getAdvisor(); // Moved getAdvisor
    int getLand(); // Added getLand
    int getCharacter(); // Added getCharacter

    void setName(string name);
    void setStrength(int strength);
    void setStamina(int stamina);
    void setWisdom(int wisdom);
    void setPridePoints(int pride_points);
    void setAge(int age);
    void setPosition(int position); // Added setPosition
    void setAdvisor(int advisor); // Moved setAdvisor
    void setLand(int land); // Added setLand
    void setCharacter(int character); // Added setCharacter

    void addStrength(int strength);
    void addStamina(int stamina);
    void addWisdom(int wisdom);
    void addPridePoints(int pride_points);
    void addAge(int age);
    void addPosition(int position); // Added addPosition

    void trainCub(int strength, int stamina, int wisdom);
    void toPrideLands();
    void printStats();

    int getboardIndex();
    int getboardOptions();
    void setboardOptions(int board);
    int getAdvisorChoice(); 
    
    int getboardc();
    void trainCub();
    int player();
    
    
  
    int play;

    
private:
    string _Name;
    int _Strength;
    int _Stamina;
    int _Wisdom;
    int _Pride_points;
    int _Age;
    int _Position; // Added position
    int _Advisor; // Added advisor
    int _Land;
    int _Character; // Added character
    int boardOptions;
    
    

};

#endif