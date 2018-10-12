//******************************************************************* 
//                                                                    
//  Program:     Homework 1
//                                                                     
//  Author:      Wesley Book
//  Email:       wb800614@ohio.edu
//                                                                    
//                                                                    
//  Description: File to hold class definition of gun class
//                                                                    
//  Date:        October 11, 2018
//                                                                    
//*******************************************************************

#include "gun.h"

GLint Gun::NumPoints=4;
bool Gun::inited=false;

//******************************************************************
      //                                                                  
      //  Function:   init_points
      //                                                                  
      //  Purpose:    Initialize points for the gun                                
      //                                                                  
      //  Parameters: none
      //                                                                  
      // Member/Global Variables: points, index, inited
      //
      // Pre Conditions: points != NULL
      //
      // Post Conditions: returns void. points array will hold new values to be stored as the points to make up a gun
      //
      //                                                                  
      //******************************************************************
void Gun::init_points()
{
  if (!inited) {
    points[0+index]= vec2( 0, crosshair_size);
    points[1+index]= vec2(0,  -1*crosshair_size);
    points[2+index]= vec2(-1*crosshair_size, 0);
    points[3+index]= vec2( crosshair_size, 0);
    inited=true;
  }
}

//******************************************************************
      //                                                                  
      //  Function:   Gun
      //                                                                  
      //  Purpose:    Constructor                              
      //                                                                  
      //  Parameters: none
      //                                                                  
      // Member/Global Variables: points, index, inited
      //
      // Pre Conditions: points != NULL
      //
      // Post Conditions: returns void. calls function to initialize points
      //
      //                                                                  
      //******************************************************************
Gun::Gun() : Object()
{
  init_points();
}

//******************************************************************
      //                                                                  
      //  Function:   Gun
      //                                                                  
      //  Purpose:    Constructor to set up information to draw gun                               
      //                                                                  
      //  Parameters: GLuint nindex, vec2 *npoints, GLint noffsetLoc, GLint nsizeLoc, GLint ncolorLoc
      //                                                                  
      // Member/Global Variables: points, index, inited
      //
      // Pre Conditions: points != NULL
      //
      // Post Conditions: returns void. sets all member variables to help draw gun
      //
      //                                                                  
      //******************************************************************
Gun::Gun(GLuint nindex, vec2 *npoints, GLint noffsetLoc, GLint nsizeLoc, GLint ncolorLoc): Object()
{
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

//******************************************************************
      //                                                                  
      //  Function:   draw
      //                                                                  
      //  Purpose:    draw gun                             
      //                                                                  
      //  Parameters: none
      //                                                                  
      // Member/Global Variables: points, index, inited
      //
      // Pre Conditions: points != NULL
      //
      // Post Conditions: returns void. gets gun ready to be viewed on next swap of buffers
      //
      //                                                                  
      //******************************************************************
void Gun::draw()
{
  glUniform2i(offsetLoc, int(x), int(y));
  glUniform4f(colorLoc, 0.0, 0.0, 0.0, 1.0);
  glDrawArrays(GL_LINES, index, NumPoints);
}

//******************************************************************
      //                                                                  
      //  Function:   update
      //                                                                  
      //  Purpose:    Calls setlastupdatecalltime                               
      //                                                                  
      //  Parameters: none
      //                                                                  
      // Member/Global Variables: none
      //
      // Pre Conditions: points != NULL
      //
      // Post Conditions: returns void. calls function to set the last time the upate function is called
      //
      //                                                                  
      //******************************************************************
void Gun::update()
{
  set_last_update_call_time();
}