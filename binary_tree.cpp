#include <stdio.h>
#include <stdlib.h>

// Define the structure for tree nodes
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Function to create a new node
struct node* createNode(int val) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node in the binary tree
// This example uses level order insertion for demonstration
void insert(struct node** root, int val) {
    struct node* newNode = createNode(val);
    if (*root == NULL) {
        *root = newNode;
        return;
    }

    // Use a queue to insert the node in level order
    struct node** queue = (struct node**)malloc(100 * sizeof(struct node*)); // Simple queue implementation
    int front = 0, rear = 0;

    queue[rear++] = *root;

    while (front < rear) {
        struct node* current = queue[front++];

        if (current->left == NULL) {
            current->left = newNode;
            break;
        } else {
            queue[rear++] = current->left;
        }

        if (current->right == NULL) {
            current->right = newNode;
            break;
        } else {
            queue[rear++] = current->right;
        }
    }

    free(queue); // Free the allocated queue
}

// Function for in-order traversal
void inOrder(struct node* root) {
    if (root == NULL) {
        return;
    }
    inOrder(root->left);
    printf("%d  ", root->data);
    inOrder(root->right);
}

// Function for pre-order traversal
void preOrder(struct node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d  ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

// Function for post-order traversal
void postOrder(struct node* root) {
    if (root == NULL) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf("%d  ", root->data);
}

// Function to free the memory of the binary tree
void freeTree(struct node* root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// Main function to demonstrate the operations
int main() {
    struct node* root = NULL;
    int ch, val;

    printf("Enter\n1 for insert node\n2 for inorder\n3 for preorder\n4 for postorder\n0 for exit\n");
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter value to be inserted: ");
                scanf("%d", &val);
                insert(&root, val);
                printf("INSERTED!\n");
                break;
            case 2:
                printf("In Order Traversal: ");
                inOrder(root);
                printf("\n");
                break;
            case 3:
                printf("Pre Order Traversal: ");
                preOrder(root);
                printf("\n");
                break;
            case 4:
                printf("Post Order Traversal: ");
                postOrder(root);
                printf("\n");
                break;
            case 0:
                freeTree(root); // Free memory before exiting
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}