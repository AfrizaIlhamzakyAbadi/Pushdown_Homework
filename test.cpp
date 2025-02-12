#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;
int l{};
void print(vector <int> x)
{
	for (int i{ 0 }; i < x.size(); i++)
	{
		cout << x[i] << " ";
	}
	cout << '\n';
}
void pushDown(vector <int> &x, int size, int node)
{
	x.push_back(node);
	while (size >= 0 && x[size] > x[(size - 1) / 2])
	{
		int t = x[size];
		x[size] = x[(size - 1) / 2];
		x[(size - 1) / 2] = t;
		l = size;
		size = (size - 1) / 2;
	}
	if (node <= x[(size - 1) / 2])
	{
		l = size;
	}
}
void push_down(vector <int> &x, int node)
{
	x.push_back(node);
	push_heap(x.begin(), x.end());
}
int test(vector <int> &x, int size, int node)
{
#ifdef NDEBUG
	cerr << "Test run with NDEBUG defined (accerts compiled out).";
	abort();
#endif
	vector <int> z = x;
	pushDown(x, size, node);
	cout << "by my function :	";
	print(x);
	push_down(z, node);
	cout << "by the test :		";
	print(z);
	cout << "dbug :	" << x[l] << ", " << z[l] << '\n';
	assert(x[l] == z[l]);
	cout << "test succeeded.\n";
	return 0;
}
int main()
{
	vector <int> v{ 1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27 };
	cout << "vector v :	";
	print(v);
	make_heap(v.begin(), v.end());
	cout << "heap v :	";
	print(v);
	srand(time(0));
	for (int i{ 0 }; i < 7; i++)
	{
		int c = rand() % 29;
		cout << "node :	" << c << '\n';
		test(v, 14 + i, c);
		cout << '\n';
	}
	return 0;
}