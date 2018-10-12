//******************************************************************* 
//                                                                    
//  Program:     Homework 1
//                                                                     
//  Author:      Wesley Book
//  Email:       wb800614@ohio.edu
//                                                                    
//                                                                    
//  Description: File to hold class declaration of the gun class
//                                                                    
//  Date:        October 11, 2018
//                                                                    
//*******************************************************************
#ifndef GUN_H
#define GUN_H

#include <Angel.h>
#include <iostream>
#include <stdlib.h>
#include "object.h"

class Gun :public Object
{
public:
  // How many points are needed to specify the gun
  static GLint NumPoints;

  // Default constructor
  Gun();

  // Constructor if start of square vertices aren't at 0.
  Gun(GLuint nindex, vec2 *npoints, GLint noffsetLoc, GLint nsizeLoc, GLint ncolorLoc);

  // Initialize the points in the points array for square.
  void init_points();

  // Code to call to draw a square.
  // If select is true, then use the selection color.
  void draw();

  // Update the position of the square from time
  void update();
  
private:
  //Whether points have been added to create gun
  static bool inited;
  //Size of crosshair
  GLint crosshair_size = 900;

};

#endif