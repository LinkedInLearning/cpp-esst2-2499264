#include <iostream>
#include <string>
#include <vector>
#include <exception>

int main()
{
    std::vector<std::string> data;

    try
    {
        data.push_back("Test");
        data.push_back("Test2");

        if(data.size() < 10)
        {
        	// TODO: Folgenden throw in eine eigene Fehlerklasse integrieren, damit über what() die Ursache abgefragt werden kann.
        	// Dieses what() soll dann im Block zu catch(const std::exception &e) aufgerufen werden.
        	// Erweitere auch die Fehlermeldung so, dass die Größe des Vectors und welcher Wert vom Entwickler:in kam, 
        	// mit in der Exception auftauchen.
            throw "Sorry, your array is too short.";
        }

        std::cout << data.at(10) << std::endl;

        data.push_back("Test3");

        data.push_back("Test5");

    }
    catch(const char *str)
    {
        std::cout << str << std::endl;
        data.push_back("Test after exception thrown with str");
    }
    catch(const std::exception &e)
    {
        std::cout << e.what() << std::endl;

        data.push_back("Test after exception thrown");
    }
    catch(...)
    {
        std::cout << "Unknown Exception caught!" << std::endl;
    }

    for(const auto &text : data)
    {
        std::cout << text << std::endl;
    }

    return 0;
}
