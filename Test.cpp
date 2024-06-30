//206917908
//michaeldadush12@gmail.com
//Michael dadush

#include "doctest.h"
#include "board.hpp"
#include "catan.hpp"
#include "player.hpp"

#include <sstream>  
#include <iostream>
#include <vector>
using namespace std;
using namespace ariel;
using std::vector;

//player test

    TEST_CASE("Player - getName/set_res/get_id/getres")
    {
        //Test player creation and ID assignment
        Player p1("Michael");
        Player p2("Rony");
        Player p3("Liat");
        Catan game(p1, p2, p3);
        
        CHECK(p1.getName() == "Michael");
        CHECK(p1.get_id() ==100);
        CHECK_FALSE(p1.get_id() == 101); // Assuming num_id starts from 0
    

        //"Test resource management"
         
        p2.set_res(0, 5); 
        vector<int>& resources = p2.getres();
        CHECK(resources.size() == 6); 
        CHECK(resources[0] == 5); 
        
        // Test throwing exception for invalid resource index
        CHECK_THROWS_AS(p2.set_res(10, 3), std::string); 
       
         
         game.get_player()[0]->set_res(ResourceType::BRICK, 8);
        
         
         // CHECK that player 1's resources are reduced appropriately
         CHECK(game.get_player()[0]->getres()[BRICK] == 8);

         
         
    }

     TEST_CASE("Player -two_round_init")
    {
        Player p1("Michael");
        Player p2("Rony");
        Player p3("Liat");
        Catan game(p1, p2, p3);
        p1.two_round_init(game.getBoard(),3,4);
        p2.two_round_init(game.getBoard(),10,11);
        CHECK_THROWS( p3.two_round_init(game.getBoard(),10,11));
        CHECK(p2.get_point()==1);
      

    }

    TEST_CASE("Player-get and set point") 
    {
        Player p1("Michael");
        Player p2("Rony");
        Player p3("Liat");
        Catan game(p1, p2, p3);
        CHECK(p1.get_point()==0);
        p1.set_point(2);
        CHECK(p1.get_point()==2);
        CHECK_FALSE(p1.get_point()==0);
        p3.set_point(8);
        CHECK(p3.get_point()==8);
        
   }


    TEST_CASE("Player-placeRoad") 
    {
       Player p1("Michael");
       Player p2("Rony");
       Player p3("Liat");
       Catan game(p1, p2, p3);

        // Set the resources required to build a road
        p1.set_res(0, 1); // Set 1 wood
        p1.set_res(4, 1); // Set 1 brick
        p1.two_round_init(game.getBoard(),1,2);
        
        std::stringstream newBuffer; 
        std::streambuf* originalBuffer = cout.rdbuf(newBuffer.rdbuf());
        // Place the road
        p1.placeRoad(game.getBoard(), 2, 3); 
        std::string buf_data = newBuffer.str();
        CHECK(buf_data == "Michael :build a road and give one wood either one brick\n");
        cout.rdbuf(originalBuffer);
        
       
        newBuffer.str(""); 
        
        

        // Check the board state and player's resources after placing the road
        CHECK(p1.getres()[0] == 0); // The wood resource should be consumed
        CHECK_FALSE(p1.getres()[4] == 1); // The brick resource should be consumed
        // Set the resources required to build a road
        p2.set_res(0, 1); // Set 1 wood
        p2.set_res(4, 1); // Set 1 brick
        CHECK_THROWS( p2.placeRoad(game.getBoard(), 1, 2));
        
        
    }

   
TEST_CASE("Player-place Settlement and City") 
{
    
    SUBCASE("Player-Initial placement of settlements") 
    {

        Player p1("Michael");
        Player p2("Rony");
        Player p3("Liat");
        Catan game(p1, p2, p3); // Assuming the game constructor takes a board as a parameter

        p1.set_res(WOOD, 3);
        p1.set_res(BRICK, 3);
        p1.set_res(WHEAT, 1);
        p1.set_res(SHEEP, 1);
        
        p1.two_round_init(game.getBoard(),1,2);
        p1.two_round_init(game.getBoard(),2,3);
        

        // Placing a settlement
        p1.placeSettelemnt(game.getBoard(), 3);
        CHECK(game.getBoard().get_game()[3][3] == p1.get_id());
    }

    SUBCASE("Player-settlements to cities") 
    {

        Player p1("Michael");
        Player p2("Rony");
        Player p3("Liat");
        Catan game(p1, p2, p3);

     
        // Setting up the initial resources for the players
        p2.set_res(WOOD, 3);
        p2.set_res(BRICK, 3);
        p2.set_res(WHEAT, 4);
        p2.set_res(SHEEP, 2);
        p2.set_res(IRON, 3);
        
        p2.two_round_init(game.getBoard(),33,34);
        p2.two_round_init(game.getBoard(),41,34);
        

        
        p2.placeSettelemnt(game.getBoard(), 41);//build city
        CHECK(game.getBoard().get_game()[41][41] == 2 * p2.get_id()); // Check if city is placed correctly
    
    
    }

    SUBCASE("Player- Invalid placement of settlements because another player build ") 
    {   
        Player p1("Michael");
        Player p2("Rony");
        Player p3("Liat");
        Catan game(p1, p2, p3);

        // Setting up the initial resources for the players
        p3.set_res(WOOD, 3);
        p3.set_res(BRICK, 3);
        p3.set_res(WHEAT, 2);
        p3.set_res(SHEEP, 1);

        p3.two_round_init(game.getBoard(),3,12);
        p3.two_round_init(game.getBoard(),13,12);

        
        // Setting up another player's resources for the same vertex
        p2.set_res(WOOD, 3);
        p2.set_res(BRICK, 3);
        p2.set_res(WHEAT, 2);
        p2.set_res(SHEEP, 1);

        

        CHECK_THROWS_AS(p2.two_round_init(game.getBoard(),3,12), std::string); 
        CHECK_THROWS_AS( p2.two_round_init(game.getBoard(),13,12), std::string);
    }

    SUBCASE("Player- Invalid buy to settlemrnt without resources") 
    {
         

    // Creating player objects
    Player p1("Michael");
    Player p2("Rony");
    Player p3("Liat");

    // Creating the game object with the players
    Catan game(p1, p2, p3);


    p3.two_round_init(game.getBoard(),3,12);
    p3.two_round_init(game.getBoard(),13,12);
    
    p3.set_res(WOOD, -3);
    p3.set_res(BRICK, 3);
   
    // Placing a settlement for player p3
    CHECK_THROWS_AS(p3.placeSettelemnt(game.getBoard(), 13), std::string);
    
    }

    
}


    TEST_CASE("Player- Buy Development Card")
    {
        Player p1("Michael");
        Player p2("Rony");
        Player p3("Liat");
        Catan game(p1, p2, p3);
        p3.set_res(1,1) ;
        p3.set_res(2,1) ;
        p3.set_res(3,1) ;

        std::stringstream newBuffer; 
        std::streambuf* originalBuffer = cout.rdbuf(newBuffer.rdbuf());

        // Place the road
        p3.buyDevelopmentCard(game.get_cards()[3]);
        std::string buf_data = newBuffer.str();
        CHECK(buf_data=="Buy Development Card and give one wheat one iron and one brick\n");
        CHECK(buf_data=="build_road_Card : number of card increas by 1\n");

        cout.rdbuf(originalBuffer);
        newBuffer.str("");  

    }

    TEST_CASE("Player-print points")
    {
        Player p1("Michael");
        Player p2("Rony");
        Player p3("Liat");
        Catan game(p1, p2, p3);
        std::stringstream newBuffer; 
        std::streambuf* originalBuffer = cout.rdbuf(newBuffer.rdbuf());
        std::string buf_data = newBuffer.str();
        p1.printPoints();
        CHECK(buf_data == "player Michael has 3 points in the game\n");
        p2.printPoints();
        CHECK(buf_data == "player Rony has 1 points in the game\n");
        p3.printPoints();
        CHECK(buf_data == "player Liat has 8 points in the game\n");
        
        cout.rdbuf(originalBuffer);
        newBuffer.str(""); 
    }

   TEST_CASE("Player-print resource")
   {
        Player p1("Michael");
        Player p2("Rony");
        Player p3("Liat");
        Catan game(p1, p2, p3);


        std::stringstream newBuffer; 
        std::streambuf* originalBuffer = cout.rdbuf(newBuffer.rdbuf());
        std::string buf_data = newBuffer.str();
        p3.printPoints();
        CHECK(buf_data == "WOOD:0   IRON:0  SHEEP:0   WHEAT:0   BRICK:0   DESERT:0 \n");
        p3.set_res(0,100);
        p3.set_res(3,10);
        p3.printPoints();
        CHECK(buf_data == "WOOD:100   IRON:0  SHEEP:0   WHEAT:10   BRICK:0   DESERT:0 \n");
        cout.rdbuf(originalBuffer);
        
        newBuffer.str(""); 
   

   }

   TEST_CASE("Player-get and set card")
   {    Player p1("Michael");
        Player p2("Rony");
        Player p3("Liat");
        p2.setCards(2,-2);//-(-2) in setcard
        CHECK(p2.getCards()[2]==2);
        CHECK_FALSE(p3.getCards()[3]==2);
   }

     




TEST_CASE("Catan") 
{ 

    SUBCASE("Catan-Catan builder")
    {   
        Player p1("Michael");
        Player p2("Rony");
        Player p3("Liat");
        Catan game(p1, p2, p3);
        CHECK(game.get_cards().size()==13);
    
    }


    SUBCASE("Catan-Choose Starting Player")
    {
        Player p1("Michael");
        Player p2("Rony");
        Player p3("Liat");
        Catan game(p1, p2, p3);
        std::stringstream newBuffer; 
        std::streambuf* originalBuffer = cout.rdbuf(newBuffer.rdbuf());
        std::string buf_data = newBuffer.str();
        game.ChooseStartingPlayer();
        CHECK(buf_data == "The beginner is p1 and his name is: Michael\n");
        cout.rdbuf(originalBuffer);
        
        newBuffer.str(""); 

    }

    SUBCASE("Catan-getBoard")
    {
        // Creating player objects
        Player p1("Michael");
        Player p2("Rony");
        Player p3("Liat");

        // Creating the game object with the players
        Catan game(p1, p2, p3);

        // Get a reference to the board using getBoard
        Board& boardRef = game.getBoard();

        // Check that the returned reference is valid
        CHECK(&boardRef != nullptr); // Check that the reference is not null


    }

}


  TEST_CASE("Catan-trade") 
  {
    Player p1("Michael");
    Player p2("Rony");
    Player p3("Liat");

    // Initialize players with some resources
    p1.set_res(WOOD, 3);
    p1.set_res(BRICK, 3);
    p1.set_res(WHEAT, 3);
    p1.set_res(SHEEP, 3);

    p2.set_res(WOOD, 2);
    p2.set_res(BRICK, 2);
    p2.set_res(WHEAT, 2);
    p2.set_res(SHEEP, 2);

    Catan game(p1, p2, p3);

    SUBCASE("Valid trade between two different players")
     {
        
        std::stringstream newBuffer; 
        std::streambuf* originalBuffer = cout.rdbuf(newBuffer.rdbuf());
        std::string buf_data = newBuffer.str();
        game.trade(&p1, &p2, WOOD, BRICK);
        CHECK(buf_data == "The trade is going well between 2 player: Michael and Rony\n");
        cout.rdbuf(originalBuffer);
        
        newBuffer.str("");


        CHECK(p1.getres()[WOOD] == 2);
        CHECK(p1.getres()[BRICK] == 4);
        CHECK(p2.getres()[WOOD] == 3);
        CHECK(p2.getres()[BRICK] == 1);
    }

    SUBCASE("Invalid trade - same player") 
    {
        

        std::stringstream newBuffer; 
        std::streambuf* originalBuffer = cout.rdbuf(newBuffer.rdbuf());
        std::string buf_data = newBuffer.str();
        game.trade(&p1, &p1, WOOD, BRICK);
        CHECK(buf_data == "You cant reaplace from you\n");
        cout.rdbuf(originalBuffer);
        
        newBuffer.str(""); 
       
    }

    SUBCASE("Invalid trade - player one resource out of bounds") 
    {
        // Trying to trade with an invalid resource type for player one
        CHECK_THROWS_AS(game.trade(&p1, &p2, -1, BRICK), std::string);
        CHECK_THROWS_AS(game.trade(&p1, &p2, 5, BRICK), std::string);
    }

    SUBCASE("Invalid trade - player two resource out of bounds") 
    {
        // Trying to trade with an invalid resource type for player two
        CHECK_THROWS_AS(game.trade(&p1, &p2, WOOD, -1), std::string);
        CHECK_THROWS_AS(game.trade(&p1, &p2, WOOD, 5), std::string);
    }
}


    TEST_CASE("Catan-get_player")
    {
        Player p1("Michael");
        Player p2("Rony");
        Player p3("Liat");
        Catan game(p1, p2, p3);
        SUBCASE("Get list of players")
         {
          std::vector<Player*>& players = game.get_player();

        // Check if the players vector has the correct size
        CHECK(players.size() == 3);

        // Check if the players' names are correct
        CHECK(players[0]->getName() == "Michael");
        CHECK(players[1]->getName() == "Rony");
        CHECK_FALSE(players[2]->getName() == "SHAY");
    }
}

TEST_CASE("Catan-get_cards") 
{
        Player p1("Michael");
        Player p2("Rony");
        Player p3("Liat");
        Catan game(p1, p2, p3);

    SUBCASE("Get list of cards") 
    {
        std::vector<Card*>& cards = game.get_cards();

        // Check if the cards vector has the correct size
        CHECK(cards.size() == 13);

        // Check if the cards' names and types are correct
        CHECK(dynamic_cast<VictoryCard*>(cards[0])->Type_of_Card() == "VictoryCard");
        

        CHECK(dynamic_cast<Knight*>(cards[4])->Type_of_Card() == "knightCard");
        

        CHECK(dynamic_cast<MonopolyCard*>(cards[7])->Type_of_Card() == "MonopolyCard");
        CHECK(dynamic_cast<MonopolyCard*>(cards[8])->Type_of_Card() == "MonopolyCard");

        CHECK_FALSE(dynamic_cast<BuildRoadCard*>(cards[9])->Type_of_Card() == "MonopolyCard");
        

 
    }
}


TEST_CASE("Catan-diffDevelopmentCard") 
{
    Player p1("Michael");
    Player p2("Rony");
    Player p3("Liat");
    Catan game(p1, p2, p3);

    // Set initial cards to players for testing
    p1.setCards(0, 1); // 1 VictoryCard
    p1.setCards(1, 3); // 3 KnightCards
    p2.setCards(2, 1); // 1 MonopolyCard
    p3.setCards(3, 1); // 1 BuildRoadCard
    p3.setCards(4, 1); // 1 YearOfPlentyCard

    SUBCASE("Use Victory Card") 
    {
        game.diffDevelopmentCard(&p1, 0);
        CHECK(p1.get_point() == 1);
    }

    SUBCASE("Use Knight Card with sufficient Knight cards")
     {
        game.diffDevelopmentCard(&p1, 1);
        CHECK(p1.get_point() == 2);
    }

    SUBCASE("Use Monopoly Card") 
    {
        p1.set_res(0, 3); // Give some resources to p1
        p2.set_res(0, 3); // Give some resources to p2
        game.diffDevelopmentCard(&p2, 2);
        CHECK(p2.getres()[0] == 6); // p2 should now have all the resources
        CHECK(p1.getres()[0] == 0); // p1 should have no resources
    }

    SUBCASE("Use Build Road Card") 
    {
        int initial_wood = p3.getres()[0];
        int initial_brick = p3.getres()[1];
        game.diffDevelopmentCard(&p3, 3);
        CHECK(p3.getres()[0] == initial_wood + 2); // Wood should increase by 2
        CHECK(p3.getres()[1] == initial_brick + 2); // Brick should increase by 2
    }

    SUBCASE("Use Year of Plenty Card") 
    {
        int initial_resources[5];
        for (int i = 0; i < 5; ++i) 
        {
            initial_resources[i] = p3.getres()[i];
        }

        game.diffDevelopmentCard(&p3, 4);
        bool resources_increased = false;
        for (int i = 0; i < 5; ++i) 
        {
            if (p3.getres()[i] > initial_resources[i])
             {
                resources_increased = true;
                break;
            }
        }
        CHECK(resources_increased == true); // Check if at least one resource type has increased
    }
}
 



//board test
TEST_CASE("Board initialization and access") 
{
    
    Board board;

    SUBCASE("Check initial game board dimensions") 
    {
        const auto& game_board = board.get_game();
        CHECK(game_board.size() == 55);
        CHECK(game_board[0].size() == 55);
    }

    SUBCASE("Check initial board configuration") 
    {
        const auto& boardd = board.get_borad();
        CHECK(boardd.size() == 55);
        CHECK(boardd[0].size() == 3);
    }

    
}


