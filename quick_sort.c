//Quick sort
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

/*
*Worst case time complexity of Quick sort is O(n_square). While Average complexity is O(nlogn).
*IF we select left-most or right-most element as pivot, and if the array is reverse sorted or sorted then complexity will be high.
*But, if we select the pivot randomly, an time complexity of O(nlogn) is achievable on average even if the arrays is reverse/or sorted.
*/

int cp_cnt, cmp_cnt;
//swap function, swaps two elements of the array
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    cp_cnt += 3;		// count the # of data copy
}

//partition function divides the array in two parts, first having values which are less than pivot, second having values greater than pivot
int partion(int arr[], int left, int right)
{
    int pivotIndex = left + rand()%(right - left + 1); //generates a random number as a pivot

    printf("\n%d\n", rand()%(right - left + 1));

    int pivot;//stores value of pivot
    int lesser = left - 1;//holds index of element having lesser value than pivot
    int j;//used to traverse array
    pivot = arr[pivotIndex];
    swap(&arr[pivotIndex], &arr[right]);//swap function
    for (j = left; j < right; j++)//traverse array
    {
        cmp_cnt++;		// count the # of data comparison
        if (arr[j] < pivot)//check if current element is less than pivot
        {
            lesser++;
            swap(&arr[lesser], &arr[j]);//start from the start of array, put elements which are less than pivot in first half of array, keep moving till end of array
        }

    }
    swap(&arr[lesser+1], &arr[right]);//put pivot at its place in the array, the second half has numbers greater than pivot
    return lesser + 1;//return index of pivot element
}

//Quick sort function
void quickSort(int arr[], int left, int right)
{
    int partitionIndex;
    if (left < right)//check if there is only one element in the array, BASE Condition
    {
        partitionIndex = partion(arr, left, right);//get index of pivot element
        quickSort(arr, left, partitionIndex-1);//recursion, first half of array
        quickSort(arr, partitionIndex+1, right);//recursion, second half of array
    }
}


// This function prints the array
void show(int arr[], int n)
{ int i;
  for (i=0; i<n; i++)
    printf("%2d: %d\n", i, arr[i]);
}


 int main(void)
{ int a[6], i;

  printf("Enter 6 integers:\n");
  for (i=0; i<6; i++){
    scanf("%d", &a[i]);
  }
  show(a,6);

  quickSort(a,0, 5);

  printf("\nSorted Array: \n");


    show(a,6);
    printf("\nInsertion sort: %d comparison, %d copy\n", cmp_cnt, cp_cnt);
    return 0;
}
