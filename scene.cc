//******************************************************************* 
//                                                                    
//  Program:     Homework 1
//                                                                     
//  Author:      Wesley Book
//  Email:       wb800614@ohio.edu
//                                                                    
//                                                                    
//  Description: File to hold class definition for scene class
//                                                                    
//  Date:        October 11, 2018
//                                                                    
//*******************************************************************
#include "scene.h"

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
Scene::Scene(vec2 window)
{
	window_size = window;
	next_shot_index = 0;
	dose_selected = 10;
	isGameOver = false;
	score = 0;
}

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
Scene::~Scene()
{
	for(int i = 0; i < count_of_animals; i++)
		delete animals_1[i];
	for(int i = 0; i < count_of_darts; i++)
		delete darts[i];
	for(int i = 0; i < count_of_obstacles; i++)
		delete obstacles[i];
}

//******************************************************************
      //                                                                  
      //  Function:   SetWindowSize
      //                                                                  
      //  Purpose:    function to set passed in variable to the window size member variable. Update everything in scene to refelect this                           
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
void Scene::SetWindowSize(vec2 window)
{
	window_size = window;
	for(int i = 0; i < count_of_animals; i++)
		animals_1[i]->set_window_size(window_size);
	for(int i = 0; i < count_of_darts; i++)
		darts[i]->set_window_size(window_size);
	DrawBackground();
}

//******************************************************************
      //                                                                  
      //  Function:   Set_Dose
      //                                                                  
      //  Purpose:    sets dose_selected to passed in variable                           
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
void Scene::Set_Dose(GLfloat d)
{
	dose_selected = d;
}

//******************************************************************
      //                                                                  
      //  Function:   DrawBackground
      //                                                                  
      //  Purpose:    draws bckground color green like the ground                          
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
void Scene::DrawBackground()
{
	//Drawing ground
	glUniform1f(sizeLoc, window_size.x*2);
  	glUniform2i(offsetLoc, int(window_size.x/2), int(window_size.y/2));
    glUniform4f(colorLoc, 0.0, 0.4, 0.0, 1.0);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	
}

//******************************************************************
      //                                                                  
      //  Function:   InitBackground
      //                                                                  
      //  Purpose:    initializes points to draw backgroun                          
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
void Scene::InitBackground()
{
	points[0]= vec2( 1,  1);
    points[1]= vec2(-1,  1);
    points[3]= vec2(-1, -1);
    points[2]= vec2( 1, -1);
    index+=4;
}

//******************************************************************
      //                                                                  
      //  Function:   GetNumberOfPointsRequired
      //                                                                  
      //  Purpose:    returns nuber of points required to draw scene                          
      //                                                                  
      //  Parameters: none
      //                                                                  
      // Member/Global Variables: points, index, inited
      //
      // Pre Conditions: points != NULL
      //
      // Post Conditions: returns int
      //
      //                                                                  
      //******************************************************************
int Scene::GetNumberOfPointsRequired()
{
	int returnval = 0;
	//Get count of points required to draw animals
	for(int i = 0; i < count_of_animals; i++)
  	{
	    if (i % 2 == 0)
	    	returnval+=Animal::NumDeerPoints;
		else 
		{
			if (i % 5 == 0)
				returnval+= Animal::NumBearPoints;
			else
				returnval += Animal::NumRabbitPoints;
		}
  	}
  	//Get number of points required to draw obstacles
  	for(int i = 0; i < count_of_obstacles; i++)
  	{
  		if (i % 2 == 0)
			returnval += Obstacle::Num_Grass_Points;
		else
		{
			if (i % 5 == 0)
				returnval += Obstacle::Num_Tree_Points;
			else 
				returnval += Obstacle::Num_Bush_Points;
		}
  	}
  	//Add points for darts, scene, and gun
  	returnval += (4 + 4 + 18);
  	return returnval;
}

//******************************************************************
      //                                                                  
      //  Function:   Init
      //                                                                  
      //  Purpose:    initializes all attribues for sceene                           
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
void Scene::Init(GLuint nindex, vec2 *npoints, GLint noffsetLoc, GLint nsizeLoc, GLint ncolorLoc)
{
	index = nindex;
	points = npoints;
	offsetLoc = noffsetLoc;
	sizeLoc = nsizeLoc;
	colorLoc = ncolorLoc;

	InitBackground();
	InitAnimals();
	InitObstacles();
	InitGun();
	InitDarts();
}

//******************************************************************
      //                                                                  
      //  Function:   InitAnimals
      //                                                                  
      //  Purpose:    Initializes and created all the animals for thes scene                          
      //                                                                  
      //  Parameters: none
      //                                                                  
      // Member/Global Variables: points, index, inited
      //
      // Pre Conditions: points != NULL
      //
      // Post Conditions: returns void
      //
      //                                                                  
      //******************************************************************
void Scene::InitAnimals()
{
	srand(time(NULL));
	for(int i = 0; i < count_of_animals; i++)
  	{
		GLfloat y = rand()%((int)window_size.y/2 + 1);
	    animals_1[i] = new Animal(index, points, offsetLoc, sizeLoc, colorLoc);
	    animals_1[i]->set_window_size(window_size);

	    //Draw a deer
	    if (i % 2 == 0)
	    {
	    	animals_1[i]-> set_animal_type(Animal::DEER);
	    	animals_1[i]->color(vec3(0.5, 0.3, 0.0));
	    	index+=Animal::NumDeerPoints;
	    }
		else 
		{
				//Draw a bear
			if (i % 5 == 0)
			{
				animals_1[i]->set_animal_type(Animal::BEAR);
				animals_1[i]->color(vec3(0.4, 0.1, 0.1));
				index+=Animal::NumBearPoints;
			}
			//Draw a rabbit
			else
			{
				animals_1[i]->set_animal_type(Animal::RABBIT);
				animals_1[i]->color(vec3(1.0, 1.0, 1.0));
				index+= Animal::NumRabbitPoints;
			}
		}
	    animals_1[i]->move(-1,y);
	    animals_1[i]->change_size();
	    animals_1[i]->set_random_timeout();
	    animals_1[i]->set_ground(vec2(window_size.x, window_size.y));
  	}
}

//******************************************************************
      //                                                                  
      //  Function:   InitGun
      //                                                                  
      //  Purpose:    initializes gun on the scene                          
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
void Scene::InitGun()
{
	gun = new Gun(index, points, offsetLoc, sizeLoc, colorLoc);
	gun->set_window_size(window_size);
	gun->move(window_size.x/2, window_size.y/2);
	index+=4;
}

//******************************************************************
      //                                                                  
      //  Function:   InitDarts
      //                                                                  
      //  Purpose:    initialzies darts on the scene                           
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
void Scene::InitDarts()
{
	for(int i = 0; i < count_of_darts; i++)
	{
		darts[i] = new Dart(index, points, offsetLoc, sizeLoc, colorLoc);
		darts[i]->set_window_size(window_size);
		darts[i]->set_ground(vec2(window_size.x, window_size.y));
		darts[i]->move(window_size.x*2, window_size.y*2);
	}
	index+=18;
}

//******************************************************************
      //                                                                  
      //  Function:   InitObstacles
      //                                                                  
      //  Purpose:    initializes obstacles on the scene                           
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
void Scene::InitObstacles()
{
	srand(time(NULL));
	for(int i = 0; i < count_of_obstacles; i++)
	{
		GLfloat y = rand()%((int)window_size.y/2 + 1);
		GLfloat x = rand()%((int)window_size.x + 1);

		obstacles[i] = new Obstacle(index, points, offsetLoc, sizeLoc, colorLoc);
		obstacles[i]->set_window_size(window_size);

		//Draw grass
		if (i % 2 == 0)
		{
			obstacles[i]->set_obstacle_type(Obstacle::GRASS);
			index+=Obstacle::Num_Grass_Points;
		}
		else
		{
			//Draw a treee
			if (i % 5 == 0)
			{
				obstacles[i]->set_obstacle_type(Obstacle::TREE);
				index+=Obstacle::Num_Tree_Points;
			}
			//Draw a bush
			else 
			{
				obstacles[i]->set_obstacle_type(Obstacle::BUSH);
				index+=Obstacle::Num_Bush_Points;
			}
		}
		obstacles[i]->move(x,y);
	    obstacles[i]->change_size();
	    obstacles[i]->set_ground(vec2(window_size.x, window_size.y));
	}
}

//******************************************************************
      //                                                                  
      //  Function:   UpdateGun
      //                                                                  
      //  Purpose:    update position of crosshairs for gun                         
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
void Scene::UpdateGun(GLint x, GLint y)
{
	gun->move(x,y);
}

//******************************************************************
      //                                                                  
      //  Function:   FireGun
      //                                                                  
      //  Purpose:    mouse click x and y passed in to create a shot placement for a dart                           
      //                                                                  
      //  Parameters: GLint x, GLint y
      //                                                                  
      // Member/Global Variables: points, index, inited
      //
      // Pre Conditions: points != NULL
      //
      // Post Conditions: returns void. 
      //
      //                                                                  
      //******************************************************************
void Scene::FireGun(GLint x, GLint y)
{
	if (next_shot_index < count_of_darts)
	{
		darts[next_shot_index]->move(x,y);
		darts[next_shot_index]->Fire_Dart();
		Check_For_Tracker();
		next_shot_index++;
	}
	else 
	{
		isGameOver = true;
	}
}

//******************************************************************
      //                                                                  
      //  Function:   Check_For_Tracker
      //                                                                  
      //  Purpose:    check to see if any of the recently shot darts should be tracking an animal                           
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
void Scene::Check_For_Tracker()
{
	vec2 fire_pos = darts[next_shot_index]->get_pos();

	for(int i = 0; i < count_of_animals; i++)
	{
		GLfloat s = animals_1[i]->get_size();
		bool obstacle_hit = false;
		vec2 Animal_pos = animals_1[i]->get_pos();
		vec2 obstacle_hit_pos;

		for(int i = 0; i < count_of_obstacles; i++)
		{
			vec2 obstacle_pos = obstacles[i]->get_pos();
			GLfloat obstacle_size = obstacles[i]->get_size();

			if (fire_pos.x >= obstacle_pos.x-obstacle_size && fire_pos.x <= obstacle_pos.x+obstacle_size
			&& fire_pos.y >= obstacle_pos.y- obstacle_size && fire_pos.y <= obstacle_pos.y+obstacle_size)
			{
				obstacle_hit = true;
				obstacle_hit_pos = obstacle_pos;
				break;
			}
		}

		//Check if dart was fired at animal in view
		if (fire_pos.x >= Animal_pos.x-s && fire_pos.x <= Animal_pos.x+s
			&& fire_pos.y >= Animal_pos.y-s && fire_pos.y <= Animal_pos.y+s)
		{
			if (!obstacle_hit || (obstacle_hit && Animal_pos.y > obstacle_hit_pos.y))
				darts[next_shot_index]->Set_Tracker(animals_1[i]);
		}
	}
}

//******************************************************************
      //                                                                  
      //  Function:   UpdateScene
      //                                                                  
      //  Purpose:    Updates all attributes within the scene                          
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
void Scene::UpdateScene()
{
	//Game isnt over
	if (!isGameOver)
	{
		for(int i = 0; i < count_of_animals; i++)
	    {
	    	if (animals_1[i]->Animal_Kill)
	    	{
	    		isGameOver = true;
	    	}
	    	if (!animals_1[i]->is_done())
	    	{
	    		if (animals_1[i]->is_laying_down())
				{
					if (animals_1[i]->body_size == 10)
					{
						//Animal dies
						if (dose_selected > 10)
						{
							animals_1[i]->animal_die();
							score -= 10;
						}
						else
						{
							animals_1[i]->animal_sleep();
							score += 10;
						}
					}
					else if (animals_1[i]->body_size == 20)
					{
						if (dose_selected > 20)
						{
							animals_1[i]->animal_die();
							score -= 20;
						}
						else if (dose_selected < 20)
							animals_1[i]->animal_wake();
						else
						{
							animals_1[i]->animal_sleep();
							score += 20;
						}
					}
					else if (animals_1[i]->body_size == 30)
					{
						if (dose_selected < 30)
							animals_1[i]->animal_angry();
						else
						{
							animals_1[i]->animal_sleep();
							score += 30;
						}
					}
		      	}
		      	animals_1[i] -> update();
	    	}
	    }
	    for(int i = 0; i < count_of_darts; i++)
	    {
	    	darts[i] -> update();
	    }
	    std::string message = "Selected Dart Dose : " + std::to_string(dose_selected) + "   /   Score : " + std::to_string(score) + "   /   Darts left : " + std::to_string(count_of_darts-next_shot_index);
	    glutSetWindowTitle(message.c_str());
	}
	//Game is over
	else 
	{
		std::string message = "GAME OVER - Score : " + std::to_string(score);
		glutSetWindowTitle(message.c_str());
	}
}






