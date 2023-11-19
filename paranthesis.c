#include <stdio.h>
#include <stdlib.h>

// Structure of a stack node
struct sNode {
	char data;
	struct sNode* next;
};

// Function to push an item to stack
void push(struct sNode** top_ref, int new_data)
{
	// allocate node
	struct sNode* new_node = (struct sNode*)malloc(sizeof(struct sNode));

	new_node->data = new_data;

	new_node->next = (*top_ref);
	(*top_ref) = new_node;
}

// Function to pop an item from stack-
char pop(struct sNode** top_ref)
{
	char res;
	struct sNode* p;
	if (*top_ref == NULL) {//Underflow
		printf("Stack underflow\n");
		exit(0);
	}
	else {
		p = *top_ref;
		res = p->data;
		*top_ref = p->next;
		free(p);
		return res;
	}
}

// Returns 1 if character1 and character2 are matching left
// and right Brackets
int isMatchingPair(char character1, char character2)
{
	if (character1 == '(' && character2 == ')')
		return 1;
	else if (character1 == '{' && character2 == '}')
		return 1;
	else if (character1 == '[' && character2 == ']')
		return 1;
	else
		return 0;
}

// Return 1 if expression has balanced Brackets
int areBracketsBalanced(char exp[])
{
	int i = 0;

	// Declare an empty character stack
	struct sNode* stack = NULL;

	// Traverse the given expression to check matching
	// brackets
	while (exp[i]) {
		// If the exp[i] is a starting bracket then push
		// it
		if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[')
			push(&stack, exp[i]);

		// If exp[i] is an ending bracket then pop from
		// stack and check if the popped bracket is a
		// matching pair*/
		if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']') {

			// If we see an ending bracket without a pair
			// then return false
			if (stack == NULL)
				return 0;

			// Pop the top element from stack, if it is not
			// a pair bracket of character then there is a
			// mismatch.
			// this happens for expressions like {(})
			else if (isMatchingPair(pop(&stack), exp[i]) == 0)
				return 0;
		}
		i++;
	}
	if (stack == NULL)
		return 1; // balanced
	else
		return 0; // not balanced
}

// Driver code
int main()
{
	char exp[100];
    printf("Enter brackets exp: \n");
    scanf("%s",exp);
	// Function call
	if (areBracketsBalanced(exp))
		printf("Balanced \n");
	else
		printf("Not Balanced \n");
	return 0;
}

