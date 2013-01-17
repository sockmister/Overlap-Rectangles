/*
Overlaps.c
A corresponding C program for the Overlap.m program.
The program checks if 2 rectangles overlap each other.
*/

#include <stdio.h>

typedef struct Rectangle{
	int originX;
	int originY;
	int width;
	int height;
} Rectangle;

int isInBetween(int value, int start, int end){
	return (value <= end && value >= start);
}

int overlaps(struct Rectangle rect1, struct Rectangle rect2) {
  // EFFECTS: returns 1 if rectangles overlap and 0 otherwise
	
	//if 
	if(!isInBetween(rect1.originX, rect2.originX, rect2.originX + rect2.width) &&
			!isInBetween(rect2.originX, rect1.originX, rect1.originX + rect1.width))
		return 0;
		
	if(!isInBetween(rect1.originY, rect2.originY, rect2.originY + rect2.height) &&
			!isInBetween(rect2.originY, rect1.originY, rect1.originY + rect2.height))
		return 0;
	
	return 1;
}

int main(int argc, const char * argv[]){
	// declare rectangle 1 and rectangle 2
	Rectangle rect1, rect2;
	
	// input origin for rectangle 1
	printf("Input <x y> cooridnates for the origin of the first rectangle: ");
	scanf("%d %d", &rect1.originX, &rect1.originY);
	
	// input size (width and height) for rectangle 1
	printf("Input width and height of the first rectangle: ");
	scanf("%d %d", &rect1.width, &rect1.height);
	
	// input origin for rectangle 2
	printf("Input <x y> cooridnates for the origin of the second rectangle: ");
	scanf("%d %d", &rect2.originX, &rect2.originY);
	
	// input size (width and height) for rectangle 2
	printf("Input width and height of the second rectangle: ");
	scanf("%d %d", &rect2.width, &rect2.height);

	// check if overlapping and write message
	if(overlaps(rect1, rect2))
		printf("The two rectangle objects are overlapping!\n");	
	else
		printf("The two rectangles are not overlapping!\n");
}