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
  TrackerOn = false;
  init_points();
}

// Constructor if start of square vertices aren't at 0.
Dart::Dart(GLuint nindex, vec2 *npoints, GLint noffsetLoc, GLint nsizeLoc, GLint ncolorLoc): Object()
{
  //Dart has not been shot yet
  isShot = false;

  //Since dart is not shot yet, tracker is off
  TrackerOn = false;

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

//Set isShot to true
void Dart::Fire_Dart()
{
  isShot = true;
}

//Set tracker on an object
void Dart::Set_Tracker(Animal * t)
{
  TrackerOn = true;
  target = t;
}

// Update the position of the square from time
void Dart::update()
{
  if (isShot)
  {
    if (TrackerOn && target != NULL)
    {
      vec2 new_pos = target -> get_pos();
      move(new_pos.x, new_pos.y);
    }
    //If dart hasn't reached animal yet
    if (size - 0.5 > 0)
      change_size(size-0.5);
    else 
    {
      //Animal is being tracked by dart
      if (TrackerOn && target != NULL)
      {
        //Animal hasn't been hit by dart yet
        if (!target->hit)
          target->animal_hit();
      }
    }
  }
  set_last_update_call_time();
}