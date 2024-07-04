#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class Cal
{
public:
    int getValue(void)
    {
        return 0;
    }
    int getSum(int a, int b)
    {
        return a + b;
    }
    vector<int> getResult(const vector<int>& input)
    {
        vector<int> output;
        for (int i = 0; i < input.size(); i++)
        {
            int num = input[i];
            if (num >= 10 || num == 4)
            {
                throw invalid_argument("INV");
            }

            num++;
            if (num == 4) num++;
            if (num == 10) num = 0;

            output.push_back(num);
        }

        return output;
    }
};
