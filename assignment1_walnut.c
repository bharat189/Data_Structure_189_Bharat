/*  Author : Bharat Sharma 189
Assignment : Find the cheapest walnut in Raghunath Bazaar of Jammu.
*/
#include <stdio.h>
#include <stdlib.h>

struct node{
    int price;
    char shop[50];
    struct node *next;
} *head = NULL, *ptr;

typedef struct node NODE;

int num=0;


int values()
{
    ptr=(NODE*)malloc(sizeof(NODE));        

    if(ptr==NULL){
        printf("\n Ram Full ⊗ \n");
    }else{
        printf("\nEnter shop's name: ");
        scanf("%*c%[^\n]",ptr->shop);

        printf("\nEnter price of walnut(per KG): ");
        scanf("%d",&ptr->price);

        if(head == NULL){
            head = ptr ;
            head->next = NULL ;
        }else{
            if(head->price >= ptr->price){ 
                ptr->next = head;
                head = ptr;
            }else{                 
                ptr->next = head->next;
                head->next = ptr;
            }
        }
        num++;
    }
    return 0;
}
int efficient(){
       
    if(head==NULL)  
    {  
        printf("\nNo data present.\n");  
    }  
    else  
    {
        printf("\nPrice efficient shop in Raghunath Bazaar for walnuts  is %s at %d ₹ /KG\n",head->shop,head->price);
    }
    return 0;
}

int disp(){
    ptr = head;   
    if(ptr==NULL)  
    {  
        printf("\nEmpty\n");
    }  
    else  
    {  
        printf("\n Collective data of entered shops\n");   
        
        while (ptr != NULL)
        {  
            printf("Shop name: '%s' Walnut's price: %d ₹ /KG\n", ptr->shop, ptr->price);  
            ptr = ptr->next;
        }
    printf("\n Data of %d shops in Raghunath Bazaar is collected.\n",num);
    } 
    return 0;
}
int main(){
    int ch;
    do{
        printf("\nEnter\n   1.Enter shop details\n   2.Display best price shop \n   3.Display price of walnuts \n   4.Exit\n");    
        scanf("%d",&ch);
        
        switch(ch){
            case 1:
                values();
                break;

            case 2:
                efficient();
                break;

            case 3:
                disp();
                break;

            case 4:
                printf("\nEND.\n");
                break;

            default:
                printf("\nERROR!!\n");
        }
    }while (ch != 4);
}

