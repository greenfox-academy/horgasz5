#include <stdio.h>
#include <stdint.h>

int main() {
	uint8_t z = 13;
	// if z is between 10 and 20 print 'Sweet!'
	if(z > 10 && z < 20){
        printf("Sweet!\n");
	}else if(z < 10){
        printf("More!\n");
	}else if(z > 20){
        printf("Less!\n");
	}
	// if less than 10 print 'More!',
	// if more than 20 print 'Less!'
	return 0;
}
