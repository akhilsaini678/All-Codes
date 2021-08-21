#include<bits/stdc++.h>
using namespace std;

// Time complexity : O(N*M) and Space complexity : O(1);
void set_zero(vector<vector<int>> &matrix)
{
	for(int i=0;i<matrix.size();i++)
		for(int j=i;j<matrix[i].size();j++)
			swap(matrix[i][j],matrix[j][i]);

	for(int i=0;i<matrix.size();i++)
		reverse(matrix[i].begin(),matrix[i].end());
}


void solve()
{
	int n,m;
	cin>>n>>m;
	vector<vector<int>> arr(n,vector<int> (m));
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>arr[i][j];
	set_zero(arr);
	for(int i=0;i<n;i++) { for(int j=0;j<m;j++) cout<<arr[i][j]<<" "; cout<<endl; }
	cout<<endl;
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