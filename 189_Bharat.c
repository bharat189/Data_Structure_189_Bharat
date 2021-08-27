#include <stdio.h> 
int search(int *a);
int insert(int*arr2);
int delelement(int*arr3);
int main()  
{
    int arr1[50]; //creating an array to fill in array elements
    int ch,b,c; //defining variables
    
    // creating a menu to choose for the user
    printf("\"Select any option from below\"\n");
	printf("1. Search an element from the Array\n");
    printf("2. Insert an element in an Array\n");
    printf("3.Delete an element from the Array\n");
    printf("\nEnter your choice : ");
    scanf("%d",&ch); //using scanf to make user enter characters to be used as logic in the switch() function
    printf("\n----------------------------------------------------------------------------------------------------------\n");
    
    //using switch function to perform the logical operations
    switch(ch)
    {
    	case 1:
    	printf("You choose to Search an element from the Array\n");
		search(arr1);
		break;
		case 2:
		printf("You choose to Insert an element from the Array\n");	
		insert(arr1);
		break;
		case 3:
		printf("You choose to Delete an element from the Array\n");
		delelement(arr1);	
		return 0;	
	}
}
	int search(int a[]) //first function is to be used as a search function
	{
		int size,i,ele,found; //defining variables
		printf("\nEnter the size of the array : ");
		scanf("%d",&size); //determining the size of array to be used to fill elements in array using for loop
		printf("\nEnter %d elements : ",size);
		for(i=0;i<size;i++)
		{
			scanf("%d",&a[i]); //for loop will run until all array blocks are filled
		}
		printf("\nElements of Array are : ");

        //now using for loop to print all the inserted elements in the array

		for(i=0;i<size;i++)
		{
			printf("%d ",a[i]);
		}
		printf("\nEnter the element that you want to search : ");

        //now all we have to do is to use the ele variable to store the value of array element we want to search

		scanf("%d",&ele); //user will enter the value he wants to search
		
        /*using for loop to run through the array elements in order to search*/

		for(i=0;i<size;i++)
		{

			//using if-else and break in the for loop in order to stop the loop if the array element matches the ele variable
			if(a[i]==ele)
			{
				found=1;
				break;		
			}
		}
			if(found==1)
			{
				printf("\n%d is found at %d position in the array",ele,i+1);
			}
			else
			printf("\n%d is not found in the array",ele);	
			return 0;
	}
	
	int insert(int arr2[]) //the second function is the insert function
	{
		int n,s,j; //definiing variables to be used
		printf("\nEnter the size of the Array : ");
		
		scanf("%d",&s); //determining the size of array to be used to fill elements in array using for loop

			for(j=0;j<s;j++)
		{
			scanf("%d",&arr2[j]); //for loop will run until all array blocks are filled
		}
		printf("\nArray before insertion of element : ");
		     
		     //now using for loop to print all the inserted elements in the array	

			for(j=0;j<s;j++)
		{
			printf("%d ",arr2[j]);
		}
		printf("\nEnter the number that you want to insert in the Array at the End : ");
		scanf("%d",&n); //using the variable n to store the value of integer we want to insert
		
		s=s+1; //making array size to increase so that we can add one more element
		
		arr2[s-1]=n; //assigning last position of array with the value we have stored in variable n
		printf("\nArray after insertion of %d is : ",n);
		
        //using for loop to print the new array
		for(j=0;j<s;j++)
		{
			printf("%d ",arr2[j]);
		}
		return 0;
	}
	
	int delelement(int arr3[]) //third function is to delete the element in the array
	{
		int k,len,pos; //defining variables
		printf("Enter the size of the array : ");
		scanf("%d",&len); //determining the size of array we want
		
        //using for loop to insert elements in the array
		for(k=0;k<len;k++)
		{
			scanf("%d",&arr3[k]);
		}
		printf("Array before deletion of elements : ");

		//now using for loop to print all elements of the array
		for(k=0;k<len;k++)
		{
			printf("%d ",arr3[k]);
		}

		printf("\nEnter the index from where you want to delete an element : ");
		scanf("%d",&pos); //entering the index of which element user wants to delete
		
		len=len-1; //redefining the size of array (i.e. decreasing one size due to deletion of element)

		for(k=pos;k<len;k++)
		{
			arr3[k]=arr3[k+1]; //using for loop to assign front values in array to the back values from the position we want to delete element
		}
		//after the finishing the for loop the value of at the index entered is replaced by the element that was before it, so the previous value at that index is deleted.
			printf("\nArray after deletion of element : ");
		//printing the new array using for loop
		for(k=0;k<len;k++)
		{
			printf("%d ",arr3[k]);
		}
		return 0;	
	}


	/*Program by : BHARAT SHARMA*/