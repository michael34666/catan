# Catan Board Game Implementation

This repository contains the implementation of a board game inspired by Catan, using C++. The main components include the Board class, the Cell struct, the ResourceType enum, the Card clas sand its derived classes,, and the Player class, all of which are part of the ariel namespace.

# Overview

The project focuses on representing a game board, managing game states, player interactions, and handling various cards used in the game. The board is a 55x55 grid where each cell can have a specific resource type and a corresponding value.

# Files

catan.hpp: Contains the declarations and definitions of the Board class, Cell struct, and ResourceType enum.
card.hpp: Contains the declaration and definition of the Card class.
player.hpp: Contains the declaration and definition of the Player class.
main.cpp: Example usage of the classes (not provided here).
Classes and Enums

ResourceType Enum
The ResourceType enum defines the types of resources that can be found on the game board:

* WOOD
* IRON
* SHEEP
* WHEAT
* BRICK
* DESERT
Cell Struct
The Cell struct represents a single cell on the board. It contains two members:

first: The resource type (ResourceType)
second: The value associated with the resource

# Board Class
The Board class manages the game board. It includes the following members and methods:

Members

game: A 55x55 grid of integers representing the game state.
board: A 55x55 grid of Cell structs representing the resource and value of each cell.
Methods

Constructor Board(): Initializes the game board and sets up the initial state.
get_game() const: Returns a constant reference to the current game state.
get_board() const: Returns a constant reference to the resource board.
set_game(int x, int y, int id): Sets the value of a specific cell in the game state. Prints a message if the coordinates are out of bounds.
Private Methods

initBoard(std::vector<std::vector<int>>& game, std::vector<std::vector<Cell>>& board): Initializes the game board with predefined resource values and types.
Card Class
The Card class represents various cards that players can use during the game. Each card has a type and an associated value.

Members

type: The type of the card (e.g., resource, development).
value: The value or effect of the card.
Methods

Constructor Card(std::string type, int value): Initializes a card with a specific type and value.
getType() const: Returns the type of the card.
getValue() const: Returns the value of the card.


# Player Class
The Player class represents a player in the game. It includes the player's resources, development cards, and methods to manage these resources.

Members

resources: A map of resource types to their quantities.
devCards: A vector of development cards the player possesses.
Methods

Constructor Player(std::string name): Initializes a player with a specific name.
getName() const: Returns the player's name.
addResource(ResourceType type, int quantity): Adds a specified quantity of a resource to the player's inventory.
removeResource(ResourceType type, int quantity): Removes a specified quantity of a resource from the player's inventory.
addDevCard(const Card& card): Adds a development card to the player's collection.
getResources() const: Returns the player's resources.
getDevCards() const: Returns the player's development cards.

# Card Class
The Card class represents various cards that players can use during the game. It serves as a base class for specific types of cards.

Members

type: The type of the card (e.g., resource, development).
value: The value or effect of the card.
Methods

Constructor Card(std::string type, int value): Initializes a card with a specific type and value.
Type_of_Card() const: Returns the type of the card.
use_flag() const: Returns the value of the card.
# Derived Card Classes
Several specific types of cards inherit from the Card class. These include:

* VictoryCard: Represents a victory point card.
* Knight: Represents a knight card, used for moving the robber.
* MonopolyCard: Allows a player to claim all resources of a specific type from other players.
* BuildRoadCard: Allows a player to build two roads without using resources.
* YearOfPlentyCard: Allows a player to take two resources of their choice from the bank.