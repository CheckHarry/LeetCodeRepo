







int fib(int n) {
    if (n == 0) return 0;
    int fbl = 0 , fbr = 1 , temp;
    for(int i = 2 ; i < n + 1 ; i ++){
        temp = fbr;
        fbr = fbr + fbl;
        fbl = temp;
    }
    return fbr;
}