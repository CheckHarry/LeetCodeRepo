#include <string>
#include <vector>
#include <iostream>
using namespace std;




vector<int> Convert(string &instruction){
    int direction = 0 , x_coor = 0 , y_coor = 0;
    const int x_Map[4] = {1 , 0 , -1 , 0};
    const int y_Map[4] = {0 , -1 , 0 , 1};
    for (char x : instruction){
        if (x == 'L') direction = (direction + 1)%4;
        else if (x == 'R') direction = (direction + 3)%4;
        else if (x == 'G'){
            x_coor += x_Map[direction];
            y_coor += y_Map[direction];
        }
    }
    return vector<int> {x_coor , y_coor , direction};
}


bool isRobotBounded(string instructions) {
    vector<int> converted_instruction = Convert(instructions);
    vector<vector<int>> rotated_converted_instruction;
    int direction = 0 , x_coor = 0 , y_coor = 0;
    rotated_converted_instruction.push_back(converted_instruction);
    for (int i = 1 ; i < 4 ; i ++){
        vector<int> temp = rotated_converted_instruction.back();
        temp[0] = -rotated_converted_instruction.back()[1];
        temp[1] = rotated_converted_instruction.back()[0];
        temp[2] = (temp[2] + 1) % 4;
        rotated_converted_instruction.push_back(temp);
    }
    for (int i = 0 ; i < 4 ; i ++){
        x_coor += rotated_converted_instruction[direction][0];
        y_coor += rotated_converted_instruction[direction][1];
        direction = rotated_converted_instruction[direction][2];
        if (x_coor == 0 && y_coor == 0) return true;
    }
    return false;
}


int main(){
    string x = "";
    cin >> x;
    cout << isRobotBounded(x);

}
