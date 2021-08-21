/*
 Akhil Saini
*/
#include <bits/stdc++.h>
using namespace std;
#define fs(a,b)            for(i=a;i<b;i++)
#define fsi(i,a,b)         for(i=a;i<b;i++)
#define fe(a,b)            for(i=a-1;i>=b;i--)
#define fit(v)             for(auto itr=v.begin();itr!=v.end();itr++)
#define all(v)             v.begin(),v.end()
#define allr(v)            v.rbegin(),v.rend()
#define ump(a,b)           unordered_map<a,b>
#define ll                 long long int
#define endl               "\n"
#define fir                first
#define sec                second
#define mp                 make_pair
#define pb                 push_back
#define bp                 __builtin_popcount
#define bit(x)              bitset<62>(x).to_string()
#define binstr_to_num(x)   stoll(x,nullptr,2)
#define debug              cout<<"Hello"<<endl
#define debug1(a)          cout<<#a<<"="<<(a)<<"\n"
typedef                    vector<ll> vll;
const                      double pi=acos(-1.0);
const                      ll inf = 1e18+1 , mod=1e9+7;


void solve()
{
    debug;
}


void fast()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("C:\\Data\\Online\\Coding\\Contest\\input.txt","r",stdin);
    freopen("C:\\Data\\Online\\Coding\\Contest\\output.txt","w",stdout);
    #endif
}

int32_t main()
{
    fast();
    int t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}