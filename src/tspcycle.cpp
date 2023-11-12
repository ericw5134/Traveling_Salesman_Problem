#include <iostream>

#include "tspcycle.hpp"

TSPCycle::TSPCycle() {
}

// returns the length of the cycle
// returns the length of the cycle
float TSPCycle::getLength() const {
  // ----initalizing variables----
  float result = 0;
  int size = getSize();

  // ----loop through the list----
  for (int i = 0; i < size; i++){
    // ----if reached the end, add from end->beginning----
    if (i+1 >= size){
      result += m_points[i].getDistance(m_points[0]);
    }
    // ----add from current->next----
    else {
      result += m_points[i].getDistance(m_points[i+1]);
    }
  }
  return result;
}
