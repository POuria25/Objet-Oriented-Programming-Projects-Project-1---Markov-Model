#include <iostream>
#include "markov_model.hpp"
#include <string>
#include <cstring>
#include <fstream>
#include <vector>


int main(int argc, char ** argv){

  std::vector <std::string>tf; //training files
  std::vector <std::string>tstf; //test files
  unsigned int order = 0;

  bool check = false;

  if(std::stoi(argv[1]) < 0){
    throw  std::invalid_argument("ORDER MUST BE GREATER THAN ZERO");
  }else{
    order = (unsigned int)std::stoi(argv[1]);
    std::cout<< "ORDER : " << order << std::endl;

  }

  for (int i = 2; i < argc; ++i){
    if(!strcmp(argv[i], "---")){
      check = true;
      i++;
    }
    if(check){
      tstf.push_back(std::string(argv[i]));
    }else{
      tf.push_back(std::string(argv[i]));
    }
  }

  std::string trnamedata; //data_training's name
  std::string trdata; //data_training
  std::string tstdata; //test data
  std::ifstream opf; //pointer to open data file
  std::ifstream opftst; //pointer to open test data file
  Markov_model ptr;

  for(unsigned int j = 0; j < tf.size(); j++){
    std:: cout << "File name : " << tf[j] << std::endl;
    opf.open(tf[j], std::ios::in);
        if(opf.is_open()){
            std:: cout << "File is opened"<< std::endl;
            //std:: cout << "######################################\n \n"<< std::endl;
            std::getline(opf, trnamedata);
            std::getline(opf, trdata); //check point : if the dataname corresponding to filename
            std:: cout << "Data name : " << trnamedata<<std::endl;
            //std:: cout << "######################################\n \n"<< std::endl;
            //std:: cout <<"Data :" << trdata<<std::endl;
            //std:: cout << "######################################\n \n"<< std::endl;
            markov_model(ptr,order, trdata);
          opf.close();
        }
    for(unsigned int k = 0; k < tstf.size(); k++){
    std:: cout << "File name : " << tstf[k] << std::endl;
    opftst.open(tstf[k], std::ios::in);
        if(opftst.is_open()){
            std:: cout << "Test File is opened \n" << std::endl;
            std:: getline(opftst, tstdata);
            //std:: cout <<"Test Data : " << tstdata << std::endl;
            std:: cout << "Likelihood : " << likelihood(ptr,tstdata) << std::endl;
          opftst.close();
        }
    }
  }

    return 0;
}
