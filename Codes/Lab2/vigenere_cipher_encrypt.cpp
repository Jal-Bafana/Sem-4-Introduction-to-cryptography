#include <iostream>
using namespace std;

int main() {
    char text[100], key[100], encryptedText[100];
    int textLen = 0, keyLen = 0;

    cout << "Enter the text: ";
    cin.getline(text, 100);
    cout << "Enter the key: ";
    cin.getline(key, 100);

    // Calculate the length of the text and key
    while (text[textLen] != '\0') textLen++;
    while (key[keyLen] != '\0') keyLen++;

    // Encrypt the text
    for (int i = 0, j = 0; i < textLen; i++) {
        // Encrypt alphabetic characters
        if ((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z')) {
            // Encrypt uppercase letters
            if (text[i] >= 'A' && text[i] <= 'Z') {
                encryptedText[i] = char(((text[i] - 'A' + (key[j % keyLen] - 'A')) % 26) + 'A');
            }
            // Encrypt lowercase letters
            else {
                encryptedText[i] = char(((text[i] - 'a' + (key[j % keyLen] - 'a')) % 26) + 'a');
            }
            j++; // Move to the next character in the key
        } else {
            encryptedText[i] = text[i]; // Non-alphabetic characters remain unchanged
        }
    }
    encryptedText[textLen] = '\0'; // Null-terminate the encrypted text

    cout << "Encrypted text: " << encryptedText << endl;

    return 0;
}
