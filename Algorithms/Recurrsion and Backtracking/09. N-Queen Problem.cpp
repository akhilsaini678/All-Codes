#include<bits/stdc++.h>
using namespace std;

bool is_safe(int row,int col,vector<string> &arr,int n)
{
	int a=row;
	int b=col;

	while(row>=0&&col>=0)
	{
		if(arr[row][col]=='Q') return false;
		row--,col--;
	}
	row=a,col=b;
	while(row>=0)
	{
		if(arr[row][col]=='Q') return false;
		row--;
	}
	row=a,col=b;
	while(row>=0&&col<n)
	{
		if(arr[row][col]=='Q') return false;
		row--,col++;
	}
	return true;
}



void N_Queen(int row,int n,vector<string> &arr,vector<vector<string>> &ans)
{
	if(row==n)
	{
		ans.push_back(arr);
		return;
	}

	for(int col=0;col<n;col++)
	{
		if(is_safe(row,col,arr,n))
		{
			arr[row][col]='Q';
			N_Queen(row+1,n,arr,ans);
			arr[row][col]='.';
		}
	}
}
       

void solve()
{
	int n;
	cin>>n;
	string str="";
    for(int i=0;i<n;i++) str=str+'.';
	vector<string> arr(n,str);
	vector<vector<string>> ans;
    N_Queen(0,n,arr,ans);
	for(int i=0;i<ans.size();i++)
	{
		for(int j=0;j<ans[i].size();j++)
		{
			cout<<ans[i][j]<<endl;
		}
		cout<<endl;
	}
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


/*
Test Case :
1
4

Answer :
.Q..
...Q
Q...
..Q.
..Q.
Q...
...Q
.Q..

*/