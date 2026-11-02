#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fileutil.h"

// DIRECTIONS
// Choose whether you are doing the 2D array or
// the array of arrays.
// For the 2D array,
//		implement loadFile2D, substringSearch2D, and free2D.
// For the array of arrays,
// 		implement loadFileAA, substringSearchAA, and freeAA.

//Array-of-arrays
char ** loadFileAA(char *filename, int *size)
{
    (void)filename;
    *size = 0;
    return NULL;
}

//Put every line into a 2D character array
char (*loadFile2D(char *filename, int *size))[COLS]
{
    FILE *in = fopen(filename, "r");
    if (in == NULL)
    {
        perror("Can't open file");
        exit(EXIT_FAILURE);
    }

    int capacity = 10;
    int count = 0;

    //Allocate initial 10 rows
    char (*arr)[COLS] = malloc(capacity * sizeof(*arr));
    if (arr == NULL)
    {
        perror("malloc failed");
        fclose(in);
        exit(EXIT_FAILURE);
    }

    char buffer[COLS];
    while (fgets(buffer, sizeof(buffer), in) != NULL)
    {
        //Removes the newline
        size_t length = strlen(buffer);
        if (length > 0 && buffer[length - 1] == '\n')
        {
            buffer[--length] = '\0';
        }
        else if (!feof(in))
        {
            
            int ch;
            while ((ch = fgetc(in)) != '\n' && ch != EOF)
            {
            }
        }
        if (length > 0 && buffer[length - 1] == '\r')
        {
            buffer[length - 1] = '\0';
        }

        //Double row capacity when the array is full
        if (count == capacity)
        {
            int newCapacity = capacity * 2;
            char (*larger)[COLS] = realloc(arr, newCapacity * sizeof(*arr));
            if (larger == NULL)
            {
                perror("realloc failed");
                free(arr);
                fclose(in);
                exit(EXIT_FAILURE);
            }
            arr = larger;
            capacity = newCapacity;
        }

        strcpy(arr[count], buffer);
        count++;
    }

    fclose(in);
    *size = count;
    return arr;
}

//Array-of-arrays version
char * substringSearchAA(char *target, char **lines, int size)
{
    (void)target;
    (void)lines;
    (void)size;
    return NULL;
}

// Search the array for the target string.
// Return the found string or NULL if not found.
char * substringSearch2D(char *target, char (*lines)[COLS], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (strstr(lines[i], target) != NULL)
        {
            return lines[i];
        }
    }
    return NULL;
}

// Free the memory used by the array
void freeAA(char **arr, int size)
{
    (void)arr;
    (void)size;
}

void free2D(char (*arr)[COLS])
{
    free(arr);
}
