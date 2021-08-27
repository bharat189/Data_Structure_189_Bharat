#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
    int data;          
    struct node *next; 
} Node;

Node *head = NULL;

void lastinsert();
void last_delete();
void display();
void search();

int main()
{
    int choice = 0;
    while (choice != 5)
    {
        printf("\nChoose an option \n");
        printf("\n1.Insert \n2.Delete \n3.Search for an element\n4.Show\n5.Exit\n");
        printf("\nEnter your choice ");
        scanf("\n%d", &choice);
        switch (choice)
        {
        case 1:
            lastinsert();
            break;
        case 2:
            last_delete();
            break;
        case 3:
            search();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Please enter valid choice..");
        }
    }
}

void lastinsert() 
{

    Node *ptr, *temp;
    int element;

    ptr = (Node *)malloc(sizeof(Node));

    if (ptr == NULL)
    {
        printf("\nNode is full");
    }
    else
    {
        printf("\nEnter value --> ");
        scanf("%d", &element);
        ptr->data = element;
        ptr->next = NULL;
        if (head == NULL)
        {
            head = ptr;
            printf("\nNode inserted");
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next; //
            }
            temp->next = ptr;
            printf("\nNode inserted");
        }
    }
}

void last_delete() 
{
    struct node *ptr, *ptr1;
    if (head == NULL)
    {
        printf("\nlist is empty");
    }
    else if (head->next == NULL)
    {
        head = NULL;
        free(head);
        printf("\nOnly node of the list deleted ...\n");
    }

    else
    {
        ptr = head;
        while (ptr->next != NULL)
        {
            ptr1 = ptr;
            ptr = ptr->next;
        }
        ptr1->next = NULL;
        free(ptr);
        printf("\nDeleted Node from the last ...\n");
    }
}

void search() 
{
    Node *ptr;
    int element, i = 0, flag;
    ptr = head;
    if (ptr == NULL)
    {
        printf("\nEmpty List\n");
    }
    else
    {
        printf("\nEnter Element which you want to search?\n");
        scanf("%d", &element);
        while (ptr != NULL)
        {
            if (ptr->data == element)
            {
                printf("Element found at location %d ", i + 1);
                flag = 0;
                break;
            }
            else
            {
                flag = 1;
            }
            i++;
            ptr = ptr->next;
        }
        if (flag == 1)
        {
            printf("Element not found\n");
        }
    }
}

void display() 
{
    Node *ptr;
    ptr = head;
    if (ptr == NULL)
    {
        printf("Nothing is Inserted inside the Node\n");
    }
    else
    {
        printf("\nThe values are --> ");
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
    }
}