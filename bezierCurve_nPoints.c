/*
 * @Developer   : Shivam Gangwar
 * @Maintainer  : Shivam Gangwar
 * @RollNo      : [17MCMC49]
 */


#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

void keyboard(unsigned char key, int x, int y);

float xc[10], yc[10];

int points; 

void myInit() {
    glClearColor(1.0,1.0,1.0,0.0);
    glColor3f(0.0,0.0,0.0);
    glPointSize(3);
}

void DrawMainAxis()
{   
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(4.0);
    glColor3f(0,0,1);
    glBegin(GL_LINES);
        glVertex2i(0,450);
        glVertex2i(0,-450);
        glVertex2i(-450,0);
        glVertex2i(450,0);
    glEnd();

    
     glColor3f(0,0,1);
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

int factorial(int n)
{
    if (n<=1)
        return(1);
    else
        n=n*factorial(n-1);
    return n;
}

float binomial_coff(float n,float k)
{
    float ans;
    ans = factorial(n) / (factorial(k)*factorial(n-k));
    return ans;
}


void drawBezierCurve() 
{
    DrawMainAxis();

    glPointSize(8.0);
    glBegin(GL_POINTS); 
        glColor3f(1,0,0);
        for (int i = 0; i < points; ++i)
        {
            glVertex2i(xc[i],yc[i]);    
        }
    glEnd();    
    glFlush();
    glPointSize(3.0);

    glColor3f(1,0.1,0.0);
    glLineWidth(3.0);
    glBegin(GL_LINES);
      for (int i = 0; i < points-1; ++i)
      {
          glVertex2f(xc[i],yc[i]);
          glVertex2f(xc[i+1],yc[i+1]);
      }
    glEnd();
    glFlush();

    glColor3f(0.0,1,0.0);
    for(double t = 0.0;t <= 1.0; t += 0.001)
    {


        float x = 0,y = 0;
        for(int i=0;i<points;i++)
        {
            x = x + binomial_coff((float)(points - 1), (float)i)   *   pow(t, (double)i)   *   pow((1 - t),(points - 1 - i))   *   xc[i];
            y = y + binomial_coff((float)(points - 1), (float)i)   *   pow(t, (double)i)   *   pow((1 - t),(points - 1 - i))   *   yc[i];
        }

        glBegin(GL_POINTS);
            glVertex2i(x,y);
        glEnd();
        glFlush();
    }
}
 

void myDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
    drawBezierCurve();
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

int main(int argc, char *argv[]) {

    if(argc == 1){
        printf("%s\n","ARGUMENT REQUIRED (Enter control points)!! <no os points> <'n' entries of x and y coordinates...> ");
        return 0;
    }
    if(argv[1][0] >= '9' || argv[1][0] <= '0'){
        printf("%s\n","INVALID ARUGMENTS!" );
    	printf("%s\n","ARGUMENT REQUIRED (Enter control points)!! <no os points> <'n' entries of x and y coordinates...> ");
    	return 0;
    } else if (atoi(argv[1]) > 10){
    	printf("%s\n","No of points should be less then 10." );
    	return 0;	
    }else if (argc < (2*atoi(argv[1]))+2){
    	printf("ARGUMENT REQUIRED (Enter control points)!! \n<no os points> <%d entries of x and y coordinates...> ",atoi(argv[1]));
    	return 0;
    }
    
    points = atoi(argv[1]);            

    for (int i = 0; i < 2*points; ++i)
    {
    	if(i%2 == 0)	
    		xc[i/2] = atoi(argv[i+2]);
    	else
    		yc[i/2] = atoi(argv[i+2]);		
    } 

    printf("Points of the line are...");
    for (int i = 0; i < points; ++i)
    {
        printf("\nV%d (x[%d],y[%d]) = (%0.2f,%0.2f)",i,i,i,xc[i],yc[i]);    
    }
    printf("%s\n","");

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(900,900);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Bezier Curve");
    gluOrtho2D(-450,450,-450,450);

    glutDisplayFunc(myDisplay);
    glutKeyboardFunc(keyboard);
    
    myInit();
    glutMainLoop();
    return 0;
}