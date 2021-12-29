




int findComplement(int num) {
        int n = 0 , temp = num;
        while (temp = temp >> 1) n = (n + 1) << 1;
        n = n + 1;
        return n ^ num;
    }