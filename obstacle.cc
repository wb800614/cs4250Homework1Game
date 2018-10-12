//******************************************************************* 
//                                                                    
//  Program:     Homework 1
//                                                                     
//  Author:      Wesley Book
//  Email:       wb800614@ohio.edu
//                                                                    
//                                                                    
//  Description: File to hold class definition of an obstacle class
//                                                                    
//  Date:        October 11, 2018
//                                                                    
//*******************************************************************



#include "obstacle.h"

//******************************************************************
      //                                                                  
      //  Function:   Obstacle
      //                                                                  
      //  Purpose:    Initializer for obstacle class                              
      //                                                                  
      //  Parameters: none
      //                                                                  
      // Member/Global Variables: inited, obstacle_type
      //
      //
      // Post Conditions: returns void. inited set to false and obstacle type is set to a tree
      //
      //                                                                  
      //******************************************************************
Obstacle::Obstacle() : Object()
{
	inited = false;
	obstacle_type = TREE;
}

//******************************************************************
      //                                                                  
      //  Function:   Obstacle
      //                                                                  
      //  Purpose:    Initializer for obstacle class                               
      //                                                                  
      //  Parameters: none
      //                                                                  
      // Member/Global Variables: points, index, inited, obstacle_type, offsetloc, sizeloc, colorloc
      //
      //
      // Post Conditions: returns void. sets up index, points, and other positions for drawing. set obstacle type to tree
      //
      //                                                                  
      //******************************************************************
Obstacle::Obstacle(GLuint nindex, vec2 *npoints, GLint noffsetLoc, GLint nsizeLoc, GLint ncolorLoc) : Object()
{
	//Initialization of index for points array
	index = nindex;

	//Setting points array and positions for position, color, and size
	points = npoints;
	offsetLoc = noffsetLoc;
	sizeLoc = nsizeLoc;
	colorLoc = ncolorLoc;

	//Points haven't been initialized yet
	inited = false;

	//Default obstacle to tree
	obstacle_type = TREE;
}

//******************************************************************
      //                                                                  
      //  Function:   init_tree_points
      //                                                                  
      //  Purpose:    Initialize points for a tree                               
      //                                                                  
      //  Parameters: none
      //                                                                  
      // Member/Global Variables: points, index, inited
      //
      // Pre Conditions: points != NULL
      //
      // Post Conditions: returns void. points array will hold new values to be stored as the points to make up a tree
      //
      //                                                                  
      //******************************************************************
void Obstacle::init_tree_points()
{
	if (!inited)
	{
		//Initialize tree points
		points[index++]= vec2(-1,  1);
		points[index++]= vec2(-1,  5);
		points[index++]= vec2(-2,  7);
		points[index++]= vec2(-1.5,  9);
		points[index++]= vec2(-1,  10);
		points[index++]= vec2(1,  10);
		points[index++]= vec2(1.5,  9);
		points[index++]= vec2(2,  7);
		points[index++]= vec2(1,  5);
		points[index++]= vec2(1,  1);
		points[index++]= vec2(-1,  1);

		index-=11;
		
		inited = true;
	}
}

//******************************************************************
      //                                                                  
      //  Function:   init_bush_points
      //                                                                  
      //  Purpose:    Initialize points for a bush                                
      //                                                                  
      //  Parameters: none
      //                                                                  
      // Member/Global Variables: points, index, inited
      //
      // Pre Conditions: points != NULL
      //
      // Post Conditions: returns void. points array will hold new values to be stored as the points to make up a bush
      //
      //                                                                  
      //******************************************************************
void Obstacle::init_bush_points()
{
	if (!inited)
	{
		points[index++]= vec2(-1,  5);
		points[index++]= vec2(-1.7,  6);
		points[index++]= vec2(-1.5,  7.5);
		points[index++]= vec2(-1,  8);
		points[index++]= vec2(-0.5,  8.5);
		points[index++]= vec2(0.5,  8.5);
		points[index++]= vec2(1,  8);
		points[index++]= vec2(1.5,  7.5);
		points[index++]= vec2(1.7,  6);
		points[index++]= vec2(1,  5);

		index -=10;
		inited = true;
	}
}

//******************************************************************
      //                                                                  
      //  Function:   init_grass_points
      //                                                                  
      //  Purpose:    Initialize points for grass                                
      //                                                                  
      //  Parameters: none
      //                                                                  
      // Member/Global Variables: points, index, inited
      //
      // Pre Conditions: points != NULL
      //
      // Post Conditions: returns void. points array will hold new values to be stored as the points to make up grass
      //
      //                                                                  
      //******************************************************************
void Obstacle::init_grass_points()
{
	if (!inited)
	{
		points[index++]= vec2(-1,  0);
		points[index++]= vec2(-0.5,  1);
		points[index++]= vec2(-1,  0);
		points[index++]= vec2(-0.9,  0);
		points[index++]= vec2(-1.3,  1);
		points[index++]= vec2(-0.9,  0);
		points[index++]= vec2(-0.8,  0);
		points[index++]= vec2(-1,  1);
		points[index++]= vec2(-0.8,  0);
		points[index++]= vec2(-0.7,  0);
		points[index++]= vec2(-0.8,  1);
		points[index++]= vec2(-0.7,  0);
		points[index++]= vec2(-0.6,  0);
		points[index++]= vec2(-0.6,  1);
		points[index++]= vec2(-0.6,  0);
		points[index++]= vec2(-0.5,  0);
		points[index++]= vec2(-0.4,  1);
		points[index++]= vec2(-0.5,  0);
		points[index++]= vec2(-0.3,  1);
		points[index++]= vec2(-0.5,  0);
		points[index++]= vec2(-0.4,  0);
		points[index++]= vec2(0.0,  1);
		points[index++]= vec2(-0.4,  0);
		points[index++]= vec2(-1,  0);

		index -=24;

		inited = true;
	}
}

//******************************************************************
      //                                                                  
      //  Function:   draw
      //                                                                  
      //  Purpose:    Draw points                             
      //                                                                  
      //  Parameters: none
      //                                                                  
      // Member/Global Variables: points, index, inited
      //
      // Pre Conditions: points != NULL
      //
      // Post Conditions: returns void. will draw the obstacle next time buffer is swaped.
      //
      //                                                                  
      //******************************************************************
void Obstacle::draw()
{
	glUniform1f(sizeLoc, size);
	glUniform2i(offsetLoc, int(x), int(y));
  	switch (obstacle_type)
  	{
  		case TREE:		
	  		glUniform4f(colorLoc, 0.0,0.2,0.0, 1.0);
	    	glDrawArrays(GL_LINE_LOOP, index, Num_Tree_Points);
  			break;
		case GRASS:
			glUniform4f(colorLoc, 0.0,1.0,0.0, 1.0);
	    	glDrawArrays(GL_LINE_LOOP, index, Num_Grass_Points);
			break;
		case BUSH:
			glUniform4f(colorLoc, 0.0,0.6,0.0, 1.0);
	    	glDrawArrays(GL_LINE_LOOP, index, Num_Bush_Points);
			break;
  	}
}

//******************************************************************
      //                                                                  
      //  Function:   set_obstacle_type
      //                                                                  
      //  Purpose:    set type of obstacle (tree, bush, grass)                            
      //                                                                  
      //  Parameters: int t (type)
      //                                                                  
      // Member/Global Variables: obstacle_type
      //
      //
      // Post Conditions: returns void. sets obstacle type and initalizes points
      //
      //                                                                  
      //******************************************************************
void Obstacle::set_obstacle_type(int t)
{
	switch (t)
	{
		case TREE:
			obstacle_type = TREE;
			init_tree_points();
			break;
		case BUSH:
			obstacle_type = BUSH;
			init_bush_points();
			break;
		case GRASS:
			obstacle_type = GRASS;
			init_grass_points();
			break;
	}
}