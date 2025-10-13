# Hotel Management (Text-Based)

A simple, text-based Hotel Management application written in modern C++ (C++17). It runs in the terminal and persists data to local files so that rooms and customers are saved across runs.

## Features

- **Rooms**
  - Add new rooms (number, type, price, availability)
  - Book a room
  - Free a room
  - Check out a customer from a room
  - View all rooms
- **Customers**
  - Add new customers (ID, name, room number, phone)
  - View all customers
- **Reports**
  - Print **Rooms** report
  - Print **Customers** report
- **Persistence**
  - Saves data in simple binary files on exit:
    - `rooms.txt` — list of rooms
    - `customers.txt` — list of customers
  - Files are read on startup (if present). If missing, the program starts with empty data and prints a warning.

> Note: File format is binary and not intended for manual editing.

---

## Project Structure

```
p01/
├─ main.cpp
├─ Rooms.h
├─ Rooms.cpp
├─ Customers.h
├─ Customers.cpp
├─ FileManagment.h
├─ FileManagment.cpp
├─ rooms.txt            # binary data file (created on exit if you added rooms)
├─ customers.txt        # binary data file (created on exit if you added customers)
└─ a.out                # (optional) a prebuilt binary on some systems
```

---

## Build Requirements

- **C++17** compatible compiler  
  - Linux/macOS: `g++` (>= 9 recommended)
  - Windows:
    - **MinGW-w64** `g++`, or
    - **MSYS2** `g++`
- No external dependencies

---

## How to Build

From the project folder (where `main.cpp` lives), run:

```bash
g++ -std=c++17 -O2 -Wall -Wextra -pedantic   main.cpp Rooms.cpp Customers.cpp FileManagment.cpp   -o hotel
```

> If you compile from inside `p01/`, the output will be `./hotel` (or `hotel.exe` on Windows).

---

## How to Run

After building, run the executable from a terminal:

```bash
./hotel         # Linux/macOS/WSL/MSYS2
hotel.exe       # Windows (PowerShell or CMD)
```

On first run, if `rooms.txt` and `customers.txt` are missing, you’ll see a message about failing to open the files—this is expected. Add data through the menus and it will save on exit.

---

## Notes & Tips

- The program uses `std::vector` and simple binary serialization to persist data.
- The `Rooms` and `Customers` lists are kept sorted when new entries are added.
- Ensure **room numbers** used for customers actually exist in the Rooms list.
- To back up your data, copy `rooms.txt` and `customers.txt` while the program is closed.

---

## License

This project is for educational purposes. If you intend to distribute or use it publicly, add a license file (e.g., MIT, Apache-2.0) and update this section.

---

## Authors

- Alex, Ellie, Hunter  
- CISS 465 