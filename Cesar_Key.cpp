#include <iostream>
#include <cstring>

using namespace std;

const char *letters = "abcdefghijklmnopqrstuvwxyz";
char key[26];

char *CSK_keygen(char key[])
{
    int i, j, k, n;

    strcat(key, letters);
    n = strlen(key);
    for (i = 0; i < n; i++)
        for (j = i + 1; j < n;)
            if (key[i] == key[j])
            {
                for (k = j; k < n; k++)
                {
                    key[k] = key[k + 1];
                }
                n--;
            }
            else
                j++;
    return key;
}

void Ecsr(char *message)
{
    cout << "Introduceti Cheiea: ";
    cin >> key;
    CSK_keygen(key);
    char enc[strlen(message)];
    for (int i = 0; i < strlen(message); i++)
    {
        for (int j = 0; j < strlen(letters); j++)
        {
            if (message[i] == letters[j])
            {
                enc[i] = key[j];
            }
        }
    }
    cout << enc << endl;
}

void Dcsr(char *message)
{
    cout << "Introduceti Cheiea: ";
    cin >> key;
    CSK_keygen(key);
    char enc[strlen(message)];
    for (int i = 0; i < strlen(message); i++)
    {
        for (int j = 0; j < strlen(key); j++)
        {
            if (message[i] == key[j])
            {
                enc[i] = letters[j];
            }
        }
    }
    cout << enc << endl;
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cout << "No arguments provided" << endl;
        return 1;
    }

    if (argc == 2)
    {
        if (strcmp(argv[1], "-Ecsr") == 0)
        {
            cout << "Missing message" << endl;
        }
        else if (strcmp(argv[1], "-Dcsr") == 0)
        {
            cout << "Missing message" << endl;
        }
        else
        {
            cout << "No such function: " << argv[1] << endl;
        }
        return 1;
    }

    if (argc == 3)
    {
        if (strcmp(argv[1], "-Ecsr") == 0)
        {
            Ecsr(argv[2]);
        }
        else if (strcmp(argv[1], "-Dcsr") == 0)
        {
            Dcsr(argv[2]);
        }
    }
    return 0;
}