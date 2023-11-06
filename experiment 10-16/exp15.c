#include <stdio.h>
#include <stdlib.h>

// Binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Pre-order traversal: Root, Left, Right
void preOrder(struct Node* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);  // Print the data of the current node
    preOrder(root->left);       // Traverse the left subtree
    preOrder(root->right);      // Traverse the right subtree
}

// In-order traversal: Left, Root, Right
void inOrder(struct Node* root) {
    if (root == NULL)
        return;

    inOrder(root->left);        // Traverse the left subtree
    printf("%d ", root->data);  // Print the data of the current node
    inOrder(root->right);       // Traverse the right subtree
}

// Post-order traversal: Left, Right, Root
void postOrder(struct Node* root) {
    if (root == NULL)
        return;

    postOrder(root->left);      // Traverse the left subtree
    postOrder(root->right);     // Traverse the right subtree
    printf("%d ", root->data);  // Print the data of the current node
}

void main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->left->right->left = createNode(6);
    root->right->left = createNode(7);
    root->right->right = createNode(8);

    printf("Pre-order traversal: ");
    preOrder(root);
    printf("\n");

    printf("In-order traversal: ");
    inOrder(root);
    printf("\n");

    printf("Post-order traversal: ");
    postOrder(root);
    printf("\n");
}
