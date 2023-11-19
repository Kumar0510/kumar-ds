#include<stdio.h>
#include<stdlib.h>

int f=-1,r=-1,size,choice;
int *queue;
int isEmpty(){
    if(f==-1 && r==-1) return 1;
    else return 0;
}
void enqueue(){

    int val;
    printf("Enter value: \n");
    scanf("%d",&val);
    if(isEmpty()){
        queue[++f] = val;
        r++;
    }
    else
        queue[++r] = val;

}
void dequeue(){
    if(f==-1 && r==-1) printf("Queue is empty\n");
    else{
        printf("removed: %d\n",queue[f++]);
    }
}
void display(){
    if(isEmpty()) printf("Queue is empty\n");
    else{
        printf("<- f");
        for(int i=f;i<=r;i++){
            printf(" %d ",queue[i]);
        }
        printf("r <-\n");
    }
}


int isFull(){
    if(r==size-1) return 1;
    else return 0;
}
void front(){
    if(isEmpty()) printf("Queue is empty\n");
    else printf("Front: %d\n",queue[f]);
}
void rear(){
    if(isEmpty()) printf("Queue is empty\n");
    else printf("Rear: %d\n",queue[r]);
}
int main(){
    printf("Enter size of Queue: \n");
    scanf("%d",&size);
    queue = (int*)malloc(size*sizeof(int));

    while(1){
        printf("1.enqueue 2.dequeue 3.display\n");
        printf("4.isEmpty,5.isFull,6.front,7.rear \n");
        printf("8.no of elements,default exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                if(r==size-1){
                    printf("Queue is full\n");
                    continue;
                }else enqueue();
            break;
            case 2: dequeue();
            break;
            case 3: display();
            break;
            case 4:
                if(isEmpty()) printf("queue is empty\n");
                else printf("Queue is not empty\n");
                break;
            case 5:
                if(isFull()) printf("queue is full\n");
                else printf("Queue is not Full\n");
                break;
            case 6: front();
            break;
            case 7: rear();
            break;
            case 8:
                printf("No of elements: %d\n",r-f+1);
                break;
            default: exit(0);
        }
    }
}
