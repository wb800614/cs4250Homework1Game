//******************************************************************* 
//                                                                    
//  Program:     Homework 1
//                                                                     
//  Author:      Wesley Book
//  Email:       wb800614@ohio.edu
//                                                                    
//                                                                    
//  Description: File to hold class definition for the Animal class
//                                                                    
//  Date:        October 11, 2018
//                                                                    
//*******************************************************************

#include "animal.h"

GLint Animal::NumDeerPoints = 30;
GLint Animal::NumRabbitPoints = 16;
GLint Animal::NumBearPoints = 31;

//******************************************************************
      //                                                                  
      //  Function:   init_deer_points
      //                                                                  
      //  Purpose:    Initialize points for a deer                                
      //                                                                  
      //  Parameters: none
      //                                                                  
      // Member/Global Variables: points, index, inited
      //
      // Pre Conditions: points != NULL
      //
      // Post Conditions: returns void. points array will hold new values to be stored as the points to make up a deer
      //
      //                                                                  
      //******************************************************************
void Animal::init_deer_points()
{
  if (!inited)
  {
    animal_type = DEER;
    //Back and top of nect
    points[index++]= vec2(-1,  1);
    points[index++]= vec2(0, 0.9);
    points[index++]= vec2(1,  1);
    points[index++]= vec2(1.3, 1.3);

    //Ear
    points[index++]= vec2(1.25, 1.45);
    points[index++]= vec2(1.25, 1.47);
    points[index++]= vec2(1.27, 1.5);
    points[index++]= vec2(1.35, 1.52);

    //Head shape
    points[index++]= vec2(1.37, 1.25);
    points[index++]= vec2(1.65, 1.22);
    points[index++]= vec2(1.7, 1.15);
    points[index++]= vec2(1.75, 1.15);
    points[index++]= vec2(1.9, 1.1);

    //Nose
    points[index++]= vec2(2.0, 1.0);
    points[index++]= vec2(2.0, 0.9);

    //Bottom of head (jaw)
    points[index++]= vec2(1.6, 0.83);
    points[index++]= vec2(1.4, 0.82);
    points[index++]= vec2(1.3, 0.80);
    points[index++]= vec2(1.1, 0.7);

    //Front leg
    points[index++]= vec2(1, -1);
    points[index++]= vec2(0.9, -1);
    points[index++]= vec2(0.8, 0.5);
    points[index++]= vec2(0.2, 0.3);
    points[index++]= vec2(-1, 0.5);

    //Back leg
    points[index++]= vec2(-1, -1);
    points[index++]= vec2(-1.1, -1);

    //Tail
    points[index++]= vec2(-1.3, 0.5);
    points[index++]= vec2(-1.35, 1.0);
    points[index++]= vec2(-1.38, 0.65);
    points[index++]= vec2(-1.4, 0.7);

    //Set index back to original
    index-=30;
    inited = true;
  }
}

//******************************************************************
      //                                                                  
      //  Function:   init_deer_laying_points
      //                                                                  
      //  Purpose:    Initialize points for a deer laying down                               
      //                                                                  
      //  Parameters: none
      //                                                                  
      // Member/Global Variables: points, index, inited
      //
      // Pre Conditions: points != NULL
      //
      // Post Conditions: returns void. points array will hold new values to be stored as the points to make up a deer laying down
      //
      //                                                                  
      //******************************************************************
void Animal::init_deer_laying_points()
{
    //Back and top of nect
    points[index++]= vec2(-1,  1);
    points[index++]= vec2(-0.9, 1.1);
    points[index++]= vec2(-0.8,  1.2);
    points[index++]= vec2(-0.4, 1.3);
    points[index++]= vec2(-0.2, 1.35);
    points[index++]= vec2(-0.1, 1.37);
    points[index++]= vec2(0.0, 1.375);
    points[index++]= vec2(0.1, 1.37);
    points[index++]= vec2(0.2, 1.35);
    points[index++]= vec2(0.4, 1.3);
    points[index++]= vec2(0.8, 1.2);
    points[index++]= vec2(0.9, 1.05);
    points[index++]= vec2(1.0, 1.05);

    //Nose
    points[index++]= vec2(1.2, 1.05);
    points[index++]= vec2(1.24, 1.05);
    points[index++]= vec2(1.33, 1.1);
    points[index++]= vec2(1.4, 1.15);
    points[index++]= vec2(1.45, 1.152);
    points[index++]= vec2(1.5, 1.15);

    //Front leg
    points[index++]= vec2(1.55, 1.1);
    points[index++]= vec2(1.6, 1.08);
    points[index++]= vec2(1.78, 0.95);
    points[index++]= vec2(1.75, 0.9);
    points[index++]= vec2(0.0, 1.0);

    //Back leg
    points[index++]= vec2(-0.1, 1.0);
    points[index++]= vec2(-0.5, 1.0);

    //Tail
    points[index++]= vec2(-0.6, 1.0);
    points[index++]= vec2(-0.6, 1.0);
    points[index++]= vec2(-0.9, 1.0);
    points[index++]= vec2(-1.0, 1.0);

    //Set index back to original
    index-=30;
    //Draw new image of deer
    draw();
}

//******************************************************************
      //                                                                  
      //  Function:   init_rabbit_points
      //                                                                  
      //  Purpose:    Initialize points for a rabbit                               
      //                                                                  
      //  Parameters: none
      //                                                                  
      // Member/Global Variables: points, index, inited
      //
      // Pre Conditions: points != NULL
      //
      // Post Conditions: returns void. points array will hold new values to be stored as the points to make up a rabbit
      //
      //                                                                  
      //******************************************************************
void Animal::init_rabbit_points()
{
  if (!inited) {
    animal_type = RABBIT;

    //Back
    points[index++]= vec2(0,  0.15);
    points[index++]= vec2(0.4, 0.4);

    //Ear
    points[index++]= vec2(0.3,  1);
    points[index++]= vec2(0.35, 1.2);
    points[index++]= vec2(0.38, 1);
    points[index++]= vec2(0.5, 0.48);

    //Head
    points[index++]= vec2(0.6, 0.45);
    points[index++]= vec2(0.65, 0.3);
    points[index++]= vec2(0.6, 0.25);

    //Belly
    points[index++]= vec2(0.45, 0.2);
    points[index++]= vec2(0.2, -0.3);

    //Feet
    points[index++]= vec2(0.7, -0.3);
    points[index++]= vec2(0.7, -0.42);
    points[index++]= vec2(0.2, -0.42);

    //Butt
    points[index++]= vec2(0.0, -0.42);
    points[index++]= vec2(-0.15, -0.2);

    //Set index back to original
    index-=16;
    inited = true;
  }
}

//******************************************************************
      //                                                                  
      //  Function:   init_rabbit_laying_points
      //                                                                  
      //  Purpose:    Initialize points for a rabbit laying down                           
      //                                                                  
      //  Parameters: none
      //                                                                  
      // Member/Global Variables: points, index, inited
      //
      // Pre Conditions: points != NULL
      //
      // Post Conditions: returns void. points array will hold new values to be stored as the points to make up a rabbit laying down
      //
      //                                                                  
      //******************************************************************
void Animal::init_rabbit_laying_points()
{
    points[index++]= vec2(-1,  1);
    points[index++]= vec2(-0.85, 1.15);
    points[index++]= vec2(-0.7,  1.25);
    points[index++]= vec2(-0.65, 1.25);
    points[index++]= vec2(-0.6, 1.23);
    points[index++]= vec2(-0.5, 1.15);
    points[index++]= vec2(-0.3, 1.14);
    points[index++]= vec2(-0.25, 1.19);
    points[index++]= vec2(-0.2, 1.21);
    points[index++]= vec2(-0.1, 1.19);
    points[index++]= vec2(-0.05, 1.0);
    points[index++]= vec2(-0.05, 1.0);
    points[index++]= vec2(-0.05, 1.0);
    points[index++]= vec2(-0.05, 1.0);
    points[index++]= vec2(-0.05, 1.0);
    points[index++]= vec2(-1.0, 1.0);

    //set index back to original
    index-=16;
    draw();
}

//******************************************************************
      //                                                                  
      //  Function:   init_bear_points
      //                                                                  
      //  Purpose:    Initialize points for a bear                          
      //                                                                  
      //  Parameters: none
      //                                                                  
      // Member/Global Variables: points, index, inited
      //
      // Pre Conditions: points != NULL
      //
      // Post Conditions: returns void. points array will hold new values to be stored as the points to make up a bear
      //
      //                                                                  
      //******************************************************************
void Animal::init_bear_points()
{
  if (!inited) {
    animal_type = BEAR;

    //Back
    points[index++]= vec2(-1,  1);
    points[index++]= vec2(-0.5, 1.2);
    points[index++]= vec2(0, 1.3);
    points[index++]= vec2(1,  1);
    points[index++]= vec2(1.3, 1.3);

    //Ear
    points[index++]= vec2(1.25, 1.45);
    points[index++]= vec2(1.25, 1.47);
    points[index++]= vec2(1.27, 1.5);
    points[index++]= vec2(1.35, 1.52);

    //Head shape
    points[index++]= vec2(1.37, 1.25);
    points[index++]= vec2(1.65, 1.22);
    points[index++]= vec2(1.7, 1.15);
    points[index++]= vec2(1.75, 1.15);
    points[index++]= vec2(1.9, 1.1);

    //Nose
    points[index++]= vec2(2.0, 1.0);
    points[index++]= vec2(2.0, 0.9);

    //Bottom of head (jaw)
    points[index++]= vec2(1.6, 0.7);
    points[index++]= vec2(1.4, 0.72);
    points[index++]= vec2(1.3, 0.70);
    points[index++]= vec2(1.1, 0.6);

    //Front leg
    points[index++]= vec2(1, -0.7);
    points[index++]= vec2(0.7, -0.7);
    points[index++]= vec2(0.6, 0.5);
    points[index++]= vec2(0.2, 0.4);
    points[index++]= vec2(-1, 0.5);

    //Back leg
    points[index++]= vec2(-1, -0.7);
    points[index++]= vec2(-1.3, -0.7);

    //Tail
    points[index++]= vec2(-1.35, 0.5);
    points[index++]= vec2(-1.4, 1.0);
    points[index++]= vec2(-1.42, 0.65);
    points[index++]= vec2(-1.5, 0.7);

    //set back to original
    index-=31;
    inited=true;
  }
}

//******************************************************************
      //                                                                  
      //  Function:   init_bear_laying_points
      //                                                                  
      //  Purpose:    Initialize points for a bear laying down                         
      //                                                                  
      //  Parameters: none
      //                                                                  
      // Member/Global Variables: points, index, inited
      //
      // Pre Conditions: points != NULL
      //
      // Post Conditions: returns void. points array will hold new values to be stored as the points to make up a bear laying down
      //
      //                                                                  
      //******************************************************************
void Animal::init_bear_laying_points()
{
    //Back and top of nect
    points[index++]= vec2(-1,  1);
    points[index++]= vec2(-0.9, 1.1);
    points[index++]= vec2(-0.8,  1.2);
    points[index++]= vec2(-0.4, 1.3);
    points[index++]= vec2(-0.2, 1.35);
    points[index++]= vec2(-0.1, 1.37);
    points[index++]= vec2(0.0, 1.375);
    points[index++]= vec2(0.1, 1.37);
    points[index++]= vec2(0.2, 1.35);
    points[index++]= vec2(0.4, 1.3);
    points[index++]= vec2(0.8, 1.2);
    points[index++]= vec2(0.9, 1.05);
    points[index++]= vec2(1.0, 1.05);

    //Nose
    points[index++]= vec2(1.2, 1.05);
    points[index++]= vec2(1.24, 1.05);
    points[index++]= vec2(1.33, 1.1);
    points[index++]= vec2(1.4, 1.15);
    points[index++]= vec2(1.45, 1.152);
    points[index++]= vec2(1.5, 1.15);

    //Front leg
    points[index++]= vec2(1.55, 1.1);
    points[index++]= vec2(1.6, 1.08);
    points[index++]= vec2(1.78, 0.95);
    points[index++]= vec2(1.75, 0.9);
    points[index++]= vec2(0.0, 1.0);

    //Back leg
    points[index++]= vec2(-0.1, 1.0);
    points[index++]= vec2(-0.5, 1.0);

    //Tail
    points[index++]= vec2(-0.6, 1.0);
    points[index++]= vec2(-0.6, 1.0);
    points[index++]= vec2(-0.9, 1.0);
    points[index++]= vec2(-1.0, 1.0);
    points[index++]= vec2(-1.0, 1.0);

    //set back to original
    index-=31;
    draw();
}

//******************************************************************
      //                                                                  
      //  Function:   init_angry_bear_points
      //                                                                  
      //  Purpose:    Initialize points for an angry bear                         
      //                                                                  
      //  Parameters: none
      //                                                                  
      // Member/Global Variables: points, index, inited
      //
      // Pre Conditions: points != NULL
      //
      // Post Conditions: returns void. points array will hold new values to be stored as the points to make up an angry bear
      //
      //                                                                  
      //******************************************************************
void Animal::init_angry_bear_points()
{
  animal_type = ANGRYBEAR;
  points[index]= vec2( 0,  0);
  GLfloat delta=(2.0*M_PI)/float(NumBearPoints-12);
  GLfloat angle=0.0;
  for (size_t ind = 1; ind < NumBearPoints-10; ++ind) {
    points[index+ind]=vec2(cos(angle), sin(angle));
    angle+=delta;
  }
  draw();
}

//******************************************************************
      //                                                                  
      //  Function:   Animal
      //                                                                  
      //  Purpose:    Constructor for a blank animal                         
      //                                                                  
      //  Parameters: none
      //                                                                  
      // Member/Global Variables: body_size, hit, laying_down, running_direction_x, running_direction_y, animal_type, initied, laying_inited, isAngry, angry_inited, animal_kill
      //
      // Pre Conditions: none
      //
      // Post Conditions: returns void. all member variables are initialized
      //
      //                                                                  
      //******************************************************************
Animal::Animal() : Object()
{
  //Default Body Size = 10.0
  body_size = 10;

  //Animal hasn't been hit yet
  hit = false;

  //Set animal isnt sleeping or dead
  done = false;

  //Animal isn't laying down yet
  laying_down = false;

  //What direction the animal is running (right and down the screen)
  running_direction_x = RIGHT;
  running_direction_y = DOWN;

  //Default animal to deer
  animal_type = DEER;

  //Animal hasn't had points inited
  inited = false;
  laying_inited = false;

  //Animal isn't angry yet
  isAngry = false;
  //Angry points havent been inited
  angry_inited= false;

  //Animal hasnt killed you yet...
  Animal_Kill = false;
}


//******************************************************************
      //                                                                  
      //  Function:   Animal
      //                                                                  
      //  Purpose:    Constructor for animal                          
      //                                                                  
      //  Parameters: GLuint nindex, vec2 *npoints, GLint noffsetLoc, GLint nsizeLoc, GLint ncolorLoc
      //                                                                  
      // Member/Global Variables: index ,running_direction_x,running_direction_y,hit,laying_down,points,offsetLoc,sizeLoc,colorLoc,laying_inited,isAngry,angry_inited,Animal_Kill
      //
      // Pre Conditions: none
      //
      // Post Conditions: returns void. member variables initialized
      //
      //                                                                  
      //******************************************************************
Animal::Animal(GLuint nindex, vec2 *npoints, GLint noffsetLoc, GLint nsizeLoc, GLint ncolorLoc): Object()
{
  // Default index to passed in value in nindex.
  index = nindex;

  //What direction the animal is running 
  running_direction_x = RIGHT;
  running_direction_y = DOWN;

  //Animal hasn't been hit yet
  hit = false;

  //Animal isnt laying down
  laying_down = false;

  // Update the location of the points array from the main program.
  points = npoints;

  // Update the values of where the variables are in the shaders.
  offsetLoc=noffsetLoc;
  sizeLoc=nsizeLoc;
  colorLoc=ncolorLoc;

  //Animal points havent been inited
  inited = false;
  laying_inited = false;
  angry_inited = false;

  //Animal isnt angry
  isAngry = false;
  
  //Animal hasnt killed you
  Animal_Kill = false;
}

//******************************************************************
      //                                                                  
      //  Function:   set_animal_type
      //                                                                  
      //  Purpose:    Set the animal_type variable based on the value passed in and initialize points accordingly                          
      //                                                                  
      //  Parameters: int type
      //                                                                  
      // Member/Global Variables: body_size
      //
      //
      // Post Conditions: returns void. points will be initialized based on what animal is selected. Body_size is also selected.
      //
      //                                                                  
      //******************************************************************
void Animal::set_animal_type(int type)
{
  animal_type = type;
  switch(type)
  {
    case DEER:
      init_deer_points();
      body_size = 20;
      break;
    case RABBIT:
      init_rabbit_points();
      body_size = 10;
      break;
    case BEAR:
      init_bear_points();
      body_size = 30;
      break;
  }
}

//******************************************************************
      //                                                                  
      //  Function:   draw
      //                                                                  
      //  Purpose:    Draw the animal                        
      //                                                                  
      //  Parameters: none
      //                                                                  
      // Member/Global Variables: points, colorLoc, sizeLoc, offsetLoc,NumDeerPoints, NumRabbitPoints, NumBearPoints
      //
      //
      // Post Conditions: returns void. Variable will be initialized and drawn on buffer screen
      //
      //                                                                  
      //******************************************************************
void Animal::draw()
{
  //std::cout << "animal : " << animal_type << " index " << index << " x " << x << " y " << y << "\n";
  // Pass the current size of the square
  glUniform1f(sizeLoc, size);
  glUniform2i(offsetLoc, int(x), int(y));

  switch(animal_type)
  {
    case DEER:
      glUniform4f(colorLoc, r,g,b, 1.0);
      glDrawArrays(GL_LINE_LOOP, index, NumDeerPoints);
      break;
    case RABBIT:
      glUniform4f(colorLoc, r,g,b, 1.0);
      glDrawArrays(GL_LINE_LOOP, index, NumRabbitPoints);
      break;
    case BEAR:
      glUniform4f(colorLoc, r,g,b, 1.0);
      glDrawArrays(GL_LINE_LOOP, index, NumBearPoints);
      break;
    case ANGRYBEAR:
      glUniform1f(sizeLoc, window_size.x*window_size.y);
      glUniform2i(offsetLoc, int(window_size.x/2), int(window_size.y/2));
      glUniform4f(colorLoc, r,g,b, 1.0);
      glDrawArrays(GL_TRIANGLE_FAN, index, NumBearPoints-10);
      break;
  }  
}

//******************************************************************
      //                                                                  
      //  Function:   update
      //                                                                  
      //  Purpose:    Update animals on screen                          
      //                                                                  
      //  Parameters: none
      //                                                                  
      // Member/Global Variables: x,y,isangry,size,hit,running_direction_x,running_direction_y,laying_down,isVisible,timeout,
      //
      //
      // Post Conditions: returns void. animal will be updated based on whether it is angry, shot, or just grazing
      //
      //                                                                  
      //******************************************************************
void Animal::update()
{
  //Animal has been shot will low dose dart
  if (isAngry)
  {
      Animal_Kill = true;
  }
  //Animal has been hit but not angry
  else if (hit)
  {
    //Check to see if animal has been running around
    if (glutGet(GLUT_ELAPSED_TIME)-last_time < TRANQ_RUNTIME && !laying_down) 
    {
      //Max speed for animal to run
      const GLfloat max_speed= 700.0/1000.0;

      //Direction that the animal has ran
      vec2 dir = vec2(1, 0.4);
      dir = (compute_last_update_call_time())*max_speed*normalize(dir);
      
      //Check to see if animal has ran off the side of the screen on the right
      if (x >= window_size.x) 
        running_direction_x = LEFT;
      //Check to see if animal has ran off the side of the screen on the left
      if (x <= 0)
        running_direction_x = RIGHT;
      //Move x in appropriate direction
      x+=(dir.x * running_direction_x);

      //Check to see if animal has ran off the side of the screen on the bottom
      if (y >= window_size.y)
        running_direction_y = DOWN;
      //Check to see if animal has ran off the side of the screen on the top
      if (y <= 0)
        running_direction_y = UP;
      //Move y in the appropriate direction
      y+=(dir.y * running_direction_y);

      //Change size based on y value
      change_size();
    }
    //Animal has ran around hit and now need to do some action
    else 
    {
      hit = false;
      isVisible = false;
      set_last_time();
      
      //Set the animal is laying down
      laying_down = true;
      if (!laying_inited)
      {
        laying_inited = true;
        animal_lay_down();
      }
    }
  }
  //Animal hasnt been hit and is grazing around
  else if ((isVisible || (glutGet(GLUT_ELAPSED_TIME) - last_time) > timeout) && !laying_down)
  {
    //Set animal is visible on screen
    isVisible = true;
    const GLfloat max_speed= 200.0/1000.0; // pixels/msec max speed
  
    //Set direction where animal is moving
    vec2 dir = vec2(1, 0.5);

    //Check to see if animal has ran off the side of the screen on the right
    if (x < window_size.x) 
    { 
      dir = (compute_last_update_call_time())*max_speed*normalize(dir);
      // Update location
      x+=dir.x;
      //Check to see if animal has ran off the side of the screen on the bottom
      if (y >= window_size.y)
        running_direction_y = DOWN;
      //Check to see if animal has ran off the side of the screen on the top
      if (y <= 0)
        running_direction_y = UP;
      y+=(dir.y * running_direction_y);
      change_size();
    } 
    //Animal has ran off the side of the screen on the right
    else 
    {
      isVisible = false;
      //Generate new y value to enter screen on
      y = rand()%((int)window_size.y/2 + 1);
      move(-1, y);
      //Change size based on new y direction
      change_size();
    }
    set_last_time();
  }
  set_last_update_call_time();
}

//******************************************************************
      //                                                                  
      //  Function:   set_body_size
      //                                                                  
      //  Purpose:    Set the body size of the animal                          
      //                                                                  
      //  Parameters: GLfloat s
      //                                                                  
      // Member/Global Variables: body_size
      //
      //
      // Post Conditions: returns void. body_size is set to value passed in
      //
      //                                                                  
      //******************************************************************
void Animal::set_body_size(GLfloat s)
{
  body_size = s;
}

//******************************************************************
      //                                                                  
      //  Function:   animal_hit
      //                                                                  
      //  Purpose:    Set whether animal has been hit with dart                          
      //                                                                  
      //  Parameters: none
      //                                                                  
      // Member/Global Variables: hit
      //
      //
      // Post Conditions: returns void. sets the hit variable to whatever was passed into the function
      //
      //                                                                  
      //******************************************************************
void Animal::animal_hit()
{
  hit = true;
}

//******************************************************************
      //                                                                  
      //  Function:   animal_die
      //                                                                  
      //  Purpose:    Set color of animal to red because it has died                         
      //                                                                  
      //  Parameters: none
      //                                                                  
      //
      // Pre Conditions: points != NULL
      //
      // Post Conditions: returns void. calls object function to set object value to red
      //
      //                                                                  
      //******************************************************************
void Animal::animal_die()
{
  color(vec3(1.0,0.0,0.0));
  done = true;
  draw();
}

//******************************************************************
      //                                                                  
      //  Function:   animal_sleep
      //                                                                  
      //  Purpose:    set animal color to green                         
      //                                                                  
      //  Parameters: none
      //                                                                  
      // Member/Global Variables: none
      //
      // Pre Conditions: points != NULL
      //
      // Post Conditions: returns void. calls color function to turn object color green
      //
      //                                                                  
      //******************************************************************
void Animal::animal_sleep()
{
  color(vec3(0.0,1.0,0.0));
  done = true;
  draw();
}

//******************************************************************
      //                                                                  
      //  Function:   animal_lay_down
      //                                                                  
      //  Purpose:    Calls laying down point initializer based on type of animal                         
      //                                                                  
      //  Parameters: none
      //                                                                  
      // Member/Global Variables: animal_type
      //
      // Pre Conditions: points != NULL
      //
      // Post Conditions: returns void. calls appropriate laying down initializer for animal
      //
      //                                                                  
      //******************************************************************
void Animal::animal_lay_down()
{
  switch(animal_type)
  {
    case DEER:
      init_deer_laying_points();
      break;
    case RABBIT:
      init_rabbit_laying_points();
      break;
    case BEAR:
      init_bear_laying_points();
      break;
  }
}

//******************************************************************
      //                                                                  
      //  Function:   animal_wake
      //                                                                  
      //  Purpose:    Make animal run around, just faster than it was                          
      //                                                                  
      //  Parameters: none
      //                                                                  
      // Member/Global Variables: points, index, inited
      //
      // Pre Conditions: points != NULL
      //
      // Post Conditions: returns void. Redraw animal standing up
      //
      //                                                                  
      //******************************************************************
void Animal::animal_wake()
{
  set_last_time();
  isVisible = true;
  laying_down = false;
  laying_inited = false;
  inited = false;
  switch(animal_type)
  {
    case DEER:
      init_deer_points();
      draw();
      break;
    case RABBIT:
      init_rabbit_points();
      draw();
      break;
    case BEAR:
      init_bear_points();
      draw();
      break;
  }
}

//******************************************************************
      //                                                                  
      //  Function:   animal_angry
      //                                                                  
      //  Purpose:    Sets animal is angry and intializes points for angry animal                         
      //                                                                  
      //  Parameters: none
      //                                                                  
      // Member/Global Variables: isangry
      //
      // Pre Conditions: points != NULL
      //
      // Post Conditions: returns void. calls initilizer for angry bear points
      //
      //                                                                  
      //******************************************************************
void Animal::animal_angry()
{
  isAngry = true;
  init_angry_bear_points();
}

//******************************************************************
      //                                                                  
      //  Function:   is_laying_down
      //                                                                  
      //  Purpose:    returns whether the animal is laying down or not                         
      //                                                                  
      //  Parameters: none
      //                                                                  
      // Member/Global Variables: laying_Down
      //
      // Pre Conditions: points != NULL
      //
      // Post Conditions: returns bool whether animal is laying down or not
      //
      //                                                                  
      //******************************************************************
bool Animal::is_laying_down()
{
  return laying_down;
}

//******************************************************************
      //                                                                  
      //  Function:   is_done
      //                                                                  
      //  Purpose:    returns whether the animal is dead or sleeping                       
      //                                                                  
      //  Parameters: none
      //                                                                  
      // Member/Global Variables: done
      //
      // Pre Conditions: points != NULL
      //
      // Post Conditions: returns bool whether animal is dead or sleeping
      //
      //                                                                  
      //******************************************************************
bool Animal::is_done()
{
  return done;
}
 
