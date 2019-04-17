// C code to implement basic 
// transformations in OPENGL 
#include <stdio.h> 
#include <math.h> 
#include <time.h> 
#include <GL/glut.h> 
  
// window size 
#define maxWD 640 
#define maxHT 480 
  

  
  
// this is a basic init for the glut window 
void myInit(void) 
{ 
	glClearColor(1.0, 1.0, 1.0, 0.0); 
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity(); 
	gluOrtho2D(0.0, maxWD, 0.0, maxHT); 
	glClear(GL_COLOR_BUFFER_BIT); 
	glFlush(); 
} 
  
// this function just draws a point 
void drawPoint(int x1, int y1, int x2, int y2, int x3, int y3) 
{ 
	glPointSize(7.0); 
	glColor3f(0.0f, 0.0f, 1.0f); 
	glBegin(GL_LINE_LOOP); 
	
	glVertex2i(x1, y1);   
	glVertex2i(x2, y2);  
	glVertex2i(x3, y3);   

	glEnd(); 
} 
  
void rotateAroundPt(int x1, int y1, int x2, int y2, int x3, int y3, int cx, int cy, float theta) 
{ 
 

        glClear(GL_COLOR_BUFFER_BIT); 
        int xf, yf; 
  
        // actual calculations.. 
        x1 = cx + (int)((float)(x1 - cx) * cos(theta)) 
             - ((float)(y1 - cy) * sin(theta)); 
        y1 = cy + (int)((float)(x1 - cx) * sin(theta)) 
             + ((float)(y1 - cy) * cos(theta)); 
             
        x2 = cx + (int)((float)(x2 - cx) * cos(theta)) 
             - ((float)(y2 - cy) * sin(theta)); 
        y2 = cy + (int)((float)(x2 - cx) * sin(theta)) 
             + ((float)(y2 - cy) * cos(theta)); 
             
             
        x3 = cx + (int)((float)(x3 - cx) * cos(theta)) 
             - ((float)(y3 - cy) * sin(theta)); 
        y3 = cy + (int)((float)(x3 - cx) * sin(theta)) 
             + ((float)(y3 - cy) * cos(theta)); 
 
  
        // drawing the rotating point 
        drawPoint(x1, y1, x2, y2, x3, y3);
        glFlush(); 


} 
  
// this function will translate the point 
void translatePoint(int x1, int y1, int x2, int y2, int x3, int y3, int tx, int ty) 
{ 


	glClear(GL_COLOR_BUFFER_BIT); 

	// update 
	x1 = x1 + tx; 
	y1 = y1 + ty; 
	
	
	x2 = x2 + tx; 
	y2 = y2 + ty; 
	
	
	x3= x3 + tx; 
	y3 = y3 + ty; 

	drawPoint(x1, y1, x2, y2, x3, y3);

	glFlush(); 

} 
  
// this function draws 
void scalePoint(int x1, int y1, int x2, int y2, int x3, int y3, int sx, int sy) 
{ 

        glClear(GL_COLOR_BUFFER_BIT); 
  
        // update 
        x1 = x1 * sx; 
        y1 = y1 * sy; 
        
        
        x2 = x2 * sx; 
        y2 = y2 * sy; 
        
        
        x3 = x3 * sx; 
        y3 = y3 * sy; 
  

 
  
        glClear(GL_COLOR_BUFFER_BIT); 
  
    
  
        // drawing the point 
        drawPoint(x1, y1, x2, y2, x3, y3);
        glFlush(); 

} 
  
// Actual display function 
void myDisplay(void) 
{ 
    int opt; 
    int x1=0, y1=0, x2=10, y2=0, x3=5, y3=5;

    
    printf("\nEnter\n\t<1> for translation"
           "\n\t<2> for rotation"
           "\n\t<3> for scaling\n\t:"); 
    scanf("%d", &opt); 
    printf("\nGo to the window..."); 
    switch (opt) { 
    case 1: 

        translatePoint(x1, y1, x2, y2, x3, y3, 2, 2); 
        break; 
    case 2: 

        rotateAroundPt(x1, y1, x2, y2, x3, y3, 2, 2, 30); 
        // point will circle around 
        // the centre of the window 
        break; 
    case 3: 

        scalePoint(x1, y1, x2, y2, x3, y3, 2, 2); 
        break; 
    case 4:
    	drawPoint(x1, y1, x2, y2, x3, y3);
    } 
} 
  
void main(int argc, char** argv) 
{ 
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
    glutInitWindowSize(maxWD, maxHT); 
    glutInitWindowPosition(100, 150); 
    glutCreateWindow("Transforming point"); 
    glutDisplayFunc(myDisplay); 
    myInit(); 
    glutMainLoop(); 
} 

