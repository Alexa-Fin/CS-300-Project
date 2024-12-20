# CS-300-Project
# Alexa Finnell
# 12/19/2024

What was the problem you were solving in the projects for this course?
The problem that was addressed was creating a program to manage and display course information for an advising system. The system had to load course data from a CSV file, display a list of courses in alphanumeric order, and provide detailed information about individual courses, including their prerequisites. The goal was to build a user-friendly tool that advisors or students could use to access course details efficiently.

How did you approach the problem? Consider why data structures are important to understand.

I approached the problem by using a hash table to store and organize the course information. I used a struct to define the structure of a course and an unordered_map to store courses using their course numbers as keys for fast lookups. This decision was crucial for efficient access of course details and managing the relationship between courses and their prerequisites. Understanding data structures like unordered_map and vector helped ensure that our program could handle tasks like searching, sorting, and storing data in a way that was both efficient and easy to implement.


How did you overcome any roadblocks you encountered while going through the activities or project?

The roadblock I got stuck at was ensuring the CSV file with the data was being read correctly. Initially, I struggled with my program not reading the file no matter which place I put it in. Somehow, I messed up the name of the file by forgetting to add .csv at the end of the file's name. Now that I look back on it, it was such an obvious answer. I'm glad that my small oversight was easily fixed.

How has your work on this project expanded your approach to designing software and developing programs?

This project specifically highlighted the importance of choosing the right data structure for the job. Using the right data structure can be a bit of a process, but it can simplify implementation and improve performance of a program. This project will forever change my approach to creating an efficient and effective software in the future.

How has your work on this project evolved the way you write programs that are maintainable, readable, and adaptable?

Working on this project improved my ability to write programs that are clear and easy to modify. Using clear, meaningful variable and function names helps to make the code more readable. Breaking up my program into smaller, reusable functions makes it much easier to debug and add onto in the future. Overall, the project showed the importance of writing clean, modular code to ensure that the program remains maintainable and adaptable for the foreseeable future.
