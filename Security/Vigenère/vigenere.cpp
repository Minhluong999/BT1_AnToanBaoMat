#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

// Hàm chuẩn hóa ký tự (gộp J vào I)
char normalizeChar(char c) {
    c = toupper(c);
    if (c == 'J') c = 'I';
    return c;
}

// Tạo bảng 5x5 từ khóa
string createKeyMatrix(const string& keyword) {
    string key = "";
    vector<bool> used(26, false);
    for (char c : keyword) {
        if (!isalpha(c)) continue;
        char ch = normalizeChar(c);
        if (!used[ch - 'A']) {
            key += ch;
            used[ch - 'A'] = true;
        }
    }
    for (char c = 'A'; c <= 'Z'; ++c) {
        if (c == 'J') continue; // bỏ J
        if (!used[c - 'A']) {
            key += c;
            used[c - 'A'] = true;
        }
    }
    return key.substr(0, 25);
}

// Tìm vị trí ký tự trong ma trận
pair<int,int> findPosition(char c, const string& matrix) {
    c = normalizeChar(c);
    int idx = matrix.find(c);
    return { idx / 5, idx % 5 };
}

// Chuẩn bị plaintext: tách digraph và chèn X nếu trùng lặp
string prepareText(const string& text) {
    string cleaned = "";
    for (char c : text) {
        if (isalpha(c)) cleaned += normalizeChar(c);
    }
    string result = "";
    for (size_t i = 0; i < cleaned.size(); ++i) {
        result += cleaned[i];
        if (i + 1 < cleaned.size() && cleaned[i] == cleaned[i + 1]) {
            result += 'X';
        }
    }
    if (result.size() % 2 != 0) result += 'X';
    return result;
}

// Mã hóa hoặc giải mã digraph
string processDigraphs(const string& text, const string& matrix, bool encrypt) {
    string result = "";
    int shift = encrypt ? 1 : 4; // +1 cho mã hóa, -1 = +4 mod5 cho giải mã
    for (size_t i = 0; i < text.size(); i += 2) {
        char a = text[i];
        char b = text[i + 1];
        auto [ra, ca] = findPosition(a, matrix);
        auto [rb, cb] = findPosition(b, matrix);

        if (ra == rb) { // cùng hàng
            result += matrix[ra*5 + (ca + shift) % 5];
            result += matrix[rb*5 + (cb + shift) % 5];
        } else if (ca == cb) { // cùng cột
            result += matrix[(ra + shift) % 5 * 5 + ca];
            result += matrix[(rb + shift) % 5 * 5 + cb];
        } else { // hình chữ nhật
            result += matrix[ra*5 + cb];
            result += matrix[rb*5 + ca];
        }
    }
    return result;
}

// Giao diện chính
int main() {
    string text, key;
    cout << "Nhap van ban: ";
    getline(cin, text);
    cout << "Nhap khoa: ";
    getline(cin, key);

    string matrix = createKeyMatrix(key);
    string prepared = prepareText(text);

    int choice;
    cout << "Chon chuc nang (1: Ma hoa, 2: Giai ma): ";
    cin >> choice;

    if (choice == 1) {
        string cipher = processDigraphs(prepared, matrix, true);
        cout << "Van ban da ma hoa: " << cipher << endl;
    } else if (choice == 2) {
        string plain = processDigraphs(prepared, matrix, false);
        cout << "Van ban da giai ma: " << plain << endl;
    } else {
        cout << "Lua chon khong hop le!" << endl;
    }

    return 0;
}
