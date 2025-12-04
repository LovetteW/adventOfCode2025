#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*here's a cool thing that happened during development (output of vim -r <file>):
Using swap file "~/Documents/adventOfCode2025/2wo/.Day2_IDtester.c.swp"
Original file "~/Documents/adventOfCode2025/2wo/Day2_IDtester.c"
Recovery completed. You should check if everything is OK.
(You might want to write out this file under another name
and run diff with the original file to check for changes)
You may want to delete the .swp file now.*/

int main(){
	int sum = 0;
	int *s = &sum;
	FILE *rangesFile = fopen("Product ID Ranges.txt", "r");
	if(!rangesFile){
		printf("Couldn't open file.\n");
		return 1;
	}
	
	//get the length of this big ol' single string we're working with. I'm finna implement a functionality that let's us recognize non-numeric characters, signalling a completion of a lower||upper bound, blah blah blah...
	char input[519]; //517 chars + \n + \0. Reducing array size to 518 yields a later inputLength of 517... How curious! Upper-bounds testing confirms the TRUE strlen(input) is 518 because it doesn't increase if we give the array more bytes.
	fgets(input, sizeof(input), rangesFile);
	printf("%s", input);


	int inputLength = strlen(input);
	printf("\nInput length: %d\n", inputLength); 
	//The fgetc() function returns the ASCII value of the character at the current position in the file and then moves the position indicator to the next character.[https://www.w3schools.com/c/ref_stdio_fgetc.php]
	int index = 0;
	char bufferThatEventuallyTurnsIntoTheFirstProductID[20];
	int bufferIndex = 0;
	int lower;
	char bufferThatMaybeOneDayWillGrowUpToBeSantaClause[20];
	int upper;
	char *theCutestPointerThatEverWas = bufferThatEventuallyTurnsIntoTheFirstProductID;

	//feed an integer within the product range
	int isLeadingZero(int productIDnum){
		char productID[20];
		itoa(productIDnum, productID, 10);
		if(productID[0] == '0' || productID[0] == 0){
			printf("LEADING ZERO FOUND!#################################################################");
			return 1;
		} else {
			return 0;
		}
	}
	//input is an array
	int isRepeater(int productIDnum){
		char productID[20];
		itoa(productIDnum, productID, 10);
		int i = 0;
		int length = strlen(productID);
		char firstHalf[10];
		char secondHalf[10];
		for(; i <= length; i++){
			firstHalf[i] = productID[i];
			i++;
			while(i >= length/2){
				secondHalf[i-(length/2)] = productID[i];
			}
		}
		printf("firstHalf: %c | secondHalf: %c", firstHalf[0], secondHalf[0]);
		int firstHalfnum = atoi(firstHalf);
		int secondHalfnum = atoi(secondHalf);
		if(firstHalfnum == secondHalfnum){
			return 1;
		} else {
			return 0;
		}
	}

	int sumOfInvalidIDsWithinRange(int lower, int upper){
		for(int i = lower; i <= upper; i++){
			if(isLeadingZero(i) || isRepeater(i)){
				*s += i;
			}
		}
	}

	while(input[index] != '\0'){
		int *l = &lower;
		int *u = &upper;
		theCutestPointerThatEverWas[bufferIndex] = input[index];
		//This part is normal names, no * or &. "When you do &bufferName, you're getting a pointer-to-an-array (type char (*)[20]), but you want a pointer-to-char (type char *)."
		switch(input[index]){
			case '-':
				*l = atoi(bufferThatEventuallyTurnsIntoTheFirstProductID);
				theCutestPointerThatEverWas = bufferThatMaybeOneDayWillGrowUpToBeSantaClause;
				bufferIndex = 0;
				index++;
				break;
			case ',':
				*u = atoi(bufferThatMaybeOneDayWillGrowUpToBeSantaClause);
				printf("Lower: %d, Upper: %d\n", lower, upper);
				sumOfInvalidIDsWithinRange(lower, upper);
				theCutestPointerThatEverWas = bufferThatEventuallyTurnsIntoTheFirstProductID;
				bufferIndex = 0;
				index++;
				break;
			default:
				printf("Added char '%c' to %p\n", input[index], *theCutestPointerThatEverWas);
				index++;
		}
	}	

	printf("Sum of all invalid product IDs: %i\n", sum);
	
	return 0;
}
