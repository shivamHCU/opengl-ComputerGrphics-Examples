/*
 * Name		: Suprava Jena
 * RollNo	: 17MCMC55
 */

#include<stdio.h>
#include "GL/glut.h"
#include<unistd.h>
#include<math.h>
#include <stdlib.h>

int x,y,r,xc,yc;

void DrawMainAxis()
{   
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(4.0);
    glColor3f(0,0,0);
    glBegin(GL_LINES);
		glVertex2i(0,450);
		glVertex2i(0,-450);
	    glVertex2i(-450,0);
		glVertex2i(450,0);
    glEnd();
}

void midPointCircle()
{
	glColor3f(1,0,1);
	glPointSize(6.0);
	glBegin(GL_POINTS);
		glVertex2i(xc,yc);
	glEnd();
	glFlush();

	int p=1-r;
	while(x>y)
	{
		y++;
		if(p<=0)
		{
			p=p+2*y+1;
		}
		else
		{
			x--;
			p=p+2*y-2*x+1;
		}
		glColor3f(1,0,1);
		glPointSize(3.0);
		glBegin(GL_POINTS);
			glVertex2i(xc+x,yc+y);
			glVertex2i(xc+x,yc-y);
			glVertex2i(xc-x,yc+y);
			glVertex2i(xc-x,yc-y);
			glVertex2i(xc+y,yc+x);
			glVertex2i(xc-y,yc+x);
			glVertex2i(xc+y,yc-x);
			glVertex2i(xc-y,yc-x);			
			usleep(10000);
		glEnd();
		glFlush();
	}
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



int main(int argc,char **argv)
{

	if(argc < 4){
		if(argv[1] != "help")
			printf("%s\n","INVALID ARUGMENTS!" );
		printf("%s\n","ARGUMENT REQUIRED !!\n<progam name>  <xc> <yc> <radius> ");
		return 0;		
	}
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(900,900);
	glutInitWindowPosition(0,0);
	glutCreateWindow("MidPoint Circle Algorithm");
	gluOrtho2D(-450,450,-450,450);
	glClearColor(1.0,1.0,1.0,0);
	glClear(GL_COLOR_BUFFER_BIT);


	xc = atoi(argv[1]);
	yc = atoi(argv[2]);
	r = atoi(argv[3]);

	x=r;y=0;

	printf("Center Coordinate (xc,yc) - %d %d",xc,yc);
	printf("\nRadius - %d",r);
	printf("\n");

	DrawMainAxis();
	
	glutDisplayFunc(midPointCircle);
	glutKeyboardFunc(keyboard);

	glutMainLoop();
	return 0;
}
