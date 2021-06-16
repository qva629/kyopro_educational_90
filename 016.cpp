#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

// ap + bq = gcd(a, b)
pll extGCD(ll a, ll b) {
    ll p11 = 1, p12 = 0, p21 = 0, p22 = 1;
    while (b) {
        ll s = a / b;
        // matrix{{0, 1}, {1, -s}}
        a -= s * b;
        swap(a, b);

        p11 -= s * p21;
        p12 -= s * p22;
        swap(p11, p21);
        swap(p12, p22);
    }
    return {p11, p12};
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, A, B, C;
    cin >> N >> A >> B >> C;
  
  	if (A < B)
      	swap(A, B);
  	if (A < C)
      	swap(A, C);

    ll ans = INT_MAX;

    if (B > C)
        swap(B, C);
    ll g = gcd(B, C);
    ll CC = C / g, BB = B / g;
    auto [p, q] = extGCD(B, C);

    for (int i = 0; i < 10000; ++i) {
        ll rem = N - i * A;
        if (rem < 0)
            break;
        if (rem % g != 0)
            continue;

        ll mul = rem / g;
        ll ptmp = p, qtmp = q;
        ptmp *= mul, qtmp *= mul;
        if (ptmp >= 0) {
            ll d = ptmp / CC;
            ptmp -= d * CC;
            qtmp += d * BB;
        } else {
            ll d = (-ptmp + CC - 1) / CC;
            ptmp += d * CC;
            qtmp -= d * BB;
        }

        if (qtmp < 0)
            continue;

        ans = min(ans, i + ptmp + qtmp);
    }

    cout << ans << "\n";

    return 0;
}
