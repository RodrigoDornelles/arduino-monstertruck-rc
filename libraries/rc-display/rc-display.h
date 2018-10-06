#include "Arduino.h"

class RCdisplay {
  public:
  	void ConfigDisplay();
  	void DisplayShow(char text[5], bool d_points = false);
  private:
	//Funcs
	void NextFrame();
	int8_t S(char letter);
};