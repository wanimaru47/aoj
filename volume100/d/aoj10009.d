import std.stdio;
import std.string;
import std.conv;
import std.math;

int main()
{
    double r = readln().chomp().to!double();
    writefln("%.6f %.6f", r * r * PI, 2 * r * PI);

    return 0;
}
