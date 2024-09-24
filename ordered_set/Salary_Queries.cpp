#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template <typename T>
using oset = tree<T, null_type, less<T>,rb_tree_tag, tree_order_statistics_node_update>;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define ok cout<<"ok"<<endl;
#define endl '\n'
#define LLONG_MAX 1e16
const ll M =1e9+7;
const ll N =1e5+1;
void debug(vector<ll>&v){for(auto it:v){cout<<it<<" ";}cout<<endl;}
ll n,m;
oset<pair<ll,ll>>st;
int32_t main()
{
    fast
    ll i,j=1,k=1,p,q,tc=1,cs=0;//cin>>tc;
    while(tc--)
    {
        cin>>n>>q;
        vector<ll>v(n+1);
        for(i=1;i<=n;i++)
        {
            cin>>k;
            v[i]=k;
            st.insert({k,i});
        }
        while(q--)
        {
            char c;
            ll x,y;
            cin>>c>>x>>y;
            if(c=='?')
            {
                cout<<st.order_of_key({y,INT_MAX})-st.order_of_key({x,0})<<endl;
            }
            else
            {
                st.erase({v[x],x});
                v[x]=y;
                st.insert({y,x});
            }
        }
    }
}
/*
Order of key methods on ordered set returns the position of the element that you are searching for or the element that is immediately greater than it.
Also, comparison in pairs compares the first value first and if they're equal the result will depend on the second value.
Considering that, if we searched for (a,0) at first we'll get the position of the first value where a is at the first value - regardless of its index at the original array.
And if we searched for (b,inf), as there are no b values whose index is infinity or larger, we'll just get the position of the element immediately greater than b.
*/
