#include <iostream>
#include <map>
#define ll long long
using namespace std;


map<ll, int>z, k;
pair<pair<ll, ll>, pair<ll, ll>>mp[200005];
ll arr[200005];
void solve()
{
	int i, j, n;
	cin >> n;
	int km, zm;
	km = zm = 0;
	k.erase(k.begin(), k.end());
	z.erase(z.begin(), z.end());
	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
		if (i % 2)
		{
			k[arr[i]]++;
			if (k[arr[i]] > km)
				km = k[arr[i]];
		}
		else
		{
			z[arr[i]]++;
			if (z[arr[i]] > zm)
				zm = z[arr[i]];
		}
	}
	if (k.size() == z.size() && z.size() == 1)
	{
		cout << 0 << endl;
		return;
	}
	for (i = 0; i <= n; i++)
	{
		mp[arr[i]].second = { arr[i + 1], 0};
		if (i > 0)
			mp[arr[i]].first = { arr[i - 1], 0 };
		else
			mp[arr[i]].first = { -1, 0 };
		if(i==n)
			mp[arr[i]].second = { -1, 0 };
	}
	
	for (i = 1; i < n; i++)
	{
		if (i % 2)
		{
			mp[arr[i - 1]].second.second++;
			if (i < n - 1)
			{
				if (arr[i + 1] == arr[i - 1])
					i++;
			}
		}
		else
		{
			mp[arr[i]].first.second++;
			if (i < n - 1)
			{
				if (arr[i + 1] == arr[i - 1])
					i++;
			}
		}
	}
	int res = n;
	pair<ll, ll>p1, p2, p3;
	pair<ll, ll>p11, p22, p33;
	p1 = p2 = p3 = { -1, -1 };
	for (i = 0; i < n; i += 2)
	{
		for (j = 1; j < n; j += 2)
		{
			if (arr[i] == arr[j])
				continue;
			int u = n - z[arr[i]] - k[arr[j]];
			bool b = 0;
			int l = 0;
			l = u;
			l += mp[arr[j]][arr[i]];

			//cout << i << ' ' << j << ' ' << l << endl;
			res = min(res, l);
		}
	}
	res = min(n - zm, res);
	res = min(n - km, res);
	cout << res << endl;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}