#include<iostream>
#include "markov_model.hpp"
#include <string>
#include <set>
//#include <bits/stdc++.h>
#include <cmath>
#include <regex>
#include <fstream>


void markov_model(Markov_model& ptr, unsigned int order, const std::string& str){
     if(order + 1 > str.length()){
         throw std::length_error("order can not be Greater-than string length\n");
     }

    int index = 0;
    for(auto it = str.begin() ; it != str.end(); it++){
        ptr.alphabet.insert(str[index]);
        index++;
    }

    ptr.order = order;
    std::string tmp = str + str.substr(0, order);
    for(unsigned int j = 0; j < str.size(); j++){
        ptr.model[tmp.substr(j, order)] += 1;
        ptr.model[tmp.substr(j, order + 1)] += 1;
    }
}


double laplace(const Markov_model& ptr, const std::string& str){

    unsigned int ns = 0;
    unsigned int ncs = 0;

    for(auto s : str){
        if(!(ptr.alphabet.find(s) != ptr.alphabet.end()))
        throw std::domain_error("string not in alphabet");
        }

        if(ptr.order+1 != str.size()){
            throw std::length_error("String can not be Greater-than Model\n");
        }else{
            auto search1 = ptr.model.find(str);
        if (!(search1 != ptr.model.end())){
            ncs = 0;
        }else{
        ncs = search1->second;
        }
        auto search2 = ptr.model.find(str.substr(0, str.size()-1));
        if (!(search2 != ptr.model.end())){
            ns = 0;
        }else{
        ns = search2->second;
      }
        }
    return (double) (ncs + 1) / (ns + ptr.alphabet.size());
}

double likelihood(Markov_model& ptr, const std::string& str){

    double sum = 0;
    std::string tmp = str + str.substr(0, ptr.order);
    for(unsigned int j = 0; j < str.size(); j++){
        sum += std::log(laplace(ptr, str.substr(j, ptr.order+1)));
        }

    return sum;
}
