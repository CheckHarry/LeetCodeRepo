




int brokenCalc(int startValue, int target){
    int ans = 0;
    while (target != startValue){
        ans++;
        if (target % 2)  target++;
        else if (target < startValue) return ans + startValue - target - 1;
        else target = target / 2;
    }
    return ans;
}