# clsDynamicArray - Dynamic Array Implementation in C++

![GitHub License](https://img.shields.io/badge/license-MIT-blue.svg)

Welcome to clsDynamicArray, a versatile and well-documented dynamic array implementation in C++. This project provides a flexible array data structure that can be easily integrated into your C++ applications.

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
- [Contributing](#contributing)
- [Author](#author)
- [Important Note](#Note)
- [License](#license)

## Introduction

`clsDynamicArray` is a C++ implementation of a dynamic array, a fundamental data structure that provides a resizable array-like container. This project offers a clean and extensible API, making it suitable for various applications where dynamic memory allocation and efficient element manipulation are required.

## Features

- **Dynamic Resizing**: The dynamic array automatically resizes itself as elements are added or removed, ensuring optimal memory usage.
- **Element Manipulation**: Easily add, delete, and modify elements within the array using intuitive methods.
- **Index-Based Access**: Access elements using standard array index notation.
- **Reversal**: Reverse the order of elements in the dynamic array.
- **Exception Handling**: Provides exception handling for out-of-range access and errors.
- **Clear Documentation**: The code is thoroughly documented, providing explanations for each method and its usage.

## Installation

1. Clone the repository:

```sh
   git clone https://github.com/mattar740/clsDynamicArray.git
```
2. Include the 'clsDynamicArray.h' file in your project.

## Usage

1. Create a new instance of clsDynamicArray:
```cpp
clsDynamicArray<int> myArray;
```
2. Add elements to the array:
```cpp
myArray.insertAtEnd(42);
myArray.insertAtBeginning(15);
```
3. Perform various operations like accessing, modifying, and deleting elements:
```cpp
int value = myArray[0];
myArray.setItem(1, 99);
myArray.deleteItem(42);
myArray.reverse();
```

## Examples

# Example1:
```cpp
#include "clsDynamicArray.h"
#include <iostream>

int main() {
    clsDynamicArray<int> myArray;

    myArray.insertAtEnd(42);
    myArray.insertAtBeginning(15);
    myArray.insertAt(1, 99);
    myArray.print();

    return 0;
}

```
# Example2:
```cpp
#include "clsDynamicArray.h"
#include <iostream>

int main() {
    clsDynamicArray<std::string> strArray;

    strArray.insertAtEnd("Hello");
    strArray.insertAtEnd("World");
    strArray.insertAtBeginning("Welcome");
    strArray.print();

    return 0;
}
```
# Example3:
```cpp
#include "clsDynamicArray.h"
#include <iostream>

int main() {
    clsDynamicArray<double> dblArray;

    dblArray.insertAtEnd(3.14);
    dblArray.insertAtEnd(2.718);
    dblArray.insertAtBeginning(1.618);
    dblArray.reverse();
    dblArray.print();

    return 0;
}
```

# Example4:
```cpp
#include "clsDynamicArray.h"
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
    clsDynamicArray<Student> studentArray;

    Student student1("Alice", 20);
    Student student2("Bob", 22);
    Student student3("Charlie", 21);

    studentArray.insertAtEnd(student1);
    studentArray.insertAtEnd(student2);
    studentArray.insertAtBeginning(student3);

    for (size_t i = 0; i < studentArray.size(); ++i) {
        std::cout << "Name: " << studentArray[i].name << ", Age: " << studentArray[i].age << std::endl;
    }

    return 0;
}
```

## Contributing
- Contributions are welcome and encouraged! To contribute to clsDynamicArray, follow these steps:

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
Greetings, I'm Mahmoud Mohamed, The purpose behind conceiving the clsDynamicArray project is driven by a quest for enhancing my prowess across diverse programming domains. By embarking on this project, I endeavor to exhibit a robust grasp of pointers, presenting an embodiment of practical expertise in the realm of C++ programming, data structures, algorithmic principles, and the nuances of object-oriented programming. This initiative serves as both a training ground to refine my skills and an illustrative platform to showcase my proficiency.

This project is meticulously structured to provide a coherent and meticulously documented codebase. It stands as a valuable resource for those aspiring to comprehend the intricacies of working with pointers and dynamic array data structures.

- Warm regards,
- Mahmoud Mohamed


## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.