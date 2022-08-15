#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll              long long int
#define endl            "\n"
#define mod             1000000007
#define test()          ll t; cin>>t; while(t--)
#define precision(x,y)  fixed<<setprecision(y)<<x
#define ordered_set     tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
 
bool compare(ll a,ll b)
{
    return a<b;
}

long long int  countPS(string str)
{
    vector<vector<ll>>dp(str.length(),vector<ll>(str.length(),0));

   
    for(ll i=0;i<str.length();i++)
    {
        ll col=i;
        ll row=0;
        while(row<str.length() and col<str.length())
        {
            if(i==0)
            dp[row][col]=1;

            else 
            {
                if(str[row]==str[col])
                dp[row][col]=(dp[row+1][col]+dp[row][col-1]+1);

                else 
                dp[row][col]=(dp[row+1][col]+dp[row][col-1]-dp[row+1][col-1]);
            }
            
            dp[row][col]+=mod;
            dp[row][col]=dp[row][col]%mod;

            row++;
            col++;
        }
    }


    // for(auto i:dp)
    // {
    //     for(auto j:i)
    //     cout<<j<<" ";
    //     cout<<endl;
    // }

    return dp[0][str.length()-1]%mod;
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

        cout<<countPS(s);
    }
    return 0;
}