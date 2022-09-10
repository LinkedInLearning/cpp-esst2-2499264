#include <iostream>

#include <array>
#include <cassert>

template <typename T1, unsigned int S>
class VectorND {
public:

    VectorND()
    {}

    template<class T, class... A>
    VectorND(const T x, A... args)
    {
        fill(x, args...);
    }


    template <typename T2>
    T1 operator*(const VectorND<T2, S> &other)
    {
        T1 result = 0;
        for(auto i=0 ; i<mData.size() ; i++)
        {
            result += mData[i]*other[i];
        }
        return result;
    }

    void clear()
    {
        for(auto &val : mData)
            val = 0;
    }

    template <typename T2>
    VectorND<T1, S> operator+(const VectorND<T2, S> &other)
    {
        VectorND<T1, S> result;
        result.clear();
        for(auto i=0 ; i<S ; i++)
        {
            result[i] += mData[i]+other[i];
        }
        return result;
    }

    T1 operator[](const unsigned int idx) const
    {
        if(idx >= mData.size())
        {
            std::cerr << "Wrong index " << idx << std::endl;
            return 0;
        }

        return mData[idx];
    }

    T1& operator[](const unsigned int idx)
    {
        if(idx >= mData.size())
        {
            std::cerr << "Warning: Wrong index " << idx << std::endl;
            return mData[0];
        }

        return mData[idx];
    }


    unsigned int size() const
    {   return S;    }

    void print()
    {
        for(auto i=0 ; i<mData.size() ; i++)
        {
            std::cout << mData[i] << std::endl;
        }
    }

private:

    void fill()
    {}

    template<class T, class... A>
    void fill(const T x, A... args)
    {
        mData[mSizeSentinel++] = x;
        assert(mSizeSentinel <= S);
        fill(args...);
    }


    std::array<T1, S> mData;
    int mSizeSentinel = 0;
};

int main()
{
    VectorND<int, 3> x1(1,2,3);
    VectorND<int, 3> x2(1,2,3);

    VectorND<int, 5> y1(1,2,3,4,5);
    VectorND<int, 5> y2(1,2,3,4,5);

    auto x3 = x1+x2;
    auto y3 = y1+y2;

    x3.print();
    y3.print();

    std::cout << x1*x2 << std::endl;
    std::cout << y1*y2 << std::endl;


    return 0;
}
