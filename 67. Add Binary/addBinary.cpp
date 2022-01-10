#include <string>
using namespace std;



string addBinary(string a, string b) {
        int overhead = 0;
        int a_size = a.size() , b_size = b.size();
        string to_return = "";
        for (int i = 0 ; i < max(a_size , b_size) ; i ++){
            if ((a_size - 1- i) >= 0 && (b_size-1 - i) >= 0){
                to_return += char(((overhead + (a[a_size - 1- i] - '0') + (b[b_size -1- i] - '0'))%2) + '0');
                if((overhead + (a[a_size - 1 - i] - '0') + (b[b_size -1 - i] - '0')) > 1) overhead = 1;
                else overhead = 0;
            }
            else if((a_size -1 - i) >= 0){
                to_return += char(((overhead + (a[a_size -1- i] - '0'))%2) + '0');
                if((overhead + (a[a_size - 1 - i] - '0') > 1)) overhead = 1;
                else overhead = 0;
            }
            else {
                to_return += char(((overhead + (b[b_size-1 - i] - '0'))%2) + '0');
                if((overhead + (b[b_size - 1 - i] - '0') > 1) )overhead = 1;
                else overhead = 0;
            }
        }
        if(overhead == 1) to_return += '1';
        reverse(to_return.begin() , to_return.end());
        return to_return;
    }