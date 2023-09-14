// C++ program to print top
// view of binary tree

#include <bits/stdc++.h>
using namespace std;

// Structure of binary tree
struct Node {
	Node* left;
	Node* right;
	int hd;
	int data;
};

// function to create a new node
Node* newNode(int key)
{
	Node* node = new Node();
	node->left = node->right = NULL;
	node->data = key;
	return node;
}

// function should print the topView of
// the binary tree
void topview(Node* root)
{
	if (root == NULL)
		return;
	queue<Node*> q;
	map<int, int> m;
	int hd = 0;
	root->hd = hd;

	// push node and horizontal distance to queue
	q.push(root);

	cout << "The top view of the tree is : \n";

	while (q.size()) {
		hd = root->hd;

		// count function returns 1 if the container
		// contains an element whose key is equivalent
		// to hd, or returns zero otherwise.
		if (m.count(hd) == 0)
			m[hd] = root->data;
		if (root->left) {
			root->left->hd = hd - 1;
			q.push(root->left);
		}
		if (root->right) {
			root->right->hd = hd + 1;
			q.push(root->right);
		}
		q.pop();
		root = q.front();
	}

	for (auto i = m.begin(); i != m.end(); i++) {
		cout << i->second << " ";
	}
}

// Driver code
int main()
{
	/* Create following Binary Tree
		1
		/ \
	2 3
		\
		4
		\
			5
			\
			6
	*/
	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->right = newNode(4);
	root->left->right->right = newNode(5);
	root->left->right->right->right = newNode(6);
	topview(root);
	return 0;
}
/* This code is contributed by Niteesh Kumar */


/////////////////////////// Method 2 ///////////////////////////////

// C++ Program for the above approach

#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;
	Node(int data){
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

struct QueueObj{
	Node* node;
	int hd;
	QueueObj(Node *node, int hd){
		this->node = node;
		this->hd = hd;
	}
};

void topView(Node* root){
	if(root == NULL) return;
	
	queue<QueueObj*> q;
	map<int, int> mp;
	int mn = 0;
	int mx = 0;
	// Level Order Traversal
	q.push(new QueueObj(root, 0));
	while(!q.empty()){
		QueueObj* curr = q.front();
		q.pop();
		
		// only include in map if this is the
		// first node of this specific
		// horizontal distance
		if(mp.find(curr->hd) == mp.end()){
			mp[curr->hd] = curr->node->data;
		}
		
		if(curr->node->left != NULL){
			// min can be found only in left side due to
			// "-1" minimum horizontal distance of any
			// node from root
			mn = min(mn, curr->hd-1);
			q.push(new QueueObj(curr->node->left, curr->hd-1));
		}
		
		if(curr->node->right != NULL){
			// max can be found only in right side due to
			// "+1" maximum horizontal distance of any
			// node from root
			mx = max(mx, curr->hd+1);
			q.push(new QueueObj(curr->node->right, curr->hd+1));
		}
	}
	
	// traversal of (horizontal distance from rooo)
	// minimum to maximum
	for(; mn<=mx; mn++){
		cout<<mp[mn]<<" ";
	}
	cout<<endl;
}

int main(){
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->right = new Node(4);
	root->left->right->right = new Node(5);
	root->left->right->right->right = new Node(6);
	cout<<"Following are nodes in top view of Binary Tree"<<endl;
	topView(root);
	return 0;
}

// This code is contributed by Yash Agarwal(yashagarwal2852002)


///////////////////////////////// Method 3 ///////////////////////////

// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

// Structure of binary tree
struct Node {
	Node* left;
	Node* right;
	int data;
};

// function to create a new node
Node* newNode(int key)
{
	Node* node = new Node();
	node->left = node->right = NULL;
	node->data = key;
	return node;
}

// function to fill the map
void fillMap(Node* root, int d, int l,
			map<int, pair<int, int> >& m)
{
	if (root == NULL)
		return;

	if (m.count(d) == 0) {
		m[d] = make_pair(root->data, l);
	}
	else if (m[d].second > l) {
		m[d] = make_pair(root->data, l);
	}

	fillMap(root->left, d - 1, l + 1, m);
	fillMap(root->right, d + 1, l + 1, m);
}

// function should print the topView of
// the binary tree
void topView(struct Node* root)
{

	// map to store the pair of node value and its level
	// with respect to the vertical distance from root.
	map<int, pair<int, int> > m;

	// fillmap(root,vectical_distance_from_root,level_of_node,map)
	fillMap(root, 0, 0, m);

	for (auto it = m.begin(); it != m.end(); it++) {
		cout << it->second.first << " ";
	}
}
// Driver code
int main()
{
	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->right = newNode(4);
	root->left->right->right = newNode(5);
	root->left->right->right->right = newNode(6);
	cout << "Following are nodes in top view of Binary "
			"Tree\n";
	topView(root);
	return 0;
}
/* This code is contributed by Akash Debnath */


////////////////////////// Method 4 ////////////////////////////////////


// C++ Program to print Top View of a binary Tree

#include <bits/stdc++.h>
using namespace std;

// class for Tree node
class Node {
public:
	Node *left, *right;
	int data;
	Node() { left = right = 0; }
	Node(int data)
	{
		left = right = 0;
		this->data = data;
	}
};

/*
		1
		/ \
		2 3
		\
		4
		\
			5
			\
			6
	Top view of the above binary tree is
	2 1 3 6
*/

// class for Tree
class Tree {
public:
	Node* root;
	Tree() { root = 0; }

	void topView()
	{
		// queue for holding nodes and their horizontal
		// distance from the root node
		queue<pair<Node*, int> > q;

		// pushing root node with distance 0
		q.push(make_pair(root, 0));

		// hd is current node's horizontal distance from
		// root node l is current left min horizontal
		// distance (or max in magnitude) so far from the
		// root node r is current right max horizontal
		// distance so far from the root node

		int hd = 0, l = 0, r = 0;

		// stack is for holding left node's data because
		// they will appear in reverse order that is why
		// using stack
		stack<int> left;

		// vector is for holding right node's data
		vector<int> right;

		Node* node;

		while (q.size()) {

			node = q.front().first;
			hd = q.front().second;

			if (hd < l) {
				left.push(node->data);
				l = hd;
			}
			else if (hd > r) {
				right.push_back(node->data);
				r = hd;
			}

			if (node->left) {
				q.push(make_pair(node->left, hd - 1));
			}
			if (node->right) {
				q.push(make_pair(node->right, hd + 1));
			}

			q.pop();
		}
		// printing the left node's data in reverse order
		while (left.size()) {
			cout << left.top() << " ";
			left.pop();
		}

		// then printing the root node's data
		cout << root->data << " ";

		// finally printing the right node's data
		for (auto x : right) {
			cout << x << " ";
		}
	}
};

// Driver code
int main()
{
	// Tree object
	Tree t;
	t.root = new Node(1);
	t.root->left = new Node(2);
	t.root->right = new Node(3);
	t.root->left->right = new Node(4);
	t.root->left->right->right = new Node(5);
	t.root->left->right->right->right = new Node(6);
	t.topView();
	cout << endl;
	return 0;
}
