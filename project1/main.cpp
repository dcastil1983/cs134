// Name: David
// Quarter, Year: Spring, 14
// Lab: 2
//
// This file is to be modified by the student.
// main.cpp
////////////////////////////////////////////////////////////
#include "object.h"
#include <algorithm>
#include <GL/glut.h>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 800;
const double VIEW_LEFT = 0.0;
const double VIEW_RIGHT = WINDOW_WIDTH;
const double VIEW_TOP = 0.0;
const double VIEW_BOTTOM = WINDOW_HEIGHT;
const int DEPTH_LIMIT = 5;
const int LIST_LIMIT = 1;

Point2D a(30, 200);
Point2D b(30, 100);
vector<Line2D> lines;


int currentTime = 0;
int previousTime = 0;
double dtTwo = 0.0;

void GLrender();
void GLupdate();

class Player : public Circle2D
{
  public:
   Circle2D circle;
   Player(Circle2D c1)
   :circle(c1)
   {}
   int accel;
   double vel_x;
   double vel_y;
   void update();
   void setAccel(int x)
   {
	accel = x;
   }
};

Point2D p1(400,400);
Circle2D c1(p1, 10, BLUE, true);

Player ball(c1);


void Player::update()
{
    ball.setAccel(4);
    double dtOne = glutGet(GLUT_ELAPSED_TIME);
    ball.circle.move(ball.vel_x*(dtOne - dtTwo)*.001, ball.vel_y*(dtOne - dtTwo)*.001);
    dtTwo = dtOne;
}



void getKeyPress(unsigned char key, int x, int y)
{

    switch (key)
    {
        case 'w':
          ball.vel_y = -80;
          break;
            
        case 'a':
          ball.vel_x = -80;
          break;

        case 's':
          ball.vel_y = 80;
          break;

        case 'd':
          ball.vel_x = 80;
          break;
        case 't':
          ball.vel_x = 0;
          ball.vel_y = 0;
          break;
        default:
          break;
    }
}

double addXR(Circle2D c)
{
    double x;
    return x = ball.circle.p.x + ball.circle.radius;
}

double addYR(Circle2D c)
{
    double y;
    return y = ball.circle.p.y + ball.circle.radius;
}

double addXL(Circle2D c)
{
    double x;
    return x = ball.circle.p.x - ball.circle.radius;
}

double addYL(Circle2D c)
{
    double y;
    return y = ball.circle.p.y - ball.circle.radius;
}

void collisions()
{
    if(addXR(ball.circle) >= 800 || addXL(ball.circle) <= 0)
    {
        ball.setAccel(0);
	ball.circle.move(800,0);
    }

    if(addYR(ball.circle) >= 800 || addYL(ball.circle) <= 0)
    {
                ball.setAccel(0);
	ball.circle.move(800,0);
    }

    if(addXR(ball.circle) >= 800 || addXL(ball.circle) <= 0)
    {
                ball.setAccel(0);
	ball.circle.move(800,0);
    }

    if(addYR(ball.circle) >= 800 || addYL(ball.circle) <= 0)
    {
                ball.setAccel(0);
	ball.circle.move(800,0);
    }
}

//Initializes OpenGL attributes
void GLInit(int* argc, char** argv)
{
	glutInit(argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow("Lab 2 - <Insert Name Here>");
	glutDisplayFunc(GLrender);
	glutIdleFunc(GLupdate);
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
	gluOrtho2D(VIEW_LEFT, VIEW_RIGHT, VIEW_BOTTOM, VIEW_TOP);
    glutKeyboardFunc(getKeyPress);
}

int main(int argc, char** argv)
{
    if(argc != 2)
    {
        cout << "Not enough arguments!" << endl;
        exit(0);
    }


    ifstream myFile;
    double x1;
    double y1;
    double x2;
    double y2;

    myFile.open(argv[1]);
    if(myFile.is_open())
    {
        while(!myFile.eof())
        {
            myFile >> x1;
            myFile >> y1;
            myFile >> x2;
            myFile >> y2;
            Line2D line1(x1, y1, x2, y2, RED);
            lines.push_back(line1);
        }
    }
    myFile.close();
	GLInit(&argc, argv);
	glutMainLoop();
	return 0;
}

void GLupdate()
{
	const int FRAME_RATE = 25;

	glutPostRedisplay();

    ball.update();

	//sleep is not effective in capturing constant time between frames because sleep
	//doesn't consider the time it takes for context-switching. However, this reduces
	//the cpu-usage. If accurate time frames are desire, use a time accumulator
	currentTime = glutGet(GLUT_ELAPSED_TIME);
	int diffTime = currentTime - previousTime;
	previousTime = currentTime;
	usleep(1000 * std::max(FRAME_RATE - diffTime, 0));
}

void GLrender()
{
	glClear(GL_COLOR_BUFFER_BIT);

    ball.circle.render();
    for(int i = 0; i < lines.size() - 1; i++)
    {
        lines[i].render(RED);
    }
	glFlush();	
	glutSwapBuffers();

}
