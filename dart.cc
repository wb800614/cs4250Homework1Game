//Class implementation of square object 
// 
// Written by Wesley Book
// 

// last-modified: Fri Oct  6 07:42:10 2017

#include "dart.h"

GLint Dart::NumPoints=18;
bool Dart::inited=false;

void Dart::init_points()
{
  if (!inited && points!=NULL) {
    points[index]= vec2( 0,  0);
    GLfloat delta=(2.0*M_PI)/float(NumPoints-2);
    GLfloat angle=0.0;
    for (size_t ind = 1; ind < NumPoints; ++ind) {
      points[index+ind]=vec2(cos(angle), sin(angle));
      angle+=delta;
    }
    inited=true;
    // Actually send the data we've created to the GPU.
    //    glBufferSubData(GL_ARRAY_BUFFER, index*sizeof(vec2), NumPoints*sizeof(vec2), points);
  }
}

// Default constructor
Dart::Dart() : Object()
{
  isShot = false;
  init_points();
}

// Constructor if start of square vertices aren't at 0.
Dart::Dart(GLuint nindex, vec2 *npoints, GLint noffsetLoc, GLint nsizeLoc, GLint ncolorLoc): Object()
{
  // Default index is the start (0).
  index = nindex;

  // Update the location of the points array from the main program.
  points = npoints;

  // Update the values of where the variables are in the shaders.
  offsetLoc=noffsetLoc;
  sizeLoc=nsizeLoc;
  colorLoc=ncolorLoc;

  init_points();
}

// Code to call to draw a square.
void Dart::draw(bool select_mode)
{
  // Pass the current size of the circle
  glUniform1f(sizeLoc, size);
  glUniform2i(offsetLoc, int(x), int(y));
  glUniform4f(colorLoc, 0.0, 0.0, 0.8, 1.0);

  glDrawArrays(GL_TRIANGLE_FAN, index, NumPoints);
}

// Update the position of the square from time
void Dart::update()
{
  if (isVisible || (glutGet(GLUT_ELAPSED_TIME) - last_time) > timeout)
  {
    isVisible = true;
    const GLfloat max_speed= 200.0/1000.0; // pixels/msec max speed
  
    vec2 dir = vec2(1, 0);

    if (x < ground.x) 
    { 
      dir = (compute_last_update_call_time())*max_speed*normalize(dir);
      // Update location
      x+=dir.x;
    } 
    else 
    {
      isVisible = false;
      y = rand()%((int)window_size.y/2 + 1);
      move(-1, y);
      change_size();
    }
    set_last_time();
  }
  set_last_update_call_time();
}