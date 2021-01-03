#include <iostream>
#include <string>


using namespace std;

string cryptography(string &input_vector);


int main() {
    string input_vector;
    string output_string;
    char word_char;
    while(cin >> word_char)
    {
        input_vector += word_char;
    }

    output_string = cryptography(input_vector);

   for (int i=0; i <= output_string.length(); i++)
    {
       cout << output_string[i];
    }
   cout << endl;

    return 0;
}


string cryptography(string &input_string)
{
    string Part1, Part2;
    string output_string;
    int k = 0, n = 0;
    if(input_string.length()<=1)
    {
      return input_string;
    }

        n = input_string.length();
        k = input_string.length() / 2;

        for (int i = k-1; i >=0 ; i--) {
            Part2 += input_string[i];
        }
        for (int j = n-1; j >= k; j--) {
            Part1 += input_string[j];
        }

        Part1 = cryptography(Part1);
        Part2 = cryptography(Part2);
        output_string = Part1 + Part2;
        return output_string;
}