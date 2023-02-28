/* Binary tree Data structure implementation
Date created: Saturday; February 28, 2023 */

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* create_node(int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

struct node* insert_node(struct node* root, int data) {
    if (root == NULL) {
        return create_node(data);
    }
    if (data < root->data) {
        root->left = insert_node(root->left, data);
    } else if (data > root->data) {
        root->right = insert_node(root->right, data);
    }
    return root;
}

struct node* delete_node(struct node* root, int data) {
    if (root == NULL) {
        return root;
    }
    if (data < root->data) {
        root->left = delete_node(root->left, data);
    } else if (data > root->data) {
        root->right = delete_node(root->right, data);
    } else {
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        root->data = temp->data;
        root->right = delete_node(root->right, temp->data);
    }
    return root;
}

struct node* edit_node(struct node* root, int old_data, int new_data) {
    if (root == NULL) {
        return root;
    }
    if (old_data < root->data) {
        root->left = edit_node(root->left, old_data, new_data);
    } else if (old_data > root->data) {
        root->right = edit_node(root->right, old_data, new_data);
    } else {
        root->data = new_data;
    }
    return root;
}

void print_inorder(struct node* root) {
    if (root != NULL) {
        print_inorder(root->left);
        printf("%d ", root->data);
        print_inorder(root->right);
    }
}

int main() {
    struct node* root = NULL;

    root = insert_node(root, 50);
    root = insert_node(root, 30);
    root = insert_node(root, 20);
    root = insert_node(root, 40);
    root = insert_node(root, 70);
    root = insert_node(root, 60);
    root = insert_node(root, 80);

    printf("Inorder traversal of the binary tree: ");
    print_inorder(root);
    printf("\n");

    int old_data, new_data;
    printf("Enter the data value of the node to edit: ");
    scanf("%d", &old_data);
    printf("Enter the new data value for the node: ");
    scanf("%d", &new_data);

    root = edit_node(root, old_data, new_data);

    printf("Inorder traversal of the binary tree after editing a node: ");
    print_inorder(root);
    printf("\n");

    int data_to_delete;
    printf("Enter the data value of the");
    root = delete_node(root, data_to_delete);

    printf("Inorder traversal of the binary tree after deleting a node: ");
    print_inorder(root);
    printf("\n");

    return 0;
}



