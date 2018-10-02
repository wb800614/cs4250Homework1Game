#ifndef SCENE_H
#define SCENE_H
//Class definition of scene
// 
// Written by Wesley Book
// 

#include <Angel.h>
#include <iostream>
#include <stdlib.h>
#include "square.h"

class Scene 
{
	private:
		//
		vec2 window_size;

		//Background
		GLuint background_index;
		vec2 *background_points;
		GLint background_offsetLoc;
		GLint background_sizeLoc;
		GLint background_colorLoc;

	public:
		static GLint Num_Points;
		static const int count_of_animals = 6;
		Animal1 * animals_1[count_of_animals];

		//Setup functions
		Scene();
		Scene(vec2 window);
		void SetWindowSize(vec2 window);
		void InitBackground(GLuint nindex, vec2 *npoints, GLint noffsetLoc, GLint nsizeLoc, GLint ncolorLoc);
		void DrawBackground();
		void InitAnimals(GLuint nindex, vec2 *npoints, GLint noffsetLoc, GLint nsizeLoc, GLint ncolorLoc);

};

#endif