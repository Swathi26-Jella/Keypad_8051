#include <reg51.h>
#define keypad_port P1

char keypad_getkey(void){
	unsigned char row,col;
	while(1){
		for(row=0;row<4;row++){
			keypad_port = 0XFF;
			keypad_port &= ~(1<<row); // make one row low
			for(col = 0;col<4;col++){
				if(!(keypad_port & (0X10 <<col))){//check each column
					while(!(keypad_port &(0X10 <<col))); //wait for release
				  //keypad layout mapping
				  switch(row){
						case 0: if(col==0) return '7';
										if(col==1) return '8';
										if(col==2) return '9';
										if(col==3) return '/';  break;
						case 1: if(col==0) return '4';
										if(col==1) return '5';
										if(col==2) return '6';
										if(col==3) return '*';  break;
						case 2: if(col==0) return '1';
										if(col==1) return '2';
										if(col==2) return '3';
										if(col==3) return '-';  break;
						case 3: if(col==0) return 'C';
										if(col==1) return '0';
										if(col==2) return '=';
										if(col==3) return '+';  break;
					}
				}
			}
		}
	}
}