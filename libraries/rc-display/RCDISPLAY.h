#ifndef RCDISPLAY_H
#define RCDISPLAY_H

#include <Arduino.h>

class RCDISPLAY{
  public:
  	//construtor | destructor
  	RCDISPLAY();
  	~RCDISPLAY();
  	//funcs
  	void displayShow(char text[5], bool d_points = false);
  private:
	//Funcs
	void nextFrame();
	uint8_t s(char letter);
};


#endif
