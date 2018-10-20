#include <Arduino.h>

#include <RCDISPLAY.h>
#include <TM1637Display.h>	

#define CLK 4		//IO PWM
#define DIO 5		//IO PWM

TM1637Display display(CLK, DIO);

/*
 *	Start Config
 */

RCDISPLAY::RCDISPLAY(){
	display.setBrightness(0x02);
}
RCDISPLAY::~RCDISPLAY(){/*nothing to destruct*/}

/*
 *	Show Message in Display 7 Seg
 */
void RCDISPLAY::displayShow(char text[5], bool d_points){
	uint8_t segs[4];

	for(int i = 0; i < 4; i++){
		segs[i]=s(text[i]);
	}

	display.setSegments(segs);	
}
/*
 * Convert Char to 7Seg Leet
 */ 
uint8_t RCDISPLAY::s(char letter)
{
 	switch(letter)
	{
		case '0': return 0b00111111;
		case '1': return 0b00000110;
		case '2': return 0b01011011;
		case '3': return 0b01001111;
		case '4': return 0b01100110;
		case '5': return 0b01101101;
		case '6': return 0b01111101;
		case '7': return 0b00000111;
		case '8': return 0b01111111;
		case '9': return 0b01101111;
		case 'A': return 0b01110111;
		case 'B': return 0b01111100;
		case 'C': return 0b00111001;
		case 'D': return 0b01011110;
		case 'E': return 0b01111001;
		case 'F': return 0b01110001;
		case 'G': return 0b01111101;
		case 'H': return 0b01110110;
		case 'I': return 0b00110000;
		case 'J': return 0b00001110;
		case 'L': return 0b00111000;
		case 'N': return 0b00110111;
		case 'P': return 0b01110011;
		case 'R': return 0b00110001;
		case 'S': return 0b01101101;
		case 'O': return 0b00111111;
		case 'U': return 0b00111110;
		case 'a': return 0b01011111;
		case 'e': return 0b01111011;
		case 'i': return 0b00000100;
		case 'o': return 0b01011100;
		case 'u': return 0b00011100;
		case 'r': return 0b01010000;
		case 'c': return 0b01011000;
		case 'd': return 0b01011110;
		case 'n': return 0b01010100;
		case ' ': return 0b00000000;
		case '.': return 0b00001000;
		case '_': return 0b00001000;
		case 0x0: return 0b00000000;
		case 0x4: return 0b00011100;//RUNING 
		case 0x3: return 0b01001100;//RUNING
		case 0x2: return 0b01010100;//RUNING
		case 0x1: return 0b01011000;//RUNING
		default: return 0b01000000;
	}
}


