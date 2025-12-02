#include <stdio.h>
#include <stdlib.h>

int main(){
	printf("Successful launch.");
	int dial = 50;
	int password = 0;
	char letter;
	int direction;
	int distance;
	int delta;
	//scanf automatically handles the variable number of digits in the int as it reads until hitting the new line
	// the whitespace before %c tells the function to skip any whitespace like \n in the input buffer since preceding %d will stop at \0
	while(scanf(" %c%d", letter, distance) == 2){
		if(letter == 'L'){
			direction = -1;
		} else {
			direction = 1;
		}
		delta = direction * distance;
		dial += delta;
		if(dial == 0){
			password++;
		} else if(dial > 99){
			dial -= 100;
		} else if(dial < 00){
			dial = 100 - abs(dial);
		}
	}
	printf("Password/ times at dead 00: %d", password);
	return 0;
}
