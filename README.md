# Inverted Search

## Project Description

Inverted Search is a C-based application that creates an inverted index for multiple text files using Hash Tables and Linked Lists.

It indexes words from the input files and stores the corresponding file names and word occurrence counts. This allows users to search for a word and quickly identify the files in which it appears.

The project demonstrates the practical implementation of data structures, file handling and dynamic memory allocation in C.

## Features

- Create an inverted index from multiple text files.
- Store words along with their corresponding file names.
- Maintain the occurrence count of each word in different files.
- Search for a specific word in the indexed database.
- Display the indexed database.
- Update the database with additional files.
- Save the database for future use.

## Technologies Used

- Programming Language: C
- Data Structures: Hash Tables and Singly Linked Lists
- Concepts: Pointers, Structures, Dynamic Memory Allocation, File Handling and String Manipulation.

## Working Principle

### 1. Database Creation

1. Accept multiple input text files.
2. Read the contents of each file.
3. Extract individual words.
4. Calculate the hash index for each word.
5. Store words in the hash table using linked lists.
6. Maintain file names and word occurrence counts.

### 2. Search Operation

1. Accept a word from the user.
2. Calculate its hash index.
3. Traverse the corresponding linked list.
4. Search for the requested word.
5. Display the file names and occurrence counts where the word is found.

### 3. Database Update

Allows users to add additional input files and update the existing inverted index.

### 4. Database Display

Displays the indexed words, their associated files and occurrence counts.

### 5. Database Save

Saves the inverted index into a file so that the database information can be reused later.

## Data Structures Used

### Hash Table

A hash table is used to organize words based on their calculated hash indices, reducing the search space.

### Singly Linked List

Linked lists are used to handle collisions and store word information along with associated file details and occurrence counts.

## Concepts Implemented

- Hashing techniques.
- Collision handling using linked lists.
- Dynamic memory allocation.
- Structures and pointers.
- File handling operations.
- String manipulation.
- Modular programming.

## How to Compile and Run

### 1. Clone the Repository

```bash
git clone https://github.com/PasamAkhila/Inverted-Search.git
```

### 2. Navigate to the Project Directory

```bash
cd Inverted-Search/inverted_search
```

### 3. Compile the Source Files

```bash
gcc *.c -o inverted_search
```

### 4. Run the Application

```bash
./inverted_search
```

Follow the menu displayed by the application to perform the available operations.

## Learning Outcomes

- Gained practical knowledge of Hash Tables and Linked Lists.
- Understood hashing and collision handling techniques.
- Improved file handling and data organization skills.
- Learned dynamic memory allocation and pointer manipulation.
- Developed efficient searching and indexing logic.
- Improved problem-solving and debugging skills.

## Author

**Pasam Akhila**

B.Tech – Electronics and Communication Engineering
