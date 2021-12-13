int maxPower(string s) {
    char cur = 0;
    int count = 0 , max = 0;
        for(char x : s){
            if (cur != x){
                cur = x;
                count = 0;
            }
            count ++;
            if (max < count) max = count;
        }
        return max;
    }