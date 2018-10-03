// animate.cc
// This program demonstrates different animation techniques.
//
// It also demonstrates how to determine which on-screen object
// you have clicked on (i.e. selection) using the drawing with colors
// to another buffer technique.
//
// Written by Prof. David M. Chelberg
//
// Modified to allow byte values (raw pixel data) to be read back from
// GPU allowing 2^24 values to be used for selection with A channel
// added could get to 2^32 (4 billion values).
// 
// last-modified: Fri Oct  6 07:41:04 2017
//

#include <Angel.h>
#include <iostream>
#include <stdlib.h>
#include "square.h"
#include "scene.h"

using std::cin;
using std::cout;
using std::endl;

// Bool to determine whether to clear the screen
bool clear=true;

// Bool to determine whether to update the animation
bool updating=true;

// Pointer to the square object (must be initialized after
// initialization of shaders, so leave it as a pointer.
Scene * MyScene;

// Data storage for our geometry for the lines
vec2 *points;

// How big a square to draw.
GLfloat size=30.0;

// Window Size 
GLint windowSizeLoc;

// Window size
int win_h=0;
int win_w=0;

// Initial parameters of the ellipses
GLfloat angular_offset=3.14;
GLfloat angular_velocity=1.0/230.0;
GLfloat minor_axis=100.0;
GLfloat major_axis=150.0;

// Simple display draws a square of size sq_size*2 around mouse
// location.
extern "C" void display()
{
  // What happens if the following is commented out?  Explain.
  if (clear) {
    glClear(GL_COLOR_BUFFER_BIT);
  }
  MyScene->DrawBackground();

  for(int i = 0; i < MyScene->count_of_animals; i++)
  {
    MyScene->animals_1[i]->draw();
  }
  
  MyScene->gun->draw();

  glutSwapBuffers ();
}

// Using idle to update all objects.  MySquare2 can move linearly,
// MySquare is orbiting MySquare2, so update_ellipse is
// called for it after setting the goal (the center of the ellipse)
// for it.  MyCircle orbits MySquare so its goal is set to the
// location of MySquare.
extern "C" void idle()
{
  if (updating) {
    for(int i = 0; i < MyScene->count_of_animals; i++)
    {
      MyScene->animals_1[i] -> update();
    }

    // Make MySquare and MyCircle follow MySquare2, but rotate around it

    glutPostRedisplay();
  }
}

void processSelection(unsigned char PixelColor[], int btn)
{

}

// Mouse callback, implements selection by using colors in the back buffer.
extern "C" void mouse(int btn, int state, int x, int y)
{
  if (state == GLUT_DOWN) {
    // Draw the scene with identifying colors
    // Ensure the clear color isn't the same as any of your objects
    glClearColor (0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    // Flush ensures all commands have drawn
    glFlush();

    MyScene->FireGun(x,y);

    glClearColor (0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glutPostRedisplay();
  }
}

// Allows you to still get location of mouse clicks when using menus
extern "C" void menustatus(int status, int x, int y)
{

  glutPostRedisplay();
}  

// Called whenever mouse moves, after being pressed
extern "C" void motion(int x, int y)
{
  MyScene->gun->move(x,win_h-y);
  glutPostRedisplay();
}


// Maintains the mapping from screen to world coordinates.
extern "C" void myReshape(int w, int h)
{
  glViewport(0,0,w,h);
  win_h = h;
  win_w = w;
  glUniform2f(windowSizeLoc, win_w, win_h);       // Pass the window size
						  // size
  glutPostRedisplay();
}

// Example menu code.
extern "C" void myMenu(int value)
{
  switch (value) {
  case 1:
    // Clear screen
    glClear (GL_COLOR_BUFFER_BIT);
    break;
  case 2:
    // Set clear color to red
    glClearColor (1.0, 0.0, 0.0, 1.0);
    break;
  case 3:
    // Set clear color to black
    glClearColor (0.0, 0.0, 0.0, 1.0);
    break;
  default:
    break;
  }
  glutPostRedisplay(); 
}


// Create menu and items.
// %%%
// %%% What happens if we change the menu's numbering scheme?
// %%%
void setupMenu()
{
  glutCreateMenu(myMenu);
  glutAddMenuEntry("clear screen", 1);
  glutAddMenuEntry("red background", 2);
  glutAddMenuEntry("black background", 3);
  /*  glutAddMenuEntry("The Answer", 42);
  glutAddMenuEntry("clear screen", 32);
  glutAddMenuEntry("red background", 22);
  glutAddMenuEntry("black background", 12);*/

  glutAttachMenu(GLUT_RIGHT_BUTTON);
}

// Keypress events.
extern "C" void key(unsigned char k, int xx, int yy)
{
  switch (k) {
  case 'q':
  case 'Q': 
    exit(0);
    break;
  // make the size of the square larger
  case '+':
    break;
  // make the size of the square smaller
  case '-':
    break;
  case 'c':
    clear = !clear;
    break;
  case '>':
    break;
  case '<':
    break;
  case ' ':
      
    break;
  default:
    // Anything else.
    break;
  }
  // Something might have changed requiring redisplay
  glutPostRedisplay();
}

// Special Keys events.
// This one only responds to the up arrow key.
extern "C" void special(int k, int xx, int yy)
{
  switch (k) {
  case GLUT_KEY_UP:
    break;
  case GLUT_KEY_DOWN:
    break;
  case GLUT_KEY_LEFT:
    break;
  case GLUT_KEY_RIGHT:
    break;
  default:
    // do nothing
    break;
  }
  glutPostRedisplay();
}

// Initialize all OpenGL callbacks, create window.
void myinit()
{
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(900,900);
  win_h = 900;
  win_w = 900;
  glutInitWindowPosition(20,20);

  glutCreateWindow("Animation test");

  // Color initializations
  glClearColor(0.0, 0.0, 0.0, 1.0);
  
  // Can you do this?  Attach a menu to a button already
  // used for something else?  
  setupMenu();

  // Callbacks
  glutDisplayFunc(display); 
  glutIdleFunc(idle); 
  glutReshapeFunc (myReshape);
  glutMouseFunc (mouse);
  glutKeyboardFunc(key);
  glutSpecialFunc(special);
  glutPassiveMotionFunc (motion);

  // NOTE: This is not in book. The following sets up a callback
  // whenever a menu is in use.  It gives mouse click location as well
  // as the status of the use of the menu.
  glutMenuStatusFunc(menustatus);
}

// This function initializes the buffers and shaders
void init()
{
  // Locations of variables in shaders.
  // Offset of square
  GLint offsetLoc;
  // Size of square
  GLint sizeLoc;
  // Color of square 
  GLint colorLoc;

  // Create a vertex array object on the GPU
  GLuint vao;
  glGenVertexArrays(1, &vao);
  glBindVertexArray(vao);

  // Create and initialize a buffer object for transferring data to
  // the GPU.
  GLuint buffer;
  glGenBuffers(1, &buffer);
  glBindBuffer(GL_ARRAY_BUFFER, buffer);

  // Load shaders and use the resulting shader program
  GLuint program = InitShader("vshader.glsl", "fshader.glsl");

  // InitShader does the glUseProgram
  // So the following would be redundant
  // glUseProgram(program);

  // Initialize the vertex position attribute from the vertex shader
  windowSizeLoc = glGetUniformLocation(program, "windowSize");

  if (windowSizeLoc==-1) {
    std::cerr << "Unable to find windowSize parameter" << std::endl;
  }
  offsetLoc  = glGetUniformLocation(program, "offset");
  if (offsetLoc==-1) {
    std::cerr << "Unable to find offsetLoc parameter" << std::endl;
  }
  sizeLoc  = glGetUniformLocation(program, "size");
  if (sizeLoc==-1) {
    std::cerr << "Unable to find sizeLoc parameter" << std::endl;
  }
  colorLoc  = glGetUniformLocation(program, "vcolor");
  if (colorLoc==-1) {
    std::cerr << "Unable to find colorLoc parameter" << std::endl;
  }
  GLuint loc = glGetAttribLocation(program, "vPosition");
  glEnableVertexAttribArray(loc);
  glVertexAttribPointer(loc, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

  glUniform2f(offsetLoc, 0.0, 0.0);               // Initial offset
						  // for mouse loc.

  //Init scene object
  MyScene = new Scene(vec2(win_w, win_h));

  // Initialize points for animals
  points = new vec2[Scene::Num_Points];

  //Build scene object
  MyScene->Init(0, points, offsetLoc, sizeLoc, colorLoc);

  // Send the data to the graphics card, after it has been generated
  // by creating the objects in the world (above).
  glBufferData(GL_ARRAY_BUFFER, (Scene::Num_Points)*sizeof(vec2), points, GL_STATIC_DRAW);
}

//  Main Program
int main(int argc, char** argv)
{
  // Several people forgot to put in the following line.  This is an
  // error, even if it still works on your machine, a program is
  // incorrect without the following call to initialize GLUT.
  glutInit(&argc,argv);

  myinit();             // set window attributes, and initial data

  // Initialize the "magic" that glues all the code together.
  glewInit();

  init();               // set up shaders and display environment

  glutMainLoop();       // enter event loop

  return(EXIT_SUCCESS); // return successful exit code
}
