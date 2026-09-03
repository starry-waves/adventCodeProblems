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
    
    int pos = 50;
    int count = 0;
    
    while(getline(file, line)){
        const char direction = line[0];
        int rotation = std::stoi(line.substr(1 , line.size() - 1));
        int modrotation = rotation % 100;
        count += rotation / 100;
        int oldpos = pos;
        switch(direction){
            case 'L':
                pos -=modrotation;
                if(pos < 0){
                    if (oldpos != 0){
                        count++;
                    }
                    
                    pos += 100;
                }
                
                if(pos == 0){
                    count++;
                }
                break;
                
            case 'R':
                pos += modrotation;
                if(pos >= 100){
                    count++;
                    pos -=100;
                }
                break;
        }
       
    }
    
    std::cout << "the password is: " << count << '\n';
    
    
        
    return 0;
    //run code here
}
