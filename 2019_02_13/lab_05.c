#include<stdio.h>
#include<GL/glut.h>
#include <GL/gl.h>
#include<stdlib.h>
#define ROUND(x) ((int)(x+0.5))
int r;
	
void display (void)
 {
	int x=0,y=r;
	glClear (GL_COLOR_BUFFER_BIT);
 	glColor3f (1.0, 0.0, 0.0);
	int di=1-r;
	glBegin(GL_POINTS);
	while(x<y)
	{
		if(di<0)
		{
			x+=1;
			glVertex2s(x,y);
			glVertex2s(y,x);
			di=di+2*x+3;
		}
		else
		{
			x+=1;
			y=y-1;
			glVertex2s(x,y);
			glVertex2s(y,x);
			di=di+2*x-2*y+5;
		}
	}
	glColor3f (1.0, 1.0, 1.0);
 	for(int i=-100 ; i<=100 ; i++)
 	{
 		glVertex2s(i,0);
 		glVertex2s(0,i);
 	}
 	for(int i=-2; i<=2 ; i++)
 	{
		 glVertex2s(95+i,4+i);
		 glVertex2s(95-i,4+i);
 	} 
 	for(int i=0; i<=2 ; i++)
 	{
 		glVertex2s(4+i,95+i);
 		glVertex2s(4-i,95+i);
 		glVertex2s(4,95-i);
 	}

 	glEnd();
 	glFlush();
 }

 void init(void)
 {
 glClearColor (0.0, 0.0, 0.0, 0.0);
 glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0);
 }

int main(int argc, char** argv)
{
 printf("Enter the radius\n");
 scanf("%d",&r);
 glutInit(&argc, argv);
 glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize (500, 500);
 glutInitWindowPosition (100, 100);
 glutCreateWindow ("circle ");
 init ();
 glutDisplayFunc(display);
 glutMainLoop();
 return 0;
}
