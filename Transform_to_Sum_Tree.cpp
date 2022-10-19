Solution 1:

class Solution {
  public:
  
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    int helper(Node *node)
   {
       if(node==NULL)
       return 0;
       return helper(node->left)+helper(node->right)+node->data;
   }
    void toSumTree(Node *node)
    {
        // Your code here
        
       if(node==NULL)
       return ;
        
        int left=helper(node->left);
        int right=helper(node->right);
        
        node->data=left+right;
        toSumTree(node->left);
        toSumTree(node->right);
    }
};


Solution 2:

class Solution {
  public:
  
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    int solve(Node *root)
  {
      if(!root) return 0;
      int a = solve(root->left);
      int b = solve(root->right);
      int x = root->data;
      root->data =  a+ b;
      return a + b + x;
  }
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    void toSumTree(Node *node)
    {
        // Your code here
         solve(node);
    }
};
