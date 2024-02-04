#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int prn;
    char name[50];
    struct node *next;
} node;

void Create(node *head) {
    int num, ch; 
    node *temp, *curr;
    temp = head;
    do {
        curr = (node*)malloc(sizeof(node));
        printf("\nEnter PRN:");
        scanf("%d", &curr->prn);
        printf("Enter Name:");
        scanf("%s", curr->name);
        curr->next = NULL;
        temp->next = curr;
        temp = curr;      
        printf("Do you want to add more members? (1/0): ");
        scanf("%d", &ch);
    } while(ch != 0);
}

int len(node *head) {
    int i = 0;
    node *curr;
    curr = head->next;
    while(curr != NULL) {
        i++;
        curr = curr->next;
    }
    return i;
}

void InsertPos(node* head) {
    int i = 1, pos;
    node *curr, *nnode;
    curr = head;
    nnode = (node*)malloc(sizeof(node));
    printf("\nEnter PRN:");
    scanf("%d", &nnode->prn);
    printf("Enter Name:");
    scanf("%s", nnode->name);
    printf("\nEnter position to insert data:");
    scanf("%d", &pos);
      
    int k = len(head);
    if(pos > k + 1) {
        printf("Data can't be inserted\n");
    } else {
        while(curr != NULL && i < pos) {
            i++;
            curr = curr->next;
        }
        nnode->next = curr->next;
        curr->next = nnode;
    } 
}

void DeletePos(node* head) {
    node *temp, *curr, *prev;
    int pos, i = 1;
    prev = head;
    curr = head->next;
    printf("\nEnter position to delete data:");
    scanf("%d", &pos);
    int k = len(head);
    if (pos > k || pos <= 0) {
        printf("Invalid position. Data can't be deleted\n");
    } else {
        while (i < pos && curr != NULL) {
            prev = curr;
            curr = curr->next;
            i++;
        }
        if (curr != NULL) {
            temp = curr;
            prev->next = curr->next;
            free(temp);
        } else {
            printf("Invalid position. Data can't be deleted\n");
        }
    }
}



void Display(node* head) {
    node* temp;
    temp = head->next;
    printf("\n\nClub Members:\n");
    while(temp != NULL) {
        printf("PRN: %d, Name: %s\n", temp->prn, temp->name);
        temp = temp->next;
    }
}

void Sort(node *head) {
    int i, j;
    node *temp, *curr, *prev;

    int len_list = len(head);
    for(i = 1; i < len_list - 1; i++) {
        prev = head;
        curr = head->next;  
        for(j = 0; j < len_list - i; j++) {        
            temp = curr->next;
            if(curr->prn > temp->prn) {
                prev->next = temp;
                curr->next = temp->next;
                temp->next = curr;
                prev = temp;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }   
    }
}

void Merge(node *head1, node *head2) {
    node *head3, *curr1, *curr2, *temp;
    curr1 = head1;
    curr2 = head2;
    if(curr1->prn <= curr2->prn) {
        temp = head1;
        curr1 = curr1->next;
    } else {
        temp = head2;
        curr2 = curr2->next;
    }
    head3 = temp;
    while(curr1 && curr2) {
        if(curr1->prn <= curr2->prn) {
            temp->next = curr1;
            temp = curr1;
            curr1 = curr1->next;
        } else {
            temp->next = curr2;
            temp = curr2;
            curr2 = curr2->next;
        }
    }
    if(curr1 == NULL) {
        temp->next = curr2;
    }
    if(curr2 == NULL) {
        temp->next = curr1;
    }
    printf("\nAfter Merge: ");
    Display(head3);
}

void Reverse(node *head) {
    node *prev, *curr, *future;
    prev = NULL;
    curr = head->next;
    while(curr != NULL) {
        future = curr->next;
        curr->next = prev;
        prev = curr;
        curr = future;
    }
    head->next = prev;
}

int main() {
    node *head, *head2;
    head = (node*)malloc(sizeof(node));
    head->next = NULL;
    head2 = (node*)malloc(sizeof(node));
    head2->next = NULL;
    int n; 
    char ch;
    do {
        printf("\nChoose an option: \n1.Create \n2.Insert \n3.Delete \n4.Display \n5.Sort \n6.Merge \n7.Reverse \nEnter your choice: ");
        scanf("%d", &n);
        switch(n) {
            case 1: Create(head);
                    break;
            case 2: InsertPos(head);
                    break;
            case 3: DeletePos(head);
                    break;
            case 4: Display(head);
                    break;
            case 5: Sort(head);
                    printf("\nAfter Sorting: ");
                    Display(head);
                    break;
            case 6: printf("\nEnter a new list(of 5 elements): ");
                    Create(head2);
                    printf("\nSecond List: ");
                    Display(head2);
                    Merge(head, head2);
                    break;
            case 7: Reverse(head);
                    printf("\nAfter Reversing: ");
                    Display(head);
                    break;
            default: printf("\nInvalid Choice!");
        }
        printf("\nDo you want to continue? (y/n): ");
        scanf(" %c", &ch);
    } while(ch == 'y' || ch == 'Y');
    return 0;
}
