//michaeldadush12@gmail.com
//Michael dadush

#ifndef PLAYER_H
#define PLAYER_H


#include <vector>
#include <iostream>
#include <string>
#include <stdexcept>
#include "board.hpp"
#include "card.hpp"




using std::string;
using std::cout;
using std::endl;


static int num_id=100;

namespace ariel{
    class Player{

    
     public:
        Player(const string& name) : name(name)
        {
            id_player=num_id;
            num_id++;
            resource.resize(6,0);
            card_of_player.resize(5);
            point=0;
           
            //cout << "Player was create with name  " << name <<" with id "<<id_player<< endl;
            

        }

        ~Player()
        {
          num_id=100;
        }
        
       
    
        const string& getName() const 
        { 
            return name; 
        }

     
        

        void placeSettelemnt(Board& board , int a);
        void placeRoad(Board& board,int a,int b);
        
      
        
        void buyDevelopmentCard(Card* card);
        void printPoints();
        void two_round_init(Board& borad, int x,int y);
       
        int get_id() const
        {
          return id_player;
        }

       

        int get_point() const
        {
            return point;
        }

        void set_point(int p)
        {
            point=p+point;
        }
        
        vector<int>& getres()  
        {
            return resource;
        }

        void print_resource()const
        {
           cout<<"WOOD:"<<resource[0]<<"   " <<"IRON:"<<resource[1]<<"  "<<"SHEEP:"<<resource[2]<<"   ";
           cout<<"WHEAT:"<<resource[3]<<"   "<<"BRICK:"<<resource[4]<<"   "<<"DESERT:"<<resource[5]<<"   "<<endl;
        }
        


        void set_res(int y,int x)
        {  if(y>6)
            {
                throw std::string("Cant be more then 6 cells in this array ");
            }

            resource[y]=resource[y]+x;
        }
        
        const std::vector<int>& getCards() const 
        {
         return card_of_player;
        }

         void setCards(int index,int num)  
        {
         card_of_player[index]=card_of_player[index]-num;
        }


     




    private:
        string name;
        int point;
        int id_player;
        vector<int> resource;
        vector<int> card_of_player;
       
        
        

       
   
   
   
   
   
   
    };


}
#endif 