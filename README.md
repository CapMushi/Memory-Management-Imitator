Memory-Management-Imitator
Overview:
Memory-Management-Imitator is a simple memory management system implemented in C++. It utilizes a linked list data structure to manage memory blocks and programs, demonstrating both first-fit and best-fit strategies for memory allocation.

Features:
Linked List Implementation: Custom linked list data structure for memory blocks and programs.
Memory Allocation: Supports first-fit and best-fit strategies.
Memory Deallocation: Efficient deallocation of memory blocks.
Dynamic Memory Management: Ability to add and remove memory blocks and programs dynamically.
Sorting and Merging: Automatically sorts and merges free memory blocks.

Usage:
Class Definitions
Node: Template class for linked list nodes.
LinkedList: Template class for the linked list.
Block: Represents a memory block.
Program: Represents a program requesting memory.
MemoryManagementSystem: Manages the memory allocation and deallocation.
Memory Management System
The MemoryManagementSystem class handles the memory management:

Constructor: Initializes the memory pool and sets the allocation strategy.
Add Block to Pool: Adds a new memory block to the pool.
Get Memory: Checks if sufficient memory is available for allocation.
Add Program to Programs: Allocates memory to a new program.
Terminate Program: Deallocates memory from a program.
Display Pool: Displays the current memory blocks in the pool.
Display Programs: Displays the current programs in memory.
Main Function
The main function demonstrates the usage of the MemoryManagementSystem:

Initializes the memory management system with a total size of 100 bytes and the best-fit strategy.
Adds programs and displays the memory pool and programs.
Terminates a program and reallocates memory to a new program.

How to Run:
1. Clone the Repository
   git clone https://github.com/CapMushi/Memory-Management-Imitator.git
   cd Memory-Management-Imitator

2. Compile the Code
   Use a C++ compiler to compile the code. For example, with g++:
   g++ -o memory_management main.cpp
   
4. Run the Executable
   ./memory_management
   
Example Output:
Node added at start
Node added at start
Node added at start
[ 90 | 10 ]-> [ 70 | 20 ]-> [ 0 | 70 ]-> NULL
[ 0 | 20 ]-> [ 20 | 30 ]-> [ 50 | 40 ]-> NULL
Node deleted in the middle
Node added at start
[ 90 | 10 ]-> [ 80 | 10 ]-> [ 70 | 10 ]-> [ 60 | 10 ]-> [ 50 | 10 ]-> [ 30 | 20 ]-> [ 0 | 30 ]-> NULL
[ 0 | 10 ]-> [ 10 | 20 ]-> [ 30 | 30 ]-> [ 50 | 40 ]-> NULL

Feel free to open issues or submit pull requests for any improvements or bug fixes.
