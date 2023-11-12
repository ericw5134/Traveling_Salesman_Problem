#include <iostream>
#include <cstdlib>

#include "point.hpp"
#include "listofpoints.hpp"
#include "tspsolver.hpp"
#include "tspcycle.hpp"

using namespace std;

void testPoint() {
  Point origin(0,0,"ORIGIN");
  cout << "--print using printPoint():" << endl;
  origin.printPoint();
  cout << "--print using toString():" << endl;
  cout << origin.toString() << endl;
  cout << "--print using << operator:" << endl;
  cout << origin << endl;
  
  
  Point q(3,4,"Q");
  // distance should be 5
  cout << "distance between ORIGIN and Q is " << q.getDistance(origin) << endl;

}

void testCycle(){

  Point p_a(0, 0, "A");
  Point p_b(0, 2, "B");
  Point p_c(2, 2, "C");
  Point p_d(2, 0, "D");

  TSPCycle testcycle;

  testcycle.addPoint(p_a);
  testcycle.addPoint(p_c);

  testcycle.addAfter(p_b, "A");
  testcycle.addAfter(p_d, "C");

  testcycle.printList();
  float len = testcycle.getLength();
  cout << "LENGTH OF THE CYCLE IS: " << len << endl;

  // Should be length 8
  // B - C
  // |   |
  // A - D  

}

// gets a list of points and runs the solver on this list
// used in test1 and test2 below
void testSolver(ListOfPoints &input) {
  cout << "---run the solver---" << endl;
  TSPSolver solver(input);
  solver.solve();
  TSPCycle solution = solver.getSolution();


  cout << "Solution found is: " << endl;
  solution.printList();
  cout << "the length of the solution is: " << solution.getLength() << endl;
}

// -----------------------------------------------------------------------------------------------------------------------------------
// ----test cases---- 

// ----test 1----
// ----only 3 points----
void test1() {
  Point p[3] = {Point(2,2,"A"),
                Point(2,6,"B"),
                Point(5,6,"C")};

  cout << "Creating a list of points:" << endl;
  ListOfPoints inputTSP;
  for (int i=0;i<3;i++){
    cout << "adding "<< i << "th time" << endl;
    inputTSP.addPoint(p[i]);
  }
  cout << "Printing the list:" << endl;
  inputTSP.printList();  
  inputTSP.draw();

  testSolver(inputTSP);
}

// ----test 2----
// ----from (0,0), (1,1) -> (20,20)----
void test2() {
  ListOfPoints inputTSP;
  Point p(0,0,"A");
  cout << "Creating a list of points:" << endl;

  for (int i=0;i<21;i++) {
    string s;
    s = 'A'+i;
    p = Point(i,i,s);
    inputTSP.addPoint(p);
  }
  
  cout << "Printing the list:" << endl;
  inputTSP.printList();  
  inputTSP.draw();  

  testSolver(inputTSP);
}

// ----test 3----
// ----random points in the 1000x1000 range----
void test3() {
  ListOfPoints inputTSP;
  Point p(0,0,"O");
  cout << "Creating a list of points:" << endl;

  for (int i=0;i<51;i++) {
    p = Point(rand() % 1000, rand() % 1000, to_string(i));
    inputTSP.addPoint(p);
  }
  
  cout << "PRINTING LIST" << endl;
  inputTSP.printList(); 
  cout << "DRAWING GRAPH" << endl;
  inputTSP.draw();  // some coordinates values more than 20, so we do not use draw here

  
  testSolver(inputTSP);
}

// ----test 4----
// ----5 of the same points----
void test4() {
  Point p[5] = {Point(0,0,"A"),
                Point(0,0,"B"),
                Point(0,0,"C"),
                Point(0,0,"D"),
                Point(0,0,"E")};

  cout << "Creating a list of points:" << endl;
  ListOfPoints inputTSP;
  for (int i=0;i<5;i++){
    cout << "adding "<< i << "th time" << endl;
    inputTSP.addPoint(p[i]);
  }
  cout << "Printing the list:" << endl;
  inputTSP.printList();   
  inputTSP.draw();

  testSolver(inputTSP);
}

// ----test 5----
// ----a few random points----
void test5() {
  ListOfPoints inputTSP;
  Point p[11] = {
    Point(1, 1, "A"),
    Point(6, 1, "B"),
    Point(8, 1, "C"),
    Point(10, 1, "D"),
    Point(3, 3, "E"),
    Point(6, 3, "F"),
    Point(1, 4, "G"),
    Point(5, 4, "H"),
    Point(8, 4, "I"),
    Point(3, 7, "J"),
    Point(6, 7, "K")
  };
  for (int i = 0; i < 11; i++) inputTSP.addPoint(p[i]);
  cout << "Printing the list:" << endl;
  inputTSP.printList();
  cout << "\n";
  inputTSP.draw();
  testSolver(inputTSP);
}

// ---test 6----
// ----all verticle points with (0, __)----
void test6() {
  ListOfPoints inputTSP;
  Point p(0,0,"A");
  cout << "Creating a list of points:" << endl;

  for (int i=0;i<21;i++) {
    string s;
    s = 'A'+i;
    p = Point(0,i,s);
    inputTSP.addPoint(p);
  }
  
  cout << "Printing the list:" << endl;
  inputTSP.printList();  
  inputTSP.draw();  

  testSolver(inputTSP);
}

// test 7
// "fence" 
void test7() {
  ListOfPoints inputTSP;
  Point p(0,0,"A");
  cout << "Creating a list of points:" << endl;

  for (int i=0;i<21;i++) {
    p = Point(0,i,"i");
    inputTSP.addPoint(p);
  }

  for (int i=1;i<21;i++) {
    p = Point(i,0,"i");
    inputTSP.addPoint(p);
  } 

  for (int i = 1; i<21; i++){
    p = Point(20, i, "i");
    inputTSP.addPoint(p);
  }

  for (int i = 1; i < 20; i++){
    p = Point(i, 20, "i");
    inputTSP.addPoint(p);
  }

  cout << "Printing the list:" << endl;
  inputTSP.printList();  
  inputTSP.draw();  

  testSolver(inputTSP);
}

void test14() {
  ListOfPoints inputTSP;
  Point p[9] = {
    Point(3, 5, "L"),
    Point(4, 5, "U"),
    Point(5, 5, "V"),
    Point(7, 5, "Y"),
    Point(8, 5, "A"),
    Point(4, 4, "I"),
    Point(5, 4, "G"),
    Point(6, 4, "O"),
    Point(7, 4, "R")
  };
  for (int i = 0; i < 9; i++) inputTSP.addPoint(p[i]);
  cout << "Printing the list:" << endl;
  inputTSP.printList();
  inputTSP.draw();
  testSolver(inputTSP);
}

// ----------------------------------------------------------------------------------------------------------------------------------

int main() {

  cout << "****test1**:" << endl;
  //test1();
  cout << "****end of test1**:" << endl << endl;
 
  cout << "****test2**:" << endl;
  //test2();
  cout << "****end of test2**:" << endl << endl;

  cout << "****test3**:" << endl;
  //test3();
  cout << "****end of test3**:" << endl << endl;

  cout << "****test4**:" << endl;
  //test4();
  cout << "****end of test4**:" << endl << endl;

  cout << "****test5**:" << endl;
  test5();
  cout << "****end of test5**:" << endl << endl;

  cout << "****test6**:" << endl;
  //test6();
  cout << "****end of test6**:" << endl << endl;

  cout << "****test7**:" << endl;
  //test7();
  cout << "****end of test7**:" << endl << endl;

  cout << "****test14**:" << endl;
  //test14();
  cout << "****end of test14**:" << endl << endl;

  return 0;
}
