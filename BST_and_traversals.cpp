  
#include <iostream>

using namespace std;

struct Node{
    int data;
    Node * left;
    Node * right;
    
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};
Node * Insert( int value, Node* root)
{
    if (!root) {
        return new Node(value);
    }
    if (value > root->data) {
        root->right = Insert( value,root->right);
    }
    else {
        root->left = Insert( value, root->left);
    }
    return root;
}
void RevInorder(Node* root)
{
    if (!root) {
        return;
    }
    RevInorder(root->right);
    cout << root->data << " ";
    RevInorder(root->left);
}
void Inorder(Node* root)
{
    if (!root) {
        return;
    }
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}
void preorder(Node* root){
    if (!root){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node* root){
    if (!root){
        return;
    }
    
    preorder(root->left);
    preorder(root->right);
    cout<<root->data<<" ";
}

int main()
{
    struct Node * root = NULL;
    int n;
    cin>>n;
    Node* node = NULL;
    for (int i=0;i<n;i++){
        int no;
        cin>>no;
        node = Insert(no, root);
        if (i == 0)         root = node;
    }
    
    RevInorder(root);
    cout<<endl;
    Inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);
    
    

    return 0;
}
