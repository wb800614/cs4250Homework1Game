//Class implementation of square object 
// 
// Written by Prof. David M. Chelberg
// 
// Assumes that the square object was defined in the VAO at location
// index

// last-modified: Fri Oct  6 07:42:10 2017

#include "square.h"

GLint Animal::NumPoints=4;
bool Animal::inited=false;

void Animal::init_points()
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
Animal::Animal() : Object()
{
  //Default Body Size = 10.0
  body_size = 10;

  //Animal hasn't been hit yet
  hit = false;

  laying_down = false;

  //What direction the animal is running 
  running_direction_x = RIGHT;
  running_direction_y = DOWN;

  init_points();
}

// Constructor if start of square vertices aren't at 0.
Animal::Animal(GLuint nindex, vec2 *npoints, GLint noffsetLoc, GLint nsizeLoc, GLint ncolorLoc): Object()
{
  // Default index is the start (0).
  index = nindex;

  //What direction the animal is running 
  running_direction_x = RIGHT;
  running_direction_y = DOWN;

  //Animal hasn't been hit yet
  hit = false;

  laying_down = false;

  // Update the location of the points array from the main program.
  points = npoints;

  // Update the values of where the variables are in the shaders.
  offsetLoc=noffsetLoc;
  sizeLoc=nsizeLoc;
  colorLoc=ncolorLoc;

  init_points();
}

// Code to call to draw a square.
void Animal::draw(bool select_mode)
{
  // Pass the current size of the square
  glUniform1f(sizeLoc, size);
  glUniform2i(offsetLoc, int(x), int(y));
  glUniform4f(colorLoc, r, g, b, 1.0);
  //  std::cout << "Drawing square at (" << x << " " << y << ") color = (" << r << ", " << g << ", " << b << ")" << std::endl;
  glDrawArrays(GL_TRIANGLE_STRIP, index, NumPoints);
}

// Update the position of the square from time
void Animal::update()
{
  if (hit)
  {
    if (glutGet(GLUT_ELAPSED_TIME)-last_time < TRANQ_RUNTIME) 
    {
      const GLfloat max_speed= 400.0/1000.0;
      vec2 dir = vec2(1, 0);

      if (x >= window_size.x) 
        running_direction_x = LEFT;
      if (x <= 0)
        running_direction_x = RIGHT;
      dir = (compute_last_update_call_time())*max_speed*normalize(dir);
      // Update location
      x+=(dir.x * running_direction_x);
    }
    else 
    {
      hit = false;
      isVisible = false;
      set_last_time();
      animal_fall();
      laying_down = true;
    }
  }
  else if ((isVisible || (glutGet(GLUT_ELAPSED_TIME) - last_time) > timeout) && !laying_down)
  {
    isVisible = true;
    const GLfloat max_speed= 200.0/1000.0; // pixels/msec max speed
  
    vec2 dir = vec2(1, 1);

    if (x < window_size.x) 
    { 
      dir = (compute_last_update_call_time())*max_speed*normalize(dir);
      // Update location
      x+=dir.x;
      if (y >= window_size.y/2)
        running_direction_y = DOWN;
      if (y <= 0)
        running_direction_y = UP;
      y+=(dir.y * running_direction_y);
      change_size();
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

void Animal::set_body_size(GLfloat s)
{
  body_size = s;
}

void Animal::animal_hit()
{
  hit = true;
}

//Draw animal dead (dose was too strong for animal size)
void Animal::animal_die()
{

}

//Draw animal laying dead
void Animal::animal_fall()
{
  
}
 
