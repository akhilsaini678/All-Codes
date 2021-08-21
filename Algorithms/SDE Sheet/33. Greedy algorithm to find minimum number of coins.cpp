#include<bits/stdc++.h>
using namespace std;


// Time Complexity : O(n) and Space Complexity : O(1)
int minimum_coin(int change,vector<int> coins)
{
	int ans=0;
	for(int i=coins.size()-1;i>=0;i--)
	{
		if(coins[i]<=change)
		{
			ans=ans+change/coins[i];
			change=change%coins[i];
		}
	}
	return ans;
}



void solve()
{
	int n,a,b,c;
	cin>>n;
	vector<int> coins = {1,2,5,10,20,50,100,500,1000};
	cout<<minimum_coin(n,coins)<<endl;
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

/*
Test Case :
2
70
121

Answer :
2
3
*/