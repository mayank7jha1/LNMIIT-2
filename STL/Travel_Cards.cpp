#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using  namespace std;
#define int long long


int Travel_Cards() {

	int a, b, n, k, f;
	cin >> n >> a >> b >> k >> f;

	map<pair<string, string>, int>mp;

	string prev_destination = "";

	for (int i = 0; i < n; i++) {

		string starting_point, ending_point;
		cin >> starting_point >> ending_point;

		int price = 0;//Current Travel normal hain ki transshipment hain.

		if (prev_destination == starting_point) {
			price = b;
		} else {
			price = a;
		}

		prev_destination = ending_point;

		if (starting_point > ending_point) {
			swap(starting_point, ending_point);
		}

		if (mp.find({starting_point, ending_point}) != mp.end()) {
			mp[ {starting_point, ending_point}] += price;
		} else {
			mp[ {starting_point, ending_point}] = price;
		}
	}

	vector<int>v;
	int total_cost = 0;

	for (auto x : mp) {
		v.push_back(x.second);
		total_cost += x.second;
	}

	sort(v.rbegin(), v.rend());//Reverse Order Sort

	for (int i = 0; i < k and i < v.size(); i++) {
		if (v[i] >= f) {
			total_cost = total_cost - v[i] + f;
		} else {
			break;
		}
	}

	return total_cost;

}

int32_t main() {
	cout << Travel_Cards() << endl;
}




