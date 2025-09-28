#include <iostream>
#include <string>
#include <cctype>
#include <tuple>

using namespace std;

// --- Hàm hỗ trợ ---
// chuẩn hóa modulo 26 (luôn trả về 0..25)
int norm26(int v) {
    v %= 26;
    if (v < 0) v += 26;
    return v;
}

// Extended Euclid: trả về (g, x, y) sao cho a*x + b*y = g = gcd(a,b)
tuple<int,int,int> ext_gcd(int a, int b) {
    if (b == 0) return {a, 1, 0};
    int g, x1, y1;
    tie(g, x1, y1) = ext_gcd(b, a % b);
    int x = y1;
    int y = x1 - (a / b) * y1;
    return {g, x, y};
}

// tính nghịch đảo modulo 26 của a; trả về -1 nếu không tồn tại
int modInverse26(int a) {
    a = norm26(a);
    int g, x, y;
    tie(g, x, y) = ext_gcd(a, 26);
    if (g != 1) return -1; // không có nghịch đảo nếu gcd != 1
    x = norm26(x);
    return x;
}

// Kiểm tra ký tự chữ cái và trả về base ('A' hoặc 'a')
bool isLetter(char c) {
    return isalpha(static_cast<unsigned char>(c));
}

char baseOf(char c) {
    return isupper(static_cast<unsigned char>(c)) ? 'A' : 'a';
}

// --- Lớp AffineCipher ---
class AffineCipher {
public:
    AffineCipher(int mul, int add) {
        a = norm26(mul);
        b = norm26(add);
    }

    // kiểm tra a hợp lệ (coprime với 26)
    bool valid() const {
        int g = gcd(a, 26);
        return g == 1;
    }

    // mã hóa một ký tự nếu là chữ, ngược lại giữ nguyên
    char encodeChar(char ch) const {
        if (!isLetter(ch)) return ch;
        char base = baseOf(ch);
        int x = ch - base;
        int y = norm26(a * x + b);
        return static_cast<char>(y + base);
    }

    // giải mã một ký tự (sử dụng nghịch đảo của a)
    char decodeChar(char ch) const {
        if (!isLetter(ch)) return ch;
        int a_inv = modInverse26(a);
        if (a_inv == -1) return '?'; // trường hợp không thể (không xảy ra nếu valid() true)
        char base = baseOf(ch);
        int y = ch - base;
        int x = norm26(a_inv * (y - b));
        return static_cast<char>(x + base);
    }

    // mã hóa chuỗi
    string encrypt(const string &plain) const {
        string out;
        out.reserve(plain.size());
        for (char c : plain) out.push_back(encodeChar(c));
        return out;
    }

    // giải mã chuỗi
    string decrypt(const string &cipher) const {
        string out;
        out.reserve(cipher.size());
        for (char c : cipher) out.push_back(decodeChar(c));
        return out;
    }

private:
    int a, b;
    // gcd đơn giản
    static int gcd(int x, int y) {
        while (y != 0) {
            int t = x % y;
            x = y;
            y = t;
        }
        return x < 0 ? -x : x;
    }
};

// --- Chương trình chính ---
int main() {
    cout << "Affine Cipher - Ma hoa va Giai ma\n";
    cout << "Nhap dong van ban (co the co khoang trang):\n";
    string line;
    getline(cin, line);

    cout << "Nhap a (he so nhan, co gcd(a,26)=1): ";
    int a;
    if (!(cin >> a)) {
        cerr << "Nhap a khong hop le.\n";
        return 1;
    }

    cout << "Nhap b (he so dich): ";
    int b;
    if (!(cin >> b)) {
        cerr << "Nhap b khong hop le.\n";
        return 1;
    }

    AffineCipher cipher(a, b);
    if (!cipher.valid()) {
        cerr << "Gia tri a khong hop le (khong nguyen to cung 26). Vui long chon a sao cho gcd(a,26)=1.\n";
        return 1;
    }

    cout << "Chon: 1 - Ma hoa, 2 - Giai ma : ";
    int choice;
    if (!(cin >> choice)) {
        cerr << "Lua chon khong hop le.\n";
        return 1;
    }

    if (choice == 1) {
        string ct = cipher.encrypt(line);
        cout << "Ban ma hoa: \n" << ct << '\n';
    } else if (choice == 2) {
        string pt = cipher.decrypt(line);
        cout << "Ban giai ma: \n" << pt << '\n';
    } else {
        cout << "Lua chon khong hop le.\n";
    }

    return 0;
}
