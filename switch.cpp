#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  
  char letter_grade {}

  cout<< "Enter the letter grade you expect from the exam: ";
  cin >> letter_grade;

  switch (letter_grade)
  {
  case 'a':
  case 'A': cout << "You got a 90 - 100, good job"<< endl;
    
    break;

    case 'f':
    case 'F': 
    {
        char confirm{};
        cout << "Are you sure (Y/N): " ;
        cin >> confirm;
        
        if (confirm == 'y' || confirm == 'Y')
        {
           cout << "You need to work harder" << endl;
        }
        else if (confirm == 'n' || confirm == 'N')
        {
           
           cout << "You made the right choice" << endl;
        }
        else 
        cout << "Illegal entry"<< endl;
    }
  
  default: cout << "Invalid Grade" << endl;
    break;
  }
}