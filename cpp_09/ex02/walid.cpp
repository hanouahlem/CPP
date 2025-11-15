#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <unordered_set>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) : _vector(other._vector), _deque(other._deque) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        _vector = other._vector;
        _deque = other._deque;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

bool PmergeMe::isNumber(const std::string& str) const 
{
    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
        if (!isdigit(*it))
            return false;
    }
    return !str.empty();
}

void PmergeMe::parseArguments(int argc, char** argv) 
{
    for (int i = 1; i < argc; ++i) {
        std::string s(argv[i]);
        if (!isNumber(s)) 
            throw std::runtime_error("Error");
        long n = std::strtol(argv[i], NULL, 10);
        if (n < 0 || n > 2147483647) 
            throw std::runtime_error("Error");
        _vector.push_back(static_cast<int>(n)); 
        _deque.push_back(static_cast<int>(n));
    }
    isDoublon();
}

void PmergeMe::isDoublon() 
{
        std::unordered_set<int> seen;

    for (std::vector<int>::iterator it = _vector.begin(); it != _vector.end(); it++)
    {
        if (!seen.insert(*it).second)
            throw std::runtime_error("Error");
    }
}


void PmergeMe::printSequence(std::vector<int> &vec, std::string expression) const 
 {
    std::cout << expression << std::endl;

    for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << BLACK << *it << " " << RESET;
    }
    std::cout << std::endl;
}

void PmergeMe::printSequence(std::deque<int> &vec, std::string expression) const 
 {
    std::cout << expression << std::endl;

    for (std::deque<int>::const_iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << BLACK << *it << " " << RESET;
    }
    std::cout << std::endl;
}

void PmergeMe::printSequence(std::vector<std::pair<int, int> >& myPairs, std::string expression) const 
 {
    std::cout << expression << std::endl;

    for (std::vector<std::pair<int, int> >::const_iterator it = myPairs.begin(); it != myPairs.end(); ++it) {
        std::cout << BLACK << it->first << " " << std::endl << RESET;
    }
    std::cout << std::endl;
}


void PmergeMe::process(int argc, char** argv) 
{ 
    std::vector<std::pair<int, int> > myPairs;
    std::deque<std::pair<int, int> > myPairsdeq;
    std::vector<int> jacobjacob;
    std::deque<int> jacobjacobDEQ;


    parseArguments(argc, argv);
    printSequence(_vector, "Before: ");
    clock_t startVector = clock();

    if (_vector.size() <= 4)
        InsertVector(_vector, 0, _vector.size() -1);
    else
    {
        Compairvec(myPairs); // compare les pairs (3;9) -> MIN -> MAX
        SortVector(myPairs, 0, myPairs.size() - 1); // sort recursivement pour arrive a 2, et ensuite il remonte.
        GenerateJacobsthal(myPairs, jacobjacob); // 
        InsertJacob(myPairs,jacobjacob);

    }

    clock_t endVector = clock();
    printSequence(_vector, "After: ");

    printSequence(_deque, "Before: ");
    clock_t startDeque = clock();
    if (_deque.size() <= 4)
        Insertdeque(_deque, 0, _deque.size() -1);
    else
    {
        CompairDeq(myPairsdeq);
        Sortdeque(myPairsdeq, 0, myPairsdeq.size() - 1); 
        GenerateJacobsthal(myPairsdeq, jacobjacobDEQ); 
        InsertJacob(myPairsdeq, jacobjacobDEQ);
    }

    clock_t endDeque = clock();
    printSequence(_deque, "After: ");



    double vectorTime = static_cast<double>(endVector - startVector) / CLOCKS_PER_SEC * 1000000;
    double dequeTime = static_cast<double>(endDeque - startDeque) / CLOCKS_PER_SEC * 1000000;

    std::cout << "Time to process a range of " << _vector.size()
             << " elements with std::vector : " << vectorTime << " us" << std::endl;
    std::cout << "Time to process a range of " << _deque.size()
               << " elements with std::deque : " << dequeTime << " us" << std::endl;
}
void PmergeMe::InsertVector(std::vector<std::pair<int, int> >& myPairs,int start, int end)
{
    int key;
    int key2;
    int j;
    int tmp;
    int tmp2;
    for (int i = start + 1; i <= end; i++)   
    {
        key = myPairs[i].first; 
        key2 = myPairs[i].second; 
        j = i - 1; 
        while (j >= start && key < myPairs[j].first) 
        {
            tmp = myPairs[j].first; 
            tmp2 = myPairs[j].second; 
            myPairs[j].first = key;
            myPairs[j].second = key2;
            myPairs[j + 1].first = tmp; 
            myPairs[j + 1].second = tmp2; 
            j--;
        }
    }
   // printSequence(vec, "insert");
}
void PmergeMe::InsertVector(std::vector<int>& vec, int start, int end)
{
    int key;
    int j;
    int tmp;
    for (int i = start + 1; i <= end; i++)   
    {
        key = vec[i]; 
        j = i - 1; 
        while (j >= start && key < vec[j]) 
        {
            tmp = vec[j]; 
            vec[j] = key;
            vec[j + 1] = tmp; 
            j--;
        }
    }

   // printSequence(vec, "insert");
}

void PmergeMe::Insertdeque(std::deque<int>& deq, int start, int end)
{
    int key;
    int j;
    int tmp;
    for (int i = start + 1; i <= end; i++)   
    {
        key = deq[i]; 
        j = i - 1; 
        while (j >= start && key < deq[j]) 
        {
            tmp = deq[j]; 
            deq[j] = key; 
            deq[j + 1] = tmp; 
            j--;
        }
    }

}

void PmergeMe::MergeVector(std::vector<std::pair<int, int> >& myPairs, int start, int mid, int end) 
{
    std::vector<std::pair<int, int> > left;
    std::vector<std::pair<int, int> > right;

    left.assign(myPairs.begin() + start, myPairs.begin() + mid + 1);
    right.assign(myPairs.begin() + mid + 1, myPairs.begin() + end + 1);

    std::vector<std::pair<int, int> >::const_iterator itleft = left.begin();
    std::vector<std::pair<int, int> >::const_iterator itright = right.begin();

    while (itleft != left.end())
    {
        if (itright == right.end()) 
        {
            myPairs[start].first = itleft->first ;
            myPairs[start++].second = itleft->second ;
            itleft++;   
        }
        else if  (*itleft < *itright)
        {
           myPairs[start].first = itleft->first ;
            myPairs[start++].second = itleft->second ;
            itleft++;   
        }
        else
        {
            myPairs[start].first = itright->first ;
            myPairs[start++].second = itright->second ;
            itright++;  
        }
    }
    while(itright != right.end()) 
    {
        myPairs[start].first = itright->first ;
        myPairs[start++].second = itright->second ;
        itright++;
    }
}

void PmergeMe::MergeVector(std::vector<int>& vec, int start, int mid, int end) 
{
    std::vector<int> left;
    std::vector<int> right;

    left.assign(vec.begin() + start, vec.begin() + mid + 1);
    right.assign(vec.begin() + mid + 1, vec.begin() + end + 1);

    std::vector<int>::const_iterator itleft = left.begin();
    std::vector<int>::const_iterator itright = right.begin();
    

    while (itleft != left.end())
    {
        if (itright == right.end()) 
        {
            vec[start] = *itleft;
            itleft++;   
        }
        else if  (*itleft < *itright)
        {
            vec[start] = *itleft;
            itleft++;   
        }
        else
        {
            vec[start] = *itright;
            itright++;  
        }
    }
    while(itright != right.end()) 
    {
        vec[start] = *itright;
        itright++;
    }
}


void PmergeMe::Mergedeque(std::deque<int>& deq, int start, int mid, int end) 
{
    std::deque<int> left;
    std::deque<int> right;

    left.assign(deq.begin() + start, deq.begin() + mid + 1);
    right.assign(deq.begin() + mid + 1, deq.begin() + end + 1);

    std::deque<int>::const_iterator itleft = left.begin();
    std::deque<int>::const_iterator itright = right.begin();
    

    while (itleft != left.end())
    {
        if (itright == right.end()) 
        {
            deq[start] = *itleft;
            itleft++;   
        }
        else if  (*itleft < *itright)
        {
            deq[start] = *itleft;
            itleft++;   
        }
        else
        {
            deq[start] = *itright;
            itright++;  
        }
    }
    while(itright != right.end()) 
    {
        deq[start] = *itright;
        itright++;
    }
}

void PmergeMe::SortVector(std::vector<std::pair<int, int> >& myPairs, int start, int end)
{
    int mid = 0;

    if (start < end) // 8 87 6 5 3 4 
    {
        if (end - start == 1)
            InsertVector(myPairs, start,end);
        else 
        {   
            mid = start + ((end - start) / 2);
            SortVector(myPairs, start, mid);
            SortVector(myPairs, mid + 1, end);
            MergeVector(myPairs, start, mid, end);
        }
    }
}

void PmergeMe::SortVector(std::vector<int>& vec, int start, int end) // revoir tout les appels de chatgpt
{
    int mid = 0; 
    if (start < end)
    {
        if (end - start == 1)
            InsertVector(vec, start,end);
        else 
        {   
            mid = start + ((end - start) / 2);
            SortVector(vec, start, mid);
            SortVector(vec, mid + 1, end);
            MergeVector(vec, start, mid, end);
        }
    }
}
void PmergeMe::Sortdeq(std::deque<int> &deq, int start, int end)
{
    int mid = 0; 
    if (start < end)
    {
        if (end - start == 1)
            Insertdeque(deq, start,end);
        else 
        {   
            mid = start + ((end - start) / 2);
            Sortdeq(deq, start, mid);
            Sortdeq(deq, mid + 1, end);
            Mergedeque(deq, start, mid, end);
        }
    }
}

void PmergeMe::Compairvec(std::vector<std::pair<int, int> > &myPairs) //vector first ! second -> first fort second les faibles.
{
    
    int i = 0;
    size_t j = 1;
    while (j < _vector.size()) 
    {
        if (_vector[i] < _vector[j])
            myPairs.emplace_back(_vector[j], _vector[i]);
        else
            myPairs.emplace_back(_vector[i], _vector[j]);
        j = j + 2;
        i = i + 2;
    }

}

void PmergeMe::GenerateJacobsthal(std::vector<std::pair<int, int> > &myPairs, std::vector<int>& jacobjacob) 
{
    size_t i;
    size_t j;
    int tmp;
    int tmp2;

    jacobjacob.push_back(1);
    jacobjacob.push_back(3);
    std::vector<int>jacobpure;
    for (size_t i = 2; i <= myPairs.size(); i++) 
    {

        if (jacobjacob[i - 1] + 2 * jacobjacob[i - 2] <= (int)myPairs.size())
           jacobjacob.push_back(jacobjacob[i - 1] + 2 * jacobjacob[i - 2]);
        else
            break;
    }
    i = 1;
    j = 2;
    jacobpure = jacobjacob;
    while(1)
    {
        if (i < jacobpure.size())
        {
            tmp = jacobpure[i - 1]; 
            tmp2 = jacobpure[i]; 
        }
        else
            break;
        while(tmp < tmp2 -1)
        {
            tmp2--;
            jacobjacob.insert(jacobjacob.begin() + j, tmp2); 
            j++;
        }
        j++;
        i++;
    }
    i = myPairs.size();
    if (myPairs.size() < 3)
        jacobjacob.erase(jacobjacob.begin() + 1);
    std::vector<int>::iterator it2 = jacobjacob.begin();
    std::vector<int>::iterator it = jacobjacob.end() -1;

    while(*it < (int)i) 
    {
        while(it2 != jacobjacob.end())
        {
            if ((int)i == *it2)
                break;
            it2++; 
        }
        if (it2 == jacobjacob.end())
            jacobjacob.push_back(i);
        else
            break;
        i--;
        it2 = jacobjacob.begin();
        it--;
    }

}
void PmergeMe::InsertJacob(std::vector<std::pair<int, int> > &myPairs, std::vector<int>& jacobjacob)
{
    int countInsert;
    std::vector<int> mainChain;
    size_t i;
    int pos;
    int last;
    int forindice = 1; 
    countInsert = 0;
    i = 0;


    printSequence(jacobjacob, "JACOB");
    if (_vector.size() % 2 != 0)
        last = _vector[_vector.size() -1];

    for (size_t i = 0; i < myPairs.size(); ++i)
    {
        mainChain.push_back(myPairs[i].first);
    }
    mainChain.insert(mainChain.begin(),  myPairs[jacobjacob[i] -1].second); //insert b_0 direct.
    countInsert++;
    i++;
    while(i < jacobjacob.size())
    {
        pos = BinarySearch(mainChain, 0, jacobjacob[i] + countInsert - forindice, myPairs[jacobjacob[i] -1].second);
        mainChain.insert(mainChain.begin() + pos,  myPairs[jacobjacob[i] -1].second);

        countInsert++;
        i++;
    }
    if (_vector.size() % 2 != 0)
    {
        pos = BinarySearch(mainChain, 0, mainChain.size(), last);
        if (pos > (int)mainChain.size())
            mainChain.push_back(last);
        else
            mainChain.insert(mainChain.begin() + pos,  last);
    }
    _vector = mainChain;
}
int PmergeMe::BinarySearch(std::vector<int>& mainChain, int start, int end, int target) 
{
    int mid = 0;

    while(end - start > 1)
    {
        mid = start + ((end - start) / 2);
        if (target > mainChain[mid])
            start = mid +1; 
        if (target < mainChain[mid])
            end = mid;         
    }
    if (target > mainChain[start])
        start++;
    return start;
}
// --- - - - - - - ------------------------------------ --- ---------- - - - - - - -DEQUE---____ _ _ ___--------------- - - - - --- - ---- - - ---  - ----- -- --- - - ---
// --- - - - - - - ------------------------------------ --- ---------- - - - - - - -DEQUE---____ _ _ ___--------------- - - - - --- - ---- - - ---  - ----- -- --- - - ---
// --- - - - - - - ------------------------------------ --- ---------- - - - - - - -DEQUE---____ _ _ ___--------------- - - - - --- - ---- - - ---  - ----- -- --- - - ---
// --- - - - - - - ------------------------------------ --- ---------- - - - - - - -DEQUE---____ _ _ ___--------------- - - - - --- - ---- - - ---  - ----- -- --- - - ---
// --- - - - - - - ------------------------------------ --- ---------- - - - - - - -DEQUE---____ _ _ ___--------------- - - - - --- - ---- - - ---  - ----- -- --- - - ---
// --- - - - - - - ------------------------------------ --- ---------- - - - - - - -DEQUE---____ _ _ ___--------------- - - - - --- - ---- - - ---  - ----- -- --- - - ---


void PmergeMe::Insertdeque(std::deque<std::pair<int, int> >& myPairs,int start, int end)
{
    int key;
    int key2;
    int j;
    int tmp;
    int tmp2;
    for (int i = start + 1; i <= end; i++)   
    {
        key = myPairs[i].first; 
        key2 = myPairs[i].second; 
        j = i - 1; 
        while (j >= start && key < myPairs[j].first) 
        {
            tmp = myPairs[j].first; 
            tmp2 = myPairs[j].second;
            myPairs[j].first = key; 
            myPairs[j].second = key2;
            myPairs[j + 1].first = tmp; 
            myPairs[j + 1].second = tmp2; 
            j--;
        }
    }
}

void PmergeMe::Mergedeque(std::deque<std::pair<int, int> >& myPairs, int start, int mid, int end) 
{
    std::deque<std::pair<int, int> > left;
    std::deque<std::pair<int, int> > right;

    left.assign(myPairs.begin() + start, myPairs.begin() + mid + 1);
    right.assign(myPairs.begin() + mid + 1, myPairs.begin() + end + 1);

    std::deque<std::pair<int, int> >::const_iterator itleft = left.begin();
    std::deque<std::pair<int, int> >::const_iterator itright = right.begin();

    while (itleft != left.end())
    {
        if (itright == right.end()) 
        {
            myPairs[start].first = itleft->first ;
            myPairs[start++].second = itleft->second ;
            itleft++;   
        }
        else if  (*itleft < *itright)
        {
           myPairs[start].first = itleft->first ;
            myPairs[start++].second = itleft->second ;
            itleft++;   
        }
        else
        {
            myPairs[start].first = itright->first ;
            myPairs[start++].second = itright->second ;
            itright++;  
        }
    }
    while(itright != right.end()) 
    {
        myPairs[start].first = itright->first ;
        myPairs[start++].second = itright->second ;
        itright++;
    }
}

void PmergeMe::Sortdeque(std::deque<std::pair<int, int> >& myPairs, int start, int end)
{
    int mid = 0;

    if (start < end)
    {
        if (end - start == 1)
            Insertdeque(myPairs, start,end);
        else 
        {   
            mid = start + ((end - start) / 2);
            Sortdeque(myPairs, start, mid);
            Sortdeque(myPairs, mid + 1, end);
            Mergedeque(myPairs, start, mid, end);
        }
    }
}

void PmergeMe::CompairDeq(std::deque<std::pair<int, int> > &myPairs)
{
    
    int i = 0;
    size_t j = 1;
    while (j < _deque.size()) 
    {
        if (_deque[i] < _deque[j])
            myPairs.push_back(std::make_pair(_deque[j], _deque[i]));
        else
            myPairs.push_back(std::make_pair(_deque[i], _deque[j]));

        j = j + 2;
        i = i + 2;
    }

}

void PmergeMe::GenerateJacobsthal(std::deque<std::pair<int, int> > &myPairs, std::deque<int>& jacobjacob) 
{
    size_t i;
    size_t j;
    int tmp;
    int tmp2;
    
    jacobjacob.push_back(1);
    jacobjacob.push_back(3);
    std::deque<int>jacobpure;
    for (size_t i = 2; i <= myPairs.size(); i++) 
    {

        if (jacobjacob[i - 1] + 2 * jacobjacob[i - 2] <= (int)myPairs.size())
           jacobjacob.push_back(jacobjacob[i - 1] + 2 * jacobjacob[i - 2]);
        else
            break;
    }
    i = 1;
    j = 2;
    jacobpure = jacobjacob;
    while(1)
    {
        if (i < jacobpure.size())
        {
            tmp = jacobpure[i - 1]; 
            tmp2 = jacobpure[i]; 
        }
        else
            break;
        while(tmp < tmp2 -1)
        {
            tmp2--;
            jacobjacob.insert(jacobjacob.begin() + j, tmp2); 
            j++;
        }
        j++;
        i++;
    }
    i = myPairs.size();
    if (myPairs.size() < 3)
        jacobjacob.erase(jacobjacob.begin() + 1);
    std::deque<int>::iterator it2 = jacobjacob.begin();
    std::deque<int>::iterator it = jacobjacob.end() -1;

    while(*it < (int)i) 
    {
        while(it2 != jacobjacob.end())
        {
            if ((int)i == *it2)
                break;
            it2++; 
        }
        if (it2 == jacobjacob.end())
            jacobjacob.push_back(i);
        else
            break;
        i--;
        it2 = jacobjacob.begin();
        it--;
    }

}

void PmergeMe::InsertJacob(std::deque<std::pair<int, int> > &myPairs, std::deque<int>& jacobjacob)
{
    int countInsert;
    std::deque<int> mainChain;
    size_t i;
    int pos;
    int last;
    int forindice = 1; 
    countInsert = 0;
    i = 0;

    if (_deque.size() % 2 != 0)
        last = _deque[_deque.size() -1];

    for (size_t i = 0; i < myPairs.size(); ++i)
    {
        mainChain.push_back(myPairs[i].first);
    }
    mainChain.insert(mainChain.begin(),  myPairs[jacobjacob[i] -1].second); 
    countInsert++;
    i++;
    while(i < jacobjacob.size())
    {
        pos = BinarySearch(mainChain, 0, jacobjacob[i] + countInsert - forindice, myPairs[jacobjacob[i] -1].second);
        mainChain.insert(mainChain.begin() + pos,  myPairs[jacobjacob[i] -1].second);

        countInsert++;
        i++;
    }

    if (_deque.size() % 2 != 0)
    {
        pos = BinarySearch(mainChain, 0, mainChain.size(), last);
       if (pos > (int)mainChain.size())
            mainChain.push_back(last);
        else
            mainChain.insert(mainChain.begin() + pos,  last);
    }
    _deque = mainChain;
}
int PmergeMe::BinarySearch(std::deque<int>& mainChain, int start, int end, int target) //hendek siya pas le chiffre.
{
    int mid = 0;

    while(end - start > 1)
    {
        mid = start + ((end - start) / 2);
        if (target > mainChain[mid])
            start = mid +1; 
        if (target < mainChain[mid])
            end = mid;         
    }
    if (target > mainChain[start])
        start++;
    return start;
}