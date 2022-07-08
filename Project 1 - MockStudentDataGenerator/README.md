# Project 1: Mock Student Data Generator
## I. Project description:*[ here](https://tdquang7.notion.site/Project-Mock-data-generator-1-7c70a1a81b724049bd82ede839e2ff24)*
## II.How to run the program
|To execute the program|To debug and view code|
|------------|:---------------|
|1. *MockDataGenerator.exe* must be put at the same level with folder *Data*|1. use Visual Studio 2019|
|2. Folder *Data* includes entrance data|2. open *MockDataGenerator.sln*|
|3. You can edit files in *Data* to get more variety output (must strictly follow the format of these files)|
### III. This program will 
1. Read all students saved in the file "students.txt" back into a vector of Student.
2. Generate randomly a number n in the range of [5, 10].
3. Generate randomly n Students and add to the previous vector.
    A student has these information:
    - Student ID (8 numbers)
    - Full-name
    - GPA 
    - Telephone
    - Email
    - Birthday
    - Address
4. Overwrite and save and the students in the current vector back to the file "students.txt".
5. Print out the average GPA of all students.
6. Print out all the students that have a GPA greater than the average GPA.
### IV. Special knowledge
- Use *time.h* to get current time and date.
- Generate a random float number with *rand()*.
- Generate random Last-name according to [actual rate](https://vi.wikipedia.org/wiki/H%E1%BB%8D_ng%C6%B0%E1%BB%9Di_Vi%E1%BB%87t_Nam).
