#include<stdio.h>
#include<GL/glut.h>
#include <GL/gl.h>
#include<stdlib.h>
#include<math.h>
#define ROUND(x) ((int)(x+0.5))

int a,b;
int tx,ty;
float x;
float changex(float a,float b)
{
 return(a*cos(x*3.14/180)-b*sin(x*3.14/180));
}
  
float changey(float a,float b)
{
 return(a*sin(x*3.14/180)+b*cos(x*3.14/180));
}
	
void display (void)
 {
	int x=0,y=b;
	glClear (GL_COLOR_BUFFER_BIT);
 	glColor3f (0.0, 1.0, 0.0);
	glBegin(GL_LINES);
	glVertex2i(0,0);
	glVertex2i(0,30);
	glVertex2i(0,30);
	glVertex2i(30,30);
	glVertex2i(30,30);
	glVertex2i(30,0);
	glVertex2i(30,0);
	glVertex2i(0,0);
	glEnd();
 	glFlush();
	
	glColor3f (1.0, 1.0, 0.0);
	glBegin(GL_LINES);
	glVertex2i(0+tx,0+ty);
	glVertex2i(0+tx,30+ty);
	glVertex2i(0+tx,30+ty);
	glVertex2i(30+tx,30+ty);
	glVertex2i(30+tx,30+ty);
	glVertex2i(30+tx,0+ty);
	glVertex2i(30+tx,0+ty);
	glVertex2i(0+tx,0+ty);
	glEnd();
 	glFlush();

	glColor3f (.50, 1.0, 0.50);
	glBegin(GL_LINES);
	glVertex2i(0*tx,0*ty);
	glVertex2i(0*tx,30*ty);
	glVertex2i(0*tx,30*ty);
	glVertex2i(30*tx,30*ty);
	glVertex2i(30*tx,30*ty);
	glVertex2i(30*tx,0*ty);
	glVertex2i(30*tx,0*ty);
	glVertex2i(0*tx,0*ty);
	glEnd();
 	glFlush();


	glColor3f (1.0, .50, 0.0);
	glBegin(GL_LINES);
	glVertex2f(changex(0,0),changey(0,0));
	glVertex2f(changex(0,30),changey(0,30));
	glVertex2f(changex(0,30),changey(0,30));
	
	glVertex2f(changex(30,30),changey(30,30));
	glVertex2f(changex(30,30),changey(30,30));
	glVertex2f(changex(30,0),changey(30,0));
	glVertex2f(changex(30,0),changey(30,0));
	glVertex2f(changex(0,0),changey(0,0));
	glEnd();
 	glFlush();

	glColor3f (.50, 1.0, 0.50);
	glBegin(GL_LINES);
	glVertex2i(0,0);
	glVertex2i(0+30*tx,30);
	glVertex2i(0+30*tx,30);
	glVertex2i(30+30*tx,30);
	glVertex2i(30+30*tx,30);
	glVertex2i(30,0);
	glVertex2i(30,0);
	glVertex2i(0,0);
	glEnd();
 	glFlush();

	glBegin(GL_POINTS);	
	glColor3f (1.0, 1.0, 1.0);
 	for(int i=-100 ; i<=100 ; i++)
 	{
 		glVertex2i(i,0);
 		glVertex2i(0,i);
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
 //printf("Enter a,b\n");
 //scanf("%d%d",&a,&b);
printf("enter the translation vector :");
	scanf("%d%d",&tx,&ty);
printf("enter value of theta :");
scanf("%f",&x);
//printf("%f%f",(0*cos(x*3.14/180)-30*sin(x*3.14/180)),(0*sin(x*3.14/180)+30*cos(x*3.14/180)));
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
