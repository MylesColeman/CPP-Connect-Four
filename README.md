# C++: Connect Four Logic
**University Year 1 | Semester 2 | Programming for Game Engines**

A console-based technical study in C++ focusing on 2D grid manipulation, algorithmic pattern recognition, and robust input validation. This project served as a foundational re-introduction to C++ programming before transitioning into Unreal Engine 5 development.

> **[🔗 View the full technical breakdown on my Portfolio](https://sites.google.com/view/myles-coleman/projects/inventory-system-plugin-wip)**

## 🕹️ Project Overview
Developed as the introductory project for the 'Programming for Game Engines' module, this implementation of Connect Four prioritises logical accuracy and stability. The project demonstrates the transition from basic syntax to architectural thinking, specifically regarding win-state detection and data integrity in game loops.

## 🛠️ Key Technical Features

### Algorithmic Win Detection
* **Multi-Directional Scans:** Engineered a custom `checkForWinner()` function that identifies winning patterns across four distinct vectors: Horizontal, Vertical, Diagonal-Left, and Diagonal-Right.
* **Boundary Validation:** Implemented strict index checking within the scanning loops to prevent "Out of Bounds" memory access errors when checking the edges of the grid.
* **Draw State Logic:** Integrated turn-tracking that monitors the total board capacity to accurately detect and broadcast draw states once the board is saturated.

### Grid & "Gravity" Simulation
* **Dynamic Architecture:** Utilised `std::vector` containers rather than static arrays, allowing the board dimensions to be easily modified or scaled at runtime.
* **Physicality Simulation:** Developed the `updateBoard()` function to iterate from the bottom of the grid upwards, identifying the lowest available slot in a column to simulate the physical "drop" of a game token.

### Robust Input Sanitization
* **Fail-Safe Validation:** Implemented an input loop that handles non-numeric characters and out-of-bounds column entries without crashing, using `std::cin.fail()` and `std::cin.ignore()` to maintain program stability.
* **State Verification:** Integrated logic to verify column occupancy, preventing players from attempting to drop tokens into a column that has already reached maximum capacity.

## 🧠 Lessons Learned: Optimization vs. Functionality
A significant hurdle in this project was the implementation of win-detection. While the optimal approach involves checking only the neighbours of the newly placed token, I chose to implement a comprehensive state-scan each turn to ensure 100% accuracy. This taught me the professional trade-off between "perfect" optimization and delivering a fully functional, bug-free system on schedule.

## 💻 Technical Specs
* **Language:** C++
* **Compiler:** Visual Studio
* **Key Focus:** 2D Grid Algorithms / Input Validation
