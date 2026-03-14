#include "my_tree.h"

int main() {
    my_tree<int> t;

    t.set_root(1);
    t.add_child(1, 2);
    t.add_child(1, 3);
    t.add_child(2, 4);
    t.add_child(2, 5);
    t.add_child(3, 6);
    t.bfs();
    return 0;
}