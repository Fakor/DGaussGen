#include <iostream>
#include <random>
#include <cstdlib>
#include <ctime>

#include "cxxopts.hpp"


int main(int argc, char *argv[]){

  cxxopts::Options options("DGaussGen", "Gaussian noise generator to json format");

  options.add_options()
    ("u,mean", "Mean value", cxxopts::value<double>()->default_value("0"))
    ("d,std", "Standard deviation", cxxopts::value<double>()->default_value("1"))
    ("s,seed", "Start seed", cxxopts::value<long>()->default_value("-1"))
    ("l,limit", "Number of samples generated", cxxopts::value<long>()->default_value("10"))
    ;

  auto result = options.parse(argc, argv);

  double mu = result["mean"].as<double>();
  double stdev = result["std"].as<double>();
  long seed = result["seed"].as<long>();
  if(seed == -1){
    seed = std::time(nullptr);
  }
  long limit = result["limit"].as<long>();
  
  std::default_random_engine gen(seed);

  std::normal_distribution<double> dist(mu,stdev);  

  std::cout << "[";
  int i = 0;
  while(true){
    std::cout << dist(gen);
    if(++i < limit){
      std::cout << ",";
    } else{
      break;
    }
  }
  std::cout << "]\n";      
}
