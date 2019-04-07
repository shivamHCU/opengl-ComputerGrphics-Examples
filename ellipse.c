/*
 * @Developer	: Shivam Gangwar
 * @Maintainer	: Shivam Gangwar
 * @RollNo		: [17MCMC49]
 */

#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <stdlib.h>

#define pi 3.14158

GLfloat a,b,xc,yc;


void DrawMainAxis()
{   
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(4.0);
    glColor3f(1,1,1);
    glBegin(GL_LINES);
		glVertex2i(0,450);
		glVertex2i(0,-450);
	    glVertex2i(-450,0);
		glVertex2i(450,0);
    glEnd();

    glColor3f(1,1,1);
    for (int i = 0; i <= 450; i += 50)
    {
    	if(i%100 == 0)
    	{	
    		glLineWidth(2.0);
    		glBegin(GL_LINES);
		        glVertex2i(i,10);
		        glVertex2i(i,-10);
		        glVertex2i(-10,i);
		        glVertex2i(10,i);
		        glVertex2i(-i,10);
		        glVertex2i(-i,-10);
		        glVertex2i(-10,-i);
		        glVertex2i(10,-i);
			glEnd();
		}
		else
		{	
	    	glLineWidth(1.0);
	    	glBegin(GL_LINES);
		        glVertex2i(i,5);
		        glVertex2i(i,-5);
		        glVertex2i(-5,i);
		        glVertex2i(5,i);
		        glVertex2i(-i,5);
		        glVertex2i(-i,-5);
		        glVertex2i(-5,-i);
		        glVertex2i(5,-i);
	    	glEnd();
	    }
    }
}


void DrawEllipse(){
	
	DrawMainAxis();

	GLfloat x,y;

	glColor3f(0,1,1);
	glPointSize(8.0);
	glBegin(GL_POINTS);
		glVertex2i(xc,yc);
	glEnd();
	glFlush();

	glPointSize(2.0);
	
	for(float i=0 ; i<=pi/2 ; i += 0.001)
	{

		glBegin(GL_POINTS);			
			x=a*cos(i);
			y=b*sin(i);
			
			glColor3f(1,0,1);
			glVertex2f(xc+x,yc+y);
			
			glColor3f(1,1,0);
			glVertex2f(xc-x,yc+y);
			glVertex2f(xc+x,yc-y);
			glVertex2f(xc-x,yc-y);
			
			usleep(1000);
		glEnd();
 		glFlush();
	}

	glColor3f(0,1,1);
	glLineWidth(1.5);
	glBegin(GL_LINES);
		glVertex2i(xc,yc);
		glVertex2i(xc+a,yc);
		glVertex2i(xc,yc);
		glVertex2i(xc,yc+b);
	glEnd();
	glFlush();
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


int main(int argc, char **argv) {

	if(argc == 1){
		printf("%s\n","ARGUMENT REQUIRED!! \n<xc> <yc> <a> <b>");
		return 0;
	}
	else if(argc < 5){
		printf("%s\n","INVALID ARUGMENTS!" );
		printf("%s\n","ARGUMENT REQUIRED!! \n<xc> <yc> <a> <b>");
		return 0;		
	}

	xc = atoi(argv[1]);
	yc = atoi(argv[2]);
	a = atoi(argv[3]);
	b = atoi(argv[4]);

	printf("\nCenter Coordinate (xc,yc) : %0.2f  %0.2f",xc,yc);
	printf("\nLength of major axis : %0.2f",a);
	printf("\nLength of minor axis : %0.2f",b);
	printf("%s\n","");
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(900,900);
	glutCreateWindow("Ellipse");
	gluOrtho2D(-450,450,-450,450);

	glutDisplayFunc(DrawEllipse);
	glutKeyboardFunc(keyboard);
	
	glutMainLoop();
	
	return 1;
}
