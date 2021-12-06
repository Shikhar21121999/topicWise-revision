#include <bits/stdc++.h>
using namespace std;

// Right view of a Binary Tree is set of nodes visible 
// when tree is visited from right side.

class Node{
public:
	int data;
	Node* left;
	Node* right;

	Node() {
		this -> data = 0;
		this -> left = nullptr;
		this -> right = nullptr;
	}

	Node (int a) {
		this -> data = a;
		this -> left = nullptr;
		this -> right = nullptr;
	}
};

vector<int> rightView(Node *root) {
	Node *curr = root;

	vector <int> a;
	// base case
	if (root == nullptr) return a;

	queue <Node *> q;

	q.push(curr);
	while(!q.empty()) {
		int n = q.size();

		for(int i=1;i<=n;i++){
			Node* curr = q.front();
			q.pop();

			if(i==n){
				a.push_back(curr->data);
			} else {
				if (curr -> left != NULL) {
					q.push(curr -> left);
				} if (curr -> right != NULL) {
					q.push(curr -> right);
				}
			}
		}
	}
	return a;

}

int main() {
	// create binary tree
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->right->left = new Node(5);
	root->right->left->left = new Node(7);
	root->right->left->right = new Node(8);

	vector <int> result = rightView(root);
	for (auto x: result) {
		cout << x << " ";
	}
}