# Bài tập 1:
# Bài làm
## Các phương pháp mã hoá cổ điển:
## 1. Caesar
## Tên gọi
- Phương pháp mã hóa Caesar có tên gọi đầy đủ là "Mã Caesar" hoặc "Caesar Cipher"
- Mã dịch chuyển (Shift Cipher): Vì nó hoạt động bằng cách dịch chuyển các chữ cái trong bảng chữ cái.
- Mã thay thế đơn giản (Simple Substitution Cipher): Là một dạng cụ thể của mã thay thế, trong đó mỗi
## Thuật toán mã hoá, thuật toán giải mã
### Thuật toán mã hoá (Encryption Algorithm):
- Công thức mã hóa:
- Với mỗi ký tự chữ cái 𝑃 trong bản rõ (plaintext), ký tự mã hóa 𝐶 được tính như sau: C=(P+k)mod26
- Trong đó:
  + P: vị trí của chữ cái trong bảng chữ cái (A = 0, B = 1, ..., Z = 25)
  + 𝑘: khóa mã hóa (số bước dịch chuyển, thường từ 1 đến 25)
  + 𝐶: vị trí của chữ cái sau khi mã hóa
  + Kết quả được chuyển ngược lại thành chữ cái
### Thuật toán giải mã (Decryption Algorithm):
- Công thức giải mã: P=(C−k+26)mod26
- Trong đó:
  + C: vị trí của ký tự trong bản mã
  + 𝑘: khóa mã hóa
  + 𝑃: vị trí của ký tự ban đầu trong bản rõ
## Không gian khoá
- Thường là bảng chữ cái Latin gồm 26 ký tự (A–Z).
- Không gian khóa: Có 25 khóa hợp lệ.
## Cách phá mã (mà không cần khoá)
- Vét cạn (brute-force): Thử tất cả các khóa khả dĩ theo thứ tự (ví dụ 1 đến 25 cho bảng chữ Latin), dịch ngược ciphertext với từng khóa rồi đọc kết quả để chọn dòng có nghĩa.
- Phân tích tần suất (frequency analysis): Đếm tần suất xuất hiện của từng chữ cái trong ciphertext, giả thiết chữ cái phổ biến nhất tương ứng với chữ cái phổ biến nhất của ngôn ngữ đích, tính khoảng dịch tương ứng và thử các khả năng gần đó.
- Từ biết trước / crib (known-plaintext): Nếu đoán trước được một từ hoặc cụm từ xuất hiện trong plaintext (ví dụ “và”, “là”, một tên), tìm vị trí tương ứng trong ciphertext và suy ra khóa từ sự chênh lệch giữa các chữ cái.
- Đánh giá ngôn ngữ (scoring theo từ điển hoặc n-gram): Với mỗi kết quả dịch thử, tính điểm bằng cách đếm số từ hợp lệ trong danh sách từ, hoặc dùng điểm n-gram; chọn kết quả có điểm cao nhất vì khả năng là plaintext thật.
## Cài đặt thuật toán mã hoá và giải mã bằng code C++ và bằng html+css+javascript























