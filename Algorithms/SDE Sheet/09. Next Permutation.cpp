#include<bits/stdc++.h>
using namespace std;


// Time complexity : O(n) and Space complexity : O(1);
void next_permutation(vector<int> &arr)
{
	int index=-1;
	int n=arr.size();
	for(int i=n-1;i>=1;i--)
	{
		if(arr[i]>arr[i-1])
		{
			index=i-1;
			break;
		}
	}
    
    if(index==-1)
    {
        for(int i=0;i<n/2;i++)
            swap(arr[i],arr[n-i-1]);
        return;
    } 

	for(int i=n-1;i>=1;i--)
	{
		if(arr[index]<arr[i])
		{
			swap(arr[index],arr[i]);
			break;
		}
	}

	int j=1;
	// cout<<index<<endl;
	for(int i=index+1;i<n;i++)
	{
		swap(arr[i],arr[n-j++]);
        if(i>=n-j)
			break;
	}
}




void solve()
{
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++) cin>>arr[i];
	next_permutation(arr);
	for(int i=0;i<n;i++) cout<<arr[i]<<" ";
	cout<<endl;
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
Input :
1
6
1 2 3 6 5 4
Output :
1 2 4 3 5 6
*/