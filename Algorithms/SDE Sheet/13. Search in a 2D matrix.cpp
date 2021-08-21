#include<bits/stdc++.h>
using namespace std;


// One solution can be linear search in matrix. Time Complexity: O(M*N) and Space Complexity : O(1)
// Another solution can be binary search in every row, which will result into Time Complexity : O(nlogm)
bool find(vector<vector<int>> &matrix,int key)
{
	int n=matrix.size();
	int m=matrix[0].size();
	int low=0,high=m-1,mid;
	for(int i=0;i<n;i++)
	{
		low=0,high=m-1;
		while(low<=high)
		{
			mid=(low+high)/2;
			if(matrix[i][mid]==key)
				return 1;
			else if(matrix[i][mid]>key)
				high=mid-1;
			else
				low=mid+1;
		}
	}
	return 0;
}

// Another solution can be reaching at the last element of each row and then check with that element.
bool find1(vector<vector<int>> &matrix,int key)
{
	int n=matrix.size();
	int m=matrix[0].size();
	int low=0,high=m-1,mid,z=m;
	for(int i=0;i<n;i++)
	{
		if(i>=n||z<0)
			return false;
		if(matrix[i][z-1]==key)
			return true;
		else if(matrix[i][z-1]<key)
			continue;
		else if(matrix[i][z-1]>key)
			i--,z--;
	}
	return false;
}

// One solution can be binary searh as a 1-D matrix on this 2-D matrix 
bool find2(vector<vector<int>> &matrix,int key)
{
	int n=matrix.size();
	int m=matrix[0].size();
	int low=0,high=n*m-1,mid,z=m;
	while(low<=high)
	{
		int mid=(low+high)/2;
		int i=mid/n;
		int j=mid%n;
		if(matrix[i][j]==key)
			return true;
		else if(matrix[i][j]>key)
			high=mid-1;
		else
			low=mid+1;
	}
	return false;
}

void solve()
{
	int n,m,key;
	cin>>n>>m;
	vector<vector<int>> matrix(n,vector<int> (m));
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>matrix[i][j];
	cin>>key;
	bool ans=find2(matrix,key);
	if(ans==false)
		cout<<"Not found"<<endl;
	else
		cout<<"Found"<<endl;
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