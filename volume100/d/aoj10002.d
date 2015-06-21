import std.stdio;
import std.string;
import std.conv;

int main()
{
    int a , b;
    string str[] = readln().chomp().split();
    a = to!int(str[0]);
    b = to!int(str[1]);

    write(a*b, " ");
    writeln((a + b) * 2);
    

    return 0;
}
