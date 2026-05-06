#include <iostream>
#include<cstdint>
#include<vector>
#include<math.h>

using namespace std;

//Task 1
/*
Create a program to do bresenham's line drawing!
*/
// void draw_line(vector<int> coords){
//   uint32_t container; // the primary handler for rgba ops -- 8 bits for each channel 
//   return;
// }

int m,y;

void naiveApproach(vector<int> coords){
  m = (coords[2] - coords[0]) / (coords[3] - coords[1]);
  for(int x = coords[0]; x < coords[2]; x++){
    y = round(m*x + coords.back());
    std::cout << "Possible point: ("<< x << " ," << y << ")\n";
  }
}




int main(int argc, char *argv[]) {
  std::cout << "To experiment with bits in c++20 \n";
  vector<int> coord{1,2,9,10,5};
  // naiveApproach(coord);


  return 0;
}