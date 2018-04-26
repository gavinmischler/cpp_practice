#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::vector;

vector<int> ReadValues(vector<int> &data)
{
  int number;
  cout << "Enter as many integers as you want. Enter 0 to end. \n";
  do {
    cin >> number;
    data.push_back(number);
  } while(number);
  //cout << "size is " << int(data.size()) << "\n";
  return data;
}

double findaverage(vector<int> &data)
{
  int sum = 0;
  const int sz = data.size();
  cout << sz << "\n";
  for (int i = 0; i < data.size(); i++)
  {
    sum += data[i];
  }
  cout << "sum: " << sum << "\n";
  return double(sum)/(sz-1);
}

int main()
{
  vector<int> data;
  data = ReadValues(data);
  cout << "Vector contains: \n";
  for (int i = 0; i < data.size(); i++) {
    cout << " " << data[i];
  }

  cout << "\n The average is: " << findaverage(data);
  return 0;
}
