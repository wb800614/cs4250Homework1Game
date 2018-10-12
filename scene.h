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
		//variable to hold size of current window
		vec2 window_size;

		//pointers and index locations for drawing
		GLuint index;
		vec2 *points;
		GLint offsetLoc;
		GLint sizeLoc;
		GLint colorLoc;

		//Dose of darts currently selected
		GLfloat dose_selected;

		//Flag for end of game
		bool isGameOver;

		//Score for entire game
		int score;

	public:
		//Count of animals, darts, and obstacles
		static const int count_of_animals = 11;
		static const int count_of_darts=15;
		static const int count_of_obstacles = 11;

		//Index for the next shot in the darts array
		int next_shot_index;

		//Pointer for the scene's gun
		Gun * gun;
		//Array of pointers for the scene's animals
		Animal * animals_1[count_of_animals];
		//Array of pointers for the scene's darts
		Dart * darts[count_of_darts];
		//Array of pointers for the  scene's obstacles
		Obstacle * obstacles[count_of_obstacles];

		//Setup functions
		Scene();
		Scene(vec2 window);
		~Scene();

		//Function to set window size
		void SetWindowSize(vec2 window);
		//Function to set dose
		void Set_Dose(GLfloat d);
		//Functions to setup background (green background for ground) and draw background
		void InitBackground(GLuint nindex, vec2 *npoints, GLint noffsetLoc, GLint nsizeLoc, GLint ncolorLoc);
		void DrawBackground();

		//Function to initialie scene (animals, background, obstacles, darts, gun)
		void Init(GLuint nindex, vec2 *npoints, GLint noffsetLoc, GLint nsizeLoc, GLint ncolorLoc);
		void InitBackground();
		void InitAnimals();
		void InitGun();
		void InitDarts();
		void InitObstacles();

		//Function to update all attribues within scene
		void UpdateScene();

		//Function to look ahead and see how many points will be needed
		int GetNumberOfPointsRequired();

		//Function to update the gun's crosshair location
		void UpdateGun(GLint x, GLint y);

		//Function to fire dart at certain location
		void FireGun(GLint x, GLint y);
		
		//Function to check if a fired dart can track any animals
		void Check_For_Tracker();

};

#endif