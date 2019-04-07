/*
 * Name		: Suprava Jena
 * RollNo	: 17MCMC55
 */

#include <stdio.h>
#include <GL/glut.h>

typedef struct pixel
{
	float red;
	float green;
	float blue;
} pixel;

void boundaryFill(int x, int y){
	pixel p;
	glReadPixels(x,y,1,1,GL_RGB,GL_FLOAT,&p);
	if((p.blue != 1 && p.red != 0) || (p.blue != 0 && p.red != 1)){
		return;
	}
	else{
		glBegin(GL_POINTS);
			glVertex2f(x,y);
		glEnd();
		glFlush();
		glutSwapBuffers();
		boundaryFill(x,y-1);
		boundaryFill(x-1,y);
		boundaryFill(x,y+1);
		boundaryFill(x+1,y);
		boundaryFill(x-1,y+1);
		boundaryFill(x-1,y-1);
		boundaryFill(x+1,y+1);
		boundaryFill(x+1,y-1);
	}
	glFlush();
	glutSwapBuffers();
}
void disp(){
	int i, n, sum_x = 0,sum_y = 0;
	printf("\nEnter the number of vertices of polygon: ");
	scanf("%d",&n);
	int a[n][2];
	
	for(i=0;i<n;i++){
		printf("V%d: ",i+1);
		scanf("%d %d", &a[i][0], &a[i][1]);
		sum_x += a[i][0];
		sum_y += a[i][1];
	}
	
	glLineWidth(4);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0,0.0,1.0);
	for(i=0;i<n;i++){
		glVertex2i(a[i][0],a[i][1]);	
	}
	glEnd();
	glFlush();
	glutSwapBuffers();
	
	glColor3f(1.0,0.0,0.0);
	boundaryFill(sum_x/n,sum_y/n);
	glFlush();
	glutSwapBuffers();
}
int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode( GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Boundry Fill");
	glClearColor(1.0,1.0,1.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	gluOrtho2D(0.0,600.0,0.0,600.0);
	glutDisplayFunc(disp);
	glutMainLoop();
	return 0;
}
