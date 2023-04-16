#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include "shoes.h"
using namespace std;
#define ll long long

bool bl[1005];
vector<pair<int, int>>y;
long long count_swaps(std::vector<int> v)
{
	int n = v.size();
	//cout << n << endl << endl;
	int res = 0;
	if (n == 1)
	{
		return (v[0] < 0);
	}
	else if (n <= 1000)
	{
		set<pair<int, int>>st;
		for (int i = n - 1; i >= 0; i--)
		{
			if (bl[i])
				continue;
			bl[i] = true;
			pair<int, int>p;
			p.second = i;
			for (int j = i - 1; j >= 0; j--)
			{
				if (v[i] == -v[j])
				{
					p.first = j;
					if (v[i] < 0)
					{
						res++;
					}
					bl[j] = true;
					break;
				}
				res++;
			}
			//cout << res << endl;
			for (set<pair<int, int>>::iterator it = st.begin(); it != st.end(); it++)
			{
				pair<int, int>u = *it;
				if (u.first < p.first && p.first < u.second && u.second < p.second)
				{
					res--;
				}
			}
			st.insert(p);
		}
		return res;
		//cout << res << endl;
	}
	else return 0;
}