//
//  problemSolving.hpp
//  adventCodeProblems
//
//  Created by Rosairy Paniagua Garcia on 9/2/26.
//

#ifndef problemSolving_hpp
#define problemSolving_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
//classes and stuff go here

//class Mathematics{
//public:
//    static int add(int a, int b);
//};

class Password{
public:
//    static std::tuple <char, int, int> Break(std::vector <std::string> dialRotations, int index, int &countClicks);
//    static std::pair <int, int> AddRotation(char direction, int dial, int &result, int &countClicks);
    
 static std::pair <int , int> Break(std::vector <std::string> dialRotations, int index, int &result, int &count);
    
};

#endif /* problemSolving_hpp */
