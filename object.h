//******************************************************************* 
//                                                                    
//  Program:     Homework 1
//                                                                     
//  Author:      Wesley Book
//  Email:       wb800614@ohio.edu
//                                                                    
//                                                                    
//  Description: File to hold class declaration of object class
//                                                                    
//  Date:        October 11, 2018
//                                                                    
//*******************************************************************
#ifndef OBJECT_H
#define OBJECT_H


#include <Angel.h>
#include <iostream>
#include <stdlib.h>

class Object 
{
  public:

  // Default constructor
  Object();
  
  // Move the object to (x, y) in screen coordinates
  void move(GLfloat nx, GLfloat ny);

  // Change the object's color to r, g, b value
  void color(GLfloat nr, GLfloat ng, GLfloat nb);

  // Change the object's color to ncolor's value
  void color(vec3 ncolor);

  // Get the object's color as a vec3
  vec3 getColor();

  // Change the size of the object.
  void change_size(GLfloat size = -1);

  // Get the current object's position
  vec2 get_pos();

  // Get the current object's size
  GLfloat get_size();

  void set_window_size(vec2 window);

  // Update the last updated time to now.
  void set_last_time();

  //Update the last update function call time
  void set_last_update_call_time();

  //Function to set timeout
  void set_random_timeout();

  //Set ground size
  void set_ground(vec2 g);

  // Returns the time since the last update
  GLint compute_time();

  GLint compute_last_update_call_time();


protected:
  //Size of current window
  vec2 window_size;
  vec2 ground;

  // size of object (see individual objects for specific meaning)
  GLfloat size; 

  //Max height and width of animal
  GLfloat max_h;
  GLfloat max_w;

  GLfloat timeout; //time that object waits before initial move (milliseconds)

  // location of object (x, y)
  GLfloat x;      
  GLfloat y; 

  // Color of object
  GLfloat r;
  GLfloat g;
  GLfloat b;

  // Start of vertices to draw in VAO
  GLuint index;
  // Pointer to the points array
  vec2 *points;

  // Locations of variables in shaders.
  // Offset of object
  GLint offsetLoc;
  // Size of object
  GLint sizeLoc;
  // Color of object 
  GLint colorLoc;
  
  // For smooth animation consistent across machines
  GLint last_time;
  GLint last_update_call_time;

  //Whether current object is in viewing range
  bool isVisible;


  //Constants
  //Max timeout possible
  GLint MAX_TIMEOUT = 10000; //10 seconds
  GLfloat DEATH_TIME = 2000; //2 seconds
};

#endif
