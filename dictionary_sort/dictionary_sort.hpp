#ifndef _DICTIONARY_SORT_HPP_
#define _DICTIONARY_SORT_HPP_

#include <iostream>
#include <vector>
#include <map>
#include <string>

template<class T>
class Dictionary_sort
{
  public:

  Dictionary_sort();

  Dictionary_sort(std::vector<T>& data, bool construct_map = false);

  bool Sort(std::vector<T>& res);

  ~Dictionary_sort();

  private:

  void Construct_map();

  std::vector<T>      data_;
  std::map<T, std::size_t> map_;
  bool map_constructed_;
};

#endif // _DICTIONARY_SORT_HPP_
