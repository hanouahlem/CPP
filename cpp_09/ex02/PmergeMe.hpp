#pragma once
  
#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <cstdlib> 
#include <climits>  
#include <cctype>    
#include <algorithm>
#include <utility>
class PmergeMe
{
    private :
                std::vector<int> _vector;
                std::deque<int> _deque;
    public :
            int parseInput(int ac, char **av);
            int checkInt(long resConvert);
            int isValidNumber(const std::string &str);
            int pushIfGood(double resConvert);
            void printNumber();

            void PrintVec();
            void vectorPrgm();
            void SortFourVec(std::vector<int> &vector, int start, int end);
            void MakePairsVec(std::vector<std::pair<int, int> > &myPairs);
            void SortPairsVec(std::vector<std::pair<int, int> >& VecPairs, int start, int end);
            void SortPairsMax(std::vector<std::pair<int, int> >& myPairs,int start, int end);
            void MergeSortPairsVec(std::vector<std::pair<int, int> >& VecPairs, int start, int middle, int end);
            // void InitJacobsthal(std::vector<std::pair<int,int> >& VecPairs, std::vector<int>& VecTab);
            void InsertJacob(std::vector<std::pair<int, int> > &VecPairs, std::vector<int>& VecTab);
            int BinarySearch(std::vector<int>& mainChain, int start, int end, int target);
            void InitJacobsthal(std::vector<std::pair<int, int> > &myPairs, std::vector<int>& jacobjacob) ;

};
