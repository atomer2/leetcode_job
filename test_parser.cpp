#include "utils.h"
#include <iterator>

int main(int argc, char** argv){
  for(int i=1; i<argc; i++){
    auto vec = parseIntVector(argv[i]);
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
  }

  return 0;
}
