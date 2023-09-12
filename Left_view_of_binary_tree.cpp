
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node *left, *right;
};

struct Node* newNode(int item)
{
	struct Node* temp
		= (struct Node*)malloc(sizeof(struct Node));
	temp->data = item;
	temp->left = temp->right = NULL;
	return temp;
}

void leftViewUtil(struct Node* root, int level,
				int* max_level)
{
    
	if (root == NULL)
		return;

	if (*max_level < level) {
		cout << root->data << " ";
		*max_level = level;
	}

	leftViewUtil(root->left, level + 1, max_level);
	leftViewUtil(root->right, level + 1, max_level);
}


void leftView(struct Node* root)
{
	int max_level = 0;
	leftViewUtil(root, 1, &max_level);
}

s
int main()
{
	Node* root = newNode(10);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(7);
	root->left->right = newNode(8);
	root->right->right = newNode(15);
	root->right->left = newNode(12);
	root->right->right->left = newNode(14);

	leftView(root);

	return 0;
}



///////////////////////// Method 2 /////////////////////////////////


#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left, *right;
};

Node* newNode(int data)
{
	Node *temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}


void printLeftView(Node* root)
{
	if (!root)
		return;

	queue<Node*> q;
	q.push(root);

	while (!q.empty())
	{	
		int n = q.size();
		
		for(int i = 1; i <= n; i++)
		{
			Node* temp = q.front();
			q.pop();
				
			if (i == 1)
				cout<<temp->data<<" ";
			
			if (temp->left != NULL)
				q.push(temp->left);

			if (temp->right != NULL)
				q.push(temp->right);
		}
	}
}	

int main()
{
    

	Node* root = newNode(10);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(7);
	root->left->right = newNode(8);
	root->right->right = newNode(15);
	root->right->left = newNode(12);
	root->right->right->left = newNode(14);

	printLeftView(root);
}

///////////////////////// Method 3 /////////////////////////////



#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left, *right;
};

Node* newNode(int data)
{
	Node *temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

void printLeftView(Node* root)
{
	if (!root)
		return;

	queue<Node*> q;
	q.push(root);

	while (!q.empty())
	{	
		int n = q.size();
		
		for(int i = 1; i <= n; i++)
		{
			Node* temp = q.front();
			q.pop();
				
			if (i == 1)
				cout<<temp->data<<" ";
			
			if (temp->left != NULL)
				q.push(temp->left);

			if (temp->right != NULL)
				q.push(temp->right);
		}
	}
}	

int main()
{

	Node* root = newNode(10);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(7);
	root->left->right = newNode(8);
	root->right->right = newNode(15);
	root->right->left = newNode(12);
	root->right->right->left = newNode(14);

	printLeftView(root);
}