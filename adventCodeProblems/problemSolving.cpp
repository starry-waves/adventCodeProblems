//
//  problemSolving.cpp
//  adventCodeProblems
//
//  Created by Rosairy Paniagua Garcia on 9/2/26.
//

#include "problemSolving.hpp"
#include <iostream>
#include <vector>
//define the methods and stuff here

//break the dial rotation instructions into 2 parts: the L and R char, and the rotation number
std::pair <char , int> Password::Break(std::vector <std::string> dialRotations, int index){
   
        char direction;
        int rotation;
   
    
    direction = dialRotations[index].at(0);
    rotation = std::stoi(dialRotations[index].substr(1, dialRotations.size()- 1)) % 100 ;
    //std::stoi converts a string into an int
   
    return {direction, rotation};
}

int Password::AddRotation(char direction, int rotation, int &result){
    
    switch(direction){
        case 'L':
            result -= rotation;
            if(result < 0){
                result += 100;
            }
            break;
        case 'R':
            result += rotation;
            if(result >= 100){
                result -= 100;
            }
            break;
    }
    
    
    return result;
}





//int Password::AddCW(int &rotation, int &result){
//    
//    
//    return result;
//}



//int Mathematics::add(int a, int b){
//    return a + b;
//}
