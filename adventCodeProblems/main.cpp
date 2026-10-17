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
    
    
    std::vector<std::vector<char>> grid;
    
    while(getline(file, line, '\n')){
        std::vector <char> row;
        
        for (const char c: line){
            row.push_back(c);
        }
        grid.push_back(row);
        
    }
    
    for(int i = 0; const auto &row : grid){
        for(int j = 0; const char &c: row){
            std::size_t count = 0;
                
                if (c == '@'){
                    if(i < grid.size() - 1 && j < grid[i].size() - 1){
//                        std::cout << "\nwhats happening: " << j << '\n';
                        if(grid[i][j + 1] == '@'){
                        count++;
                        }
                        if(grid[i + 1][j] == '@'){
                        count++;
                        }
                        if(grid[i + 1][j + 1] == '@'){
                        count++;
                        }
                        if(j > 0){
                            if(grid[i + 1][j - 1] == '@'){
                                count++;
                            }
                            if(grid[i][j - 1] == '@'){
                                count++;
                            }
                        }
                        if(i > 0){
                            if(grid[i - 1][j + 1] == '@'){
                                count++;
                            }
                            if(grid[i - 1][j] == '@'){
                                count++;
                            }
                        }
                        if(i > 0 && j > 0){
                            if(grid[i - 1][j - 1] == '@'){
                                count++;
                            }
                        }
                    }
                    else if (j == grid[i].size() - 1){
                    if(i > 0){
                            if(grid[i - 1][j] == '@'){
                            count++;
                            }
                            if(grid[i][j - 1] == '@'){
                            count++;
                            }
                        if(grid[i - 1][j - 1] == '@'){
                            count++;
                        }
                        }
                
                        if(i < grid.size() - 1){
                            if(grid[i + 1][j] == '@'){
                            count++;
                            }
                            if(grid[i + 1][j - 1] == '@'){
                            count++;
                            }
                        }
                    }
                        else if (i == grid.size() - 1){
                            if (grid[i - 1][j] == '@'){
                                count++;
                            }
                            if(j > 0){
                                if(grid[i - 1][j - 1] == '@'){
                                    count++;
                                }
                                if(grid[i][j - 1] == '@'){
                                    count++;
                                }
                            }
                            if(j < grid[i].size()){
                                if(grid[i - 1][j + 1] == '@'){
                                    count++;
                                }
                                
                                if(grid[i][j + 1] == '@'){
                                    count++;
                                }
                            }
                        }
                       
                    if (count < 4){
                        total += 1;
                    }
                }
            std::cout << j + 1 << ":" << '\n';
            std::cout <<"the count is " << count << '\n';
            std::cout << "the total is: " << total <<'\n';
            j++;
        }
        std::cout << '\n' ;
        i++;
    }
        std::cout << "the total output voltage is: " << total << '\n';
    
    return 0;
  
}

