#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const ll N = 2e5+7;
const ll mod=1e9+7;
ll seg[4*N]={0}, a[N];

void build(ll ind, ll low, ll high){
	if(low==high){
		seg[ind]=0;
		return;
	}
	ll mid=(low+high)/2;
	build(2*ind, low, mid);
	build(2*ind+1, mid+1, high);
	seg[ind]=0;
}

ll query(ll ind, ll low, ll high, ll l, ll r){
	if(low>=l && high<=r){
		return seg[ind];
	}
	if(high<l || low>r){
		return LLONG_MIN;
	}
	ll mid=(low+high)/2;
	ll left=query(2*ind, low, mid, l, r);
	ll right=query(2*ind+1, mid+1, high, l, r);
	return max(left, right);
}

void update(ll pos, ll val, ll ind, ll low, ll high){
	if(low==high){
		seg[ind]=val;
		return;
	}
	ll mid=(low+high)/2;
	if(pos<=mid){
		update(pos, val, 2*ind, low, mid);
	}
	else{
		update(pos, val, 2*ind+1, mid+1, high);
	}
	seg[ind]=max(seg[2*ind], seg[2*ind+1]);
}

ll lis(vector<ll> a, ll n){
	ll lis[n+1]={0};
	for(ll i=1;i<=n;i++){
		ll mx=query(1, 1, N, 1, a[i]-1);
		lis[i]=mx+1;
		update(a[i], lis[i], 1, 1, N);
	}
	ll mxlis=*max_element(lis+1, lis+n+1);
	return mxlis;
}

void solve(){
    ll n;
	cin>>n;
    vector<ll> a(n);
    for(ll i=0;i<n;i++){
    	cin>>a[i];
	}
	build(1, 1, N);
	ll ans=lis(a, n);
	cout<<ans<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}
