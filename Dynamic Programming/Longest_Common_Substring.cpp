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

int lcs(string &str1, string &str2){

    vector<vector<int>>dp(str1.size()+1,vector<int>(str2.size()+1,0));

    for(int i=1;i<=str1.size();i++)
    {
        for(int j=1;j<=str2.size();j++)
        {
            if(str1[i-1]==str2[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1]++;
            }

            else 
            dp[i][j]=0;
        }
    }

    // for(auto i:dp)
    // {
    //     for(auto j:i)
    //     cout<<j<<" ";
    //     cout<<endl;
    // }

    int maxi=INT_MIN;

    for(int i=0;i<=str1.size();i++)
    maxi=max(maxi, *max_element(dp[i].begin(),dp[i].end()));
    

    return maxi;
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
        ll i,j,n;
        string s1,s2;
        cin>>s1>>s2;

        cout<<lcs(s1,s2)<<endl;
    }
    return 0;
}