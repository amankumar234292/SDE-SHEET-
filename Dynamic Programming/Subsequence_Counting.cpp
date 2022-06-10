#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll              long long int
#define endl            "\n"
#define MOD             1000000007
#define test()          ll t; cin>>t; while(t--)
#define precision(x,y)  fixed<<setprecision(y)<<x
#define ordered_set     tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
 
bool compare(ll a,ll b)
{
    return a<b;
}


int recursion(int index_t, int index_s, string t, string s)
{
    if(index_s<0)
    return 1;

    if(index_t<0)
    return 0;

    if(t[index_t]==s[index_s])
    return recursion(index_t-1, index_s-1, t, s)+recursion(index_t-1, index_s, t, s);

    return recursion(index_t-1,index_s,t, s );
}


int topDown(int index_t, int index_s, string &t, string &s, vector<vector<int>>&dp)
{
    if(index_s<0)
    return 1;

    if(index_t<0)
    return 0;

    if(dp[index_t][index_s]!=-1)
    return dp[index_t][index_s];

    if(t[index_t]==s[index_s])
    return dp[index_t][index_s]= (topDown(index_t-1, index_s-1, t, s,dp)%MOD+topDown(index_t-1, index_s, t, s,dp)%MOD)%MOD;

    return dp[index_t][index_s]=topDown(index_t-1,index_s,t, s,dp )%MOD;
}

int bottomUp(int index_t, int index_s, string &t, string &s)
{
    vector<vector<int>>dp(index_t+1,vector<int>(index_s+1, 0));
    int i,j;
    dp[0][0]=1;
    for(i=1;i<=index_t;i++)
    {
        for(j=0;j<=index_s;j++)
        {
            
            if(j==0)
            dp[i][j]=1;

            else if(i==0)
            dp[i][j]=0;

            else if(s[j-1]==t[i-1])
            dp[i][j]=(dp[i-1][j-1]%MOD+dp[i-1][j]%MOD)%MOD;

            else 
            dp[i][j]=dp[i-1][j];
        }
    }

    // for(auto i:dp)
    // {
    //     for(auto j:i)
    //     cout<<j<<" ";
    //     cout<<endl;
    // }
    // cout<<endl;

    return dp[index_t][index_s];
}

int subsequenceCounting(string &t, string &s, int lt, int ls) {
    // cout<<t<<s<<endl;
    vector<vector<int>>dp(lt, vector<int>(ls, -1));
    return bottomUp(lt, ls, t, s);
} 

int main ()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    test()
    {
        ll i,j,n,m;
        cin>>n>>m;
        string s, t;
        cin>>s>>t;

        cout<<subsequenceCounting(s, t, n,m)<<endl;
    }
    return 0;
}