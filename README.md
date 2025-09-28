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
## Tên gọi:
- Phương pháp mã hóa Vigenère có tên gọi chính thức là Vigenère Cipher (Mật mã Vigenère).
- Vigenère Square hoặc Tabula Recta (tên gọi cho bảng chữ cái dùng trong mã hóa/giải mã)
- Thuộc nhóm mật mã thay thế đa bảng (polyalphabetic substitution cipher).
## Thuật toán mã hoá, thuật toán giải mã
### Thuật toán mã hoá
- Chuẩn hóa văn bản và khóa:
  + Chỉ dùng chữ cái (A–Z hoặc a–z)
  + Nếu khóa ngắn hơn văn bản, lặp lại khóa cho đến khi đủ độ dài
- Mã hóa từng ký tự:
 + Với mỗi ký tự P_i trong văn bản và K_i trong khóa: C_i = (P_i + K_i) \mod 26
 + Trong đó:
   + P_i: vị trí của ký tự trong bảng chữ cái (A = 0, B = 1, ..., Z = 25)
   + K_i: vị trí của ký tự khóa tương ứng
   + C_i: vị trí của ký tự mã hóa
- Ghép các ký tự mã hóa lại thành bản mã
### Thuật toán giải hoá
- Chuẩn hóa bản mã và khóa như bước mã hóa
- Giải mã từng ký tự:
  + Với mỗi ký tự C_i trong bản mã và K_i trong khóa: P_i = (C_i - K_i + 26) \mod 26
  + Trong đó:
    + C_i: vị trí của ký tự mã hóa
    + K_i: vị trí của ký tự khóa
    + P_i: vị trí của ký tự gốc
- Ghép các ký tự lại để khôi phục văn bản gốc
## Không gian khoá
- Không gian khóa của Vigenère chính là tập hợp tất cả các khóa có thể được sử dụng để mã hóa văn bản. Mỗi khóa là một chuỗi ký tự, thường lấy trong bảng chữ cái gồm 26 chữ cái (A–Z).
- Nếu độ dài khóa là m, thì số lượng khóa có thể là 26𝑚. Điều này cho thấy khi chiều dài khóa càng lớn thì không gian khóa sẽ càng rộng, khiến cho việc thử hết tất cả các khóa trở nên khó khăn hơn.
## Cách phá mã (mà không cần khoá)
- Xác định độ dài khóa — Friedman Test (Index of Coincidence):
  + dùng Index of Coincidence (IC) để ước lượng độ dài khóa trung bình. Vigenère phân chia ciphertext thành các dãy giống Caesar; IC gần với IC của ngôn ngữ khi sắp xếp theo đúng bước khóa.
  + tính IC tổng của ciphertext, so sánh với IC ngôn ngữ chuẩn; hoặc tách ciphertext theo giả sử độ dài r và tính IC cho từng chuỗi cột; khi r đúng, IC các cột gần với IC tiếng mẹ đẻ.
- Phân tích tần suất theo cột (columnar frequency analysis):
  + nếu biết (hoặc đoán) độ dài khóa m, tách ciphertext thành m cột (chuỗi gồm mọi ký tự vị trí i, i+m, i+2m, ...). Mỗi cột là Caesar-cipher; áp dụng phân tích tần suất lên từng cột để tìm shift phù hợp.
  + cho mỗi cột, thử tất cả 26 shift và dùng chi-squared hoặc tương tự để chọn shift khiến phân bố gần với tần suất chuẩn (E,T,A...). Ghép các shift lại thành khóa.
  + Ưu/nhược: rất hiệu quả nếu ciphertext dài; kém với văn bản ngắn hoặc bố cục khác thường.
- Kasiski + frequency (kết hợp):
  + Ý tưởng: dùng Kasiski/Friedman để tìm m, sau đó frequency analysis để tìm từng ký tự khóa.
  + Thực tế: là workflow tiêu chuẩn, nhanh và chắc nếu ciphertext đủ dài.
## Cài đặt thuật toán mã hoá và giải mã bằng code C++ và bằng html+css+javascript
``` html
<!DOCTYPE html>
<html lang="vi">
<head>
<meta charset="utf-8" />
<meta name="viewport" content="width=device-width,initial-scale=1" />
<title>Vigenère Cipher — Tool</title>
<style>
  :root{
    --bg:#0d1117; --card:#0f1724; --accent:#6ee7b7; --muted:#9fb0c8;
  }
  *{box-sizing:border-box}
  body{
    margin:0; min-height:100vh;
    font-family: Inter, Roboto, system-ui, Arial;
    background:linear-gradient(180deg,#071021 0%, #0d1117 100%);
    color:#e6eef7; display:flex; align-items:center; justify-content:center; padding:28px;
  }
  .card{
    width:100%; max-width:980px;
    background:linear-gradient(180deg, rgba(255,255,255,0.02), rgba(255,255,255,0.01));
    border-radius:12px; padding:18px; box-shadow: 0 12px 36px rgba(2,6,23,0.7);
    display:grid; grid-template-columns: 1fr 360px; gap:18px;
  }
  header{grid-column:1/-1; display:flex; justify-content:space-between; align-items:center}
  header h1{margin:0;font-size:18px}
  header p{margin:0;color:var(--muted);font-size:13px}
  .panel{background:var(--card); padding:12px; border-radius:10px; border:1px solid rgba(255,255,255,0.03)}
  label{display:block;color:var(--muted);font-size:13px;margin-bottom:6px}
  textarea,input,select{width:100%; padding:10px 12px; border-radius:8px; border:1px solid rgba(255,255,255,0.04); background:transparent; color:inherit; font-size:14px; outline:none}
  textarea{min-height:140px; resize:vertical}
  .row{display:flex; gap:8px}
  .row > *{flex:1}
  .controls{display:flex; gap:8px; margin-top:10px; flex-wrap:wrap}
  button{background:linear-gradient(90deg,var(--accent), #34d399); border:none; color:#052018; padding:10px 12px; border-radius:8px; cursor:pointer; font-weight:700}
  button.ghost{background:transparent; border:1px solid rgba(255,255,255,0.06); color:var(--muted)}
  .note{color:var(--muted); margin-top:8px; font-size:13px}
  .warn{color:#ffd2d2; margin-top:8px; font-size:13px}
  .output{min-height:120px; white-space:pre-wrap; font-family:ui-monospace,Menlo,monospace; background:rgba(255,255,255,0.01); padding:12px; border-radius:8px; border:1px solid rgba(255,255,255,0.03)}
  footer{grid-column:1/-1;text-align:center;color:var(--muted);font-size:12px;margin-top:8px}
  @media (max-width:880px){ .card{grid-template-columns:1fr} .right{order:2} }
</style>
</head>
<body>
  <div class="card">
    <header>
      <div>
        <h1>Vigenère Cipher — Mã hóa & Giải mã</h1>
        <p>Giữ nguyên chữ hoa/chữ thường — khóa chỉ dùng chữ cái (khóa sẽ lặp)</p>
      </div>
      <div style="text-align:right">
        <div style="background:rgba(255,255,255,0.02);padding:6px 10px;border-radius:8px;color:var(--muted);font-size:13px">A=0 ... Z=25</div>
      </div>
    </header>

    <section class="panel left">
      <label for="text">Văn bản (Plaintext / Ciphertext)</label>
      <textarea id="text" placeholder="Nhập văn bản..."></textarea>

      <div style="margin-top:8px" class="row">
        <div>
          <label for="key">Khóa (keyword)</label>
          <input id="key" placeholder="vd: SECRET" />
        </div>
        <div>
          <label for="mode">Chế độ</label>
          <select id="mode">
            <option value="encrypt">Mã hóa</option>
            <option value="decrypt">Giải mã</option>
          </select>
        </div>
      </div>

      <div class="controls">
        <button id="runBtn">Thực hiện</button>
        <button id="copyBtn" class="ghost">Sao chép</button>
        <button id="clearBtn" class="ghost">Xóa</button>
      </div>

      <div id="warn" class="warn" style="display:none"></div>
      <div class="note">Lưu ý: khóa sẽ tự động loại bỏ ký tự không phải chữ; nếu khóa rỗng sau chuẩn hóa, sẽ không thể thực hiện.</div>
    </section>

    <aside class="panel right">
      <label>Kết quả</label>
      <div id="output" class="output" aria-live="polite"></div>

      <label style="margin-top:12px">Preview khóa (đã chuẩn hóa)</label>
      <div id="keyPreview" class="note" style="padding:8px;background:rgba(255,255,255,0.01);border-radius:6px;border:1px solid rgba(255,255,255,0.03)">—</div>
    </aside>

    <footer>Phiên bản: 1.0 — Bấm "Thực hiện" để mã hóa/giải mã.</footer>
  </div>

<script>
  // Helpers
  const textEl = document.getElementById('text');
  const keyEl = document.getElementById('key');
  const modeEl = document.getElementById('mode');
  const runBtn = document.getElementById('runBtn');
  const outputEl = document.getElementById('output');
  const keyPreview = document.getElementById('keyPreview');
  const warnEl = document.getElementById('warn');
  const copyBtn = document.getElementById('copyBtn');
  const clearBtn = document.getElementById('clearBtn');

  function sanitizeKey(raw) {
    // chỉ giữ chữ cái a-z, chuyển về lowercase
    return (raw || '').split('').filter(ch => /[A-Za-z]/.test(ch)).map(ch => ch.toLowerCase()).join('');
  }

  function showWarn(msg) {
    if (!msg) { warnEl.style.display = 'none'; warnEl.textContent = ''; }
    else { warnEl.style.display = 'block'; warnEl.textContent = msg; }
  }

  function shiftFromChar(ch) { // ch lowercase a-z
    return ch.charCodeAt(0) - 97;
  }

  function vigenereProcess(input, rawKey, mode) {
    const key = sanitizeKey(rawKey);
    keyPreview.textContent = key.length ? key : '— (không hợp lệ)';
    if (!key.length) {
      showWarn('Khóa không hợp lệ: sau khi loại ký tự không phải chữ, khóa rỗng.');
      return null;
    }
    showWarn('');
    let out = '';
    let kIdx = 0;
    const kLen = key.length;
    for (let i = 0; i < input.length; i++) {
      const ch = input[i];
      if (/[A-Za-z]/.test(ch)) {
        const base = (ch === ch.toUpperCase()) ? 65 : 97;
        const p = ch.charCodeAt(0) - base;
        const s = shiftFromChar(key[kIdx % kLen]);
        let c;
        if (mode === 'encrypt') {
          c = (p + s) % 26;
        } else {
          c = (p - s + 26) % 26;
        }
        out += String.fromCharCode(base + c);
        kIdx++;
      } else {
        // giữ nguyên và KHÔNG tăng kIdx
        out += ch;
      }
    }
    return out;
  }

  runBtn.addEventListener('click', () => {
    const txt = textEl.value || '';
    const rawKey = keyEl.value || '';
    const mode = modeEl.value;
    if (!txt) { showWarn('Nhập văn bản trước.'); return; }
    const res = vigenereProcess(txt, rawKey, mode);
    if (res === null) return;
    outputEl.textContent = res;
  });

  copyBtn.addEventListener('click', () => {
    const txt = outputEl.textContent || '';
    if (!txt) { showWarn('Chưa có kết quả để sao chép.'); return; }
    navigator.clipboard?.writeText(txt).then(()=> {
      showWarn('Đã sao chép vào clipboard.');
      setTimeout(()=> showWarn(''),1300);
    }).catch(()=> showWarn('Trình duyệt chặn thao tác clipboard.'));
  });

  clearBtn.addEventListener('click', () => {
    textEl.value = '';
    keyEl.value = '';
    outputEl.textContent = '';
    keyPreview.textContent = '—';
    showWarn('');
  });

  // Live preview key sanitized
  keyEl.addEventListener('input', () => {
    keyPreview.textContent = sanitizeKey(keyEl.value) || '—';
  });

  // init
  keyPreview.textContent = '—';
</script>
</body>
</html>
```
- MÃ HOÁ
<img width="1270" height="656" alt="image" src="https://github.com/user-attachments/assets/19a388fd-5c3b-4c11-b2ec-49b09421059d" />
- GIẢI MÃ
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


 






























