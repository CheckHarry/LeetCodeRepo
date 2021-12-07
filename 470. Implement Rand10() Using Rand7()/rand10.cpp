




// rand7 is provided by leetcode
int rand10() {
        int x = rand(5);
        int y = rand(2);
        return y == 1 ? x : 5 + x;
    }
    int rand(int n){
        int x = rand7();
        while(x > n) x = rand7();
        return x;
    }