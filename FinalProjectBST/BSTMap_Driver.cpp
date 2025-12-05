#include "Tree.h"
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <random>
using namespace std;
using namespace std::chrono;
char RandomlyGenerateLetter();
int main() {
  
    TreeType Test;
    Test.InsertKeyValue("Morehouse", 1867);
    Test.InsertKeyValue("Spelman", 1881);
    Test.InsertKeyValue("Clark", 1988);
    Test.InsertKeyValue("Howard", 1867);
    Test.InsertKeyValue("Hampton", 1868);
    Test.InsertKeyValue("Tuskegee", 1881);
    Test.InsertKeyValue("Florida A&M", 1887);
    Test.InsertKeyValue("Xavier", 1831);
    Test.InsertKeyValue("Morgan State", 1867);
    Test.InsertKeyValue("Dillard", 1869);
    Test.AddKeyValue();
    Test.GetLength();
    Test.SearchKey();
    Test.DeleteNode();
    Test.GetLength();
      int string_length = 5;
    string sample="";
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < string_length; j++)
        {
            sample+= RandomlyGenerateLetter();
        }
        Test.InsertKeyValue(sample, 1023);
    } 
    Test.GetLength();
   auto start = high_resolution_clock::now();
    Test.DeleteNode2("Clark");
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    cout << "Insert took " << duration.count() << " microseconds.\n"; 
    return 0;
}

char RandomlyGenerateLetter() {
    std::random_device rd;  // non-deterministic random seed
    std::mt19937 gen(rd()); // Mersenne Twister RNG
    std::uniform_int_distribution<> dist(0, 9);  
int number = dist(gen);
char title;
if (number == 1) {title = 'A';}
else if (number == 2) {title = 'B';}
else if (number == 3) {title = 'C';}
else if (number == 4) {title = 'D';}
else if (number == 5) {title = 'E';}
else if (number == 6) {title = 'F';}
else if (number == 7) {title = 'G';}
else if (number == 8) {title = 'H';}
else if (number == 9) {title = 'I';}
else if (number == 10) {title = 'J';}
else if (number == 11) {title = 'K';}
else if (number == 12) {title = 'L';}
else if (number == 13) {title = 'M';}
else if (number == 14) {title = 'N';}
else if (number == 15) {title = 'O';}
else if (number == 16) {title = 'P';}
else if (number == 17) {title = 'Q';}
else if (number == 18) {title = 'R';}
else if (number == 19) {title = 'S';}
else if (number == 20) {title = 'T';}
else if (number == 21) {title = 'U';}
else if (number == 22) {title = 'V';}
else if (number == 23) {title = 'W';}
else if (number == 24) {title = 'X';}
else if (number == 25) {title = 'Y';}
else if (number == 26) {title = 'Z';}
    return title;
}