#include <iostream>
#include <random>
#include <cstdlib>

int main(int argc, char *argv[]){

  double mu = atoi(argv[1]);
  double var = atoi(argv[2]);

  long limit = atoi(argv[3]);
  long seed = atoi(argv[4]);
  
  std::default_random_engine gen(seed);

  std::normal_distribution<double> dist(mu,var);  

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
