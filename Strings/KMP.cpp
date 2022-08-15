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

// abcabcd



vector<int> prefix_function(string s)
{
    int n=s.size();

    vector<int>prefix(n,0);

    for(int i=1;i<n;i++)
    {
        int j=prefix[i-1];
        while(j>0 and s[i]!=s[j])
        {
            j=prefix[j-1];
        }

        if(s[i]==s[j])
        {
            j++;
        }

        prefix[i]=j;
    }

    return prefix;
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
        string s="aaa";
        cout<<s<<endl;

        string t="aaaaaaa";

        s+="#";

        s+=t;
        cout<<s<<endl;
        for(auto i:prefix_function(s))
        cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}