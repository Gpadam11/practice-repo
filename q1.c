
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link_460;
    struct node *head_460;
};

void linkedlistTraversal(struct node *temp_460)
{
    if (temp_460 == NULL)
    {
        printf("\nThe linked list is empty\n");
    }
    else
    {
        while (temp_460 != NULL)
        {
            printf("Elements: %d\n", temp_460->info);
            temp_460 = temp_460->link_460;
        }
    }
}

struct node *insertAtFirst(struct node *head_460, struct node *newnode_460)
{
    if (head_460 == NULL)
    {
        newnode_460->link_460 = NULL;
        head_460 = newnode_460;
    }
    else
    {
        newnode_460->link_460 = head_460;
        head_460 = newnode_460;
    }
    return head_460;
}

struct node *insertAtEnd(struct node *head_460, struct node *newnode_460)
{
    newnode_460->link_460 = NULL;
    struct node *temp_460 = head_460;
    if (head_460 == NULL)
    {
        head_460 = newnode_460;
    }
    else
    {
        for (temp_460 = head_460; temp_460->link_460 != NULL; temp_460 = temp_460->link_460)
            ;
        temp_460->link_460 = newnode_460;
    }
    return head_460;
}

struct node *insertAtPos(struct node *head_460, struct node *newnode_460, int pos_460)
{
    int i_460;
    if (pos_460 == 1)
    {
        newnode_460->link_460 = head_460;
        head_460 = newnode_460;
    }
    else
    {
        struct node *temp_460 = head_460;
        for (i_460 = 1; i_460 < pos_460 - 1; i_460++)
        {
            temp_460 = temp_460->link_460;
        }
        newnode_460->link_460 = temp_460->link_460;
        temp_460->link_460 = newnode_460;
    }
    return head_460;
}

struct node *deletetAtFirst(struct node *head_460)
{
    if (head_460 == NULL)
    {
        printf("The linked list is empty\n");
    }
    else
    {
        struct node *temp_460 = head_460;
        head_460 = head_460->link_460;
        free(temp_460);
    }
    return head_460;
}

struct node *deletetAtEnd(struct node *head_460)
{
    if (head_460 == NULL)
    {
        printf("The linked list is empty\n");
    }
    else if (head_460->link_460 == NULL)
    {
        free(head_460);
        head_460 = NULL;
    }
    else
    {
        struct node *temp_460 = head_460;
        /* while (temp_460->link_460->link_460 != NULL)
         {
             temp_460 = temp_460->link_460;
         }*/

        for (temp_460 = head_460; temp_460->link_460->link_460 != NULL; temp_460 = temp_460->link_460)
            ;

        temp_460->link_460 = NULL;
        free(temp_460->link_460);
    }
    return head_460;
}

struct node *deleteAtPos(struct node *head_460, int pos_460)
{
    if (pos_460 == 1)
    {
        struct node *temp_460 = head_460;
        head_460 = head_460->link_460;
        free(temp_460);
    }
    else
    {
        struct node *temp_460 = head_460;
        int i_460;
        for (i_460 = 1; i_460 < pos_460 - 1; i_460++)
        {
            temp_460 = temp_460->link_460;
        }
        struct node *temp2_460 = temp_460->link_460;
        temp_460->link_460 = temp2_460->link_460;
        free(temp2_460);
    }
    return head_460;
}

struct node *deletekey(struct node *head_460, int key_460)
{
    if (head_460 == NULL)
    {
        printf("The linked list is empty\n");
    }
    else if (head_460->info == key_460)
    {
        struct node *temp_460 = head_460;
        head_460 = head_460->link_460;
        free(temp_460);
    }
    else
    {
        struct node *temp_460 = head_460;

        for (temp_460 = head_460; temp_460->link_460->info != key_460; temp_460 = temp_460->link_460)
            ;

        if (temp_460->link_460 == NULL)
        {
            printf("The key is not found\n");
        }
        else
        {
            struct node *temp2_460 = temp_460->link_460;
            temp_460->link_460 = temp2_460->link_460;
            free(temp2_460);
        }
    }
    return head_460;
}

void countNodes(struct node *head_460)
{
    struct node *temp_460=head_460;
    int count_460=0;
  while(temp_460!=NULL)
  {
    count_460++;
    temp_460=temp_460->link_460;
    
     }
     printf("no of nodes=%d", count_460);
}

void search(struct node *temp_460, int key_460)
{
    int flag_460 = 0;
    if (temp_460==NULL)                                                                                                                                                 
    {
        printf("\nThe linked list is empty\n");
    }
    else
    {
        while (temp_460 != NULL)
        {
            if (temp_460->info == key_460)
            {
                flag_460 = 1;
                break;
            }
            temp_460 = temp_460->link_460;
        }
        if (flag_460 == 1)
        {
            printf("\nElement found\n");
        }
        else
        {
            printf("\nElement not found\n");
        }
    }
}

int main(void)
{

    struct node *head_460 = NULL;
    
     // CREATING n NUMBER OF NODES

    struct node *M_460 = NULL;
    struct node *N_460 = NULL;
    int num_nodes_460, i_460;
    printf("Enter the no. of nodes you want to create");
    scanf("%d", &num_nodes_460);
    for (i_460 = 0; i_460 < num_nodes_460; i_460++)
    {
        if (head_460 == NULL) 
        {
            N_460 = (struct node *)malloc(sizeof(struct node));
            printf("\n List is empty");
            printf("\n Enter the value to be kept at 1st node");
            scanf("%d", &N_460->info);
            N_460->link_460 = NULL;
            head_460 = N_460;
        }
        else
        {
            M_460 = (struct node *)malloc(sizeof(struct node));
            printf("\n Enter the value to be kept in %d node", i_460 + 1);
            scanf("%d", &M_460->info);
            M_460->link_460 = NULL;
            N_460->link_460 = M_460;
            N_460 = M_460;
        }
    }

    int choice;
    do
    {

        printf("\nEnter-\n");
        printf("1.Linked list before Insersion\n2.Insert a node at beginning\n3.Insert a node at end\n4.Insert a node at any position\n5.Delete a node at beginning\n6.Delete a node at end\n7.Delete a node at any position\n8.Delete a node for a given key\n9.Count the total no. of nodes\n10. Search for an element in the linked list\n11.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            linkedlistTraversal(head_460);
            break;
        }

        case 2:
        {
            struct node *newnode_460;
            printf("\nEnter the new node info:");
            newnode_460 = (struct node *)malloc(sizeof(struct node));
            scanf("%d", &newnode_460->info);
            head_460 = insertAtFirst(head_460, newnode_460);
            linkedlistTraversal(head_460);
            break;
        }

        case 3:
        {
            struct node *newnode_460;
            printf("\nEnter the new node info:");
            newnode_460 = (struct node *)malloc(sizeof(struct node));
            scanf("%d", &newnode_460->info);
            head_460 = insertAtEnd(head_460, newnode_460);
            linkedlistTraversal(head_460);
            break;
        }

        case 4:
        {
            struct node *newnode_460;
            int pos_460;
            printf("\nEnter position at which node is to be added:");
            scanf("%d", &pos_460);
            printf("\nEnter the new node info:");
            newnode_460 = (struct node *)malloc(sizeof(struct node));
            scanf("%d", &newnode_460->info);
            head_460 = insertAtPos(head_460, newnode_460, pos_460);
            linkedlistTraversal(head_460);
            break;
        }

        case 5:
        {
            head_460 = deletetAtFirst(head_460);
            linkedlistTraversal(head_460);
            break;
        }
        case 6:
        {
            head_460 = deletetAtEnd(head_460);
            linkedlistTraversal(head_460);
            break;
        }

        case 7:
        {
            int pos_460;
            printf("\nEnter position at which node is to be deleted:");
            scanf("%d", &pos_460);
            head_460 = deleteAtPos(head_460, pos_460);
            linkedlistTraversal(head_460);
            break;
        }

        case 8:
        {
            int key_460;
            printf("\nEnter the key to be deleted:");
            scanf("%d", &key_460);
            head_460 = deletekey(head_460, key_460);
            linkedlistTraversal(head_460);

            break;
        }
        case 9:
        {
            countNodes(head_460);
            break;
        }

        case 10:
        {
            int key_460;
            printf("\nEnter the element you want to search:");
            scanf("%d", &key_460);
            search(head_460, key_460);
            break;
        }
        case 11:
        {
            printf("\nExiting the program\n");
            break;
        }

        default:
            printf("\nInvalid choice\n");
        }
    } while (choice >= 1 && choice <= 10);
}