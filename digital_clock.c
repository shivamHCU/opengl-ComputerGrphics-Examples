/*
 * @Developer	: Shivam Gangwar
 * @Maintainer	: Shivam Gangwar
 * @RollNo		: [17MCMC49]
 */

#include<stdio.h>
#include"GL/gl.h"
#include"GL/freeglut.h"
#include<time.h>

int digits[][7]={
			{1,1,1,1,1,1,0},
		   	{0,1,1,0,0,0,0},
		   	{1,1,0,1,1,0,1},
		   	{1,1,1,1,0,0,1},
		   	{0,1,1,0,0,1,1},
		   	{1,0,1,1,0,1,1},
		   	{1,0,1,1,1,1,1},
		   	{1,1,1,0,0,0,0},
		   	{1,1,1,1,1,1,1},
		   	{1,1,1,1,0,1,1}
		   };

void keyboard(unsigned char key, int x, int y);

int sec,min,hour,i,t[6];
int isAM ;


void printnumber(int no,int loc_x,int loc_y)
{
	glColor3f(0.0,1.0,1.0);
	glLineWidth(5);
	glBegin(GL_LINES);
		
		if(digits[no][0]==1){
			glVertex2i(loc_x+5,loc_y+200);
			glVertex2i(loc_x+95,loc_y+200);
		}

		if(digits[no][1]==1){
			glVertex2i(loc_x+100,loc_y+195);
			glVertex2i(loc_x+100,loc_y+105);
		}

		if(digits[no][2]==1){
			glVertex2i(loc_x+100,loc_y+95);
			glVertex2i(loc_x+100,loc_y+5);
		}

		if(digits[no][3]==1){
			glVertex2i(loc_x+95,loc_y);
			glVertex2i(loc_x+5,loc_y);
		}

		if(digits[no][4]==1){
			glVertex2i(loc_x,loc_y+5);
			glVertex2i(loc_x,loc_y+95);
		}

		if(digits[no][5]==1){
			glVertex2i(loc_x,loc_y+105);
			glVertex2i(loc_x,loc_y+195);
		}

		if(digits[no][6]==1){
			glVertex2i(loc_x+5,loc_y+100);
			glVertex2i(loc_x+95,loc_y+100);
		}
	glEnd();

}

void setTimeDigits()
{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		glColor3f(0.0,1.0,1.0);
		glLineWidth(5);
		glBegin(GL_LINES);
		
		int loc_x = 50,loc_y = 100;
		printnumber(t[0],loc_x,loc_y);
		
		loc_x += 130;
		printnumber(t[1],loc_x,loc_y);

		if(t[6] % 2 == 0){
			glColor3f(0,0,0);
		}

		loc_x += 150;
		glPointSize(10);
		glBegin(GL_POINTS);
			glVertex2i(loc_x,loc_y + 50);
			glVertex2i(loc_x,loc_y + 150);
		glEnd();

		if(t[6] % 2 == 0){
			glColor3f(0.0,1.0,1.0);
		}
		
		loc_x +=50;
		printnumber(t[2],loc_x,loc_y);
		
		loc_x += 130;
		printnumber(t[3],loc_x,loc_y);

		if(t[6] % 2 == 0){
			glColor3f(0,0,0);
		}		
		
		loc_x += 150;
		glPointSize(10);
		glBegin(GL_POINTS);
			glVertex2i(loc_x,loc_y + 50);
			glVertex2i(loc_x,loc_y + 150);
		glEnd();

		if(t[6] % 2 == 0){
			glColor3f(0.0,1.0,1.0);
		}

		loc_x += 50;
		printnumber(t[4],loc_x,loc_y);
		
		loc_x += 130;
		printnumber(t[5],loc_x,loc_y);
		loc_x += 170;

		glColor3f(1.0,0.0,0.0);
		glLineWidth(3.0);
		if(isAM){
			glBegin(GL_LINES);
				glVertex2i(loc_x,loc_y + 100);
				glVertex2i(loc_x,loc_y + 147);
				glVertex2i(loc_x,loc_y + 153);
				glVertex2i(loc_x,loc_y + 197);
				glVertex2i(loc_x + 3,loc_y + 200);
				glVertex2i(loc_x + 47,loc_y + 200);
				glVertex2i(loc_x + 50,loc_y + 197);
				glVertex2i(loc_x + 50,loc_y + 153);
				glVertex2i(loc_x + 50,loc_y + 147);
				glVertex2i(loc_x + 50,loc_y + 100);
				glVertex2i(loc_x + 3,loc_y + 150);
				glVertex2i(loc_x + 47,loc_y + 150);
			glEnd();
		}
		else{
			glBegin(GL_LINES);
				glVertex2i(loc_x,loc_y + 100);
				glVertex2i(loc_x,loc_y + 147);
				glVertex2i(loc_x,loc_y + 153);
				glVertex2i(loc_x,loc_y + 197);
				glVertex2i(loc_x + 3,loc_y + 200);
				glVertex2i(loc_x + 47,loc_y + 200);
				glVertex2i(loc_x + 50,loc_y + 197);
				glVertex2i(loc_x + 50,loc_y + 153);
				glVertex2i(loc_x + 3,loc_y + 150);
				glVertex2i(loc_x + 47,loc_y + 150);
			glEnd();
		}

		loc_x += 80;
		glBegin(GL_LINES);
			glVertex2i(loc_x,loc_y + 100);
			glVertex2i(loc_x,loc_y + 147);
			glVertex2i(loc_x,loc_y + 153);
			glVertex2i(loc_x,loc_y + 197);
			
			glVertex2i(loc_x + 3,loc_y + 200);
			glVertex2i(loc_x + 23,loc_y + 200);
			glVertex2i(loc_x + 28,loc_y + 200);
			glVertex2i(loc_x + 47,loc_y + 200);
			
			glVertex2i(loc_x + 50,loc_y + 197);
			glVertex2i(loc_x + 50,loc_y + 153);
			glVertex2i(loc_x + 50,loc_y + 147);
			glVertex2i(loc_x + 50,loc_y + 100);
			
			glVertex2i(loc_x + 25,loc_y + 197);
			glVertex2i(loc_x + 25,loc_y + 167);
		glEnd();


		glFlush();
		glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 'q': case 'Q':
            exit(0);
            break;
        case 'r': case 'R':
            glutPostRedisplay();
            break;
    }
}

void digitalClock()
{
	time_t my_time;
	struct tm * timeinfo; 
	time (&my_time);
	timeinfo = localtime (&my_time);
	hour=timeinfo->tm_hour;   min=timeinfo->tm_min;    sec=timeinfo->tm_sec;
	

	isAM = ((hour/12) == 1 ) ? 0 : 1;

	if(hour == 12 || hour == 24)
	{
		hour = 12;
		t[0] = (hour<10) ? 0 : (hour/10);
		t[1] = hour%10;

	}
	else
	{
		hour = hour % 12;
		t[0] = (hour<10) ? 0 : (hour/10);
		t[1] = hour%10;
	}
	t[2] = (min<10) ? 0 : (min/10);
	t[3] = min%10;
	t[4] = (sec<10) ? 0 : (sec/10);
	t[5] = sec%10;

	setTimeDigits();
}

int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(1200,400);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Digital Clock");
	glClearColor(0,0,0,0);
	gluOrtho2D(0,1200,0,400);

	glutDisplayFunc(digitalClock);
	glutIdleFunc(digitalClock);
    glutKeyboardFunc(keyboard);
	
	glutMainLoop();
	return 0;
}
