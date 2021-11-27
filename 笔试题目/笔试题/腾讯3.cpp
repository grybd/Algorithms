

#include <bits/stdc++.h>

using namespace std;

int main () {
    string input;
    stack<char> op;
    stack<long long> num;
    getline(cin, input);
    unordered_map<char, int> prio;
    prio['@'] = 1;
    prio['x'] = 2;
    prio['+'] = 3;
    //符号栈的量比数少1
    //符号栈按优先级处理单调排列，低优先级的放下面,同优先级从左到右那么遇到相同优先级符号压栈要先弹开符号处理计算
    string temp;
    for (const auto& c : input) {
        if (c <= '9' && c >= '0') {
            temp += c;
        } else {
            num.push(stoll(temp));
            temp.clear();
            if (op.empty()) {
                op.push(c);
            } else {
                while (!op.empty() && prio[c] >= prio[op.top()]) {
                    char opt = op.top();
                    long long b = num.top();
                    op.pop();
                    num.pop();
                    if (opt == '@') {
                        num.top() = num.top() | (num.top() + b);
                    } else if (opt == 'x') {
                        num.top() *= b;
                    } else if (opt == '+') {
                        num.top() += b;
                    }
                }
                op.push(c);
            }
        }
    }
    if (!temp.empty()) {
        num.push(stoll(temp));
        temp.clear();
    }
    while (!op.empty()) {
        char opt = op.top();
        long long b = num.top();
        op.pop();
        num.pop();
        if (opt == '@') {
            num.top() = num.top() | (num.top() + b);
        } else if (opt == 'x') {
            num.top() *= b;
        } else if (opt == '+') {
            num.top() += b;
        }
    }
    //数栈最后肯定只会剩一个的
    cout << num.top() << endl;
    return 0;
}
