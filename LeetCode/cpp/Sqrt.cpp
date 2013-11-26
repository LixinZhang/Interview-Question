#include <iostream>
using namespace std;

class Solution {
    public:
     int sqrt(int x) 
     {
        double low = 0.0;
        double high = x;

       while(low < high) 
       {
           double tmp = (low + high) / 2.0;
           if ((tmp * tmp - x) < 0.0001 && (tmp * tmp - x) > -0.00001) 
           {
               if (tmp - int(tmp) >= 0.5) return int(tmp) + 1;
               else return int(tmp);
           }
           if (tmp * tmp < x) 
           {
               low = tmp;
           }
           else
           {
               high = tmp;
           }
       }
       
      if (low - int(low) >= 0.5) return int(low) + 1;
      else return int(low);
    }
};

int main()
{
    Solution s;
    int x;
    while(true) 
    {
        cin >> x;
        cout << s.sqrt(x);
    }
    return 0;
}
