//Project1

/*
*Worst case time complexity of Quick sort is O(n-square). While Average complexity is O(nlogn).
*IF we select left-most or right-most element as pivot, and if the array is reverse sorted or sorted then complexity will be high.
*But, if we select the pivot randomly, an time complexity of O(nlogn) is achievable on average even if the arrays is reverse/or sorted.
*/


/*
*There are functions for each Sorting Algorithm.
*I have used an additional array for each algorithm to store and return Copy and Comparison counts.
*/
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

//Buble Sort
void bubble_sort(int a[], int n, int compCopyCountBubble[])
{ int cmp_cnt = 0, cp_cnt = 0;
  int i, j, tmp;
  for (i=0; i<n; i++)
  { for (j=n-1; j>=i+1; j--)
    { cmp_cnt++;		// count the # of comparisons
      if (a[j] < a[j-1])
      { cp_cnt += 3;		// count the # of data copy
        tmp = a[j];
        a[j] = a[j-1];
        a[j-1] = tmp;
      }
    }
  }
    compCopyCountBubble[0] = cmp_cnt;
    compCopyCountBubble[1] = cp_cnt;
  //printf("Bubble sort: %d comparison, %d copy\n", cmp_cnt, cp_cnt);
  //printf("-------Bubble Done!!!-------\n");
}



//----------------COUNTING---------------------------------------------------------------------------------------------------
// The Counting Sort function
void countSort(int arr[],int smallest, int largest, int lenOfArray, int compCopyCountCounting[])
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
        //printf("arr[i] is: %d, smallest is: %d, count[arr[i]-smallest] is %d \n", arr[i],smallest,count[arr[i]-smallest]);
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
        //printf("i is %d, arr [i] is %d, arr[i]-smallest is %d, count[arr[i]-smallest]-1 is %d, output[count[arr[i]-smallest]-1] is %d \n", i, arr[i], arr[i]-smallest, count[arr[i]-smallest]-1, output[count[arr[i]-smallest]-1]);
        --count[arr[i]-smallest];
        //printf("count[arr[i] is %d\n", count[arr[i]-smallest]);
    }

    // Copy the output array to arr, so that arr now contains sorted characters
    for (i = 0; i<lenOfArray; i++){
        arr[i] = output[i];
        cp_cnt++;		// count the # of data copy
        //printf("%d\n", output[i]);
    }
    compCopyCountCounting[0] = cmp_cnt;
    compCopyCountCounting[1] = cp_cnt;
    //printf("Counting sort: %d comparison, %d copy\n", cmp_cnt, cp_cnt);
}


//---------------INSERTION------------------------------------------------------------------------------------------------------
/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n, int compCopyCountInsertion[])
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
   compCopyCountInsertion[0] = cmp_cnt;
   compCopyCountInsertion[1] = cp_cnt;
   //printf("Insertion sort: %d comparison, %d copy\n", cmp_cnt, cp_cnt);
   //printf("-------Insertion Done!!!-------\n");
}

//---------MERGE----------------------------------------------------------------------------------------------------------

// Merges two sub-arrays of arr[].
// First sub-array is arr[left..middle], Second sub-array is arr[middler+1..right]
static int mergeCp_cnt=0, mergeCmp_cnt=0;
void merge(int arr[], int left, int middle, int right)
{
    int i, j, k;

    int lenLeftArray = middle - left + 1;
    int lenRightArray =  right - middle;

    //create temp arrays
    int leftArray[lenLeftArray], rightArray[lenRightArray];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (i = 0; i < lenLeftArray; i++){
        leftArray[i] = arr[left + i];
        mergeCp_cnt++;		// count the # of data copy
    }
    for (j = 0; j < lenRightArray; j++){
        rightArray[j] = arr[middle + 1+ j];
        mergeCp_cnt++;		// count the # of data copy
    }

    /* Merge the temp arrays back into arr[]*/
    i = 0; // Initial index of first sub-array
    j = 0; // Initial index of second sub-array
    k = left; // Initial index of merged sub-array
    while (i < lenLeftArray && j < lenRightArray)
    {
        mergeCmp_cnt++;		// count the # of data comparison
        if (leftArray[i] <= rightArray[j])
        {
            arr[k] = leftArray[i];
            mergeCp_cnt++;		// count the # of data copy
            i++;
        }
        else
        {
            arr[k] = rightArray[j];
            mergeCp_cnt++;		// count the # of data copy
            j++;
        }
        k++;
    }

    //Copy the remaining elements of leftArray[], if there are any
    while (i < lenLeftArray)
    {
        arr[k] = leftArray[i];
        mergeCp_cnt++;		// count the # of data copy
        i++;
        k++;
    }

    // Copy the remaining elements of rightArray[], if there are any
    while (j < lenRightArray)
    {
        arr[k] = rightArray[j];
        mergeCp_cnt++;		// count the # of data copy
        j++;
        k++;
    }

    //printf("Merge sort: %d comparison, %d copy\n", cmp_cnt, cp_cnt);
}

//Merge Sort Function
void mergeSort(int arr[], int left, int right, int compCopyCountMerge[])//Left holds left-most element's index, right holds right-most element's index
{
    if (left < right)
    {
        int middle = left+(right-left)/2;//middle element of the array

        // Sort left-half of array
        mergeSort(arr, left, middle, compCopyCountMerge);
        //Sort right-half of array
        mergeSort(arr, middle+1, right, compCopyCountMerge);
        //Merge sorted left and half arrays
        merge(arr, left, middle, right);
    }
    compCopyCountMerge[0] = mergeCmp_cnt;
    compCopyCountMerge[1] = mergeCp_cnt;
    //printf("-------Merge Done!!!-------\n");
}

//----------QUICK----------------------------------------------------------------------------------------------------------


static int quickCp_cnt, quickCmp_cnt;
//swap function, swaps two elements of the array
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    quickCp_cnt += 3;		// count the # of data copy
}

//partition function divides the array in two parts, first having values which are less than pivot, second having values greater than pivot
int partion(int arr[], int left, int right)
{
    int pivotIndex = left + rand()%(right - left + 1); //generates a random number as a pivot

    //printf("\n%d\n", rand()%(right - left + 1));

    int pivot;//stores value of pivot
    int lesser = left - 1;//holds index of element having lesser value than pivot
    int j;//used to traverse array
    pivot = arr[pivotIndex];
    swap(&arr[pivotIndex], &arr[right]);//swap function
    for (j = left; j < right; j++)//traverse array
    {
        quickCmp_cnt++;		// count the # of data comparison
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
void quickSort(int arr[], int left, int right, int compCopyCountQuick[])
{
    int partitionIndex;
    if (left < right)//check if there is only one element in the array, BASE Condition
    {
        partitionIndex = partion(arr, left, right);//get index of pivot element
        quickSort(arr, left, partitionIndex-1, compCopyCountQuick);//recursion, first half of array
        quickSort(arr, partitionIndex+1, right, compCopyCountQuick);//recursion, second half of array
    }
    compCopyCountQuick[0] = quickCmp_cnt;
    compCopyCountQuick[1] = quickCp_cnt;
    //printf("-------Quick Done!!!-------\n");
}



//--------MAIN()-------------------------------------------------------------------------------------------------------------

int main(int argc, char *argv[])
{

    // We assume argv[1] is a filename to open
    FILE *file = fopen( argv[1], "r" );//Input File
    FILE *outfile = fopen( argv[2], "w" );//Output File
    FILE *evaluationFile = fopen(argv[3], "w");//Stores performance measurement of each sorting algorithm

    /* fopen returns 0, the NULL pointer, on failure */
    if ( file == 0 )
    {
        printf( "Could not open file\n" );
    }
    else
    {
        int number=0, i=0;
        int firstLine[3];

        //Read first Three numbers from the file
        while( fscanf(file, "%d,", &number) > 0 && i<3){
            firstLine[i]=number;
            i++;
        }
        //Create and array of size "n"
        int* numberArray;
        int* bubbleArray;
        int* insertionArray;
        int* countingArray;
        int* mergeArray;
        int* quickArray;

        //Create array to store Copy and Comparison count
        int* compCopyCountBubble;
        int* compCopyCountInsertion;
        int* compCopyCountCounting;
        int* compCopyCountMerge;
        int* compCopyCountQuick;

        //Store Number of elements, Smallest and largest number in variables
        int numOfElements = firstLine[0], smallest = firstLine[1], largest = firstLine[2];

        //Memory allocation for arrays
        numberArray = malloc(numOfElements*sizeof(int));
        bubbleArray = malloc(numOfElements*sizeof(int));
        insertionArray = malloc(numOfElements*sizeof(int));
        countingArray = malloc(numOfElements*sizeof(int));
        mergeArray = malloc(numOfElements*sizeof(int));
        quickArray = malloc(numOfElements*sizeof(int));

        compCopyCountBubble = malloc(2*sizeof(int));
        compCopyCountInsertion = malloc(2*sizeof(int));
        compCopyCountCounting = malloc(2*sizeof(int));
        compCopyCountMerge = malloc(2*sizeof(int));
        compCopyCountQuick = malloc(2*sizeof(int));


        //Read the Numbers from File and store in the array
        i=0;
        do{
            numberArray[i]=number;
            bubbleArray[i]=number;
            insertionArray[i]=number;
            countingArray[i]=number;
            mergeArray[i]=number;
            quickArray[i]=number;
            i++;
            //printf("%d\n", number);
            //printf("%d %d %d %d %d\n", bubbleArray[i-1], insertionArray[i-1], countingArray[i-1], mergeArray[i-1], quickArray[i-1]);
        }while( fscanf(file, "%d,", &number) > 0);

        //calling Sort functions
        bubble_sort(bubbleArray,numOfElements, compCopyCountBubble);
        insertionSort(insertionArray, numOfElements, compCopyCountInsertion);
        countSort(countingArray, smallest, largest, numOfElements, compCopyCountCounting);
        mergeSort(mergeArray, 0, numOfElements-1, compCopyCountMerge);
        quickSort(quickArray, 0, numOfElements-1, compCopyCountQuick);


        //Writing comparisons to the second output file
        fprintf(evaluationFile,"Bubble Sort: %d comparisons, %d copies\n", compCopyCountBubble[0], compCopyCountBubble[1]);
        fprintf(evaluationFile,"Insertion Sort: %d comparisons, %d copies\n", compCopyCountInsertion[0], compCopyCountInsertion[1]);
        fprintf(evaluationFile,"Counting Sort: %d comparisons, %d copies\n", compCopyCountCounting[0], compCopyCountCounting[1]);
        fprintf(evaluationFile,"Merge Sort: %d comparisons, %d copies\n", compCopyCountMerge[0], compCopyCountMerge[1]);
        fprintf(evaluationFile,"Quick Sort: %d comparisons, %d copies\n", compCopyCountQuick[0], compCopyCountQuick[1]);


        //Writing sorted array values to the first output file
        for(i=0;i<numOfElements;i++){
            fprintf(outfile, " %d \t", bubbleArray[i]);
            fprintf(outfile, " %d \t", insertionArray[i]);
            fprintf(outfile, " %d \t", countingArray[i]);
            fprintf(outfile, " %d \t", mergeArray[i]);
            fprintf(outfile, " %d\n", quickArray[i]);
        }
        fclose(file);
        fclose(outfile);
        fclose(evaluationFile);

    }
    return 0;
}
