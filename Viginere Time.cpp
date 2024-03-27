#include <iostream>
#include <cstring>

using namespace std;

const char *letters = "abcdefghijklmnopqrstuvwxyz";
char key[26];

void VigenereEncrypt(char *message)
{
    int time;
    cout << "Introduceti Cheiea: ";
    cin >> key;
    cout << "Introduceti Timpul: ";
    cin >> time;

    char enc[strlen(message)];
    for (int i = 0, j = 0; i < strlen(message); i++)
    {
        char c = message[i];
        if (isalpha(c))
        {
            if (isupper(c))
            {
                enc[i] = (c + toupper(key[j]) - 2 * 'A' + time) % 26 + 'A';
            }
            else
            {
                enc[i] = (c + tolower(key[j]) - 2 * 'a' + time) % 26 + 'a';
            }
            j = (j + 1) % strlen(key);
        }
        else
        {
            enc[i] = c;
        }
    }
    enc[strlen(message)] = '\0';
    cout << enc << endl;
}

void VigenereDecrypt(char *message)
{
    int time;
    cout << "Introduceti Cheiea: ";
    cin >> key;
    cout << "Introduceti Timpul: ";
    cin >> time;
    char dec[strlen(message)];
    for (int i = 0, j = 0; i < strlen(message); i++)
    {
        char c = message[i];
        if (isalpha(c))
        {
            if (isupper(c))
            {
                dec[i] = (((c - 'A') - (tolower(key[j]) - 'a') - (time % 26) + 26 * 2) % 26) + 'A';
            }
            else
            {
                dec[i] = (((c - 'a') - (tolower(key[j]) - 'a') - (time % 26) + 26 * 2) % 26) + 'a';
            }
            j = (j + 1) % strlen(key);
        }
        else
        {
            dec[i] = c;
        }
    }
    dec[strlen(message)] = '\0';
    cout << dec << endl;
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
            VigenereEncrypt(argv[2]);
        }
        else if (strcmp(argv[1], "-Dcsr") == 0)
        {
            VigenereDecrypt(argv[2]);
        }
    }
    return 0;
}