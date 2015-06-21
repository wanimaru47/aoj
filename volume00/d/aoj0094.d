import std.stdio;
import std.string;
import std.conv;

int main()
{
    string[] str = readln().chomp().split();
    double a = str[0].to!double;
    double b = str[1].to!double;
    const double s = 3.305785;
    double ans = a * b / s;
    writefln("%.6f", ans);

    return 0;
}
