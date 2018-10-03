//Class implementation of base object class
// 
// Written by Prof. David M. Chelberg
// 

// last-modified: Fri Oct 25 15:21:44 2013

#include "object.h"

Object::Object()
{
  // Default index is the start (0).
  index = 0;

  // Default Size = 30.0
  size = 30.0;

  // Default color = white.
  r=g=b=1.0;

  // Default selection color = black.
  sr=sg=sb=0.0;

  // Default position is (0, 0)
  x=y=0.0;

  // When did we last update object
  last_time=last_update_call_time=glutGet(GLUT_ELAPSED_TIME);

  // Make sure it is initialize to NULL
  points=NULL;

  //Set not visible
  isVisible = false;
}

// Move the object to (x, y) in screen coordinates
void Object::move(GLfloat nx, GLfloat ny)
{
  if (nx == -1)
    x = size * -1;
  else 
    x = nx;
  y = ny;
}

// Get the current object's position
vec2 Object::get_pos()
{
  return(vec2(x, y));
}

// Change the size of the object.
void Object::change_size(GLfloat nsize)
{
  if (nsize == -1)
    size = 30 - y/22.5;
  else
    size = nsize;
}

//Set current window size
void Object::set_window_size(vec2 window)
{
  window_size = window;
}

// Update the last time object was modified to now.
void Object::set_last_time()
{
  // When did we last update object
  last_time=glutGet(GLUT_ELAPSED_TIME);
}

// Returns the amount of time since we last updated the object.
GLint Object::compute_time()
{
  return(glutGet(GLUT_ELAPSED_TIME)-last_time);
}

// Returns the amount of time since we last updated the object.
GLint Object::compute_last_update_call_time()
{
  return(glutGet(GLUT_ELAPSED_TIME)-last_update_call_time);
}

void Object::set_last_update_call_time()
{
  last_update_call_time = glutGet(GLUT_ELAPSED_TIME);
}

// Change the object's color to r, g, b value
void Object::color(GLfloat nr, GLfloat ng, GLfloat nb)
{
  r = nr; g = ng; b = nb;
}  

// Change the object's color to ncolor's value
void Object::color(vec3 ncolor)
{
  r = ncolor.x;
  g = ncolor.y;
  b = ncolor.z;
}

// Get the object's color as a vec3
vec3 Object::getColor()
{
  return(vec3(r, g, b));
}

// Change the object's color to r, g, b value
void Object::selectColor(GLfloat nr, GLfloat ng, GLfloat nb)
{
  sr = nr; sg = ng; sb = nb;
}  

// Change the object's color to ncolor's value
void Object::selectColor(vec3 ncolor)
{
  sr = ncolor.x;
  sg = ncolor.y;
  sb = ncolor.z;
}

// Get the object's color as a vec3
vec3 Object::getSelectColor()
{
  return(vec3(sr, sg, sb));
}

void Object::set_random_timeout()
{
  timeout = rand()%((int)MAX_TIMEOUT + 1);
  std::cout << timeout << std::endl;
}

//Set ground size
void Object::set_ground(vec2 g)
{
  ground = g;
}

bool cmpcolor(unsigned char colora[], vec3 colorb)
{
  return((colora[0]==int(colorb.x*255+0.5)) &&
	 (colora[1]==int(colorb.y*255+0.5)) &&
	 (colora[2]==int(colorb.z*255+0.5)));
}
