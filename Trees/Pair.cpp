#include<iostream>
#include<utility>
using  namespace std;


template<typename T>

class Pair {
public:
	T x;
	T y;
};

int main() {
	Pair<int> p;
	p.x = 10;
	p.y = 20;

	cout << p.x << " " << p.y << endl;

	pair<int, int>p1;
	p1.first = 100;
	p1.second = 200;

	pair<int, int>p2 = p1;

	p2 = make_pair(101, 500);

	cout << p2.first << " " << p2.second << endl;

	p2 = {300, 900};
}















