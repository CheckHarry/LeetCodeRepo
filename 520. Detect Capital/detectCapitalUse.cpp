#include <string>
using namespace std;





bool detectCapitalUse(string word) {
    if (word.size() == 1) return true;
    bool first = 'A' <= word[0] && word[0] <= 'Z';
    bool second = 'A' <= word[1] && word[1] <= 'Z';
    if (first && second){
        for (int i = 2 ; i < word.size() ; i ++){
            if('a' <= word[i] && word[i] <= 'z') return false;
        }
        return true;
        }
    else if(first && !second || !first && !second){
        for (int i = 2 ; i < word.size() ; i ++){
            if('A' <= word[i] && word[i] <= 'Z') return false;
        }
        return true;
    }
    else return false;
  
    }