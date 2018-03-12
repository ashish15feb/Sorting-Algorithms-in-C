//Counting sort
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

//cp_cnt++;		// count the # of data copy
//cmp_cnt++;		// count the # of data comparison
//printf("Insertion sort: %d comparison, %d copy\n", cmp_cnt, cp_cnt);

// The Counting Sort function
void countSort(int arr[],int smallest, int largest, int lenOfArray)
{
    int cp_cnt=0, cmp_cnt=0;
    // The output sorted arr
    int *output;
    //Store Smallest and largest number
    output = malloc(lenOfArray*sizeof(int));


    // Create a count array to store count of individual number, initialize count array as 0
    int *count;
    count = calloc((largest-smallest+1), sizeof(int));
    int i;
    for(i=0;i<(largest-smallest+1);i++){
        count[i]=0;
    }

    // Store count of each number
    for(i = 0; i<lenOfArray; i++){
        count[arr[i]-smallest]++;
        printf("arr[i] is: %d, smallest is: %d, count[arr[i]-smallest] is %d \n", arr[i],smallest,count[arr[i]-smallest]);
    }

    // Change count[i] so that count[i] now contains actual position of this number in output array
    for (i = 1; i<(largest-smallest+1); i++){
        count[i] += count[i-1];
        //printf("count of (i+smallest) %d is %d: \n", i+smallest, count[i]);
    }

    // Build the output array
    for (i = 0; i<lenOfArray; i++)
    {
        output[count[arr[i]-smallest]-1] = arr[i];
        cp_cnt++;		// count the # of data copy
        printf("i is %d, arr [i] is %d, arr[i]-smallest is %d, count[arr[i]-smallest]-1 is %d, output[count[arr[i]-smallest]-1] is %d \n", i, arr[i], arr[i]-smallest, count[arr[i]-smallest]-1, output[count[arr[i]-smallest]-1]);
        --count[arr[i]-smallest];
        printf("count[arr[i] is %d\n", count[arr[i]-smallest]);
    }

    // Copy the output array to arr, so that arr now contains sorted characters
    for (i = 0; i<lenOfArray; i++){
        arr[i] = output[i];
        cp_cnt++;		// count the # of data copy
        printf("%d\n", output[i]);
    }
    printf("Counting sort: %d comparison, %d copy\n", cmp_cnt, cp_cnt);
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

  countSort(a, -10, 3000, 6);

  printf("\nSorted Array: \n");


    show(a,6);

    return 0;
}
