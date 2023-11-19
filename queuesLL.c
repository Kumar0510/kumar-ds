#include<stdio.h>
#include<stdlib.h>
int count=0,choice;
struct node{
    int data;
    struct node* next;
};
struct node* f=NULL;
struct node* r=NULL;
int isEmpty(){
    if(r ==NULL && f==NULL) return 1;
    else return 0;
}
void enqueue(){
    int val;
    printf("Enter value: \n");
    scanf("%d",&val);
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    if(temp == NULL) printf("Memory Insufficient!");
    else{
        temp->data = val;
        temp->next =NULL;
        if(f==NULL && r==NULL){
            r=temp;
            f=temp;
        }
        else{
            r->next = temp;
            r = temp;
        }count++;
    }
}
void dequeue(){
    if(r==NULL && f==NULL) printf("Queue is empty\n");
    else if(r==f){//ONLY ONE ELEMNT
        printf("removed: %d\n",r->data);
        struct node* temp = f;
        r=NULL;
        f=NULL;
        free(temp);
        count--;
    }else{
        printf("removed: %d\n",f->data);
        struct node* temp = f;
        f=f->next;
        free(temp);
        count--;
    }
}
void display(){
    if(isEmpty()) printf("Queue is empty\n");
    else{
        struct node* temp=f;
        printf("<- f");
        while(temp->next!=NULL){
            printf(" %d ",temp->data);
            temp=temp->next;
        }
        printf("%d r <-\n",temp->data);
    }
}



void front(){
    if(isEmpty()) printf("Queue is empty\n");
    else printf("Front: %d\n",f->data);
}
void rear(){
    if(isEmpty()) printf("Queue is empty\n");
    else printf("Rear: %d\n",r->data);
}
int main(){
    while(1){
        printf("1.enqueue 2.dequeue 3.display\n");
        printf("4.isEmpty,6.front,7.rear \n");
        printf("8.size,default exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: enqueue();
            break;
            case 2: dequeue();
            break;
            case 3: display();
            break;
            case 4:
                if(isEmpty()) printf("queue is empty\n");
                else printf("Queue is not empty\n");
                break;
            case 6: front();
            break;
            case 7: rear();
            break;
            case 8:
                printf("No of elements: %d\n",count);
                break;
            default: exit(0);
        }
    }
}

