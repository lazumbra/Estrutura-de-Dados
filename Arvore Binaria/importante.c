/*
  This program sorts an array of elements using the bubble sort algorithm
  By: randerson112358
  
  Output:
  Enter total number(s) of elements: 4
  Enter the 4 elements: 1 5 4 3
  After Sorting: 1 3 4 5
  
*/

#include <stdio.h>

int BubbleSort(int size, int *array);

int main(void){
	
	int size, i, array[20];
	
	printf("Enter total number(s) of elements: ");
	scanf("%d", &size);
	
	printf("Enter the %d elements: ", size);
	for(i=0; i<size; i++){
		scanf("%d", &array[i]);
	}
	
	//Run the Bubble Sort Algorithm to sort the list of elements
	BubbleSort(size, array);
	
	printf("After Sorting: ");
	for(i=0; i<size; i++){
		printf(" %d", array[i]);
	}
	
	printf("\n");
	system("pause"); // comment this line if you are not using Windows OS
	return 0; 
}

int BubbleSort(int size, int *array){
	
	int i, j, temp;
	
	//Bubble sorting algorthm
	for(i=size-2; i>= 0; i--){
		for(j=0; j<=i; j++){
			
			//Swap
			if(array[j] > array[j+1]){
				temp = array[j];
				array[j] = array[j+1];
				array[j+1]= temp;
			}
		}
	}
	
	return 1;
}


FIM 
#include <stdio.h>

#define LEN 20

int insertion_sort(int *array, int n)
{
	--n; /* considering that n is the real size of elements */

	if (n < 1)
		return -1;

	for (int i = 1; i <= n; ++i) {
		int tmp = array[i]; /* save the current value */
		int prev;

		/*
		 * move elements that are greater than current value
		 * one position ahead
		 */
		for (prev = i - 1; prev >= 0 && array[prev] > tmp; --prev)
			array[prev + 1] = array[prev];

		/* save current value to sorted position */
		array[prev + 1] = tmp;
	}

	return 0;
}

int main(void)
{
	int array[LEN] = {3, 1, 4, 7, 10,
			  20, 17, 19, 15, 16,
			  18, 2, 5, 6, 8,
			  9, 11, 13, 12, 14};

	insertion_sort(array, LEN);

	for (int i = 0; i < LEN; ++i)
		printf("%d ", array[i]);

	return 0;
}

fim

/*
 * 
 * compile: gcc quicksort.c
 * test: ./a.out
 *
 */

#include <stdio.h>

enum { SIZE = 9 };

void quicksort(int *target, int left, int right) {
  if(left >= right) return;
  int i = left, j = right;
  int tmp, pivot = target[i];
  for(;;) {
    while(target[i] < pivot) i++;
    while(pivot < target[j]) j--;
    if(i >= j) break;
    tmp = target[i]; target[i] = target[j]; target[j] = tmp;
    i++; j--;
  }
  quicksort(target, left, i-1);
  quicksort(target, j+1, right);
}

int main() {
  int i, array[SIZE] = { 2, 6, 3, 8, 5, 4, 1, 9, 7 };

  quicksort(array, 0, SIZE-1);

  for(i=0; i<SIZE; i++)
    printf("%d ", array[i]);
  printf("\n");
}

fim
selection sort 
#include <stdio.h>

#define LEN 20

int selection_sort(int *array, int n)
{
	--n; /* considering that n is the real size of elements */

	if (n < 1)
		return -1;

	for (int i = 0; i < n - 1; ++i) {
		int min = i;

		/* find next smallest */
		for (int j = i + 1; j <= n; ++j)
			if (array[j] < array[min])
				min = j;

		/* swap smallest with current value */
		if (min != i) {
			int tmp = array[i];
			array[i] = array[min];
			array[min] = tmp;
		}
	}

	return 0;
}

int main(void)
{
	int array[LEN] = {3, 1, 4, 7, 10,
			  20, 17, 19, 15, 16,
			  18, 2, 5, 6, 8,
			  9, 11, 13, 12, 14};

	selection_sort(array, LEN);

	for (int i = 0; i < LEN; ++i)
		printf("%d ", array[i]);

	return 0;
}

