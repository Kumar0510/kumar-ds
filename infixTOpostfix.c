#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Function to return precedence of operators
int precedence(char operator)
{
	switch (operator) {
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	case '^':
		return 3;
	default://FOR NO OPERATOR
		return -1;
	}
}

// Function to check if the scanned character
// is an operator
int isOperator(char ch)
{
	return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

char* infixToPostfix(char* infix)
{
	int i, j;
	int len = strlen(infix);
	char* postfix = (char*)malloc(sizeof(char) * (len + 2));
	char stack[MAX];//OPERATOR STACK
	int top = -1;

	for (i = 0, j = 0; i < len; i++) {
		if (infix[i] == ' ' || infix[i] == '\t')
			continue;

		// If the scanned character is operand
		// add it to the postfix expression
		if (isalnum(infix[i])) {//checks for alphanumeric or not
			postfix[j++] = infix[i];
		}
		// if the scanned character is '('
		// push it in the stack
		else if (infix[i] == '(') {
			stack[++top] = infix[i];
		}

		// if the scanned character is ')'
		// pop the stack and add it to the
		// output string until empty or '(' found
		else if (infix[i] == ')') {
			while (top > -1 && stack[top] != '(')
				postfix[j++] = stack[top--];
			if (top > -1 && stack[top] != '(') //the stack is not empty and the top is not opening bracket its invalid
				return "Invalid Expression";
			else
				top--;
		}

		// If the scanned character is an operator
		// push it in the stack
		else if (isOperator(infix[i])) {
			while (top > -1 && (precedence(stack[top]) >= precedence(infix[i])))
				postfix[j++] = stack[top--];//pop until top prec is less than infix oper
			stack[++top] = infix[i];
		}
	}//end of for loop

	// Pop all remaining elements from the stack
	while (top > -1) {
		if (stack[top] == '(') { //the remaining elements in stack the bracket is not closed
			return "Invalid Expression";
		}
		postfix[j++] = stack[top--];
	}
	postfix[j] = '\0';
	return postfix;
}

// Driver code
int main()
{
	char infix[MAX];
	printf("Enter infix: \n");
	scanf("%s",infix);
	// Function call
	char* postfix = infixToPostfix(infix);
	printf("%s\n", postfix);
	free(postfix);
	return 0;
}
