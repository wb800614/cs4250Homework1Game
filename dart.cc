//******************************************************************* 
//                                                                    
//  Program:     Homework 1
//                                                                     
//  Author:      Wesley Book
//  Email:       wb800614@ohio.edu
//                                                                    
//                                                                    
//  Description: File to hold class definition for dart class
//               left over.
//                                                                    
//  Date:        October 11, 2018
//                                                                    
//*******************************************************************

#include "dart.h"

GLint Dart::NumPoints=18;
bool Dart::inited=false;

//******************************************************************
      //                                                                  
      //  Function:   init_points
      //                                                                  
      //  Purpose:    Initialize points for a dart                                
      //                                                                  
      //  Parameters: none
      //                                                                  
      // Member/Global Variables: points, index, inited
      //
      // Pre Conditions: points != NULL
      //
      // Post Conditions: returns void. points array will hold new values to be stored as the points to make up a dart
      //
      //                                                                  
      //******************************************************************
void Dart::init_points()
{
  if (!inited && points!=NULL) {
    points[index]= vec2( 0,  0);
    GLfloat delta=(2.0*M_PI)/float(NumPoints-2);
    GLfloat angle=0.0;
    for (size_t ind = 1; ind < NumPoints; ++ind) {
      points[index+ind]=vec2(cos(angle), sin(angle));
      angle+=delta;
    }
    inited=true;
    // Actually send the data we've created to the GPU.
    //    glBufferSubData(GL_ARRAY_BUFFER, index*sizeof(vec2), NumPoints*sizeof(vec2), points);
  }
}

//******************************************************************
      //                                                                  
      //  Function:   Dart
      //                                                                  
      //  Purpose:    Constructor for darts                               
      //                                                                  
      //  Parameters: none
      //                                                                  
      // Member/Global Variables: isshot, trackeron
      //
      // Pre Conditions: points != NULL
      //
      // Post Conditions: returns void. initializes tracker off and not shot, then initializes points
      //
      //                                                                  
      //******************************************************************
Dart::Dart() : Object()
{
  isShot = false;
  TrackerOn = false;
  init_points();
}

//******************************************************************
      //                                                                  
      //  Function:   Dart
      //                                                                  
      //  Purpose:    constructor for dart                               
      //                                                                  
      //  Parameters: GLuint nindex, vec2 *npoints, GLint noffsetLoc, GLint nsizeLoc, GLint ncolorLoc
      //                                                                  
      // Member/Global Variables: points, index, inited
      //
      // Pre Conditions: points != NULL
      //
      // Post Conditions: returns void. initializes all member variables to help draw dart
      //
      //                                                                  
      //******************************************************************
Dart::Dart(GLuint nindex, vec2 *npoints, GLint noffsetLoc, GLint nsizeLoc, GLint ncolorLoc): Object()
{
  //Dart has not been shot yet
  isShot = false;

  //Since dart is not shot yet, tracker is off
  TrackerOn = false;

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
      //  Purpose:    draws dart                              
      //                                                                  
      //  Parameters: s
      //                                                                  
      // Member/Global Variables: points, index, inited
      //
      // Pre Conditions: points != NULL
      //
      // Post Conditions: returns void. gets dart ready to be viewed once buffer is switched
      //
      //                                                                  
      //******************************************************************
void Dart::draw()
{
  // Pass the current size of the circle
  glUniform1f(sizeLoc, size);
  glUniform2i(offsetLoc, int(x), int(y));
  glUniform4f(colorLoc, 0.0, 0.0, 0.8, 1.0);

  glDrawArrays(GL_TRIANGLE_FAN, index, NumPoints);
}

//******************************************************************
      //                                                                  
      //  Function:   Fire_Dart
      //                                                                  
      //  Purpose:    set isshot flag to true                              
      //                                                                  
      //  Parameters: none
      //                                                                  
      // Member/Global Variables: isShot
      //
      // Pre Conditions: points != NULL
      //
      // Post Conditions: returns void. sets flag letting program know that dart has been shot
      //
      //                                                                  
      //******************************************************************
void Dart::Fire_Dart()
{
  isShot = true;
}

//******************************************************************
      //                                                                  
      //  Function:   Set_Tracker
      //                                                                  
      //  Purpose:    set dart tracer on animal                               
      //                                                                  
      //  Parameters: Animal * t (pointer to animal)
      //                                                                  
      // Member/Global Variables: target, trackeron
      //
      // Pre Conditions: points != NULL
      //
      // Post Conditions: returns void. sets tracker on target animal
      //
      //                                                                  
      //******************************************************************
void Dart::Set_Tracker(Animal * t)
{
  TrackerOn = true;
  target = t;
}

//******************************************************************
      //                                                                  
      //  Function:   update
      //                                                                  
      //  Purpose:    Updates information for dart like size and location                             
      //                                                                  
      //  Parameters: none
      //                                                                  
      // Member/Global Variables: points, index, inited
      //
      // Pre Conditions: points != NULL
      //
      // Post Conditions: returns void. updates dart with new position and size
      //
      //                                                                  
      //******************************************************************
void Dart::update()
{
  if (isShot)
  {
    if (TrackerOn && target != NULL)
    {
      vec2 new_pos = target -> get_pos();
      move(new_pos.x, new_pos.y);
    }
    //If dart hasn't reached animal yet
    if (size - 0.5 > 0)
      change_size(size-0.5);
    else 
    {
      //Animal is being tracked by dart
      if (TrackerOn && target != NULL)
      {
        //Animal hasn't been hit by dart yet
        if (!target->hit)
          target->animal_hit();
      }
    }
  }
  set_last_update_call_time();
}