# Ball-Sort-Puzzle-Solver
[![Build Status](https://travis-ci.org/AntounWagdy/Ball-Sort-Puzzle-Solver.svg?branch=master)](https://travis-ci.org/AntounWagdy/Ball-Sort-Puzzle-Solver)

Ball-Sort-Puzzle-Solver is a c++ based project to find and analyse solutions for the game known as **"Ball Sort Puzzle"**. You may test the game play at [Google Play Store]([https://play.google.com/store/apps/details?id=com.GMA.Ball.Sort.Puzzle](https://play.google.com/store/apps/details?id=com.GMA.Ball.Sort.Puzzle)).

## Getting started
Import the .sln file into your visual studio. 3 projects will be imported to your environment:

 1. Ball-Sort-Puzzle-Solver: This is the back-end of the project. It is responsible for the tubes and the balls and the actions on them
 2. Ball-Sort-Puzzle-Solver-Tester: This is the project where gtest take the lead to test the project and ensure the right functionality.
 3. Ball-Sort-GUI: This is the project where the GUI is implemented using the QT libraries.


## Prerequisites
Install Visual Studio and import the solution file. Add [google test]([[https://docs.microsoft.com/en-us/visualstudio/test/how-to-use-google-test-for-cpp?view=vs-2019](https://docs.microsoft.com/en-us/visualstudio/test/how-to-use-google-test-for-cpp?view=vs-2019)]) to your environment to start testing the project. And add [QT VS tool]([[https://medium.com/@paryleevatou/how-to-setting-qt-gui-using-c-with-visual-studio-2017-dbb50406f99](https://medium.com/@paryleevatou/how-to-setting-qt-gui-using-c-with-visual-studio-2017-dbb50406f99)]) to your environment to start viewing solutions.

## Running tests
After finishing the prerequisites you run **Ball-Sort-Puzzle-Solver-Tester** project 

## Running the GUI
After finishing the prerequisites you run **Ball-Sort-GUI**. You may need to change the test file use in the GUI in the main.cpp. 

## Solutions analysis
Multiple solution has been tested over so many test cases. test cases has been broken into two types:
 1. Easy test cases: Those are the levels [1-10] in the game.
 2. Hard test cases: Those are the levels [50-60] in the game and also some other chosen hard levels.
 
Four different solutions has been implemented: <br>
 1. Algorithm 1 : this is the recursive solution. We search the whole tree using recursion (DFS) to reach to the goal solution.<br>
 2. Algorithm 2: this is the iterative solution.  We search the whole tree but using queues.<br>
 3. Algorithm 3: this is another version of the iterative solution where we use threading to take less time.<br>
 4. Algorithm 4: another version of the iterative solution where we use heuristic calculations to take the most promising state to the next iteration.<br>

And here is the timing of each algorithm on each split of the test cases:

|  Algorithm  | average timing on the easy test cases | average timing on the hard test cases |
|:-----------:|:-------------------------------------:|:-------------------------------------:|
| Algorithm 1 |                9923 ms                |                28703 ms               |
| Algorithm 2 |                6132 ms                |                51720 ms               |
| Algorithm 3 |                7205 ms                |                15844 ms               |
| Algorithm 4 |                 84 ms                 |                 113 ms                |
  
  ## Output
  This is the GIF showing how the program runs with a 300 ms interval between each two moves.
![GIF to show the program running](https://github.com/AntounWagdy/Ball-Sort-Puzzle-Solver/blob/master/demo.gif)
## License
Copyright (c) 2020 Antoun Wagdy.

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
