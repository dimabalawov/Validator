//Проверка, чтобы когда открывалась < в этой же строчке закрывалась >
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int mistackescount = 0;
    ifstream in("index.html");
    if (in.is_open())
    {
        const int SIZE = 100;
        char buff[SIZE];
        while (in)
        {
            in.getline(buff, SIZE);
            for (size_t i = 0; buff[i] != 0; i++)
            {
                if (buff[i] == '<')
                {
                    for (size_t j = i; buff[j] != 0; j++)
                    {
                        if (buff[j] == '>')
                            break;
                        if (buff[j + 1] == 0)
                            mistackescount++;
                    }
                }
            }
            for (int i = strlen(buff); i >= 0; i--)
            {
                if (buff[i] == '>')
                {
                    for (int j = i; j >= 0; j--)
                    {
                        if (buff[j] == '<')
                            break;
                        if (j == 0)
                            mistackescount++;
                    }
                }
            }
        }
    }
    else
        cout << "File could not be reached" << endl;
    in.close();
    cout << "Mistackes: " << mistackescount << endl;
}

