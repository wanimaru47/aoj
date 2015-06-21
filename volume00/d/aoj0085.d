import std.stdio;
import std.string;
import std.conv;

int main()
{
    while (true) {
        string[] str = readln().chomp().split();
        int n = str[0].to!int;
        int m = str[1].to!int;

        if (m == n && n == 0) break;
        int[1001] ans;
        int c = n - 1;
        for (int i = 0; i < n; i++) ans[i] = i + 1;
        while (n > 1) {
            c = (c + m) % n;
            for (int i = c; i < n - 1; i++) ans[i] = ans[i + 1];
            n--;
            c--;
        }
        writeln(ans[0]);
    }
    
    return 0;
}
    
