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

bool recursion(int index1, int index2, string pattern, string text)
{
    if(index1<0 and index2<0)
    return true;

    if(index1<0)
    return false;

    if(index2<0)
    {
        map<char, int>mp;

        for(int i=0;i<=index1;i++)
        mp[pattern[i]]++;

        if(mp['*']==index1+1)
        return true;

        return false;
    }

    if(pattern[index1]==text[index2] or pattern[index1]=='?')
    return recursion(index1-1, index2-1, pattern, text);

    else if(pattern[index1]=='*')
    {
        return recursion(index1-1, index2, pattern, text)|recursion(index1, index2-1, pattern, text);
    }

    return false;
}


bool topDown(int index1, int index2, string pattern, string text, vector<vector<int>>dp)
{
    if(index1<0 and index2<0)
    return true;

    if(index1<0)
    return false;

    if(index2<0)
    {
        map<char, int>mp;

        for(int i=0;i<=index1;i++)
        mp[pattern[i]]++;

        if(mp['*']==index1+1)
        return true;

        return false;
    }

    if(dp[index1][index2]!=-1)
    return dp[index1][index2];
    
    if(pattern[index1]==text[index2] or pattern[index1]=='?')
    return dp[index1][index2]=topDown(index1-1, index2-1, pattern, text,dp);

    else if(pattern[index1]=='*')
    {
        return dp[index1][index2]=topDown(index1-1, index2, pattern, text,dp)|topDown(index1, index2-1, pattern, text,dp);
    }

    return dp[index1][index2]=false;
}

bool bottomUp (string pattern, string text)
{
    vector<vector<bool>>dp(pattern.size()+1, vector<bool>(text.size()+1, false));

    for(int i=0;i<=pattern.size();i++)
    {
        for(int j=0;j<=text.size();j++)
        {
            if(i==0 and j==0)
            dp[i][j]=true;
            
            else if(i==0 and j>0)
            dp[0][j]=false;

            else if(j==0 and i>0)
            {
                bool flag=true;
                for(int k=1;k<=i;k++)
                {
                    if(pattern[k-1]!='*')
                    flag=false;
                }
                dp[i][0]=flag;
            }
            else if(pattern[i-1]==text[j-1] or pattern[i-1]=='?')
            {
                dp[i][j]=dp[i-1][j-1];
            }

            else if (pattern[i-1]=='*')
            {
                dp[i][j]=(dp[i-1][j]|dp[i][j-1]);
            }

            else 
            dp[i][j]=false;
        }
    }


    for(auto i:dp)
    {
        for(auto j:i)
        cout<<j<<" ";
        cout<<endl;
    }

    return dp[pattern.size()][text.size()];
}

bool wildcardMatching(string pattern, string text)
{
   // Write your code here.
//    vector<vector<int>>dp(pattern.size(), vector<int>(text.size(),-1));
//    return topDown(pattern.size()-1, text.size()-1, pattern, text,dp);
    return bottomUp(pattern, text);
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
        string s,t;
        cin>>s>>t;

        cout<<wildcardMatching(s,t)<<endl;
    }
    return 0;
}