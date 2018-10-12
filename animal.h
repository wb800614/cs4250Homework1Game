//******************************************************************* 
//                                                                    
//  Program:     Homework 1
//                                                                     
//  Author:      Wesley Book
//  Email:       wb800614@ohio.edu
//                                                                    
//                                                                    
//  Description: File to hold class declaration of an Animal
//               left over.
//                                                                    
//  Date:        October 11, 2018
//                                                                    
//*******************************************************************

#ifndef Animal_H
#define Animal_H

#include <Angel.h>
#include <iostream>
#include <stdlib.h>
#include "object.h"

class Animal :public Object
{
public:
  // How many points are needed to specify each animal
  static GLint NumDeerPoints;
  static GLint NumRabbitPoints;
  static GLint NumBearPoints;

  //Constants to define animals
  static const int DEER = 1;
  static const int RABBIT = 2;
  static const int BEAR = 3;
  static const int ANGRYBEAR = 4;

  //Whether animal was hit by dart yet
  bool hit;

  //Whether animal has killed player
  bool Animal_Kill;

  //Body side of animal (10 - Deer, 20 - Rabbit, 30 - Bear)
  GLfloat body_size;

  // Default constructor
  Animal();

  // Constructor if start of square vertices aren't at 0.
  Animal(GLuint nindex, vec2 *npoints, GLint noffsetLoc, GLint nsizeLoc, GLint ncolorLoc);

  // Initialize the points in the points array for each animal.
  void init_deer_points();
  void init_rabbit_points();
  void init_bear_points();

  //Initialize the points in the points array for each animal laying
  void init_deer_laying_points();
  void init_rabbit_laying_points();
  void init_bear_laying_points();

  //Initialize points in the points array for an angry bear coming to kill you
  void init_angry_bear_points();

  // Draw each object based on the animal type
  void draw();

  // Update the position of the square from time
  void update();

  //Set body size of animal
  void set_body_size(GLfloat s);

  //Set the animal type (deer, rabbit, or bear)
  void set_animal_type(int type);

  //Sets that the animal was hit
  void animal_hit();

  //Called when animal dies from too high of dose
  void animal_die();

  //Called when dose for animal is just right
  void animal_sleep();

  //Called when dose is less than what was needed to put animal to sleep
  void animal_wake();

  //Called when dose is less than what was needed to put animal to sleep and animal begins to come after you
  void animal_angry();

  //Called when animal is hit with a dart and running time was up
  void animal_lay_down();

  //Returns whether animal has been hit with a dart and is laying down
  bool is_laying_down();

  //Returns whether animal is dead or sleeping
  bool is_done();
  
private:
  //Whether points are inited for animal
  bool inited;
  //Whether points are inited for animal laying down
  bool laying_inited;
  //Whether points are intited for angry animal
  bool angry_inited;
  //Whether animal is laying down from being shot or not
  bool laying_down;
  //Whether animal has been shot with dose lower than what was required to put animal to sleep and is angry
  bool isAngry;
  //Whether animal has died or sleeping
  bool done;

  //Direction animal is running (Left or right)
  int running_direction_x;
  //Direction animal is running (Up or down)
  int running_direction_y;
  //Variable to hold what type the animal is
  int animal_type;

  //Constant to hold how long the animal will run around after hit with dart
  const int TRANQ_RUNTIME = 4000; // 4 seconds before animal sleeps or dies

  //Constants to hold directions in x and y
  const int LEFT = -1;
  const int RIGHT = 1;
  const int UP = 1;
  const int DOWN = -1;
};

#endif
