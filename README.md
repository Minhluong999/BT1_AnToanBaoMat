# Môn An toàn bảo mật 

# Sinh viên thực hiện : Lăng Nguyễn Minh Lượng   MSSV: K225480106044

## Bài tập 1: 
## TÌM HIỂU CÁC PHƯƠNG PHÁP MÃ HOÁ CỔ ĐIỂN
 1. Caesar
 2. Affine
 3. Hoán vị
 4. Vigenere
 5. Playfair

## Với mỗi phương pháp, hãy tìm hiểu:

 1. Tên gọi
 2. Thuật toán mã hoá, thuật toán giải mã
 3. Không gian khóa
 4. Cách phá mã (mà không cần khoá)
 5. Cài đặt thuật toán mã hoá và giải mã bằng code C++ và bằng html+css+javascript
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
# Bài làm
## Các phương pháp mã hoá cổ điển:
## 1. Caesar
### Tên: Caesar (mã dịch chuyển)

### Thuật toán

 - Mã hoá: E(p) = (p + k) mod 26

 - với p = 0..25 (A=0,B=1...), k ∈ {0..25}

 - Giải mã: D(c) = (c - k) mod 26

### Không gian khoá: 

 - 26 (k = 0..25)

### Cách phá mã (không cần khoá):

-  Brute-force thử 26 khả năng.

-  Phân tích tần suất chữ cái (E, T, A...).

-  Với ngôn ngữ có cấu trúc, 1–2 lượt thử là đủ.

### MÃ HOÁ

<img width="793" height="693" alt="image" src="https://github.com/user-attachments/assets/f7f61ec2-8009-45ad-b3d0-bc49393b6af9" />

### GIẢI MÃ

<img width="786" height="678" alt="image" src="https://github.com/user-attachments/assets/62ad0907-ec0e-4a52-97fa-1994b56dd912" />

## 2. Affine
### Tên: Affine cipher

### Thuật toán

 - Mã hoá: E(p) = (a * p + b) mod 26, với p∈{0..25}

 - Giải mã: D(c) = a^{-1} * (c - b) mod 26, trong đó a^{-1} là nghịch đảo modulo 26 (a * a^{-1} ≡ 1 mod 26)

-  Điều kiện: gcd(a,26) = 1 (để tồn tại nghịch đảo). Các a hợp lệ: 1,3,5,7,9,11,15,17,19,21,23,25 (12 giá trị).

### Không gian khoá: 

-  12 lựa chọn cho a × 26 lựa chọn cho b = 312 khả năng.

### Cách phá mã (không cần khoá):

-  Brute-force trên tất cả (a,b) (312 trường hợp) và dùng kiểm tra ngôn ngữ (wordlist/IC) để chọn ra.

-  Phân tích tần suất (một số chuyển đổi tuyến tính của tần suất): tìm ánh xạ giữa hai chữ cái có tần xuất lớn nhất.

-  Nếu có plaintext nổi bật (known-plaintext) dễ phá.
### MÃ HOÁ

<img width="1325" height="720" alt="image" src="https://github.com/user-attachments/assets/1eb44626-b673-4328-9d05-45bab3f8de76" />

### GIẢI MÃ

<img width="1300" height="726" alt="image" src="https://github.com/user-attachments/assets/2850171c-f009-438d-a664-82f6e94dbfff" />

## 3. Hoán vị
## Tên: Permutation cipher / Columnar Transposition (hoán vị cột)

### Thuật toán (columnar transposition phổ biến):

- Khoá: một permuation (ví dụ: key word "ZEBRAS" → gán thứ tự cột theo chữ cái hoặc bạn cho trực tiếp một perm như 3 1 4 2 ...).

- Tạo ma trận hàng đủ để chứa plaintext (viết theo hàng, điền kí tự pad nếu cần).

- Đọc ciphertext theo thứ tự cột dựa trên thứ tự perm của khoá.

- Giải mã: Tạo bảng có kích thước phù hợp, gán số kí tự cho mỗi cột theo thứ tự khoá, điền ciphertext cột theo cột, sau đó đọc theo hàng.

### Không gian khoá: Với độ dài key = n, không gian khoá = n! (rất lớn khi n tăng). Với columnar thường n nhỏ (ví dụ 6–10).

### Cách phá mã (không cần khoá):

- Thử mọi perm (n! — chỉ khả dĩ cho n nhỏ).

- Phân tích mẫu từ và vị trí chữ cái, tấn công bằng heuristics: IC, trích xuất từ, ngữ cảnh, simulated annealing / hill-climbing dùng scoring (language model) — thường dùng cho transposition độ dài lớn.

- Kết hợp với substitution (nếu cipher kết hợp).


### MÃ HOÁ

<img width="1451" height="816" alt="image" src="https://github.com/user-attachments/assets/6e3a41da-f952-422f-9650-b248e3a65206" />

### GIẢI MÃ

<img width="1424" height="818" alt="image" src="https://github.com/user-attachments/assets/d378fb33-1ce2-4d8f-81d3-a8525d72881b" />

## 4. Vigenère

### Tên: Vigenère

### Thuật toán

- Khoá: key là chuỗi ký tự k₀..k_{m-1} (m = độ dài key)

- Mã hoá: E(p_i) = (p_i + k_{i mod m}) mod 26 (với k_j là số tương ứng ký tự)

- Giải mã: D(c_i) = (c_i - k_{i mod m}) mod 26

### Không gian khoá: 26^m nếu key dài m. Nếu m không biết, attacker dùng Kasiski & Friedman để ước lượng m.

### Cách phá mã (không cần khoá):

- Kasiski examination: tìm khoảng cách giữa các pattern lặp để dự đoán độ dài key.

- Friedman test / Index of Coincidence (IC): ước lượng m dựa trên IC.

- Sau khi biết m, chia ciphertext thành m stream con, áp dụng phân tích tần suất từng stream như Caesar (vì mỗi stream là Caesar).

- Brute-force nhỏ cho m nhỏ; dictionary attack nếu key là từ thực.
### MÃ HOÁ
<img width="1270" height="656" alt="image" src="https://github.com/user-attachments/assets/19a388fd-5c3b-4c11-b2ec-49b09421059d" />
### GIẢI MÃ
<img width="1274" height="669" alt="image" src="https://github.com/user-attachments/assets/f7c78a74-6878-413b-9190-3b2049823484" />

## 5. Playfair
## Tên gọi:
- Được gọi là "Mã hóa Playfair" hoặc "Phương pháp mã hóa cặp chữ cái Playfair".
- Đây là một phương pháp mã hóa cổ điển được phát minh bởi Charles Wheatstone vào năm 1854, nhưng được đặt tên theo Lord Playfair, người đã phổ biến nó.
## Thuật toán mã hoá, thuật toán giải mã
### Thuật toán mã hoá
- Tạo bảng khóa (5×5 key square)
  + Chọn một keyword
  + Loại bỏ ký tự không phải chữ, chuyển về chữ hoa, và loại bỏ chữ trùng lặp giữ thứ tự xuất hiện.
  + Gộp bảng chữ cái còn lại (thường ghép I và J thành một chữ; chọn quy ước I/J hoặc loại J) để được đủ 25 ký tự.
  + Điền 5×5 theo thứ tự: đầu là ký tự trong keyword (sau khi loại trùng), tiếp theo là các chữ cái chưa dùng. Kết quả là một ma trận 5×5.
- Chuẩn bị bản rõ (plaintext preprocessing)
  + Loại ký tự không phải chữ (tuỳ lựa chọn: có thể loại bỏ khoảng trắng/dấu câu).
  + Chuyển về chữ hoa (hoặc chữ thường) và thay thế J bằng I nếu dùng quy ước đó.
  + Tách bản rõ thành cặp ký tự (digraphs) theo thứ tự từ trái sang phải.
  + Nếu trong một digraph hai ký tự giống nhau (ví dụ AA), chèn ký tự đệm (thường là X, đôi khi là Q) giữa hai ký tự để tránh cặp giống nhau; sau đó tiếp tục tách tiếp.
- Mã hóa từng digraph: Với digraph gồm hai ký tự (A, B) và vị trí của chúng trong ma trận là (rA, cA) và (rB, cB) (hàng, cột, 0-based hoặc 1-based đều được nhưng giữ nhất quán)
### Thuật toán giải hoá
- Tạo lại bảng khóa: Dùng cùng keyword và cùng quy ước (I/J) như khi mã hóa để xây ma trận 5×5 giống hệt.
- Chuẩn bị ciphertext: Loại bỏ ký tự lạ nếu cần; tách ciphertext thành digraphs theo 2 ký tự liên tiếp (không cần xử lý dấu đệm ở bước này).
- Giải mã từng digraph:
  + Nếu cùng hàng: thay bằng ký tự ngay trái của mỗi ký tự (vòng vòng sang phải cho wrap-around).
  + Nếu cùng cột: thay bằng ký tự ngay trên mỗi ký tự (vòng vòng xuống cho wrap-around).
  + Nếu hình chữ nhật: tương tự mã hóa nhưng đổi cột (lấy góc còn lại):
- Xử lý hậu kỳ (post-processing): Sau khi ghép các digraph được giải mã, có thể loại bỏ các ký tự đệm (X hoặc Q) đã chèn khi mã hóa. Tuy nhiên cần thận trọng: không phải mọi X là padding — đôi khi X thực sự thuộc plaintext. Việc loại bỏ thường dựa vào qui ước đã sử dụng (ví dụ: chèn X chỉ khi hai chữ cái giống nhau) và/hoặc kiểm tra ngữ nghĩa.
## Không gian khoá
- Không gian khóa (key space) của Playfair Cipher được xác định bởi tất cả các cách sắp xếp có thể của 25 ký tự trong bảng 5×5 (vì phải gộp I và J lại làm một).
- Số lượng khóa lý thuyết chính là số hoán vị của 25 ký tự: 25!(xấp xỉ 1.55×10^25)
## Cách phá mã (mà không cần khoá)
- Thu thập digraphs:
  + Tách ciphertext thành các cặp ký tự liên tiếp.
  + Ghi nhận tần suất xuất hiện của từng digraph trong ciphertext.
- So sánh với phân bố digraph chuẩn của ngôn ngữ:
  + Mỗi ngôn ngữ có phân bố digraph phổ biến (ví dụ trong tiếng Anh: TH, HE, IN, ER…).
  + So sánh digraphs ciphertext với bảng tần suất chuẩn để đoán các cặp tương ứng.
- Ước lượng bảng khóa từng phần:
  + Dựa trên các digraph phổ biến, suy ra các cặp ký tự nằm cùng hàng, cùng cột hoặc tạo thành hình chữ nhật.
  + Từ đó dần dần lấp các vị trí của bảng 5×5.
## Cài đặt thuật toán mã hoá và giải mã bằng code C++ và bằng html+css+javascript
``` html
<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<title>Playfair Cipher</title>
<style>
    body {
        font-family: Arial, sans-serif;
        background: linear-gradient(to right, #74ebd5, #ACB6E5);
        color: #333;
        display: flex;
        justify-content: center;
        align-items: center;
        height: 100vh;
        margin: 0;
    }
    .container {
        background-color: rgba(255, 255, 255, 0.9);
        padding: 30px;
        border-radius: 15px;
        box-shadow: 0 10px 25px rgba(0,0,0,0.2);
        max-width: 500px;
        width: 100%;
    }
    h1 {
        text-align: center;
        margin-bottom: 25px;
        color: #333;
    }
    input, textarea, button {
        width: 100%;
        padding: 10px;
        margin-top: 10px;
        margin-bottom: 15px;
        border-radius: 5px;
        border: 1px solid #aaa;
        font-size: 16px;
    }
    button {
        background-color: #4CAF50;
        color: white;
        border: none;
        cursor: pointer;
    }
    button:hover {
        background-color: #45a049;
    }
    label {
        font-weight: bold;
    }
</style>
</head>
<body>
<div class="container">
    <h1>Playfair Cipher</h1>
    <label for="text">Nhập văn bản:</label>
    <textarea id="text" rows="3" placeholder="Nhập văn bản..."></textarea>

    <label for="key">Nhập khóa:</label>
    <input type="text" id="key" placeholder="Nhập khóa...">

    <button onclick="encrypt()">Mã hóa</button>
    <button onclick="decrypt()">Giải mã</button>

    <label for="output">Kết quả:</label>
    <textarea id="output" rows="3" readonly></textarea>
</div>

<script>
function normalizeChar(c) {
    c = c.toUpperCase();
    if (c === 'J') c = 'I';
    return c;
}

function createMatrix(key) {
    let matrix = '';
    let used = new Set();
    key = key.toUpperCase();

    for (let ch of key) {
        if (/[A-Z]/.test(ch)) {
            ch = normalizeChar(ch);
            if (!used.has(ch)) {
                matrix += ch;
                used.add(ch);
            }
        }
    }

    for (let ch = 'A'.charCodeAt(0); ch <= 'Z'.charCodeAt(0); ch++) {
        let c = String.fromCharCode(ch);
        if (c === 'J') continue;
        if (!used.has(c)) {
            matrix += c;
            used.add(c);
        }
    }
    return matrix;
}

function findPosition(c, matrix) {
    c = normalizeChar(c);
    let idx = matrix.indexOf(c);
    return { row: Math.floor(idx / 5), col: idx % 5 };
}

function prepareText(text) {
    text = text.toUpperCase().replace(/[^A-Z]/g, '').replace(/J/g, 'I');
    let result = '';
    for (let i = 0; i < text.length; i++) {
        result += text[i];
        if (i + 1 < text.length && text[i] === text[i + 1]) {
            result += 'X';
        }
    }
    if (result.length % 2 !== 0) result += 'X';
    return result;
}

function processPlayfair(text, key, encrypt=true) {
    let matrix = createMatrix(key);
    let prepared = prepareText(text);
    let shift = encrypt ? 1 : 4;
    let result = '';

    for (let i = 0; i < prepared.length; i += 2) {
        let a = prepared[i], b = prepared[i + 1];
        let posA = findPosition(a, matrix);
        let posB = findPosition(b, matrix);

        if (posA.row === posB.row) {
            result += matrix[posA.row * 5 + (posA.col + shift) % 5];
            result += matrix[posB.row * 5 + (posB.col + shift) % 5];
        } else if (posA.col === posB.col) {
            result += matrix[((posA.row + shift) % 5) * 5 + posA.col];
            result += matrix[((posB.row + shift) % 5) * 5 + posB.col];
        } else {
            result += matrix[posA.row * 5 + posB.col];
            result += matrix[posB.row * 5 + posA.col];
        }
    }
    return result;
}

function encrypt() {
    let text = document.getElementById('text').value;
    let key = document.getElementById('key').value;
    document.getElementById('output').value = processPlayfair(text, key, true);
}

function decrypt() {
    let text = document.getElementById('text').value;
    let key = document.getElementById('key').value;
    document.getElementById('output').value = processPlayfair(text, key, false);
}
</script>
</body>
</html>
```
- MÃ HOÁ
<img width="757" height="792" alt="image" src="https://github.com/user-attachments/assets/e37cee02-0ab6-4172-ac8a-84b13b91b4bc" />
- GIẢI MÃ
<img width="830" height="796" alt="image" src="https://github.com/user-attachments/assets/0702074b-e3fe-44f7-8222-32d61543cd87" />


 






























