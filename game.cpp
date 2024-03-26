#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "game.h"

namespace game 
{
  int getRandomNumber() 
  {
      srand(time(0));
      return rand() % 100;
  }
  
  bool isEven(int num) 
  {
      return num % 2 == 0;
  }
  
  int startgame() 
  {
      std::cout << "Welcome to the Brain Games!\n";
      std::string name;
      std::cout << "May I have your name? \n";
      std::cin >> name;
      std::cout << "Hello, " << name << "!\n" << "Answer 'yes' if the number is even, otherwise answer 'no'.\n";
      
      int correctanswer = 0;

      for (int i = 0; i < 3; i++)
      {
          int number = getRandomNumber();
          std::cout << "Question: " << number << std::endl;
          std::cout << "Your answer: ";
          std::string answer;
          std::cin >> answer;
          std::string correctanswer = isEven(number) ? "yes" : "no";
          if (answer != correctanswer) 
          {
              std::cout << "'" << answer << "' is wrong answer ;(. Correct answer was '" << correctanswer << "'." << std::endl;
              std::cout << "Let's try again, " << name << "!" << std::endl;
              correctanswer = 0;
          }
          else 
          {
              std::cout << "Correct!" << std::endl;
              correctanswer++;
          }
      }
  
      return 0;
  }
}
void testIsEven()
{
    assert(test1::isEven(2) == true);
    assert(test1::isEven(3) == false);
    assert(test1::isEven(0) == true);
    assert(test1::isEven(-1) == false);
}
