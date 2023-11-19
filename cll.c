#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head;
int count=0;
void insert_begin(){
    int value;
    printf("Enter value:\n");
    scanf("%d",&value);
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    //for checking memory allocation
    if (temp == NULL)
        printf("memory insufficient:\n");
    else{

        temp->data = value;
        if(head == NULL){//IF NO NODES IN LL
            temp->next = temp;
        }else{
            temp->next = head;
            struct node *p = head;
            while(p->next != head)
                p=p->next;
            p->next = temp;
        }
    }
    head = temp;
    count++;
}
void display(){
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p = head;
    if(head == NULL){
        printf("List is empty\n");
    }else{
        if(count >1){
            printf("head -> ");
            while(p->next != head){
                printf("%d -> ",p->data);
                p = p->next;
            }
            printf("%d -> Head\n",p->data);
        }else if(count==1){
            printf("head %d -> Head\n",p->data);
        }
    }
}
void insert_end(){
    int value;
    printf("Enter value:\n");
    scanf("%d",&value);
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    //for checking memory allocation
    if (temp == NULL)
        printf("memory insufficient:\n");
    else{
        temp->data = value;
        //temp->next = NULL;
        if(head == NULL){
            head = temp;
            head->next = head;
        }
        else{
            struct node *p = head;
            while(p->next != head){
                p=p->next;
            }
            p->next = temp;
            temp->next = head;

        }
        count++;
    }
}

void insert_at_part(){
    int value,pos,i;
    printf("Enter Position:\n");
    scanf("%d",&pos);
    if(pos<=count+1 && pos>0){
        struct node *temp;
        temp = (struct node *)malloc(sizeof(struct node));
        if (temp == NULL)
            printf("memory insufficient:\n");
        else{
            if(pos == 1)
                insert_begin();
            else if(pos == count+1)
                insert_end();
            else{
                printf("Enter value:\n");
                scanf("%d",&value);
                temp->data = value;
                temp->next = NULL;
                struct node *p = head;
                for(i=1;i<=pos-2;i++)
                    p=p->next;
                temp->next = p->next;
                p->next=temp;
                count++;
            }
        }
    }
}

void delete_begin(){
    if(head==NULL)
        printf("List is empty\n");
    else{
        struct node* q = head;
        struct node *p = head;
        while(p->next != head)
            p=p->next;
        p->next = head->next;
        head=head->next;
        free(q);
        count--;
    }
}

void delete_end(){
    if(head==NULL)
        printf("List is empty\n");
    else{
        struct node *p = head;

        while(p->next->next != head)
            p=p->next;
        struct node *q = p->next;
        p->next = head;
        free(q);
        count--;
    }
}
void delete_at_part(){
    int pos,i;
    printf("Enter position\n");
    scanf("%d",&pos);
    if(pos>0 && pos<=count){
        if(pos == 1)
            delete_begin();
        else if(pos == count)
            delete_end();
        else{
            struct node *p = head;
            for(i=1;i<=pos-2;i++)
                p=p->next;
            struct node *q;
            q = p->next;
            p->next = q->next;
            free(q);
            count--;
        }
    }
}
void search(){
    int x,i,found=0;
    printf("enter value to search:\n");
    scanf("%d",&x);
    struct node *p=head;
    i=1;
    while(p->next !=head){
        if(p->data == x){
            found++;
            break;
        }
        i++;
        p = p->next;
    }
    if(p->data == x){
        found++;
    }
    if(found != 0){
        printf("found at %d\n",i);
    }
    else{
        printf("not found\n");
    }
}

void remove_dup(){
    if(head == NULL || head->next == head)
    return;
    struct node* current = head->next;
    do {
        struct node* runner = current;
        do {
            if (runner->next->data == current->data) {
                struct node* temp = runner->next;
                runner->next = temp->next;
                if (temp == head)
                    head = runner;
                free(temp);
            }else
                runner = runner->next;
        } while (runner->next != current);
        current = current->next;
    } while (current != head);


}

int main(){
    int choice;
    while(1){
        printf("Insertion choice:(1.insert, 4.End ,5.position)\n");
        printf("Deletion choice: 6.Begin 7.End 8.position \n");
        printf("2.display 9.Search ,3.Size of List, default exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: insert_begin();
                break;
            case 2: display();
                break;
            case 3: printf("no of node: %d\n",count);
                break;

            case 4: insert_end();
                break;
            case 5: insert_at_part();
                break;
            case 6: delete_begin();
            break;
            case 7: delete_end();
            break;
            case 8: delete_at_part();
            break;
            case 9: search();
            break;
            case 10: remove_dup();
            break;
            default: exit(0);
        }
    }
}
