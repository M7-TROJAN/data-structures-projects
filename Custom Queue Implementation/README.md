# clsMyQueue - Queue Implementation Using Doubly Linked List

![GitHub License](https://img.shields.io/badge/license-MIT-blue.svg)

Welcome to clsMyQueue, a C++ implementation of a queue data structure using a doubly linked list. This project provides an easy-to-use and efficient queue interface that can be seamlessly integrated into your C++ applications.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Example](#example)
- [Author](#author)
- [Note](#Note)
- [License](#license)

## Introduction

`clsMyQueue` is a C++ implementation of a queue, a fundamental data structure that follows the First-In-First-Out (FIFO) principle. This project is built on top of the `clsDblLinkedList` doubly linked list implementation, making it possible to leverage the benefits of a doubly linked list for efficient queue operations.

## Features

- **Efficient Enqueue and Dequeue**: Enqueue (push) and dequeue (pop) operations are optimized for efficient insertion and removal at both ends of the queue.
- **Front and Back Access**: Retrieve the front and back elements of the queue in constant time.
- **Size and Empty Check**: Get the current size of the queue and check if it's empty.
- **Printing**: Print the contents of the queue for debugging and analysis.
- **Reversal**: Reverse the order of elements in the queue.
- **Item Access**: Access individual elements in the queue by index.
- **Update and Insert**: Update elements at specific indices and insert elements after a given index.
- **Clearing**: Clear the entire queue.

## Installation

1. Clone the repository:

```sh
   git clone https://github.com/mattar740/clsMyQueue.git
```
2. Include the 'clsMyQueue.h' file in your project.

## Usage
1. Create a new instance of clsMyQueue:
```cpp
clsMyQueue<int> myQueue;
```
2. Enqueue and dequeue elements:
```cpp
myQueue.push(42);
myQueue.push(15);
myQueue.pop();
```
3. Perform various queue operations:
```cpp
int frontElement = myQueue.front();
int backElement = myQueue.back();
int queueSize = myQueue.size();
bool emptyStatus = myQueue.isEmpty();
myQueue.Print();
myQueue.Reverse();
myQueue.InsertAtFront(99);
```
## Example

```cpp
#include "clsMyQueue.h"
#include <iostream>

int main() {
    clsMyQueue<int> myQueue;

    myQueue.push(42);
    myQueue.push(15);
    myQueue.push(99);
    myQueue.pop();

    std::cout << "Front element: " << myQueue.front() << std::endl;
    std::cout << "Back element: " << myQueue.back() << std::endl;
    std::cout << "Queue size: " << myQueue.size() << std::endl;

    myQueue.Print();

    return 0;
}
```
## Author

- Mahmoud Mohamed
- Email: mahmoud.abdalaziz@outlook.com
- LinkedIn: [Mahmoud Mohamed Abdalaziz](https://www.linkedin.com/in/mahmoud-mohamed-abd/)

## Note
Hello, I'm Mahmoud Mohamed, 
as a CS student. The motivation behind creating the clsMyQueue project is to facilitate training and showcase my proficiency in various programming domains. Building upon the foundation of the clsDblLinkedList project, this endeavor serves as a practical exercise aimed at refining my skills and vividly demonstrating competence in C++ programming, data structures, algorithmic concepts, and object-oriented programming principles. Moreover, it allows me to explore code reuse while providing a tangible application of object-oriented concepts.
Best regards,
Mahmoud Mohamed


## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.