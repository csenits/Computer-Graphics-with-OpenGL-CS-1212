#include<openGL/gl.h>
#include<openGL/glu.h>
#include<GLUT/glut.h>
int a=40,b=20,d;
float x,y,i;
void ref(int x,int y)
{
    glVertex2i(x,y);
    glVertex2i(x,-y);
    glVertex2i(-x,y);
    glVertex2i(-x,-y);
}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    d=b*b-b*a*a+0.25*a*a;
    x=0;
    y=b;
    glColor3f(1.0,1.0,0.0);
    while(x*x<=y*y)
    {
        if(d<0)
        {
            ref(x,y);
            x+=1;
            d=d+2*b*b*x +b*b;
        }
        else
        {
            ref(x,y);
            x+=1;
            y-=1;
            d=d+2*b*b*x +b*b - 2*a*a*y;
        }
    }
    d=b*b*(x+0.5)*(x+0.5) + a*a*(y-1)*(y-1) -a*a*b*b;
    while(y>=0)
    {
        if(d<0)
        {
            ref(x,y);
            x+=1;
            y-=1;
            d=d - 2*a*a*y +a*a;
        }
        else
        {
            ref(x,y);
            y-=1;
            d=d+2*b*b*x +a*a - 2*a*a*y;
        }
    }
    glColor3f(1.0,0.0,1.0);
    for(i=-100;i<=100;++i)
    {
        glVertex2i(i,0);
        glVertex2i(0,i);
    }
    glEnd();
    glFlush();
}
void init(void)
{
    glClearColor(0,0,0,0);
    glOrtho(-100,100,-100,100,-1,1);
}
int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("midpoint ellipse");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}
