import std.stdio;
import std.string;
import std.conv;

int main()
{
    int n = readln().chomp().to!int();
    string s = "Hoshino";
    while (n--) {
        string str = readln().chomp();
        char[] ans;
        for (int i = 0; i < str.length; i++) {
            ans ~= str[i];
            if (str[i] == 'H') {
                bool flag = true;
                if (i + 6 > str.length - 1) flag = false;
                for (int j = 0; j < 7 && flag; j++) {
                    if (str[i + j] != s[j]) flag = false;
                }
                if (flag) {
                    i += 6;
                    ans ~= str[i-5..i];
                    ans ~= 'a';
                }
            }
        }
        writeln(ans);
    }

    return 0;
}
