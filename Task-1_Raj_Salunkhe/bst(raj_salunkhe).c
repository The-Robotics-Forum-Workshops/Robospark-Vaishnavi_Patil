# include <stdio.h>
# include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}nde;



nde *create(int data)
{
    struct node *root = (nde *)malloc(sizeof(nde));
    root->data = data;
    root->left = NULL;
    root->left = NULL;

    return root;
}

nde *insert(nde *root, int data1)
{
    //nde *newnode;
    if(root==NULL)
    {
        root = create(data1);
        return root;
    }
    else if(data1<=root->data)
    {
        //root = root->left;
        root->left = insert(root->left, data1);
        return root;
    }
    else
    {
        //root = root->right;
        root->right = insert(root->right, data1);
        return root;
    }
    return root;
}

int search(nde *root, int data2)
{
    if(root==NULL)
    {
        return 0;
    }
    else if(data2==root->data)
    {
        //printf("Found");
        return 1;
    }
    else if(data2<=root->data)
    {
        //root = root->left;
        return search(root->left, data2);
    }
    else
    {
        //root = root->right;
        return search(root->right, data2);
    }
}

void main()
{
    nde *root = NULL;
    printf("This is a program for Binary Search Tree Implementation:\n");
    int data[20], num;
    for(int i=0; i<6; i++)
    {
        scanf("%d", &data[i]);
        root = insert(root, data[i]);
    }

    printf("Enter a number which you want to search: ");
    scanf("%d", &num);

    if(search(root,num))
    {
        printf("\nThe number exists !\n");
    }
    else
    {
        printf("\nThe number does not exist !\n");
    }


}

