#include <bits/stdc++.h>
using namespace std;

/*
  Columnar Transposition (Permutation) Cipher
  - Mã hóa: điền plaintext theo hàng (left-to-right, top-to-bottom),
    rồi đọc ra theo thứ tự cột được chỉ định bởi permutation.
  - Giải mã: biết permutation và ciphertext, tính độ dài từng cột (vì
    hàng cuối có thể ngắn), tách ciphertext theo từng cột rồi đọc lại theo hàng.
*/

// Kiểm tra key có phải là 1..n permutation không
bool validPermutation(const vector<int>& perm) {
    int n = (int)perm.size();
    vector<bool> seen(n+1, false);
    for (int v : perm) {
        if (v < 1 || v > n) return false;
        if (seen[v]) return false;
        seen[v] = true;
    }
    return true;
}

// Mã hóa: không dùng padding, giữ nguyên độ dài plaintext
string encryptColumnar(const string &plain, const vector<int> &perm) {
    int cols = (int)perm.size();
    if (cols == 0) return "";

    int len = (int)plain.size();
    int rows = (len + cols - 1) / cols; // ceil(len/cols)
    int shortCols = cols * rows - len;  // số cột cuối sẽ thiếu 1 ký tự ở hàng cuối

    // Tạo cột bằng cách điền theo hàng
    vector<string> colsStr(cols);
    colsStr.assign(cols, "");
    for (int i = 0; i < len; ++i) {
        int c = i % cols; // cột hiện tại khi điền theo hàng
        colsStr[c].push_back(plain[i]);
    }

    // Đọc theo thứ tự perm (perm chứa 1-based column indices)
    string cipher;
    cipher.reserve(len);
    for (int k = 0; k < cols; ++k) {
        int colIndex = perm[k] - 1;
        cipher += colsStr[colIndex];
    }
    return cipher;
}

// Giải mã: tính độ dài từng cột rồi lấp ngược lại
string decryptColumnar(const string &cipher, const vector<int> &perm) {
    int cols = (int)perm.size();
    if (cols == 0) return "";

    int len = (int)cipher.size();
    int rows = (len + cols - 1) / cols;
    int fullCols = len % cols; // số cột có đủ rows ký tự; nếu fullCols==0 thì tất cả có rows
    if (fullCols == 0) fullCols = cols;

    // Độ dài từng cột khi đọc theo thứ tự cột 0..cols-1 (tính theo cách điền hàng-then-col)
    // Nếu plaintext điền theo hàng, thì cột j có độ dài:
    //   rows       nếu j < fullCols
    //   rows - 1   nếu j >= fullCols
    vector<int> colLen(cols, 0);
    for (int j = 0; j < cols; ++j) {
        colLen[j] = (j < fullCols ? rows : (rows - 1));
    }

    // Tách ciphertext thành các cột theo thứ tự perm
    vector<string> colsStr(cols, "");
    int pos = 0;
    for (int k = 0; k < cols; ++k) {
        int colIdx = perm[k] - 1;          // vị trí cột thực tế
        int L = colLen[colIdx];           // độ dài cột đó
        if (pos + L > len) L = max(0, len - pos); // safety
        colsStr[colIdx] = cipher.substr(pos, L);
        pos += L;
    }

    // Bây giờ đọc lại theo hàng để lấy plaintext
    string plain;
    plain.reserve(len);
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            if (r < (int)colsStr[c].size()) {
                plain.push_back(colsStr[c][r]);
            }
        }
    }
    return plain;
}

// Hàm tiện: đọc một dòng toàn bộ sau khi đã dùng >> trước đó
void readRestOfLine() {
    string tmp;
    getline(cin, tmp);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "Permutation (Columnar) Cipher - Encrypt/Decrypt\n";
    cout << "Nhập văn bản (có thể có khoảng trắng):\n";
    string message;
    getline(cin, message);

    cout << "Nhập số cột (độ dài khóa/hoán vị): ";
    int n;
    if (!(cin >> n) || n <= 0) {
        cerr << "Giá trị số cột không hợp lệ.\n";
        return 1;
    }

    vector<int> key(n);
    cout << "Nhập hoán vị n số (ví dụ: 2 4 1 3) - các số cách nhau bởi khoảng trắng:\n";
    for (int i = 0; i < n; ++i) {
        if (!(cin >> key[i])) {
            cerr << "Nhập khóa không hợp lệ.\n";
            return 1;
        }
    }

    if (!validPermutation(key)) {
        cerr << "Khóa không phải là hoán vị hợp lệ của 1.." << n << ".\n";
        return 1;
    }

    cout << "Chọn thao tác (1 = Mã hóa, 2 = Giải mã): ";
    int choice;
    if (!(cin >> choice)) {
        cerr << "Lựa chọn không hợp lệ.\n";
        return 1;
    }

    if (choice == 1) {
        string ct = encryptColumnar(message, key);
        cout << "Ciphertext:\n" << ct << "\n";
    } else if (choice == 2) {
        string pt = decryptColumnar(message, key);
        cout << "Plaintext:\n" << pt << "\n";
    } else {
        cerr << "Lựa chọn không hợp lệ.\n";
        return 1;
    }

    return 0;
}
