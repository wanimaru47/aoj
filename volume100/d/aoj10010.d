import std.stdio;
import std.string;
import std.conv;

int main()
{
    string[] str;
    while (true) {
        str = readln().split();
        int num1 = str[0].to!int();
        char op = str[1].to!char();
        int num2 = str[2].to!int();
        switch (op) {
        case '+': writeln(num1 + num2); break;
        case '-': writeln(num1 - num2); break;
        case '*': writeln(num1 * num2); break;
        case '/': writeln(num1 / num2); break;
        default : break;
        }
        if (op == '?') break;
    }
    

    return 0;
}
