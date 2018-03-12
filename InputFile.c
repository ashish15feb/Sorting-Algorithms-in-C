//Project1

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

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
        printf("First Line is: %d, %d and %d\nNumber is: %d\n",firstLine[0],firstLine[1],firstLine[2], number );
        //Create and array of size "n"
        int* numberArray;
        //Store Smallest and largest number
        int smallest = firstLine[1], largest = firstLine[2];
        numberArray = malloc(firstLine[0]*sizeof(int));
        //Read the Numbers from File and store in the array
        i=0;
        numberArray[i++]=number;
        while( fscanf(file, "%d,", &number) > 0){
            numberArray[i]=number;
            printf("%d\n",numberArray[i]);
            i++;
        }
    }
    return 0;
}
