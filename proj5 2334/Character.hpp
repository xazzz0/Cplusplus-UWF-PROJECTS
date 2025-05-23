#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include <iostream>
#include <vector>


class Character {
private:
    std::string name;
    int health;
    std::vector<std::string> items;
    int x_coord;
    int y_coord;
    void Load_From_CSV(const std::string& FILENAME);
    void Tokenize_Line(); // Splits a given line from the CSV file into its component tokens (key and value parts)
public:
    Character(); // Default constructor
    Character(int health, int x, int y, const std::string& name) : health(health), x_coord(x), y_coord(y), name(name) {} // Parameterized constructor
    void Display_Player(); //Returns a string with the character's details (name, health, items, coordinates) in a clear format
    std::string FILENAME = "character.csv";
};

#endif 