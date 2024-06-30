//michaeldadush12@gmail.com
//Michael dadush

#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include <iostream>
#include <string>


using std::vector;
using std::pair;
using std::cout;
using std::endl;



 enum ResourceType { 
    WOOD, //עץ
    IRON, //סלע-הרים
    SHEEP, //כבש
    WHEAT, //חיטה
    BRICK, //-חימר
    DESERT//מדבר
}; 

struct Cell 
{
    ResourceType first;
    int second;
};

namespace ariel{

    class Board
    {
         public:
         vector<vector<int>> game;
         Board(){
            game.resize(55, vector<int>(55, 0)); // Initialize a 55x55 game board with zeros
            board.resize(55, std::vector<Cell>(3));
            

            initBoard(game,board);
      
         }
          
         const vector<vector<int>>& get_game()const
         {
            return game;
         }

         const vector<vector<Cell>>& get_borad () const {
            return board;
         }

         void set_game(int x,int y,int id)
         {
            if (x >= 0 && x < 55 && y >= 0 && y < 55) 
            {
              game[x][y]=id;
            }
            else
            {
              cout<<"The player try to build without the bound board"<<endl;

            }
         }

       

private:
void initBoard(vector<vector<int>>& game,vector<vector<Cell>>& board) { 
    
     board[1][0].first =ResourceType::IRON;
     board[1][0].second =10;
     board[1][1].first=DESERT;
     board[1][1].second=std::numeric_limits<int>::max();
     board[1][2].first=DESERT;
     board[1][2].second=std::numeric_limits<int>::max();

     board[2][0].first=ResourceType::IRON;
     board[2][0].second=10;
     board[2][1].first=DESERT;
     board[2][1].second=std::numeric_limits<int>::max();
     board[2][2].first=DESERT;
     board[2][2].second=std::numeric_limits<int>::max();

     board[3][0].first=ResourceType::IRON;
     board[3][0].second=10;
     board[3][1].first=ResourceType::SHEEP;
     board[3][1].second=2;
     board[3][2].first=DESERT;
     board[3][2].second=std::numeric_limits<int>::max();

     board[4][0].first=ResourceType::SHEEP;
     board[4][0].second=2;
     board[4][1].first=DESERT;
     board[4][1].second=std::numeric_limits<int>::max();
     board[4][2].first=DESERT;
     board[4][2].second=std::numeric_limits<int>::max();


     board[5][0].first=ResourceType::SHEEP;
     board[5][0].second=2;
     board[5][1].first=ResourceType::WOOD;
     board[5][1].second=9;
     board[5][2].first=DESERT;
     board[5][2].second=std::numeric_limits<int>::max();

     board[6][0].first=ResourceType::WOOD;
     board[6][0].second=9;
     board[6][1].first=DESERT;
     board[6][1].second=std::numeric_limits<int>::max();
     board[6][2].first=DESERT;
     board[6][2].second=std::numeric_limits<int>::max();


     board[7][0].first=ResourceType::WOOD;
     board[7][0].second=9;
     board[7][1].first=DESERT;
     board[7][1].second=std::numeric_limits<int>::max();
     board[7][2].first=DESERT;
     board[7][2].second=std::numeric_limits<int>::max();



     board[8][0].first=ResourceType::WOOD;
     board[8][0].second=9;
     board[8][1].first=ResourceType::BRICK;
     board[8][1].second=10;
     board[8][2].first=DESERT;
     board[8][2].second=std::numeric_limits<int>::max();

     board[9][0].first=ResourceType::WOOD;
     board[9][0].second=9;
     board[9][1].first=ResourceType::SHEEP;
     board[9][1].second=4;
     board[9][2].first=ResourceType::BRICK;
     board[9][2].second=10;

     board[10][0].first=ResourceType::SHEEP;
     board[10][0].second=4;
     board[10][1].first=ResourceType::SHEEP;
     board[10][1].second=2;
     board[10][2].first=ResourceType::WOOD;
     board[10][2].second=9;



     board[11][0].first=ResourceType::SHEEP;
     board[11][0].second=4;
     board[11][1].first=ResourceType::SHEEP;
     board[11][1].second=2;
     board[11][2].first=ResourceType::BRICK;
     board[11][2].second=6;


     board[12][0].first=ResourceType::IRON;
     board[12][0].second=10;
     board[12][1].first=ResourceType::BRICK;
     board[12][1].second=6;
     board[12][2].first=ResourceType::SHEEP;
     board[12][2].second=2;

     board[13][0].first=ResourceType::IRON;
     board[13][0].second=10;
     board[13][1].first=ResourceType::BRICK;
     board[13][1].second=6;
     board[13][2].first=ResourceType::WHEAT;
     board[13][2].second=12;

     board[14][0].first=ResourceType::IRON;
     board[14][0].second=10;
     board[14][1].first=ResourceType::WHEAT;
     board[14][1].second=12;
     board[14][2].first=DESERT;
     board[14][2].second=std::numeric_limits<int>::max();

     
     board[15][0].first=ResourceType::WHEAT;
     board[15][0].second=12;
     board[15][1].first=DESERT;
     board[15][1].second=std::numeric_limits<int>::max();
     board[15][2].first=DESERT;
     board[15][2].second=std::numeric_limits<int>::max();

     board[16][0].first=ResourceType::WHEAT;
     board[16][0].second=12;
     board[16][1].first=ResourceType::WHEAT;
     board[16][1].second=9;
     board[16][2].first=DESERT;
     board[16][2].second=std::numeric_limits<int>::max();
     
     board[17][0].first=ResourceType::WHEAT;
     board[17][0].second=9;
     board[17][1].first=ResourceType::WHEAT;
     board[17][1].second=12;
     board[17][2].first=ResourceType::WOOD;
     board[17][2].second=11;

     board[18][0].first=ResourceType::WHEAT;
     board[18][0].second=12;
     board[18][1].first=ResourceType::WOOD;
     board[18][1].second=11;
     board[18][2].first=ResourceType::BRICK;
     board[18][2].second=6;

     board[19][0].first=ResourceType::WOOD;
     board[19][0].second=11;
     board[19][1].first=ResourceType::BRICK;
     board[19][1].second=6;
     board[19][2].first=ResourceType::DESERT;
     board[19][2].second=0;



     board[20][0].first=ResourceType::DESERT;
     board[20][0].second=0;
     board[20][1].first=ResourceType::BRICK;
     board[20][1].second=6;
     board[20][2].first=ResourceType::SHEEP;
     board[20][2].second=4;

     board[21][0].first=ResourceType::DESERT;
     board[21][0].second=0;
     board[21][1].first=ResourceType::SHEEP;
     board[21][1].second=4;
     board[21][2].first=ResourceType::WOOD;
     board[21][2].second=3;

     board[22][0].first=ResourceType::SHEEP;
     board[22][0].second=4;
     board[22][1].first=ResourceType::WOOD;
     board[22][1].second=3;
     board[22][2].first=ResourceType::BRICK;
     board[22][2].second=10;

     board[23][0].first=ResourceType::WOOD;
     board[23][0].second=3;
     board[23][1].first=ResourceType::BRICK;
     board[23][1].second=10;
     board[23][2].first=ResourceType::IRON;
     board[23][2].second=8;

     board[24][0].first=ResourceType::BRICK;
     board[24][0].second=10;
     board[24][1].first=DESERT;
     board[24][1].second=std::numeric_limits<int>::max();
     board[24][2].first=DESERT;
     board[24][2].second=std::numeric_limits<int>::max();

     
    

     board[25][0].first=ResourceType::BRICK;
     board[25][0].second=10;
     board[25][1].first=ResourceType::IRON;
     board[25][1].second=8;
     board[25][2].first=DESERT;
     board[25][2].second=std::numeric_limits<int>::max();

     
     board[26][0].first=ResourceType::IRON;
     board[26][0].second=8;
     board[26][1].first=DESERT;
     board[26][1].second=std::numeric_limits<int>::max();
     board[26][2].first=DESERT;
     board[26][2].second=std::numeric_limits<int>::max();

     board[27][0].first=ResourceType::IRON;
     board[27][0].second=8;
     board[27][1].first=DESERT;
     board[27][1].second=std::numeric_limits<int>::max();
     board[27][2].first=DESERT;
     board[27][2].second=std::numeric_limits<int>::max();

     board[28][0].first=ResourceType::IRON;
     board[28][0].second=8;
     board[28][1].first=ResourceType::SHEEP;
     board[28][1].second=5;
     board[28][2].first=DESERT;
     board[28][2].second=std::numeric_limits<int>::max();
    

     board[29][0].first=ResourceType::IRON;
     board[29][0].second=8;
     board[29][1].first=ResourceType::SHEEP;
     board[29][1].second=5;
     board[29][2].first=ResourceType::WOOD;
     board[29][2].second=3;

     board[30][0].first=ResourceType::SHEEP;
     board[30][0].second=5;
     board[30][1].first=ResourceType::WOOD;
     board[30][1].second=3;
     board[30][2].first=ResourceType::WHEAT;
     board[30][2].second=4;

     board[31][0].first=ResourceType::WHEAT;
     board[31][0].second=4;
     board[31][1].first=ResourceType::WOOD;
     board[31][1].second=3;
     board[31][2].first=ResourceType::DESERT;
     board[31][2].second=0;

     board[32][0].first=ResourceType::DESERT;
     board[32][0].second=0;
     board[32][1].first=ResourceType::WHEAT;
     board[32][1].second=4;
     board[32][2].first=ResourceType::IRON;
     board[32][2].second=3;

     board[33][0].first=ResourceType::DESERT;
     board[33][0].second=0;
     board[33][1].first=ResourceType::IRON;
     board[33][1].second=3;
     board[33][2].first=ResourceType::WOOD;
     board[33][2].second=11;

     board[34][0].first=ResourceType::IRON;
     board[34][0].second=3;
     board[34][1].first=ResourceType::WOOD;
     board[34][1].second=11;
     board[34][2].first=ResourceType::WOOD;
     board[34][2].second=8;

     board[35][0].first=ResourceType::WOOD;
     board[35][0].second=11;
     board[35][1].first=ResourceType::WHEAT;
     board[35][1].second=9;
     board[35][2].first=ResourceType::WOOD;
     board[35][2].second=8;

     

     board[36][0].first=ResourceType::WHEAT;
     board[36][0].second=9;
     board[36][1].first=ResourceType::WOOD;
     board[36][1].second=8;
     board[36][2].first=DESERT;
     board[36][2].second=std::numeric_limits<int>::max();
    

     board[37][0].first=ResourceType::WHEAT;
     board[37][0].second=9;
     board[37][1].first=DESERT;
     board[37][1].second=std::numeric_limits<int>::max();
     board[37][2].first=DESERT;
     board[37][2].second=std::numeric_limits<int>::max();

     
     board[38][0].first=ResourceType::WHEAT;
     board[38][0].second=9;
     board[38][1].first=DESERT;
     board[38][1].second=std::numeric_limits<int>::max();
     board[38][2].first=DESERT;
     board[38][2].second=std::numeric_limits<int>::max();
     
     board[39][0].first=ResourceType::WOOD;
     board[39][0].second=8;
     board[39][1].first=DESERT;
     board[39][1].second=std::numeric_limits<int>::max();
     board[39][2].first=DESERT;
     board[39][2].second=std::numeric_limits<int>::max();
    
     board[40][0].first=ResourceType::WOOD;
     board[40][0].second=8;
     board[40][1].first=ResourceType::BRICK;
     board[40][1].second=5;
     board[40][2].first=DESERT;
     board[40][2].second=std::numeric_limits<int>::max();

     board[41][0].first=ResourceType::BRICK;
     board[41][0].second=5;
     board[41][1].first=ResourceType::WOOD;
     board[41][1].second=8;
     board[41][2].first=ResourceType::IRON;
     board[41][2].second=3;

     board[42][0].first=ResourceType::BRICK;
     board[42][0].second=5;
     board[42][1].first=ResourceType::IRON;
     board[42][1].second=3;
     board[42][2].first=ResourceType::WHEAT;
     board[42][2].second=6;

     board[43][0].first=ResourceType::IRON;
     board[43][0].second=3;
     board[43][1].first=ResourceType::WHEAT;
     board[43][1].second=4;
     board[43][2].first=ResourceType::WHEAT;
     board[43][2].second=6;

     board[44][0].first=ResourceType::WHEAT;
     board[44][0].second=6;
     board[44][1].first=ResourceType::WHEAT;
     board[44][1].second=4;
     board[44][2].first=ResourceType::SHEEP;
     board[44][2].second=11;

     board[45][0].first=ResourceType::WHEAT;
     board[45][0].second=4;
     board[45][1].first=ResourceType::SHEEP;
     board[45][1].second=11;
     board[45][2].first=ResourceType::SHEEP;
     board[45][2].second=5;

     board[46][0].first=ResourceType::SHEEP;
     board[46][0].second=5;
     board[46][1].first=ResourceType::SHEEP;
     board[46][1].second=11;
     board[46][2].first=DESERT;
     board[46][2].second=std::numeric_limits<int>::max();

     board[47][0].first=ResourceType::SHEEP;
     board[47][0].second=5;
     board[47][1].first=DESERT;
     board[47][1].second=std::numeric_limits<int>::max();
     board[47][2].first=DESERT;
     board[47][2].second=std::numeric_limits<int>::max();

     board[48][0].first=ResourceType::BRICK;
     board[48][0].second=5;
     board[48][1].first=DESERT;
     board[48][1].second=std::numeric_limits<int>::max();
     board[48][2].first=DESERT;
     board[48][2].second=std::numeric_limits<int>::max();

     board[49][0].first=ResourceType::BRICK;
     board[49][0].second=5;
     board[49][1].first=DESERT;
     board[49][1].second=std::numeric_limits<int>::max();
     board[49][2].first=DESERT;
     board[49][2].second=std::numeric_limits<int>::max();

     board[50][0].first=ResourceType::BRICK;
     board[50][0].second=5;
     board[50][1].first=ResourceType::WHEAT;
     board[50][1].second=6;
     board[50][2].first=DESERT;
     board[50][2].second=std::numeric_limits<int>::max();

     board[51][0].first=ResourceType::WHEAT;
     board[51][0].second=6;
     board[51][1].first=DESERT;
     board[51][1].second=std::numeric_limits<int>::max();
     board[51][2].first=DESERT;
     board[51][2].second=std::numeric_limits<int>::max();

     board[52][0].first=ResourceType::WHEAT;
     board[52][0].second=6;
     board[52][1].first=ResourceType::SHEEP;
     board[52][1].second=11;
     board[52][2].first=DESERT;
     board[52][2].second=std::numeric_limits<int>::max();

     board[53][0].first=ResourceType::SHEEP;
     board[53][0].second=11;
     board[53][1].first=DESERT;
     board[53][1].second=std::numeric_limits<int>::max();
     board[53][2].first=DESERT;
     board[53][2].second=std::numeric_limits<int>::max();

     board[54][0].first=ResourceType::SHEEP;
     board[54][0].second=11;
     board[54][1].first=DESERT;
     board[54][1].second=std::numeric_limits<int>::max();
     board[54][2].first=DESERT;
     board[54][2].second=std::numeric_limits<int>::max();



     

    // Initialize the board with fixed resources and numbers 
    //board ={
     //   {{IRON, 10}, {WOOL, 2}, {WOOD, 9}},
    //    {{OATS, 12}, {WHEAT, 6}, {WOOL, 4}, {WHEAT, 10}},
      //  {{OATS, 9}, {WOOD, 11}, {DESERT, 0}, {WOOD, 3}, {IRON, 8}},
     //   {{WOOD, 8}, {IRON, 3}, {OATS, 4}, {WOOL, 2} },
     //   {{WHEAT, 10}, {OATS, 2}, {WOOL, 9}}
   // };
        
    for(size_t i=0;i<=53;i++)
    {
        for(size_t j=0;j<=53;j++)
        {
          game[i][j]=0;
        }
    }
    
   game[1][2]=1;
   game[1][14]=1;
   game[2][3]=1;
   game[3][12]=1;
   game[12][13]=1;
   game[13][14]=1;
   game[3][4]=1;
   game[4][5]=1;
   game[5][10]=1;
   game[10][11]=1;
   game[11][12]=1;
   game[5][6]=1;
   game[6][7]=1;
   game[7][8]=1;
   game[8][9]=1;
   game[9][10]=1;
   game[8][24]=1;
   game[24][25]=1;
   game[23][25]=1;
   game[22][23]=1;
   game[9][22]=1;
   game[21][22]=1;
   game[20][21]=1;
   game[11][20]=1;
   game[19][20]=1;
   game[18][19]=1;
   game[13][18]=1;
   game[17][18]=1;
   game[16][17]=1;
   game[14][15]=1;
   game[15][16]=1;
   game[25][26]=1;
   game[26][27]=1;
   game[27][28]=1;
   game[28][29]=1;
   game[23][29]=1;
   game[29][30]=1;
   game[30][31]=1;
   game[21][31]=1;
   game[31][32]=1;
   game[32][33]=1;
   game[19][33]=1;
   game[33][34]=1;
   game[34][35]=1;
   game[17][35]=1;
   game[35][36]=1;
   game[36][37]=1;
   game[37][38]=1;
   game[16][38]=1;
   game[28][47]=1;
   game[46][47]=1;
   game[45][46]=1;
   game[30][45]=1;
   game[44][45]=1;
   game[43][44]=1;
   game[32][43]=1;
   game[42][43]=1;
   game[41][42]=1;
   game[34][41]=1;
   game[40][41]=1;
   game[39][40]=1;
   game[36][39]=1;
   game[46][54]=1;
   game[53][54]=1;
   game[52][53]=1;
   game[44][52]=1;
   game[51][52]=1;
   game[50][51]=1;
   game[42][50]=1;
   game[49][50]=1;
   game[48][49]=1;
   game[40][48]=1;

   

        
}


        

         
   std::vector<std::vector<Cell>> board;
         
    

};

}
#endif 

