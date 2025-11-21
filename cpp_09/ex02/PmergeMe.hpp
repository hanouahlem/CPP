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

            void PrintVec();
            void myAlgo();
    
            void MakePairsVec(std::vector<std::pair<int, int> > &myPairs);
            void SortPairsVec(std::vector<std::pair<int, int> >& VecPairs, int start, int end);
            void SortPairsMax(std::vector<std::pair<int, int> >& myPairs,int start, int end);
            void MergeSortPairsVec(std::vector<std::pair<int, int> >& VecPairs, int start, int middle, int end);
            void InitJacobsthal(std::vector<std::pair<int,int> >& VecPairs, std::vector<int>& VecTab);
            void InsertJacob(std::vector<std::pair<int, int> > &VecPairs, std::vector<int>& VecTab);
            int BinarySearch(std::vector<int>& mainChain, int start, int end, int target);
            int IfIsSortedVec();
            // void Printchaine();

            void MakePairsDeque(std::deque<std::pair<int, int> > &myPairs);
            void SortPairsDeque(std::deque<std::pair<int, int> >& DequePairs, int start, int end);
            void SortPairsMaxDeque(std::deque<std::pair<int, int> >& myPairs,int start, int end);
            void MergeSortPairsDeque(std::deque<std::pair<int, int> >& DequePairs, int start, int middle, int end);
            void InitJacobsthalDeque(std::deque<std::pair<int,int> >& DequePairs, std::deque<int>& DequeTab);
            void InsertJacobDeque(std::deque<std::pair<int, int> > &DequePairs, std::deque<int>& DequeTab);
            int SearchWereIsertDeque(std::deque<int>& mainChain, int start, int end, int target);
            int IfIsSortedDeque();
            void PrintDeque();




};
