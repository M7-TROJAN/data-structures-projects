# UndoAbleString - String with Undo and Redo Functionality

![GitHub License](https://img.shields.io/badge/license-MIT-blue.svg)

Welcome to UndoAbleString, a custom class for handling strings with undo and redo functionality. This project provides a versatile and well-documented implementation of a string that allows you to easily manage changes, undo them, and redo them as needed.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Usage](#usage)
- [Examples](#examples)
    - [Example1](#example1)
    - [Example2](#example2)
- [Author](#author)
- [Note](#note)
- [License](#license)

## Introduction

`UndoAbleString` is a custom class that extends the functionality of a standard string by incorporating undo and redo capabilities. With this class, you can easily track changes to the string, revert to previous versions using the `Undo` method, and redo changes that were undone using the `Redo` method.

## Features

- **Undo and Redo**: The class allows you to undo changes made to the string and redo them if needed, providing a convenient way to manage edits.

- **History Management**: The class uses internal stacks to store the history of changes, making it efficient to switch between different versions of the string.

- **Simple Interface**: The API is designed to be user-friendly, requiring minimal code to utilize the undo and redo functionality.

## Usage

1. Create an instance of `UndoAbleString`:

```cpp
UndoAbleString myString;
```

2. Set the initial value of the string:

```cpp
myString.Value = "Hello, World!";
```

3. Make changes to the string and utilize undo and redo:

```cpp
myString.Value = "Hello, My Friend!";
myString.Undo(); // Reverts to the previous value ("Hello, World!")
myString.Redo(); // Restores the value ("Hello, My Friend!")

```

## Examples
- Here are some examples of using the UndoAbleString class:

# Example1:
```cpp
#include "UndoAbleString.h"
#include <iostream>

int main() {
    UndoAbleString myString;

    myString.Value = "Hello, World!";
    std::cout << "Initial value: " << myString.Value << std::endl;

    myString.Value = "Hello, GitHub!";
    std::cout << "Changed value: " << myString.Value << std::endl;

    myString.Undo();
    std::cout << "After Undo: " << myString.Value << std::endl;

    myString.Redo();
    std::cout << "After Redo: " << myString.Value << std::endl;

    return 0;
}
```

# Example2:
```cpp
#include "UndoAbleString.h"
#include <iostream>

int main() {
    UndoAbleString myString;

    myString.Value = "C++";
    std::cout << "Initial value: " << myString.Value << std::endl;

    myString.Value = "C#";
    std::cout << "Changed value: " << myString.Value << std::endl;

    myString.Undo();
    std::cout << "After Undo: " << myString.Value << std::endl;

    return 0;
}
```
## Author

- Mahmoud Mohamed
- Email: mahmoud.abdalaziz@outlook.com
- LinkedIn: [Mahmoud Mohamed Abdalaziz](https://www.linkedin.com/in/mahmoud-mohamed-abd/)

# Note 
Hello, I'm Mahmoud Mohamed. the motivation behind creating the UndoAbleString class is to provide a practical illustration of programming concepts and data structure implementation. This project aims to demonstrate proficiency in C++ programming, object-oriented principles, and managing state changes using stacks.

The project is designed to offer clear and well-documented code that serves as a reference for understanding how to implement undo and redo functionality in custom classes.

- Best regards,
- Mahmoud Mohamed

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.