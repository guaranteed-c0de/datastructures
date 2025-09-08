# DataStructures

design choices + where you throw exceptions + how CSV escaping works

I did challenge extensions 1 and 3. 
For challenge extension 1, I created a csv.cpp file and a csv.hpp file. The csv.hpp file handles the declaration of the csv while defining the csv_escape() function, and the csv.cpp file defines the function make_csv, which makes the csv.
For challenge extension 3, I defined from_json functions in student.cpp and instructor.cpp. I passed JSON objects to the Instructor.cpp/Student.cpp files. From there, the objects' attributes were passed to the constructors of the Instructor.hpp//Student.hpp files.
I throw exceptions when the name field is empty, the email name is empty, office is empty the ID is less than 0, graduation year is before 2000.
With CSV escaping, the string is enclosed between two backslashes. The function takes the string as an argument, defines a variable that is two characters longer than the string, and replaces the first and last character with double quotes.
