// implement binary tree using linked list
// insertion using level order
#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
#include <stdbool.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root = NULL;
struct node *createNode(int data){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
struct queue{
    int front, rear, size;
    struct node* *arr;
};
struct queue* createQueue(){
    struct queue* newQueue = (struct queue*) malloc(sizeof( struct queue ));
    newQueue->front = -1;
    newQueue->rear = 0;
    newQueue->size = 0;
    newQueue->arr = (struct node**) malloc(100 * sizeof( struct node* ));
    return newQueue;
}
void enqueue(struct queue* queue, struct node *temp){
    queue->arr[queue->rear++] = temp;
    queue->size++;
}
struct node *dequeue(struct queue* queue){
    queue->size--;
    return queue->arr[++queue->front];
}
void insertNode(int data) {
    struct node *newNode = createNode(data);
    if(root == NULL){
        root = newNode;
        return;
    }
    else {
        struct queue* queue = createQueue();
        enqueue(queue, root);
        while(true) {
            struct node *node = dequeue(queue);
            if(node->left != NULL && node->right != NULL) {
                enqueue(queue, node->left);
                enqueue(queue, node->right);
            }
            else {
                if(node->left == NULL)node->left = newNode;
                else node->right = newNode;
                break;
            }
        }
    }
}
void printlevelorder(struct node* r){
    struct queue* queue = createQueue();
    enqueue(queue, r);
    while(queue->size != 0) {
        struct node *node = dequeue(queue);
        printf("%d ",node->data);
        if(node->left != NULL) enqueue(queue, node->left);
        if(node->right != NULL)enqueue(queue, node->right);
    }
}
void leafnodes(struct node* r){
    struct queue* queue = createQueue();
    enqueue(queue, r);
    while(queue->size != 0) {
        struct node *node = dequeue(queue);
        if(node->left == NULL && node->right == NULL) printf("%d ",node->data);
        if(node->left != NULL) enqueue(queue, node->left);
        if(node->right != NULL)enqueue(queue, node->right);
    }
}
void deletetree(struct node *r){
    if(r != NULL){
        deletetree(r->left);
        deletetree(r->right);
        free(r);
    }
}
void inorderTraversal(struct node *node) {
    if(root == NULL){
        printf("Tree is empty\n");
        return;
    }
    else {
        if(node->left != NULL)  inorderTraversal(node->left);
        printf("%d ", node->data);
        if(node->right != NULL)  inorderTraversal(node->right);
    }
}
void preorderTraversal(struct node *node) {
    if(root == NULL){
        printf("Tree is empty\n");
        return;
    }
    else {
        printf("%d ", node->data);
        if(node->left != NULL)  preorderTraversal(node->left);
        if(node->right != NULL) preorderTraversal(node->right);
    }
}
void postorderTraversal(struct node *node) {
    if(root == NULL){
        printf("Tree is empty\n");
        return;
    }
    else {

        if(node->left != NULL)
            postorderTraversal(node->left);
        if(node->right != NULL)
            postorderTraversal(node->right);
        printf("%d ", node->data);

        }
}
int treeheight(struct node *Root){
    int leftheight,rightheight;
    if(Root == NULL) return 0;
    else{
        leftheight = treeheight(Root->left);
        rightheight = treeheight(Root->right);
        if(leftheight > rightheight) return leftheight+1;
        else return rightheight+1;
    }
}
void search(struct node* r,int val){
    int f=0;
    struct queue* queue = createQueue();
    enqueue(queue, r);
    while(queue->size != 0) {
        struct node *node = dequeue(queue);
        if(node->data == val) f++;
        if(node->left != NULL) enqueue(queue, node->left);
        if(node->right != NULL)enqueue(queue, node->right);
    }
    if(f==0) printf("not found\n");
    else printf("Found \n");
}
void Min(struct node* r){
    int min = r->data;
    struct queue* queue = createQueue();
    enqueue(queue, r);
    while(queue->size != 0) {
        struct node *node = dequeue(queue);
        if(node->data < min) min=node->data;
        if(node->left != NULL) enqueue(queue, node->left);
        if(node->right != NULL)enqueue(queue, node->right);
    }
    printf("\nminimum in tree: %d",min);
}
void Max(struct node* r){
    int max= r->data;
    struct queue* queue = createQueue();
    enqueue(queue, r);
    while(queue->size != 0) {
        struct node *node = dequeue(queue);
        if(node->data > max) max=node->data;
        if(node->left != NULL) enqueue(queue, node->left);
        if(node->right != NULL)enqueue(queue, node->right);
    }
    printf("\nmaximum in tree: %d",max);
}

void eachnode(struct node* r){
    int offheight = treeheight(root);
    struct queue* queue = createQueue();
    enqueue(queue, r);
    while(queue->size != 0) {
        struct node *node = dequeue(queue);
        int h = treeheight(node);
        printf("The height of %d is %d\n",node->data,h);
        if(node->left != NULL) enqueue(queue, node->left);
        if(node->right != NULL)enqueue(queue, node->right);
    }
}
void getBreadth(struct node *node, int height, int *breadth) {
    if(root == NULL){
        printf("Tree is empty\n");
        return;
    }
    else {
        if(node == NULL)
            return;

        if(height == 0)
            (*breadth)++;
        else {
            getBreadth(node->left, height - 1, breadth);
            getBreadth(node->right, height - 1, breadth);
        }
    }
}
void breadthOfEachNode(struct node *node) {
    if(root == NULL){
        printf("Tree is empty\n");
        return;
    }
    else {
        int height = treeheight(node);
        printf("\nDepths: \n");
        for (int i = 0; i <= height; i++) {
            int breadth = 0;
            getBreadth(node, i, &breadth);
            if(breadth >= height ) breadth--;
            printf("Node at height %d: %d\n", i, breadth);
        }
    }
}
struct node* deleteNode(struct node* root, int key) {
    if(root == NULL)
        return root;
    if(key < root->data)
        root->left = deleteNode(root->left, key);
    else if(key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if(root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = root->right;
        while(temp && temp->left != NULL)
            temp = temp->left;
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
int main(){
    int choice, value,val,del;
    while(1){
      printf("\n1.Insert 2.Inorder 3.Preorder");
      printf("\n4.Postorder 5.levelorder 6.height ");
      printf("\n7.delete node 8.leafs 9.Search ");
      printf("\n10.min 11.max");
      printf("\nEnter your choice: ");
      scanf("%d",&choice);
      switch(choice){
        case 1: printf("\nEnter the value to be insert: ");
            scanf("%d", &value);
            insertNode(value);
            break;
        case 2:printf("\n"); inorderTraversal(root);; break;
        case 3:printf("\n"); preorderTraversal(root); break;
        case 4:printf("\n"); postorderTraversal(root); break;
        case 5:printf("\n"); printlevelorder(root);break;
        case 6:printf("\n Height: %d",treeheight(root)); break;
         case 7:printf("\nENter node to be deleted: ");
         scanf("%d",&del);
             root = deleteNode(root,del); break;
         case 8: printf("\n");leafnodes(root);break;
         case 9:printf("enter val: ");
                scanf("%d",&val);
                search(root,val); break;
        case 10: Min(root); break;
        case 11: Max(root); break;
        case 12: eachnode(root);
        breadthOfEachNode(root);break;
    default: exit(0);
      }
   }
}

