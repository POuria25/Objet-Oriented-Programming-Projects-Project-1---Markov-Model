#include<iostream>
#include<set>
#include<map>

typedef std::set<char> Alphabet;
typedef std::map<std::string, unsigned int> Model;


struct Markov_model
{
    unsigned int order;
    Alphabet alphabet;
    Model model;
};


void markov_model(Markov_model& , unsigned int, const std:: string&);

double laplace(const Markov_model&, const std::string&);

double likelihood(Markov_model&, const std::string&);