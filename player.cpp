//michaeldadush12@gmail.com
//Michael dadush

#include "player.hpp"
#include "board.hpp"


using namespace ariel;

int min(int a,int b)
{
  if(a>b) return b;
  return a;

}


void Player::placeSettelemnt(Board& board,int a)
{ 
  if(getres()[IRON]>2 && getres()[WHEAT]>1)
  {//we need 2 OATS and 3 WHEAT at least
 
        if(board.get_game()[a][a]==id_player)//There is ישוב so u can improve to city
        { 
          getres()[IRON]=getres()[IRON]-3;//3 rock
          getres()[WHEAT]=getres()[WHEAT]-2;//2 oats
          board.set_game(a,a,2*id_player);
          set_point(1);//only one becuse of we buy settelemnt and then city
          cout<<getName()<<" buy city"<<endl;
          return;

        }

  else if(board.get_game()[a][a]==0)
  {//The vertex is free lets chcek anothr case

        for(int i=0;i<55;i++)
        {
            if(a!=i)
            {
            if(board.get_game()[a][i]==1 && board.get_game()[i][i]!=0)//there is path between a to i and someone build in i vertex
            {
              throw std::string("You can't build becuse someone build already");
            }
            if(board.get_game()[i][a]==1 &&board.get_game()[i][i]!=0)//there is path between i to a and someone build in i vertex
            {
              throw std::string("You can't build becuse someone build already");
            }
            }
        }
   }
}


   for(int i=0;i<55;i++)
   { 
      
    if(i!=a)
    {
      if(board.get_game()[a][i]==id_player||board.get_game()[i][a]==id_player)
        {
        for(int j=0;j<54;j++)
        {
          if(i!=j)
          {
            
              if(getres()[WOOD]>0 && getres()[BRICK]>0 &&getres()[WHEAT]>0 && getres()[SHEEP]>0)
              {
                if(board.get_game()[i][j]==id_player||board.get_game()[j][i]==id_player)
                { 
                  //update thr resource
                  getres()[WOOD]=getres()[WOOD]-1;
                  getres()[SHEEP]=getres()[SHEEP]-1;
                  getres()[WHEAT]=getres()[WHEAT]-1;
                  getres()[BRICK]=getres()[BRICK]-1;
                  set_point(1);
                  board.set_game(a,a,id_player);
                  cout<<getName()<<" buy settelemnt"<<endl;
                  
                  return;

                }
              }

              else
              {
                  throw std::string("You don't have the cards to buy ");
              }
            

           
          }
        } 
      }
    }
   }
  } 


  



void Player::placeRoad(Board& board,int a,int b)
{ 
  //bool itsOkBulide=false;
  
  if(getres()[WOOD]>0 && getres()[BRICK]>0)
  {  
    if(a<b)
    {
      if(board.get_game()[a][b]!=1)
      {
        throw std::string("The locatiin is placed in previous round");
      }
      else
      {
        if(board.get_game()[a][a]==id_player||board.get_game()[b][b]==id_player||
            board.get_game()[a][a]==2*id_player||board.get_game()[b][b]==2*id_player)
            { 
              getres()[WOOD]=getres()[WOOD]-1;
              getres()[BRICK]=getres()[BRICK]-1;
              board.set_game(b,a,id_player);
              cout<<getName()<<" :build a road and give one wood either one brick"<<endl;
              return;

            }
        if(board.get_game()[a][a]!=id_player||board.get_game()[b][b]!=id_player)
        {
          for(int i=0;i<54;i++)
          {
            if(board.get_game()[a][i]==id_player||board.get_game()[i][a]==id_player||board.get_game()[i][b]==id_player
            ||board.get_game()[b][i]==id_player)
          {
          getres()[WOOD]=getres()[WOOD]-1;
          getres()[BRICK]=getres()[BRICK]-1;
          board.set_game(a,b,id_player);
          cout<<getName()<<" :build a road and give one wood either one brick"<<endl;
          return;
          }
          }

          
        }

        if(board.get_game()[b][b]!=id_player*2||board.get_game()[a][a]!=2*id_player)
        {
         for(int i=0;i<54;i++)
          {
            if(board.get_game()[a][i]==id_player||board.get_game()[i][a]==id_player||board.get_game()[i][b]==id_player
            ||board.get_game()[b][i]==id_player)
            {
              getres()[WOOD]=getres()[WOOD]-1;
              getres()[BRICK]=getres()[BRICK]-1;
              board.set_game(a,b,id_player);
              cout<<getName()<<" :build a road and give one wood either one brick"<<endl;
              return;
            }
          }
        }

        

      }

      // for(int i=a;i<54;i++)
      // {
      //   if(board.get_game()[a][i]==id_player||board.get_game()[b][i]==id_player)
      //   {
      //     itsOkBulide=true;
      //     break;
      //   }
      // }

    }

    else if(a>b)
    {
        if(board.get_game()[b][a]!=1)
        {
          throw std::string("The locatiin is placed in previous round");
        }

        else
        {  if(board.get_game()[a][a]==id_player||board.get_game()[b][b]==id_player||
            board.get_game()[a][a]==2*id_player||board.get_game()[b][b]==2*id_player)
            { 
              getres()[WOOD]=getres()[WOOD]-1;
              getres()[BRICK]=getres()[BRICK]-1;
              board.set_game(b,a,id_player);
              cout<<getName()<<" :build a road and give one wood either one brick"<<endl;
              return;

            }
          if(board.get_game()[a][a]!=id_player||board.get_game()[b][b]!=id_player)
          {
            for(int i=0;i<54;i++)
           {
            if(board.get_game()[a][i]==id_player||board.get_game()[i][a]==id_player||board.get_game()[i][b]==id_player
            ||board.get_game()[b][i]==id_player)
            {
            getres()[WOOD]=getres()[WOOD]-1;
            getres()[BRICK]=getres()[BRICK]-1;
            board.set_game(b,a,id_player);
            cout<<getName()<<" :build a road and give one wood either one brick"<<endl;
            return;
            }
           }
          }
          if(board.get_game()[b][b]!=id_player*2||board.get_game()[a][a]!=2*id_player)
          {
            for(int i=0;i<54;i++)
            {
            if(board.get_game()[a][i]==id_player||board.get_game()[i][a]==id_player||board.get_game()[i][b]==id_player
            ||board.get_game()[b][i]==id_player)
            {
            getres()[WOOD]=getres()[WOOD]-1;
            getres()[BRICK]=getres()[BRICK]-1;
            board.set_game(b,a,id_player);
            cout<<getName()<<" :build a road and give one wood either one brick"<<endl;
            return;
            }
            }
          }
        }

        // for(int i=b;i<54;i++)
        // {
        //   if(board.get_game()[a][i]==id_player||board.get_game()[b][i]==id_player)
        //   {
        //     itsOkBulide=true;
        //     break;
        //   }
        // }
    }

        else//a=b
        {
          throw std::string("The locatiin is't valid");
        }

        // if(itsOkBulide==false)
        // {

        //   throw std::string ("You can't bulid here ");

        // }


  }

  else
    {
      throw std::string ("You can't buy road becuse u dont have card");
    } 

}

void Player::two_round_init(Board& board, int n,int m)//m is candidate to build sattelment,n candidate to build road 
{

   
  if(board.get_game()[m][n]==1 || board.get_game()[n][m]==1)//there is road between m to n or n to m
  {
    
      if(board.get_game()[n][n]==0)
      {//The vertex is free lets chcek anothr case

        for(int i=0;i<55;i++)
        {
           
                if(board.get_game()[n][i]==1 && board.get_game()[i][i]!=0)//there is path between a to i and someone build in i vertex
                {
                  
                  throw std::string("You can't build becuse someone build already");
                }

                if(board.get_game()[i][n]==1 && board.get_game()[i][i]!=0)//there is path between i to a and someone build in i vertex
                {
                  throw std::string("You can't build becuse someone build already");
                }

        }
      }
   


  }

   else
    {
     throw std::string("You can't build becuse someone build already");
    }

    set_point(1);
    board.set_game(n,n,get_id());//build settlmaent

  

    for(int i=0;i<3;i++)
      {
          if(board.get_borad()[n][i].first!=5)
          {
            set_res(board.get_borad()[n][i].first, 1);
            cout <<getName()<< " gets one card in type:" <<board.get_borad()[n][i].first  << endl;

            
          }

          else
          {
            cout<< getName()<< ":There is no card of DESERT"<<endl;
          }
      
      }
  
    if(m>n)
    {
      
      board.set_game(n,m,get_id());//n is sattelment m is other vertx that help build road
      return;
                           
    }

    else if (m!=n)
    {
        board.set_game(m,n,get_id());
        return;
      
    }
  

}






void Player::buyDevelopmentCard(Card* card)
{ 
  
 if(resource[WHEAT]<=0 || resource[IRON]<=0 || resource[SHEEP]<=0)
 {
  
  throw std::string("There is no card to buy development card");

 }

 else
 {
   
  resource[WHEAT]=resource[WHEAT]-1;
  resource[IRON]=resource[IRON]-1;
  resource[SHEEP]=resource[SHEEP]-1;
  cout<<"Buy Development Card and give one wheat one iron and one brick"<<endl;
 }

 string x=card->Type_of_Card();
 if( x == "VictoryCard")
 {
  
  card_of_player[0]=card_of_player[0]+1; //victory card i 0 in vector card of player
  cout<<"victory card: number of card increas by 1"<<endl;

 }
  
  else if(x=="knightCard") //knight Card  1 in vector card of player
  {
    card_of_player[1]=card_of_player[1]+1;
    cout<<"knight Card: number of card increas by 1"<<endl;

  }
 
  else if(x=="MonopolyCard") //MonopolyCard  2 in vector card of player
  {
   card_of_player[2]=card_of_player[2]+1;
   cout<<"MonopolyCard : number of card increas by 1"<<endl;
  }

  else if(x=="build_road_Card")//build_road_Card  3 in vector card of player
  {
    card_of_player[3]=card_of_player[3]+1;
    cout<<"build_road_Card : number of card increas by 1"<<endl;
  }

  else if(x=="YearOfPlentyCard")//YearOfPlentyCard  4 in vector card of player
  {
   card_of_player[4]=card_of_player[4]+1;
   cout<<"YearOfPlentyCard : number of card increas by 1"<<endl;
  }

  else
  {
    std::string("invalid card name");
  }

  }
 


void Player::printPoints()
{
  cout<<"player "<<name<<" has "<<point<<" points in the game"<<endl;
}