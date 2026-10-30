
#include <iostream>
#include <stdexcept>
using namespace std;

class StackArray {
    static constexpr int CAP = 5;
    int a[CAP];
    int t = -1;

public:
    bool empty() const {
        return t == -1;
    }

    void push(int x) {
        if (t == CAP - 1)
            throw overflow_error("penuh");

        a[++t] = x;
    }

    void pop() {
        if (empty())
            throw underflow_error("kosong");

        --t;
    }

    int top() const {
        if (empty())
            throw underflow_error("kosong");

        return a[t];
    }
};

int main() {
    StackArray s;

    try {
        s.push(10);
        s.push(20);
        s.push(30);

        cout << "Data paling atas: " << s.top() << endl;

        s.pop();

        cout << "Setelah pop: " << s.top() << endl;
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
