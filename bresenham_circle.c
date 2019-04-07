/*
 * Name		: Suprava Jena
 * RollNo	: 17MCMC55
 */

#include<stdio.h>
#include "GL/gl.h"
#include"GL/freeglut.h"
#include<unistd.h>

int x,y,r,xc,yc,limit=0,d,d1,d2;

void draw(int xc,int yc,int x,int y)
{	
	glColor3f(1.0,1.0,0.0);
	glPointSize(3);
	glBegin(GL_POINTS);
		glVertex2i(xc+x,yc+y);
		glVertex2i(xc-x,yc+y);
		glVertex2i(xc+x,yc-y);
		glVertex2i(xc-x,yc-y);
		usleep(5000);	
	glEnd();
	glFlush();	
}
void display()
{
	y=0;x=r;d=2*(1-r);
	while(x>limit)
	{
		draw(xc,yc,x,y);
		glFlush();
		if(d<0)
		{
			d1=2*(d+x)-1;
			if(d1<=0)
			{
				y=y+1;
				d=d+2*y+1;
			}
			else
			{
				x=x-1;
				y=y+1;
				d=d-2*x+2*y+2;
			}		
		}
		else if(d>0)
		{
			d2=2*(d-y)-1;
			if(d2<=0)
			{
				x=x-1;
				y=y+1;
				d=d-2*x+2*y+2;
			}
			else
			{
				x=x-1;
				d=d-2*x+1;
			}
		}
		else
		{
			x=x-1;
			y=y+1;
			d=d-2*x+2*y+2;
		}
	}
}
int main(int argc,char **argv)
{
	printf("Enter center coordinates(xc,yc) of a circle :");
	scanf("%d%d",&xc,&yc);
	printf("Enter value of radius : ");
	scanf("%d",&r);
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(600,600);
	glutInitWindowPosition(200,200);
	glutCreateWindow("Bresenham circle drawing algorithm in anticlockwise direction");
	glClearColor(0.4,0.4,0.4,0.4);
	gluOrtho2D(0,600,0,600);
	glClear(GL_COLOR_BUFFER_BIT);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
