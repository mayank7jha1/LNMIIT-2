#include<iostream>
#include<climits>
#include<bits/stdc++.h>
using  namespace std;

class node {
public:
	int data;
	node* left;
	node* right;

	node(int inputdata) {
		data = inputdata;
		left = NULL;
		right = NULL;
	}
};

node* buildtree() {
	int x;
	cin >> x;
	if (x == -1) {
		return NULL;
	} else {
		node* n = new node(x);
		// (*n).left
		n->left = buildtree();
		n->right = buildtree();
		return n;
	}
}

void Preorder(node* root) {

	if (root == NULL) {
		return;
	}

	cout << root->data << " ";
	Preorder(root->left);
	Preorder(root->right);
}

void Inorder(node* root) {

	if (root == NULL) {
		return;
	}
	Inorder(root->left);
	cout << root->data << " ";
	Inorder(root->right);
}

void Postorder(node* root) {

	if (root == NULL) {
		return;
	}
	Postorder(root->left);
	Postorder(root->right);
	cout << root->data << " ";
}

int Countnodes(node* root) {

	if (root == NULL) {
		return 0;
	}

	int left_subtree = Countnodes(root->left);
	int right_subtree = Countnodes(root->right);

	int ans = left_subtree + right_subtree + 1;
	return ans;
}


int SumOfnodes(node* root) {

	if (root == NULL) {
		return 0;
	}

	int left_subtree = SumOfnodes(root->left);
	int right_subtree = SumOfnodes(root->right);

	int ans = left_subtree + right_subtree + root->data;
	return ans;
}


int height(node* root) {
	if (root == NULL) {
		return 0;
	}

	int left_subtree_height = height(root->left);
	int right_subtree_height = height(root->right);

	int ans = max(left_subtree_height, right_subtree_height) + 1;
	return ans;
}

void Mirror(node* root) {
	if (root == NULL) {
		return;
	}
	swap(root->left, root->right);
	Mirror(root->left);
	Mirror(root->right);
}
int diameter(node* root) {

	if (root == NULL) {
		return 0;
	}

	int Option1 = diameter(root->left);
	int Option2 = diameter(root->right);

	int Option3 = height(root->left) + height(root->right);

	return max({Option1, Option2, Option3});
}

class Pair2 {
public:
	int height;
	int diameter;
};

// pair<int, int>p;

Pair2  fastdiameter(node* root) {
	Pair2 p;

	if (root == NULL) {
		p.height = 0;
		p.diameter = 0;
		return p;
	}

	Pair2 left_subtree = fastdiameter(root->left);
	Pair2 right_subtree = fastdiameter(root->right);

	p.height = max(left_subtree.height, right_subtree.height) + 1;

	p.diameter = max({left_subtree.diameter, right_subtree.diameter,
	                  left_subtree.height + right_subtree.height
	                 });

	return p;
}

class Pair3 {
public:
	int height;
	int isbalanced;
};

Pair3 IsheightBalanced(node* root) {
	Pair3 p;

	if (root == NULL) {
		p.isbalanced = 1;
		p.height = 0;
		return p;
	}

	Pair3 left_subtree = IsheightBalanced(root->left);
	Pair3 right_subtree = IsheightBalanced(root->right);

	p.height = max(left_subtree.height, right_subtree.height) + 1;

	if (left_subtree.isbalanced == 1 and right_subtree.isbalanced == 1 and
	        abs(left_subtree.height - right_subtree.height) <= 1) {
		p.isbalanced = 1;
	} else {
		p.isbalanced = 0;
	}
	return p;
}


int main() {
	node* root = buildtree();
	Preorder(root);
	cout << endl;
	Inorder(root);
	cout << endl;
	Postorder(root);
	cout << endl;

	cout << Countnodes(root) << endl;
	cout << SumOfnodes(root) << endl;
	cout << height(root) << endl;
	Mirror(root);
	Preorder(root);
	cout << endl;
	cout << diameter(root) << endl;
	Pair2 p = fastdiameter(root);
	cout << p.height << " " << p.diameter << endl;
	Pair3 p1 = IsheightBalanced(root);
	cout << p1.height << " " << p1.isbalanced << endl;
}



// Data = x;
// left = NULL;
// right = NULL;







