#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const ll N = 1e7+7;
vector<ll> a;

void PrimeFactorization(ll n){
	//O(sqrt(n))
	for(ll i=2;i*i<=n;i++){
    	while(n%i==0){
    		a.push_back(i);
    		n/=i;
		}
	}
	if(n>1){
		a.push_back(n);
	}
}

//Totient Function(Number Theory) - a single integer
void totient(ll n){
	ll cnt=n;
    for(ll i=2;i*i<=n;i++){
    	if(n%i==0){
    		while(n%i==0){
    			n/=i;
			}
		cnt-=cnt/i;
		}
	}
	if(n>1){
		cnt-=cnt/n;
	}
}

//Totient Function(Number Theory) - Array integer
void totient(){
	vector<ll> phi(N);
	iota(phi.begin(), phi.end(), 0);
	for(ll i=2;i<N;i++){
		if(phi[i]==i){
			for(ll j=i;j<N;j+=i){
				phi[j]-=(phi[j]/i);
			}
		}
	}
	ll n;
	cin>>n;
	for(ll i=0;i<n;i++){
		ll p;
		cin>>p;
		cout<<phi[p]<<"\n";
	}
}


vector<ll> lpf(N);
void LeastCommonFactorization(ll n){
	//O(nlog(n))
	for(ll i=2;i<N;i++){
        if(lpf[i]==0){
            lpf[i]=i;
            for(ll j=2*i;j<N;j+=i){
                if(lpf[j]==0){
                    lpf[j]=i;
                }
            }
        }
    }
}

vector<ll> gpf(N);
void GreatestCommonFactorization(){
	for(ll i=2;i<N;i++){
        if(lpf[i]==0){
            lpf[i]=i;
            for(ll j=2*i;j<N;j+=i){
                    gpf[j]=i;
            }
        }
    }
}

vector<ll> prime(N, 1);
void isPrime(){
	//O(nlog(n))
	prime[0]=prime[1]=0;
	for(ll i=2;i<N;i++){
		for(ll j=2*i;j<N;j+=i){
			prime[j]=0;
		}
	}
}

bool is_prime(ll n){
	if(n<2){
		return false;
	}
	for(ll i=2;i*i<=n;i++){
		if(n%i==0){
			return false;
		}
	}
	return true;
}


// binary search
	ll low=0, high=a[n-1]-a[0];
	ll ans=0;
	while(low<=high){
		ll mid=(low+high)/2;
		ll cnt=1;
		ll idx=a[0];
		for(ll i=1;i<n && cnt<k;i++){
			if(a[i]-idx>=mid){
				cnt++;
				idx=a[i];
			}
		}
		if(cnt>=k){
			ans=mid;
			low=mid+1;
		}
		else{
			high=mid-1;
		}
	}
	

void solve(){
    ll n;
    cin>>n;
    cout<<n<<" ";
    cout<<"\n";

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


