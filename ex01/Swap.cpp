#include "Swap.hpp"

Swap::Swap(int n)
{
    this->_n = n;
}
Swap::Swap()
{
    this->_n = 0;
}

Swap::~Swap()
{

}

Swap::Swap(const Swap &ref)
{
    this->_n = ref.size();
}

unsigned int Swap::size() const 
{
    return (_n);
}

std::vector<int> const Swap::get_vector() const 
{
    return (_vector);
}

void Swap::addNumber(int value)
{
    if (_vector.size() >= _n)
        throw FullException();
    else
        _vector.push_back(value);
}

long Swap::shortestSpan()
{
    if (_vector.size() < 2)
        throw SearchInvailable();
	std::vector<int> copy = _vector;

	std::sort(copy.begin(), copy.end());
	std::vector<int>::iterator prev = copy.begin();
	std::vector<int>::iterator next = ++copy.begin();
	long minSpan = *next - *prev;
    
	while (next != copy.end())
	{
		if ((long)*next - *prev < minSpan)
			minSpan = (long)*next - *prev;
		prev = next;
		next++;
	}
	return minSpan;
}

long Swap::longestSpan()
{
    if (_vector.size() < 2)
        throw SearchInvailable();
	std::vector<int> copy = _vector;

	std::sort(copy.begin(), copy.end());

	return ((long)copy.back() - copy.front());
}

int &Swap::operator[](int i)
{
    if (i < 0 || i > _n)
        throw OutofRangeException();
    return _vector[i];
}

const char *Swap::FullException::what() const throw()
{
    return ("Swap Exception : container is full");
}

const char *Swap::OutofRangeException::what() const throw()
{
    return ("Swap Exception : out of range");
}
const char *Swap::SearchInvailable::what() const throw()
{
    return ("Swap Exception : search Invailabe");
}
