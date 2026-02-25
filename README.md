# Corner Grocer Item Tracking Program (C++)

## Project Overview
This project is a C++ program designed to analyze grocery purchase data. The program reads a text file containing a list of items purchased throughout the day and determines how frequently each item appears. The goal is to help a small grocery store understand which items sell the most so they can manage inventory more efficiently.

The program allows the user to interact with a menu system where they can search for the frequency of a specific item, display all item frequencies, or print a histogram showing purchase quantities.

---

## What the Program Solves
Small stores often track purchases manually, which is time-consuming and prone to mistakes. This program automates that process. By reading data from a file and counting occurrences, the program quickly provides useful business information such as which products are most popular.

---

## What I Did Well
One of my strengths in this project was creating a clear, user-friendly menu system. The options are easy to understand, and the program continues to run until the user chooses to exit.

I also successfully implemented file input and output. The program reads item data from an input file and writes frequency results to a backup file. I separated tasks into functions instead of placing all code inside main(), which improved readability and organization. I also included comments explaining the purpose of different sections of the code.

---

## Where the Code Could Be Improved
The program could be improved with stronger input validation. Currently, it assumes the user enters correct menu options and properly spelled item names. Additional error checking would make the program more secure and reliable.

Efficiency could also be improved by using a C++ map or unordered_map instead of repeatedly reading through the file. This would significantly improve performance with larger datasets.

A graphical interface could also be added in the future to make the program more practical for real business use.

---

## Challenges and How I Solved Them
The most difficult part of the project was working with file input/output and counting duplicate items correctly. At first, the program was not counting items accurately.

I solved this by testing the program using small sample files and printing intermediate values to verify the logic. I also used debugging tools in Visual Studio to watch variable values change as the program executed.

Resources I used included:
- zyBooks course material
- Instructor examples
- Visual Studio debugging tools
- Trial-and-error testing

---

## Transferable Skills
This project helped me build skills that apply to future software development work:

- Reading and writing files
- Data processing
- Debugging and troubleshooting
- Writing modular functions
- Designing a user interface (menu system)
- Writing readable and documented code

These skills can be applied to automation programs, data analysis tools, and monitoring systems.

---

## Maintainability and Adaptability
I made the program maintainable by using functions, meaningful variable names, and comments. The code is modular, so new features could be added without rewriting the program.

The program is also adaptable. By changing the input file, the same program could track inventory, analyze logs, or count repeated events in other applications.

---

## Conclusion
This project strengthened my understanding of loops, conditionals, functions, and file handling in C++. It demonstrates my ability to design a functional program that solves a real-world problem. Completing this program increased my confidence in programming and improved my ability to write clear and maintainable code.
