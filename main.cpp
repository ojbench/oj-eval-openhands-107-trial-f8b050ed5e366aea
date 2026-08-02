#include <bits/stdc++.h>
using namespace std;

namespace LIST
{

    struct NODE {
        int data;
        NODE *next;
    };

    NODE *head = nullptr;
    int len = 0;

    void init() {
        head = nullptr;
        len = 0;
    }
    NODE* move(int i) {
        NODE *cur = head;
        while (i-- && cur) cur = cur->next;
        return cur;
    }
    void insert(int i, int x) {
        NODE *node = new NODE{x, nullptr};
        if (len == 0) {
            node->next = node;
            head = node;
        } else if (i == 0) {
            NODE *tail = move(len - 1);
            node->next = head;
            tail->next = node;
            head = node;
        } else {
            NODE *prev = move(i - 1);
            node->next = prev->next;
            prev->next = node;
        }
        ++len;
    }
    void remove(int i) {
        if (len == 1) {
            delete head;
            head = nullptr;
            len = 0;
            return;
        }
        if (i == 0) {
            NODE *tail = move(len - 1);
            NODE *del = head;
            head = head->next;
            tail->next = head;
            delete del;
        } else {
            NODE *prev = move(i - 1);
            NODE *del = prev->next;
            prev->next = del->next;
            delete del;
        }
        --len;
    }
    void remove_insert(int i) {
        if (len == 1) return;
        NODE *tail = move(len - 1);
        NODE *del;
        if (i == 0) {
            del = head;
            head = head->next;
            tail->next = head;
        } else {
            NODE *prev = move(i - 1);
            del = prev->next;
            prev->next = del->next;
        }
        del->next = head;
        tail->next = del;
    }
    void get_length() {
        cout << len << '\n';
    }
    void query(int i) {
        if (i < 0 || i >= len) {
            cout << -1 << '\n';
            return;
        }
        cout << move(i)->data << '\n';
    }
    void get_max() {
        if (len == 0) {
            cout << -1 << '\n';
            return;
        }
        int mx = head->data;
        NODE *cur = head->next;
        for (int i = 1; i < len; ++i) {
            if (cur->data > mx) mx = cur->data;
            cur = cur->next;
        }
        cout << mx << '\n';
    }
    void clear() {
        if (!head) return;
        NODE *cur = head->next;
        while (cur != head) {
            NODE *tmp = cur;
            cur = cur->next;
            delete tmp;
        }
        delete head;
        head = nullptr;
        len = 0;
    }

}
int n;
int main()
{
    cin >> n;
    int op, x, p;
    LIST::init();
    for (int _ = 0; _ < n; ++_)
    {
        cin >> op;
        switch(op) {
            case 0:
                LIST::get_length();
                break;
            case 1:
                cin >> p >> x;
                LIST::insert(p,x);
                break;
            case 2:
                cin >> p;
                LIST::query(p);
                break;
            case 3:
                cin >> p;
                LIST::remove(p);
                break;
            case 4:
                cin >> p;
                LIST::remove_insert(p);
                break;
            case 5:
                LIST::get_max();
                break;
        }
    }
    LIST::clear();
    return 0;
}
