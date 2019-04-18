#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include<stdio.h>
int a=0,b=0,c=210,d=100,e=310,f=200,g=400,h=1;
void myinit()
{
    glClearColor(0.0, 0.0, 0.0, 0.1);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-788, 788, -420, 420);
}
int i=0;

void xys()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
    for(float i=0;i<=1;i+=0.01){
        glVertex2f((1-i)*(1-i)*(1-i)*a+3*(1-i)*(1-i)*i*c+3*(1-i)*i*i*e+i*i*i*g,
                   (1-i)*(1-i)*(1-i)*b+3*(1-i)*(1-i)*i*d+3*(1-i)*i*i*f+i*i*i*h);
        glVertex2f((1-(i+0.01))*(1-(i+0.01))*(1-(i+0.01))*a+3*(1-(i+0.01))*(1-(i+0.01))*(i+0.01)*c+3*(1-(i+0.01))*(i+0.01)*(i+0.01)*e+(i+0.01)*(i+0.01)*(i+0.01)*g,
                   (1-(i+0.01))*(1-(i+0.01))*(1-(i+0.01))*b+3*(1-(i+0.01))*(1-(i+0.01))*(i+0.01)*d+3*(1-(i+0.01))*(i+0.01)*(i+0.01)*f+(i+0.01)*(i+0.01)*(i+0.01)*h);
        
    }
    glEnd();
    glFlush();
}
int main(int argc,char ** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RED);
    glutInitWindowSize(1360, 788);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("xyz");
    myinit();
    glutDisplayFunc(xys);
    glutMainLoop();
}
