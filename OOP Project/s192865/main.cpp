#include <iostream>
#include "markov_model.hpp"
#include <string>
#include <cstring>
#include <fstream>
#include <vector>
#include<limits>
#include<cmath>



int main(int argc, char** argv){

  std::vector <std::string>tf;
  std::vector <std::string>tstf;
  unsigned int order = 0;

  bool check = false;

  if(std::stoi(argv[1]) < 0){
    throw  std::invalid_argument("ORDER MUST BE GREATER THAN ZERO");
  }
  else{
    order = (unsigned int)std::stoi(argv[1]);
  }

  for(int i = 2; i < argc; ++i){
    if(!strcmp(argv[i], "---")){
      check = true;
      i++;
    }
    if(check){
      tstf.push_back(std::string(argv[i]));
    }
    else{
      tf.push_back(std::string(argv[i]));
    }
  }

  std::ifstream opf;
  std::ifstream opftst;

  for(unsigned int j = 0; j < tstf.size(); j++){  
    std::string tstdata = "";
    double bestLikelihood = -INFINITY;
    double currLikelihood = 0.0;
    std::string bestCase = "-";

    opftst.open(tstf[j], std::ios::in);
    if(opftst.is_open()){
      std::getline(opftst, tstdata);
      opftst.close();
    }
    else{
      std::cerr << "Test File Doesn't Exist or File Still Close [:-(] " << std::endl;
    }
    for(unsigned int k = 0; k < tf.size(); k++){

      std::string trnamedata = "";
      std::string trdata = "";
      Markov_model ptr = Markov_model();
      opf.open(tf[k], std::ios::in);
      if(opf.is_open()){
        std::getline(opf, trnamedata);
        std::getline(opf, trdata);
        opf.close();
        try{
          markov_model(ptr, order, trdata);
        }
        catch(const std::exception& e){
          std::cout << "Markov Model Failed" << std::endl;
        }

        try{
          currLikelihood = likelihood(ptr, tstdata);
        }
        catch(const std::exception& e){
          std::cout << trnamedata << "-" << std::endl;
        }

      }
      else{
        std::cerr << "Data File Doesn't Exist or File Still Close [:-(] " << std::endl;
      }
      std::cout << trnamedata << " : " << currLikelihood << std::endl;

      if(currLikelihood > bestLikelihood){
        bestCase = trnamedata;
        bestLikelihood = currLikelihood;
      }
    }
    std::cout << tstf[j] << " attribited to " << bestCase << std::endl;
  }

  return 0;
}
