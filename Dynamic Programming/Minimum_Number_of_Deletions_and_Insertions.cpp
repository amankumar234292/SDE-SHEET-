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


int recursion(int index1, int index2, string s1, string s2)
{
    if(index1<0 or index2<0)
    return 0;

    if(s1[index1]==s2[index2])
    return 1+recursion(index1-1, index2-1, s1, s2);

    return max(recursion(index1-1, index2, s1, s2), recursion(index1,index2-1, s1, s2));
}

int topDown(int index1, int index2, string &s1, string &s2,vector<vector<int>>&dp)
{
    if(index1<0 or index2<0)
    return 0;

    if(dp[index1][index2]!=-1)
    return dp[index1][index2];

    if(s1[index1]==s2[index2])
    return dp[index1][index2]=1+topDown(index1-1, index2-1, s1, s2,dp);

    return dp[index1][index2]=max(topDown(index1-1, index2, s1, s2,dp), topDown(index1,index2-1, s1, s2,dp));
}


int  bottomUp(string s1, string s2)
{
    vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,0));
    int i,j;

    // dp[0][0]=1;

    for(i=1;i<=s1.size();i++)
    {
        for(j=1;j<=s2.size();j++)
        {
            if(s1[i-1]==s2[j-1])
            dp[i][j]=1+dp[i-1][j-1];

            else 
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }

    return dp[s1.size()][s2.size()];
}

int canYouMake(string &str, string &ptr)
{
    int x=bottomUp(str, ptr);
    int n=str.length();
    int m=ptr.length();
   return abs(x-n)+abs(x-m);
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
        string s1, s2;
        cin>>s1>>s2;

        cout<<canYouMake(s1,s2)<<endl;
    }
    return 0;
}