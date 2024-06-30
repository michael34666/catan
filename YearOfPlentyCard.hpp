//michaeldadush12@gmail.com
//Michael dadush
 
#include "card.hpp"
using namespace ariel;
using std::string;
#include <iostream>

 


class YearOfPlentyCard : public Card 
{
    public:
        // Constructor
        YearOfPlentyCard(const string& card_name) : Card(card_name) {}

        // Override use_card function
        void use_flag() override 
        {
            std::cout << " Year of Plenty Cards use: " << Type_of_Card() << std::endl;
            
        }
};