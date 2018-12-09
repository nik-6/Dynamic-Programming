#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t; cin >> t;
	while(t--)
	{
		int a[100],ans;
	vector<pair<int,int>> v;
	int n; cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	int mn = 9999,mx = -1,mni,mxi;
	bool togg = true;
	for (int i = 0; i < n; ++i)
	{
		if(togg)
		{
			if(a[i] <= mn)
			{
				mn = a[i];
				mni = i;
			}
			else
			{
				togg = !togg;
				mx = a[i];
				mxi = i;
				if(i == n-1)
				{
					ans += mx - mn;
					v.push_back(make_pair(mni,mxi));
				}
			}
		}
		else
		{
			if(a[i] >= mx)
			{
				mx = a[i];
				mxi = i;
				if(i == n-1) {ans += mx-mn; v.push_back(make_pair(mni,mxi));}
			}
			else
			{
				ans += mx-mn;
				v.push_back(make_pair(mni,mxi));
				togg = !togg;
				mn = a[i];
				mni = i;
			}
		}
	}
	if(v.size() != 0)
	{for(auto it : v){cout << '(' << it.first << " " << it.second << ") ";}cout << endl;}
	else cout << "No Profit" << endl;
	}
	return 0;
}