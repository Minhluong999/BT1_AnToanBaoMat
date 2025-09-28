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

Mã hoá: E(p) = (p + k) mod 26

với p = 0..25 (A=0,B=1...), k ∈ {0..25}

Giải mã: D(c) = (c - k) mod 26

### Không gian khoá: 26 (k = 0..25)

### Cách phá mã (không cần khoá):

Brute-force thử 26 khả năng.

Phân tích tần suất chữ cái (E, T, A...).

Với ngôn ngữ có cấu trúc, 1–2 lượt thử là đủ.

### MÃ HOÁ
<img width="793" height="693" alt="image" src="https://github.com/user-attachments/assets/f7f61ec2-8009-45ad-b3d0-bc49393b6af9" />
### GIẢI MÃ
<img width="786" height="678" alt="image" src="https://github.com/user-attachments/assets/62ad0907-ec0e-4a52-97fa-1994b56dd912" />

## 2. Affine
## Tên gọi: 
Affine Cipher (Mã hóa Affine)
## Thuật toán mã hoá, thuật toán giải mã
### Thuật toán mã hoá
#### E(x)=(a⋅x+b)modm
- Trong đó:
  + x: vị trí của ký tự gốc trong bảng chữ cái (A=0, B=1, ..., Z=25).
  + a,b: khóa bí mật (với gcd(𝑎,𝑚)=1).
  + m: số lượng ký tự trong bảng chữ cái (thường 𝑚=26).
  + Kết quả 𝐸(𝑥) được đổi lại thành ký tự mã hóa.
### Thuật toán giải mã
#### D(y)=a−1⋅(y−b)mod m
- Trong đó:
  + y: vị trí của ký tự đã mã hóa
  + a^{-1}: số sao cho a \cdot a^{-1} \equiv 1 \mod m
  + b: hệ số dịch chuyển như ở bước mã hóa
## Không gian khoá
- a phải thỏa mãn: gcd(a, m) = 1
  + Với m = 26, các giá trị a hợp lệ là: a \in \{1, 3, 5, 7, 9, 11, 15, 17, 19, 21, 23, 25\} -> Có 12 giá trị thỏa mãn điều kiện.
- b \in \{0, 1, 2, ..., 25\} -> Có 26 giá trị có thể chọn.
-> Tổng số khóa hợp lệ: \text{Không gian khóa} = 12 \times 26 = 312 \text{ cặp khóa } (a, b)
## Cách phá mã (mà không cần khoá)
- Phương pháp duyệt toàn bộ khóa (brute-force): Với m=26 có 12 giá trị hợp lệ cho 𝑎 và 26 cho 𝑏 ⇒ chỉ 312 tổ hợp — rất nhỏ, dò hết được.
- Phân tích tần suất (Frequency analysis):
  + Ý nghĩa: ánh xạ ký tự hay xuất hiện nhất trong bản mã vào chữ cái hay xuất hiện nhất trong ngôn ngữ
  + Nhược: kém chính xác với văn bản ngắn hoặc khi phân bố khác.
- Kết hợp nhiều phương pháp:
  + Thường dùng brute-force + scoring (chi-squared / dictionary match) là nhanh và đáng tin.
  + Nếu có một số đoạn biết trước (common words như "the", "and"), dùng known-plaintext để rút khóa nhanh.
## Cài đặt thuật toán mã hoá và giải mã bằng code C++ và bằng html+css+javascript
``` html
<!DOCTYPE html>
<html lang="vi">
<head>
<meta charset="utf-8" />
<meta name="viewport" content="width=device-width,initial-scale=1" />
<title>Affine Cipher — Tool</title>
<style>
    :root{
        --bg:#0f1724; --card:#0b1220; --accent:#7c3aed; --muted:#9aa6b2; --glass: rgba(255,255,255,0.03);
    }
    *{box-sizing:border-box}
    body{
        margin:0;
        font-family: Inter, Roboto, Arial, sans-serif;
        background:
          radial-gradient(1200px 600px at 10% 10%, rgba(124,58,237,0.12), transparent 8%),
          radial-gradient(1000px 500px at 90% 90%, rgba(3,105,161,0.06), transparent 8%),
          var(--bg);
        color:#e6eef7;
        min-height:100vh;
        display:flex;
        align-items:center;
        justify-content:center;
        padding:28px;
    }

    .container{
        width:100%;
        max-width:980px;
        background: linear-gradient(180deg, rgba(255,255,255,0.02), rgba(255,255,255,0.01));
        border-radius:14px;
        box-shadow: 0 10px 30px rgba(2,6,23,0.7);
        padding:22px;
        display:grid;
        grid-template-columns: 1fr 420px;
        gap:18px;
        align-items:start;
    }

    header{
        grid-column: 1 / -1;
        display:flex;
        justify-content:space-between;
        align-items:center;
        gap:12px;
    }

    header h1{
        font-size:20px;
        margin:0;
        letter-spacing:0.2px;
    }
    header p{margin:0;color:var(--muted);font-size:13px}

    .panel{
        background:var(--card);
        border-radius:10px;
        padding:14px;
        border: 1px solid rgba(255,255,255,0.03);
    }

    .left .field{margin-bottom:12px}
    label{display:block;font-size:13px;color:var(--muted);margin-bottom:6px}
    textarea, input[type="text"], input[type="number"], select{
        width:100%;
        padding:10px 12px;
        border-radius:8px;
        border:1px solid rgba(255,255,255,0.04);
        background:var(--glass);
        color:inherit;
        font-size:14px;
        outline:none;
        resize:vertical;
    }
    textarea{min-height:140px; max-height:300px}
    .row{display:flex;gap:10px}
    .row > *{flex:1}

    .actions{display:flex;gap:8px;margin-top:10px}
    button{
        padding:10px 12px;
        border-radius:8px;
        border: none;
        cursor:pointer;
        font-weight:600;
        background:linear-gradient(90deg,var(--accent), #0ea5a3);
        color:white;
        box-shadow: 0 6px 18px rgba(124,58,237,0.12);
    }
    button.ghost{
        background:transparent;
        border:1px solid rgba(255,255,255,0.06);
        color:var(--muted);
        font-weight:600;
    }
    .small{padding:8px 10px;font-size:13px}
    .note{font-size:13px;color:var(--muted);margin-top:6px}

    .right .meta{display:flex;gap:8px;align-items:center;margin-bottom:10px}
    .chip{
        background: rgba(255,255,255,0.025);
        padding:8px 10px;border-radius:999px;border:1px solid rgba(255,255,255,0.02);
        color:var(--muted);font-size:13px;
    }

    .output{
        min-height:120px;
        white-space:pre-wrap;
        background: linear-gradient(180deg, rgba(255,255,255,0.01), rgba(255,255,255,0.00));
        border-radius:8px;padding:12px;border:1px solid rgba(255,255,255,0.03);
        font-family: ui-monospace, SFMono-Regular, Menlo, monospace;
        color:#dff3ff;
    }

    .warning{color:#ffcccb;font-size:13px;margin-top:8px}
    .brutelist{max-height:260px;overflow:auto;padding:10px;border-radius:8px;border:1px solid rgba(255,255,255,0.03);background:rgba(255,255,255,0.01)}
    .bf-item{padding:6px 6px;border-bottom:1px dashed rgba(255,255,255,0.02);font-size:13px}
    .controls{display:flex;gap:8px;flex-wrap:wrap;margin-top:8px}

    footer{grid-column:1/-1;margin-top:8px;color:var(--muted);font-size:12px;text-align:center}
    @media (max-width:980px){
        .container{grid-template-columns: 1fr; padding:16px}
        .right{order:2}
    }
</style>
</head>
<body>
  <div class="container">
    <header>
      <div>
        <h1>Affine Cipher — Mã hóa & Giải mã</h1>
        <p>Chuẩn: Extended Euclid cho nghịch đảo, giữ nguyên ký tự không phải chữ, hỗ trợ uppercase/lowercase.</p>
      </div>
      <div style="text-align:right">
        <div class="chip">Bảng chữ: A=0..Z=25</div>
      </div>
    </header>

    <section class="panel left">
      <div class="field">
        <label for="inputText">Văn bản (Plaintext / Ciphertext)</label>
        <textarea id="inputText" placeholder="Nhập văn bản..."></textarea>
      </div>

      <div class="row">
        <div>
          <label for="keyA">Khóa a (nhân)</label>
          <input id="keyA" type="number" value="5" />
        </div>
        <div>
          <label for="keyB">Khóa b (dịch)</label>
          <input id="keyB" type="number" value="8" />
        </div>
      </div>

      <div class="controls">
        <button id="encryptBtn">Mã hóa (Encrypt)</button>
        <button id="decryptBtn">Giải mã (Decrypt)</button>
        <button id="bruteBtn" class="ghost small">Brute-force (tất cả 312)</button>
        <button id="copyOut" class="ghost small">Sao chép kết quả</button>
        <button id="clearBtn" class="ghost small">Xóa</button>
      </div>

      <div class="note">Lưu ý: giá trị <strong>a</strong> phải nguyên tố cùng nhau với 26 (vd: 1,3,5,7,9,11,15,17,19,21,23,25).</div>
      <div id="warn" class="warning" style="display:none"></div>
    </section>

    <aside class="panel right">
      <div class="meta">
        <div class="chip">a: <span id="showA">5</span></div>
        <div class="chip">b: <span id="showB">8</span></div>
        <div class="chip">a mod 26: <span id="showAMod">5</span></div>
      </div>

      <div>
        <label>Kết quả</label>
        <div id="output" class="output" aria-live="polite"></div>
      </div>

      <div style="margin-top:12px">
        <label>Kết quả brute-force (nhấp để sao chép một dòng)</label>
        <div id="bruteList" class="brutelist" title="Danh sách các kết quả brute-force"></div>
      </div>
    </aside>

    <footer>Phiên bản: 1.0 — Lưu ý: Affine là mã cổ điển, dễ phá khi văn bản dài.</footer>
  </div>

<script>
/* --- Helpers --- */
function norm26(n){
    n = Number(n) % 26;
    if (n < 0) n += 26;
    return n;
}

function egcd(a,b){
    // Extended Euclid iterative
    a = Math.floor(a); b = Math.floor(b);
    let x0=1, x1=0, y0=0, y1=1;
    while (b !== 0) {
        let q = Math.floor(a / b);
        let t = a - q * b; a = b; b = t;
        t = x0 - q * x1; x0 = x1; x1 = t;
        t = y0 - q * y1; y0 = y1; y1 = t;
    }
    return {g: a, x: x0, y: y0};
}

function modInverse26(a){
    a = norm26(a);
    const r = egcd(a,26);
    if (r.g !== 1) return null;
    return norm26(r.x);
}

function isLetter(ch){
    return /[A-Za-z]/.test(ch);
}
function baseOf(ch){ return /[A-Z]/.test(ch) ? 65 : 97; }

/* --- Affine operations --- */
function encodeChar(ch, a, b){
    if (!isLetter(ch)) return ch;
    let base = baseOf(ch);
    let x = ch.charCodeAt(0) - base;
    let y = norm26(a * x + b);
    return String.fromCharCode(y + base);
}
function decodeChar(ch, a, b){
    if (!isLetter(ch)) return ch;
    let aInv = modInverse26(a);
    if (aInv === null) return '?';
    let base = baseOf(ch);
    let y = ch.charCodeAt(0) - base;
    let x = norm26(aInv * (y - b));
    return String.fromCharCode(x + base);
}

function encryptAffine(text, a, b){
    a = norm26(a); b = norm26(b);
    let out = '';
    for (let ch of text) out += encodeChar(ch, a, b);
    return out;
}
function decryptAffine(text, a, b){
    a = norm26(a); b = norm26(b);
    let aInv = modInverse26(a);
    if (aInv === null) return null;
    let out = '';
    for (let ch of text) out += decodeChar(ch, a, b);
    return out;
}

/* --- UI bindings --- */
const inputText = document.getElementById('inputText');
const keyA = document.getElementById('keyA');
const keyB = document.getElementById('keyB');
const encryptBtn = document.getElementById('encryptBtn');
const decryptBtn = document.getElementById('decryptBtn');
const bruteBtn = document.getElementById('bruteBtn');
const outputEl = document.getElementById('output');
const warnEl = document.getElementById('warn');
const showA = document.getElementById('showA');
const showB = document.getElementById('showB');
const showAMod = document.getElementById('showAMod');
const bruteList = document.getElementById('bruteList');
const copyOut = document.getElementById('copyOut');
const clearBtn = document.getElementById('clearBtn');

function updateChips(){
    const a = Number(keyA.value || 0);
    const b = Number(keyB.value || 0);
    showA.textContent = a;
    showB.textContent = b;
    showAMod.textContent = norm26(a);
}
updateChips();

[keyA, keyB].forEach(el => el.addEventListener('input', updateChips));

function showWarning(msg){
    if (!msg) { warnEl.style.display='none'; warnEl.textContent=''; }
    else { warnEl.style.display='block'; warnEl.textContent = msg; }
}

encryptBtn.addEventListener('click', ()=> {
    showWarning('');
    const a = Number(keyA.value || 0), b = Number(keyB.value || 0);
    const aMod = norm26(a);
    // check coprime
    if (modInverse26(aMod) === null){
        showWarning('Giá trị a không hợp lệ — không có nghịch đảo modulo 26. Chọn a sao cho gcd(a,26)=1.');
        outputEl.textContent = '';
        return;
    }
    const text = inputText.value || '';
    const ct = encryptAffine(text, aMod, b);
    outputEl.textContent = ct;
    bruteList.innerHTML = '';
});

decryptBtn.addEventListener('click', ()=> {
    showWarning('');
    const a = Number(keyA.value || 0), b = Number(keyB.value || 0);
    const aMod = norm26(a);
    if (modInverse26(aMod) === null){
        showWarning('Giá trị a không hợp lệ — không có nghịch đảo modulo 26. Chọn a sao cho gcd(a,26)=1.');
        outputEl.textContent = '';
        return;
    }
    const text = inputText.value || '';
    const pt = decryptAffine(text, aMod, b);
    if (pt === null){
        showWarning('Không thể giải mã (a không có nghịch đảo).');
        outputEl.textContent = '';
        return;
    }
    outputEl.textContent = pt;
    bruteList.innerHTML = '';
});

bruteBtn.addEventListener('click', ()=> {
    showWarning('');
    bruteList.innerHTML = '';
    const text = inputText.value || '';
    if (!text){
        showWarning('Nhập bản mã để brute-force.');
        return;
    }
    const validAs = [];
    for (let a=0;a<26;a++){
        let inv = modInverse26(a);
        if (inv !== null) validAs.push(a);
    }
    // validAs.length should be 12
    let html = '';
    for (let a of validAs){
        for (let b=0;b<26;b++){
            const pt = decryptAffine(text, a, b);
            // build a clickable item
            const item = document.createElement('div');
            item.className = 'bf-item';
            item.textContent = `a=${a}, b=${b} -> ${pt}`;
            item.title = 'Nhấp để sao chép dòng này';
            item.addEventListener('click', ()=> {
                navigator.clipboard?.writeText(pt).then(()=> {
                    showWarning('Đã sao chép dòng đã chọn vào clipboard.');
                    setTimeout(()=> showWarning(''),1800);
                }).catch(()=> {
                    showWarning('Không thể sao chép — trình duyệt chặn clipboard.');
                });
            });
            bruteList.appendChild(item);
        }
    }
    outputEl.textContent = '';
});

copyOut.addEventListener('click', ()=> {
    const txt = outputEl.textContent || '';
    if (!txt) { showWarning('Chưa có kết quả để sao chép.'); return; }
    navigator.clipboard?.writeText(txt).then(()=> {
        showWarning('Đã sao chép kết quả vào clipboard.');
        setTimeout(()=> showWarning(''),1700);
    }).catch(()=> {
        showWarning('Không thể sao chép — trình duyệt chặn clipboard.');
    });
});

clearBtn.addEventListener('click', ()=> {
    inputText.value = '';
    outputEl.textContent = '';
    bruteList.innerHTML = '';
    showWarning('');
});

</script>
</body>
</html>
```
- MÃ HOÁ
<img width="1325" height="720" alt="image" src="https://github.com/user-attachments/assets/1eb44626-b673-4328-9d05-45bab3f8de76" />
- GIẢI MÃ
<img width="1300" height="726" alt="image" src="https://github.com/user-attachments/assets/2850171c-f009-438d-a664-82f6e94dbfff" />

## 3. Hoán vị
## Tên gọi: 
- Transposition Cipher (Permutation Cipher / Mã hoá hoán vị / Mã hoá chuyển vị)
- Đây là nhóm phương pháp mã hoá cổ điển dựa trên việc hoán đổi vị trí các ký tự trong bản rõ thay vì thay thế ký tự như Caesar hay Affine.
## Thuật toán mã hoá, thuật toán giải mã
### Thuật toán mã hoá
- Chọn khóa: là một hoán vị của các số từ 1 đến n (với n là độ dài khóa). Ví dụ: khóa = 3 1 4 2.
- Viết bản rõ theo hàng: xếp bản rõ thành một bảng có n cột.
- Điền thêm ký tự giả (padding) nếu hàng cuối chưa đủ.
- Đọc bản mã theo thứ tự cột của khóa: theo chỉ số cột trong khóa, nối lại thành chuỗi bản mã.
### Thuật toán giải mã
- Xác định số hàng: chia độ dài bản mã cho số cột (n). Nếu không chia hết, một số cột cuối sẽ có ít ký tự hơn.
- Chia bản mã vào cột theo thứ tự khóa: lần lượt điền ký tự bản mã vào từng cột dựa trên khóa.
- Ghép bảng lại theo hàng ngang để thu được bản rõ gốc.
## Không gian khoá
- Công thức chung: nếu khóa là một hoán vị của 𝑛 cột thì số khóa khả dĩ là: ∣K∣=n!
- Là tập hợp tất cả các hoán vị có thể của các cột trong bảng mã hóa. Mỗi hoán vị tương ứng với một khóa duy nhất.
- Giả sử dùng khóa có độ dài n (tức là chia văn bản thành n cột), thì số lượng hoán vị có thể của các cột là: \text{Không gian khóa} = n!
## Cách phá mã (mà không cần khoá)
- Brute-force theo độ dài khóa (Permutation brute-force):
  + Ý chính: thử mọi hoán vị cho một độ dài khóa cố định.
  + Bước: đoán 𝑛 (số cột), sinh tất cả 𝑛! hoán vị, áp dụng mỗi hoán vị để tái tạo plaintext, dùng scoring (đếm từ hợp lệ hoặc log-likelihood) để chọn kết quả tốt nhất.
- Thử mọi độ dài cột + phân chia cột (column length enumeration):
  + Không biết 𝑛 thì thử các 𝑛 khả dĩ; với mỗi 𝑛 chia ciphertext theo số hàng/col rồi thử hoán vị cột.
  + Cho mỗi 𝑛 từ 2..max, tính số hàng (và cột ngắn/lâu nếu không đều), rồi brute-force hoán vị cột + scoring.
- Crib / Known-plaintext (khoảng khớp mẫu):
  + nếu biết (hoặc đoán) một từ/đoạn xuất hiện trong plaintext (ví dụ "the", "and"), thử căn chỉnh vị trí đó qua các cột để suy ra hoán vị.
  + đặt mẫu vào các vị trí khả dĩ trong ma trận cột và giải để tìm ánh xạ cột có thể.
- Phân tích từ/chữ (Word-pattern matching / anagramming)
- Đánh giá bằng scoring ngôn ngữ (bigrams/trigrams / log-likelihood)
## Cài đặt thuật toán mã hoá và giải mã bằng code C++ và bằng html+css+javascript
``` html
<!DOCTYPE html>
<html lang="vi">
<head>
<meta charset="utf-8" />
<meta name="viewport" content="width=device-width,initial-scale=1" />
<title>Transposition (Permutation) Cipher — Tool</title>
<style>
  :root{
    --bg:#0b1020; --card:#0f1726; --accent:#ff7a59; --muted:#9fb0c8;
    --glass: rgba(255,255,255,0.03);
  }
  *{box-sizing:border-box}
  body{
    margin:0;
    min-height:100vh;
    font-family: Inter, Roboto, "Segoe UI", Arial, sans-serif;
    background: linear-gradient(180deg,#06121a 0%, #0b1020 60%);
    color:#e8f1f8;
    display:flex;
    align-items:center;
    justify-content:center;
    padding:28px;
  }

  .wrap{
    width:100%; max-width:1100px;
    border-radius:12px;
    padding:18px;
    background: linear-gradient(180deg, rgba(255,255,255,0.02), rgba(255,255,255,0.01));
    box-shadow: 0 12px 40px rgba(2,6,23,0.7);
    display:grid;
    grid-template-columns: 1fr 420px;
    gap:18px;
  }

  header{grid-column:1/-1; display:flex; align-items:center; justify-content:space-between}
  header h1{margin:0;font-size:18px}
  header p{margin:0;color:var(--muted);font-size:13px}

  .panel{
    background:var(--card);
    padding:14px;
    border-radius:10px;
    border:1px solid rgba(255,255,255,0.03);
  }

  label{display:block;color:var(--muted);font-size:13px;margin-bottom:6px}
  textarea, input, select{width:100%; padding:10px 12px; border-radius:8px; border:1px solid rgba(255,255,255,0.04); background:var(--glass); color:inherit; font-size:14px; outline:none}
  textarea{min-height:140px; resize:vertical}
  .small{font-size:13px;padding:8px 10px}
  .row{display:flex; gap:10px}
  .row > *{flex:1}

  .controls{display:flex; gap:8px; margin-top:10px; flex-wrap:wrap}
  button{background:linear-gradient(90deg,var(--accent), #ffb86b); border:none; color:#08101a; padding:10px 12px; border-radius:8px; cursor:pointer; font-weight:700}
  button.ghost{background:transparent; border:1px solid rgba(255,255,255,0.06); color:var(--muted); font-weight:600}
  .note{color:var(--muted); margin-top:8px; font-size:13px}
  .warn{color:#ffd2d2; font-size:13px; margin-top:8px}

  .right .meta{display:flex; gap:8px; margin-bottom:8px; align-items:center}
  .chip{background:rgba(255,255,255,0.02); padding:8px 10px; border-radius:999px; color:var(--muted); font-size:13px}
  .output{min-height:120px; white-space:pre-wrap; font-family: ui-monospace, SFMono-Regular, Menlo, monospace; background:rgba(255,255,255,0.01); padding:12px; border-radius:8px; border:1px solid rgba(255,255,255,0.03)}
  .matrix{margin-top:10px; font-size:13px; color:var(--muted); display:block; max-height:220px; overflow:auto; padding:8px; border-radius:8px; border:1px solid rgba(255,255,255,0.03); background:rgba(255,255,255,0.01)}
  .perm-preview{margin-top:8px; color:var(--muted); font-size:13px}

  footer{grid-column:1/-1; text-align:center; color:var(--muted); font-size:12px; margin-top:10px}
  @media (max-width:980px){
    .wrap{grid-template-columns: 1fr}
  }
</style>
</head>
<body>
  <div class="wrap">
    <header>
      <div>
        <h1>Transposition (Permutation) Cipher — Tool</h1>
        <p>Columnar transposition: điền theo hàng, đọc theo thứ tự cột (hoán vị)</p>
      </div>
      <div class="chip">Columns = n (độ dài khóa)</div>
    </header>

    <section class="panel">
      <label for="inputText">Văn bản (Plaintext / Ciphertext)</label>
      <textarea id="inputText" placeholder="Nhập văn bản..."></textarea>

      <div class="row" style="margin-top:8px">
        <div>
          <label>Kiểu khóa</label>
          <select id="keyMode">
            <option value="numeric">Numeric (ví dụ: 3 1 4 2)</option>
            <option value="keyword">Keyword (ví dụ: ZEBRAS)</option>
          </select>
        </div>
        <div>
          <label>Số cột (n)</label>
          <input id="numCols" type="number" min="1" value="4" />
        </div>
      </div>

      <div id="numericKeyArea" style="margin-top:8px">
        <label>Khóa (dạng số - thứ tự đọc cột, 1-based)</label>
        <input id="numericKey" placeholder="vd: 3 1 4 2" />
      </div>

      <div id="keywordArea" style="display:none; margin-top:8px">
        <label>Keyword</label>
        <input id="keyword" placeholder="vd: ZEBRAS" />
        <div class="note">Keyword sẽ được chuyển thành hoán vị theo thứ tự chữ cái (stable).</div>
      </div>

      <div style="margin-top:10px">
        <label>Padding</label>
        <div style="display:flex; gap:8px">
          <select id="paddingMode" style="width:160px">
            <option value="none">Không padding (mặc định)</option>
            <option value="pad">Thêm padding để làm đầy</option>
          </select>
          <input id="padChar" type="text" value="X" maxlength="1" style="width:60px" />
        </div>
        <div class="note">Chọn padding nếu bạn muốn làm cho hàng cuối đầy đủ. Nếu không, bản mã giữ nguyên độ dài.</div>
      </div>

      <div class="controls">
        <button id="encryptBtn">Mã hóa</button>
        <button id="decryptBtn">Giải mã</button>
        <button id="copyBtn" class="ghost">Sao chép</button>
        <button id="clearBtn" class="ghost">Xóa</button>
      </div>

      <div id="warn" class="warn" style="display:none"></div>
      <div class="perm-preview" id="permPreview"></div>
    </section>

    <aside class="panel right">
      <div class="meta">
        <div class="chip">n = <span id="showN">4</span></div>
        <div class="chip">padding = <span id="showPad">none</span></div>
      </div>

      <label>Kết quả</label>
      <div id="output" class="output"></div>

      <label style="margin-top:12px">Preview ma trận (hàng x cột)</label>
      <div id="matrixPreview" class="matrix" aria-live="polite"></div>
    </aside>

    <footer>Phiên bản: 1.0 — Lưu ý: tool xử lý chữ & ký tự như nhập (không loại bỏ khoảng trắng tự động).</footer>
  </div>

<script>
/* --- Helpers và thuật toán --- */
function normN(n){
  n = Number(n) || 0;
  if (n < 1) n = 1;
  return Math.floor(n);
}

// chuyển keyword -> hoán vị 1-based (stable rank)
function permutationFromKeyword(key){
  // loại bỏ khoảng trắng đầu/cuối
  key = key.replace(/^\s+|\s+$/g,'');
  const arr = [];
  for (let i=0;i<key.length;i++) arr.push({ch: key[i].toLowerCase(), idx: i});
  // stable sort theo chữ
  const sorted = arr.slice().sort((a,b)=>{
    if (a.ch < b.ch) return -1;
    if (a.ch > b.ch) return 1;
    return a.idx - b.idx;
  });
  const perm = new Array(key.length);
  for (let i=0;i<sorted.length;i++){
    perm[sorted[i].idx] = i+1; // 1-based
  }
  return perm;
}

// parse numeric key "3 1 4 2"
function parseNumericKey(s){
  const parts = s.trim().split(/\s+/).filter(Boolean);
  const out = [];
  for (let p of parts){
    const v = parseInt(p,10);
    if (Number.isNaN(v)) return null;
    out.push(v);
  }
  return out;
}

// kiểm tra hoán vị 1..n
function isValidPermutation(perm, n){
  if (!Array.isArray(perm)) return false;
  if (perm.length !== n) return false;
  const seen = new Array(n+1).fill(false);
  for (let v of perm){
    if (!Number.isInteger(v) || v < 1 || v > n) return false;
    if (seen[v]) return false;
    seen[v] = true;
  }
  return true;
}

// xây ma trận hàng-then-col, trả object {rows, cols, grid, rowsCount, colLengths}
function buildGridFromPlain(plain, n, padMode, padChar){
  const len = plain.length;
  const rows = Math.ceil(len / n);
  const rmod = len % n;
  const fullCols = rmod === 0 ? n : rmod; // cột 0..fullCols-1 có rows chars
  const grid = [];
  let pos = 0;
  for (let r=0;r<rows;r++){
    const row = [];
    for (let c=0;c<n;c++){
      if (pos < len){
        row.push(plain[pos++]);
      } else {
        if (padMode === 'pad') row.push(padChar);
        else row.push(''); // empty cell
      }
    }
    grid.push(row);
  }
  // colLengths
  const colLengths = new Array(n);
  for (let c=0;c<n;c++){
    colLengths[c] = (c < fullCols) ? rows : (rows-1);
    if (padMode === 'pad') colLengths[c] = rows;
  }
  return {rows, cols:n, grid, colLengths};
}

// Encrypt: fill rows left-to-right, then read columns by perm order
function encryptColumnar(plain, perm, padMode='none', padChar='X'){
  const n = perm.length;
  const info = buildGridFromPlain(plain, n, padMode, padChar);
  // read columns in perm order
  let out = '';
  for (let k=0;k<perm.length;k++){
    const colIdx = perm[k]-1;
    for (let r=0;r<info.rows;r++){
      const ch = info.grid[r][colIdx];
      if (ch !== '') out += ch;
    }
    // if padMode == 'pad', empty won't occur
  }
  return out;
}

// Decrypt: determine colLengths (based on plain-filling), then distribute cipher into columns in perm order, then read rows
function decryptColumnar(cipher, perm, padMode='none', padChar='X'){
  const n = perm.length;
  const len = cipher.length;
  const rows = Math.ceil(len / n);
  const rmod = len % n;
  const fullCols = rmod === 0 ? n : rmod;
  // If original used padMode 'pad' then all columns have rows length
  const colLen = new Array(n);
  for (let c=0;c<n;c++){
    colLen[c] = (c < fullCols) ? rows : (rows-1);
  }
  if (padMode === 'pad'){
    // if padded, ciphertext length will be rows * n; then all have length rows
    const expected = rows * n;
    if (len === expected){
      for (let c=0;c<n;c++) colLen[c] = rows;
    } else {
      // best effort: if lengths mismatch, fallback to previous rule
    }
  }

  // distribute
  const colsArr = new Array(n).fill(null).map(()=>[]);
  let pos = 0;
  for (let k=0;k<n;k++){
    const colIdx = perm[k]-1;
    const L = Math.min(colLen[colIdx], Math.max(0, len - pos));
    const seg = cipher.substr(pos, L);
    colsArr[colIdx] = seg.split('');
    pos += L;
  }

  // read row-wise
  let out = '';
  for (let r=0;r<rows;r++){
    for (let c=0;c<n;c++){
      if (colsArr[c][r] !== undefined && colsArr[c][r] !== ''){
        out += colsArr[c][r];
      }
    }
  }

  // if padMode pad, optionally trim trailing padChar (common)
  if (padMode === 'pad' && padChar){
    while (out.endsWith(padChar)) out = out.slice(0,-1);
  }
  return out;
}

/* --- UI Bindings --- */
const inputText = document.getElementById('inputText');
const keyMode = document.getElementById('keyMode');
const numericKeyArea = document.getElementById('numericKeyArea');
const keywordArea = document.getElementById('keywordArea');
const numericKey = document.getElementById('numericKey');
const keyword = document.getElementById('keyword');
const numCols = document.getElementById('numCols');
const paddingMode = document.getElementById('paddingMode');
const padChar = document.getElementById('padChar');
const encryptBtn = document.getElementById('encryptBtn');
const decryptBtn = document.getElementById('decryptBtn');
const copyBtn = document.getElementById('copyBtn');
const clearBtn = document.getElementById('clearBtn');
const warn = document.getElementById('warn');
const output = document.getElementById('output');
const matrixPreview = document.getElementById('matrixPreview');
const permPreview = document.getElementById('permPreview');
const showN = document.getElementById('showN');
const showPad = document.getElementById('showPad');

function showWarn(msg){
  if (!msg){ warn.style.display='none'; warn.textContent=''; }
  else { warn.style.display='block'; warn.textContent = msg; }
}

function updateUI(){
  const mode = keyMode.value;
  numericKeyArea.style.display = (mode === 'numeric') ? 'block' : 'none';
  keywordArea.style.display = (mode === 'keyword') ? 'block' : 'none';
  showN.textContent = numCols.value;
  showPad.textContent = (paddingMode.value === 'none') ? 'none' : `pad '${padChar.value || 'X'}'`;
  updatePermPreview();
  previewMatrix();
}
keyMode.addEventListener('change', updateUI);
numCols.addEventListener('input', updateUI);
paddingMode.addEventListener('change', updateUI);
padChar.addEventListener('input', updateUI);
numericKey.addEventListener('input', updateUI);
keyword.addEventListener('input', updateUI);

function getPermutation(){
  const n = normN(numCols.value);
  const mode = keyMode.value;
  if (mode === 'numeric'){
    const arr = parseNumericKey(numericKey.value || '');
    if (!arr || arr.length !== n) return {ok:false, err:'Khóa số phải có đúng ' + n + ' số (1-based).', perm:null};
    if (!isValidPermutation(arr, n)) return {ok:false, err:'Khóa số không phải hoán vị hợp lệ của 1..' + n, perm:null};
    return {ok:true, perm:arr};
  } else {
    // keyword -> perm length must match n (or we can ignore n and set n = keyword.length)
    const kw = (keyword.value || '').trim();
    if (kw.length === 0) return {ok:false, err:'Keyword rỗng.', perm:null};
    const perm = permutationFromKeyword(kw);
    if (perm.length !== n){
      return {ok:false, err:'Độ dài keyword phải bằng n (số cột). Hoặc thay đổi n cho phù hợp.', perm:null};
    }
    return {ok:true, perm:perm};
  }
}

function updatePermPreview(){
  const res = getPermutation();
  if (!res.ok){
    permPreview.textContent = res.err;
    permPreview.style.color = '';
  } else {
    permPreview.textContent = 'Hoán vị (1-based): ' + res.perm.join(' ');
    permPreview.style.color = 'var(--muted)';
  }
}

function previewMatrix(){
  const text = inputText.value || '';
  const n = normN(numCols.value);
  const padMode = paddingMode.value;
  const pchar = padChar.value || 'X';
  if (n <= 0) { matrixPreview.textContent = ''; return; }
  const info = buildGridFromPlain(text, n, padMode, pchar);
  // build ASCII preview rows
  let html = '';
  for (let r=0;r<info.rows;r++){
    html += '| ';
    for (let c=0;c<n;c++){
      const val = info.grid[r][c] === '' ? '·' : escapeHtml(info.grid[r][c]);
      html += padCell(val,4) + ' | ';
    }
    html += '\n';
  }
  matrixPreview.textContent = html;
}

function padCell(s,len){
  s = String(s);
  while (s.length < len) s += ' ';
  return s;
}

function escapeHtml(ch){
  if (ch === '<') return '&lt;';
  if (ch === '>') return '&gt;';
  if (ch === '&') return '&amp;';
  return ch;
}

encryptBtn.addEventListener('click', ()=>{
  showWarn('');
  const text = inputText.value || '';
  if (text.length === 0){ showWarn('Nhập văn bản trước khi mã hóa.'); return; }
  const n = normN(numCols.value);
  if (n <= 0){ showWarn('Số cột không hợp lệ.'); return; }
  const pm = getPermutation();
  if (!pm.ok){ showWarn(pm.err); return; }
  const padMode = paddingMode.value;
  const padCharacter = padChar.value || 'X';
  const ct = encryptColumnar(text, pm.perm, padMode, padCharacter);
  output.textContent = ct;
  previewMatrix();
});

decryptBtn.addEventListener('click', ()=>{
  showWarn('');
  const text = inputText.value || '';
  if (text.length === 0){ showWarn('Nhập văn bản (ciphertext) trước khi giải mã.'); return; }
  const n = normN(numCols.value);
  if (n <= 0){ showWarn('Số cột không hợp lệ.'); return; }
  const pm = getPermutation();
  if (!pm.ok){ showWarn(pm.err); return; }
  const padMode = paddingMode.value;
  const padCharacter = padChar.value || 'X';
  const pt = decryptColumnar(text, pm.perm, padMode, padCharacter);
  output.textContent = pt;
  previewMatrix();
});

copyBtn.addEventListener('click', ()=>{
  const txt = output.textContent || '';
  if (!txt){ showWarn('Không có kết quả để sao chép.'); return; }
  navigator.clipboard?.writeText(txt).then(()=> {
    showWarn('Đã sao chép vào clipboard.');
    setTimeout(()=> showWarn(''),1400);
  }).catch(()=> showWarn('Trình duyệt chặn thao tác clipboard.'));
});

clearBtn.addEventListener('click', ()=>{
  inputText.value = '';
  output.textContent = '';
  numericKey.value = '';
  keyword.value = '';
  updateUI();
  showWarn('');
});

/* utils */
function normN(n){ n = Number(n) || 0; if (n < 1) n = 1; return Math.floor(n); }

// initial UI
updateUI();

</script>
</body>
</html>
```

- MÃ HOÁ
<img width="1451" height="816" alt="image" src="https://github.com/user-attachments/assets/6e3a41da-f952-422f-9650-b248e3a65206" />
- GIẢI MÃ
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


 






























