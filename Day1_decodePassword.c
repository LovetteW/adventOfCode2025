#include <stdio.h>
#include <ctype.h>

//Files tutorial I used: https://youtu.be/Hzg3kCHJcxI?si=mjyea-iNUuiqbhHn
//AI DISCLAIMER! I had to consult Clause 4.5 (see line 22) to get input into my program, lol. 

int main(){
	int dial = 50;
	int password = 0;
	
	FILE *filePointer = fopen("Rotations.txt", "r");
	
	// tested: 6 is the LOWEST value possible, here. I guess max 4 characters plus the \n and \0. I think I can tell the difference in speed, too!
	char rotationBuffer[6];
	//fgets() retrieves a single line with arguments of destination, max size, and pointer to file you're referencing.
	// since it will return NULL when we reach the end of a file...
	while(fgets(rotationBuffer, sizeof(rotationBuffer), filePointer) != NULL){
		char letter;
		int distance;
		int direction;
		int delta;
		//I hadn't learned on my own how to handle files, so I used Claude 4.5 to help be get input into my program. Not sure why the '&' reference operators were needed here, but no pointers or '&' throughout the iterations.
		sscanf(rotationBuffer, "%c%d", &letter, &distance);
		//printf("Letter: %c | Distance: %d | ", letter, distance);
		if(letter == 'L'){
			//decrement
			for(int i = 0; i < distance; i++){
				dial--;
				if(dial == 0){
				} else if(dial == -1){
					dial = 99;
				}
			}
		} else {
			//incrementing
			for(int i = 0; i < distance; i++){
				dial++;
				if(dial == 100){
					dial = 0;
				}
			}
		}
		password += dial == 0 ? 1 : 0;
		printf("%d | %d\n", password, dial);
	}
	fclose(filePointer);
	return 0;
}
