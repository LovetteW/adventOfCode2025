#include <stdio.h>
#include <string.h>

/*here's a cool thing that happened during development (output of vim -r <file>):
Using swap file "~/Documents/adventOfCode2025/2wo/.Day2_IDtester.c.swp"
Original file "~/Documents/adventOfCode2025/2wo/Day2_IDtester.c"
Recovery completed. You should check if everything is OK.
(You might want to write out this file under another name
and run diff with the original file to check for changes)
You may want to delete the .swp file now.*/

int main(){
	int sum = 0;
	FILE *rangesFile = fopen("Product ID Ranges.txt", "r");
	if(!rangesFile){
		printf("Couldn't open file.\n");
		return 1;
	}
	
	//get the length of this big ol' single string we're working with. I'm finna implement a functionality that let's us recognize non-numeric characters, signalling a completion of a lower||upper bound, blah blah blah...
	char input[519]; //reducing to 518 yields a later inputLength of 517... How curious! Upper-bounds testing confirms the TRUE strlen(input) is 518 because it doesn't increase if we give the array more bytes.
	fgets(input, sizeof(input), rangesFile);
	printf("%s", input);

	int inputLength = strlen(input);
	printf("Input length: %d", inputLength); 

	//The fgetc() function returns the ASCII value of the character at the current position in the file and then moves the position indicator to the next character.[https://www.w3schools.com/c/ref_stdio_fgetc.php]
	
	//identify lower bound of product ID range. input sequence is predictable: [lower][hyphen][upper][comma]

	//while((c = fgetc(rangesFile)) != EOF){} //you NEED to do c = fgetc() so that each character gets assigned to c. The incrementing to the next char is done by the function itself
	
	return 0;
}
