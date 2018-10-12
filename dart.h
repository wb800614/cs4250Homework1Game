//******************************************************************* 
//                                                                    
//  Program:     Homework 1
//                                                                     
//  Author:      Wesley Book
//  Email:       wb800614@ohio.edu
//                                                                    
//                                                                    
//  Description: File to hold class declaration of dart class
//                                                                    
//  Date:        October 11, 2018
//                                                                    
//*******************************************************************
#ifndef DART_H
#define DART_H

#include <Angel.h>
#include <iostream>
#include <stdlib.h>
#include "object.h"
#include "animal.h"

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

  //Set isShot to true
  void Fire_Dart();

  //Set tracker on an object
  void Set_Tracker(Animal * target);

  // Code to call to draw a square.
  // If select is true, then use the selection color.
  void draw();

  // Update the position of the square from time
  void update();
  
private:
  //Whether points have been created to draw dart
  static bool inited;
  //Whether dart has been shot
  bool isShot;

  //Dart tracking bit and target animal
  bool TrackerOn;
  Animal * target;
};

#endif