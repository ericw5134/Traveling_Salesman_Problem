void ListOfPoints::draw() const {

  int size = m_points.size();

  // y values
  for (int i = 20; i > -1; i--){

    // x values
    for (int j = 0; j < 21; j++){

      // to determine if name is printed
      int check = 0;

      // loop through every elem in m_points
      for (int elem = 0; elem < size; elem++){
        // if x & y values match with j & i, print the name of that element 
        // update check too
        if (i == m_points[elem].getY() && j == m_points[elem].getX()){
          cout << m_points[elem].getName();
          check = 1;
        }
        if (elem > 0){
          if (m_points[elem].getX() == m_points[elem-1].getX() && m_points[elem].getY() == m_points[elem-1].getY())
            cout << "";
        }
      }
      // if not changed, then name wasnt printed
      // print - instead
      if (check == 0)
        cout << "-" ;
    }
    // move to next line
    cout << "" << endl;
  }
}