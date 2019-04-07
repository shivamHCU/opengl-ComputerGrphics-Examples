/*
Name:-Amit Kumar Gupta
Reg no:-17MCMC64
*/

#include<stdio.h>
#include"GL/gl.h"
#include"GL/freeglut.h"
#include<math.h>
int i;

void drawAxis()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLineWidth(1);
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_LINES);

		glVertex2f(-300,0);
		glVertex2f(300,0);
		glVertex2i(0,300);
		glVertex2i(0,-300);
	glEnd();
	glFlush();
}
void draw(float k[3][3],int n)
{	

	glColor3f(0.0,1.0,0.0);
	glBegin(GL_LINE_LOOP);

			for(i=0;i<n;i++)
			{
				glVertex2f(k[i][0],k[i][1]);
					
			}

	glEnd();
	glFlush();
}

void matrixMulti(float arr1[3][3],float arr2[3][3],float arr3[3][3],int m,int n,int l)
{

int j,k;
float sum=0;

for(i=0;i<m;i++)
{
	for(j=0;j<n;j++)
	{
		arr3[i][j]=0;
		for(k=0;k<l;k++)
		{
			arr3[i][j]+=(arr1[i][k]*arr2[k][j]);
		}
		
	}
}
}

void display()
{

glClear(GL_COLOR_BUFFER_BIT);
float T5[3][3],T6[3][3],T7[3][3],T8[3][3],T9[3][3],T10[3][3],T11[3][3],T12[3][3];
float T1[3][3]={{50.0,0.0,1.0},{100.0,0.0,1.0},{75.0,30.0,1.0}};
float T2[3][3]={{50.0,60.0,1.0},{100.0,60.0,1.0},{75.0,30.0,1.0}};

drawAxis();
draw(T1,3);
draw(T2,3);

float T3[3][3]={{50.0,0.0,1.0},{100.0,0.0,1.0},{75.0,30.0,1.0}};
float T4[3][3]={{50.0,60.0,1.0},{100.0,60.0,1.0},{75.0,30.0,1.0}};
float K[3][3]={{1,0,0},{0,1,0},{-75,-30,1}};

matrixMulti(T3,K,T5,3,3,3);
matrixMulti(T4,K,T6,3,3,3);

float S[3][3]={{2.0,0.0,0.0},{0.0,2.0,0.0},{0.0,0.0,1.0}};
matrixMulti(T5,S,T7,3,3,3);
matrixMulti(T6,S,T8,3,3,3);

float R[3][3]={{0,1,0},{-1,0,0},{0,0,1}};
	
matrixMulti(T7,R,T9,3,3,3);
matrixMulti(T8,R,T10,3,3,3);

float K1[3][3]={{1,0,0},{0,1,0},{75,30,1}};

matrixMulti(T9,K1,T11,3,3,3);
matrixMulti(T10,K1,T12,3,3,3);
draw(T11,3);
draw(T12,3);


}

int main(int argc,char **argv)
{

glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE);
glutInitWindowSize(600,600);
glutInitWindowPosition(200,200);
glutCreateWindow("Question 7");
glClearColor(0,0,0,0);
gluOrtho2D(-300,300,-300,300);

glutDisplayFunc(display);
glutMainLoop();
return 0;
}
