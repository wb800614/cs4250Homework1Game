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
#include "gun.h"
#include "dart.h"

class Scene 
{
	private:
		//
		vec2 window_size;

		//Background
		GLuint index;
		vec2 *points;
		GLint offsetLoc;
		GLint sizeLoc;
		GLint colorLoc;

	public:
		static GLint Num_Points;
		static const int count_of_animals = 6;
		static const int count_of_darts = 5;
		Gun * gun;
		Animal1 * animals_1[count_of_animals];
		Dart * darts[count_of_darts];

		//Setup functions
		Scene();
		Scene(vec2 window);
		void SetWindowSize(vec2 window);
		void InitBackground(GLuint nindex, vec2 *npoints, GLint noffsetLoc, GLint nsizeLoc, GLint ncolorLoc);
		void DrawBackground();
		void Init(GLuint nindex, vec2 *npoints, GLint noffsetLoc, GLint nsizeLoc, GLint ncolorLoc);
		void InitAnimals();
		void InitGun();
		void InitDarts();

		void UpdateGun(GLint x, GLint y);
		void FireGun(GLint x, GLint y);

};

#endif