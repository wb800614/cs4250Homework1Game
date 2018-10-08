#include "scene.h"

GLint Scene::Num_Points = 4 * (Scene::count_of_animals + 1) + 18;

Scene::Scene(vec2 window)
{
	window_size = window;
	next_shot_index = 0;
	dose_selected = 10;
}

Scene::~Scene()
{
	for(int i = 0; i < count_of_animals; i++)
		delete animals_1[i];
	for(int i = 0; i < count_of_darts; i++)
		delete darts[i];
}

void Scene::SetWindowSize(vec2 window)
{
	window_size = window;
}

void Scene::Set_Dose(GLfloat d)
{
	dose_selected = d;
}

void Scene::DrawBackground()
{
	//Drawing ground
	glUniform1f(sizeLoc, window_size.x/2);
  	glUniform2i(offsetLoc, int(window_size.x/2), int(window_size.y/2));
    glUniform4f(colorLoc, 0.0, 0.4, 0.0, 1.0);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	glUniform1f(sizeLoc, window_size.x/2);
	//Drawing sky
  	glUniform2i(offsetLoc, int(window_size.x/2), int(window_size.y));
    glUniform4f(colorLoc, 0.0, 0.0, 0.8, 1.0);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	
}

void Scene::Init(GLuint nindex, vec2 *npoints, GLint noffsetLoc, GLint nsizeLoc, GLint ncolorLoc)
{
	index = nindex;
	points = npoints;
	offsetLoc = noffsetLoc;
	sizeLoc = nsizeLoc;
	colorLoc = ncolorLoc;

	InitAnimals();
	InitGun();
	InitDarts();
}

void Scene::InitAnimals()
{
	srand(time(NULL));
	for(int i = 0; i < count_of_animals; i++)
  	{
		GLfloat y = rand()%((int)window_size.y/2 + 1);
	    animals_1[i] = new Animal(index, points, offsetLoc, sizeLoc, colorLoc);
	    animals_1[i]->set_window_size(window_size);
	    if (i % 2 == 0)
		    animals_1[i]->set_body_size(10);
		else
			animals_1[i]->set_body_size(20);
	    animals_1[i]->move(-1,y);
	    animals_1[i]->change_size();
	    animals_1[i]->set_random_timeout();
	    animals_1[i]->set_ground(vec2(window_size.x, window_size.y/2.0));
  	}
  	index+=4;
}

void Scene::InitGun()
{
	gun = new Gun(index, points, offsetLoc, sizeLoc, colorLoc);
	gun->set_window_size(window_size);
	gun->move(window_size.x/2, window_size.y/2);
	index+=4;
}

void Scene::InitDarts()
{
	for(int i = 0; i < count_of_darts; i++)
	{
		darts[i] = new Dart(index, points, offsetLoc, sizeLoc, colorLoc);
		darts[i]->set_window_size(window_size);
		darts[i]->set_ground(vec2(window_size.x, window_size.y/2.0));
		darts[i]->move(window_size.x*2, window_size.y*2);
	}
	index+=18;
}

void Scene::UpdateGun(GLint x, GLint y)
{
	gun->move(x,y);
}

void Scene::FireGun(GLint x, GLint y)
{
	if (next_shot_index < count_of_darts)
	{
		darts[next_shot_index]->move(x,y);
		darts[next_shot_index]->Fire_Dart();
		Check_For_Tracker();
		next_shot_index++;
	}
	
}

void Scene::Check_For_Tracker()
{
	vec2 fire_pos = darts[next_shot_index]->get_pos();
	for(int i = 0; i < count_of_animals; i++)
	{
		GLfloat s = animals_1[i]->get_size();
		vec2 Animal_pos = animals_1[i]->get_pos();

		//Check if dart was fired at animal in view
		if (fire_pos.x >= Animal_pos.x-s/2 && fire_pos.x <= Animal_pos.x+s/2
			&& fire_pos.y >= Animal_pos.y-s/2 && fire_pos.y <= Animal_pos.y+s/2)
		{
			darts[next_shot_index]->Set_Tracker(animals_1[i]);
		}
	}
}






