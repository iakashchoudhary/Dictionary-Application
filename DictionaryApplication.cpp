#include <iostream>
#include <vector>
#include <limits>

// Declaration of the Dictionary class
class Dictionary {
private:
    // Constants for the hash table
    static const int tableSize = 5; // Size of the hash table
    static const std::string EMPTY;  // Placeholder for empty slots

    // HashNode represents each element in the hash table
    struct HashNode {
        std::string key;
        std::string value;
    };

    // Hash table implemented as a vector of HashNode
    std::vector<HashNode> table;

    // Hash function to convert a key into an index in the hash table
    int hashFunction(const std::string& key);

    // Probing function for linear probing
    int linearProbe(int index);

public:
    // Constructor initializes the hash table with empty slots
    Dictionary();

    // Function to check whether the dictionary is empty
    bool isEmpty() const;

    // Function to add a word to the dictionary
    void addWord(const std::string& key, const std::string& value);

    // Function to search for a word in the dictionary
    std::string searchWord(const std::string& key);

    // Function to delete a word from the dictionary
    void deleteWord(const std::string& key);

    // Function to display hash values in the dictionary
    void displayDictionary();
};

// Initialization of the EMPTY constant
const std::string Dictionary::EMPTY = "";

// Constructor definition
Dictionary::Dictionary() : table(tableSize, {EMPTY, EMPTY}) {}

// Hash function definition
int Dictionary::hashFunction(const std::string& key) {
    int hash = 0;
    for (char ch : key) {
        hash += static_cast<int>(ch);
    }
    return hash % tableSize;
}

// Probing function definition
int Dictionary::linearProbe(int index) {
    return (index + 1) % tableSize;
}

// Function to check whether the dictionary is empty
bool Dictionary::isEmpty() const {
    for (const auto& node : table) {
        if (node.key != EMPTY) {
            return false; // Hash table is not empty
        }
    }
    return true; // Hash table is empty
}

// Function to add a word to the dictionary
void Dictionary::addWord(const std::string& key, const std::string& value) {
    int index = hashFunction(key);
    while (table[index].key != EMPTY) {
        index = linearProbe(index);
        if (index == hashFunction(key)) {
            std::cout << "Dictionary is full. Cannot add more words.\n";
            return;
        }
    }
    table[index] = {key, value};
    std::cout << "Word added to the dictionary.\n";
}

// Function to search for a word in the dictionary
std::string Dictionary::searchWord(const std::string& key) {
    int index = hashFunction(key);
    while (table[index].key != EMPTY) {
        if (table[index].key == key) {
            return table[index].value;
        }
        index = linearProbe(index);
    }
    return "Word not found";
}

// Function to delete a word from the dictionary
void Dictionary::deleteWord(const std::string& key) {
    int index = hashFunction(key);
    while (table[index].key != EMPTY) {
        if (table[index].key == key) {
            table[index] = {EMPTY, EMPTY};
            std::cout << "Word deleted from the dictionary.\n";
            return;
        }
        index = linearProbe(index);
    }
    std::cout << "Word not found. Cannot delete.\n";
}

// Function to display hash values in the dictionary
void Dictionary::displayDictionary() {
    for (int i = 0; i < tableSize; ++i) {
        std::cout << "[" << i << "]";
        if (table[i].key != EMPTY) {
            std::cout << " -> {" << table[i].key << ": " << table[i].value << "}";
        }
        std::cout << std::endl;
    }
}

// Entry point of the program
int main() {
    // Create an instance of the Dictionary class
    Dictionary dictionary;

    // Variables for user input
    int choice;
    std::string word, meaning;

    // Display initial message
    std::cout << "\nDictionary Application\n";

    // Main loop for user interaction
    do {
        // Display menu
        std::cout << "\n1. Add Word 2. Search Word 3. Delete Word 4. Display Dictionary 5. Exit"
                  << "\nEnter your choice: ";

        // Get user choice
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer

        // Switch statement to handle user choices
        switch (choice) {
            case 1:
                // Add Word
                std::cout << "\nEnter word: ";
                std::getline(std::cin, word);
                std::cout << "Enter meaning: ";
                std::getline(std::cin, meaning);
                dictionary.addWord(word, meaning);
                break;

            case 2:
                // Search Word
                if (dictionary.isEmpty()) {
                    std::cout << "\nDictionary is empty. Add words first.\n";
                } else {
                    std::cout << "\nEnter word to search: ";
                    std::getline(std::cin, word);
                    std::cout << "Search Result: " << dictionary.searchWord(word) << std::endl;
                }
                break;

            case 3:
                // Delete Word
                if (dictionary.isEmpty()) {
                    std::cout << "\nDictionary is empty. Add words first.\n";
                } else {
                    std::cout << "\nEnter word to delete: ";
                    std::getline(std::cin, word);
                    dictionary.deleteWord(word);
                }
                break;

            case 4:
                // Display Dictionary
                if (dictionary.isEmpty()) {
                    std::cout << "\nDictionary is empty. Add words first.\n";
                } else {
                    std::cout << "\nDictionary Table:\n";
                    dictionary.displayDictionary();
                }
                break;

            case 5:
                // Exit
                std::cout << "\nExiting program.\n";
                break;

            default:
                std::cout << "\nInvalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
