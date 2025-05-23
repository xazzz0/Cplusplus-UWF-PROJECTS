#include "Character.hpp"
#include <fstream>
#include <sstream>
#include <iomanip>

Character::Character() : health(0), x_coord(0), y_coord(0), name("") {}

Character::Character(int health, int x, int y, const std::string& name)
    : health(health), x_coord(x), y_coord(y), name(name) {}

/**
 * @brief Loads character data from a CSV file.
 * 
 * This function reads a CSV file from input and gives the character's attributes values.abort
 * 
 * @param FILENAME The name of the CSV file to load data from.
 * 
 * @return void
 */

void Character::Load_From_CSV(const std::string& FILENAME) {

}
/**
 * @brief Tokenizes a line from the CSV file.
 * 
 * This function splits a line into key-value pairs and assigns them to the character's attributes.
 * 
 * @return void
 */

void Character::Tokenize_Line() {

    }

/**
 * @brief Displays the character details.
 * 
 * This function prints the character's name, health, coordinates, and items to the console.
 * 
 * @return void
 */

