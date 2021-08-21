#include<bits/stdc++.h>
using namespace std;


// Time complexity : O((N*M)*(N+M)) and Space complexity : O(1);
void set_zero(vector<vector<int>> &arr)
{
	int n=arr.size();
	int m=arr[0].size();
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(arr[i][j]==0)
			{
				for(int k=0;k<n;k++)
					if(arr[k][j]!=0)
						arr[k][j]=-1;
				for(int k=0;k<m;k++)
					if(arr[i][k]!=0)
						arr[i][k]=-1;
			}
		}
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(arr[i][j]==-1)
				arr[i][j]=0;
}


// Time complexity : O(N*M) and Space complexity : O(N+M);
void set_zero1(vector<vector<int>> &matrix)
{
	int n=matrix.size();
	int m=matrix[0].size();
	vector<int> row(n,-1);
	vector<int> col(m,-1);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(matrix[i][j]==0)
			{
				row[i]=0;
				col[j]=0;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		if(row[i]==0)
		{
			for(int j=0;j<m;j++)
			{
				matrix[i][j]=0;
			}
		}
	}
	for(int i=0;i<m;i++)
	{
		if(col[i]==0)
		{
			for(int j=0;j<n;j++)
			{
				matrix[j][i]=0;
			}
		}
	}
}


// Time complexity : O(N*M) and Space complexity : O(1);
void set_zero2(vector<vector<int>> &matrix)
{
	int n=matrix.size();
	int m=matrix[0].size();
	bool row=false,col=false;
	for(int i=0;i<n;i++)
	{
		if(matrix[i][0]==0)
			row=true;
	}
	for(int i=0;i<m;i++)
	{
		if(matrix[0][i]==0)
			col=true;
	}
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<m;j++)
		{
			if(matrix[i][j]==0)
			{
				matrix[0][j]=0;
				matrix[i][0]=0;
			}
		}
	}

	for(int i=1;i<n;i++)
	{
		if(matrix[i][0]==0)
		{
			for(int j=1;j<m;j++)
			{
				matrix[i][j]=0;
			}
		}
	}

	for(int i=1;i<m;i++)
	{
		if(matrix[0][i]==0)
		{
			for(int j=1;j<n;j++)
			{
				matrix[j][i]=0;
			}
		}
	}
	if(row==true)
	{
	for(int i=0;i<n;i++)
		matrix[i][0]=0;
	}
	if(col==true)
	{
		for(int i=0;i<m;i++)
			matrix[0][i]=0;
	}
}





void solve()
{
	int n,m;
	cin>>n>>m;
	vector<vector<int>> arr(n,vector<int> (m));
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>arr[i][j];
	set_zero2(arr);
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