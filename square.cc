//Class implementation of square object 
// 
// Written by Prof. David M. Chelberg
// 
// Assumes that the square object was defined in the VAO at location
// index

// last-modified: Fri Oct  6 07:42:10 2017

#include "square.h"

GLint Animal1::NumPoints=4;
bool Animal1::inited=false;

void Animal1::init_points()
{
  if (!inited) {
    points[0+index]= vec2( 1,  1);
    points[1+index]= vec2(-1,  1);
    points[3+index]= vec2(-1, -1);
    points[2+index]= vec2( 1, -1);
    inited=true;
    // Actually send the data we've created to the GPU.
    // Can't do this here as we aren't sure we have an open OpenGL window yet.
    //    glBufferSubData(GL_ARRAY_BUFFER, index*sizeof(vec2), NumPoints*sizeof(vec2), points);
  }
}

// Default constructor
Animal1::Animal1() : Object()
{
  init_points();
}

// Constructor if start of square vertices aren't at 0.
Animal1::Animal1(GLuint nindex, vec2 *npoints, GLint noffsetLoc, GLint nsizeLoc, GLint ncolorLoc): Object()
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

//Set ground size
void Animal1::set_ground(vec2 g)
{
  ground = g;
}

// Code to call to draw a square.
void Animal1::draw(bool select_mode)
{
  // Pass the current size of the square
  glUniform1f(sizeLoc, size);
  glUniform2i(offsetLoc, int(x), int(y));
  // Set color on GPU
  if (select_mode) {
    glUniform4f(colorLoc, sr, sg, sb, 1.0);
  } else if (selected) {
    glUniform4f(colorLoc, 0.0, 1.0, 1.0, 1.0);
  } else {
    glUniform4f(colorLoc, r, g, b, 1.0);
  }
  //  std::cout << "Drawing square at (" << x << " " << y << ") color = (" << r << ", " << g << ", " << b << ")" << std::endl;
  glDrawArrays(GL_TRIANGLE_STRIP, index, NumPoints);
}

// Update the position of the square from time
void Animal1::update()
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
 
