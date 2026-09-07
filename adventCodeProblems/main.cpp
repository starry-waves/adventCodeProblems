//
//  main.cpp
//  adventCodeProblems
//
//  Created by Rosairy Paniagua Garcia on 9/2/26.
//

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[]) {
    
    std::string input = "text.txt";
    if (argc > 1) {
           input = argv[1];
       }
    std::ifstream file (input);
    
    if (!file.is_open()) {
            std::cerr << "Error: Could not open the file!" << std::endl;
            std::cerr << "Looking for it at: " << std::filesystem::absolute(input) << '\n';
            return 1;
        }
    
    std::string line;
    
    int total = 0;

    while(getline(file, line, '\n')){
        std::vector <int> nums;
        nums.reserve(nums.size());
    
        for (const char numC: line){
            nums.push_back(numC - '0');

        }
        
      
        const auto target1 = std::max_element(std::begin(line), std::prev(std::end(line)) );
        const auto target2 = std::max_element(std::next(target1), std::end(line) );
        
        total += (*target1 - '0') * 10 + (*target2 - '0');
        
        std::cout << "the total is: " << total << '\n';
        
    }
    

     
    
    
    std::cout << "the total output voltage is: " << total << '\n';
    
    return 0;
  
}

