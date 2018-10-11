#ifndef Animal_H
#define Animal_H
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

class Animal :public Object
{
public:
  // How many points are needed to specify the square
  static GLint NumDeerPoints;
  static GLint NumRabbitPoints;
  static GLint NumBearPoints;
  static const int DEER = 1;
  static const int RABBIT = 2;
  static const int BEAR = 3;
  static const int ANGRYBEAR = 4;

  //Whether animal was hit by dart yet
  bool hit;

  //Whether animal has killed player
  bool Animal_Kill;

  GLfloat body_size;

  // Default constructor
  Animal();

  // Constructor if start of square vertices aren't at 0.
  Animal(GLuint nindex, vec2 *npoints, GLint noffsetLoc, GLint nsizeLoc, GLint ncolorLoc);

  // Initialize the points in the points array for square.
  void init_deer_points();
  void init_rabbit_points();
  void init_bear_points();

  void init_deer_laying_points();
  void init_rabbit_laying_points();
  void init_bear_laying_points();

  void init_angry_bear_points();

  // Code to call to draw a square.
  // If select is true, then use the selection color.
  void draw();

  // Update the position of the square from time
  void update();

  //Set body size of animal
  void set_body_size(GLfloat s);

  void set_animal_type(int type);

  void animal_hit();

  void animal_die();

  void animal_sleep();

  void animal_wake();

  void animal_angry();

  void animal_lay_down();

  bool is_laying_down();
  
private:
  bool inited;
  bool laying_inited;
  bool angry_inited;
  bool laying_down;
  bool isAngry;

  int running_direction_x;
  int running_direction_y;
  int animal_type;

  const int TRANQ_RUNTIME = 4000; // 4 seconds before animal sleeps or dies
  const int LEFT = -1;
  const int RIGHT = 1;
  const int UP = 1;
  const int DOWN = -1;
};

#endif
