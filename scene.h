//******************************************************************* 
//                                                                    
//  Program:     Homework 1
//                                                                     
//  Author:      Wesley Book
//  Email:       wb800614@ohio.edu
//                                                                    
//                                                                    
//  Description: File to hold class declaration of scene class
//                                                                    
//  Date:        October 11, 2018
//                                                                    
//*******************************************************************
#ifndef SCENE_H
#define SCENE_H

#include <Angel.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include "animal.h"
#include "gun.h"
#include "dart.h"
#include "obstacle.h"

class Scene 
{
	private:
		//
		vec2 window_size;

		GLuint index;
		vec2 *points;
		GLint offsetLoc;
		GLint sizeLoc;
		GLint colorLoc;
		GLfloat dose_selected;
		bool isGameOver;
		int score;

	public:
		static const int count_of_animals = 11;
		static const int count_of_darts=15;
		static const int count_of_obstacles = 11;
		int next_shot_index;
		Gun * gun;
		Animal * animals_1[count_of_animals];
		Dart * darts[count_of_darts];
		Obstacle * obstacles[count_of_obstacles];

		//Setup functions
		Scene();
		Scene(vec2 window);
		~Scene();
		void SetWindowSize(vec2 window);
		void Set_Dose(GLfloat d);
		void InitBackground(GLuint nindex, vec2 *npoints, GLint noffsetLoc, GLint nsizeLoc, GLint ncolorLoc);
		void DrawBackground();
		void Init(GLuint nindex, vec2 *npoints, GLint noffsetLoc, GLint nsizeLoc, GLint ncolorLoc);
		void InitBackground();
		void InitAnimals();
		void InitGun();
		void InitDarts();
		void InitObstacles();
		void UpdateScene();
		int GetNumberOfPointsRequired();

		void UpdateGun(GLint x, GLint y);
		void FireGun(GLint x, GLint y);
		void Check_For_Tracker();

};

#endif