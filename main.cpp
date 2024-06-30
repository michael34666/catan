//michaeldadush12@gmail.com
//Michael dadush

#include "board.hpp"
#include "catan.hpp"
#include "player.hpp"
#include <iostream>
#include <vector>
using std::vector;

using namespace ariel;

int main()
{
    Player p1("Michael");
    Player p2("Rony");
    Player p3("Shay");

     
    
    
    Catan play(p1,p2,p3);
    
    play.ChooseStartingPlayer();
    
    
    
    
        p1.two_round_init(play.getBoard(),23,25);
        p1.print_resource();
        p2.two_round_init(play.getBoard(),8,24);
        p2.print_resource();
        p3.two_round_init(play.getBoard(),10,11);
        p3.print_resource();
        p3.two_round_init(play.getBoard(),33,34);
        p3.print_resource();
        p2.two_round_init(play.getBoard(),12,13);
        p2.print_resource();
        p1.two_round_init(play.getBoard(),44,43);
        p1.print_resource();
    
   
        //round 3 for the players
        play.rollDice();
        p1.print_resource();
        p2.print_resource();
        p3.print_resource();
     
        play.rollDice();
        p1.print_resource();
        p2.print_resource();
        p3.print_resource();
        p2.placeRoad(play.getBoard(),13,18);

        play.rollDice();
        p1.print_resource();
        p2.print_resource();
        p3.print_resource();

        //p1
        play.rollDice();
        p1.placeRoad(play.getBoard(),42,43);
        p1.print_resource();
        p2.print_resource();
        p3.print_resource();
        p1.buyDevelopmentCard(play.get_cards()[0]);
        
        play.get_cards()[0]->use_flag();// Victory Card is used: VictoryCard
        p1.printPoints();
        play.diffDevelopmentCard(&p1,0);
        p1.printPoints();

        //p2
        play.rollDice();
        p1.print_resource();
        p2.print_resource();
        p3.print_resource();
    

    //p3
     play.rollDice();  
     p1.print_resource();
     p2.print_resource();
     p3.print_resource();
   
     
     //p1
     play.rollDice();  
     p1.print_resource();
     p2.print_resource();
     p3.print_resource();
    
     play.trade(&p1,&p3,3,0);
     play.trade(&p1,&p3,0,1);
     p1.print_resource();
     p2.print_resource();
     p3.print_resource();
     p1.placeSettelemnt(play.getBoard(),44);
    
    //p2
     play.rollDice(); 
     
     //p3
     play.rollDice(); 
    
    //p1
     play.rollDice();
     p1.print_resource();
     p2.print_resource();
     p3.print_resource();
     play.trade(&p1,&p3,3,0);
     play.trade(&p1,&p3,3,2);
     p1.placeSettelemnt(play.getBoard(),42);

    p1.printPoints();
    p2.printPoints();
    p3.printPoints();

    //p2
    play.rollDice();

    //p3
    play.rollDice();

    play.printWinner(); //There is no winners in the game
    p2.set_point(10);
   
   
    play.printWinner(); //The winners is: Rony
   

    
   
     

   
     
//    return 0;
   





}
