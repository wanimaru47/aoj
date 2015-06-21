import std.stdio;
import std.string;
import std.conv;

int main()
{
    int i = 0;
    string str;
    while ((str = readln().chomp()) != "0") {
        i++;
        writeln("Case ", i, ": ", str);
    }

    return 0;
}
