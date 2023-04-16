#include <iostream>
#include <vector>
using namespace std;
#define ll long long

ll arr[20005];
ll brr[200005];
int m;
ll opt2(vector<ll> ms, int ind);
ll opt1(vector<ll> ms, int ind)
{
	ll a, b;
	vector<ll> ms1, ms2;
	ms1 = ms2 = ms;
	a = b = 0;
	//cout << '5';
	for (int i = 0; i < ms1.size(); i++)
	{
		if (ms1[i] == -10000000000000)
			continue;
		if (ms1[i] % brr[ind] == 0)
		{
			a += ms1[i];
			ms1[i] = -10000000000000;
		}
		if (ms2[i] % brr[ind] != 0)
		{
			b += ms2[i];
			ms2[i] = -10000000000000;
		}
	}
	//cout << '5';
	//cout << '5';
	if (ind == m - 1)
	{
		return min(a, b);
	}
	else
		return min(opt2(ms1, ind + 1), opt2(ms2, ind + 1));
}
ll opt2(vector<ll> ms, int ind)
{
	ll a, b;
	vector<ll> ms1, ms2;
	ms1 = ms2 = ms;
	a = b = 0;
	//cout << '5';
	for (int i = 0; i < ms1.size(); i++)
	{
		if (ms1[i] == -10000000000000)
			continue;
		if (ms1[i] % brr[ind] == 0)
		{
			a += ms1[i];
			ms1[i] = -10000000000000;
		}
		if (ms2[i] % brr[ind] != 0)
		{
			b += ms2[i];
			ms2[i] = -10000000000000;
		}
	}
	//cout << '5';
	//cout << '5';
	if (ind == m - 1)
	{
		return max(a, b);
	}
	else
		return max(opt1(ms1, ind + 1), opt1(ms2, ind + 1));
}
void solve()
{
	int i, j, n;
	bool multitest2 = 1;
	bool multitest3 = 1;
	cin >> n >> m;
	ll sum = 0;
	vector<ll>ms;
	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
		sum += arr[i];
		ms.push_back(arr[i]);
	}
	for (i = 0; i < m; i++)
	{
		cin >> brr[i];
		if (i > 0)
		{
			if (brr[i - 1] != brr[i])
				multitest2 = false;
			if (brr[i] % brr[i - 1] != 0)
				multitest3 = false;
		}
	}
	if (m == 1)
	{
		ll s1, s2;
		s1 = s2 = 0;
		for (i = 0; i < n; i++)
		{
			s1 += (arr[i] % brr[0] == 0) * arr[i];
			s2 += (arr[i] % brr[0] != 0) * arr[i];
		}
		cout << min(s1, s2);
	}
	else if (multitest2)
	{
		ll s1, s2;
		s1 = s2 = 0;
		for (i = 0; i < n; i++)
		{
			s1 += (arr[i] % brr[0] == 0) * arr[i];
			s2 += (arr[i] % brr[0] != 0) * arr[i];
		}
		if (m > 2)
		{
			cout << 0;
		}
		else cout << min(s1, s2);
	}
	else if (multitest3 && m>2)
	{
		cout << 0;
	}
	else
	{
		cout << opt1(ms, 0);
	}
}
int main()
{
	solve();

	return 0;
}