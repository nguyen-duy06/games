#include <iostream>
#include "random.h"
namespace
{
constexpr int min{1};
constexpr int max{100};
constexpr int guess_times{7};
}
void cacul_guess(int correct_num)
{
    for (int count{1}; count <= guess_times; ++count)
    {
        int guess_num;
        std::cout << "Guess #" << count << ':';
        std::cin >> guess_num;
        if (guess_num > correct_num)
            std::cout << "Your guess is too high.\n";
        else if (guess_num < correct_num)
            std::cout << "Your guess is too low.\n";
        else
        {
            std::cout << "Correct! You win!\n";
            return;
        }
    }
    std::cout << "Sorry, you lose. The correct number was " << correct_num << ".\n";
}
bool wanna_play_again()
{
    char yes_or_no;
takeInput:
    std::cout << "Would you like to play again (y/n)?";
    std::cin >> yes_or_no;
    if (yes_or_no == 'y')
        return true;
    else if (yes_or_no == 'n')
        return false;
    else
        goto takeInput; 
}
int main()
{
start:
    std::cout << "Let's play a game. I'm thinking of a number between 1 and 100. You have 7 tries to guess what it is.\n";
    int correct_num{Random::get(min,max)};
    cacul_guess(correct_num);
    if(wanna_play_again())
        goto start;
    else
        std::cout << "Thank you for playing.\n";
    return 0;
}


