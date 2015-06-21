import std.stdio;
import std.string;
import std.conv;
import std.algorithm;

int main()
{
    string[] num = readln().split();
    num.sort;
    writeln(num[0], " ", num[1], " ", num[2]);
        
    return 0;
}
