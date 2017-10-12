//
//  maze.cpp
//  C++ project
//
//  Created by HaiNt on 10/5/17.
//  Copyright © 2017 HaiNt. All rights reserved.
//

#include "maze.hpp"
#include <vector>


void maze::maze_process()
{
//  std::vector<std::vector<std::string>> output;
  point_data start;
  start.i_point = m_start_point[0];
  start.j_point = m_start_point[1];
  start.total_step = 1;
  start.total_sum = START_POINT;
  start.road_map.push_back(m_data[start.i_point][start.j_point]);
  
  std::vector<point_data> tmp;
  tmp.push_back(start);
  int step = 0;
  while(true)
    {
      step ++;
      
      if(tmp[0].total_step == m_total_node)
      {
        for(int i = 0; i < this->m_out.size(); i++)
        {
          std::cout<<"\n";
          for(std::vector<int>::iterator it = m_out[i].begin(); it!= m_out[i].end(); it++)
          {
      
      
            std::cout<<" "<<*it;
      
          }
          std::cout<<"\n";
          //    std::cout<<"sucess";
        }
      }
      
       tmp =  this->point_extend(tmp);
      
      if(tmp.size() == 0)
        break;
      
      
//      if(tmp[0].total_step  0)
//      {
//        tmp = this->road_compress(tmp);
      std::cout<<"Step:"<<tmp[0].total_step<< " size: "<<tmp.size()<<" \n";
//      }
      

    }
  

////  this->point_extend(tmp);

}

void maze::maze_start()
{
  
  std::vector<int> road_map;
  int count = 0;

}


//EXTEND Point up, down, lef, right
std::vector<point_data> maze::point_extend(std::vector<point_data> &input)
{
  std::vector<point_data> point_return;
  
  for(int i = 0; i < input.size(); i++ )
  {
    //lef
    point_data lef;
    point_data right;
    point_data up;
    point_data down;

    //lef
    lef.i_point = input[i].i_point;
    lef.j_point = input[i].j_point -1;
    lef.total_step =input[i].total_step;
    lef.total_sum = input[i].total_sum;
    lef.road_map = input[i].road_map;

    //right
    right.i_point = input[i].i_point;
    right.j_point = input[i].j_point +1;
    right.total_step =input[i].total_step;
    right.total_sum = input[i].total_sum;
    right.road_map = input[i].road_map;


    //up
    up.i_point = input[i].i_point -1;
    up.j_point = input[i].j_point;
    up.total_step =input[i].total_step;
    up.total_sum = input[i].total_sum;
    up.road_map = input[i].road_map;

    //down
    down.i_point = input[i].i_point +1;
    down.j_point = input[i].j_point;
    down.total_step =input[i].total_step;
    down.total_sum = input[i].total_sum;
    down.road_map = input[i].road_map;
    
    std::vector<point_data> point_neighbour;
    point_neighbour.push_back(lef);
    point_neighbour.push_back(right);
    point_neighbour.push_back(up);
    point_neighbour.push_back(down);
    
    bool oneWayFlg = false;
    for (int k = 0; k < point_neighbour.size(); k++)
    {
      point_neighbour[k].multi_road_map = input[i].multi_road_map;
      point_neighbour[k].validate = this->validate(point_neighbour[k]);
      if(point_neighbour[k].neighbour == 1 && point_neighbour[k].validate == true)
      {
        oneWayFlg = true;
      }
    }
    
    
    for (int k = 0; k <point_neighbour.size(); k++)
    {
      if(point_neighbour[k].validate == false)
      {
        continue;
      }
//
      if (oneWayFlg == true && point_neighbour[k].neighbour == 1)
      {
        point_return.push_back(point_neighbour[k]);
      }

      if(oneWayFlg == false && point_neighbour[k].neighbour >=2)
      {
        point_return.push_back(point_neighbour[k]);
      }
      
//      full
//      point_return.push_back(point_neighbour[k]);
    }
    
  }
  
  return point_return;
  
}


//validate point
bool maze::validate(point_data &point)
{
  /////test
//  std::vector<int> tmp = point.road_map;
//  if(
//     tmp[1] == 1 &&
//     tmp[2] == 2 &&
//     tmp[3] ==3 &&
//     tmp[4] == 4 &&
//     tmp[5] == 9 &&
//     tmp[6] == 8 &&
//     tmp[7] == 7 &&
//     tmp[8] == 6 &&
//     tmp[9] == 5 &&
//     tmp[10] == 10 &&
//     tmp[11] == 11 &&
//     tmp[12] == 12 &&
//     tmp[13] == 13 &&
//     tmp[14] == 14 &&
//     tmp[15] == 19 &&
////     tmp[16] == 18 &&
////     tmp[17] == 17 &&
////     tmp[18] == 16 &&
////     tmp[19] == 15 &&
////     tmp[20] == 20 &&
////     tmp[21] == 21 &&
////     tmp[22] == 22 &&
////     tmp[23] == 23 &&
//     tmp[0] == -2
//     )
//  {
//    std::cout<<"debug";
//  }
//
  
  
  /////
  //check i, j
  if (point.i_point < 0 || point.j_point < 0 || point.i_point >=m_line || point.j_point >=m_colume)
  {
    return false;
  }
  
  int point_value = m_data[point.i_point][point.j_point];
  
  //check ignore poit
  if (point_value == IGNORE_POINT) {
    return false;
  }
  
  std::vector<int>::iterator it;
  it = std::find(point.road_map.begin(), point.road_map.end(), point_value);
  
  if(it != point.road_map.end())
  {
    //already exit
    return false;
  }
  
  point.neighbour = count_neighbor(point);
  
  point.road_map.push_back(point_value);
  point.total_step = point.total_step +1;
  point.total_sum += point_value;
  
  
  //check success
//  if (point.total_step == m_total_node && point_value == END_POINT  && point.total_sum == m_total_sum)
  if (point.total_step == m_total_node)
  {
//    std::cout<<"on sucess \n";
    std::vector<int> newmap = point.road_map;
    m_out.push_back(point.road_map);
    
    return false;
  }
  
  
  return true;
  
}


//ai validate

bool maze::ai_validate(point_data &point)
{
  return false;
}

int maze::count_neighbor(point_data point)
{
  
  //check end point
  if(m_data[point.i_point][point.j_point] == END_POINT && point.total_step < m_total_node -1)
    return 0;
  
  int count = 0;
  
  for (int i = point.i_point -1; i < point.i_point + 2; i++)
  {
    for (int j = point.j_point -1; j < point.j_point + 2; j++)
    {
      //check i, j
      if (i < 0 || j < 0 || i >=m_line || j >=m_colume)
      {
        continue;
      }
      
      if(i != point.i_point && j !=point.j_point )
      {
        continue;
      }
      
      if(i == point.i_point && j ==point.j_point )
      {
        continue;
      }
      
      //SEARCH
      if(search(point.road_map, m_data[i][j]) == false &&  m_data[i][j] != IGNORE_POINT)
      {
        count ++;
      }
      
    }
  
  }
  
  return count;
}

//search
bool maze::search(std::vector<int> map, int value)
{
  std::vector<int>::iterator it;
  it = std::find(map.begin(), map.end(), value);
  
  if(it != map.end())
  {
    //already exit
    return true;
  }
  return false;
}


bool sort_function(point_data first, point_data second)
{
  return (first.total_sum < second.total_sum);
}

std::vector<point_data> maze::road_compress(std::vector<point_data> &in)
{
  
  
  std::vector<point_data> out_put;
  
  //sort
  std::sort(in.begin(), in.end(), sort_function);
  
  out_put.push_back(in[0]);
  
  
  for(int i = 0; i < in.size(); i++)
  {
    int size_output = out_put.size();
    
    if (in[i].total_sum == out_put[size_output -1].total_sum)
    {
      //update output
      if (compare_vector(out_put[size_output -1].road_map, in[i].road_map))
      {
        out_put[size_output -1].multi_road_map.push_back(in[i].road_map);
      }
      else
      {
        out_put.push_back(in[i]);
      }
      
    }
    else
    {
      //add more
      out_put.push_back(in[i]);
    }
    
    
  }
  
  
  return out_put;
}


//compare vector

bool maze::compare_vector(std::vector<int> first, std::vector<int> second)
{
  for(int i = 0; i < first.size(); i++)
  {
    if(search(second, first[i]) == false)
      return false;
  }
  return true;
}

maze::maze(std::vector<std::vector<int>> data_in):m_data(data_in)
{
  
  //start get size,
 
}

void maze::reload()
{
  m_total_node = 0;
  m_line = m_data.size();
  m_colume = 1000;
  
  for (int i =0; i<m_data.size(); i++)
  {
    if(m_data[i].size() < m_colume)
    {
      m_colume = m_data[i].size();
    }
  }
  //end get size
  
  
  for (int i = 0; i < m_line; i++)
  {
    for (int j = 0; j <m_colume; j++)
    {
      if(m_data[i][j] == START_POINT)
      {
        //get start point
        m_start_point[0] = i;
        m_start_point[1] = j;
      }
      
      if(m_data[i][j] == END_POINT)
      {
        //get end point
        m_end_point[0] = i;
        m_end_point[1] = j;
      }
      
      //ignore -1
      if (this->m_data[i][j] == IGNORE_POINT)
      {
        continue;
      }
      
      //count
      if(m_data[i][j] != START_POINT && m_data[i][j] != END_POINT)
        m_data[i][j] = i * m_colume + j;
      
      m_total_sum = m_total_sum + m_data[i][j];
      m_total_node++;
    }
  }
  
  //total node start
  m_total_node_from_start = m_total_node/2;
  //total node from end
  m_total_node_from_end = m_total_node - m_total_node_from_start +1;
}
