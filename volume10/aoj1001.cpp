#include <bits/stdc++.h>
using namespace std;

pair<string,string> get_subtree(string tree) {
    tree.erase(tree.begin());
    tree.erase(tree.end()-1);
    int point = 0;
    for (int i = 0, count = 0; i < tree.size(); i++) {
        if (tree[i] == '(') count++;
        else if (tree[i] == ')') count--;
        else if (!count) {
            point = i;
            break;
        }
    }

    auto sub1 = string(tree.begin(), tree.begin() + point);
    auto sub2 = string(tree.begin() + point + 1, tree.end());

    return make_pair(sub1, sub2);
}

string pro_i(string t1, string t2) {
    if (t1 == "" || t2 == "") return "";

    auto p_subtree1 = get_subtree(t1);
    auto p_subtree2 = get_subtree(t2);

    return "(" + pro_i(p_subtree1.first, p_subtree2.first) + "," + pro_i(p_subtree1.second, p_subtree2.second) + ")";
}

string pro_u(string t1, string t2) {
    if (t1 == "") return t2;
    if (t2 == "") return t1;


    auto p_subtree1 = get_subtree(t1);
    auto p_subtree2 = get_subtree(t2);

    return "(" + pro_u(p_subtree1.first, p_subtree2.first) + "," + pro_u(p_subtree1.second, p_subtree2.second) + ")";
}

int main() {
    char s;
    string t1, t2;
    while (cin >> s >> t1 >> t2) {
        if (s == 'i') cout << pro_i(t1, t2) << endl;
        else cout << pro_u(t1, t2) << endl;
    }

    return 0;
}
