/*
 * Name		: Suprava Jena
 * RollNo	: 17MCMC55
 */

#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>

float a1=0;
float b1=0;
float a2=0;
float b2=0;

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

    glPointSize(6.0);
	glBegin(GL_POINTS);	
        glColor3f(1,0,0);
	    glVertex2i(a1,b1);
	    glVertex2i(a2,b2);
	glEnd();    
	glFlush();
	glPointSize(1.0);	
}
    

void Bresenhamline()
{
    float x=0,y=0,dx=0,dy=0,incx=0,incy=0,e=0;
    int temp=0,interchange=0,i=1;
   	x=a1;
	y=b1;
	dx=abs(a2-a1);
	dy=abs(b2-b1);
	
 	if((a2-a1)>0)
		incx = 1;
	else if((a2-a1)<0)
		incx = -1;
	else
		incx = 0;
	
	if((b2-b1)>0)
            incy = 1;
    else if((b2-b1)<0)
            incy = -1;
    else
            incy = 0;
		
	if(dy > dx)
	{
		temp = dx;
		dx = dy;
		dy = temp;
		interchange = 1;
				
	}
	else
		interchange = 0;
	
	e=((2*dy)-dx);

        
	glBegin(GL_POINTS);	
        glColor3f(1,0,0);
	
       	for(i;i<=dx;i++)
      	{	
			glVertex2i(x,y);		
			while(e>0)
			{
				if (interchange == 1)
					x = x+incx;
				else
					y = y+incy;
				
			e=(e-(2*dx));
			}
			
		    if(interchange == 1)
				y = y+incy;
			else
				x = x+incx;
			e=(e+(2*dy));
	    }
    glEnd();
	glFlush();
		 
}

int main(int argc,char *argv[])
{

	if(argc < 5){
		if(argv[1] != "help")
			printf("%s\n","INVALID ARUGMENTS!" );
		printf("%s\n","ARGUMENT REQUIRED (End point of the line segment)!! \n<a1> <b1> <a2> <b2>");
		return 0;		
	}

	a1 = atof(argv[1]);
	b1 = atof(argv[2]);
	a2 = atof(argv[3]);
	b2 = atof(argv[4]);
	
	printf("Two end points of the line are...");
	printf("\nV1 (a1,b1) = (%0.2f,%0.2f)",a1,b1);
	printf("\nV2 (a2,b2) = (%0.2f,%0.2f)",a2,b2);
	printf("%s\n","");
    

    glutInit(&argc,argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(900,900);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Bresenham's Line Drawing Algorithm ");
	gluOrtho2D(-450,450,-450,450);
	glClearColor(0,1,0,0.9);
	
    DrawMainAxis();
	glutDisplayFunc(Bresenhamline);
        
    glutMainLoop();
    return 0;

}