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

        vector<vector<ll>>dp(n,vector<ll>(n,0));

        for(ll k=0;k<n;k++)
        {
            if(k==0)
            {
                i=0;
                j=k;
                while(i<n and j<n)
                {
                    dp[i][j]=1;
                    i++;
                    j++;
                }
            }

            else if(k==1)
            {
                i=0;
                j=k;

                while(i<n and j<n)
                {
                    if(s[i]==s[j])
                    dp[i][j]=1;
                    i++;
                    j++;
                }
            }

            else 
            {
                i=0;
                j=k;

                while(i<n and j<n)
                {
                    if(s[i]==s[j] and dp[i+1][j-1]==1)
                    dp[i][j]=1;
                    i++;
                    j++;
                }
            }
        } 

        ll ans=1;

        ll first=0;
        ll second=0;

        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(dp[i][j]==1)
                if(abs(i-j)+1>ans)
                {
                    first=i;
                    second=j;
                    ans=abs(i-j)+1;
                }
            }
        }

        cout<<first<<" "<<second<<endl;
        string fin_ans;

        for(i=first;i<=second;i++)
        fin_ans.push_back(s[i]);
        cout<<fin_ans<<endl;
    }
    return 0;
}