# Queue Line Management

![Queue Line Management](queue.jpg)

## Overview

Queue Line Management is a C++ project that provides a simple implementation of a queue-based system for managing customer queues in various scenarios. The project includes a class named `clsQueueLine` that allows you to simulate issuing tickets, serving customers, and managing waiting clients in a queue.

## Features

- Issue new tickets with a prefix and average serving time.
- Serve customers in a first-come-first-served manner.
- Retrieve information about the queue, waiting clients, and served clients.
- Print the current state of the queue and ticket information.

## Files

- [clsQueueLine.h](clsQueueLine.h): The header file containing the `clsQueueLine` class implementation.
- [test.cpp](test.cpp): A test program demonstrating the usage of the `clsQueueLine` class.

## Usage

1. Include the `clsQueueLine.h` header file in your C++ project.
2. Create instances of the `clsQueueLine` class to manage different queues.
3. Use the provided methods to issue tickets, serve customers, and retrieve queue information.
4. Compile and run your program to observe the queue management in action.

## Example

Here's a simple example of using the `clsQueueLine` class:

```cpp
#include <iostream>
#include "clsQueueLine.h"

int main() {
    clsQueueLine queue("A", 10);

    queue.IssueTicket();
    queue.IssueTicket();

    std::cout << "Waiting Clients: " << queue.WaitingClients() << std::endl;
    std::cout << "Next Customer: " << queue.WhoIsNext() << std::endl;

    queue.ServeNextClient();
    std::cout << "Waiting Clients After Serving: " << queue.WaitingClients() << std::endl;

    return 0;
}
```
## Author

- Mahmoud Mohamed
- Email: mahmoud.abdalaziz@outlook.com
- LinkedIn: [Mahmoud Mohamed Abdalaziz](https://www.linkedin.com/in/mahmoud-mohamed-abd/)


## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.