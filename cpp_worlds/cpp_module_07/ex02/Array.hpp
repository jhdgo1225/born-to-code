#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <cstdlib>
# include <sstream>

template<typename T>
class Array
{
public:
    Array()
        :arrayLen(0)
    {
        try {
            arr = new T[0];
        } catch(std::bad_alloc& e) {
            std::cout << "exception : " << e.what() << '\n';
            std::abort();
        }
    }
    Array(unsigned int sz)
        : arrayLen(sz)
    {
        try {
            arr = new T[sz];
        } catch(std::bad_alloc& e) {
            std::cout << "exception : " << e.what() << '\n';
            std::abort();
        }
    }
    ~Array()
    {
        delete[] arr;
    }
    Array(const Array<T>& rhs)
        : arrayLen(rhs.arrayLen)
    {
        try {
            arr = new T[arrayLen];
            for (unsigned int idx = 0; idx < arrayLen; idx++)
                arr[idx] = rhs.arr[idx];
        } catch(std::bad_alloc& e) {
            std::cout << "exception : " << e.what() << '\n';
            std::abort();
        }
    }
    Array<T>& operator=(const Array<T>& rhs)
    {
        try {
            delete[] arr;
            arrayLen = rhs.arrayLen;
            arr = new T[arrayLen];
            for (unsigned int idx = 0; idx < arrayLen; idx++)
                arr[idx] = rhs.arr[idx];
        } catch(std::bad_alloc& e) {
            std::cout << "exception : " << e.what() << '\n';
            std::abort();
        }
        return (*this);
    }
    T& operator[](unsigned int pos) {
        if (pos < 0 || pos >= arrayLen)
        {
            std::string message;
            std::stringstream ss;
            ss << arrayLen;
            message.append("Error => Out of Range: ").append(ss.str());
            throw (std::out_of_range(message));
        }
        return (arr[pos]);
    }
    unsigned int size()
    {
        return (arrayLen);
    }
private:
    unsigned int  arrayLen;
    T       *arr;
};

#endif
