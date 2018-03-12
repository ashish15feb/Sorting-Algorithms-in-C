//Counting sort
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

//cp_cnt++;		// count the # of data copy
//cmp_cnt++;		// count the # of data comparison
//printf("Insertion sort: %d comparison, %d copy\n", cmp_cnt, cp_cnt);

// Merges two sub-arrays of arr[].
// First sub-array is arr[left..middle], Second sub-array is arr[middler+1..right]
void merge(int arr[], int left, int middle, int right)
{
    int i, j, k;
    static int cp_cnt=0, cmp_cnt=0;
    int lenLeftArray = middle - left + 1;
    int lenRightArray =  right - middle;

    //create temp arrays
    int leftArray[lenLeftArray], rightArray[lenRightArray];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (i = 0; i < lenLeftArray; i++){
        leftArray[i] = arr[left + i];
        cp_cnt++;		// count the # of data copy
    }
    for (j = 0; j < lenRightArray; j++){
        rightArray[j] = arr[middle + 1+ j];
        cp_cnt++;		// count the # of data copy
    }

    /* Merge the temp arrays back into arr[]*/
    i = 0; // Initial index of first sub-array
    j = 0; // Initial index of second sub-array
    k = left; // Initial index of merged sub-array
    while (i < lenLeftArray && j < lenRightArray)
    {
        cmp_cnt++;		// count the # of data comparison
        if (leftArray[i] <= rightArray[j])
        {
            arr[k] = leftArray[i];
            cp_cnt++;		// count the # of data copy
            i++;
        }
        else
        {
            arr[k] = rightArray[j];
            cp_cnt++;		// count the # of data copy
            j++;
        }
        k++;
    }

    //Copy the remaining elements of leftArray[], if there are any
    while (i < lenLeftArray)
    {
        arr[k] = leftArray[i];
        cp_cnt++;		// count the # of data copy
        i++;
        k++;
    }

    // Copy the remaining elements of rightArray[], if there are any
    while (j < lenRightArray)
    {
        arr[k] = rightArray[j];
        cp_cnt++;		// count the # of data copy
        j++;
        k++;
    }
    printf("Merge sort: %d comparison, %d copy\n", cmp_cnt, cp_cnt);
}

//Merge Sort Function
void mergeSort(int arr[], int left, int right)//Left holds left-most element's index, right holds right-most element's index
{
    if (left < right)
    {
        int middle = left+(right-left)/2;//middle element of the array

        // Sort left-half of array
        mergeSort(arr, left, middle);
        //Sort right-half of array
        mergeSort(arr, middle+1, right);
        //Merge sorted left and half arrays
        merge(arr, left, middle, right);
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

  mergeSort(a,0, 5);

  printf("\nSorted Array: \n");


    show(a,6);

    return 0;
}
