#include<iostream>
#include<vector>
using  namespace std;

int main() {
	int  n;
	cin >> n;
	pair<int, int>a[n];
	vector<pair<int, int>>b(n);

	for (int i = 0; i < n; i++) {
		// int x, y;
		// cin >> x >> y;
		// a[i] = {x, y};

		cin >> a[i].first >> a[i].second;
	}


	for (int i = 0; i < n; i++) {
		cout << a[i].first << " " << a[i].second << endl;
	}

	cout << endl;

	//For Each:

	for (pair<int, int> x : a) {
		cout << x.first << " " << x.second << endl;
	}




}





