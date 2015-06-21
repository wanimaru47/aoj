import std.stdio;
import std.string;
import std.conv;
import std.algorithm;

struct P {int first; int second;}

int main()
{
    while (true) {
        string[] str = readln().chomp().split();
        int h = str[0].to!int();
        int w = str[1].to!int();
        if (h == 0 && w == 0) break;
        string t;
        char[101][101] f;
        for (int i = 0; i < h; i++) {
            t = readln.chomp;
            for (int j = 0; j < w; j++) {
                f[i][j] = t[j].to!char;
            }
        }

        P[char] m; P p;
        p.first = 0; p.second = 1; m['>'] = p;
        p.first = 0; p.second = -1; m['<'] = p;
        p.first = -1; p.second = 0; m['^'] = p;
        p.first = 1; p.second = 0; m['v'] = p;
        p.first = p.second = 0; m['.'] = m['*'] = p;

        int x = 0, y = 0;
        while (true) {
            int nx = x, ny = y;
            if (f[nx][ny] == '*') {
                writeln("LOOP");
                break;
            }
            //writeln(m[f[nx][ny]].first, " ", m[f[nx][ny]].second);
            if (0 <= nx + m[f[nx][ny]].first && nx + m[f[nx][ny]].first < h && 0 <= ny + m[f[nx][ny]].second && ny + m[f[nx][ny]].second < w) {
                nx = nx + m[f[nx][ny]].first;
                ny = ny + m[f[nx][ny]].second;
            }
            f[x][y] = '*';
            if (x == nx && y == ny || f[nx][ny] == '.') {
                writeln(ny, " ", nx);
                break;
            }
            x = nx; y = ny;
        }
    }

    return 0;
}
