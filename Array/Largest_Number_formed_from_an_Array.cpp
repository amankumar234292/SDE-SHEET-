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
 
bool compare(string a,string b)
{
    string ab=a+b;
    string ba=b+a;

    return ab>ba;
}

string printLargest(vector<string> &arr) {
    sort(arr.begin(),arr.end(),compare);  

    string ans="";

    for  (auto i:arr)
    cout<<i<<" ";


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
        cin>>n;

        vector<string>v(n);

        for(i=0;i<n;i++)
        {
            cin>>v[i];
        }

        cout<<printLargest(v);
    }
    return 0;
}