#ifndef KEYVALUESTORE_H
#define KEYVALUESTORE_H

#include <string>
#include <unordered_map>

struct Node {
    std::string key;
    std::string value;
    Node* prev;
    Node* next;

    Node(const std::string& k, const std::string& v)
        : key(k), value(v), prev(nullptr), next(nullptr) {}
};

class KeyValueStore {
public:
    KeyValueStore(int cap);
    ~KeyValueStore();

    void set(const std::string& key, const std::string& value);
    std::string get(const std::string& key);
    bool del(const std::string& key);
    bool exists(const std::string& key);

private:
    int capacity;
    std::unordered_map<std::string, Node*> cache;
    Node* head;
    Node* tail;

    void addToFront(Node* node);
    void removeNode(Node* node);
    void moveToFront(Node* node);
    void evictLRU();
};

#endif