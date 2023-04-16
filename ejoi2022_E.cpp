#include <iostream>
#include <map>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

int arr[200005];
pair<int, /**/map<pair<int, int>, int>/**/>dp[200005];
map<int, int>dp1[200005];
string to2(int n, int k)
{
	string r = "";
	while (n)
	{
		r += '0';
		if (n % 2)
			r[r.size() - 1] = '1';
		n /= 2;
	}
	for (int i = 0; i <= k - r.size(); i++)
	{
		r += '0';
	}
	reverse(r.begin(), r.end());
	return r;
}
void solve()
{
	int i, j, n;
	cin >> n;
	//cout << to2(n, n);
	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	for (i = 0; i < n; i++)
	{
		for(j=)
	}
}
int main()
{
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}