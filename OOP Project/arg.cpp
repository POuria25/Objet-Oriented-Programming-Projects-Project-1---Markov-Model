#include <iostream>
#include <cstring>
#include <vector>

int main(int argc, char ** argv){

  std::vector <std::string>tData;
  std::vector <std::string>tstData;
  bool check = false;

  if(std::stoi(argv[1]) < 0){
    throw  std::invalid_argument("ORDER MUST BE GREATER THAN ZERO");
  }else{
    unsigned int order = (unsigned int)std::stoi(argv[1]);
    std::cout<< order << std::endl;
  }

  for (int i = 2; i < argc; ++i){
    if(!strcmp(argv[i], "---")){
      check = true;
      i++;
    }
    if(check){
      tstData.push_back(std::string(argv[i]));
    }else{
      tData.push_back(std::string(argv[i]));
    }
  }

  for(unsigned int j = 0; j < tData.size(); j++){
    std:: cout << tData[j] << std::endl;
    for(unsigned int k = 0; k < tstData.size(); k++){
      std:: cout << tstData[k] << std::endl;
    }
  }
    return 0;
}
