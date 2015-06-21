import std.stdio;
import std.string;
import std.conv;
import std.algorithm;

/*
int n;
int[25][25][25] dp;

int test(int a, int b, int c, int w) {
    int res;
    int t = a * 200 + b * 300 + c * 500;
    if (w == 0) return 0;
    if (w) return 999999;
    else if (dp[w] > 0) return dp[w];
    else {
        int p1 = dp[w - 200] + 380; if ((a + 1) % 5 == 0) p1 = p1 - 380;
        
        int p2 = dp[w - 300] + 550; if ((b + 1) % 4 == 0) p2 = p2 - 330;
        int p3 = dp[w - 300] + 850; if ((c + 1) % 5 == 0) p3 = p3 - 306;

        res = min(test(a + 1, b, c, p1), test(a, b + 1, c, p2), test(a, b, c + 1, p3));
        if (res == p1) t += 200;
        else if (res == p2) t += 300;
        else t += 500;
    }

    return dp[w] = res;
}
*/

int main()
{
    /*
    for (int i = 0; i < 5001; i++) dp[i] = -1;
    dp[200] = 380;
    dp[300] = 550;
    dp[500] = 850;
    */
    while (true) {
        int n = readln().chomp().to!int();
        if (n == 0) break;
        //writeln(dfs(0,0,0,n));
        int p = 9999999;
        for (int i = 0; i <= 25 && i * 200 <= n; i++) {
            for (int j = 0; j <= 17 && i * 200 + j * 300 <= n; j++) {
                for (int k = 0; k <= 10 && i * 200 + j * 300 + k * 500 <= n; k++) {
                    if (i * 200 + j * 300 + k * 500 == n) {
                        int t = i * 380 + j * 550 + k * 850;
                        t -= (i / 5) * 380;
                        t -= (j / 4) * 330;
                        t -= (k / 3) * 306;
                        p = min(p, t);
                    }
                }
            }
        }
        writeln(p);
    }

    return 0;
}
