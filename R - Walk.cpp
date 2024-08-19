/*
Problem Name: R - Walk
Problem Link: https://atcoder.jp/contests/dp/tasks/dp_r
Idea: 
Complexity:
Resource:
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;
 
struct Matrix {
    int n, m;
    vector<vector<int>> a;
    Matrix(int n, int m) : n(n), m(m), a(n, vector<int>(m)) {}
 
    Matrix operator*(const Matrix& other) const {
        Matrix product(n, other.m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                for (int k = 0; k < n; ++k) {
                    product.a[i][j] = (product.a[i][j] + (ll)a[i][k] * other.a[k][j]) % M;
                }
            }
        }
        return product;
    }
};
 
Matrix expo_power(Matrix a, ll k, int n) {
    Matrix product(n, n);
    for (int i = 0; i < n; i++) {
        product.a[i][i] = 1;
    }
    while (k > 0) {
        if (k % 2) {
            product = product * a;
        }
        a = a * a;
        k /= 2;
    }
    return product;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    // cin >> tt;
    while(tt--) {
        int n, m;
        ll k;
        cin >> n >> k;
        Matrix matrix(n, n);
        for(int u = 0; u < n; u++) {
          for(int v = 0; v < n; v++) {
            int x;
            cin >> x;
            matrix.a[u][v]+=x;
          }
        }
        matrix = expo_power(matrix, k, n);
        ll ans = 0;
        for(int u = 0; u < n; u++) {
          for(int v = 0; v < n; v++) {
            ans = (ans + matrix.a[u][v]) % M;
          }
        }
        cout << ans << "\n";
    }
    return 0;
}
