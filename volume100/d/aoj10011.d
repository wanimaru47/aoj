import std.stdio;
import std.string;
import std.conv;

int main()
{
    int N = readln().chomp().to!int();
    string[] num = readln().split();
    for (int i = N - 1; i > 0; i--)
        write(num[i], " ");
    writeln(num[0]);

    return 0;
}
