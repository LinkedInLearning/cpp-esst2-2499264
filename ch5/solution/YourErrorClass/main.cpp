#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <sstream>

class ArrayTooShortException : public std::exception
{
public:

    ArrayTooShortException(const int expc, const int got) :
        mExpc(expc),
        mGot(got)
    {
        std::stringstream ss;

        ss << "Sorry, but your array is too short. Size is ";
        ss << mExpc;
        ss << ". You gave me ";
        ss << mGot;
        ss << "." << std::endl;

        ss.seekg (0, ss.end);
        const int numChars = ss.tellg();
        ss.seekg (0, ss.beg);
        mErrorMsg.assign(numChars+1, 0);
        ss.getline(mErrorMsg.data(), numChars);
    }

protected:

    virtual const char* what() const noexcept
    {
        return mErrorMsg.c_str();
    }

private:

    std::string mErrorMsg;

    const int mExpc = 0;
    const int mGot = 0;
};


int main()
{
    std::vector<std::string> data;

    try
    {
        data.push_back("Test");
        data.push_back("Test2");

        if(data.size() < 10)
        {
            throw ArrayTooShortException(data.size(), 10);
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
