#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;
//***********************
//global variables
//"i" always represents rows while "j" represents colunms
//static array of 1000 maximum rows and cols.
const int MAX_ROWS = 1000;
const int MAX_COLS = 1000;
int matrixA[MAX_ROWS][MAX_COLS];
//**********************
//Functions
int parse(int);
//**********************
int main() 
{
// where n = size of the square matrix inputed by the user
int n;
cout << "Enter the dimension of your square matrix: ";
cin >> n;
//r represents rows read from parse() 
int r;
r = parse(n);
//Testing to be sure its working
for(int i =0; i<r; i++)
   {
     for(int j=0; j<n; j++)
       {
        cout << matrixA[i][j] <<"  ";
       }
        cout<< endl;
    }
//**********************
// parse function receives the size of the array as arguement
int parse(int n)
{
  string line; 
  int i=0;
  ifstream myfile("data.csv");
  if(!myfile)
  {
    cout<< " File does not exist";
    return -1;
  }
  while (getline(myfile, line) && i< n)
    {
      string text;
      stringstream abc(line);
      int j=0;
      while (getline(abc, text , ',') && j<n)
        {
          matrixA[i][j]= stoi(text);
          j++;
        }
      i++;
    }
  myfile.close();
  return i;
}
