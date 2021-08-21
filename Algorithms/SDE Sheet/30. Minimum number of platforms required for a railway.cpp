#include<bits/stdc++.h>
using namespace std;


// Time Complexity : O(nlogn) and Space Complexity : O(n)
int platform(vector<int> &first,vector<int> &second)
{
	sort(first.begin(),first.end());
	sort(second.begin(),second.end());
	int n=first.size();
	int ans=0,platforms=0,j=0;
	for(int i=0;i<n;i++)
	{
		if(first[i]<=second[j])
			platforms++;
		else
		{
			while(first[i]>second[j])
			{
				j++;
				platforms--;
			}
			platforms++;
		}
		ans=max(ans,platforms);
	}
	return ans;
}



void solve()
{
	int n;
	cin>>n;
	vector<int> first(n),second(n);
	for(int i=0;i<n;i++)
		cin>>first[i];
	for(int i=0;i<n;i++)
		cin>>second[i];
	
	cout<<platform(first,second)<<endl;
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
1
6
0900 0940 0950 1100 1500 1800
0910 1200 1120 1130 1900 2000

Answer :
3
*/