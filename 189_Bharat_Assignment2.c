/* 
Author : Bharat Sharma 189
Assignment 2: 

Write a C program to compare the running times of Bubble Sort and Merge Sort for the following array: 
{1,3,42,2,41,66,66,33,98,0}

Which algorithm is faster and why?
*/

#include <stdio.h>  
#include <stdlib.h>    //Header files
#include <time.h>

clock_t start;
clock_t end;
float function_time;


// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    /* Create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    //Copy the remaining elements of L[]
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    // Copy the remaining elements of R[]
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;
 
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }
}

/* Function to print an array */
void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
 
int merge_sort()
{
    int arr[] = { 1,3,42,2,41,66,66,33,98,0};
    int arr_size = sizeof(arr) / sizeof(arr[0]); // Calculating size of array. 
 
    printf("Given array is \n");
    printArray(arr, arr_size);
 
    start = clock();

    mergeSort(arr, 0, arr_size - 1);

 
    printf("\nSorted array using Merge Sort is : ");
    printArray(arr, arr_size);          //Printing elements of array after sorting.
    
    end = clock();
    function_time = (float)(end - start);   // Calculating runtime
    printf("\nTime for merge sort is: %f milliseconds\n ", function_time);
    return 0;
}


int bubble_sort(){
    
    int arr[] = {1,3,42,2,41,66,66,33,98,0};
    int n = 10, i, j;
                            // 'n' is number of element in array.    
    start = clock();

    for(i = 0; i < n - 1; ++i)
    { 
        int swapped = 0;

        for(j = 0; j < (n - i - 1); ++j)    //Using for loop
            if(arr[j] > arr[j+1]){          
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;

                swapped = 1;
            }
        if(!swapped)
            break;
    }
    

    printf("\nArray after sorting using Bubble Sort: ");
    for(i = 0; i < n; ++i)                  //Printing elements of array after sorting.
        printf("%d ", arr[i]);

    end = clock();
    function_time = (float)(end - start);   // Calculating runtime.
    printf("\nTime for Bubble sort is: %f milliseconds\n ", function_time);
 
    return 0;
}

int main(){
    merge_sort();   // Merge Sort  of the array. 
    bubble_sort();  // Bubble Sort of the array. 
}

/*
    The bubble sort procedure is a more intuitive and easily imaginable approach to visualize sorting
    Merge Sort is a recursive algorithm that is used in most of the servers and applications that require sorting procedures. 
    It is one of the fastest methods to sort a data set and more importantly, it requires minimum time to do so.
*/