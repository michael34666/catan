//michaeldadush12@gmail.com
//Michael dadush


#include "card.hpp"
using namespace ariel;
using std::string;
#include <iostream>


class Knight : public Card 
{
    public:
        // Constructor
        Knight(const string& card_name) : Card(card_name) {}

        // Override the pure virtual function
        void use_flag() override 
        {
            std::cout << " Knight Card is use: " << Type_of_Card() << std::endl;
            
        }
};