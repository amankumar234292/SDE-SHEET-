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

string removeConsecutiveCharacter(string s){
    int i=0,j=1,k,n=s.length();

    while(j<n and i<n)
    {
        if(s[i]==s[j])
        {
            s[j]='&';
            j++;
        }

        else 
        {
            i=j;
            j++;
        }
    }

    string ans;
    for(auto i:s)
    {
        if(i!='&')
        ans+=i;
    }
    return ans;
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
        // cin>>n;

        string s;
        cin>>s;

        cout<<removeConsecutiveCharacter(s);
    }
    return 0;
}