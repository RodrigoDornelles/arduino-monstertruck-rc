#ifndef RCDISPLAY_H
#define RCDISPLAY_H

#include <Arduino.h>

class RCDISPLAY{
  public:
  	/*
  	 * construtor | destructor
  	 */
  	RCDISPLAY();
  	~RCDISPLAY();
  	/*
  	 * Display message
  	 */
  	void displayShow(const char text[5], bool d_points = false, uint8_t mode = 0);
   	void sliderShow(const char text[56], int speed);
   	void run(const char text[5]="rc ");
   	void error();
   	/*
   	 * Display processing
   	 */
  	void process(); 	
  	
  private:
  	/*
  	 *	Anim Display Modes	
		@MODE_NONE		0
		@MODE_RUNNING	1 
 		@MODE_SLIDER	2
  	 */
  	uint8_t	modeType;
  	//anim: run
  	unsigned long tickRunning;
  	uint8_t	running;
  	char runningText[5];
  	//anim: slider
  	unsigned long tickSlider;
  	uint8_t slider;
  	char sliderText[60];
  	int sliderSpeed;
  	/*
  	 * Animation display 
  	 */
	bool nextFrame();
	/*
	 * Convert Char to 7Seg Leet
	 */
	uint8_t s(char letter);
};
#endif
