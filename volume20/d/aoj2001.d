import std.stdio;
import std.string;
import std.conv;

int main()
{
    while (true) {
        string[] s1 = readln.chomp.split;
        int n = s1[0].to!int;
        int m = s1[1].to!int;
        int a = s1[2].to!int;
        if (a == 0) break;
        int max = -1;

        int[1001][1001] N;
        for (int i = 0; i < 1001; i++)
            for (int j = 0; j < 1001; j++)
                N[i][j] = i;
        bool flag = true;
        for (int i = 0; i < m; i++) {
            string[] s2 = readln.chomp.split;
            int h = s2[0].to!int;
            int p = s2[1].to!int;
            int q = s2[2].to!int;

            N[p][h] = q;
            N[q][h] = p;
        }

        max = 1000;
        while (max) {
            a = N[a][max];
            --max;
        }
        writeln(a);
    }

    return 0;
}
