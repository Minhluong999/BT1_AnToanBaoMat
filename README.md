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

### Không gian khoá:

- 26^m nếu key dài m. Nếu m không biết, attacker dùng Kasiski & Friedman để ước lượng m.

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
### Tên: Playfair

### Thuật toán (5×5 key square, thường hợp I/J):

- Tạo key square 5×5 từ khoá: ghi các chữ cái khoá (loại trùng lặp), sau đó điền các chữ cái còn lại (thường hợp J→I để có 25 chữ cái).

- Chia plaintext thành các digraphs (cặp). Qui tắc:

-- Nếu cặp có hai chữ cái giống nhau, chèn chữ cái filler (thường 'X') giữa chúng rồi tiếp tục (ví dụ "BALLOON" → BA LX LO ON).

-- Nếu độ dài lẻ, thêm filler ở cuối.

- Mã hoá mỗi digraph (A,B):

-- Nếu A và B ở cùng hàng: thay mỗi chữ bằng chữ ngay bên phải (wrap-around).

-- Nếu cùng cột: thay bằng chữ ngay dưới (wrap-around).

-- Nếu khác hàng/cột: thay mỗi chữ bằng chữ ở cùng hàng nhưng cột của chữ kia (tức hình chữ nhật swap columns).

- Giải mã đảo ngược quy tắc (trái/trên thay vì phải/dưới).

### Không gian khoá:
- Khoá là chuỗi sắp xếp 25 ký tự → 25! (rất lớn). Nhưng nhiều key tương đương nếu dùng quy tắc I/J.

### Cách phá mã (không cần khoá):

- Dựa vào phân tích digraph (tần suất cặp ký tự).

- Brute-force toàn bộ keyspace không khả thi; dùng heuristics / hill-climbing, simulated annealing dựa trên scoring bằng ngôn ngữ (log-likelihood) để tìm bảng gần đúng.

- Nếu có plaintext đoạn nhỏ (known-plaintext) hoặc mẫu digraph có thể suy ra.

### MÃ HOÁ 

<img width="757" height="792" alt="image" src="https://github.com/user-attachments/assets/e37cee02-0ab6-4172-ac8a-84b13b91b4bc" />

### GIẢI MÃ

<img width="830" height="796" alt="image" src="https://github.com/user-attachments/assets/0702074b-e3fe-44f7-8222-32d61543cd87" />


 






























