#include <iostream>
#include <fstream>
using namespace std;

// output format to use IDENTICALLY:
//BSH:Saru> ./filesize input.3lines input.1line 
//program: ./filesize
// input.3lines: 3
// input.1line: 1

int main( int argc, char* argv[] )
{
    // just to get you started, this is how to refer to the arguments that were passed
    for (int arg = 0; arg < argc; ++arg){
        string line;
        int count = 0;
        if(arg == 0){
            std::cout << "program: " << argv[arg] << '\n' ;
        }else{
            ifstream inFile(argv[arg]);
            if(inFile.fail() || inFile.peek() == EOF){
                std::cout << " " << argv[arg] << ": -1" << '\n' ;
            }else{
                while(inFile.peek() != EOF){
                    getline(inFile, line);
                    count++;
                }
                inFile.close();
                std::cout << " " << argv[arg] << ": " << count << '\n' ;
            }    
        }
    }
    exit(0); // this means that the program executed correctly!
}
