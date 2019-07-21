#ifndef _DICTIONARY_SORT_HPP_
#define _DICTIONARY_SORT_HPP_

#include <iostream>
#include <vector>
#include <map>
#include <string>

class Dictionary_sort_ex : public std::runtime_error
{
  public:

  explicit Dictionary_sort_ex(const char* msg) : std::runtime_error(msg)
  {

  }

  explicit Dictionary_sort_ex(std::string& msg) : std::runtime_error(msg)
  {

  }

  virtual ~Dictionary_sort_ex() noexcept
  {

  }

  virtual const char* what() const noexcept
  {
    return std::runtime_error::what();
  }
};

template<class T>
class Dictionary_sort
{
  public:

  Dictionary_sort();

  Dictionary_sort(std::vector<T>& data, bool construct_map = false);

  bool Sort(std::vector<T>& res);
  std::vector<T> Sort() noexcept(false);

  virtual ~Dictionary_sort();

  private:

  void Construct_map();

  std::vector<T>           data_;
  std::map<T, std::size_t> map_;
  bool map_constructed_;
};

#endif // _DICTIONARY_SORT_HPP_
