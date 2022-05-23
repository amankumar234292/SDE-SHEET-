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

// class node
// {
//     public:
//     ll data;
//     node*next;

//     node(int d)
//     {
//         data=d;
//         next=NULL;
//     }
// };

// void solve(node*&head, ll num)
// {
//     node*temp=head;
//     node*prev=NULL;
//     ll carry =0;

//     while(temp!=NULL)
//     {
//         ll multi=(temp->data)*num+carry;
//         temp->data=multi%10;
//         carry=multi/10;
//         prev=temp;
//         temp=temp->next;
//     }

//     while(carry>0)
//     {
//         node*n=new node(carry%10);
//         n->next=NULL;
//         prev->next=n;
//         carry=carry/10;
//         prev=prev->next;
//     }
// }



// void print(node*head)
// {
//     if(head==NULL)
//     return;

//     print(head->next);
//     cout<<head->data;
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
//         ll i,j,n;
//         cin>>n;

//         node*head=new node(1);

//         for(i=1;i<=n;i++)
//         {
//             solve(head,i);
//         }

//         // cout<<head->data<<endl;

//         print(head);
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
    // test()
    {
        ll i,j,n;
        cin>>n;
        vector<ll>v(n);

    }
    return 0;
}