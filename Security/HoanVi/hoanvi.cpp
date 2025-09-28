#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Hàm chuẩn hóa ký tự (trả về 0-25)
int normalizeChar(char c) {
    return tolower(c) - 'a';
}

// Hàm mã hóa Vigenère
string vigenereEncrypt(const string& plain, const string& key) {
    string result;
    int keyLen = key.size();
    int j = 0; // chỉ số cho khóa

    for (char c : plain) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            int shift = normalizeChar(key[j % keyLen]);
            char enc = char((c - base + shift) % 26 + base);
            result.push_back(enc);
            j++; // chỉ tăng khi gặp ký tự chữ
        } else {
            result.push_back(c);
        }
    }
    return result;
}

// Hàm giải mã Vigenère
string vigenereDecrypt(const string& cipher, const string& key) {
    string result;
    int keyLen = key.size();
    int j = 0;

    for (char c : cipher) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            int shift = normalizeChar(key[j % keyLen]);
            char dec = char((c - base - shift + 26) % 26 + base);
            result.push_back(dec);
            j++;
        } else {
            result.push_back(c);
        }
    }
    return result;
}

int main() {
    string text, key;
    cout << "Nhap van ban: ";
    getline(cin, text);

    cout << "Nhap khoa: ";
    cin >> key;

    int choice;
    cout << "Chon che do (1 = Ma hoa, 2 = Giai ma): ";
    cin >> choice;

    if (choice == 1) {
        cout << "Ban ma hoa: " << vigenereEncrypt(text, key) << endl;
    } else if (choice == 2) {
        cout << "Ban giai ma: " << vigenereDecrypt(text, key) << endl;
    } else {
        cout << "Lua chon khong hop le!" << endl;
    }

    return 0;
}
