#include "PmergeMe.hpp"


int main(int ac, char **av)
{  
    if (ac < 2)
    {
        std::cerr << "Error: no numbers provided" << std::endl;
        return 1;
    }
    PmergeMe pm;
    if(pm.parseInput(ac, av))
        return 1;
    pm.vectorPrgm();
    return 0;
}



// void PmergeMe::InsertJacob(std::vector<std::pair<int,int> >& VecPairs)
// {
//     std::vector<int> FinalVec;

//     // Étape 1 : ajouter tous les first (max de chaque paire)
//     for (size_t i = 0; i < VecPairs.size(); ++i)
//         FinalVec.push_back(VecPairs[i].first);

//     // Étape 2 : insérer tous les second (min de chaque paire) à leur place
//     for (size_t i = 0; i < VecPairs.size(); ++i)
//     {
//         int target = VecPairs[i].second;
//         int pos = BinarySearch(FinalVec, 0, FinalVec.size(), target);
//         FinalVec.insert(FinalVec.begin() + pos, target);
//     }

//     // Étape 3 : gérer le dernier élément si le vecteur initial est impair
//     if (_vector.size() % 2 != 0)
//     {
//         int lastOdd = _vector.back();
//         int pos = BinarySearch(FinalVec, 0, FinalVec.size(), lastOdd);
//         if (pos >= (int)FinalVec.size())
//             FinalVec.push_back(lastOdd);
//         else
//             FinalVec.insert(FinalVec.begin() + pos, lastOdd);
//     }

//     _vector = FinalVec;
// }