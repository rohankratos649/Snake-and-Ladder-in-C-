#include<iostream>
#include<cstdlib>
#include<conio.h>
using namespace std;
bool gameOver;
const int width=20;
const int height=20;
int x,y,fruitX,fruitY,score;   
/*
the snake will goes to the fruit so vaiable
fruitX and fruitY will give the position of the fruit
*/
enum Direction{STOP=0,LEFT,RIGHT,UP,DOWN};  //controls for the snake
Direction dir;   //this will hold the snake's direction
void Setup()
{
	gameOver=false;
	dir=STOP;
	x=width/2;  //initial pos of the snake w.r.t x
	y=height/2; //initial pos of the snake w.r.t y
	fruitX=rand() %width;  //fruit will be at the random position 
	fruitY=rand() %height; //here rand is a in_built function
	score=0; 
}
void Draw()  //this function is used to draw the map of the game
{
    system("cls");  //to clear the screen
	for(int i=0;i<width;i++)
	cout<<"#";
	cout<<endl;
	
	for(int i=0;i<height;i++)
	{
		for(int j=0;j<width;j++)
		{
			if(j==0)
			cout<<"#";
			if(i==y && j==x)
			cout<<"o";    //where starting of the snake begins
			else if(i==fruitY && j==fruitX)
			cout<<"F";    //where fruit will appear
			else
			cout<<" ";
			
			if(j==width-1)
			cout<<"#";
		}
		cout<<endl;
	}
	for(int i=0;i<width+2;i++)
	cout<<"#";	
	cout<<endl;
}
void Input()
{
	if(_kbhit())
	{
	  switch(dir)
	  {
	  	case 'a':
	  		dir=LEFT;
	  		x--;
	  		break;
	    case 'd':
	    	dir=RIGHT;
	    	x++;
	    	break;
	    case 'w':
		    dir=UP;
		    y--;
			break;
		case 's':
		    dir=DOWN;
		    y++;
			break;	
		case 'x':
		    gameOver=true;
			break;	
		   } 	
	}
	
}
void Logic()
{
	switch(dir)
	{
		case LEFT:
	    	x--;
	    	break;
	    case RIGHT:
	    	x++;
		    break;
		case UP:
			y--;
		    break;
		case DOWN:
			y++;
		    break;
		default:
		    break;				
	}
	
}
int main()
{
	Setup();    //calling the setup function
	while(!gameOver)   //all below functions will work till the game is over
	Draw();        //calling the draw function
	Input();       // calling input function
	Logic();      //calling logic function
	//sleep(10);   //this function will slow down 
	
	return 0;
}
