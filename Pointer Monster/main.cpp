#include <cstdio>
#include <iostream>

char a[4][7] = {"Common", "Point", "Boost", "Better"};
char (*b[4])[7] = {a + 3, a + 1, a, a + 2};

char (*(*C())[4])[7] {
    return &b;
}

char (**d())[7] {
    return C()[1] - 3;
}

char buf[256];

char *pointer_monster(__typeof__(d) f) {
    int len;
    len = sprintf(buf, "%s", *f()[0]);
    len += sprintf(buf + len, "%s ", *((**f)() - 1)[0] + 4);
    len += sprintf(buf + len, "%s", (*f())[0] - 4);
    len += sprintf(buf + len, "%s", f()[1][2] + 3);
    len += sprintf(buf + len, "%s", *((**f)() - 1)[0] + 4);
    return buf;
}


int main() {

    std::cout << pointer_monster(d) << std::endl;

    return 0;
}
