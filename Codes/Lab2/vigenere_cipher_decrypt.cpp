#include <iostream>
using namespace std;

int main() {
    char encryptedText[100], key[100], decryptedText[100];
    int textLen = 0, keyLen = 0;

    cout << "Enter the encrypted text: ";
    cin.getline(encryptedText, 100);
    cout << "Enter the key: ";
    cin.getline(key, 100);

    // Calculate the length of the encrypted text and key
    while (encryptedText[textLen] != '\0') textLen++;
    while (key[keyLen] != '\0') keyLen++;

    // Decrypt the text
    for (int i = 0, j = 0; i < textLen; i++) {
        // Decrypt alphabetic characters
        if ((encryptedText[i] >= 'A' && encryptedText[i] <= 'Z') || (encryptedText[i] >= 'a' && encryptedText[i] <= 'z')) {
            // Decrypt uppercase letters
            if (encryptedText[i] >= 'A' && encryptedText[i] <= 'Z') {
                decryptedText[i] = char(((encryptedText[i] - 'A' - (key[j % keyLen] - 'A') + 26) % 26) + 'A');
            }
            // Decrypt lowercase letters
            else {
                decryptedText[i] = char(((encryptedText[i] - 'a' - (key[j % keyLen] - 'a') + 26) % 26) + 'a');
            }
            j++; // Move to the next character in the key
        } else {
            decryptedText[i] = encryptedText[i]; // Non-alphabetic characters remain unchanged
        }
    }
    decryptedText[textLen] = '\0'; // Null-terminate the decrypted text

    cout << "Decrypted text: " << decryptedText << endl;

    return 0;
}
