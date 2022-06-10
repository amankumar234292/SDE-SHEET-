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


int recursion (int index1, int index2, string s1, string s2)
{
    if(index1<0)
    return index2+1;


    if(index2<0)
    return index1+1;

    if(s1[index1]==s2[index2])
    return recursion(index1-1, index2-1, s1,s2);

    int insert=1+recursion(index1, index2-1, s1,s2);
    int delet=1+recursion(index1-1, index2, s1,s2);
    int replace =1+recursion(index1-1, index2-1 , s1,s2);

    return min({insert, delet, replace});
}

int topDown (int index1, int index2, string &s1, string &s2, vector<vector<int>>&dp)
{
    if(index1<0)
    return index2+1;


    if(index2<0)
    return index1+1;

    if(dp[index1][index2]!=-1)
    return dp[index1][index2];

    if(s1[index1]==s2[index2])
    return dp[index1][index2]=topDown(index1-1, index2-1, s1,s2,dp);

    int insert=1+topDown(index1, index2-1, s1,s2,dp);
    int delet=1+topDown(index1-1, index2, s1,s2,dp);
    int replace =1+topDown(index1-1, index2-1 , s1,s2,dp);

    return dp[index1][index2]=min({insert, delet, replace});
}

int bottomUp(string s1, string s2)
{
    vector<vector<int>>dp(s1.size()+1, vector<int>(s2.size()+1,0));

    for(int i=0;i<=s1.size();i++)
    {
        for(int j=0;j<=s2.size();j++)
        {
            if(i==0 and j==0)
            dp[i][j]=0;

            else if(i==0)
            {
                dp[i][j]=j;
            }

            else if(j==0)
            {
                dp[i][j]=i;
            }

            else 
            {
                if(s1[i-1]==s2[j-1])
                dp[i][j]=dp[i-1][j-1];

                else 
                {
                    dp[i][j]=1+min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
                }
            }
        }
    }

    // for(auto i:dp)
    // {
    //     for(auto j:i)
    //     cout<<j<<" ";
    //     cout<<endl;
    // }

    return dp[s1.size()][s2.size()];
}


int editDistance(string str1, string str2)
{
    vector<vector<int>>dp(str1.size(),vector<int>(str2.size(),-1));
    // return topDown(str1.size()-1, str2.size()-1, str1,str2,dp);

    return bottomUp(str1,str2);

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
        string s1,s2;
        cin>>s1>>s2;

        cout<<editDistance(s1,s2)<<endl; 
    }
    return 0;
}