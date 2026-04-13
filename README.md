# Mini Redis - LRU Cache (C++)

## Overview
This project is an in-memory key-value store implemented in C++ with an LRU (Least Recently Used) eviction policy.

It supports constant-time operations for insertion, lookup, deletion, and eviction by combining a hash map with a doubly linked list.

---

## Features
- O(1) average time complexity for:
  - SET
  - GET
  - DELETE
  - EXISTS
- LRU eviction when capacity is exceeded
- Command-line interface for interaction
- Manual memory management using pointers

---

## Data Structures Used

### 1. Hash Map (`unordered_map`)
- Maps keys to nodes
- Enables O(1) lookup

### 2. Doubly Linked List
- Maintains usage order
- Head = most recently used
- Tail = least recently used

---

## How LRU Works

- When a key is accessed (`GET`), it is moved to the front (most recent)
- When inserting (`SET`):
  - If the key exists → update + move to front
  - If new → insert at front
- If capacity is exceeded:
  - Remove the least recently used item (tail)

---

## Example

SET a 1
SET b 2
GET a → makes 'a' most recent
SET c 3 → evicts 'b'

GET b → NULL
GET a → 1
GET c → 3

---

## How to Run

### Compile

g++ src/main.cpp src/KeyValueStore.cpp -o mini-redis

### Run

./mini-redis.exe

---

## Project Structure

mini-redis/
│
├── src/
│ ├── main.cpp
│ ├── KeyValueStore.h
│ ├── KeyValueStore.cpp
│
├── .gitignore
└── README.md


---

## Key Concepts Demonstrated
- Data structures (hash maps, linked lists)
- Pointer manipulation
- Memory management (`new` / `delete`)
- Object-oriented design in C++
- Separation of concerns (interface vs implementation)

---

## Future Improvements
- TTL (time-to-live) expiration
- Multithreading support
- Persistent storage (file-based)
- Network interface (TCP server)
