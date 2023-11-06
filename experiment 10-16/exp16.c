#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return search(root->left, key);

    return search(root->right, key);
}

struct Node* findMin(struct Node* root) {
    if (root == NULL)
        return NULL;
    else if (root->left == NULL)
        return root;
    else
        return findMin(root->left);
}

struct Node* findMax(struct Node* root) {
    if (root == NULL)
        return NULL;
    else if (root->right == NULL)
        return root;
    else
        return findMax(root->right);
}

struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void displayMenu() {
    printf("\nBST Operations:");
    printf("\na. Search for an element");
    printf("\nb. Find minimum");
    printf("\nc. Find maximum");
    printf("\nd. Insert an element");
    printf("\ne. Delete an element");
    printf("\nf. Exit");
}

int main() {
    struct Node* root = NULL;
    int data, key, n;
    char choice;
    struct Node* temp;
    printf("Enter no. of elements: ");
    scanf("%d",&n);
    printf("Enter elements to insert: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d", &data);
        root = insert(root, data);
    }
                
    displayMenu();
    do{
        printf("\nEnter your choice: ");
        scanf(" %c", &choice);
        switch (choice) {
            case 'a':
                printf("Enter element to search: ");
                scanf("%d", &key);
                temp = search(root, key);
                if (temp != NULL)
                    printf("Element found in the BST\n");
                else
                    printf("Element not found in the BST\n");
                break;
            case 'b':
                temp = findMin(root);
                if (temp != NULL)
                    printf("Minimum element in the BST: %d\n", temp->data);
                else
                    printf("BST is empty\n");
                break;
            case 'c':
                temp = findMax(root);
                if (temp != NULL)
                    printf("Maximum element in the BST: %d\n", temp->data);
                else
                    printf("BST is empty\n");
                break;
            case 'd':
                printf("Enter element to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                printf("Element inserted into the BST\n");
                break;
            case 'e':
                printf("Enter element to delete: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                printf("Element deleted from the BST\n");
                break;
            case 'f':
                printf("Exiting from the program\n");
                break;
            default:
                printf("Invalid choice, please try again\n");
        }
    } while(choice!='f');

    return 0;
}
