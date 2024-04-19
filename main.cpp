#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
using namespace std;

string caesarEncrypt(string text, int shift) {
    for (int i = 0; i < text.length(); ++i) {
        if (isalpha(text[i])) {
            if (islower(text[i])) {
                text[i] = (text[i] + shift - 'a') % 26 + 'a';
            } else {
                text[i] = (text[i] + shift - 'A') % 26 + 'A';
            }
        }
    }
    return text;
}

string rot13Encrypt(string text) {
    for (int i = 0; i < text.length(); ++i) {
        if (isalpha(text[i])) {
            char base = islower(text[i])? 'a' : 'A';
            text[i] = ((text[i] - base + 13) % 26) +base;
        }
    }
    return text;
}
string substitutionEncryption(string text, string key) {
    for (int i = 0; i < text.length(); ++i) {
        if (isalpha(text[i])) {
            if (islower(text[i])) {
                text[i] = tolower(key[text[i] - 'a']);
            } else {
                text[i] = tolower(key[text[i] - 'A']);
            }
        }
    }
    return text;
}
string asciiEncrypt(string text) {
    string encryptedText;
    for (int i = 0; i < text.length(); ++i) {
        encryptedText += std::to_string(int(text[i])) + " ";

    }
    return encryptedText;
}
void writeToFile(string filename, string content) {
    ofstream outputFile(filename);
    if (outputFile.is_open()) {
        outputFile << content;
        outputFile.close();
        cout << "Text successfully written to file: " << filename << endl;
    } else {
        cout << "Unable to open file: " << filename << endl;
    }
}
int main() {
    string text, key;
    int shift;
    char choice;

    cout << "Enter the text to encrypt: ";
    getline(cin, text);

    cout << "Choose encryption methode:\n"
         << "1. Caesar\n"
         << "2. ROT13\n"
         << "3.Substitution\n"
         << "4. ASCII\n"
         << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case '1': {
            cout << "Enter the shift amount for Caesar encryption:";
            cin >> shift;
            cin.ignore();

            string caesarEncryptedText = caesarEncrypt(text, shift);
            writeToFile("caesar_encrypted_text.txt", caesarEncryptedText);
            cout << "Encrypted text (Caesar):" << caesarEncryptedText << endl;
            break;
        }
        case '2': {
            string rot13EncryptedText = rot13Encrypt(text);
            writeToFile("rot13_encrypted_text.txt", rot13EncryptedText);
            cout << "Encrypted text (ROT13):" << rot13EncryptedText << endl;
            break;
        }
        case '3': {
            cout << "Enter the key for Substitution encryption: ";
            cin.ignore();
            getline(cin, key);

            string substitutionEncryptedText = substitutionEncryption(text, key);
            writeToFile("substitution_encrypted_text.txt", substitutionEncryptedText);
            cout << "Encrypted text (Substitution): " << substitutionEncryptedText << endl;
            break;
        }
        case '4': {
            string asciiEncryptedText = asciiEncrypt(text);
            writeToFile("ascii_encrypted_text.txt", asciiEncryptedText);
            cout << "Encrypted text (ASCII):" << asciiEncryptedText << endl;
        }
        default:
            cout << "Invalid choice!" << endl;
            break;
    }

    return 0;
}