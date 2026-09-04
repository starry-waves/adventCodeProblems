//
//  main.cpp
//  adventCodeProblems
//
//  Created by Rosairy Paniagua Garcia on 9/2/26.
//

#include <fstream>
#include <iostream>
#include <string>


int main(int argc, char* argv[]) {
    // insert code here...
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
    
    while(getline(file, line, ',')){
        
//        long wholeID1 = std::stol(line.substr(line[0], line.find('-') ) );
//        long sizeHalf = line.size() / 2;
        
//        get the 2 nums
        std::string wholeID1S = line.substr(0 , line.find('-'));
        std::string wholeID2S = line.substr( (line.find('-') + 1), line.find('-') );
        
        long wholeID1N = std::stol(wholeID1S);
        long wholeID2N = std::stol(wholeID2S);
        
       
        
      //split nums, check for equality
        for (long i = wholeID1N; i <= wholeID2N; i++){
            
            std::string wholeNumS = std::to_string(i);
            
            if( (wholeNumS.size() % 2)  == 0 ){
                
                std::string halfNum1S = wholeNumS.substr(0, wholeNumS.size() / 2);
                std::string halfNum2S = wholeNumS.substr( ( (wholeNumS.size() / 2)), wholeNumS.size() / 2 );
            
                long wholeNum = std::stol(wholeNumS);
                long halfnum1 = std::stol(halfNum1S);
                long halfnum2 = std::stol(halfNum2S);
            
                if(halfnum1 == halfnum2){
                count += wholeNum;
                }
            }
            continue;
                
            
            
        }
                
    
       
    }
    
    std::cout << "the sum of invalid ids is: " << count << '\n';
    
    
        
    return 0;
    //run code here
}
