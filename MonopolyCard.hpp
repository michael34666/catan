 //michaeldadush12@gmail.com
//Michael dadush

 #include "card.hpp"
 using namespace ariel;
using std::string;
#include <iostream>

 
 class MonopolyCard : public Card 
 {
    public:
        // Constructor
        MonopolyCard(const string& card_name) : Card(card_name) {}

        // Override use_card function
        void use_flag() override 
        {
            std::cout << " Monopoly Card is use: " << Type_of_Card() << std::endl;
            
        }
    };