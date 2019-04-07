/* 	
	cohen-sutherland line clipping algorithms
	Name-Amit Kumar Gupta
	17mcmc64
*/

  #include<GL/glut.h>
  #include<stdio.h>
  #include<math.h>

	float ix1,ix2,iy1,iy2;
	float x3,x4,y3,y4;
	float xmin,ymin,xmax,ymax;
	float m;

  void takeInput()
      {
	
	printf("Enter The windows vertices");
	printf("\nxmin :\tymin :\txmax :\tymax : \n");
	scanf("%f%f%f%f",&xmin,&ymin,&xmax,&ymax);
	
	printf("enter the end points of clipping line: ");
	scanf("%f %f %f %f",&ix1,&iy1,&ix2,&iy2);
	
	x3 = ix1;
	y3 = iy1;
	x4 = ix2;
	y4 = iy2;

       }

             void drawPolygon()
		{
	
	   glColor3f(0,0,1);
	   glBegin(GL_LINE_LOOP);

			glVertex3f(xmin,ymin,0);
			glVertex3f(xmax,ymin,0);
			glVertex3f(xmax,ymax,0);
			glVertex3f(xmin,ymax,0);

		glEnd();
		}
			

	void drawLine(float x1, float y1,float x2,float y2)
		{
		
			glBegin(GL_LINES);
			glVertex3f(x1,y1,0);
			glVertex3f(x2,y2,0);
	glEnd();
	
	}

    int findCodepoint(int x,int y)
	{
	int cp =0;
	if(x<xmin)
		cp+=1;
	else if(x>xmax)
		cp+=2;

	if(y<ymin)
		cp+=4;
	else if(y>ymax)
		cp+=8;
	return cp;
		}	

	void findIntersection(int line)
		{
	
	if(line==1)
			{
		
		x4 = xmin;
		y4 = y3 + m*(xmin-x3);
	}
	else if(line==2){
		
		x4 = xmax;
		y4 = y3 + m*(xmax-x3);
	}
	else if(line ==4){
		
		y4 = ymin;
		x4 = x3+(ymin-y3)/m;
	}
	
	else
	{
		y4 = ymax;
		x4 = x3 +(ymax-y3)/m;
	}
  }

    void swap(float *x,float *y)
       {
	int temp = *x;
	*x = *y;
	*y = temp;
        }
	
     void applyCohenSutherland()
         {
	m = (y4-y3)/(x4-x3);
	GLint codepoint1;
	GLint codepoint2;
	int line =1;

	for(int i=0;i<5;i++)
	{
		codepoint1 = findCodepoint(x3,y3);
		codepoint2 = findCodepoint(x4,y4);
		
		if((codepoint1 | codepoint2) ==0)
		{
			
			drawLine(x3,y3,x4,y4);
			break;	
		}

		else if((codepoint1 & codepoint2) !=0)
		{
			
			break;
		}
		else
		{
			if((codepoint1&line)==line){

				swap(&x3,&x4);
				swap(&y3,&y4);
				findIntersection(line);
			}

			else if((codepoint2&line)==line)
				findIntersection(line);
		}
		
		line*=2;
	}			
			
}


	int main(int argc, char **argv) 
	{

	takeInput();
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(750,750);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Cohen Sutherland");
	glClearColor(0,0,0,0);
	gluOrtho2D(-375,375,-375,375);
	
	glClear(GL_COLOR_BUFFER_BIT);
	
	drawPolygon();
	
	glColor3f(1,0,0);
	drawLine(ix1,iy1,ix2,iy2);
	
	glColor3f(0,1,0);
	applyCohenSutherland();
	
        glutSwapBuffers();

	glutMainLoop();
	
	return 1;
}
