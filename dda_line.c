/*
 * Name		: Suprava Jena
 * RollNo	: 17MCMC55
 */


#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<GL/glut.h>

void keyboard(unsigned char key, int x, int y);

float x_a=0,y_a=0,x_b=0,y_b=0;

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

    glPointSize(6.0);
	glBegin(GL_POINTS);	
        glColor3f(1,0,0);
	    glVertex2i(x_a,y_a);
	    glVertex2i(x_b,y_b);
	glEnd();    
	glFlush();
	glPointSize(1.0);	
}


void DDAline()
{
	float steps=0, x=0, y=0, i=1;
	float dx=0,dy=0, Xinc=0, Yinc=0;

	dx=x_b-x_a;
	dy=y_b-y_a;

	if(abs(dx) >= abs(dy))
		steps=abs(dx);
	else
		steps=abs(dy);

	Xinc=((dx)/steps);
	Yinc=((dy)/steps);
	
	x=x_a;
	y=y_a;
	
	glBegin(GL_LINE_LOOP);
        glColor3f(1,0,0);	
	for(i;i<=steps;i++)
	{

		glVertex2f(round(x),round(y));
		x=x+Xinc;
		y=y+Yinc;
	}
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


int main(int argc,char *argv[])
{

	if(argc < 5){
		if(argv[1][0] != 'h')
		{	
			printf("%s\n","INVALID ARUGMENTS!");
		}
		printf("%s\n","ARGUMENT REQUIRED (End point of the line segment)!! \n<x_a> <y_a> <x_b> <y_b>");
		return 0;		
	}

	x_a = atoi(argv[1]);
	y_a = atoi(argv[2]);
	x_b = atoi(argv[3]);
	y_b = atoi(argv[4]);
	
	printf("Two end points of the line are...");
	printf("\nV1 (x_a,y_a) = (%0.2f,%0.2f)",x_a,y_a);
	printf("\nV2 (x_b,y_b) = (%0.2f,%0.2f)",x_b,y_b);
	printf("%s\n","");


    glutInit(&argc,argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(900,900);
    glutInitWindowPosition(0,0);
    glutCreateWindow(" DDALine Drawing Algorithm ");
	gluOrtho2D(-450,450,-450,450);
	glClearColor(1,1,1,1);
	
    DrawMainAxis();
	glutDisplayFunc(DDAline);
    glutKeyboardFunc(keyboard);
    
    glutMainLoop();
    return 0;

}


