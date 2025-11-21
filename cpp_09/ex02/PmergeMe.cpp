#include "PmergeMe.hpp"

void printfError(std::string error)
{
    std::cout << "Error" << error << std::endl;
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
    return (0);
}


void PmergeMe::PrintVec()
{
    for (std::vector<int>::const_iterator it = _vector.begin(); it != _vector.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

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
        // if (a < b) 
        //     VecPairs.push_back(std::make_pair(b, a));
        // else 
        //     VecPairs.push_back(std::make_pair(a, b));
        i = i + 2;
        k = k + 2;
    }
}

// tri par insertion, appliqué à des paires et basé uniquement sur la valeur .first
void PmergeMe::SortPairsMax(std::vector<std::pair<int, int> >& VecPairs,int start, int end)
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

void PmergeMe::MergeSortPairsVec(std::vector<std::pair<int, int> >& VecPairs, int start, int middle, int end)
{
    std::vector<std::pair<int, int> > left;
    std::vector<std::pair<int, int> > right;

    left.assign(VecPairs.begin() + start, VecPairs.begin() + middle + 1);
    right.assign(VecPairs.begin() + middle + 1, VecPairs.begin() + end + 1);


    std::vector<std::pair<int, int> >::const_iterator iteratorLeft = left.begin();
    std::vector<std::pair<int, int> >::const_iterator iteratorRight = right.begin();

    // Fusion
    while (iteratorLeft != left.end())
    {
        if (iteratorRight == right.end())
        {
            VecPairs[start].first  = iteratorLeft->first;
            VecPairs[start].second = iteratorLeft->second;
            start++;
            iteratorLeft++;
        }
        else if (*iteratorLeft < *iteratorRight)
        {
            VecPairs[start].first  = iteratorLeft->first;
            VecPairs[start].second = iteratorLeft->second;
            start++;
            iteratorLeft++;
        }
        else
        {
            VecPairs[start].first  = iteratorRight->first;
            VecPairs[start].second = iteratorRight->second;
            start++;
            iteratorRight++;
        }
    }

    // Si il reste un éléments dans right
    while (iteratorRight != right.end())
    {
        VecPairs[start].first  = iteratorRight->first;
        VecPairs[start].second = iteratorRight->second;
        start++;
        iteratorRight++;
    }

}

void PmergeMe::SortPairsVec(std::vector<std::pair<int, int> >& VecPairs, int start, int end)
{
    int middle = 0;

    if(start < end)
    {
        if(end - start == 1)
        {
            SortPairsMax(VecPairs, start,end);
        }
        else
        {
            middle = start + ((end - start) / 2);
            SortPairsVec(VecPairs, start, middle);
            SortPairsVec(VecPairs, middle + 1, end);
            MergeSortPairsVec(VecPairs, start, middle, end);
        }
    }
}

void PmergeMe::InitJacobsthal(std::vector<std::pair<int,int> >& VecPairs, std::vector<int>& VecTab)
{
    int n = VecPairs.size();
    if (n == 0)
        return;

    std::vector<int> SeqJacob;
    SeqJacob.push_back(1);
    // n >= 3 avant d'ajouter 3 sinon on aura des valeurs > n
    if (n >= 3)
        SeqJacob.push_back(3);

    // construire la suite jusqu'à <= n
    while (true)
    {
        if (SeqJacob.size() < 2) break; // garde la sûreté
        int next = SeqJacob[SeqJacob.size()-1] + 2 * SeqJacob[SeqJacob.size()-2];
        if (next > n)
            break;
        SeqJacob.push_back(next);
    }

    VecTab.clear();

    // remplir VecTab à partir de SeqJacob (en veillant à rester <= n)
    for (size_t i = 0; i < SeqJacob.size(); ++i)
    {
        //revoir ****************************
        if (SeqJacob[i] <= n)
            VecTab.push_back(SeqJacob[i]);

        if (i + 1 < SeqJacob.size())
        {
            int start = SeqJacob[i + 1] - 1;
            int stop  = SeqJacob[i];
            if (start > n) start = n;
            int s = start;
            while (s > stop)
            {
                if (s <= n)
                    VecTab.push_back(s);
                s--;
            }
        }
    }

    // Ajouter les indices manquants (1..n) dans l'ordre décroissant comme avant
    for (int k = n; k >= 1; --k)
    {
        if (std::find(VecTab.begin(), VecTab.end(), k) == VecTab.end())
            VecTab.push_back(k);
    }

}

int PmergeMe::BinarySearch(std::vector<int>& FinalVec, int start, int end, int target) 
{
    if (FinalVec.empty())
        return 0;
    int middle = 0;

    while(end - start > 1)
    {
        middle = start + ((end - start) / 2);
        if (target > FinalVec[middle])
            start = middle +1; 
        if (target < FinalVec[middle])
            end = middle;         
    }
    if (target > FinalVec[start])
        start++;
    return start;
}

void PmergeMe::InsertJacob(std::vector<std::pair<int,int> >& VecPairs,std::vector<int>& VecTab)
{
    std::vector<int> FinalVec;  
    size_t i = 0;
    int NbrInserted = 0; 
    int lastOdd = 0;

    // Si le nombre d'éléments initial est impair, on conserve le dernier élément
    if (_vector.size() % 2 != 0)
        lastOdd = _vector.back();

    // On commence par remplir FinalVec avec les plus grands de chaque paire
    for (size_t i = 0; i < VecPairs.size(); ++i)
        FinalVec.push_back(VecPairs[i].first);

    // Insérer le premier “petit” élément b0
    FinalVec.insert(FinalVec.begin(), VecPairs[VecTab[i]-1].second);
    NbrInserted++;
    i++;

    // Boucle d’insertion selon l’ordre Jacobsthal
    while (i < VecTab.size())
    {
        int target = VecPairs[VecTab[i] - 1].second;
        int pos = BinarySearch(FinalVec, 0, VecTab[i] + NbrInserted - 1, target);
        FinalVec.insert(FinalVec.begin() + pos, target);
        NbrInserted++;
        i++;
    }

    // Si taille initiale impair, insérer le dernier élément
    if (_vector.size() % 2 != 0)
    {
        int pos = BinarySearch(FinalVec, 0, FinalVec.size() - 1, lastOdd);
        if (pos >= (int)FinalVec.size())
            FinalVec.push_back(lastOdd);
        else
            FinalVec.insert(FinalVec.begin() + pos, lastOdd);
    }

    _vector = FinalVec;
}

int PmergeMe::IfIsSortedVec()
{
    for (size_t i = 1; i < _vector.size(); ++i)
    {
        if (_vector[i - 1] > _vector[i]) 
            return 0;
    }
    return 1;
}

int PmergeMe::IfIsSortedDeque()
{
    for (size_t i = 1; i < _deque.size(); ++i)
    {
        if (_deque[i - 1] > _deque[i])
            return 0;
    }
    return 1;
}

void PmergeMe::myAlgo()
{
    std::vector<std::pair<int, int> > VecPairs;
    std::vector<int> vecTab;

    std::cout << "Before:  ";
    PrintVec();

    clock_t VecTimeToStart = clock();

    bool vecSorted = IfIsSortedVec();
    if(!vecSorted && _vector.size() > 1)
    {
        MakePairsVec(VecPairs);
        SortPairsVec(VecPairs, 0, VecPairs.size() - 1); 
        InitJacobsthal(VecPairs, vecTab);
        InsertJacob(VecPairs, vecTab);
    }
    clock_t VecTimeToEnd = clock();

    // ** Deque ** //

    clock_t DequeTimeToStart = clock();

    std::deque<std::pair<int, int> > DequePairs;
    std::deque<int> DequeTab;

    bool DequeSorted = IfIsSortedDeque();
    if(!DequeSorted && _deque.size() > 1)
    {
        MakePairsDeque(DequePairs);
        SortPairsDeque(DequePairs, 0, VecPairs.size() - 1); 
        InitJacobsthalDeque(DequePairs, DequeTab);
        InsertJacobDeque(DequePairs, DequeTab);
    }
    clock_t DequeTimeToEnd = clock();

    std::cout << "After:   ";
    PrintVec();
    double vectorTime = static_cast<double>(VecTimeToEnd - VecTimeToStart) / CLOCKS_PER_SEC * 1000000;
    double dequeTime = static_cast<double>(DequeTimeToEnd - DequeTimeToStart) / CLOCKS_PER_SEC * 1000000;
    
    std::cout << "Time to process a range of " << _vector.size()
    << " elements with std::vector : " << vectorTime << " us" << std::endl;
    std::cout << "Time to process a range of " << _deque.size()
    << " elements with std::deque : " << dequeTime << " us" << std::endl;
}



// ****************************************  DEQUE  ********************************************************
// ****************************************  DEQUE  ********************************************************
// ****************************************  DEQUE  ********************************************************
// ****************************************  DEQUE  ********************************************************
// ****************************************  DEQUE  ********************************************************
// ****************************************  DEQUE  ********************************************************
// ****************************************  DEQUE  ********************************************************
// ****************************************  DEQUE  ********************************************************



void PmergeMe::PrintDeque()
{
    for (std::deque<int>::const_iterator it = _deque.begin(); it != _deque.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

}

void PmergeMe::MakePairsDeque(std::deque<std::pair<int, int> > &DequePairs)
{
    int i = 0;
    size_t k = 1;
    size_t len = _deque.size();
    
    while(k < len)
    {
        int a = _deque[i];
        int b = _deque[k];

        if (a < b) 
            DequePairs.push_back(std::make_pair(b, a));
        else 
            DequePairs.push_back(std::make_pair(a, b));
        i = i + 2;
        k = k + 2;
    }
}

// tri par insertion, appliqué à des paires et basé uniquement sur la valeur .first
void PmergeMe::SortPairsMaxDeque(std::deque<std::pair<int, int> >& DequePairs,int start, int end)
{
    int nbrFirst;
    int nbrSecond;
    int k;
    int tmp;
    int tmpBis;
    
    for (int i = start + 1; i <= end; ++i)
    {
        nbrFirst = DequePairs[i].first;
        nbrSecond = DequePairs[i].second;
        k = i - 1;
        while (k >= start && nbrFirst < DequePairs[k].first)
        {
            tmp = DequePairs[k].first;
            tmpBis = DequePairs[k].second;
            DequePairs[k].first = nbrFirst;
            DequePairs[k].second = nbrSecond;
            DequePairs[k + 1].first = tmp;
            DequePairs[k + 1].second = tmpBis;
            k--;
        }
    }
}

void PmergeMe::MergeSortPairsDeque(std::deque<std::pair<int, int> >& DequePairs, int start, int middle, int end)
{
    std::deque<std::pair<int, int> > left;
    std::deque<std::pair<int, int> > right;

    left.assign(DequePairs.begin() + start, DequePairs.begin() + middle + 1);
    right.assign(DequePairs.begin() + middle + 1, DequePairs.begin() + end + 1);


    std::deque<std::pair<int, int> >::const_iterator iteratorLeft = left.begin();
    std::deque<std::pair<int, int> >::const_iterator iteratorRight = right.begin();

    // Fusion
    while (iteratorLeft != left.end())
    {
        if (iteratorRight == right.end())
        {
            DequePairs[start].first  = iteratorLeft->first;
            DequePairs[start].second = iteratorLeft->second;
            start++;
            iteratorLeft++;
        }
        else if (*iteratorLeft < *iteratorRight)
        {
            DequePairs[start].first  = iteratorLeft->first;
            DequePairs[start].second = iteratorLeft->second;
            start++;
            iteratorLeft++;
        }
        else
        {
            DequePairs[start].first  = iteratorRight->first;
            DequePairs[start].second = iteratorRight->second;
            start++;
            iteratorRight++;
        }
    }

    // Si il reste un éléments dans right
    while (iteratorRight != right.end())
    {
        DequePairs[start].first  = iteratorRight->first;
        DequePairs[start].second = iteratorRight->second;
        start++;
        iteratorRight++;
    }

}

void PmergeMe::SortPairsDeque(std::deque<std::pair<int, int> >& DequePairs, int start, int end)
{
    int middle = 0;

    if(start < end)
    {
        if(end - start == 1)
        {
            SortPairsMaxDeque(DequePairs, start,end);
        }
        else
        {
            middle = start + ((end - start) / 2);
            SortPairsDeque(DequePairs, start, middle);
            SortPairsDeque(DequePairs, middle + 1, end);
            MergeSortPairsDeque(DequePairs, start, middle, end);
        }
    }
}

void PmergeMe::InitJacobsthalDeque(std::deque<std::pair<int,int> >& DequePairs, std::deque<int>& DequeTab)
{
    int n = DequePairs.size();
    if (n == 0)
        return;

    std::deque<int> SeqJacob;
    SeqJacob.push_back(1);
    // n >= 3 avant d'ajouter 3 sinon on aura des valeurs > n
    if (n >= 3)
        SeqJacob.push_back(3);

    // construire la suite jusqu'à <= n
    while (true)
    {
        if (SeqJacob.size() < 2) break; // garde la sûreté
        int next = SeqJacob[SeqJacob.size()-1] + 2 * SeqJacob[SeqJacob.size()-2];
        if (next > n)
            break;
        SeqJacob.push_back(next);
    }

    DequeTab.clear();

    // remplir DequeTab à partir de SeqJacob (en veillant à rester <= n)
    for (size_t i = 0; i < SeqJacob.size(); ++i)
    {
        if (SeqJacob[i] <= n)
            DequeTab.push_back(SeqJacob[i]);

        if (i + 1 < SeqJacob.size())
        {
            int start = SeqJacob[i + 1] - 1;
            int stop  = SeqJacob[i];
            if (start > n) start = n;
            int s = start;
            while (s > stop)
            {
                if (s <= n)
                    DequeTab.push_back(s);
                s--;
            }
        }
    }

    // Ajouter les indices manquants (1..n) dans l'ordre décroissant comme avant
    for (int k = n; k >= 1; --k)
    {
        if (std::find(DequeTab.begin(), DequeTab.end(), k) == DequeTab.end())
            DequeTab.push_back(k);
    }

}

int PmergeMe::SearchWereIsertDeque(std::deque<int>& FinalDeque, int start, int end, int target) 
{
    if (FinalDeque.empty())
        return 0;
    int middle = 0;

    while(end - start > 1)
    {
        middle = start + ((end - start) / 2);
        if (target > FinalDeque[middle])
            start = middle +1; 
        if (target < FinalDeque[middle])
            end = middle;         
    }
    if (target > FinalDeque[start])
        start++;
    return start;
}

void PmergeMe::InsertJacobDeque(std::deque<std::pair<int,int> >& DequePairs,std::deque<int>& DequeTab)
{
    std::deque<int> FinalDeque;  
    size_t i = 0;
    int NbrInserted = 0; 
    int lastOdd = 0;

    // Si le nombre d'éléments initial est impair, on conserve le dernier élément
    if (_deque.size() % 2 != 0)
        lastOdd = _deque.back();

    // On commence par remplir FinalDeque avec les plus grands de chaque paire
    for (size_t i = 0; i < DequePairs.size(); ++i)
        FinalDeque.push_back(DequePairs[i].first);

    // Insérer le premier “petit” élément b0
    FinalDeque.insert(FinalDeque.begin(), DequePairs[DequeTab[i]-1].second);
    NbrInserted++;
    i++;

    // Boucle d’insertion selon l’ordre Jacobsthal
    while (i < DequeTab.size())
    {
        int target = DequePairs[DequeTab[i] - 1].second;
        int pos = SearchWereIsertDeque(FinalDeque, 0, DequeTab[i] + NbrInserted - 1, target);
        FinalDeque.insert(FinalDeque.begin() + pos, target);
        NbrInserted++;
        i++;
    }

    // Si taille initiale impair, insérer le dernier élément
    if (_deque.size() % 2 != 0)
    {
        int pos = SearchWereIsertDeque(FinalDeque, 0, FinalDeque.size() - 1, lastOdd);
        if (pos >= (int)FinalDeque.size())
            FinalDeque.push_back(lastOdd);
        else
            FinalDeque.insert(FinalDeque.begin() + pos, lastOdd);
    }

    _deque = FinalDeque;
}