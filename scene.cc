#include "scene.h"

GLint Scene::Num_Points = 4 * (Scene::count_of_animals + 1);

Scene::Scene(vec2 window)
{
	window_size = window;
}

void Scene::SetWindowSize(vec2 window)
{
	window_size = window;
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
}

void Scene::InitAnimals()
{
	srand(time(NULL));
	for(int i = 0; i < count_of_animals; i++)
  	{
		GLfloat y = rand()%((int)window_size.y/2 + 1);
	    animals_1[i] = new Animal1(index, points, offsetLoc, sizeLoc, colorLoc);
	    animals_1[i]->set_window_size(window_size);
	    animals_1[i]->move(-1,y);
	    animals_1[i]->change_size();
	    animals_1[i]->set_random_timeout();
	    animals_1[i]->set_ground(vec2(window_size.x, window_size.y/2.0));
	    animals_1[i]->selectColor(1.0/255.0, 0.0, 0.0);
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

}

void Scene::UpdateGun(GLint x, GLint y)
{
	gun->move(x,y);
}

void Scene::FireGun(GLint x, GLint y)
{
	std::cout << x << "/" << y << "\n";
}

