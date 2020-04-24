int main() {
    int i, j, *p;
    i = 42;
    p = new int;
    *p = i;
    delete p;

    ((i<42) ? i : j) = 23;

    //42 = i;
    return 0;
}