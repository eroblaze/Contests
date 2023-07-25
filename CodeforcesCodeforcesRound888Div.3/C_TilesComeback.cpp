// time-limit: 2000
// problem-url: https://codeforces.com/contest/1851/problem/C
// @eroblaze
#include "bits/stdc++.h"
using namespace std;

#define redc "\033[48;5;196m\033[38;5;15m" // Red color code
#define endredc "\033[0m" << "\n" // This resets the coloring
#define db1(x) cout<< #x <<" = "<< x <<'\n'
#define db2(x,y) cout<< #x <<" = "<< x <<", "<< #y <<" = "<< y <<'\n'
#define db3(x,y,z) cout<< #x <<" = "<< x <<", "<< #y <<" = "<< y <<", "<< #z <<" = "<< z <<'\n'
#define len(x) int((x).size())

#ifdef ERO
string to_string(char c) { return string({c}); }
template<class... Ts>
// For tuples
ostream& operator<<(ostream& o, tuple<Ts...> t) {
  string s = "(";
  apply([&](auto&&... r) {
    ((s += to_string(r) + ", "), ...); }, t);
  return o << s.substr(0, len(s) - 2) + ")";
}
// For pairs
ostream& operator<<(ostream &o, pair<auto, auto> p) {
  return o << "(" << p.first << ", " << p.second << ")";
}
// For vectors, e.t.c
template<class C, class T = typename C::value_type,
typename std::enable_if<!std::is_same<C, std::string>
::value>::type* = nullptr>
ostream& operator<<(ostream &o, C c) {
  for (auto e : c) o << setw(2) << e;
  return o << endredc << "\n" << redc;
}

void debug(const auto &e, const auto &... r) {
  cout << redc << e;
  ((cout << " " << r), ..., (cout << endredc << "\n"));
}
#else
#define debug(...)
#endif

using ll = long long;
using PII = pair<int, int>;
using VI = vector<int>;
using VLL = vector<ll>;
using VC = vector<char>;
using VVI = vector<VI>;
using VVLL = vector<VLL>;
using VVC = vector<VC>;
using VPII = vector<PII>;

// Reads N input into V
template <typename T>
void create_vector(T&, int);

template <typename T>
void print(const T&);

void solve() {
	int N, K; cin>>N>>K;
  VI arr;
  create_vector(arr, N);
  int first = arr[0];
  int last = arr[N-1];
  int cnt1 = 0, cnt2 = 0;
  int cnt2idx = -1;

  for (int i = N-1; i >= 0; --i) {
    if (arr[i] != last) continue;
    ++cnt2;
    if (cnt2 == K) {
      cnt2idx = i;
      break;
    }
  }

  debug("cnt2idx", cnt2idx);

  for (int i = 0; i <= cnt2idx; ++i) {
    if (arr[i] == first) ++cnt1;
  }
  debug(cnt1, cnt2, K);
  cout<<(cnt1 >= K && cnt2 == K?"YES\n":"NO\n");
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int t = 1;
    cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}

template <typename T>
void create_vector(T& V, int N) {
	V.resize(N);
	for (int i = 0; i < N; ++i)	
	    cin>>V[i];
}

template <typename T>
void print(const T& ds) {
    for (auto& el: ds) {
        cout<<el<<", ";
    }
    cout<<"\n";
}