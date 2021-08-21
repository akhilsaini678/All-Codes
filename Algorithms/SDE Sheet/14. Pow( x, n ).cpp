#include<bits/stdc++.h>
using namespace std;


// Time Complexity : O(n) and Space Complexity : O(1)
long long int power_brute(long long int x,long long int n)
{
	long long int ans=1;
	for(int i=0;i<n;i++)
	{
		ans=ans*x;
	}
	return ans;
}

// Time Complexity : O(log(n)) and Space Complexity : O(1)
// Recursive function
long long int power(long long int x,long long int n)
{
	if(n==0) return 1;
	return (n%2==0)? power(x*x,n/2): power(x,n-1)*x;		
}

// Time Complexity : O(log(n)) and Space Complexity : O(1)
// Iterative function
long long int power_it(long long int x,long long int n)
{
	long long int ans=1;
	while(n>0)
	{
		if(n%2==0)
		{
			x=x*x;
			n=n/2;
		}
		else
		{
			ans=ans*x;
			n--;
		}
	}
	return ans;
}

void solve()
{
	long long int n,m,x,answer=0;
	cin>>x>>n;
	if(n<0)
		n=-1*n;
	answer=power_it(x,n);
	cout<<answer<<endl;
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