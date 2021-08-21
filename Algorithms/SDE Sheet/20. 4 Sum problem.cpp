#include<bits/stdc++.h>
using namespace std;


// One way can be using 3 pointer and then binary searching in the remaining array , Time complexity : O(n^3logn)
// Time Complexity : O(n^3) and Space Complexity : O(1)
vector<vector<int>> four_sum(vector<int> &arr,int target)
{
	vector<vector<int>> ans;
	int n=arr.size();
	int sum=0;
	sort(arr.begin(),arr.end());
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			sum=target-(arr[i]+arr[j]);

			int left=j+1;
			int right=n-1;
			while(left<right)
			{
				int sum1=arr[left]+arr[right];
				if(sum>sum1) left++;
				else if(sum<sum1) right--;
				else
				{
					vector<int> tmp = {arr[i],arr[j],arr[left],arr[right]};
					ans.push_back(tmp);
					while(left<right&&arr[left]==tmp[2]) left++;
					while(left<right&&arr[right]==tmp[3]) right--;
				}
			}
			while(j+1<n&&arr[j]==arr[j+1]) j++;
		}
		while(i+1<n&&arr[i]==arr[i+1]) i++;
	}
	return ans;
}


void solve()
{
	int n,target;
	cin>>n;
	vector<vector<int>> ans;
	vector<int> arr(n);
	for(int i=0;i<n;i++) cin>>arr[i];
	cin>>target;
	ans= four_sum(arr,target);
	for(int i=0;i<ans.size();i++)
	{
		for(int j=0;j<4;j++)
		{
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
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