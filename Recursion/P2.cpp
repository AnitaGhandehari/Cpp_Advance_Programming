#include <iostream>
#include <vector>
using namespace std;

int Multiplier(vector<int> &input_vector);

int main()
{
    vector<int> input_vector;
    int new_num;
    while(cin >> new_num)
    {
        input_vector.push_back(new_num);
    }

    Multiplier(input_vector);

    for (int i=0; i < input_vector.size(); i++)
    {
        cout << input_vector[i]<< "  ";
    }
    cout << endl;


return 0;
}

int Multiplier(vector<int> &input_vector)
{
    int except_value;
    int result;
    int revers;
    int new_value;
    if(input_vector.size() <= 1)
    {
        return 1;
    }
    else if(input_vector.size()==2)
    {
        revers = input_vector[0];
        input_vector[0] = input_vector[1];
        input_vector[1] = revers;
        return 1;
    }
    else if(input_vector.size()==3) {
        except_value = input_vector[input_vector.size() - 1];
        input_vector.pop_back();
        result = Multiplier(input_vector);
        input_vector.push_back((input_vector[0] * input_vector[1]));
        input_vector[0] = input_vector[0] * except_value;
        input_vector[1] = input_vector[1] * except_value;
        return except_value;
    }
    else
    {
        except_value = input_vector[input_vector.size() - 1];
        input_vector.pop_back();
        result = Multiplier(input_vector);
        new_value = input_vector[input_vector.size()-1] * result;
        input_vector.push_back(new_value);
        for(int i=0 ; i< (input_vector.size()-1) ; i++)
        {
            input_vector[i] = input_vector[i] * except_value;
        }
        return except_value;
    }
}