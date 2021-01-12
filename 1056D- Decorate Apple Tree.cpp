    #include <bits/stdc++.h>
    using namespace std;
    using ull = uint64_t;
    using ll = int64_t;
    using ld = long double;
     
    const int N = 200228;
     
    int a[N];
    int p[N];
    bool nl[N];
     
    int main() {
    #ifdef BZ
        freopen("input.txt", "r", stdin);
    #endif
        ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);
        int n;
        cin >> n;
        for (int i = 1; i < n; ++i) {
            cin >> p[i];
            --p[i];
            nl[p[i]] = true;
        }
     
        for (int i = n - 1; i >= 0; --i) {
            a[i] += !nl[i];
     
            if (i) {
                a[p[i]] += a[i];
            }
        }
     
        sort(a, a + n);
        for (int i =0; i < n; ++i) {
            cout << a[i] << " ";
        }
    }
     
