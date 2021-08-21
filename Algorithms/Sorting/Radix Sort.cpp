#include<bits/stdc++.h>
using namespace std;


void counting_sort(vector<int> &arr,int exp)
{
	int n=arr.size();
	vector<int> output(n),count(10,0); // output array

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i <=9; i++)
        count[i]+=count[i-1];

    for(int i=n-1;i>=0;i--)
    {
    	output[count[(arr[i]/exp)%10]-1]=arr[i];
    	count[(arr[i]/exp)%10]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radix_sort(vector<int> &arr)
{
	int n=arr.size(),maxi=-1;
	for(int i=0;i<n;i++) maxi=max(arr[i],maxi);

	for (int exp = 1; maxi / exp > 0; exp *= 10)
        counting_sort(arr, exp);
}


void solve()
{
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++) cin>>arr[i];
	radix_sort(arr);
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