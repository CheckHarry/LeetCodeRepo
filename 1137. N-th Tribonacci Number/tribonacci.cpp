





int tribonacci(int n) {
    int t[] = {0 , 1 , 1} , temp;
    if (n <= 2) return t[n];
    for (int i = 3 ; i < n + 1 ; i ++){
        temp = t[2];
        t[2] = t[2] + t[1] + t[0];
        t[0] = t[1];
        t[1] = temp;
    }
    return t[2];
}