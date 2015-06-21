import std.stdio;
import std.string;
import std.conv;
import std.algorithm;

int main()
{
    int[][string] T;
    string[] t;
    while (true) {
        string[] s = readln.chomp.split;
        //if (stdin.eof) break;
        if (s[0] == "0") break;
        string str = s[0];
        int p = s[1].to!int;
        T[str] ~= p;
        t ~= str;
    }
    t.sort();
    int i = 0;
    string tmp = t[0];
    while (i < t.length) {
        tmp = t[i];
        writeln(tmp);
        sort(T[tmp]);
        write(T[tmp][0]);
        for (int j = 1; j < T[tmp].length; j++) write(" ", T[tmp][j]);
        while (tmp == t[i]) {
            i++;
            if (i >= t.length) break;
        }
        writeln();
    }

    return 0;
}
