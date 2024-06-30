//michaeldadush12@gmail.com
//Michael dadush

#include "card.hpp"
 using namespace ariel;
using std::string;
#include <iostream>

 class VictoryCard : public Card 
 {
    public:
        VictoryCard(const string& card_name) : Card(card_name) {}
        
        void use_flag() override 
        {
            std::cout << " Victory Card is used: " << Type_of_Card() << std::endl;
        }
        

       
 };