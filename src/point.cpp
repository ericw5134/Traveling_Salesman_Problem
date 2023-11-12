#include "point.hpp"
#include <cmath>


float Point::getDistance(const Point &other) const { 

  // ----getting the values of parameter----
  int x2 = other.getX();
  int y2 = other.getY();

  // ----getting the values of origin----
  int x1 = this->getX();
  int y1 = this->getY();

  // ----for simplicity sake----
  //float dummy_x = (x2-x1)*(x2-x1);
  //float dummy_y = (y2-y1)*(y2-y1);
  
  // ----distance formula----
  float distance = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
  
  return distance;
}

string Point::toString() const {
  // examples how to create string from small parts
  string str(m_name);
  str += " = (";
  str += std::to_string(m_x);
  str.append(",").append(std::to_string(m_y)).append(")");
  return str;
}


void Point::printPoint() const {
  cout << toString() << endl;
}

// used for printing Point using << operator.
// For example, the following code will work
// Point origin(0,0,'O');
// cout << origin;
ostream& operator<<(ostream &os, const Point &p) {
  return os << p.toString();
}
