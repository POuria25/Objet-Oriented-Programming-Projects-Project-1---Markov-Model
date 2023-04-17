#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv){

  std::string x;
  std::string y;

  std::ifstream myfile;

  for(int i = 1; i < argc; ++i){

        myfile.open(argv[i]);

        if(myfile.is_open()){
          std::getline(myfile, x);
          std::getline(myfile, y);

          std::cout << x << '\n';
          std::cout << y << '\n';

          myfile.close();
        }

  }
 }
