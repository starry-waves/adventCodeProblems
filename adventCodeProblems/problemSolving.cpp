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
std:: pair <int , int> Password::Break(std::vector <std::string> dialRotations, int index, int &result, int &count){
        char direction;
        int rotation;
        int countClicks = 0;
       
   
    direction = dialRotations[index].at(0);
    rotation = std::stoi(dialRotations[index].substr(1, dialRotations[index].size() - 1) );//remember %100 was here
    //std::stoi converts a string into an int
//    if(result == 0){
//        countClicks --;
//    }
    if((rotation % 100 == 0) || (rotation / 100 > 0)){
        countClicks += (rotation / 100) ;
    }
    
    rotation %= 100;
    
    switch(direction){
            
            case 'L':
                result -= rotation;
            if(result <= 0){
                if(result == 0){
                    count ++;
                }
                if(result < 0){
                    countClicks++;
                }
                result += 100;
            }
                break;
            
            case 'R':
                result += rotation;
            if (result >= 100){
                if(result == 100){
                    count++;
                }
                if(result > 100){
                    countClicks += 1;
                }
                result -= 100;
            }
                break;
        }
    
    if (countClicks > 0){
        count +=  countClicks;
    }
 
    return {count , result};
}

//std::pair <int, int> Password::AddRotation(char direction, int rotation, int &result, int &countClicks){
//    
//    switch(direction){
//        case 'L':
//            result -= rotation;
//            if(result < 0){
//                countClicks += 1;
//                result += 100;
//            }
//            break;
//        case 'R':
//            result += rotation;
//            if(result >= 100){
//                countClicks += 1;
//                result -= 100;
//            }
//            break;
//    }
//    
//    
//    return {result , countClicks};
//}





//int Password::AddCW(int &rotation, int &result){
//    
//    
//    return result;
//}



//int Mathematics::add(int a, int b){
//    return a + b;
//}
