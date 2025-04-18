## 🔢 Problem: Count and Say

The **Count and Say** sequence is a series of digit strings defined recursively. The goal is to return the `n`th term of the sequence.

### 📄 Problem Statement

Given a positive integer `n`, return the `n`th term of the Count and Say sequence.

The sequence starts as follows:



---

## 📊 Example Cases

| Input | Output   | Explanation                                  |
|-------|----------|----------------------------------------------|
| n = 1 | `"1"`     | Base case                                    |
| n = 2 | `"11"`    | one 1 → "11"                                 |
| n = 3 | `"21"`    | two 1s → "21"                                |
| n = 4 | `"1211"`  | one 2, one 1 → "1211"                        |
| n = 5 | `"111221"`| one 1, one 2, two 1s → "111221"              |

---


---

## 🧠 Algorithm

### 📌 Base Case
Start with the string `"1"` for `countAndSay(1)`.

### 🔁 Recursive/Iterative Step
Generate the next term by applying **Run-Length Encoding (RLE)** on the current term.

### ⚙️ Run-Length Encoding Logic
1. Traverse the current string character by character.
2. Count the number of times the same digit appears consecutively.
3. Append the **count followed by the digit** to a new string.
4. Repeat the process for `n - 1` steps.

---



