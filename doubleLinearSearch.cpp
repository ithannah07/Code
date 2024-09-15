// Hyeonseo Lee
// Lab 1

#include <iostream>
#include <vector>
using namespace std;

int NOT_FOUND = -1;
/**
 It executes linear search and also finds the indexes of all the search values if there are more than one.
 @param list the vector that indicates the int numbers
 @param search_value the number which user wants to search
 @return result vector which indicates the indexes of search value
 */
vector<int> linearSearch (const vector<int> & list, int search_value);

/**
 It prints the values of search result vector.
 @param searchResult vector that indicates the results of the linear search
 */
void print (const vector<int> & searchResult);


int main() {
  vector<int> array {10, 50, 16, 1, 9, 15, 16, 20, 16, 2, 5};
  int searchValue = 16;
  vector<int> searchResult = linearSearch(array, searchValue);
  cout << "Search value: " << searchValue << endl;
  print(searchResult);
  return 0;
}

vector<int> linearSearch (const vector<int> & list, int search_value)
{
  vector<int> results; // vector that includes the results of the search
  int size = (int)list.size();
  int position = NOT_FOUND;
  int index = 0;
  while (index < size)
  {
    if (list.at(index) == search_value) // if the value is found
    {
      position = index;
      results.push_back(position); // store it into a results vector
      if (results.size() == 2) // when it finds the value two times, the loop wil stop
      {
        break;
      }
    }
    else if (index == size - 1 && results.size() == 1) // if the value is found only once
    {
      results.pop_back(); // delete the position which is saved in the previous step
      results.push_back(NOT_FOUND); // put -1 to the vector
    }
    else if (index == size - 1 && results.size() == 0) //if the value is not found
    {
      results.push_back(position); // put -1 to the results vector
    }
    index++;
  }

  return results;
}

void print (const vector<int> & searchResult)
{
  int size = (int)searchResult.size();
  
  cout << "{" ;
  for(int i = 0; i < size; i++)
  {
    if(i == size-1) // last number of the vector (does not need a comma)
    {
      cout << searchResult.at(i);
    }
    else
    {
      cout << searchResult.at(i) << "," ;
    }
  }
  cout << "}" << endl;
}
