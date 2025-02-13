#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    char ptext[100];
    int key,len;
    cout<<"Enter plain text = ";
    cin.getline(ptext,100);
    cout<<"\n Enter Key = ";
    cin>>key;
    len = strlen(ptext);
    char ch;
    for(int i = 0 ; ptext[i] != '\0' ; i++)
    {
        ch = ptext[i];
        if (ch>= 'a' &&ch<= 'z')
        {
            ch = ch + key;
            if (ch> 'z')
                ch = ch - 'z' + 'a' - 1;

            ptext[i] = ch;
        }
        else if (ch>= 'A' &&ch<= 'Z')
        {
            ch = ch + key;
            if (ch> 'Z')
                ch = ch - 'Z' + 'A' - 1;
            ptext[i] = ch;
        }
    }
    cout<<"Encrypted text is : "<<ptext;
    return 0;
}
