# clsDblLinkedList - Doubly Linked List Implementation in C++

![GitHub License](https://img.shields.io/badge/license-MIT-blue.svg)

Welcome to clsDblLinkedList, a comprehensive implementation of a doubly linked list in C++. This project provides a versatile and well-documented doubly linked list data structure that can be easily integrated into your C++ applications.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Examples](#examples)
    - [Example1](#example1)
    - [Example2](#example2)
    - [Example3](#example3)
    - [Example4](#example4)
- [Code Review](#Code-Review)
- [Contributing](#contributing)
- [Author](#Author)
- [Very Important Note](#Note)
- [License](#license)

## Introduction

`clsDblLinkedList` is a C++ implementation of a doubly linked list, a fundamental data structure that allows for efficient insertion, deletion, and traversal of elements in both directions. This project offers a clean and extensible API, making it suitable for various applications.

## Features

- **Double Linking**: Each node in the list contains references to both the previous and next nodes, enabling easy traversal in both directions.
- **Efficient Operations**: Insertions and deletions at the beginning, end, or specific positions in the list are optimized for efficiency.
- **Flexible API**: The API is designed to be user-friendly, making it easy to manipulate the list and access its elements.
- **Generic Support**: The linked list is implemented using templates, allowing you to store elements of any data type.
- **Clear Documentation**: The code is thoroughly documented, providing explanations for each method and its usage.

## Installation

1. Clone the repository:

```sh
   git clone https://github.com/mattar740/clsDblLinkedList.git
   
```
2. Include the 'clsDblLinkedList.h' file in your project.


## Usage

1. Create a new instance of clsDblLinkedList:

```cpp
clsDblLinkedList<int> myList;
```

2. Add elements to the list:

```cpp
myList.InsertAtBeginning(42);
myList.InsertAtEnd(15);
```

3. Perform various operations like inserting, deleting, and iterating:
```cpp
myList.InsertAfter(myNode, 99);
myList.DeleteNodeWithValue(15);
myList.PrintList();
```

## Examples
Here are some examples of using the STR class:

# Example1:
```cpp
#include "clsDblLinkedList.h"
#include <iostream>

int main() {
    clsDblLinkedList<int> myList;

    myList.InsertAtBeginning(42);
    myList.InsertAtEnd(15);
    myList.InsertAfter(myList.GetNode(0), 99);
    myList.PrintList();

    return 0;

}
```
# Example2:
```cpp
#include "clsDblLinkedList.h"
#include <iostream>

int main() {

    clsDblLinkedList<std::string> myStrList;

    myStrList.InsertAtBeginning("Hello");
    myStrList.InsertAtEnd("World");
    myStrList.InsertAfter(myStrList.GetNode(0), "from");
    myStrList.InsertAfter(myStrList.GetNode(2), "clsDblLinkedList!");
    myStrList.PrintList();

    return 0;
}
```
# Example3:
```cpp
#include "clsDblLinkedList.h"
#include <iostream>

int main() {
    clsDblLinkedList<double> myList;

    myList.InsertAtBeginning(3.14);
    myList.InsertAtEnd(2.718);
    myList.InsertAfter(myList.GetNode(0), 1.618);
    myList.InsertAfter(myList.GetNode(2), 0.577);
    
    std::cout << "Size of the list: " << myList.Size() << std::endl;

    for (int i = 0; i < myList.Size(); ++i) {
        std::cout << "Item at index " << i << ": " << myList.GetItem(i) << std::endl;
    }

    return 0;
}
```

# Example4:
```cpp
#include "clsDblLinkedList.h"
#include <iostream>
#include <string>

// Define a custom Student class
class Student {
public:
    std::string name;
    int age;

    Student(const std::string& _name, int _age) : name(_name), age(_age) {}
};

int main() {
    clsDblLinkedList<Student> studentList;

    // Create instances of the Student class
    Student student1("Alice", 20);
    Student student2("Bob", 22);
    Student student3("Charlie", 21);

    // Insert students into the list
    studentList.InsertAtEnd(student1);
    studentList.InsertAtEnd(student2);
    studentList.InsertAtBeginning(student3);

    // Print student information
    std::cout << "Students in the list:" << std::endl;
    for (int i = 0; i < studentList.Size(); ++i) {
        Student student = studentList.GetItem(i);
        std::cout << "Name: " << student.name << ", Age: " << student.age << std::endl;
    }

    return 0;
}
```

## Code Review

The `clsDblLinkedList` project demonstrates good coding practices and follows a well-structured design that promotes readability and maintainability. Here's a brief code review:

### Positive Aspects

- **Modular Design**: The code is organized into a class, `clsDblLinkedList`, which encapsulates the functionality of a doubly linked list. This modular design promotes separation of concerns and code reusability.

- **Clear Method Names**: The method names are intuitive and reflect their functionality. This makes it easier for users to understand how to interact with the clsDblLinkedList class and encourages good coding practices.

## Contributing
- Contributions are welcome and encouraged! To contribute to clsDblLinkedList, follow these steps:

1. Fork the repository.
2. Create a new branch.
3. Make your changes and commit them.
4. Push your changes to your fork.
5. Create a pull request detailing your changes.
6. Please ensure your code follows the existing coding style and includes appropriate tests.

## Author

- Mahmoud Mohamed
- Email: mahmoud.abdalaziz@outlook.com
- LinkedIn: [Mahmoud Mohamed Abdalaziz](https://www.linkedin.com/in/mahmoud-mohamed-abd/)

## Note

Hi, I'm Mahmoud Mohamed The purpose behind this project, `clsDblLinkedList`, this serves as a practical exercise for training and demonstrating competence in dealing with pointers, data structures, and C++ programming concepts. It showcases the implementation of a doubly linked list, which is a fundamental data structure used in various computer science applications.

The project is designed to provide a clear and well-documented codebase that serves as a reference for those looking to understand how to work with pointers and linked data structures.

Whether you're a student, a developer looking to brush up on C++ skills, or someone aiming to showcase your coding expertise on platforms like LinkedIn, this project can be a valuable addition to your portfolio. Feel free to explore, contribute, and use this project as a learning resource.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.