# 🎓 Student Database Management System

A console-based **Student Database Management System** written in **C++**, featuring secure login, file-based persistent storage, and full CRUD operations on student records.

---

## 📋 Features

- 🔐 **Login System** — Secure username/password authentication via file
- 🔑 **Change Password** — Update credentials with old password verification
- ➕ **Add Student** — Store roll number, name, and marks
- 📄 **View Students** — Display all student records
- 🔍 **Search Student** — Find a student by roll number
- ✏️ **Update Student** — Modify name and marks for a given roll
- 🗑️ **Delete Student** — Remove a student record by roll number
- 🚪 **Logout / Exit** — Session management with re-login support

---

## 🗂️ Project Structure

```
StudentDatabaseManagementSystem/
├── main.cpp        # Main source file with all functions
├── login.txt       # Stores username and password (auto-managed)
├── data.txt        # Stores student records (auto-managed)
└── README.md       # Project documentation
```

---

## 🚀 Getting Started

### Prerequisites

- A C++ compiler (e.g., `g++` from GCC, MinGW on Windows, or Clang)

### Compilation

```bash
g++ main.cpp -o student_mgmt
```

### Run

```bash
./student_mgmt        # Linux / macOS
student_mgmt.exe      # Windows
```

---

## 🔐 Login Setup

Before running, create a `login.txt` file in the same directory with your credentials:

```
admin password123
```

> ⚠️ The username and password must be on a single line separated by a space. Passwords with spaces are not currently supported.

---

## 🖥️ Menu Options

```
===== STUDENT MANAGEMENT SYSTEM =====
1. Add Student
2. View Students
3. Delete Student
4. Search Student
5. Update Student
6. Change Password
7. Logout
8. Exit
```

---

## 💾 Data Storage

- Student records are stored in **`data.txt`** (appended on each add).
- Login credentials are stored in **`login.txt`**.
- Deletion and updates use a **temp file** strategy to safely rewrite records.

---

## ⚠️ Known Limitations

- Student **names cannot contain spaces** (uses `>>` operator for reading).
- Password file uses **plain text** storage — not suitable for production use.
- No input validation for marks or roll number type checking.

---

## 🛠️ Built With

- **C++** (Standard: C++11 or later recommended)
- **File I/O** (`fstream`) for persistent storage
- **STL** (`bits/stdc++.h`)

---

## 📌 Future Improvements

- [ ] Support for multi-word student names
- [ ] Hashed/encrypted password storage
- [ ] Sort students by marks or roll number
- [ ] Export records to CSV
- [ ] GUI version using Qt or a web interface

---

## 👨‍💻 Author

**Your Name**
- GitHub: [@Shakti](https://github.com/shaktikumarsuraj)

---
