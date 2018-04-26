#include <iostream>
using std::cin;
using std::cout;
using std::endl;


double findaverage(int array[])
{
  int sum = 0;
  for (int i = 0; i < 5; i++)
  {
    sum += array[i];
    cout << array[i] << endl;
  }
  cout << "sum: " << sum << endl;
  const double divisor = 5.0;
  return double(sum)/divisor;
}

int main()
{
  int values[5];
  for (int i = 0; i < 5; i++)
  {
     cout << endl;
     char val;
     cout << "Type number #" << i << ": ";
     cin >> val;
     int x = val - '0';
     values[i] = int(x);
  }
   //= read5ints();
  double average = findaverage(values);
  cout << "The average is: " << average << endl;
  return 0;
}
