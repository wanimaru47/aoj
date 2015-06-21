import std.stdio;
import std.string;
import std.conv;

int main()
{
    string[] str = readln().split();
    int a = to!int(str[0]);
    int b = to!int(str[1]);

    if (a > b) writeln("a > b");
    else if (a < b) writeln("a < b");
    else writeln("a == b");

    return 0;
}
