#include "KeyValueStore.h"

KeyValueStore::KeyValueStore(int cap) {
    capacity = cap;
    head = nullptr;
    tail = nullptr;
}

KeyValueStore::~KeyValueStore() {
    Node* current = head;
    while (current) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}


void KeyValueStore::removeNode(Node* node) {
    if (!node) return;

    if (node->prev) {
        node->prev->next = node->next;
    } else {
        head = node->next; // node was head
    }

    if (node->next) {
        node->next->prev = node->prev;
    } else {
        tail = node->prev; // node was tail
    }
}

void KeyValueStore::addToFront(Node* node) {
    node->next = head;
    node->prev = nullptr;

    if (head) {
        head->prev = node;
    }

    head = node;

    if (!tail) {
        tail = node;
    }
}

void KeyValueStore::moveToFront(Node* node) {
    removeNode(node);
    addToFront(node);
}

void KeyValueStore::set(const std::string& key, const std::string& value) {
    // Case 1: key already exists
    if (cache.find(key) != cache.end()) {
        Node* node = cache[key];
        node->value = value;
        moveToFront(node);
        return;
    }

    // Case 2: new key
    Node* newNode = new Node(key, value);
    cache[key] = newNode;
    addToFront(newNode);

    // If over capacity, remove LRU
    if (cache.size() > capacity) {
        evictLRU();
    }
}

void KeyValueStore::evictLRU() {
    if (!tail) return;

    Node* lru = tail;

    // remove from map
    cache.erase(lru->key);

    // remove from list
    removeNode(lru);

    delete lru;
}

std::string KeyValueStore::get(const std::string& key) {
    if (cache.find(key) == cache.end()) {
        return "NULL";
    }

    Node* node = cache[key];

    // move to front (most recently used)
    moveToFront(node);

    return node->value;
}