#include "Span.hpp"

Span::Span() : _N(0)
{
    // std::cout << "Constructor Span has called" << std::endl;
}


Span::Span(unsigned int N) : _N(N)
{
    // std::cout << "Constructor Span has called" << std::endl;
}


Span::Span(const Span &other) : _N(other._N), _number(other._number)
{
}

Span &Span::operator=(const Span &other)
{
    if(this != &other)
    {
        _N = other._N;
        _number = other._number;
    }
    return(*this);
}

Span::~Span()
{
    // std::cout << "Destructor Span has called" << std::endl;
}


void Span::addNumber(int number)
{
    if(_number.size() >= _N)
        throw spanIsFull();
    _number.push_back(number);
}

int Span::shortestSpan() const
{
    if(_number.size() < 2)
        throw NoSpanClac();
    std::vector<int> sorted = _number;
    std::sort(sorted.begin(), sorted.end());

    int minSpan = sorted[1] - sorted[0];
    for (size_t i = 1; i < sorted.size() - 1; i++)
    {
        int result = sorted[i + 1] - sorted[i];
        if(result < minSpan)
            minSpan = result;
    }
    return(minSpan);
}

// Trie les nombres : [17, 3, 11, 9, 6] → [3, 6, 9, 11, 17]
// Compare les nombres consécutifs :
// 6 - 3 = 3
// 9 - 6 = 3
// 11 - 9 = 2 ← Plus petit !
// 17 - 11 = 6
// Retourne 2


int Span::longestSpan() const
{
    if(_number.size() < 2)
        throw NoSpanClac();
    int min = *std::min_element(_number.begin(), _number.end());
    int max = *std::max_element(_number.begin(), _number.end());
    return (max - min);
}
