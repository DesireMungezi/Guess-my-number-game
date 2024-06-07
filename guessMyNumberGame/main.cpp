#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>

int randomNumber(int gameDifficuly)
{
    int numberLimit;
    switch(gameDifficuly)
    {
    case 1:
        numberLimit = 20;
    case 2:
        numberLimit = 50;
    case 3:
        numberLimit = 100;
    }
    srand(static_cast<unsigned int>(time(0)));
    //random number geneartor
    const int randomValue = (rand() % numberLimit);
    return randomValue;
}
void gameDifficulty()
{
    std::cout<<"\tGame Difficulty"<<std::endl;
    std::cout<<"1.Easy Level (1-20)"<<std::endl;
    std::cout<<"2.Normal Level (1-50)"<<std::endl;
    std::cout<<"3.Hard Level (1-100)"<<std::endl;
    std::cout<<"4.Quit"<<std::endl;
}
void menu()
{
    std::cout<<"\tGUESS MY NUMBER"<<std::endl;
    std::cout<<"I know no human can guess my number"<<std::endl;
    std::cout<<"Too much tries means your score will be low\n"<<std::endl;
}

void gameSystem(int userChoice)
{
    int answer = randomNumber(userChoice);
    int myGuess;
    int tries = 0;

    do {
        std::cout<<"Enter your guess :";
        std::cin>>myGuess;
        if (myGuess > answer) {
            std::cout<<"Too high\n"<<std::endl;
            tries++;
        } else if (myGuess < answer) {
            std::cout<<"Too low\n"<<std::endl;
            tries++;
        }
    }while(myGuess != answer);

    int score = 0;
    if (tries > 10)
    {
        score += 30;
    }
    else if (tries <= 9 && tries >= 5)
    {
        score += 50;
    }
    else if (tries <= 4 && tries >= 2)
    {
        score += 70;
    }
    else if (tries <= 1 )
    {
        score += 100;
    }

    if (myGuess == answer) {
        std::cout<<"\nNo! No!, How did you do it, it's Impossible!"<<std::endl;
        std::cout<<"You may have WON this time but you won't the next time"<<std::endl;
        std::cout<<"Your Score is :"<<score<<std::endl;
    }
}

int main()
{
    int choice;
    menu();
    do
    {
        gameDifficulty();
        std::cout<<"Enter choice :";
        std::cin>>choice;
        if((choice != 1 && choice != 2) && (choice != 3 && choice != 4))
        {
            //invalid number
            std::cout<<"Invalid Number!\n"<<std::endl;
        }
        else
        {
            if(choice == 4)
            {
                break;
            }
            gameSystem(choice);
        }

    }while(choice != 4);
    std::cout<<"Ha! Ha!, I knew you would quit "<<std::endl;
    return 0;
}
