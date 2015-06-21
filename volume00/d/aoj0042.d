import std.stdio;
import std.string;
import std.conv;
import std.algorithm;

const int MAX_N = 1000;
const int MAX_W = 1000;
const int MAX_V = 10000;

int[MAX_N + 1][MAX_W + 1] dp;

int main()
{
    int times = 1;
    while (true) {
        int lim = readln().chomp().to!int();
        if (lim == 0) break;
        int n = readln().chomp().to!int();

        int[MAX_N] w, v;
        for (int i = 0; i < n; i++) {
            string[] str = readln().split(",");
            v[i] = str[0].to!int();
            w[i] = str[1].to!int();
        }

        int res = 99999999, ans = -1;
        for (int i = 0; i <= MAX_N; i++)
            for (int j = 0; j <= MAX_W; j++)
                dp[i][j] = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j <= lim; j++) {
                if (j < w[i]) dp[i + 1][j];
                else dp[i][j] = max(dp[i + 1][j], dp[i + 1][j - w[i]] + v[i]);
                if (ans < dp[i][j]) {
                    ans = dp[i][j];
                    if (res > j) res = j;
                }
            }
        }
        writeln("case ", times, ":");
        writeln(ans);
        writeln(res);
        times++;
    }

    return 0;
}
