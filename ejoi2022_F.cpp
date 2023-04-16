#include <iostream>
#include <algorithm>
using namespace std;

/*int lcs(int a[], int b[], int n)
{
	int d[8][8];
	for (int i = 0; i <= n; i++)
	{
		d[i][0] = 0;
		d[0][i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i] == b[j])
			{
				d[i + 1][j + 1] = d[i][j] + 1;
			}
			else
			{
				d[i + 1][j + 1] = max(d[i][j + 1], d[i + 1][j]);
			}
		}
	}
	return d[n][n];
}*/
void solve()
{
	int n, a, b, c, d;
	cin >> n >> a >> b >> c >> d;
	/*if (n <= 6)
	{
		int i, j;
		int arr1[8];
		int arr2[8];
		int arr3[8];
		for (i = 0; i < n; i++)
		{
			arr1[i] = i + 1;
			arr2[i] = i + 1;
			arr3[i] = i + 1;
		}
		bool con = true;
		do {
			do {
				do {
					if (lcs(arr1, arr2, n) == a && lcs(arr1, arr3, n) == b && lcs(arr2, arr3, n) == c)
					{
						cout << "YES\n";
						con = 0;
						for (i = 0; i < n; i++)
						{
							cout << arr1[i] << ' ';
						}
						cout << endl;
						for (i = 0; i < n; i++)
						{
							cout << arr2[i] << ' ';
						}
						cout << endl;
						for (i = 0; i < n; i++)
						{
							cout << arr3[i] << ' ';
						}
						cout << endl;
					}
				} while (next_permutation(arr3, arr3 + n) && con);
			} while (next_permutation(arr2, arr2 + n) && con);
		} while (next_permutation(arr1, arr1 + n) && con);
		if (con)
			cout << "NO\n";
	}
	else*/ if (a == b && b == 1)
	{
		if (c != n)
		{
			cout << "NO\n";
			return;
		}
		cout << "YES\n";
		for (int i = 0; i < n; i++)
		{
			cout << i + 1 << ' ';
		}
		cout << endl;
		for (int i = n - 1; i >= 0; i--)
		{
			cout << i + 1 << ' ';
		}
		cout << endl;
		for (int i = n - 1; i >= 0; i--)
		{
			cout << i + 1 << ' ';
		}
		cout << endl;
	}
	else if (c == n)
	{
		if (b != a)
		{
			cout << "NO\n";
		}
		else
		{
			cout << "YES\n";
			for (int i = n - 1; i >= a; i--)
			{
				cout << i + 1 << ' ';
			}
			for (int j = 0; j <= a - 1; j++)
			{
				cout << j + 1 << ' ';
			}
			cout << endl;
			for (int i = 0; i < n; i++)
			{
				cout << i + 1 << ' ';
			}
			cout << endl;
			for (int i = 0; i < n; i++)
			{
				cout << i + 1 << ' ';
			}
			cout << endl;
		}
	}
	else if (a == 1)
	{
		if (c == 1 && b == n)
		{
			cout << "YES\n";
			for (int i = 0; i < n; i++)
			{
				cout << i + 1 << ' ';
			}
			cout << endl;
			for (int i = n - 1; i >= 0; i--)
			{
				cout << i + 1 << ' ';
			}
			cout << endl;
			for (int i = 0; i < n; i++)
			{
				cout << i + 1 << ' ';
			}
			cout << endl;
		}
		else
		cout << "NO\n";
	}
	else
		cout << "NO\n";
}
int main()
{
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}