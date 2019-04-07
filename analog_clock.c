/*
 * @Developer	: Shivam Gangwar
 * @Maintainer	: Shivam Gangwar
 * @RollNo		: [17MCMC49]
 */

#include <stdio.h>
#include "GL/glut.h"
#include <math.h>
#include <time.h>

void keyboard(unsigned char key, int x, int y);

const float SS_X=900,SS_Y=900;
const float C_X = 450, C_Y = 450;
const double DEG=3.141592653/180;
int hour,min,sec;
double angleSec,angleMin,angleHour;

void printClockHands(double r)
{
	hour=(hour>12)?hour-12:hour;	
	angleSec=(90-(sec*6))*DEG;
	
	float j = sec ;  
	angleMin=(90-(min*6 + j*0.1))*DEG;
	
	float i = min ;
	angleHour=(90-(hour*30 + i*0.5))*DEG;
	
	double r1=r*3/5;	
	glLineWidth(4);
	glColor3f(0.8,0.8,0.0);
	glBegin(GL_LINES);
		glVertex2d(C_X,C_Y);
		glVertex2d(C_X+r1*cos(angleHour)-0,C_Y+r1*sin(angleHour)-0);
	glEnd();

	double r2=r*3/4;
	glLineWidth(3);
	glColor3f(0.2,0.8,0.0);
	glBegin(GL_LINES);
		glVertex2d(C_X,C_Y);
		glVertex2d(C_X+r2*cos(angleMin)-0,C_Y+r2*sin(angleMin)-0);
	glEnd();
	
	double r3=r*3/3.5;
	glLineWidth(1.5);
	glColor3f(0.8,0.3,0.0);
	glBegin(GL_LINES);
		glVertex2d(C_X,C_Y);
		glVertex2d(C_X+r3*cos(angleSec)-0,C_Y+r3*sin(angleSec)-0);
	glEnd();
	
}

void drawClock(double r)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	float i;
	
	glPointSize(12);
	glBegin(GL_POINTS);
		glVertex2i(C_X,C_Y);
	glEnd();

	glColor3f(1.0,1.0,1.0);
	glPointSize(5.0);
	glBegin(GL_POINTS);
		for(i=0;i<360;i+=0.25)
		{
			float x=cos(DEG*i);	
			float y=sin(DEG*i);
			glVertex2d(x*r+C_X,y*r+C_Y);
		}
	glEnd();	

	float r3 = r*1.04;
	glPointSize(2.0);
	glBegin(GL_POINTS);
		for(i=0;i<360;i+=0.20)
		{
			float x=cos(DEG*i);	
			float y=sin(DEG*i);
			glVertex2d(x*r3+C_X,y*r3+C_Y);
		}
	glEnd();


	glColor3f(1.0,1.0,1.0);
	glLineWidth(2.0);
	glBegin(GL_LINES);
		double r1=r*0.95;
		for(i=0;i<=360;i+=6)
		{
			float x=cos(DEG*i);	
			float y=sin(DEG*i);
			glVertex2d(x*r+C_X,y*r+C_Y);
			glVertex2d(x*r1+C_X,y*r1+C_Y);
			
		}
	glEnd(); 

	glLineWidth(5.0);
	glBegin(GL_LINES);
		double r2=r*0.85;
		for(i=0;i<360;i=i+30)
		{
			float x=cos(DEG*i);	
			float y=sin(DEG*i);
			glVertex2d(x*r3+C_X,y*r3+C_Y);
			glVertex2d(x*r2+C_X,y*r2+C_Y);	
		}
	glEnd(); 
	
	

}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 'q': case 'Q':
            exit(0);
            break;
    }
}


void analogClock()
{
  	time_t tim = time(0);
  	struct tm* t;
  	t=localtime(&tim);
	hour=t->tm_hour;   min=t->tm_min;    sec=t->tm_sec;
	drawClock(C_X-200);
	printClockHands(C_X-200);
	glutSwapBuffers();
}

int main(int argc ,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(SS_Y,SS_Y);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Analog Clock");
	glClearColor(0,0.1,0.2,0);
	gluOrtho2D(0.0,SS_Y,0.0,SS_Y);
	
	glutDisplayFunc(analogClock);
	glutIdleFunc(analogClock);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}
