class Solution{
    public:
    int find(int in[],int start,int n){
       for(int i=0;i<n;i++){
           if(start==in[i]){
               return i;
           }
       }
   }
   Node* construct(int in[],int pre[],int &preindex,int instart,int inend,int n){
       if(preindex >=n)return NULL;
       if(instart > inend)return NULL;
       int start=pre[preindex++];
       Node* root= new Node(start);
       int pos=find(in,start,n);
       root->left=construct(in,pre,preindex,instart,pos-1,n);
       root->right=construct(in,pre,preindex,pos+1,inend,n);
       return root;
   }
   Node* buildTree(int in[],int pre[], int n)
   {
       // Code here
       int preindex=0;
       Node* root=construct(in,pre,preindex,0,n-1,n);
       return root;
   }
};

