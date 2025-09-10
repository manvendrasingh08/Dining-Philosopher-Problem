# Dining Philosophers Problem (C Implementation)

This project is a **C implementation of the classic Dining Philosophers problem** using `pthread` mutexes for synchronization.  
It demonstrates how to avoid **deadlock** using `pthread_mutex_trylock` and how to handle graceful termination with `SIGINT`.

---

## 📖 Problem Description
The Dining Philosophers problem is a classic synchronization challenge in computer science.  
Five philosophers sit around a table, alternating between **thinking** and **eating**.  
They need **two forks** (left and right) to eat, but only one fork is available between each pair of philosophers.

The main challenges are:
- Avoiding **deadlock** (when everyone holds one fork and waits forever).
- Avoiding **starvation** (when some philosophers never get a chance to eat).

---

## 🛠 Features
- Uses **POSIX threads (`pthread`)** for philosophers.
- **Mutexes** represent forks.
- Prevents **deadlock** by using `pthread_mutex_trylock`.
- Handles **CTRL+C** (`SIGINT`) with a signal handler that gracefully exits.
- Continuous simulation: philosophers **think → pick forks → eat → release forks**.

---

## 📂 Project Structure
DiningPhilosophers/
├── main.c # Main program with pthread logic
└── README.md # Documentation
---

## 🚀 How to Compile & Run
Make sure you have GCC and pthreads installed.  

### Compile:
gcc -o philosophers main.c -lpthread

### Run:
./philosophers


### Stop:
Press CTRL+C to stop. The signal handler will print:
All philosophers will leave the table


