#include<bits/stdc++.h>
using namespace std;
const int N = 0;

class node {
public:
	int data;
	//Address ko store karna of the next block.
	node *next;//Self Referencing Pointer

	//Pointer Should never be left unitiliased.

	//Constructor
	node(int inputdata) {
		data = inputdata;
		next = NULL;
	}
};

void InsertAtHead(node* &head, int value) {

	node* n = new node(value);
	// (*n).next = head;
	n->next = head;
	head = n;
}

void Print(node* &head) {
	node* temp = head;

	// while (head != NULL) {
	// 	cout << head->data << "-->";
	// 	head = head->next;
	// }
	// cout << "NULL";

	while (temp != NULL) {
		cout << temp->data << "-->";
		temp = temp->next;
	}
	cout << "NULL" << endl;
}

int len(node* head) {
	int length = 0;
	node* temp = head;
	while (temp != NULL) {
		length++;
		temp = temp->next;
	}
	return length;
}

int midPoint(node* head) {
	int mid = len(head) / 2;
	node* temp = head;
	while (mid > 0) {
		temp = temp->next;
		mid--;
	}
	return temp->data;
}

node* midPoint1(node* head) {
	int mid = len(head) / 2;
	node* temp = head;
	while (mid > 0) {
		temp = temp->next;
		mid--;
	}
	return temp;
}
//Second Mid Point
node* midPoint2(node* head) {
	node* slow = head;
	node* fast = head;

	while (fast != NULL and fast->next != NULL) {
		// fast = fast->next;
		// fast = fast->next;
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}
//First MId Point
node* midPoint3(node* head) {
	node* slow = head;
	node* fast = head->next;

	while (fast != NULL and fast->next != NULL) {
		// fast = fast->next;
		// fast = fast->next;
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}

bool searchIterative(node* head, int key) {
	node* temp = head;
	while (temp != NULL) {
		if (temp->data == key) {
			return true;
		}
		temp = temp->next;
	}

	return false;
}

bool searchRecursive(node* head, int key) {

	node* temp = head;
	if (temp == NULL) {
		return false;
	}

	if (temp->data == key) {
		return true;
	} else {
		return searchRecursive(head->next, key);
	}
}

void ReverseLL(node* &head) {
	node* current = head;
	node* prev = NULL;
	node* n;

	while (current != NULL) {
		n = current->next;
		current->next = prev;
		prev = current;
		current = n;
	}
	//current==NULL
	//prev=last node or the first node of the reverse ll.
	head = prev;
}

void Cycle_Creation(node* head) {
	node* temp = head;

	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = head->next->next->next;
}

bool isCycle(node*head) {
	node* slow = head;
	node* fast = head;

	while (fast != NULL and fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast) {
			return true;
		}
	}
	return false;
}

void Break_Cycle(node* head) {
	if (isCycle(head) == 0) {
		return;
	}

	node* fast = head;
	node* slow = head;

	while (fast != NULL and fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast) {
			break;
		}
	}



	// Mayank:
	node* prev = head;
	while (prev->next != fast) {
		prev = prev->next;
	}

	slow = head;

	while (slow != fast) {
		slow = slow->next;
		fast = fast->next;
		prev = prev->next;
	}

	prev->next = NULL;

}







int main() {

	node* head = NULL;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		InsertAtHead(head, x);
	}

	// int key;
	// cin >> key;

	// Print(head);
	// Print(head);
	// cout << len(head) << endl;
	// cout << midPoint(head) << endl;

	// cout << midPoint1(head)->data << endl;
	// node* m = midPoint1(head);
	// cout << m->data << endl;

	// cout << midPoint2(head)->data << endl;
	// cout << midPoint3(head)->data << endl;
	// cout << searchIterative(head, key) << endl;
	// cout << searchRecursive(head, key) << endl;

	ReverseLL(head);
	Print(head);
	Cycle_Creation(head);
	cout << isCycle(head) << endl;
	Break_Cycle(head);
	cout << isCycle(head) << endl;

}