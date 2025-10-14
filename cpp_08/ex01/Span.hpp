#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include <limits>
#include <list>


class Span
{
        private:
                unsigned int _N;
                std::vector<int> _number;

        public:
                Span();
                Span(unsigned int _N);
                ~Span();
                Span(const Span &other);
                Span &operator=(const Span &other);

                void addNumber(int number);
                int shortestSpan() const;
                int longestSpan() const;
                
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
                void print() const;

                template<typename Iterator>
                void addMoreNumber(Iterator begin, Iterator end)
                {
                        while (begin != end)
                        {
                                if (_number.size() >= _N)
                                throw spanIsFull();
                                _number.push_back(*begin);
                                ++begin;
                        }
                }

};