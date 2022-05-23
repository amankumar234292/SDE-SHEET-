#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll              long long int
#define endl            "\n"
#define MOD             1e9 + 7
#define test()          ll t; cin>>t; while(t--)
#define precision(x,y)  fixed<<setprecision(y)<<x
#define ordered_set     tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
 
bool compare(ll a,ll b)
{
    return a<b;
}

int main ()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    // test()
    {
        ll i,j,n;
        string s;
        cin>>s;

        n=s.length();

        vector<vector<ll>>dp(n+1,vector<ll>(n+1,0));

        for(i=0;i<=n;i++)
        {
            for(j=0;j<=n;j++)
            {
                if(i==0 or j==0)
                dp[i][j]=0;

                else 
                {
                    if(s[i-1]==s[j-1] and i!=j)
                    dp[i][j]=dp[i-1][j-1]+1;
                    
                    else 
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

                }
            }
        }

        for(auto i:dp){
            for(auto j:i)
            cout<<j<<" ";
            cout<<endl;
        }

        cout<<dp[n][n]<<endl;
    }
    return 0;
}