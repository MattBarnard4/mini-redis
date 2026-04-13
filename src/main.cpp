#include <iostream>
#include "KeyValueStore.h"

int main() {
    KeyValueStore kv(2); // capacity = 2

    std::cout << "Setting a=1\n";
    kv.set("a", "1");

    std::cout << "Setting b=2\n";
    kv.set("b", "2");

    std::cout << "Getting a: " << kv.get("a") << "\n"; // makes 'a' most recent

    std::cout << "Setting c=3 (should evict b)\n";
    kv.set("c", "3");

    std::cout << "Getting b: " << kv.get("b") << "\n"; // should be NULL
    std::cout << "Getting a: " << kv.get("a") << "\n"; // should exist
    std::cout << "Getting c: " << kv.get("c") << "\n"; // should exist
}
    