#include "Split.h"

int split(string input_string, char separator, string arr[], const int ARR_SIZE)
{
    int sepcheck = 0;
    int counter = 0;
    int i = 0;
    int chars = 0;
    int extra = 0;
    if ((int)input_string.length() == 0)
    {
        return 0;
    }
    for (int j = 0; j < (int)input_string.length(); j++)
    {
        if (input_string[j] == separator)
        {
            sepcheck++;
        }
    }
    if (sepcheck == 0)
    {
        arr[i] = input_string;
        return 1;
    }
    for (int k = 0; k < (int)input_string.length() + 1; k++)
    {
        chars++;
        if (input_string[k] == separator || input_string[k] == '\0')
        {
            chars--;
            arr[counter] = input_string.substr(i, chars);
            i = k + 1;
            counter++;
            chars = 0;
            if (counter == ARR_SIZE)
            {
                for (int f = i; f < (int)input_string.length() + 1; f++)
                {
                    if (input_string[f] == separator || input_string[f] == '\0')
                    {
                        extra++;
                        f = input_string.length() + 2;
                    }
                }
                k = input_string.length() + 2;
            }
        }
    }

    if (extra == 1)
    {
        return -1;
    }
    else
    {
        return counter;
    }
}