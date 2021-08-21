#include<bits/stdc++.h>
using namespace std;


// Time complexity : O(n^2) and Space complexity : O(n^2);
void pascal_triangle(int n)
{
	vector<vector<int>> arr(n);
	for(int i=0;i<n;i++)
	{
		arr[i].resize(i+1);
		arr[i][0]=arr[i][i]=1;
		for(int j=1;j<=i-1;j++)
		{
			arr[i][j]=arr[i-1][j-1]+arr[i-1][j];
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<arr[i].size();j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}

// Time complexity : O(N) and Space complexity : O(N);
void pascal_triangle1(int n)
{
	int up=n-1;
	int down=1;
	vector<int> arr(n);
	arr[0]=1;
	for(int i=1;i<n;i++)
	{
		arr[i]=(arr[i-1]*up--)/down++;
	}
	for(int i=0;i<n;i++) cout<<arr[i]<<" ";
	cout<<endl;
}


void solve()
{
	int n;
	cin>>n;
	pascal_triangle(n);
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