import std.stdio;
import std.string;
import std.conv;
import std.algorithm;

bool sreach (int[10] N) {
    bool res = false;
    bool flag = true;
    int count = 0;
    for (int j = 1; j < 10; j++) {
        if (N[j] == 2) count++;
        else if (N[j] != 3 && N[j] != 0) flag = false;
        if (N[j] < 0) return false;
    }
    if (flag && count == 1) return true;
    for (int i = 1; i + 2 < 10; i++) {
        auto tmp = N;
        if (tmp[i] > 0) {
            flag = true;
            for (int j = 0; j < 3; j++)
                if (tmp[i + j] < 1) flag = false;
            if (flag) --tmp[i..i + 3];
            if (flag) {
                res = (res || sreach(tmp));
                tmp.reverse;
                res = (res || sreach(tmp));
            }
        }
    }
    
    return res;
}

int main()
{
    while (true) {
        if (stdin.eof()) break;
        string str = readln().chomp();
        int[10] N = 0;  
        for (int i = 0; i < str.length; i++)
            ++N[to!int(str[i] - '0')];
        bool[10] ans = false;
        for (int i = 1; i < 10; i++) {
            auto tmp = N;
            if (tmp[i] < 4) ++tmp[i];
            else continue;
            ans[i] = sreach(tmp);
            tmp.reverse;
            ans[i] = (ans[i] || sreach(tmp));
        }
        int t = 0;
        for (int i = 9; i > 0; i--)
            if (ans[i]) {t = i; break;}
        for (int i = 1; i < t; i++)
            if (ans[i]) write(i, " ");
        writeln(t);
    }
    
    return 0;
}
