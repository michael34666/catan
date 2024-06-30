//michaeldadush12@gmail.com
//Michael dadush

#include "catan.hpp"
#include "player.hpp"
#include <iostream>
using namespace std;

using namespace ariel;

void Catan::ChooseStartingPlayer()
{   
    std::cout<<"The beginner is p1 and his name is: "<<players[0]->getName()<<std::endl;
   
    
    if(players.size()!=3)
    {
     throw std::string("There is only 3 players in The game");
    }
}

void Catan::rollDice()
{


 
    int result_dice=rand() % 6 +1 + rand() %6 + 1;
    cout<<"Now u rolled :"<<result_dice<<endl;
    

    if (result_dice == 7) {
        for (int j = 0; j < 3; j++) { 
          
            int totalResources = 0;

            // Calculate total resources for the current player
            for (int i = 0; i < 5; i++) 
            {
                totalResources += get_player()[j]->getres()[i];
            }

            // Check if player has more than 7 resources
            if (totalResources > 7) 
            {
                int halfResources = totalResources / 2;

                
                for (int z = 0; z < 5 && halfResources > 0; z++) 
                {
                  int currentResources = get_player()[j]->getres()[z];//how muck reaource in specific cell
                  int removeAmount = (currentResources + 1) / 2; // Remove half, rounding up
                  removeAmount = std::min(removeAmount, halfResources);//who prefer to remove
                  get_player()[j]->set_res(static_cast<ResourceType>(z), -(currentResources - removeAmount));
                  halfResources -= removeAmount;
                    
                }
            }
        }
    }

   else{
    
    for(size_t i=0;i<55;i++)
    {
      for(size_t j=0;j<3;j++)
      { 
        if((board.get_borad()[i][j]).second == result_dice)
        { 
           
           int game_state = board.get_game()[i][i];
                    
                    switch (game_state) 
                    {   
                        case 100:
                            get_player()[0]->set_res(board.get_borad()[i][j].first, 1);
                            cout <<get_player()[0]->getName()<< " gets one card in type:" <<board.get_borad()[i][j].first  << endl;
                            break;
                        
                        case 101:
                            get_player()[1]->set_res(board.get_borad()[i][j].first, 1);
                            cout <<get_player()[1]->getName()<< " gets one card in type:" <<board.get_borad()[i][j].first  << endl;
                            break;
                        
                        case 102:
                            get_player()[2]->set_res(board.get_borad()[i][j].first, 1);
                             cout <<get_player()[2]->getName()<< " gets one card in type:" <<board.get_borad()[i][j].first  << endl;
                            break;
                        
                        case 200:
                            get_player()[0]->set_res(board.get_borad()[i][j].first, 2);
                             cout <<get_player()[0]->getName() <<" gets two card in type:" <<board.get_borad()[i][j].first  << endl;
                            break;
                        
                        case 202:
                            get_player()[1]->set_res(board.get_borad()[i][j].first, 2);
                             cout <<get_player()[1]->getName()<< " gets two card in type:" <<board.get_borad()[i][j].first  << endl;
                            break;
                        
                        case 204:
                            get_player()[2]->set_res(board.get_borad()[i][j].first, 2);
                             cout <<get_player()[2]->getName()<< " gets two card in type:" <<board.get_borad()[i][j].first  << endl;
                            break;
                        
                        default:
                            break;
                    }
        
        }
      }
    }
   }  
}

Board& Catan::getBoard() 
{
 return board;
}

void Catan::diffDevelopmentCard(Player* pl,int n) //the player send valid number
{ 
              
        
  if(pl->getCards()[n]==0)
  {
    throw std::string("There is no card from type n");
  }
   
  if(n==0)
  { 
    pl->set_point(1);

   
  }
  if(n==1)
  {
   if(pl->getCards()[n]==3)
   {
    
    pl->set_point(2);
  
    cout<<"The number of point +2"<<endl;
   
   }
   else
   {
     throw std::string("There is no 3  Knight card");
   }
  }
  if(n==2)
  {
    int random_number = std::rand() % 6;
    
    if(pl->get_id()==players[0]->get_id())
    {   
        random_number = std::rand() % 6;
        int count_card1=players[1]->getres()[random_number];
        int count_card2=players[1]->getres()[random_number];
        players[1]->set_res(random_number,-count_card1);
        players[2]->set_res(random_number,-count_card2);
        players[0]->set_res(random_number,count_card1+count_card2);
        
    }

     if(pl->get_id()==players[1]->get_id())
    {   
        random_number = std::rand() % 6;
        int count_card1=players[0]->getres()[random_number];
        int count_card2=players[2]->getres()[random_number];
        players[0]->set_res(random_number,-count_card1);
        players[2]->set_res(random_number,-count_card2);
        players[1]->set_res(random_number,count_card1+count_card2);
        
    }
     if(pl->get_id()==players[2]->get_id())
    {   
        random_number = std::rand() % 6;
        int count_card1=players[0]->getres()[random_number];
        int count_card2=players[1]->getres()[random_number];
        players[0]->set_res(random_number,-count_card1);
        players[1]->set_res(random_number,-count_card2);
        players[2]->set_res(random_number,count_card1+count_card2);
        
    }
   
   
  }
    if(n==3)//build_road_Card
  {
    pl->set_res(0,2);//add one wood card to resource vector
    pl->set_res(4,2);//add one BRICK card to resource vector
    
    
  }
    if(n==4) //YearOfPlentyCard
  {
    int random_number = std::rand() % 6;
    int random_number1 = std::rand() % 6;
    pl->set_res(random_number,2);//add one randome card  to resource vector
    pl->set_res(random_number1,2);//add one randome card to resource vector
    
  }

 pl->setCards(n,-1); //use the card
 
}



void Catan::printWinner()
{
if(players[2]->get_point()>=10)
 {
    cout<<"The winners is: "<<players[2]->getName()<<std::endl;
    return;
 }
 
if(players[1]->get_point()>=10)
 {
    cout<<"The winners is: "<<players[1]->getName()<<std::endl;
    return;
 }

 if(players[0]->get_point()>=10)
 {
    cout<<"The winners is : "<<players[0]->getName()<<std::endl;
    return;
 }

 cout<<"There is no winners in the game"<<endl;
}

void Catan::trade(Player* p_one,Player* p_two,int p_one_res ,int p_two_res)//p_one_res and p_two_res its what i want to replace
{
  if(p_one->get_id()==p_two->get_id())
  {
   throw std::string("You cant reaplace from you");
  }
  if(p_one_res<0||p_one_res>4)
  {
    throw std::string("You cant reaplace becuse you dont have resoucre card in type replace_resource ");
  }
  if(p_two_res<0||p_two_res>4)
  {
    throw std::string("You cant reaplace becuse you dont have resoucre card in type give_resource ");
  }

  p_one->set_res(p_one_res,-1);
  p_two->set_res(p_one_res,1);
  
  p_two->set_res(p_two_res,-1);
  p_one->set_res(p_two_res,1);
  cout<<"The trade is going well between 2 player: "<<p_one->getName();
  cout<<" and " <<p_two->getName()<<endl;
  
  


}