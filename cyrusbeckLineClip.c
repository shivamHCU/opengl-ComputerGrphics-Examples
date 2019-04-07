/*
	cyrus-beck line clipping algorithm
	Name:-Amit Kumar Gupta
	17MCMC64
*/

  #include <GL/glut.h>
  #include<stdio.h>
  #include<math.h>

  int vertices[100][2];
  int linex1,linex2,liney1,liney2;

  int n;

	void takeInput()
	{

	printf("Enter The no of vertices in windows :");
	scanf("%d",&n);
	
	printf("Enter windows vertices :");
	
	for(int i=0;i<n;i++)
		scanf("%d %d",&vertices[i][0],&vertices[i][1]);
	
	printf("Enter the end points of clipping line : ");
	scanf("%d %d %d %d",&linex1,&liney1,&linex2,&liney2);	

	}

	void drawPolygon()
	{
	glColor3f(1,1,1);
	
	glBegin(GL_LINE_LOOP);
		for(GLint i=0;i<n;i++)
			glVertex3f(vertices[i][0],vertices[i][1],0);
	glEnd();
	glFlush();
}

	void drawLine()	
	{
		glColor3f(1,0,0);
			
		printf("%d %d",linex1,liney1);
		glBegin(GL_LINES);
			glVertex2i(linex1,liney1);
			glVertex2i(linex2,liney2);
		glEnd();
		glFlush();
	}

	void applyCyrusBeck()
	{
	
	float normal[n][2];
	float diff[n][2];
	int dx = linex2-linex1;
	int dy = liney2 - liney1;
	float NP=0;
	float ND=0;
	float te=0;
	float tl=1;
	float t;
	
	for(int i=0;i<n;i++)
		{
		
		normal[i][0]=vertices[(i+1)%n][1]-vertices[i][1];
		normal[i][1]=vertices[i][0]-vertices[(i+1)%n][0];
		
		diff[i][0]=linex1-vertices[i][0];
		diff[i][1]=liney1-vertices[i][1];

		NP=normal[i][0]*diff[i][0]+normal[i][1]*diff[i][1];

		ND=normal[i][0]*dx+normal[i][1]*dy;
		t=-1.0*NP/ND;
		
		if(t>0 && t<1){
			if(ND>0){
				if(te<t)
					te=t;	
			}
			else if(ND<0){
				if(tl>t)
					tl=t;
			}
		}
		
		}
		glColor3f(0,1,0);
		
		glBegin(GL_LINES); 
			glVertex2i(linex1+(dx)*tl,liney1+(dy)*tl);
			glVertex2i(linex1+(dx)*te,liney1+(dy)*te);	
		glEnd();
		glFlush();	
	}				
	
	int main(int argc, char **argv) 
		{
	
		takeInput();
		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
		glutInitWindowSize(750,750);
		glutInitWindowPosition(100,100);
		glutCreateWindow("Cyrus Beck");
		
	glClearColor(0,0,0,0);
	gluOrtho2D(-700,700,-700,700);
	glClear(GL_COLOR_BUFFER_BIT);
	
	drawLine();
	drawPolygon();
	
	applyCyrusBeck();

        glutSwapBuffers();
	
	glutMainLoop();
	
	return 1;
	}
