//Insertion sort
#include <stdio.h>
#include <math.h>

/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n)
{
   int cmp_cnt = 0, cp_cnt = 0;
   int i, key, j;
   for (i = 1; i < n; i++)
   {
       cp_cnt++;		// count the # of data copy
       key = arr[i];
       j = i-1;

       /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
       cmp_cnt++;		// count the # of comparisons
       while (j >= 0 && arr[j] > key)
       {
           cp_cnt++;		// count the # of data copy
           arr[j+1] = arr[j];
           j = j-1;
       }
       cp_cnt++;		// count the # of data copy
       arr[j+1] = key;
   }
   printf("Insertion sort: %d comparison, %d copy\n", cmp_cnt, cp_cnt);
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

  insertionSort(a,6);

  printf("\nSorted Array: \n");

  show(a,6);
  return 0;
}
