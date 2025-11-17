#include "PmergeMe.hpp"

void printfError(std::string error)
{
    std::cout << "Error" << error << std::endl;
}

void PmergeMe::printNumber()
{
    std::cout << "Vector: ";
    for (size_t i = 0; i < _vector.size(); ++i)
        std::cout << _vector[i] << " ";
    std::cout << std::endl;

    std::cout << "Deque:  ";
    for (size_t i = 0; i < _deque.size(); ++i)
        std::cout << _deque[i] << " ";
    std::cout << std::endl;
}

int PmergeMe::checkInt(long resConvert)
{
    if (resConvert < 0)
        return (printfError(" : no negative number"), 1);
    if (resConvert > INT_MAX)
        return (printfError(" : value too large "), 1);
    return (0);
}

int PmergeMe::isValidNumber(const std::string &str)
{
    if (str.empty())
        return 1;
    for (size_t i = 0; i < str.size(); i++)
    {
        if (!std::isdigit(str[i]))
            return 1;
    }
    return 0;
}
bool contains_in_vector(const std::vector<int>& v, int x)
{
    return std::find(v.begin(), v.end(), x) != v.end();
}

int PmergeMe::pushIfGood(double resConvert)
{
    if (contains_in_vector(_vector, resConvert )) 
    {
        std::cerr << "Error: duplicate value " << resConvert << std::endl;
        return 1;
    }
    _vector.push_back(static_cast<int>(resConvert));
    _deque.push_back(static_cast<int>(resConvert));
    return(0);
}


int PmergeMe::parseInput(int ac, char **av)
{
    for (int i = 1; i < ac; ++i)
    {
        std::string str;
        str = av[i];
        if (isValidNumber(str))
            return (printfError(" : Invalid arguments"), 1);
        long resConvert;
        resConvert = std::strtol(av[i], NULL, 10);
        if (checkInt(resConvert))
            return (1);
        if(pushIfGood(resConvert))
            return (1);
    }
    printNumber();
    return (0);
}


void PmergeMe::PrintVec()
{
    for (std::vector<int>::const_iterator it = _vector.begin(); it != _vector.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

}

void PmergeMe::SortFourVec(std::vector<int> &vector, int start, int end)
{
    int i;
    int j;
    int nbr;
    int tmp;

    i = start + 1;
    while(i <= end)
    {
        nbr = vector[i];
        j = i -1;
        while(j >= start && nbr < vector[j])
        {
            tmp = vector[j];
            vector[j] = nbr;
            vector [j + 1] = tmp;
            j--;
        }
        i++;
    }
}
void PmergeMe::MakePairsVec(std::vector<std::pair<int, int> > &VecPairs)
{
    int i = 0;
    size_t k = 1;
    size_t len = _vector.size();
    
    while(k < len)
    {
        int a = _vector[i];
        int b = _vector[k];

        if (a < b) {
            VecPairs.push_back(std::make_pair(b, a));
            std::cout << "pair indices (" << i << "," << k << ") : (" << b << "," << a << ")" << std::endl;
        } else {
            VecPairs.push_back(std::make_pair(a, b));
            std::cout << "pair indices (" << i << "," << k << ") : (" << a << "," << b << ")" << std::endl;
        }
        i = i + 2;
        k = k + 2;
    }
}
// tri par insertion, appliqué à des paires et basé uniquement sur la valeur .first
void PmergeMe::SortPairsMaxMin(std::vector<std::pair<int, int> >& VecPairs,int start, int end)
{
    int nbrFirst;
    int nbrSecond;
    int k;
    int tmp;
    int tmpBis;
    
    for (int i = start + 1; i <= end; ++i)
    {
        nbrFirst = VecPairs[i].first;
        nbrSecond = VecPairs[i].second;
        k = i - 1;
        while (k >= start && nbrFirst < VecPairs[k].first)
        {
            tmp = VecPairs[k].first;
            tmpBis = VecPairs[k].second;
            VecPairs[k].first = nbrFirst;
            VecPairs[k].second = nbrSecond;
            VecPairs[k + 1].first = tmp;
            VecPairs[k + 1].second = tmpBis;
            k--;
        }
    }
}

void PmergeMe::SortPairsVec(std::vector<std::pair<int, int> >& VecPairs, int start, int end)
{
    int middle = 0;

    if(start < end)
    {
        if(end - start == 1)
        {
            SortPairsMaxMin(VecPairs, start,end);
            std::cout << "  après MakePairsMaxMin: ";
            for (int idx = start; idx <= end; ++idx)
                std::cout << "[" << VecPairs[idx].first << "," << VecPairs[idx].second << "] ";
            std::cout << std::endl;

        }
        else
        {
            middle = start + ((end - start) / 2);
            std::cout << "  division en [" << start << "," << middle << "] et ["
                << (middle + 1) << "," << end << "]" << std::endl;
            SortPairsVec(VecPairs, start, middle);
            std::cout << "  retour gauche [" << start << "," << middle << "] état: ";
            for (int idx = start; idx <= middle; ++idx)
                std::cout << "(" << VecPairs[idx].first << "," << VecPairs[idx].second << ") ";
            std::cout << std::endl;
            SortPairsVec(VecPairs, middle + 1, end);
            std::cout << "  retour droit [" << (middle + 1) << "," << end << "] état: ";
            for (int idx = middle + 1; idx <= end; ++idx)
            std::cout << "(" << VecPairs[idx].first << "," << VecPairs[idx].second << ") ";
            std::cout << std::endl;

            // MergePairsVec();

        }
    }
}

void PmergeMe::vectorPrgm()
{
    std::vector<std::pair<int, int> > VecPairs;
    std::vector<int> vecTab;

    std::cout << "Before: " << std::endl;
    PrintVec();

    // clock_t VecTimeToStart = clock();
    if(_vector.size() <= 4)
        SortFourVec(_vector, 0, _vector.size() - 1);
    else
    {
        MakePairsVec(VecPairs);
        SortPairsVec(VecPairs, 0, VecPairs.size() - 1);
    }
    std::cout << "After: " << std::endl;
    PrintVec();
}
