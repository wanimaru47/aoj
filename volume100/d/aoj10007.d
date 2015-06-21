import std.stdio;
import std.string;
import std.conv;
import std.algorithm;

int main()
{
    while (true) {
        string[] str = readln().split();
        if (str[0] == str[1] && str[0] == "0") break;
        int[] num;
        num ~= to!int(str[0]);
        num ~= to!int(str[1]);
        sort(num);
        writeln(num[0], " ", num[1]);
    }
    
    return 0;
}
