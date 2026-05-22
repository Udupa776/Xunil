# Xunil 🪞💻

> Xunil = Linux reversed

A fun Linux-inspired reverse terminal written in C++.

In this terminal, commands are typed in reverse form.

Example:

| Normal Command | Xunil Command |
|----------------|---------------|
| echo           | ohce          |
| ls             | sl            |
| cd             | dc            |
| mkdir          | ridkm         |
| touch          | hcuot         |

---

## ✨ Features

- Reverse command execution
- Custom shell prompt
- File creation support
- Directory navigation
- File reading
- Directory listing
- Lightweight and simple
- Built using modern C++

---

## 🛠 Built With

- C++
- STL
- `<filesystem>`
- Linux system calls

---

## 📦 Compilation

Compile using g++:

```bash
g++ main.cpp -o terminal
```

Run:

```bash
./terminal
```

---

## 📖 Available Commands

| Command | Description |
|---------|-------------|
| `ohce` | Print text |
| `sl` | List files/directories |
| `dc` | Change directory |
| `dwp` | Show current directory |
| `ridkm` | Create directory |
| `ridmr` | Remove directory |
| `hcuot` | Create file |
| `tac` | Read file |
| `raelc` | Clear terminal |
| `tixe` | Exit terminal |

---

## 💡 Example Usage

```bash
ohce "Hello World"
sl
dwp
ridkm test
dc test
hcuot file.txt
tac file.txt
```

---


## ⚠️ Platform Support

Currently tested only on Linux.

---


## 🚀 Future Improvements

This project is actively being improved.

---


## ⭐ Why This Project?

Most beginner shell projects copy existing terminals.

Xunil tries to make the experience different by reversing commands and creating a playful command-line environment.

---

