//Counting sort
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

//cp_cnt++;		// count the # of data copy
//cp_cnt++;		// count the # of data copy
//printf("Insertion sort: %d comparison, %d copy\n", cmp_cnt, cp_cnt);

// The Counting Sort function
void countSort(int arr[], int n)
{
    // The output sorted arr
    int *output;
    //Store Smallest and largest number
    output = malloc(n*sizeof(int));


    // Create a count array to store count of individual number, initialize count array as 0
    int *count;
    count = calloc(n, sizeof(int));
    int i;
    for(i=0;i<10;i++){
        count[i]=0;
        printf("i is %d and value is %d \n",i, count[i]);
    }
    printf("1st step Done.........    \n");

    // Store count of each number
    for(i = 0; i<n; i++){
        count[arr[i]]++;
        printf("arr[i] is %d and value is %d \n",arr[i], count[arr[i]]);
    }
    printf("2nd step Done.........    \n");

    // Change count[i] so that count[i] now contains actual position of this number in output array
    for (i = 1; i<10; i++){
        count[i] += count[i-1];
        printf("%d ", count[i]);
    }
    printf("\n3rd step Done......... \n");
    // Build the output array
    for (i = 0; i<n; i++)
    {
        output[count[arr[i]]-1] = arr[i];
        --count[arr[i]];
    }
    printf("\n4th step Done......... \n");
    // Copy the output array to arr, so that arr now contains sorted characters
    for (i = 0; arr[i]; ++i)
        arr[i] = output[i];
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

  countSort(a,6);

  printf("\nSorted Array: \n");

  show(a,6);
  return 0;
}
