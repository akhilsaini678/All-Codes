#include<bits/stdc++.h>
using namespace std;


bool cmp(int a ,int b)
{
	if(a%2==0&&b%2==0)
	{
		if(a%5==0&&b%5==0)
			return a<b;
		else if(a%5==0)
			return true;
		return false;
	}
	else if(a%2==0&&b%2==0)
	{
		return a<b;
	}
	else if(a%2==0)
	{
		return true;
	}
	return false;
}


void solve()
{
	int n,m,u;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++) cin>>v[i];
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<n;i++) cout<<v[i]<<" ";
}

void fast()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("D:\\Online\\Coding\\Contest\\input.txt","r",stdin);
	freopen("D:\\Online\\Coding\\Contest\\output.txt","w",stdout);
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