import std.stdio;
import std.string;
import std.conv;

int main()
{
    int a = readln().chomp().to!int();
    a = a * a * a;
    writeln(a);

    return 0;
}
