#include <iostream>
#include <sstream>
#include <string>
#include "KeyValueStore.h"

int main() {
    KeyValueStore kv(2); // capacity = 2 for testing
    std::string line;

    std::cout << "Mini Redis LRU Cache\n";
    std::cout << "Commands:\n";
    std::cout << "  SET key value\n";
    std::cout << "  GET key\n";
    std::cout << "  DEL key\n";
    std::cout << "  EXISTS key\n";
    std::cout << "  EXIT\n";

    while (true) {
        std::cout << "\n> ";
        std::getline(std::cin, line);

        if (line.empty()) {
            continue;
        }

        std::stringstream ss(line);
        std::string command;
        ss >> command;

        if (command == "EXIT") {
            std::cout << "Exiting program.\n";
            break;
        }
        else if (command == "SET") {
            std::string key, value;
            ss >> key >> value;

            if (key.empty() || value.empty()) {
                std::cout << "Usage: SET key value\n";
                continue;
            }

            kv.set(key, value);
            std::cout << "OK\n";
        }
        else if (command == "GET") {
            std::string key;
            ss >> key;

            if (key.empty()) {
                std::cout << "Usage: GET key\n";
                continue;
            }

            std::cout << kv.get(key) << "\n";
        }
        else if (command == "DEL") {
            std::string key;
            ss >> key;

            if (key.empty()) {
                std::cout << "Usage: DEL key\n";
                continue;
            }

            std::cout << (kv.del(key) ? "OK" : "Key not found") << "\n";
        }
        else if (command == "EXISTS") {
            std::string key;
            ss >> key;

            if (key.empty()) {
                std::cout << "Usage: EXISTS key\n";
                continue;
            }

            std::cout << (kv.exists(key) ? "true" : "false") << "\n";
        }
        else {
            std::cout << "Unknown command\n";
        }
    }

    return 0;
}