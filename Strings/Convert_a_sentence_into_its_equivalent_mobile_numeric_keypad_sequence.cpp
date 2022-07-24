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

string printSequence(string s)
{
    map<char, string>mp;
    mp['A']="2";
    mp['B']="22";
    mp['c']="222";

    mp['D']="3";
    mp['E']="33";
    mp['F']="333";

    mp['G']="4";
    mp['H']="44";
    mp['I']="444";

    mp['J']="5";
    mp['K']="55";
    mp['L']="555";

    mp['M']="6";
    mp['N']="66";
    mp['O']="666";

    mp['P']="7";
    mp['Q']="77";
    mp['R']="777";
    mp['S']="7777";

    mp['T']="8";
    mp['U']="88";
    mp['V']="888";

    mp['W']="9";
    mp['X']="99";
    mp['Y']="999";
    mp['Z']="9999";

    string ans="";
    for(auto i:s)
    {
        if(i==' ')
        ans+="0";

        else
        ans+=mp[i];
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
    // test()
    {
        ll i,j,n;
        string s;
        getline(cin, s);
        cout<<s<<endl;

        cout<<printSequence(s)<<endl;
    }
    return 0;
}