#ifndef ANIMAL1_H
#define ANIMAL1_H
//Class definition of square object 
// 
// Written by Prof. David M. Chelberg
// 
// Assumes that the square object was defined in the VAO at location
// index

// last-modified: Fri Oct 25 15:22:05 2013

#include <Angel.h>
#include <iostream>
#include <stdlib.h>
#include "object.h"

class Animal1 :public Object
{
public:
  // How many points are needed to specify the square
  static GLint NumPoints;

  // Default constructor
  Animal1();

  // Constructor if start of square vertices aren't at 0.
  Animal1(GLuint nindex, vec2 *npoints, GLint noffsetLoc, GLint nsizeLoc, GLint ncolorLoc);

  // Initialize the points in the points array for square.
  void init_points();

  // Code to call to draw a square.
  // If select is true, then use the selection color.
  void draw(bool select=false);

  // Update the position of the square from time
  void update();

  //Set Ground Size
  void set_ground(vec2 g);
  
private:
  static bool inited;
  //Size of ground
  vec2 ground;

};

#endif
