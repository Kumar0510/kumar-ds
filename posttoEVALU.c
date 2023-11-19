#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node{
    char data;
    struct node *next;
    };
struct node *top;

void push(char cha){
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = cha;
    if(top==NULL)
        temp->next= NULL;
    else
        temp->next=top;
    top=temp;
}
char pop(){
    char res;
    if(top->next!=NULL)
    {
        struct node *p;
        p=top;
        res=top->data;
        top=top->next;
        free(p);
    }
    else{
        struct node *p;
        p=top;
        res=top->data;
        top=NULL;
        free(p);
    }
    return res;
}

int evaluatePostfix(char* exp)
{
	for (int i = 0; exp[i]!='\0'; ++i) {
		if (isdigit(exp[i]))
			push(exp[i] - '0');
		else {
			int val1 = pop();
			int val2 = pop();
			switch (exp[i]) {
			case '+':
				push(val2 + val1);
				break;
			case '-':
				push(val2 - val1);
				break;
			case '*':
				push(val2 * val1);
				break;
			case '/':
				push(val2 / val1);
				break;
            case '^':
				push(pow(val2,val1));
				break;
			}
		}
	}
	return pop();
}
int main()
{
	char exp[50];
	printf("Enter the postfix:\n");
	scanf("%s",exp);
	printf("postfix evaluation: %d", evaluatePostfix(exp));
	return 0;
}
