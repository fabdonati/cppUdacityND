bool myLocalFunction(int myInt) {
    bool isBelowThreshold = myInt < 42 ? true : false;
    return isBelowThreshold;
}

int main() {
    bool res = myLocalFunction(23);
    return 0;
}