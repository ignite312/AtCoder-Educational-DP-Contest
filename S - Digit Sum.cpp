/*
Problem Name: S - Digit Sum
Problem Link: https://atcoder.jp/contests/dp/tasks/dp_s
Idea: Digit DP
Complexity:
Resource:
*/
#include<bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    // cin >> tt;
    while(tt--) {
        string number;
        cin >> number;
        int mod;
        cin >> mod;

        int n = (int)number.size();
        vector<vector<int>> dp(mod, vector<int>(2, 0));
        dp[0][0] = 1;
        for(int idx = 0; idx < n; idx++) {
            vector<vector<int>> new_dp(mod, vector<int>(2)); 
            for(int sum = 0; sum < mod; sum++) {
                for(char digit = '0'; digit <= '9'; digit++) {
                    for(auto already_smaller: {false, true}) {
                        if(digit > number[idx] && !already_smaller) {
                           continue;
                        }
                        (new_dp[(sum + digit - '0') % mod][digit < number[idx] || already_smaller]+=dp[sum][already_smaller]) %= M;
                    }
                }
            }
            dp = new_dp;
        }
        cout << (dp[0][0] + dp[0][1] - 1 + M) % M << "\n";
    }
    return 0;
}
