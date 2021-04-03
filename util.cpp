#include "util.h"

char NEXT_COMMAND(){
	char c = ' ';
	while(true){
		scanf("%c",&c);
		while(c == '\n' || c == ' ' || c == '\t' )
			scanf("%c", &c);

		if (c == 'S' || c == 's') {
			c = 's';
			return c;
		}
		else if (c == 'R' || c == 'r') {
			c = 'r';
			return c;
		}
        else if (c == 'C' || c == 'c') {
            c = 'c';
            return c;
        }
		else if (c == 'P' || c == 'p') {
			c = 'p';
			return c;
		}
		else if (c == 'W' || c == 'w') {
			c = 'w';
			return c;
		}
		else if (c == 'D' || c == 'd') {
			c = 'd';
			return c;
		}
		else if (c == 'I' || c == 'i') {
			c = 'i';
			return c;
		}
		else{
			std::cout << "[ERROR]: invalid input " << c << std::endl;
			c = 'x';
			return c;
		}
	}
}