import std.stdio;
import std.string;
import std.conv;
import std.algorithm;
import std.math;

int main()
{
    while (true) { 
        int[3] s;
        string[] str = readln.chomp.split;
        s[0] = to!int(str[0]); s[1] = to!int(str[1]); s[2] = to!int(str[2]);
        if (s[0] == 0 && s[1] == 0 && s[2] == 0) break;
        s.sort;
        int n = readln.chomp.to!int;
        for (int i = 0; i < n; i++) {
            double r = readln.chomp.to!double;
            r *= 2.0;
            if (r > sqrt(to!float(s[0] * s[0] + s[1] * s[1]))) writeln("OK");
            else writeln("NA");
        }
    }
    
    return 0;
}
