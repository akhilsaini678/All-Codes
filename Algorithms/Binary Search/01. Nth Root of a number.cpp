#include<bits/stdc++.h>
#define
using namespace std;

void solve()
{
	int n,m;
	cin>>n>>m;
	nth_root(n,m);
}

void fast()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("C:\\Data\\Online\\Coding\\Contest\\input.txt","r",stdin);
    freopen("C:\\Data\\Online\\Coding\\Contest\\output.txt","w",stdout);
    #endif
}

int main()
{
	fast();
	int t=1;
	cin>>t;
	while(t--) solve();
	return 0;
}