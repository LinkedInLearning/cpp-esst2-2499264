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

    // TODO: consume beim Aufruf reduziert resources nicht. Lambda Notation muss verändert werden.
    auto consume = [resources]() mutable {
        resources--;
    };

    // TODO: produce beim Aufruf erhöht resources nicht. Lambda Notation muss verändert werden.
    auto produce = [=]() mutable {
        resources += amtToProduce;
    };

    // TODO: Zeigt es die richtigen resources an? Irgendwie bleibt der Wert doch bei 1000.
    // Herausfinden, was hier nicht stimmt.
    auto display = [resources]() {
        cout << "Resources left: " << resources << endl;
    };

    consume();
    produce();
    display();

    bool dispUpper = true;

    std::string text= "Hello World!\n";

    // TODO: Folgende Zeilen Code wiederholen sich sehr oft.
    // Finden Sie einen Weg die gleiche Logik beizubehalten, aber folgenden Code mit Hilfe eines Lambdas zu reduzieren.
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

    dispUpper = false;

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



    return 0;
}
