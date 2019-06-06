#include "dictionary_sort.hpp"

using namespace std;

template<class T>
Dictionary_sort<T>::Dictionary_sort()
{

}

template<class T>
Dictionary_sort<T>::Dictionary_sort(vector<T>& data, bool construct_map)
  : data_(data), map_constructed_(false)
{
  if (construct_map)
  {
    this->Construct_map();
  }
}

template<class T>
bool  Dictionary_sort<T>::Sort(vector<T>& res)
{
  if (0 == data_.size())
  {
    cerr << "No objects in data_\n";
    return false;
  }

  if (0 != res.size())
  {
    cerr << "Provide an empty vector in res variable (reserve space is OK)\n";
    return false;
  }
    
  if (false == map_constructed_)
  {
    this->Construct_map();
  }

  for (pair<T, size_t> t : map_)
  {
    for (size_t i {}; i < t.second; ++i)
    {
      res.push_back(t.first);
    }
  }

  return true;
}

template<class T>
Dictionary_sort<T>::~Dictionary_sort()
{
  data_.clear();
  data_.shrink_to_fit();

  map_.clear();
}

template<class T>
void Dictionary_sort<T>::Construct_map()
{
  for (T curr : data_)
  {
    auto res { map_.find(curr) };

    if (map_.end() == res)
    {
      // This key is not in the map yet, insert it there.

      map_.insert( {curr, 1} );
    }
    else
    {
      // There was such key in the map, inc the counter.

      map_.at(curr)++;
    }
  }

  map_constructed_ = { true };
}

int main()
{
  vector<int> in{ 1, 2, 4, 8, 0, 6, 5, 4, 3, 3, 1, 0 };

  Dictionary_sort<int> ds(in, true);

  vector<int> res;

  bool succ = ds.Sort(res);

  if (succ)
  {
    for (int i : res)
    {
      cout << i << ' ';
    }

    cout << endl;
  }
  else
  {
    cerr << "Failure\n";
  }

  cin.get();

  return 0;
}
