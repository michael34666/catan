 //michaeldadush12@gmail.com
//Michael dadush
 
 #include "card.hpp"
 using namespace ariel;
using std::string;
#include <iostream>


class DevelopmentCard : public Card 
{
    public:
        // Constructor
        DevelopmentCard(const string& card_name) : Card(card_name) {}

        // Pure virtual function for using the card
        virtual void use_card() = 0;
};