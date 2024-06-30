 //michaeldadush12@gmail.com
//Michael dadush
 #include "card.hpp"
 using namespace ariel;
using std::string;
#include <iostream>

 



class BuildRoadCard : public Card 
{
    public:
        
        BuildRoadCard(const string& card_name) : Card(card_name) {}

        // Override use_card function
        void use_flag() override 
        {
            std::cout << " Build Road Card is use: " << Type_of_Card() << std::endl;
            
        }
};