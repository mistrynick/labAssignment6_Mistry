#include <stdio.h>
#include <stdlib.h>

int search(int numbers[], int low, int high, int value) 
{
    if (low > high) {
        return -1; // Returns false when low is greater than high which is a condition in which the value being searched is not present in the list
    }
    int mid = (high + low) / 2;
    if (value == numbers[mid]) {
      return mid;
    }
    if (value > numbers[mid]) { // value is on the right side of the mid
        mid++;
        return search(numbers,mid,high,value);
    } else {
        mid--; // value is on the left side
        return search(numbers,low,mid,value);
    }
    
	return -1;
}

void printArray(int numbers[], int sz)
{
	int i;
	printf("Number array : ");
	for (i = 0;i<sz;++i)
	{
		printf("%d ",numbers[i]);
	}
	printf("\n");
}

int main(void)
{
	int i, numInputs;
	char* str;
	float average;
	int value;
	int index;
	int* numArray = NULL;
	int countOfNums;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &countOfNums);
		numArray = (int *) malloc(countOfNums * sizeof(int));
		average = 0;
		for (i = 0; i < countOfNums; i++)
		{
			fscanf(inFile," %d", &value);
			numArray[i] = value;
			average += numArray[i];
		}

		printArray(numArray, countOfNums);
		value = average / countOfNums;
		index = search(numArray, 0, countOfNums - 1, value);
		if (index >= 0)
		{
			printf("Item %d exists in the number array at index %d!\n",value, index);
		}
		else
		{
			printf("Item %d does not exist in the number array!\n", value);
		}

		free(numArray);
	}

	fclose(inFile);
}
