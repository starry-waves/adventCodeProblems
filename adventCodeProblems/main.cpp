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
    
    std::size_t total = 0;

    while(getline(file, line, '\n')){
        std::vector <std::size_t> nums;
        nums.reserve(nums.size());
    
        for (const char numC: line){
            nums.push_back(numC - '0');

        }
        
        const int digits = 12;
        std::size_t joltage = 0;
      
        auto target = std::begin(line);
        
        for(int i = 0; i < digits; i++){
        
            target = std::max_element(target, std::prev(std::end(line), digits - i - 1));
            joltage = joltage * 10 + (*target - '0');
            target = std::next(target);
            
        }
        total += joltage;
        
        
        
        std::cout << "the total is: " << total << '\n';
        
    }
    
        std::cout << "the total output voltage is: " << total << '\n';
    
    return 0;
  
}

