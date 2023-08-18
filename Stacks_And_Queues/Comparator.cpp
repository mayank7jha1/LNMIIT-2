#include<iostream>
#include<vector>
#include<algorithm>
using  namespace std;

bool compare(int x, int y) {

	if (x > y) {
		return false;
	} else {
		return true;
	}

}



int main() {

	vector<int>v{15, 13, 22, 12, 9, 19, 37};

	sort(v.begin(), v.end(), greater<int>());
	// reverse(v.begin(), v.end());

	for (auto x : v) {
		cout << x << " ";
	}
}

// greater<int>
// less<int>
//less_equal

