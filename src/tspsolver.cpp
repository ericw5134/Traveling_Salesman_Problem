#include "tspsolver.hpp"

TSPSolver::TSPSolver(ListOfPoints &list) {
  m_list = list;
}

void TSPSolver::solve() {

  // ----dummy cycle for testing----
  TSPCycle m_tester;

  // ----getting the size of the taken inputTSP----
  int size = m_list.getSize();

  // ----copying the first three elements into both solution & tester----
  for (int dummy = 0; dummy < 3; dummy++){
    m_solution.addPoint(m_list.getPointAt(dummy));
    m_tester.addPoint(m_list.getPointAt(dummy));
  }

  // ----for adding the 3rd - size-1th element---- in m_list
  for (int i = 3; i < size; i++){

    // ----some variables that will be used later
    float shortest_length = 100000000000;  // storing shortest length overall
    int iter_num = 0; // determine rather removing elements is needed or not
    int curr_position = 0; // where the add_needed is stored in m_solution

    // ----for adding elements into m_tester----
    for (int j = 0; j < i; j++){  // or size - 1 if i-1 doesnt work

      // ----points needed----
      Point add_needed = m_list.getPointAt(i);
      cout << "point that needs to be added ---> " << add_needed << endl;
      Point add_after = m_tester.getPointAt(j);
      cout << "add after ---> " << add_after << endl;

      // ----getting the length of the CURRENT m_test----
      m_tester.addAfter(add_needed, add_after.getName());
      float length = m_tester.getLength();

      // ----iter_num will be used later----
      iter_num++;

      // ** IF MORE THAN 1 ITER WAS DONE ** 
      if (iter_num > 1){

        if (length < shortest_length){

          cout << "Current length is smaller than stored" << endl;

          // ----update length----
          shortest_length = length;

          // ----remove the previeously added element----
          Point need_remove = m_solution.getPointAt(curr_position);
          cout << "Point being removed from m_solution: " << need_remove << endl;
          m_solution.remove(need_remove, need_remove.getName());

          // ----add after jth elem in m_solution----
          Point add_to_solu = m_solution.getPointAt(j);
          m_solution.addAfter(add_needed, add_to_solu.getName());
          cout << "m_solution after editing: " << endl;
          m_solution.printList();
          curr_position = m_solution.getPosition(need_remove);

          // ----remove the added elem in m_tester and get ready for next iteration----
          m_tester.remove(add_needed, add_needed.getName());
          cout << "m_tester after editing: " << endl;
          m_tester.printList();
          cout << endl;
        }
        // ----if length is not shorter than currently stored length----
        else if (length >= shortest_length){
          cout << "Current length is not shorter than stored" << endl;
          m_tester.remove(add_needed, add_needed.getName());
          cout << "m_tester after editing: " << endl;
          m_tester.printList();
          cout << endl;
        }
      }
      // **IF ONLY 1 ITER WAS DONE** 
      else {
        // ----if length is shorter than currently stored length----
        if (length < shortest_length){

          cout << "Current length is smaller than stored" << endl;

          // ----update length----
          shortest_length = length;

          // ----add after jth elem in m_solution----
          Point add_to_solu = m_solution.getPointAt(j);
          m_solution.addAfter(add_needed, add_to_solu.getName());
          curr_position = 1;
          cout << "m_solution after editing: " << endl;
          m_solution.printList();

          // ----remove the added elem in m_tester and get ready for next iteration----
          m_tester.remove(add_needed, add_needed.getName());
          cout << endl;
        }
        // ----if length is not shorter than currently stored length----
        else if (length >= shortest_length){
          m_tester.remove(add_needed, add_needed.getName());
          cout << endl;
        }
      }
    }

    // ----update m_tester since we need to use the newly added elem in our next iteration too----
    m_tester = m_solution;
    cout << "m_tester for adding next element: " << endl;
    m_tester.printList();
    cout << "" << endl;
  }
}

TSPCycle& TSPSolver::getSolution() {
  return m_solution;
}
