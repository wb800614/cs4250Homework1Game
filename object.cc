//******************************************************************* 
//                                                                    
//  Program:     Homework 1
//                                                                     
//  Author:      Wesley Book
//  Email:       wb800614@ohio.edu
//                                                                    
//                                                                    
//  Description: File to hold class definition for object class
//                                                                    
//  Date:        October 11, 2018
//                                                                    
//*******************************************************************

#include "object.h"

//******************************************************************
      //                                                                  
      //  Function:   Object
      //                                                                  
      //  Purpose:    default constructor to set variables to default                            
      //                                                                  
      //  Parameters: none
      //                                                                  
      // Member/Global Variables: points, index, inited
      //
      // Pre Conditions: points != NULL
      //
      // Post Conditions: returns void. sets variables to defaul values for program
      //
      //                                                                  
      //******************************************************************
Object::Object()
{
  // Default index is the start (0).
  index = 0;

  // Default Size = 30.0
  size = 30.0;

  // Default color = white.
  r=g=b=1.0;

  // Default position is (0, 0)
  x=y=0.0;

  // When did we last update object
  last_time=last_update_call_time=glutGet(GLUT_ELAPSED_TIME);

  // Make sure it is initialize to NULL
  points=NULL;

  //Set not visible
  isVisible = false;
}

//******************************************************************
      //                                                                  
      //  Function:   move
      //                                                                  
      //  Purpose:    moves object ot nx,ny                            
      //                                                                  
      //  Parameters: none
      //                                                                  
      // Member/Global Variables: points, index, inited
      //
      // Pre Conditions: points != NULL
      //
      // Post Conditions: returns void.
      //
      //                                                                  
      //******************************************************************
void Object::move(GLfloat nx, GLfloat ny)
{
  if (nx == -1)
    x = size * -1;
  else 
    x = nx;
  y = ny;
}

//******************************************************************
      //                                                                  
      //  Function:   get_pos
      //                                                                  
      //  Purpose:    return location of object on screen
      //                                                                  
      //  Parameters: none
      //                                                                  
      // Member/Global Variables: x,y
      //
      // Pre Conditions: points != NULL
      //
      // Post Conditions: returns void. 
      //
      //                                                                  
      //******************************************************************
vec2 Object::get_pos()
{
  return(vec2(x, y));
}

//******************************************************************
      //                                                                  
      //  Function:   change_size
      //                                                                  
      //  Purpose:    changes size of object based on value passed in                           
      //                                                                  
      //  Parameters: GLfloat nsize
      //                                                                  
      // Member/Global Variables: size
      //
      // Pre Conditions: points != NULL
      //
      // Post Conditions: returns void. 
      //
      //                                                                  
      //******************************************************************
void Object::change_size(GLfloat nsize)
{
  if (nsize == -1)
    size = 30 - y/22.5;
  else
    size = nsize;
}

//******************************************************************
      //                                                                  
      //  Function:   set_window_size
      //                                                                  
      //  Purpose:    set the window size to vector passed in                            
      //                                                                  
      //  Parameters: vec2 window
      //                                                                  
      // Member/Global Variables: window_size
      //
      // Pre Conditions: points != NULL
      //
      // Post Conditions: returns void. 
      //
      //                                                                  
      //******************************************************************
void Object::set_window_size(vec2 window)
{
  window_size = window;
}

//******************************************************************
      //                                                                  
      //  Function:   set_last_time
      //                                                                  
      //  Purpose:    set last_time to the last time glutget was called                             
      //                                                                  
      //  Parameters: none
      //                                                                  
      // Member/Global Variables: last_time
      //
      // Pre Conditions: points != NULL
      //
      // Post Conditions: returns void. gets gun ready to be viewed on next swap of buffers
      //
      //                                                                  
      //******************************************************************
void Object::set_last_time()
{
  // When did we last update object
  last_time=glutGet(GLUT_ELAPSED_TIME);
}

//******************************************************************
      //                                                                  
      //  Function:   compute_time
      //                                                                  
      //  Purpose:    computes the current time to last time                          
      //                                                                  
      //  Parameters: none
      //                                                                  
      // Member/Global Variables: last_time
      //
      // Pre Conditions: points != NULL
      //
      // Post Conditions: returns glint holding the elapased time
      //
      //                                                                  
      //******************************************************************
GLint Object::compute_time()
{
  return(glutGet(GLUT_ELAPSED_TIME)-last_time);
}

//******************************************************************
      //                                                                  
      //  Function:   compute_last_update_call_time
      //                                                                  
      //  Purpose:    returns the current time minus the last_update_call_time                           
      //                                                                  
      //  Parameters: none
      //                                                                  
      // Member/Global Variables: last_update_call_time
      //
      // Pre Conditions: points != NULL
      //
      // Post Conditions: returns GLint
      //
      //                                                                  
      //******************************************************************
GLint Object::compute_last_update_call_time()
{
  return(glutGet(GLUT_ELAPSED_TIME)-last_update_call_time);
}

//******************************************************************
      //                                                                  
      //  Function:   set_last_update_call_time
      //                                                                  
      //  Purpose:    sets the last update call time                          
      //                                                                  
      //  Parameters: none
      //                                                                  
      // Member/Global Variables: last_update_call_time
      //
      // Pre Conditions: points != NULL
      //
      // Post Conditions: returns void.
      //
      //                                                                  
      //******************************************************************
void Object::set_last_update_call_time()
{
  last_update_call_time = glutGet(GLUT_ELAPSED_TIME);
}

//******************************************************************
      //                                                                  
      //  Function:   color
      //                                                                  
      //  Purpose:    sets color of objec based on values passed in                            
      //                                                                  
      //  Parameters: GLfloat nr, GLfloat ng, GLfloat nb
      //                                                                  
      // Member/Global Variables: points, index, inited
      //
      // Pre Conditions: points != NULL
      //
      // Post Conditions: returns void
      //
      //                                                                  
      //******************************************************************
void Object::color(GLfloat nr, GLfloat ng, GLfloat nb)
{
  r = nr; g = ng; b = nb;
}  

//******************************************************************
      //                                                                  
      //  Function:   color
      //                                                                  
      //  Purpose:    sets color of object based on values passed in                            
      //                                                                  
      //  Parameters: vec3 ncolor
      //                                                                  
      // Member/Global Variables: r,g,b
      //
      // Pre Conditions: points != NULL
      //
      // Post Conditions: returns void.
      //
      //                                                                  
      //******************************************************************
void Object::color(vec3 ncolor)
{
  r = ncolor.x;
  g = ncolor.y;
  b = ncolor.z;
}

//******************************************************************
      //                                                                  
      //  Function:   getColor
      //                                                                  
      //  Purpose:    return color                            
      //                                                                  
      //  Parameters: none
      //                                                                  
      // Member/Global Variables: r,g,b
      //
      // Pre Conditions: points != NULL
      //
      // Post Conditions: returns vec3 holding rg,b
      //
      //                                                                  
      //******************************************************************
vec3 Object::getColor()
{
  return(vec3(r, g, b));
}

//******************************************************************
      //                                                                  
      //  Function:   get_size
      //                                                                  
      //  Purpose:    returns the size of the object                           
      //                                                                  
      //  Parameters: none
      //                                                                  
      // Member/Global Variables: size
      //
      // Pre Conditions: points != NULL
      //
      // Post Conditions: returns GLfloat
      //
      //                                                                  
      //******************************************************************
GLfloat Object::get_size()
{
  return size;
}

//******************************************************************
      //                                                                  
      //  Function:   set_random_timeout
      //                                                                  
      //  Purpose:    gets a random timeout with domain 1 - MAX_TIMEOUT                            
      //                                                                  
      //  Parameters: none
      //                                                                  
      // Member/Global Variables: MAX_TIMEOUT
      //
      // Pre Conditions: points != NULL
      //
      // Post Conditions: returns void.
      //
      //                                                                  
      //******************************************************************
void Object::set_random_timeout()
{
  timeout = rand()%((int)MAX_TIMEOUT + 1);
}

//******************************************************************
      //                                                                  
      //  Function:   set_ground
      //                                                                  
      //  Purpose:    sets ground variable based on value passed in                            
      //                                                                  
      //  Parameters: vec2 g
      //                                                                  
      // Member/Global Variables: ground
      //
      // Pre Conditions: points != NULL
      //
      // Post Conditions: returns void.
      //
      //                                                                  
      //******************************************************************
void Object::set_ground(vec2 g)
{
  ground = g;
}
