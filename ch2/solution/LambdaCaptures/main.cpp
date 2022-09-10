#include <iostream>

using namespace std;

void displayUpper(const char ch)
{
    if(ch >= 'a' && ch <= 'z')
        std::cout << char((ch-32));
    else
        std::cout << ch;
}

void displayNormal(const char ch)
{
    if(ch >= 'A' && ch <= 'Z')
        std::cout << char((ch+32));
    else
        std::cout << ch;
}


int main()
{
    int resources = 1000;
    int amtToProduce = 10;

    auto consume = [&resources](){
        resources--;
    };

    auto produce = [&]() mutable {
        resources += amtToProduce;
    };

    auto display = [&resources]() {
        cout << "Resources left: " << resources << endl;
    };

    consume();
    produce();
    display();

    bool dispUpper = true;

    std::string text= "Hello World!\n";

    auto dispWithProberTextSize = [=](const bool dispUpper){
        if(dispUpper)
        {
            for(int i=0 ; i<text.size() ; i++)
                displayUpper(text.at(i));
        }
        else
        {
            for(int i=0 ; i<text.size() ; i++)
                displayNormal(text.at(i));
        }
    };

    dispWithProberTextSize(dispUpper);
    dispUpper = false;
    dispWithProberTextSize(dispUpper);

    return 0;
}
