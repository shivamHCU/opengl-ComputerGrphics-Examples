/* 
	Name:-Amit Kumar Gupta
	17MCMC64
*/

  #include<GL/glut.h>
  #include<stdio.h>
  #include<math.h>	

	int n;
	float poly[50][3];
	float s1[3][3],s2[3][3],s3[3][3],s4[3][3];
	float m,c;
	float res[50][3];


	void input()
	{
	
	printf("ENter the number of co_ordinate in polygon :\n");
	scanf("%d",&n);
	printf("Enter the Co_ordinate of polygon :\n");

			for(int i=0;i<n;i++)
			{
			scanf("%f%f",&poly[i][0],&poly[i][1]);
			poly[i][2]=1;
			}

	
		printf("Enter the slope and intercept of line y=mx+c :\n");
		scanf("%f%f",&m,&c);	
	}

	void drawPolygon(float poly[][3],int n)
	{

		glColor3f(1.0,0,0);
		glBegin(GL_LINE_LOOP);
			for(int i=0;i<n;i++)
				glVertex3f(poly[i][0],poly[i][1],0);

				glEnd();
				glFlush();
	}

	void drawline(float m,float c)
	{
	float x1,y1,x2,y2;
		
		for(x1=-500;x1<0;x1++)
		{
			y1=m*x1+c;
			if(y1>-500 || y1<500)
				break;
		}
		for(x2=500;x2>0;x2++)
		{
			y2=m*x2+c;
			if(y2>-500 || y2<500)
				break;
		}

		glColor3f(0,1.0,0);
		glBegin(GL_LINE_LOOP);
		glVertex3f(x1,y1,0);
		glVertex3f(x2,y2,0);
		glEnd();
		glFlush();
		
	}

	void matrixMul(float arr1[n][3],float arr2[3][3],float arr3[n][3],int n)
		{
		int i,j,k;
	
		for(i=0;i<n;i++)
		{
		for(j=0;j<3;j++)
		  {
			float sum=0;
			for(k=0;k<3;k++)
				{
				sum+=(arr1[i][k]* arr2[k][j]);
				}
				arr3[i][j]= sum;
				}
			}
		}


		void reflection()
		{
		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(1,1,1);
		glBegin(GL_LINES);
		glVertex2i(-500,0);
		glVertex2i(500,0);
		glVertex2i(0,-500);
		glVertex2i(0,500);


	glEnd();
	glFlush();
	drawline(m,c);
	drawPolygon(poly,n);
	
	float Q=atan(m);
	
	float trans[3][3]={{1,0,0},{0,1,0}, {0,-c,1}};
	float rot[3][3]={{cos(-Q),sin(-Q),0},{-sin(-Q),cos(Q),0},{0,0,1}};
	float traninv[3][3]={{1,0,0},{0,1,0}, {0,c,1}};
	float rotinv[3][3]={{cos(Q),sin(Q),0},{-sin(Q),cos(Q),0},{0,0,1}};
	float ref[3][3]={{1,0,0},{0,-1,0},{0,0,1}};
	
	
	matrixMul(trans,rot,s1,3);
	
	matrixMul(s1,ref,s2,3);
	
	matrixMul(s2,rotinv,s3,3);
	
	matrixMul(s3,traninv,s4,3);
	
	matrixMul(poly,s4,res,n);
	
	drawPolygon(res,n);	
		}

	int main(int argc,char **argv){

	input();
	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(1000,1000);
	glutInitWindowPosition(100,100);
	glutCreateWindow("REFLECTION");
	glClearColor(0,0,0,0);
	gluOrtho2D(-500,500,-500,500);
	
	glutDisplayFunc(reflection);

	glutMainLoop();
	
	return 1;

	}
