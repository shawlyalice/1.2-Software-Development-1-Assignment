#include<iostream>
using namespace std;
#include "iGraphics.h"
#define screenWidth 1000
#define screenHeight 600

char c[5][10]={"c1\\01.bmp","c1\\02.bmp","c1\\03.bmp","c1\\04.bmp","c1\\05.bmp"};
int r=0;
int g=0;
int b=0;
int x=0,y=0;;
int cX=0;
int cY=0;
int cIndex =0;
int mx,my;
void iDraw()
{
	iClear();
	
	iShowBMP(0,0,"c1\\back.bmp");
	iShowBMP2(cX,cY,c[cIndex],0);
	
	iSetColor(r,g,b);
	iRectangle(x+100,y+300,300,200);//body
	iFilledRectangle(x+150,y+200,50,100);//left leg
	iFilledRectangle(x+300,y+200,50,100);//right leg
	iText(x+210,y+370,"WANNA_EAT",GLUT_BITMAP_8_BY_13);
	iRectangle(x+170,y+350,160,50);//mouth
	iCircle(x+200,y+450,40,100);//left eye
	iCircle(x+300,y+450,40,100);//right eye
	iRectangle(x+150,y+500,50,100);//I
	iFilledCircle(x+175,y+650,50,100);
	iRectangle(x+300,y+500,50,100);//I
	iFilledCircle(x+325,y+650,50,100);
}

/*function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/


void iMouseMove(int mx, int my)
{

	x=mx -100;
	y =my -400;
}
void iPassiveMouseMove(int mx, int my)
{
	
}

void iMouse(int button, int state, int mx, int my)
{
	
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		x= mx-100;
		y=my-300;
	
	}
	
	
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		r=82;
		g=204;
		b=235;
	}
	
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/


void iKeyboard(unsigned char key)
{
	if (key == 'w')
	{
		y+=10;
	}
	else if(key =='s')
	{
		y-=10;
	}
	else if(key =='a')
	{
		x-=10;
	}
	else if(key =='d')
	{
		x+=10;
	}
	else if(key =='r')
	{
		r=255;
		g=0;
		b=0;
	}
	else if(key =='g')
	{
		r=0;
		g=255;
		b=0;
	}
	else if(key =='b')
	{
		r=0;
		g=0;
		b=255;
	}
	
	
	
	
}

/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{
	if(key == GLUT_KEY_UP)
	{
		y+=10;

	}
	if(key == GLUT_KEY_DOWN){
	
		y-=10;
	}
	if (key == GLUT_KEY_RIGHT)
	{
		x+=10;
				
	}
	if (key == GLUT_KEY_LEFT)
	{
		x-=10;
	}
	
	if (key == GLUT_KEY_HOME)
	{
		r=186;
		g=177;
		b=186;
	}
	if(key == GLUT_KEY_INSERT)
	{
		r=235;
		g=82;
		b=235;
	}
	
}





void change(){
	cIndex++;
	if(cIndex>=5){
	cIndex = 0;
	}


}


int main()
{
	iSetTimer(1000,change);
	///srand((unsigned)time(NULL));
	iInitialize(screenWidth, screenHeight, "Project Title");
	
	iStart();
	return 0;
}