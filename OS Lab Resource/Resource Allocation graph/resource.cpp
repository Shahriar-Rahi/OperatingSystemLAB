#include<bits/stdc++.h>

using namespace std;

#define endl "\n"
#define _ <<" "<<
#define int int64_t
#define mp make_pair
#define pb push_back
#define sqr(x) (x*x)
#define all(x) x.begin(), x.end()
#define fill(x, val) fill(all(x), val)
#define rep(i, n) for(auto i=0; i<(n); i++)
#define read(input) freopen(input, "r", stdin)

typedef long double ld;
typedef vector<int> vint;
typedef map<int, int> mii;
typedef pair<int, int> pii;
typedef vector<string> vstr;
typedef map<string, int> msi;
typedef pair<string, int> psi;
typedef priority_queue<int> pqi;
typedef pair<string, string> pss;
typedef priority_queue<string> pqs;

const ld pi = acos(-1.0);
const ld eps = 1e-11;
const int mod = 1e9+7;

int readp(){
	cout << "enter the number of processes:" << endl;
	int p;
	cin >> p;
	return p;
}

int readr(){
	cout << "enter the number of resources:" << endl;
	int r;
	cin >> r;
	return r;
}

int reade(){
	cout << "enter the number of edges:" << endl;
	int e;
	cin >> e;
	return e;
}

vector<pss> readv(int e){
	string p, q, buff;
	vector<pss> v;
	rep(i, e){
		cin >> p >> buff >> q;
		v.pb(mp(p, q));
	}
	return v;
}

vector<vector<string> > allocate(vector<pss>& v, int p){
	vector<vector<string> > res(p);
	rep(i, p){
		rep(j, v.size()){
			if(v[j].first[0]=='p' && v[j].first[1]-'0'==i){
				res[i].pb( "Process " + v[j].first + " is holding an instance of resource type " +  v[j].second + ". " );
			}
			else if(v[j].second[0]=='p' && v[j].second[1]-'0'==i){
				res[i].pb( "Process " + v[j].second + " is waiting for an instance of resource type " +  v[j].first + ". " );
			}
		}
	}
	return res;
}

void showres(vector<vector<string> >& res){
	cout << endl;
	rep(i, res.size()){
		rep(j, res[i].size()){
			cout << res[i][j];
		}
		cout << endl << endl;;
	}
}

int32_t main(){

	int p = readp();
	int r = readr();
	int e = reade();
	vector<pss> v = readv(e);
	vector<vector<string> > res = allocate(v, p);
	showres(res);
	
	return 0;
}
