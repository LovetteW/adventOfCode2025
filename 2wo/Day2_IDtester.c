#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Don't forget you need your \0 terminators at the end of strings.

int main(){
	int sum = 0;
	int *s = &sum;

	//declare a pointer for a file-type data using the return value of the fopen() function
	FILE *rangesFile = fopen("Product ID Ranges.txt", "r");
	//read the value of rangesFile (for a pointer it'll be a valid 0x/ hex address or NULL/0) and if not the valid thing then oopsie, let 'em know we got a problem
	if(!rangesFile){
		printf("Couldn't open file.\n");
		return 1;
	}
	//prepare a character variable to store that single long string we see in the input file [https://pastebin.com/Uz63VRqW]
	char input[2550];

	fgets(input, sizeof(input), rangesFile);
	printf("Input:\n%s\n", input);
	int inputLength = strlen(input);
	printf("Input length: %d\n", inputLength); 
	int index = 0;
	char bufferThatEventuallyTurnsIntoTheFirstProductID[255];
	int bufferIndex = 0;
	int lower;
	char bufferThatMaybeOneDayWillGrowUpToBeSantaClause[255];
	int upper;
	char *theCutestPointerThatEverWas = bufferThatEventuallyTurnsIntoTheFirstProductID;

	int isLeadingZero(int productIDnum){
		char productID[255];
		itoa(productIDnum, productID, 10);
		if(productID[0] == '0' || productID[0] == 0){
			printf("LEADING ZERO FOUND!");
			return 1;
		} else {
			return 0;
		}
	}
	
	int isRepeater(int productIDnum){
		char productID[255];
		itoa(productIDnum, productID, 10);
		int i = 0;
		int length = strlen(productID);
		char firstHalf[255];
		char secondHalf[255];
		for(; i <= length; i++){
			firstHalf[i] = productID[i];
			i++;
			while(i >= length/2){
				secondHalf[i-(length/2)] = productID[i];
				i++;

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
