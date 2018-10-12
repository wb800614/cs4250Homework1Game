//******************************************************************* 
//                                                                    
//  Program:     Homework 1
//                                                                     
//  Author:      Wesley Book
//  Email:       wb800614@ohio.edu
//                                                                    
//                                                                    
//  Description: File to hold class declaration of obstacle class
//                                                                    
//  Date:        October 11, 2018
//                                                                    
//*******************************************************************

#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <Angel.h>
#include <iostream>
#include <stdlib.h>
#include "object.h"

class Obstacle :public Object
{
public:
  //Constants to define animals
  static const int Num_Tree_Points = 11;
  static const int Num_Bush_Points = 10;
  static const int Num_Grass_Points = 24;
  static const int TREE = 1;
  static const int BUSH = 2;
  static const int GRASS = 3;

  // Default constructor
  Obstacle();

  //Initializers for points for obstables
  void init_tree_points();
  void init_bush_points();
  void init_grass_points();

  // Constructor if start of square vertices aren't at 0.
  Obstacle(GLuint nindex, vec2 *npoints, GLint noffsetLoc, GLint nsizeLoc, GLint ncolorLoc);

  // Draw each object based on the animal type
  void draw();

  //Set type of obstacle (tree grass or bush)
  void set_obstacle_type(int t);
  
private:
  //Whether points are inited for animal
  bool inited;
  //Variable to hold what type the animal is
  int obstacle_type;
};

#endif