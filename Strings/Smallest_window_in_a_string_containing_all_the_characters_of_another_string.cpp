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

string smallestWindow (string s, string p)
{
    int count =0;
    map<char,ll>mp;

    for(int i=0;i<p.length();i++)
    {
        if(mp[p[i]]==0)
        count ++;

        mp[p[i]]++;
    }

    int res=INT_MAX;
    int start=0;
    int i=0;j=0;

    while(j<s.length())
    {
        mp[s[j]]--;

        if(mp[s[j]]==0)
        count--;
         
        if(count==0)
        {
            while(count==0)
            {
                if(j-i+1<res)
                {
                    res=j-i+1;
                    start=i;
                }

                mp[s[i]]++;
                if(mp[s[i]]==1)
                count++;
            }
        }
        j++;
    }
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
        string s,p;
        cin>>s>>p;

        cout<<smallestWindow(s,p)<<endl;
    }
    return 0;
}