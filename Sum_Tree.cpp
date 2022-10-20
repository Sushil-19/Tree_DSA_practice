


class Solution
{
    public:
    bool isleaf(Node* root){
        if(root->left==NULL and root->right==NULL) return 1;
        else return 0;
    }
    bool isSumTree(Node* root)
    {
         // Your code here
        if(!root) return true;
        if(isleaf(root)) return 1;
        
        int x=0; //sum from left and right sub tree
        if(root->left and isleaf(root->left)) x+= root->left->data;
        else if(root->left) x+= 2*root->left->data;
        if(root->right and isleaf(root->right)) x+= root->right->data;
        else if(root->right) x+= 2*root->right->data;
        
        return (isSumTree(root->left) and isSumTree(root->right) 
            and root->data==x);
    }
};

