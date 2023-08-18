#include<iostream>
#include<vector>
#include<stack>
using  namespace std;

int main() {
	int  n;
	cin >> n;
	stack<char>st;
	vector<char>v;
	string str;

	for (int i = 0; i < n; i++) {
		char x;
		cin >> x;
		st.push(x);
		v.push_back(x);
		str.push_back(x);
	}


	cout << st.top() << endl;
	cout << v[v.size() - 1] << endl;
	cout << str.back() << endl;


	st.pop();
	v.pop_back();
	str.pop_back();

	cout << st.top() << endl;
	cout << v[v.size() - 1] << endl;
	cout << str.back() << endl;



	cout << v[0] << endl;
	cout << str.front() << endl;

}









