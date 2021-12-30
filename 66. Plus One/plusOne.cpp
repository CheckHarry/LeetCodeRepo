#inlucde <vector>
using namespace std;



vector<int> plusOne(vector<int>& digits) {
        vector<int> digits_to_return(1 , 0);
        for (int i : digits) digits_to_return.push_back(i);
        int pos = digits.size();
        while(digits_to_return[pos] == 9 and pos >= 0){
            digits_to_return[pos] = 0;
            pos --;
        }
        digits_to_return[pos] += 1;
        if (pos != 0) digits_to_return.erase(digits_to_return.begin());
        return digits_to_return;
        
    }