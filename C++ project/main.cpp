//
//  main.cpp
//  C++ project
//
//  Created by HaiNt on 4/7/17.
//  Copyright © 2017 HaiNt. All rights reserved.
//

#include <iostream>
#include "maze.hpp"
#include <time.h>
int main(int argc, const char * argv[]) {
  // insert code here...
//  std::vector<std::vector<int>> data = {{-2,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,-3,-1}};
//  std::vector<std::vector<int>> data = {{-2,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,-3}};
//  std::vector<std::vector<int>> data = {{-2,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,-3}}; //104
//  std::vector<std::vector<int>> data = {{-2,0,0,0,0},{0,0,0,0,0},{0,0,0,-3,-1}};
//    std::vector<std::vector<int>> data = {{-2,0,0,0,0,0,0},{0,0,0,0,0,0,0},{0,0,0,0,0,0,0},{0,0,0,0,0,0,0},{0,0,0,0,0,0,-3}};
  std::vector<std::vector<int>> data = {{-2,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,-3,0}};
//  std::vector<std::vector<int>> data = {
//    {-2, 0, 0, 0, 0, 0, 0},
//    {0, 0, 0, 0, 0, 0, 0},
//    {0, 0, 0, 0, 0, 0, 0},
//    {0, 0, 0, 0, 0, 0, 0},
//    {0, 0, 0, 0, 0, 0, 0},
//    {0, 0, 0, 0, 0, 0, 0},
//    {0, 0, 0, 0, -3, -1, -1}};
//
  
//  std::vector<std::vector<int>> data = {
//    {-2, 0, 0, 0, 0, 0, 0, 0, 0},
//    {0 , 0, 0, 0, 0, 0, 0, 0, 0},
//    {0 , 0, 0, 0, 0, 0, 0, 0, 0},
//    {0 , 0, 0, 0, 0, 0, 0, 0, 0},
//    {0 , 0, 0, 0, 0, 0, 0, 0, 0},
//    {0 , 0, 0, 0, 0, 0, 0, 0, 0},
//    {0 , 0, 0, 0, 0, 0, 0, 0, 0},
//    {0 , 0, 0, 0, 0, 0, 0, 0, 0},
//    {0, 0, 0, 0, 0, 0, -3, -1, -1}};
//
//  2 0 0 0 0 0 0
//  0 0 0 0 0 0 0
//  0 0 0 0 0 0 0
//  0 0 0 0 0 0 0
//  0 0 0 0 0 0 0
//  0 0 0 0 0 0 0
//  0 0 0 0 3 1 1
  maze mazeProcess(data);
  mazeProcess.reload();
  
  time_t start;
  start = time(NULL);
  std::cout << "START: "<<start <<"\n";
//  mazeProcess.maze_process(data);
  mazeProcess.maze_process();
  

  time_t END;
  END = time(NULL);

  
  for(int i = 0; i < mazeProcess.m_out.size(); i++)
  {
    std::cout<<"\n";
    for(std::vector<int>::iterator it = mazeProcess.m_out[i].begin(); it!= mazeProcess.m_out[i].end(); it++)
    {

      if(*it < 0)
        {
          std::cout<<"Start/End: "<<*it;
        }
      else
      {
        int line = 0;
        int colume = 0;
        line = *it/mazeProcess.m_colume;
        colume =*it - (line * mazeProcess.m_colume);
        std::cout<<" A["<<line<<"]["<<colume<<"] ";
      }


    }
    std::cout<<"\n";
//    std::cout<<"sucess";
  }
  
  std::cout << "END: "<<END <<"\n";
  std::cout << "Total time: "<<END -start <<"   Total road:"<<mazeProcess.m_out.size()<<"\n";
  
  
  
  std::cout << "Finish \n";
  
  
  
  
    return 0;
}
