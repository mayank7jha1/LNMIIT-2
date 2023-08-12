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

node* buildtreefromArray(int* a, int s, int e) {

	if (s > e) {
		return NULL;
	}

	int mid = (s + e) / 2;

	node* n = new node(a[mid]);
	n->left = buildtreefromArray(a, s, mid - 1);
	n->right = buildtreefromArray(a, mid + 1, e);

	return n;
}


void Printkthlevel(node* root, int k) {

	if (root == NULL) {
		return;
	}

	if (k == 1) {
		cout << root->data << " ";
		return;
	}

	Printkthlevel(root->left, k - 1);
	Printkthlevel(root->right, k - 1);
}

//O(n^2);
void PrintAllLevel(node* root) {
	int H = height(root);//O(n);

	for (int i = 1; i <= H; i++) {
		Printkthlevel(root, i);
		cout << endl;
	}
}


void bfs(node* root) {

	queue<node*>q;

	q.push(root);

	while (!q.empty()) {
		node* f = q.front();
		q.pop();

		cout << f->data << " ";

		if (f->left != NULL) {
			q.push(f->left);
		}

		if (f->right != NULL) {
			q.push(f->right);
		}
	}
}


void bfs2(node* root) {
	queue<node*>q;
	q.push(root);
	q.push(NULL);

	while (!q.empty()) {
		node* f = q.front();

		if (f == NULL) {
			cout << endl;
			q.pop();

			if (!q.empty()) {
				q.push(NULL);
			}
		} else {
			cout << f->data << " ";
			q.pop();

			if (f->left != NULL) {
				q.push(f->left);
			}

			if (f->right != NULL) {
				q.push(f->right);
			}
		}

	}
}

void PrintLeftView(node* root, int level, int &maxlevel) {

	if (root == NULL) {
		return;
	}

	if (maxlevel < level) {
		cout << root->data << " ";
		maxlevel = level;
	}

	PrintLeftView(root->left, level + 1, maxlevel);
	PrintLeftView(root->right, level + 1, maxlevel);
}

void PrintRightView(node* root, int level, int &maxlevel) {

	if (root == NULL) {
		return;
	}

	if (maxlevel < level) {
		cout << root->data << " ";
		maxlevel = level;
	}

	PrintRightView(root->right, level + 1, maxlevel);
	PrintRightView(root->left, level + 1, maxlevel);
}

node* InsertATBST(node* &root, int value) {

	if (root == NULL) {
		root = new node(value);
		return root;
	}

	if (value < root->data) {
		root->left = InsertATBST(root->left, value);
	}

	if (value > root->data) {
		root->right = InsertATBST(root->right, value);
	}

	return root;

}

node* buildbst() {
	int x;
	cin >> x;

	node* root = NULL;

	while (x != -1) {
		root = InsertATBST(root, x);
		cin >> x;
	}
	return root;
}

int main() {
	// node* root = buildtree();
	// Preorder(root);
	// cout << endl;
	// Inorder(root);
	// cout << endl;
	// Postorder(root);
	// cout << endl;

	// cout << Countnodes(root) << endl;
	// cout << SumOfnodes(root) << endl;
	// cout << height(root) << endl;
	// Mirror(root);
	// Preorder(root);
	// cout << endl;
	// cout << diameter(root) << endl;
	// Pair2 p = fastdiameter(root);
	// cout << p.height << " " << p.diameter << endl;
	// Pair3 p1 = IsheightBalanced(root);
	// cout << p1.height << " " << p1.isbalanced << endl;

	int arr[] = {1, 2, 3, 4, 5, 6, 7};
	int n = 7;
	node* root2 = buildtreefromArray(arr, 0, n - 1);
	Preorder(root2);
	cout << endl;

	Pair3 p2 = IsheightBalanced(root2);
	cout << p2.isbalanced << " " << p2.height << endl;

	Pair2 p = fastdiameter(root2);
	cout << p.diameter << " " << p.height << endl;
	Printkthlevel(root2, 3);
	cout << endl;
	PrintAllLevel(root2);

	bfs(root2);
	cout << endl << endl;;

	bfs2(root2);
	cout << endl;

	cout << "The Left View of the Tree is : ";
	int maxlevel = -1;
	PrintLeftView(root2, 0, maxlevel);
	int maxlevel2 = -1;
	cout << endl;

	cout << "The Right View of the Tree is : ";
	PrintRightView(root2, 0, maxlevel2);



}



// Data = x;
// left = NULL;
// right = NULL;






