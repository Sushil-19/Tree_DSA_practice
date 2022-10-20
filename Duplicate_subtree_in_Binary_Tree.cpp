


class Solution {
  public:
    unordered_map<string , int> mp;
    
    string solve(Node *root ){
        if(root==NULL)
            return "#";
        if(root->left== NULL && root->right == NULL)
            return to_string(root->data);
        
        string temp = to_string(root->data);
    
        string l = solve(root->left);
        string r = solve(root->right);
        
        temp = temp+" "+l+" "+r;
        
        mp[temp]++;
        
        return temp;
        
    }
    
    int dupSub(Node *root) {
        if(root == NULL)
            return 0;
        string temp = solve(root);
        for(auto x : mp){
            if(x.second >1){
                return 1;
            }
        }
        return 0;
      
    }
};








