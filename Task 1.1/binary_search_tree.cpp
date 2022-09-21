#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int n){
        data = n;
        left = NULL;
        right = NULL;
    }

      Node* insert(Node* root, int data) {
        if(root == NULL){
            return new Node(data);
        }
     else{
            Node* cur;
            if(data <= root->data) {
                cur = insert(root->left, data);
                root->left = cur;
            }
            else {
                cur = insert(root->right, data);
                root->right = cur;
            }
        return root;
     }
    }
     void inorder(Node* root){
        if(root == NULL)
            return;
        
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
     Node* search(Node* root, int key) {
            if(root == NULL || root->data == key)
                return root;

            if(root->data < key)
                return search(root->right,key);

            return search(root->left,key);
         }

          Node* deletenode(Node* root, int k) 
    { 
        
        if (root == NULL) 
            return root; 
        
        if(root->data > k){ 
            root->left = deletenode(root->left, k); 
            return root; 
        } 
        else if(root->data < k){ 
            root->right = deletenode(root->right, k); 
            return root; 
        } 
        
        if (root->left == NULL) { 
            Node* temp = root->right;
            delete root; 
            return temp; 
        } 
        else if (root->right == NULL) { 
            Node* temp = root->left; 
            delete root; 
            return temp; 
        } 
else {
            Node* Parent = root;
            Node *succ = root->right; 
            while (succ->left != NULL) { 
                Parent = succ; 
                succ = succ->left; 
            } 

            if (Parent != root) 
                Parent->left = succ->right; 
            else
                Parent->right = succ->right; 
 
            root->data = succ->data; 

            delete succ;          
            return root; 
        } 
    } 
};

int main(){
    Node Tree(0);
    Node* root = NULL;
    //Take input 
    int t;
    cin>>t;
    while(t--){
        int data;
        cin>>data;
        root = Tree.insert(root,data);
    }

    cout << "Enter the data: ";
    int data;
    cin>>data;
    Node* find_element = Tree.search(root,data);

    int delete_data;
    cin>>delete_data;
    Node* deleteelement = Tree.deletenode(root,delete_data);
    return 0;
}