#include <stdio.h>
#include <ctype.h>

//https://youtu.be/Hzg3kCHJcxI?si=mjyea-iNUuiqbhHn

int main(){
	printf("Successful launch!\n");
	int dial = 50;
	int *dialPointer = &dial;
	int password = 0;
	int *passwordPointer = &password;
	FILE *filePointer = fopen("Rotations.txt", "r");
	
	char rotationBuffer[10];
	//fgets() retrieves a single line with arguments of destination, max size, and pointer to file you're referencing.
	// since it will return NULL when we reach the end of a file...
	while(fgets(rotationBuffer, 10, filePointer) != NULL){
		char letter;
		int distance;
		int direction;
		int delta;
		sscanf(rotationBuffer, "%c%d", &letter, &distance);
		printf("Letter: %c | Distance: %d | ", letter, distance);
		direction = letter == 'L' ? -1 : 1;
		delta = direction * distance;
		dial += delta;
		printf("Delta: %d | New Dial Position: %d\n", delta, dial);
	}
	fclose(filePointer);
/*


	char letter;
	int n1;
	int n2;
	int numbers[2];
	int direction;
	int distance;
	int *dis;
	int delta;
	//scanf automatically handles the variable number of digits in the int as it reads until hitting the new line
	// the whitespace before %c tells the function to skip any whitespace like \n in the input buffer since preceding %d will stop at \0
	FILE *f = fopen("Day1_input.txt", "r");
	if(!f) {
		printf("Cannot open file\n");
		return 1;
	} else {
		printf("File opened\n");
	}
	char line[10];
	while(fgets(line, sizeof(line), f)){
		printf("Line: %s\n", line);
		letter = line[0];
		numbers[0] = line[1];
		if(line[2] == '\n' || line[2] == '\0'){
			distance = numbers[0];
		} else {
			numbers[1] = line[2];
			distance = (numbers[0] * 10) + numbers[1];
		}
		printf("Distance: %d", distance);
		//printf("Line: %c | %d | %d\n", letter, n1, n2);
		//if(line[2] == '\n' || line[2] == '\0'){
			printf("Line[0]: %c";
		} else {
			*dis = (line[0] * 10) + line[1];
		}
		printf("Grabbed number \"%d\" from line.", distance);
		if(letter == 'L'){
			direction = -1;
		} else {
			direction = 1;
		}
		printf("Direction: %d, Distance: %d\n", direction, distance);
		delta = direction * distance;
		dial += delta;
		printf("New dial value: %d\n", dial);
		if(dial == 0){
			password++;
		} else if(dial > 99){
			dial = dial % 100;
		} else if(dial < 0){
			dial = 100 + (dial % 100);
		}//
	}
	fclose(f);
	printf("Password/ times at dead 00: %d\n", password);*/
	return 0;
}
