Wesley Book

CS4250 - Homework 1

	For the tracking darts, or smart darts, I simply used pointers to reference the object that the dart would be tracking.
I used a member variable target inside the dart class to hold a pointer to the animal class. This pointer would point to the
animal that the dart was suppose to be tracking. When a dart is shot, I track where the crosshairs were on screen, and then
check to see if an animal falls inside the crosshairs. If an animal does, I check to see if there are any other objects that
might block the dart from hitting the animal. If none of these occur, then the dart begins to track the animal. The user will
see the dart get smaller as it approaches the animal until it finally comes into contact with the animal it was tracking. 

	As the animal moves around on the screen, the dart will be updated with the animal's x and y coordinates. This is how the
dart seems to be tracking the animal. For the animals, a random y value, within the range of the ground, will be assigned to 
the animal. The x value starts at 0, or all the way to the left of the screen, and progresses across, until it is out of view,
where it is reset. The y value will be recreated at random when this occurs. The y value also has a value added to it to help
the animal move about the screen.

	There are three distinct animals in the game, a deer, bear, and rabbit. There are multiples of each of these animals. This
number can be changed via editing the class scene. There are three distinct obstacles, a tree, grass, and a bush. There are 
also multiples of each obstacle. There are three different doses of darts, 10, 20, and 30. These doses coorespond to the animal
sizes, 10, 20, and 30. When a dart is fired, if the dart strikes an obstacle first, then the dart is deemed dead, or inactive.
When a dart is fired at an animal, it will track that animal it was fired at. It will continue to track until the dart hits the
animal, where a decision is made as to whether the dose was just right, putting the animal to sleep, too little, causing the
animal to run around faster (in a bear's case, kill you), or too much, which will kill the animal. For each animal put to sleep
, the score will be added to based on the animal's weight, 10, 20, or 30. If an animal dies, that same weight cooresponding to 
an animal will be subtracted off the score. A cap is put on the max number of darts you have. This number can be changed via
editing a variable within the scene class.