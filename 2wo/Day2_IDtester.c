#include <stdio.h>

int main(){
	FILE *rangesFile = fopen("Product ID Ranges.txt", "r");
	if(!rangesFile){
		printf("Couldn't open file.\n");
		return 1;
	}
	//The fgetc() function returns the ASCII value of the character at the current position in the file and then moves the position indicator to the next character.[https://www.w3schools.com/c/ref_stdio_fgetc.php]
	char c;
	while((c = fgetc(rangesFile)) != EOF){ //you NEED to do c = fgetc() so that each character gets assigned to c. The incrementing to the next char is done by the function itself
		printf("%c", c);
		}
	return 0;
}
