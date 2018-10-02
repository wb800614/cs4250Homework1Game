#include "scene.h"

GLint Scene::Num_Points = 4 * Scene::count_of_animals;

Scene::Scene(vec2 window)
{
	window_size = window;
}

void Scene::SetWindowSize(vec2 window)
{
	window_size = window;
}

void Scene::InitBackground(GLuint nindex, vec2 *npoints, GLint noffsetLoc, GLint nsizeLoc, GLint ncolorLoc)
{
	background_index = nindex;
	background_points = npoints;
	background_offsetLoc = noffsetLoc;
	background_sizeLoc = nsizeLoc;
	background_colorLoc = ncolorLoc;
}

void Scene::DrawBackground()
{
	//Drawing ground
	glUniform1f(background_sizeLoc, window_size.x/2);
  	glUniform2i(background_offsetLoc, int(window_size.x/2), int(window_size.y/2));
    glUniform4f(background_colorLoc, 0.0, 0.4, 0.0, 1.0);
	glDrawArrays(GL_TRIANGLE_STRIP, background_index, 4);
	glUniform1f(background_sizeLoc, window_size.x/2);
	//Drawing sky
  	glUniform2i(background_offsetLoc, int(window_size.x/2), int(window_size.y));
    glUniform4f(background_colorLoc, 0.0, 0.0, 0.8, 1.0);
	glDrawArrays(GL_TRIANGLE_STRIP, background_index, 4);
	
}

void Scene::InitAnimals(GLuint nindex, vec2 *npoints, GLint noffsetLoc, GLint nsizeLoc, GLint ncolorLoc)
{
	srand(time(NULL));
	for(int i = 0; i < count_of_animals; i++)
  	{
		GLfloat y = rand()%((int)window_size.y/2 + 1);
	    animals_1[i] = new Animal1(0, npoints, noffsetLoc, nsizeLoc, ncolorLoc);
	    animals_1[i]->set_window_size(window_size);
	    animals_1[i]->move(-1,y);
	    animals_1[i]->change_size();
	    animals_1[i]->set_random_timeout();
	    animals_1[i]->set_ground(vec2(window_size.x, window_size.y/2.0));
	    animals_1[i]->selectColor(1.0/255.0, 0.0, 0.0);
  	}
}