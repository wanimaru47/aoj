import std.stdio;
import std.string;
import std.conv;

int main()
{
    string[] num = readln().split();
    writefln("%d %d %.6f", to!int(num[0]) / to!int(num[1]), to!int(num[0]) % to!int(num[1]), to!double(num[0]) / to!double(num[1]));

    return 0;
}
