#pragma

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include <limits>

class Span
{
        private:
                unsigned int _nbrMax;
                std::vector<int> _number;

        public:
                Span();
                Span(unsigned int _nbrMax);
                ~Span();
                Span(const Span &other);
                Span &operator=(const Span &other);

                void addNumber(int number);
                int shortestSpan() const;
                int longestSpan() const;
                void AddMoreNumber();

                
                class  spanIsFull : public std::exception
                {
                        public:
                                virtual const char *what() const throw(){
                                        return ("Span is full, cannot add more numbers !!"); 
                                }
                };

                class NoSpanClac : public std::exception 
                {
                        public:
                                virtual const char* what() const throw(){
                                     return ("Not enough numbers to calculate span !!");   
                                }
                };


};