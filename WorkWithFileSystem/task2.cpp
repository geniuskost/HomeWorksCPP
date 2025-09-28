#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool isVowel(char c) {
    string vowels = "AEIOUYaeiouyАЕЄИІОУЯЮЇаеєиіоуяюї";
    return vowels.find(c) != string::npos;
}

bool isConsonant(char c) {
    string consonants = "BCDFGHJKLMNPQRSTVWXZbcdfghjklmnpqrstvwxzБВГҐДЖЗЙКЛМНПРСТФХЦЧШЩбвгґджзйклмнпрстфхцчшщ";
    return consonants.find(c) != string::npos;
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("stat.txt");
    string line;
    int chars = 0, lines = 0, vowels = 0, consonants = 0, digits = 0;
    while (getline(fin, line)) {
        lines++;
        for (char c : line) {
            chars++;
            if (isVowel(c)) vowels++;
            else if (isConsonant(c)) consonants++;
            else if (isdigit(c)) digits++;
        }
    }
    fout << "Кількість символів: " << chars << endl;
    fout << "Кількість рядків: " << lines << endl;
    fout << "Кількість голосних букв: " << vowels << endl;
    fout << "Кількість приголосних букв: " << consonants << endl;
    fout << "Кількість цифр: " << digits << endl;
    return 0;
}