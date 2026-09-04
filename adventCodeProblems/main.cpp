//
//  main.cpp
//  adventCodeProblems
//
//  Created by Rosairy Paniagua Garcia on 9/2/26.
//

#include <fstream>
#include <iostream>
#include <string>
#include <regex>
#include <ranges>

int main(int argc, char* argv[]) {
    
    std::cout << "Hello, World!\n";
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
    
    long count = 0;
    //save number of invalid ids here
    
    while(getline(file, line, ',')){

        std::string wholeID1S = line.substr(0 , line.find('-'));
        std::string wholeID2S = line.substr( (line.find('-') + 1), line.find('-') );
        //get the ids without '-'
        
        long wholeID1N = std::stol(wholeID1S);
        long wholeID2N = std::stol(wholeID2S);
        //save the 2 ids as longs bc the numbers are too big
        
        for(long i : std::views::iota(wholeID1N, wholeID2N + 1)){
            //loop over all numbers in the range (why range was imported)
            
            std::string input = std::to_string(i);
            //save number as a string to use regex
            
            std::regex pattern (R"((.+)\1+)");
            //R "(any character repeated at least once) \this group is repeated at least once)"
            
            if(std::regex_match(input, pattern) == true){
                count+= i;
            }
            //if the patter matches for the full string, add the number we're on to count
            
        }
       
    }
    
    std::cout << "the sum of invalid ids is: " << count << '\n';
    
    return 0;
  
}

