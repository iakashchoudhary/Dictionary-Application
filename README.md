# Dictionary Application
A C++ application that implements a dictionary using a hash table with linear probing. Provides functionality to add, search, delete words, and display the dictionary contents.

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Implementation Details](#implementation-details)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [Usage](#usage)
  - [Example Interaction](#example-interaction)
- [Contributing](#contributing)
- [License](#license)
- [Contact](#contact)

## Overview

This C++ console application provides a simple dictionary management system using a hash table with linear probing for collision resolution. Users can perform operations such as adding, searching, deleting, and displaying words and their meanings.

## Features

- **Add Word**: Insert a new word and its meaning into the dictionary.
- **Search Word**: Look up the meaning of a word in the dictionary.
- **Delete Word**: Remove a word from the dictionary.
- **Display Dictionary**: Show all words and their meanings currently stored in the dictionary.

## Implementation Details

- **Hash Table Size**: Fixed at 5.
- **Collision Resolution Method**: Linear probing.

## Getting Started

### Prerequisites

- A C++ compiler (e.g., g++).
- Basic understanding of C++ and hash tables.

### Installation

1. **Clone the Repository**

   ```bash
   git clone https://github.com/yourusername/your-repo.git

2. **Navigate to the Project Directory**

   ```bash
   cd your-repo

3. **Compile the Code**

   ```bash
   g++ -o DictionaryApplication DictionaryApplication.cpp

4. **Run the Application**

   ```bash
   ./DictionaryApplication

## Usage

Upon running the application, you will be presented with a menu:

1. **Add Word:** Enter a word and its meaning to add to the dictionary.

2. **Search Word:** Enter a word to find its meaning.

3. **Delete Word:** Enter a word to remove it from the dictionary.

4. **Display Dictionary:** View all current entries in the dictionary.

5. **Exit:** Close the application.

### Example Interaction

Dictionary Application

1. Add Word
2. Search Word
3. Delete Word
4. Display Dictionary
5. Exit
Enter your choice: 1

Enter word: Hello
Enter meaning: A greeting or expression of goodwill.
Word added to the dictionary.

Enter your choice: 2

Enter word to search: Hello
Search Result: A greeting or expression of goodwill.

## Contributing

Contributions are welcome! To contribute:

1. **Fork the Repository**

   Click on the "Fork" button at the top-right corner of the repository page on GitHub.

2. **Create a New Branch**

   ```bash
   git checkout -b feature-branch

3. **Make Your Changes**

   Edit the code or documentation as needed.

4. **Commit Your Changes**

   ```bash
   git commit -am 'Add new feature'

5. **Push to the Branch**

   ```bash
   git push origin feature-branch

6. **Create a Pull Request**

   Go to the repository on GitHub and create a new Pull Request from your branch.

Please ensure that your code follows the project's coding standards and includes appropriate tests.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Contact

For any questions or suggestions, please open an issue on GitHub or submit a pull request.
