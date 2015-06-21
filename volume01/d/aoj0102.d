import std.stdio;
import std.string;
import std.conv;

int main()
{
    int n;
    while (true) {
        n = readln().chomp().to!int();
        if (n == 0) break; 
        int num[101][101];
        for (int i = 0; i < n; i++) {
            string[] str = readln().chomp().split();
            for (int j = 0; j < n; j++)
                num[i][j] = str[j].to!int();
        }
        for (int i = 0; i < n; i++)
            num[n][i] = num[i][n] = 0;
        num[n][n] = 0;
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                num[i][n] += num[i][j];
                num[n][i] += num[j][i];
            }
        for (int i = 0; i < n; i++)
            num[n][n] += num[n][i];

        for (int i = 0; i < n + 1; i++) {
            for (int j = 0; j < n; j++) {
                writef("%5d", num[i][j]);
            }
            writefln("%5d", num[i][n]);
        }
    }

    return 0;
}
