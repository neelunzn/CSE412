#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const ll N = 1e9+7;
const ll MOD=1e9+7;

ll coin(ll n, ll m, ll k, ll w, vector<ll> a, vector<ll> b){
	vector<vector<ll>> dp(n+1, vector<ll>(w+1, 0));
	vector<vector<ll>> dp1(m+1, vector<ll>(w+1, 0));
	dp[n][0]=dp1[m][0]=1;
	for(ll i=n-1;i>=0;i--){
		for(ll j=0;j<=w;j++){
			dp[i][j]=dp[i+1][j]%MOD;
			if(a[i]<=j){
				dp[i][j]=(dp[i][j]+dp[i+1][j-a[i]])%MOD;
			}
		}
	}
	for(ll i=m-1;i>=0;i--){
		for(ll j=0;j<=w;j++){
			dp1[i][j]=dp1[i+1][j]%MOD;
			if(b[i]<=j){
				dp1[i][j]=(dp1[i][j]+dp1[i+1][j-b[i]])%MOD;
			}
		}
	}
	ll cnt=0;
	for(ll i=0;i<=w;i++){
		for(ll j=0;j<=w;j++){
			if(abs(i-j)<=k && i+j==w){
				cnt=(cnt+(ll)dp[0][i]*dp1[0][j])%MOD;
			}
		}
	}
	return cnt;
}

void solve(){
	ll n, m, k, w;
	cin>>n>>m>>k>>w;
	vector<ll> a(n), b(m);
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	for(ll i=0;i<m;i++){
		cin>>b[i];
	}
	cout<<coin(n, m, k, w, a, b)<<"\n";
}


int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
}



