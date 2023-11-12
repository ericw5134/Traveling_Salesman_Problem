#include "listofpoints.hpp"
#include <vector>

using namespace std;

ListOfPoints::ListOfPoints() {
  // cout << constructor for listofpoints activated << endl;
}

// add newPt after the given point's name 
void ListOfPoints::addAfter(Point& newPt, string name) {
  int i = 0;
  // ----loop through the vector using an iterator----
  for(vector<Point> :: iterator it = m_points.begin(); it != m_points.end(); it++){
    // ----if the name is found, use the .insert() function to add newPt
    if(m_points[i].getName() == name){
      m_points.insert(it + 1, newPt);
      break;  // end the loop
    }
    i++;
  }
}

// remove the point from the vector with the given name
void ListOfPoints::remove(Point& pt, string name){
  int i = 0;
  // ----loop through the vector using an iterator----
  for(vector<Point> :: iterator it = m_points.begin(); it != m_points.end(); it++){
    // ----if the name is found, use the .erase() function to remove the Pt
    if(m_points[i].getName() == name){
      m_points.erase(it);
      break;  // end the loop
    }
    i++;
  }
}

// adds a new point to the end of the list
void ListOfPoints::addPoint(Point& newPt)  {
  m_points.push_back(newPt);
}

int ListOfPoints::getPosition(Point& pt){
  int position = 0;
  int size = m_points.size();
  for (int i = 0; i < size; i++){
    if (pt.getName() == m_points[i].getName()){
      position = i;
      break;
    }
  }
  return position;
}

// gets a point from the list at index i
Point& ListOfPoints::getPointAt(unsigned int i) {
  return m_points[i];
}

// gets the size of the list
int ListOfPoints::getSize() const {
  return m_points.size();
}

// prints the list of points
void ListOfPoints::printList() const {
  int size = m_points.size();
  for (int i = 0; i < size; i++){
    cout << m_points.at(i) << endl;
  }
}



// draws the points
void ListOfPoints::draw() const {

  int size = m_points.size();

  // ----y values, starting from top to bottom----
  for (int i = 20; i > -1; i--){

    // ----x values. starting from left to right----
    for (int j = 0; j < 21; j++){

      int check = 0;  // to determine if name is printed
      bool skip = false;  // to see if 2 points are identical, skip printing the name if true

      // ----loop through every elem in m_points----
      for (int elem = 0; elem < size; elem++){

        // ----if x & y values match with j & i, print the name of that element---- 
        // ----update check & skip according to the situation----

        // ----if 2 points are identical, only print the first printed name----
        // i.e. A=[0,0] & B=[0,0], if A is already printed, don't print B
        // test4 shows how it is done
        if (elem > 0){
          int i = elem;
          while (i >= 0){
            if (m_points[elem].getX() == m_points[i-1].getX() && m_points[elem].getY() == m_points[i-1].getY()){
              skip = true;
            }
            i--;  
          }
        }
        // ----print name is skip is changed to true----
        if (!skip){
          if (i == m_points[elem].getY() && j == m_points[elem].getX()){
            cout << m_points[elem].getName();
            check = 1; 
          }
        }
      }
  
      // ----print "-" instead if name wasn't printed
      if (check == 0)
        cout << "-" ;
    }
    // move to next line
    cout << "" << endl;
  }
}
 
