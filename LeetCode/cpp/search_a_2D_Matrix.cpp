#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    public :
        bool searchMatrix(vector<vector<int> > &matrix, int target) 
        {
            int i, j;
            int h = matrix.size();
            int w = matrix[0].size();
            i = 0;
            j = w - 1;
            while( i < h && j >= 0)
            {
                if (target > matrix[i][j]) i ++;
                else if (target < matrix[i][j]) j --;
                else return true;
            }
            return false;
        
        }
};


int main()
{
    Solution s;
    vector<vector<int> > matrix;
    vector<int> row1;
    row1.push_back(1);
    row1.push_back(3);
    row1.push_back(5);
    row1.push_back(7);
    vector<int> row2;
    row2.push_back(10);
    row2.push_back(11);
    row2.push_back(16);
    row2.push_back(20);
    vector<int> row3;
    row3.push_back(23);
    row3.push_back(30);
    row3.push_back(34);
    row3.push_back(50);
    
    matrix.push_back(row1);
    matrix.push_back(row2);
    matrix.push_back(row3);

    int num;
    while(cin >> num) 
    {
        cout<<s.searchMatrix(matrix, num)<<endl;
    }
    return 0;
}
