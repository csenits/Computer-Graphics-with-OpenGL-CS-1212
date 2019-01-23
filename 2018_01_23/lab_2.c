// 17-1-5-091
// Khilji Abdullah Faiz Ur Rahman 
// Lab 1: 23 January 2019
// Write a OpenGL Program to create a display window and draw a rectangle within it.


// Initialization Function
#include<GL/glut.h>
void myInit ()
{  
	// Resest background color with black (since all three argument is 0.0)	
	glClearColor(0.0,0.0,0.0,1.0) ;
	glMatrixMode(GL_PROJECTION); //Set window size in X and Y direction
	gluOrtho2D(-780, 780, -420, 420);
}
	


// Function to display animation	

void lineSegment(void)
{    
	glClear(GL_COLOR_BUFFER_BIT); //clear display window
	glColor3f(1.0,0.0,0.0); //set line segment color to red
	glBegin(GL_LINES); 
	glVertex2i(0,0);   //specify line-segment geometry
	glVertex2i(100,0);
	glVertex2i(0,100);
	glVertex2i(100,100);
	glVertex2i(0,0);
	glVertex2i(0,100);

	glVertex2i(100,100);
	glVertex2i(100,0);

	
	glEnd();
	glFlush();   
}


int main(int argc, char** argv) 
 {
	glutInit(&argc, argv); // Display which is of RGB (Red Green Blue) type
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);  //Declares window size
	glutInitWindowSize(1368,768); //set display window width and height
	glutInitWindowPosition(0,0); // Declares window position which is (0,0)
	glutCreateWindow("A Line Segment"); // Name to Window
	myInit( );  // Call to myInit()
	glutDisplayFunc(lineSegment); //send graphics to display window
	glutMainLoop( ); //Display everything and wait

}





