# Computer-Graphics-with-OpenGL-CS-1212
CS-1212 Lab Class of CS-1206 Computer Graphics


Compile:

## For Linux:


```
gcc -o filename filename.c -lGL -lGLU -lglut

```

## On macOS:
### You need to change the header files to:

```
#include <OpenGL/gl.h> 
#include <OpenGL/glu.h> 
#include <GLUT/glut.h> 
```

and compile using:

```
gcc -o filename filename.c -framework Carbon -framework OpenGL -framework GLUT

```

## On Windows:

### Type the following in cygwin shell with GLUT installed

```
gcc -o filename.exe filename.c -lopengl32 -lglut32
```



