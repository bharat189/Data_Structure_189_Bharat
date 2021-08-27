// Author : Bharat Sharma 189
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
} *head = NULL , *ptr , *temp ;
typedef struct node NODE;

int num_element=0;

int enqueue()
{
    ptr=(NODE*)malloc(sizeof(NODE));

    if(ptr==NULL){
        printf("\nRAM FULL!!\n");
    }else{
        printf("\nEnter element to be enqueue : ");
        scanf("%d",&ptr->data);
        
        ptr->next = NULL ;
        
        if(head == NULL){
            head = ptr ;
        }else{
            temp = head;

            while(temp->next != NULL)
            {
                temp = temp->next ;
            }
            temp->next = ptr ;
        }
        printf("\nNode inserted at address : %p\n",ptr);
        num_element++;
    }
}

int dequeue(){
    if(head==NULL)
    {
        printf("Nothing to dequeue.\n");
        num_element=0;
    }else{
        
        if(head->next == NULL){
            head = NULL;
            free(head);
        }else{
            temp = head;
            head = head->next;
            free(temp);
        }
        num_element--;
        printf("\nNode deleated.\n");
    }
}

int search(){
    int element , x=1;
    ptr = head;
    if(ptr== NULL) 
    {
        printf("\nNothing to search.\n");
    }  
    else
    {   
        printf("Enter element to search : ");
        scanf("%d",&element);   
        while (ptr != NULL)
        {    
            if(ptr->data == element){
                printf("\n-->Element %d present at %p .\n", element, ptr);
                x=0;
            }
            ptr = ptr->next;    
        }
        if(x != 0){
            printf("\n-->Element %d not found \n\n",element);
        }
    } 
}

int display(){
    ptr = head;   
    if(ptr== NULL)  
    {  
        printf("\nNothing to print\n");  
    }  
    else  
    {  
        printf("\nElements present :\n");   
        
        while (ptr != NULL)
        {  
            printf("-->%d at address %p\n", ptr->data, ptr);  
            ptr = ptr->next;  
        }
    printf("\n-->Number of node present : %d.\n",num_element);
    } 
}

int main(){
    int ch;
    do{
        printf("\nEnter\n   1.To enqueue \n   2.To dequeue\n   3.To search\n   4.To display\n   5.To Exit\n\n");    
        scanf("%d",&ch);
        
        switch(ch){
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                search();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("\nProcess ended.\n");
                break;

            default:
                printf("\n!!ERROR!!\n");
        }
    }while (ch != 5);
}