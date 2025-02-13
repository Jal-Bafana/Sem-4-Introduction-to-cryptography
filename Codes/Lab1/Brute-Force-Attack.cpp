#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    char ctext[100];
    int key,len;
    cout<<"Enter cipher text = ";
    cin.getline(ctext,100);
    len = strlen(ctext);
    char ch;
    for(key=0;key<26;key++)
    {
        for(int i = 0 ; ctext[i] != '\0' ; i++)
        {
            ch = ctext[i];
            if (ch>= 'a' &&ch<= 'z')
            {
                ch = ch - key;
                if (ch< 'a')
                    ch = ch + 'z' - 'a' + 1;
                ctext[i] = ch;
            }
            else if (ch>= 'A' &&ch<= 'Z')
            {
                ch = ch - key;
                if (ch< 'A')
                    ch = ch + 'Z' - 'A' + 1;
                ctext[i] = ch;
            }
        }
    cout<<"Decrypted text for key="<< key+1 <<" is: "<<ctext<<endl;
    }
    return 0;
}
