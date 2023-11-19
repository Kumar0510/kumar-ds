#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *pn;
    struct node *nn;
};

struct node *head;
int count=0;

void insert_begin(){
    int value;
    printf("Enter value:\n");
    scanf("%d",&value);
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
        printf("memory insufficient:\n");
    else{
        temp->data = value;
        temp->nn = NULL;
        temp->pn = NULL;
        if(head == NULL){
            temp->nn = NULL;
        }else{
            temp->nn = head;
            head->pn = temp;
        }
    }
    head = temp;
    count++;
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
        temp->nn = NULL;
        temp->pn = NULL;
        if(head == NULL)
            head = temp;
        else{
            struct node *p = head;
            while(p->nn != NULL){
                p=p->nn;
            }
            p->nn = temp;
            temp->pn = p;
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
                temp->nn = NULL;
                temp->pn = NULL;
                struct node *p = head;
                for(i=1;i<=pos-2;i++)
                    p=p->nn;
                temp->pn = p;
                temp->nn = p->nn;
                p->nn=temp;
                temp->nn->pn = temp;
                count++;
            }
        }
    }
}
void display(){
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p = head;
    if(head == NULL){
        printf("List is empty\n");
    }else{
        while(p->nn != NULL){
            printf("%d <-> ",p->data);
            p = p->nn;
        }
        printf("%d <-> NULL\n",p->data);
    }
}

void delete_begin(){
    if(head==NULL)
        printf("List is empty\n");
    else{
        struct node *p = head;
        head = head->nn;
        head->pn = NULL;
        free(p);
        count--;
    }
}
void delete_end(){
    if(head==NULL)
        printf("List is empty\n");
    else{
        struct node *p = head;
        while(p->nn != NULL)
            p=p->nn;
        p->pn->nn = NULL;
        free(p);
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
            for(i=1;i<=pos-1;i++)
                p=p->nn;
            p->pn->nn = p->nn;
            p->nn->pn = p->pn;
            free(p);
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
    while(p->nn !=NULL){
        if(p->data == x){
            found++;
            break;
        }
        i++;
        p = p->nn;
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
void reverse(){
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p = head;
    if(head == NULL){
        printf("List is empty\n");
    }else{
        while(p->nn != NULL)
            p = p->nn;
        while(p->pn != NULL){
            printf("%d <-> ",p->data);
            p = p->pn;
        }
        printf("%d <-> NULL\n",p->data);
    }
}


int main(){
    int choice;
    while(1){
        printf("Insertion choice: (1.insert, 4.End ,5.Particular position)\n");
        printf("Deletion choice: 6.Begin 7.End 8.particular position\n");
        printf("2.display 9.Search ,3.Size of List, 10.reverse, default exit\n");
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
            case 10: reverse();
            break;
            default: exit(0);
        }
    }
}
