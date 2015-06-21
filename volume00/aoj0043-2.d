import std.stdio;
import std.string;
import std.conv;
import std.algorithm;

bool search(auto tmp) {
    int count = 0;
    bool flag = true;
    for (int i = 1; i < 10; i++) {
        if (tmp[i] == 2) count++;
        else if (tmp[i] != 3 && tmp[i] != 0) flag = false;
    }
    if (flag && count == 1) return true;

}

int main()
{
    string str = readln().chomp();
    int[10] N;
    for (int i = 0; i < str.length; i++) {
        int tmp = to!int(str[i]);
        ++N[tmp];
    }
    for (int i = 1; i < 10; i++) {
        auto tmp = N;
        if (tmp[i] > 4) continue;
        ++tmp[i];
        
    }

    return 0;
}
