#include <Arduino.h>

#include <RCDISPLAY.h>
#include <TM1637Display.h>	

#define CLK 4		//IO PWM
#define DIO 5		//IO PWM


#define MODE_NONE		0
#define MODE_RUNNING	1 
#define MODE_SLIDER		2

TM1637Display display(CLK, DIO);

/*
 *	Start Config
 */

RCDISPLAY::RCDISPLAY(){
	display.setBrightness(0x02);
}
RCDISPLAY::~RCDISPLAY(){/*nothing to destruct*/}


//-----------------------------------------------------------------------------------------
/*
 *	Show Message in Display 7 Seg
 */
void RCDISPLAY::displayShow(const char text[5], bool d_points, uint8_t mode){
	uint8_t segs[4];
	modeType=mode;

	for(int i = 0; i < 4; i++){
		segs[i]=s(text[i]);
	}

	display.setSegments(segs);	
}

void RCDISPLAY::sliderShow(const char text[56], int speed){
	sprintf(sliderText, "    %s", text);
	sliderSpeed=speed;
  	modeType=MODE_SLIDER;
  	slider=0;
}

void RCDISPLAY::run(const char text[5]){
	sprintf(runningText, "%s", text);
	modeType=MODE_RUNNING;
}
void RCDISPLAY::error(){
	displayShow("Erro");
}
//-----------------------------------------------------------------------------------------
/*
 * time synchronized processing
 */
void RCDISPLAY::process(){

	unsigned long now = millis();
	//---------------------------
	//RUNNING:	
	if(now > tickRunning + 60)
	{
		tickRunning = now;

		if(++running > 4)
			running = MODE_RUNNING;
	}
	//----------------------------
	//SLIDER
	if(now > tickSlider + sliderSpeed)
	{
		tickSlider = now;
		slider++;
	}
	//----------------------------
	nextFrame();
}
/*
 * animation display 
 */
bool RCDISPLAY::nextFrame(){
	char string[5];
	switch(modeType)
	{
		case MODE_RUNNING:	
			sprintf(string, "%s%c", runningText, (running + 0xA) );		
		break;

		case MODE_SLIDER:
			if( (strlen(sliderText) + 1) < slider)
				slider=0;

			if(slider == 0)
				sprintf(string, "   ");
			else
			{

				for(int i = 0; i < 4; i++)
					string[i]= sliderText[ (i + slider) ];	
			}
		break;

		default: 
			return false;
	}
	displayShow(string,false,modeType);
}

//-----------------------------------------------------------------------------------------
/*
 * Convert Char to 7Seg Leet
 */ 
uint8_t RCDISPLAY::s(char letter)
{

 	switch(letter)
	{
		case 'A': return 0b01110111;	case 'a': return 0b01011111;
		case 'B': return 0b01111100;	case 'b': return 0b01111100;
		case 'C': return 0b00111001;	case 'c': return 0b01011000;
		case 'D': return 0b01011110;	case 'd': return 0b01011110;
		case 'E': return 0b01111001;	case 'e': return 0b01111011;
		case 'F': return 0b01110001;	case 'f': return 0b01110001;
		case 'G': return 0b01111101;	case 'g': return 0b01111101;
		case 'H': return 0b01110110;	case 'h': return 0b01110110;
		case 'I': return 0b00110000;	case 'i': return 0b00000100;
		case 'J': return 0b00001110;	case 'j': return 0b00001100;
		case 'K': return 0b00111001;	case 'k': return 0b00111001;
		case 'L': return 0b00111000;	case 'l': return 0b00111000;
		case 'M': return 0b00110111;	case 'm': return 0b01010100;
		case 'N': return 0b00110111;	case 'n': return 0b01010100;
		case 'O': return 0b00111111;	case 'o': return 0b01011100;
		case 'P': return 0b01110011;	case 'p': return 0b01110011;
		case 'Q': return 0b01100111;	case 'q': return 0b01100111;
		case 'R': return 0b00110001;	case 'r': return 0b01010000;
		case 'S': return 0b01101101;	case 's': return 0b01101101;
		case 'T': return 0b00000111;	case 't': return 0b01000100;	
		case 'U': return 0b00111110;	case 'u': return 0b00011100;
		case 'V': return 0b00111110;	case 'v': return 0b00011100;
		case 'X': return 0b01110110;	case 'x': return 0b01110110;
		case 'W': return 0b00111110;	case 'w': return 0b00111110;
		case 'Y': return 0b01100110;	case 'y': return 0b01100110;
		case 'Z': return 0b01011011;	case 'z': return 0b01011011;
		case ' ': case 0x0: return 0b00000000;
		case '1': case 0x1:	return 0b00000110;	
		case '2': case 0x2:	return 0b01011011;	
		case '3': case 0x3:	return 0b01001111;	
		case '4': case 0x4:	return 0b01100110;	
		case '5': case 0x5:	return 0b01101101;	
		case '6': case 0x6:	return 0b01111101;
		case '7': case 0x7:	return 0b00000111;
		case '8': case 0x8:	return 0b01111111;
		case '9': case 0x9:	return 0b01101111;
		case '0': case 0xA:	return 0b00111111;
		case 0xB: return 0b01011000;//RUNING
		case 0xC: return 0b01010100;//RUNING
		case 0xD: return 0b01001100;//RUNING
		case 0xE: return 0b00011100;//RUNING 
		//especial:
		case 'Á': case 'À': case 'Â': case 'Ã': return s('A');
		case 'Ó': case 'Ò': case 'Ô': case 'Õ': return s('O');
		case 'Ú': case 'Ù': case 'Û': case 'Ü': return s('U');	
		case 'á': case 'à': case 'â': case 'ã': return s('a');
		case 'ó': case 'ò': case 'ô': case 'õ': return s('o');
		case 'ú': case 'ù': case 'û': case 'ü': return s('u');	
		case 'É': case 'È': case 'Ê': return s('E');
		case 'Í': case 'Ì': case 'Î': return s('I');
		case 'é': case 'è': case 'ê': return s('e');
		case 'í': case 'ì': case 'î': return s('i');
		case '.': case '_': case ',': return 0b00001000;
		case 'º': case '°': case '*': return 0b01100011;
		case '{': case '[': case '(': return 0b00111001;
		case '}': case ']': case ')': return 0b00001111;
		case 'ñ': case 'Ñ': return 0b01010101;		
		case '@': case 'ª': return 0b00100011;
		case '¢': case '<': return 0b01100001;
		case '>': return 0b01000011;
		case '?': return 0b00100111;
		case '¿': return 0b00111100;
		case 'Ç': return s('C');
		case 'ç': return s('c');
		default: return 0b01000000;
	}
}
