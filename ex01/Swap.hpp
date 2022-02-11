#ifndef  SWAP_HPP
#define  SWAP_HPP

#include <iostream>
#include <algorithm>    // std::find
#include <vector>       // std::vector

class Swap 
{
    unsigned int _n;
	std::vector<int> _vector;


public:
	Swap();
	Swap(int n);
	~Swap();
    Swap(const Swap &ref);
    unsigned int size() const ;	
    std::vector<int> const get_vector() const ;
    

    // Span &operator=(Span const &other);
	int &operator[](int i);
    void addNumber(int value);
    long shortestSpan();
    long longestSpan();
    class FullException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
    class OutofRangeException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
    class SearchInvailable : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
};



#endif