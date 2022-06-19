// // #include <bits/stdc++.h>
// // #include<ext/pb_ds/assoc_container.hpp>
// // #include<ext/pb_ds/tree_policy.hpp>
// // using namespace std;
// // using namespace __gnu_pbds;
// // #define ll              long long int
// // #define endl            "\n"
// // #define MOD             1e9 + 7
// // #define test()          ll t; cin>>t; while(t--)
// // #define precision(x,y)  fixed<<setprecision(y)<<x
// // #define ordered_set     tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
 
// // bool compare(ll a,ll b)
// // {
// //     return a<b;
// // }
// // int recursion(int index, int prev, vector<int>arr, vector<int>&ans)
// // {
// //     if(index>=arr.size())
// //     {
// //         ans.clear();
// //         return 0;
// //     }

// //     int notPick=recursion(index+1, prev, arr, ans);
// //     int pick=0;
// //     if(prev==-1 or arr[index]%ans.back()==0)
// //     {
// //         ans.push_back(arr[index]);
// //         pick=1+recursion(index+1, index, arr, ans);
// //     }

// //     return max(pick, notPick);
// // }

// // vector<int> divisibleSet(vector<int> &arr){
// //     // Write your code here.
// //     vector<int>ans;
// //     sort(arr.begin(),arr.end());

// //     recursion(0, -1, arr, ans);

// //     return ans;
// // }

// // int main ()
// // {
// // #ifndef ONLINE_JUDGE
// //     freopen("input.txt","r",stdin);
// //     freopen("output.txt","w",stdout);
// // #endif
// //     ios_base::sync_with_stdio(false);
// //     cin.tie(NULL);  
// //     test()
// //     {
// //         ll i,j,n;
// //         cin>>n;

// //         vector<int>v(n);

// //         for(i=0;i<n;i++)
// //         cin>>v[i];

// //         for(auto i:divisibleSet(v))
// //         cout<<i<<" ";
// //         cout<<endl;
// //     }
// //     return 0;
// // }



// #include <bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// using namespace std;
// using namespace __gnu_pbds;
// #define ll              long long int
// #define endl            "\n"
// #define MOD             1e9 + 7
// #define test()          ll t; cin>>t; while(t--)
// #define precision(x,y)  fixed<<setprecision(y)<<x
// #define ordered_set     tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
 
// bool compare(ll a,ll b)
// {
//     return a<b;
// }

// ll solve(vector<ll>v, ll b)
// {
//     priority_queue<ll, vector<ll>, greater<ll>>pq;
//     ll i;
//     for(i=0;i<v.size();i++)
//     {
//         pq.push(v[i]);
//     }

//     ll ans=0;

//     while(b-- or !pq.empty())
//     {
//         if(pq.size()==1)
//         break;
//         ll f=pq.top();
//         pq.pop();

//         ll s=pq.top();
//         pq.pop();

//         pq.push(f+s);

//         ans+=min(f,s);
//     }

//     return ans;
// }

// int main ()
// {
// #ifndef ONLINE_JUDGE
//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);
// #endif
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);  
//     // test()
//     {
//         ll i,j,n,a,b;
//         cin>>a>>b;

//         vector<ll>v(a);
//         for(i=0;i<n;i++)
//         cin>>v[i];

//         cout<<solve(v,b)<<endl;
//     }
//     return 0;
// }



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
    test()
    {
        ll i,j,n;
        string s,prev;
        cin>>s;

        ll c=s.length();

        while(c--)
        {
            for(i=1;i<s.length();i++)
            {
                if(s[i]==s[i-1])
                {
                    s[i]='&';
                    s[i-1]='&';
                }
            }

            prev="";
            for(i=0;i<s.length();i++)
            {
                if(s[i]!='&')
                prev+=s[i];
            }

            s.clear();
            s=prev;
        }

        cout<<s<<endl;
    }
    return 0;
}