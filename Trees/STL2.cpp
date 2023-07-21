#include<iostream>
#include<list>
using  namespace std;

void Print(list<int>&l) {
	list<int>::iterator it;

	for (it = l.begin(); it != l.end(); it++) {
		cout << (*it) << " ";
	}

	cout << endl;

	for (int x : l) {
		cout << x << " ";
	}
	cout << endl;

}


int main() {

	//vector<int>

	list<int>l;

	l.push_front(10);
	l.push_back(30);
	l.push_front(45);
	l.push_back(100);
	l.push_back(301);

	Print(l);
	list<int>l2 = l;

	// l.pop_front();
	// l.pop_back();

	//Print(l);

	l.sort();
	l.reverse();

	Print(l);

	cout << l.front() << " " << l.back() << endl;

}










