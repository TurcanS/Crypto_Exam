#include <iostream>
#include <cstring>

using namespace std;

int key;

void Ecsr(char *message){
    char enc[strlen(message)];
    const char* letters = "abcdefghijklmnopqrstuvwxyz";
    for(int i = 0; i < strlen(message); i++){
        for(int j = 0; j < strlen(letters); j++){
            if(message[i] == letters[j]){
                if((j + key) < strlen(letters)){
                    enc[i] = letters[j + key];
                } else {
                    enc[i] = letters[(j + key) - strlen(letters)];
                }
            }
        }
    }
    cout<<enc<<endl;
}

void Dcsr(char *message){
    char dec[strlen(message)];
    const char* letters = "abcdefghijklmnopqrstuvwxyz";
    for(int i = 0; i < strlen(message); i++){
        for(int j = 0; j < strlen(letters); j++){
            if(message[i] == letters[j]){
                if((j - key) >= 0){
                    dec[i] = letters[j - key];
                } else {
                    dec[i] = letters[strlen(letters) + (j - key)];
                }
            }
        }
    }
    cout<<dec<<endl;
}

int main(int argc, char *argv[]){
    if(argc < 2){
        cout<<"No arguments provided"<< endl;
        return 1;
    }
    
    if(argc == 2){
        if(strcmp(argv[1], "-Ecsr") == 0){
            cout<<"Missing message"<< endl;
        } else if(strcmp(argv[1], "-Dcsr") == 0){
            cout<<"Missing message"<< endl;
        } else {
            cout<<"No such function: "<< argv[1]<< endl;
        }
        return 1;
    }
    
    if(argc == 3){
        if(strcmp(argv[1], "-Ecsr") == 0){
            cout<<"Introduceti Cheiea: ";
            cin>>key;
            Ecsr(argv[2]);
        } else if(strcmp(argv[1], "-Dcsr") == 0){
            cout<<"Introduceti Cheiea: ";
            cin>>key;
            Dcsr(argv[2]);
        }
    }
    return 0;
}