#ifndef DART_H
#define DART_H
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

class Dart :public Object
{
public:
  // How many points are needed to specify the gun
  static GLint NumPoints;

  // Default constructor
  Dart();

  // Constructor if start of square vertices aren't at 0.
  Dart(GLuint nindex, vec2 *npoints, GLint noffsetLoc, GLint nsizeLoc, GLint ncolorLoc);

  // Initialize the points in the points array for square.
  void init_points();

  // Code to call to draw a square.
  // If select is true, then use the selection color.
  void draw(bool select=false);

  // Update the position of the square from time
  void update();
  
private:
  static bool inited;
  bool isShot;
};

#endif