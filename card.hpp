//michaeldadush12@gmail.com
//Michael dadush

#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>
 using std::string;

using namespace std;

namespace ariel 
{

    class Card {
    private:
      string type;
      
    public:
        // Pure virtual function -abstract function
        virtual void use_flag()   = 0;

        // Member function to get the type of card
        string Type_of_Card() const 
        {
            return type;
        }
        // Constructor
        Card(const std::string& car) : type(car) {}
    };

}

#endif
