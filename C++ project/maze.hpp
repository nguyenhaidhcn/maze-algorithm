//
//  maze.hpp
//  C++ project
//
//  Created by HaiNt on 10/5/17.
//  Copyright © 2017 HaiNt. All rights reserved.
//

#define START_POINT -2
#define END_POINT -3
#define IGNORE_POINT -1

#ifndef maze_hpp
#define maze_hpp

#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include <iostream>

#endif /* maze_hpp */

struct point_data
{
  int i_point;
  int j_point;
  int total_step;
  int total_sum;
  std::vector<int> road_map;
  std::vector<std::vector<int>> multi_road_map;
  bool validate;
  int neighbour;
};

class maze
{
private:
  std::vector<std::vector<int>> m_data;
  

  int m_total_sum;
  int m_total_node;
  int m_total_node_from_start;
  int m_total_node_from_end;
  int m_start_point[2];
  int m_end_point[2];
  

public:
  std::vector<std::vector<int>> m_out;
  void maze_process();
  void maze_start();
  void maze_end();
  int m_line;
  int m_colume;
  std::vector<point_data> point_extend(std::vector<point_data> &in);
  
  std::vector<point_data> road_compress(std::vector<point_data> &in);
  
  bool validate(point_data &point);
  
  bool ai_validate(point_data &point);
  
  int count_neighbor(point_data point);
  
  bool search(std::vector<int> map, int value);
  
  bool compare_vector(std::vector<int> first, std::vector<int> second);
  
  maze();
  maze(std::vector<std::vector<int>> data_in);
  void reload();
  
  
};
