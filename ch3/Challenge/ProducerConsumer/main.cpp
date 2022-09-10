#include <iostream>
#include <future>
#include <thread>
#include <chrono>

using namespace std;

int main()
{
    auto promise = std::promise<int>();

    auto producer = std::thread([&]
    {
        for(int i=0; i<=10 ; i++)
        {
            const int r = i*i;

            std::this_thread::sleep_for(chrono::milliseconds(1000));

            // TODO: Folgender Abschnitt gehört in den Consumer-Bereich
            std::cout << "Incoming Result: ";
            std::cout << r;
            std::cout << std::endl;
        }
    });


    auto consumer = std::thread([&]
    {
        int r = 0;
        while(r < 100)
        {
            // TODO: Consumer Code implementieren, bei dem promises und futures für die
            // Interthread-Kommunikation verwendet werden.
            //std::cout << "Incoming Result: ";
            break;
        }

    });

    producer.join();
    consumer.join();
    return 0;
}
