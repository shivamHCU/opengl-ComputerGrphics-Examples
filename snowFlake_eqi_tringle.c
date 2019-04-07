/*
 * @Developer	: Shivam Gangwar
 * @Maintainer	: Shivam Gangwar
 * @RollNo		: [17MCMC49]
 */


#include <stdio.h>
#include<GL/glut.h>
#include<math.h>
#define PI 3.14159

float x_1, y_1, x_2, y_2, x_3, y_3;
int iteration;

void keyboard(unsigned char key, int x, int y);


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
}

void snowFlake(int x_1, int y_1, int x_2, int y_2, int i)
{
 
 float angle = 60*PI/180;
 int x_3 = (2*x_1+x_2)/3;
 int y_3 = (2*y_1+y_2)/3;

 int x_4 = (x_1+2*x_2)/3;
 int y_4 = (y_1+2*y_2)/3;

 int x = x_3 + (x_4-x_3)*cos(angle) + (y_4-y_3)*sin(angle);
 int y = y_3 - (x_4-x_3)*sin(angle) + (y_4-y_3)*cos(angle);


 if(i > 0)
 {
 	snowFlake(x_1, y_1, x_3, y_3, i-1);
  	snowFlake(x_3, y_3, x, y, i-1);
  	snowFlake(x, y, x_4, y_4, i-1);
  	snowFlake(x_4, y_4, x_2, y_2, i-1);
 }
 else
 {
 	glLineWidth(1.0);
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0,1.0,1.0);
		glVertex2i(x_1, y_1);
		glVertex2i(x_3, y_3);
		glVertex2i(x, y);
		glVertex2i(x_4, y_4);
		glVertex2i(x_2, y_2);
		
	glEnd();
	glFlush();
 }
}

void display() {

	snowFlake(x_1 ,y_1 , x_2, y_2, iteration);
	glFlush();
	snowFlake(x_2 ,y_2 , x_3, y_3, iteration);
	glFlush();
	snowFlake(x_3 ,y_3 , x_1, y_1, iteration);
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

int main(int argc,char *argv[])
{

	if(argc < 8){
		if(argv[1] != "help")
			printf("%s\n","INVALID ARUGMENTS!" );
		printf("%s\n","ARGUMENT REQUIRED (All three vertices of the initial triangle along with no of iterations)!! \n<x1> <y1> <x2> <y2> <x3> <y3> <iteration>");
		return 0;		
	}

	x_1 = atoi(argv[1]);
	y_1 = atoi(argv[2]);
	x_2 = atoi(argv[3]);
	y_2 = atoi(argv[4]);
	x_3 = atoi(argv[5]);
	y_3 = atoi(argv[6]);
	iteration = atoi(argv[7]);

	printf("Three vertices of the initial triangle...");
	printf("\nV1 (x_1,y_1) = (%0.2f,%0.2f)",x_1,y_1);
	printf("\nV2 (x_2,y_2) = (%0.2f,%0.2f)",x_2,y_2);
	printf("\nV3 (x_3,y_3) = (%0.2f,%0.2f)",x_3,y_3);
	printf("\niteration = %d",iteration);
	printf("%s\n","");
    
    glutInit(&argc,argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(900,900);
    glutInitWindowPosition(0,0);
    glutCreateWindow("SnowFlake");
	gluOrtho2D(-450,450,-450,450);
	glClearColor(0.0,0.0,0.0,0.0);
	
	DrawMainAxis();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
       
	
	glutMainLoop();
    return 1;
}
