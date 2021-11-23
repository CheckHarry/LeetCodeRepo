#include <string>
#include <iostream>
using namespace std;

 

string process_str(string str) {
    string result = ".";
    for (const char x : str) {
        result += x;
        result += '.';
    }
    return result;
}

string replace(string str) {
    string result = "";
    for (const char x : str) {
        if (x != '.') {
            result += x;
        }
    }
    return result;
}
// assume len(str >= 3)
int  RadiusTable[210000];
string max_pali(string Str_pre) {

    string Str = process_str(Str_pre);
    int reflected_index, reflected_radius, max = 0, max_index = 0;
    int StrLength = Str.length();
    int CurCenteredElementIndex = 0;
    RadiusTable[0] = 0;
    for (int index = 1; index < StrLength; index++) {
        bool x = false;
        reflected_radius = 0;
        if ((index - CurCenteredElementIndex) <= RadiusTable[CurCenteredElementIndex]) {
            reflected_index = 2 * CurCenteredElementIndex - index;
            reflected_radius = RadiusTable[reflected_index];
            if (reflected_index - reflected_radius != CurCenteredElementIndex - RadiusTable[CurCenteredElementIndex]) {
                RadiusTable[index] = min(reflected_index - CurCenteredElementIndex + RadiusTable[CurCenteredElementIndex], reflected_radius);
                x = true;
            }
        }
        if (! x) {
            while (0 <= index - (reflected_radius + 1) && index + (reflected_radius + 1) < StrLength && Str[index - (reflected_radius + 1)] == Str[index + (reflected_radius + 1)]) {
                reflected_radius++;
            }
            RadiusTable[index] = reflected_radius;
        }

       if (RadiusTable[index] + index >= RadiusTable[CurCenteredElementIndex] + CurCenteredElementIndex)
           CurCenteredElementIndex = index;
        if (max < RadiusTable[index]) {
            max_index = index;
            max = RadiusTable[index];
        }
    }
    
   
    return replace(Str.substr(max_index - max, 2 * max + 1));

}


int main() {
    string x;
    cin >> x;
    cout << max_pali(x);
}

