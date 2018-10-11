//Class implementation of square object 
// 
// Written by Prof. David M. Chelberg
// 
// Assumes that the square object was defined in the VAO at location
// index

// last-modified: Fri Oct  6 07:42:10 2017

#include "square.h"

GLint Animal::NumDeerPoints = 30;
GLint Animal::NumRabbitPoints = 16;
GLint Animal::NumBearPoints = 31;

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

    index-=30;
    inited = true;
  }
}

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

    index-=30;
    draw();
}

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

    index-=16;
    inited = true;
  }
}

void Animal::init_rabbit_laying_points()
{
    //Back and top of nect
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

    //Nose
    points[index++]= vec2(-0.05, 1.0);
    points[index++]= vec2(-0.05, 1.0);
    points[index++]= vec2(-0.05, 1.0);
    points[index++]= vec2(-0.05, 1.0);
    points[index++]= vec2(-0.05, 1.0);
    points[index++]= vec2(-0.05, 1.0);

    //Front leg
    points[index++]= vec2(-0.05, 1.0);
    points[index++]= vec2(-0.05, 1.0);
    points[index++]= vec2(-0.05, 1.0);
    points[index++]= vec2(-0.05, 1.0);
    points[index++]= vec2(-0.05, 1.0);

    //Back leg
    points[index++]= vec2(-0.05, 1.0);
    points[index++]= vec2(-0.05, 1.0);

    //Tail
    points[index++]= vec2(-0.05, 1.0);
    points[index++]= vec2(-0.05, 1.0);
    points[index++]= vec2(-0.05, 1.0);
    points[index++]= vec2(-1.0, 1.0);

    index-=30;
    draw();
}

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

    index-=31;
    inited=true;
  }
}

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

    index-=30;
    draw();
}

void Animal::init_angry_bear_points()
{
  animal_type = ANGRYBEAR;
  points[index]= vec2( 0,  0);
  GLfloat delta=(2.0*M_PI)/float(NumBearPoints-2);
  GLfloat angle=0.0;
  for (size_t ind = 1; ind < NumBearPoints; ++ind) {
    points[index+ind]=vec2(cos(angle), sin(angle));
    angle+=delta;
  }
  draw();
}

// Default constructor
Animal::Animal() : Object()
{
  //Default Body Size = 10.0
  body_size = 10;

  //Animal hasn't been hit yet
  hit = false;

  laying_down = false;

  //What direction the animal is running 
  running_direction_x = RIGHT;
  running_direction_y = DOWN;

  //Default animal to deer
  animal_type = DEER;

  inited = false;
  laying_inited = false;
  isAngry = false;
  angry_inited= false;
  Animal_Kill = false;
}

// Constructor if start of square vertices aren't at 0.
Animal::Animal(GLuint nindex, vec2 *npoints, GLint noffsetLoc, GLint nsizeLoc, GLint ncolorLoc): Object()
{
  // Default index is the start (0).
  index = nindex;

  //What direction the animal is running 
  running_direction_x = RIGHT;
  running_direction_y = DOWN;

  //Animal hasn't been hit yet
  hit = false;

  laying_down = false;

  // Update the location of the points array from the main program.
  points = npoints;

  // Update the values of where the variables are in the shaders.
  offsetLoc=noffsetLoc;
  sizeLoc=nsizeLoc;
  colorLoc=ncolorLoc;

  laying_inited = false;
  isAngry = false;
  angry_inited = false;
  Animal_Kill = false;
}

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

// Code to call to draw a square.
void Animal::draw()
{
  //std::cout << "animal : " << animal_type << " index " << index << " x " << x << " y " << y << "\n";
  // Pass the current size of the square
  glUniform1f(sizeLoc, size*2.0);
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
      glUniform2i(offsetLoc, int(window_size.x/2), int(window_size.y/2));
      glUniform4f(colorLoc, r,g,b, 1.0);
      glDrawArrays(GL_TRIANGLE_FAN, index, NumBearPoints);
      break;
  }  
}

// Update the position of the square from time
void Animal::update()
{
  if (isAngry)
  {
    x = window_size.x/2;
    y = window_size.y/2;
    change_size(size+0.5);
    if (size >= 100)
    {
      Animal_Kill = true;
    }
  }
  else if (hit)
  {
    if (glutGet(GLUT_ELAPSED_TIME)-last_time < TRANQ_RUNTIME && !laying_down) 
    {
      const GLfloat max_speed= 700.0/1000.0;
      vec2 dir = vec2(1, 0.4);
      dir = (compute_last_update_call_time())*max_speed*normalize(dir);
      
      if (x >= window_size.x) 
        running_direction_x = LEFT;
      if (x <= 0)
        running_direction_x = RIGHT;
      x+=(dir.x * running_direction_x);
      if (y >= window_size.y/2)
        running_direction_y = DOWN;
      if (y <= 0)
        running_direction_y = UP;
      y+=(dir.y * running_direction_y);
      change_size();
    }
    else 
    {
      hit = false;
      isVisible = false;
      set_last_time();
      laying_down = true;
      if (!laying_inited)
      {
        laying_inited = true;
        animal_lay_down();
      }
    }
  }
  else if ((isVisible || (glutGet(GLUT_ELAPSED_TIME) - last_time) > timeout) && !laying_down)
  {
    isVisible = true;
    const GLfloat max_speed= 200.0/1000.0; // pixels/msec max speed
  
    vec2 dir = vec2(1, 0.5);

    if (x < window_size.x) 
    { 
      dir = (compute_last_update_call_time())*max_speed*normalize(dir);
      // Update location
      x+=dir.x;
      if (y >= window_size.y/2)
        running_direction_y = DOWN;
      if (y <= 0)
        running_direction_y = UP;
      y+=(dir.y * running_direction_y);
      change_size();
    } 
    else 
    {
      isVisible = false;
      y = rand()%((int)window_size.y/2 + 1);
      move(-1, y);
      change_size();
    }
    set_last_time();
  }
  set_last_update_call_time();
}

void Animal::set_body_size(GLfloat s)
{
  if (animal_type == BEAR)
    s += s * 0.2;
  body_size = s;
}

void Animal::animal_hit()
{
  hit = true;
}

//Draw animal dead (dose was too strong for animal size)
void Animal::animal_die()
{
  color(vec3(1.0,0.0,0.0));
  draw();
}

//Draw animal laying asleep
void Animal::animal_sleep()
{
  color(vec3(0.0,1.0,0.0));
  draw();
}

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

void Animal::animal_angry()
{
  isAngry = true;
  init_angry_bear_points();
}

bool Animal::is_laying_down()
{
  return laying_down;
}
 
