//Class implementation of square object 
// 
// Written by Wesley Book
// 

// last-modified: Fri Oct  6 07:42:10 2017

#include "gun.h"

GLint Gun::NumPoints=4;
bool Gun::inited=false;

void Gun::init_points()
{
  if (!inited) {
    points[0+index]= vec2( 0, crosshair_size);
    points[1+index]= vec2(0,  -1*crosshair_size);
    points[2+index]= vec2(-1*crosshair_size, 0);
    points[3+index]= vec2( crosshair_size, 0);
    inited=true;
    // Actually send the data we've created to the GPU.
    // Can't do this here as we aren't sure we have an open OpenGL window yet.
    //    glBufferSubData(GL_ARRAY_BUFFER, index*sizeof(vec2), NumPoints*sizeof(vec2), points);
  }
}

// Default constructor
Gun::Gun() : Object()
{
  init_points();
}

// Constructor if start of square vertices aren't at 0.
Gun::Gun(GLuint nindex, vec2 *npoints, GLint noffsetLoc, GLint nsizeLoc, GLint ncolorLoc): Object()
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
void Gun::draw(bool select_mode)
{
  glUniform2i(offsetLoc, int(x), int(y));
  glUniform4f(colorLoc, 0.0, 0.0, 0.0, 1.0);
  glDrawArrays(GL_LINES, index, NumPoints);
}

// Update the position of the square from time
void Gun::update()
{
  set_last_update_call_time();
}