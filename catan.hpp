//michaeldadush12@gmail.com
//Michael dadush

#ifndef CATAN_H
#define CATAN_H
#include <vector>
#include <iostream>
#include <string>
#include "player.hpp"

#include "VictoryCard.hpp"
#include "Knight.hpp"
#include "MonopolyCard.hpp"
#include "BuildRoadCard.hpp"
#include "YearOfPlentyCard.hpp"
#include "DevelopmentCard.hpp"
using std::cout;
using std::endl;


namespace ariel{
    class Catan
    { 
        private:
            vector<Player*> players;
             Board board;
             vector<Card*> cardDeck;
            

        public:

            Catan( Player& p1,Player& p2, Player& p3): players{&p1,&p2,&p3}         
            { 
                 // Add different types of cards to the deck
                cardDeck.push_back(new VictoryCard("VictoryCard"));
                cardDeck.push_back(new VictoryCard("VictoryCard"));
                cardDeck.push_back(new VictoryCard("VictoryCard"));
                cardDeck.push_back(new VictoryCard("VictoryCard"));
                cardDeck.push_back(new Knight("knightCard"));
                cardDeck.push_back(new Knight("knightCard"));
                cardDeck.push_back(new Knight("knightCard"));
                cardDeck.push_back(new MonopolyCard("MonopolyCard"));
                cardDeck.push_back(new MonopolyCard("MonopolyCard"));
                cardDeck.push_back(new BuildRoadCard("build_road_Card"));
                cardDeck.push_back(new BuildRoadCard("build_road_Card"));
                cardDeck.push_back(new YearOfPlentyCard("YearOfPlentyCard"));
                cardDeck.push_back(new YearOfPlentyCard("YearOfPlentyCard"));
            
                board=Board();
             
            }

    
            void ChooseStartingPlayer();

            Board& getBoard() ;
            void trade(Player* wanna_replace,Player* wanna_give,int replace_resource ,int give_resource);
            void rollDice();

            vector<Player*>& get_player()  
            {
             return players;
            }
            vector<Card*>& get_cards()
            {
              return cardDeck;
            }

           

            void printWinner();
            
         

            void diffDevelopmentCard(Player* pl,int n);
           
        
       

    };
}

#endif 
     