🔐 Login and Registration System — C++
A console-based Login and Registration System built in C++ as part of my internship at CodeAlpha.

📌 About the Project
This program allows users to register with a username and password, and login securely. Credentials are stored in a file, making the data persistent across sessions.

✨ Features
📝 Register new users with username and password
🔍 Validates input and checks for duplicate usernames

💾 Stores credentials securely in a file
🔑 Login function that reads and verifies user identity
✅ Displays appropriate success or error messages
🔄 Simple menu to switch between Register and Login

🛠️ Tech Stack
Language: C++
Compiler: G++ / MinGW
File Handling: fstream (txt/dat file)

📸 Sample Output
=============================
   LOGIN & REGISTRATION MENU
=============================
1. Register
2. Login
3. Exit
Enter choice: 1

--- REGISTER ---
Enter username: john_doe
Enter password: ********

✅ Registration successful!

=============================
Enter choice: 2

--- LOGIN ---
Enter username: john_doe
Enter password: ********

✅ Login successful! Welcome, john_doe!

=============================
Enter choice: 2

--- LOGIN ---
Enter username: john_doe
Enter password: wrongpass

❌ Error: Incorrect password. Please try again.
IDE: VS Code / Code::Blocks / Dev C++


