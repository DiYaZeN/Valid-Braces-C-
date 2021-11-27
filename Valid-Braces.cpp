#include <iostream>
#include <string>

using namespace std;

bool valid_braces(std::string braces)
{
    int strSize = braces.size();
    int counter = 0;
    int first = 0;
    bool x = false;
    int i = 0;
    if ((braces[0] == '(' && braces[1] == ')') && (braces[2] == '{' && braces[3] == '}') && (braces[4] == '[' && braces[5] == ']'))
    {
        x = true;
    }

    if (strSize % 2 == 0)
    {

        for (i = 0; i < strSize; i++)
        {

            if (braces[first] == '[')
            {
                for (int j = 0; j < strSize; j++)
                {
                    if ((braces[first] == '[') && (braces[first + j] == ']') && (braces[first + j - 1] != '(') && (braces[first + j - 1] != '{'))

                    {
                        counter++;
                        braces.erase(braces.begin() + (first + j));
                        braces.erase(braces.begin());
                    }
                }
            }

            else if (braces[first] == '(')
            {
                for (int m = 0; m < strSize; m++)
                {
                    if (braces[first] == '(' && braces[first + m] == ')')
                    {
                        counter++;
                        braces.erase(braces.begin() + (first + m));
                        braces.erase(braces.begin());
                    }
                }
            }
            else if (braces[first] == '{')
            {
                for (int k = 0; k < strSize; k++)
                {
                    if (braces[first] == '{' && braces[first + k] == '}')
                    {
                        counter++;
                        braces.erase(braces.begin() + (first + k));
                        braces.erase(braces.begin());
                    }
                }
            }
        }
    }
    else
    {
        x = false;
    }

    if (braces.size() == 0)
    {
        x = true;
    }

    return x;
}
