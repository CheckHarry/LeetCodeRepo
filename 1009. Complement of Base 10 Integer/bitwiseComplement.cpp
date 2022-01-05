









int bitwiseComplement(int n) {
    int m = 0 , temp = n;
    while (temp = temp >> 1) m = (m + 1) << 1;
    return (m + 1) ^ n;
 }
