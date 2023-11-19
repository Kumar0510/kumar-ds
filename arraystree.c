#include<stdio.h>
#include<limits.h>
int complete_node = 15;
int MAX = INT_MIN,MIN = INT_MAX;
char tree[15]="1234567\0\0\0\0\0\089" ;

int get_right_child(int index){
    if(tree[index]!='\0' && ((2*index)+2)<complete_node)
        return (2*index)+2;
    return -1;
}
int get_left_child(int index){
    if(tree[index]!='\0' && (2*index)+1<complete_node)
        return (2*index)+1;
    return -1;
}
void preorder(int index){
    if(index>=0 && tree[index]!='\0'){
        printf(" %c ",tree[index]);
        preorder(get_left_child(index));
        preorder(get_right_child(index));
    }
}
void postorder(int index){
    if(index>=0 && tree[index]!='\0'){
        postorder(get_left_child(index));
        postorder(get_right_child(index));
        printf(" %c ",tree[index]);
    }
}
void inorder(int index){
    if(index>=0 && tree[index]!='\0'){
        inorder(get_left_child(index));
        printf(" %c ",tree[index]);
        inorder(get_right_child(index));
    }
}
void levelorder(){
    int j;
    for(j=0;j<complete_node;j++){
        if(tree[j]!='\0' )
            printf(" %c ",tree[j]);
    }
}
void printleafs(){
    int j;
    for(j=0;j<complete_node;j++){
        if(is_leaf(j) && tree[j] != '\0')
            printf(" %c ",tree[j]);
    }
}
int is_leaf(int index){
    if(!get_left_child(index) && !get_right_child(index))
        return 1;
    if(tree[get_left_child(index)]=='\0' && tree[get_right_child(index)]=='\0')
        return 1;
    return 0;
}
int get_max(int a, int b){
    return (a>b) ? a : b;
}
int get_height(int index){
    if(tree[index]=='\0' || index<0 || is_leaf(index))
        return 0;
    return(get_max(get_height(get_left_child(index)), get_height(get_right_child(index)))+1);
}
void maxe(int index){
    int present = tree[index] - '0';
    if(index>=0 && tree[index]!='\0'){
        if(present > MAX) MAX = present;
        maxe(get_left_child(index));
        maxe(get_right_child(index));
    }
}
void mine(int index){
    int present = tree[index] - '0';
    if(index>=0 && tree[index]!='\0'){
        if(present < MIN) MIN = present;
        mine(get_left_child(index));
        mine(get_right_child(index));
    }
}
int Search(int val){
    int j,f=0;
    for(j=0;j<complete_node;j++){
        int v = tree[j] - '0';
        if(v == val )
            f = 1;
    }
    if(f==0)  printf("\nnot found");
    else printf("\nFound");
    return 0;
}
int main(){
    int choice,s;;
    while(1){
        printf("\n1.preorder 2.postorder 3.inorder\n");
        printf("5.leafs 6.height 7.min 8.max\n");
        printf("4.levelorder 9.search\n");
        printf("Enter your choice:\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:printf("\nPreorder:\n");
                    preorder(0);break;
            case 2:printf("\nPostorder:\n");
                    postorder(0);break;
            case 3:printf("\nInorder:\n");
                    inorder(0);
                    break;
            case 4:printf("\nLevelorder:\n");
                    levelorder();break;
            case 5:printf("\nLeafs:\n");
                    printleafs();break;
            case 6:printf("\nheight of the tree is:%d\n",get_height(0)+1);
                    break;
            case 7:mine(0);printf("\nthe min of tree: %d",MIN);
                    break;
            case 8:maxe(0);
                    printf("\nthe max of tree: %d",MAX);break;
            case 9:printf("Enter search element: \n");
                    scanf("%d",&s);
                Search(s);break;
            default: exit(0);
        }
    }
}
