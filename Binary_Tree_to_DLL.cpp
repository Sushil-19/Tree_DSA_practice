class Solution
{
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    Node * bToDLL(Node *root)
    {
        Node *curr = root, *head = NULL;
        
        while(curr != NULL){
            if(curr->left != NULL){
                Node* trav = curr->left;
                while(trav->right != NULL && trav->right != curr)
                    trav = trav->right;
                
                if(trav->right == NULL){
                    trav->right = curr;
                    
                    Node *tmp = curr->left;
                    curr->left = trav;
                    curr=tmp;
                    continue;
                }
            }    
            if(head == NULL) head = curr;
            //cout<<curr->right->data<<endl;
            
            Node *trav = curr->right;
            if(trav != NULL && trav->left != curr){
                while(trav->left != NULL)
                    trav = trav->left;
                
                Node* tmp = curr->right;
                trav->left = curr;
                curr->right = trav;
                curr = tmp;
            }
            else curr = curr->right;
                
            
        }
        return head;
    }
};
