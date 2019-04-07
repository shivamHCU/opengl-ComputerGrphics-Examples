/*
 * @Developer	: Shivam Gangwar
 * @Maintainer	: Shivam Gangwar
 * @RollNo		: [17MCMC49]
 */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<GL/glut.h>

float x_1, y_1, x_2, y_2, x_3, y_3;
int timesCount;

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

void sierpinskiTriangle(float x_1, float y_1, float x_2, float y_2, float x_3, float y_3, int times) {
	glLineWidth(1.0);
	if(times>0) {
		glBegin(GL_LINE_LOOP);
			glColor3f(0,0.2,1);
			glVertex2f(x_1,y_1);
			glVertex2f(x_2,y_2);
			glVertex2f(x_3,y_3);
		glEnd();
		
		sierpinskiTriangle((x_1+x_2)/2,(y_1+y_2)/2,x_2,y_2,(x_2+x_3)/2,(y_2+y_3)/2, times-1);
		sierpinskiTriangle( x_1,y_1,(x_1+x_2)/2,(y_1+y_2)/2,(x_1+x_3)/2,(y_1+y_3)/2, times-1);
		sierpinskiTriangle( x_3,y_3,(x_1+x_3)/2,(y_1+y_3)/2,(x_2+x_3)/2,(y_2+y_3)/2, times-1);
		
	}

}


void display() {
	sierpinskiTriangle(x_1, y_1, x_2, y_2, x_3, y_3, timesCount);	
	glFlush();
}

int main(int argc,char *argv[])
{
	if(argc < 8){
		if(argv[1] != "help")
			printf("%s\n","INVALID ARUGMENTS!" );
		printf("%s\n","ARGUMENT REQUIRED (All three vertices of the initial triangle )!! \n<x1> <y1> <x2> <y2> <x3> <y3> <times>");
		return 0;		
	}

	x_1 = atoi(argv[1]);
	y_1 = atoi(argv[2]);
	x_2 = atoi(argv[3]);
	y_2 = atoi(argv[4]);
	x_3 = atoi(argv[5]);
	y_3 = atoi(argv[6]);
	timesCount = atoi(argv[7]);

	printf("Three vertices of the initial triangle...");
	printf("\nV1 (x_1,y_1) = (%0.2f,%0.2f)",x_1,y_1);
	printf("\nV2 (x_2,y_2) = (%0.2f,%0.2f)",x_2,y_2);
	printf("\nV3 (x_3,y_3) = (%0.2f,%0.2f)",x_3,y_3);
	printf("\nTimesCount = %d",timesCount);
	printf("%s\n","");

    glutInit(&argc,argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(900,900);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Sierpinski Triangle ");
	gluOrtho2D(-450,450,-450,450);
	glClearColor(1,1,1,1); 
		
    DrawMainAxis();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	  
    glutMainLoop();
    return 0;

}


