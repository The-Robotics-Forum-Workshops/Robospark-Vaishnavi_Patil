#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left_child, *right_child;
};

struct node *newNode(int key);// Create a node
void inOrder(struct node *root);// inOrder Traversal
void preOrder(struct node *root);// preOrder Traversal
void postOrder(struct node *root);// postOrder Traversal
struct node *insert(struct node *node, int data);// Insert a node
struct node *inOrderSuccessor(struct node *node);// Find the inOrder successor
struct node *deleteNode(struct node *root, int data);// Deleting a node
struct node* search(struct node *root, int key);// Searching an item

int main()
{
    struct node *root = NULL;
    int n;

    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 7);
    root = insert(root, 10);
    root = insert(root, 14);
    root = insert(root, 4);
    
    printf("*Binary Search Tree*");

    printf("\nInOrder traversal: ");
    inOrder(root);

    printf("\nAfter deleting 10\n");
    root = deleteNode(root, 10);

    printf("InOrder traversal: ");
    inOrder(root);

    printf("\n\n*Traversing*");
    printf("\nPreOrder traversal: ");
    preOrder(root);
    printf("\nPostOrder traversal: ");
    postOrder(root);

    printf("\n\n*Searching*");
    search(root, 1);
    search(root, 10);
}

struct node *newNode(int key)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = key;
    temp->left_child = temp->right_child = NULL;
    return temp;
}

void inOrder(struct node *root)
{
    if (root != NULL)
    {
        inOrder(root->left_child);
        printf("%d - ", root->data);
        inOrder(root->right_child);
    }
}

void preOrder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d - ", root->data);
        preOrder(root->left_child);
        preOrder(root->right_child);
    }
}

void postOrder(struct node *root)
{
    if (root != NULL)
    {
        postOrder(root->left_child);
        postOrder(root->right_child);
        printf("%d - ", root->data);
    }
}

struct node *insert(struct node *node, int data)
{
    if (node == NULL) return newNode(data);
    if (data < node->data) node->left_child = insert(node->left_child, data);
    else node->right_child = insert(node->right_child, data);
    return node;
}

struct node *inOrderSuccessor(struct node *node)
{
    struct node *current = node;
    while (current && current->left_child != NULL)
    current = current->left_child;
    return current;
}

struct node *deleteNode(struct node *root, int data)
{
    if (root == NULL) return root;
    if (data < root->data) root->left_child = deleteNode(root->left_child, data);
    else if (data > root->data) root->right_child = deleteNode(root->right_child, data);
    else
    {
        if (root->left_child == NULL)
        {
            struct node *temp = root->right_child;
            free(root);
            return temp;
        }
        else if (root->right_child == NULL)
        {
            struct node *temp = root->left_child;
            free(root);
            return temp;
        }
        struct node *temp = inOrderSuccessor(root->right_child);
        root->data = temp->data;
        root->right_child = deleteNode(root->right_child, temp->data);
    }
    return root;
}

struct node* search(struct node *root, int key)
{
    while(root != NULL)
    {
    if(root->data==key)
    {
        printf("\n%d is present in list", key);
        return root;
    }
    else if(key>root->data)
        return search(root->right_child, key);
    else
        return search(root->left_child,key);
    }
    printf("\n%d is not present in list", key);
    return 0;
}