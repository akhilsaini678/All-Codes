#include<bits/stdc++.h>
using namespace std;

bool is_safe(int row,int col,char val,vector<vector<char>> &arr,int n)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i][col]==val)
            return false;
           
        if(arr[row][i]==val)
            return false;
    }

    for(int i=3*(row/3);i<(3*(row/3))+3;i++)
    {
        for(int j=3*(col/3);j<(3*(col/3)+3);j++)
        {
            if(arr[i][j]==val)
                return false;
        }
    }

    return true;
}



bool Sudoko(int n,vector<vector<char>> &arr)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[i][j]=='.')
            {
                for(char k='1';k<='9';k++)
                {
                    if(is_safe(i,j,k,arr,n))
                    {
                        arr[i][j]=k;
                        if(Sudoko(n,arr)==true)
                            return true;
                        else
                        arr[i][j]='.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solve()
{
    int n=9;
    vector<vector<char>> arr(n,vector<char> (n,'.'));
    Sudoko(n,arr);
    for(int i=0;i<arr.size();i++)
    {
        for(int j=0;j<arr[i].size();j++)
        {
            cout<<arr[i][j]<<" ";
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