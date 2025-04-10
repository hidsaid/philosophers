## 🧵 Threads – Core Concepts Summary

## ✅ What I've Learned So Far

### Threads (`pthread`)
- Threads allow multiple tasks to run **concurrently** within the same process.
- Each thread has:
  - Its own **stack**
  - Shared access to **global memory**
- Threads are created using `pthread_create`.
- Threads can be managed using:
  - `pthread_join` — waits for a thread to finish.
  - `pthread_detach` — lets a thread clean up its own resources when it ends.

---

## 🔄 Thread Lifecycle

| **State**       | **Description**                                              |
|-----------------|--------------------------------------------------------------|
| **New**         | Thread is created with `pthread_create`.                     |
| **Ready**       | Waiting to be scheduled by the OS.                           |
| **Running**     | Actively executing the thread function.                      |
| **Blocked**     | Waiting (for mutex, sleep, I/O, etc.).                       |
| **Terminated**  | Finished execution. Needs to be cleaned up (`join`/`detach`).|

---

## 🧠 How Threads Run “In Parallel”

### ⏱️ Time-Slicing (Single Core)
- On a single-core CPU, threads **do not** truly run at the same time.
- The OS **rapidly switches** between threads (in microseconds or milliseconds).
- This creates the **illusion** of parallelism → called **concurrency**.

### 💻 Multi-Core Execution (True Parallelism)
- On a multi-core system, threads can run **at the same time**, each on a different core.
- This is true **parallelism**, not just time-sharing.

---

## 🧨 Race Conditions (Coming Soon)
- Happen when multiple threads **access shared data without synchronization**.
- Can lead to **unpredictable and buggy behavior**.
- Solved using **mutexes** (mutual exclusion mechanisms).
