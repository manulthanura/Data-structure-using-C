/* A simple Tree (dynamic) implementation
Date created: Friday; April 01, 2022 


Content

    01. Header files

        1.1 stdio.h

        1.2 stdlib.h

    02. Data structure

    03. Functions

    04. main


*/

// 01. Header files
#include <stdio.h>
#include <stdlib.h>

// 02. Data structure
struct node {
	int data;
	struct node *left, *right;
};

// A utility function to create a new BST node
struct node* newNode(int item)
{
	struct node* temp
		= (struct node*)malloc(sizeof(struct node));
	temp->data = item;
	temp->left = temp->right = NULL;
	return temp;
}

// 03. Functions
// A utility function to do in-order traversal of BST
void inorder(struct node* root)
{
	if (root != NULL) {
		inorder(root->left);
		printf("%d -> ", root->data);
		inorder(root->right);
	}
}

// A utility function to do pre-order traversal of BST
void preorder(struct node* root)
{
	if (root != NULL) {
		printf("%d -> ", root->data);
		inorder(root->left);
		inorder(root->right);
	}
}

// A utility function to do post-order traversal of BST
void postorder(struct node* root)
{
	if (root != NULL) {
		inorder(root->left);
		inorder(root->right);
		printf("%d -> ", root->data);
	}
}

/* A utility function to insert a new node with given data in all BST */
struct node* insert(struct node* node, int data)
{
	/* If the tree is empty, return a new node */
	if (node == NULL)
		return newNode(data);

	/* Otherwise, recur down the tree */
	if (data < node->data)
		node->left = insert(node->left, data);
	else if (data > node->data)
		node->right = insert(node->right, data);

	/* return the (unchanged) node pointer */
	return node;
}

// 04. main
int main()
{
	struct node* root = NULL;
	root = insert(root, 0);
	insert(root, 9);
	insert(root, -8);
	insert(root, 14);
	insert(root, 2);
	insert(root, -11);

	// print in-oder traversal of the BST
	printf(" In-oder traversal of the BST\n");
	printf(" Start -> ");
	inorder(root);
	printf(" End\n");
	// print pre-oder traversal of the BST
	printf("\n Pre-oder traversal of the BST\n");
	printf(" Start -> ");
	preorder(root);
	printf(" End\n");
	// print post-oder traversal of the BST
	printf("\n Post-oder traversal of the BST\n");
	printf(" Start -> ");
	postorder(root);
	printf(" End");
	return 0;
}
