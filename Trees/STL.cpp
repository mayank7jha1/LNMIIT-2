#include<iostream>
#include<forward_list>
#include<vector>
using  namespace std;

int main() {

	//Singly Linkly List:
	forward_list<int>f;

	f.assign({50, 60, 90});
	f.assign({101});

	f.assign(15, 10);



	vector<int>v = {1, 2, 3, 4, 5};
	f.assign(v.begin(), v.end());

	for (auto x : f) {
		cout << x << " ";
	}
	cout << endl;

	forward_list<int>f1 = f;
	for (auto x : f) {
		cout << x << " ";
	}
	cout << endl;

	//Insert  at head.

	forward_list<int>g;
	g.push_front(100);
	g.push_front(200);
	g.push_front(300);

	for (auto x : g) {
		cout << x << " ";
	}
	cout << endl;

	g.pop_front();
	for (auto x : g) {
		cout << x << " ";
	}
	cout << endl;

	g.remove(100);
	for (auto x : g) {
		cout << x << " ";
	}

	g.clear();
	cout << endl;
	int a[] = {1, 2, 3, 4, 5};
	cout << a << endl;

	cout << *(a + 1) << endl;

	forward_list<int>m{11, 12, 13, 14, 15};

	for (forward_list<int>::iterator it = m.begin(); it != m.end(); it++) {
		cout << (*it) << " ";
	}
}













