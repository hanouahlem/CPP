#include "BitcoinExchange.hpp"



int main(int ac, char **av)
{
    if(ac != 2)
    {
        std::cout << "Usage: ./btc [File]" << std::endl;
        return 1;
    }
    
    return 0;
}



// Votre programme doit prendre un fichier en argument.
// Chaque ligne de ce fichier doit utiliser le format suivant: "date | valeur".
// Une date valide sera toujours au format "Année-Mois-Jour" (YYYY-MM-DD).
// Une valeur valide doit être soit un nombre à virgule flottante (float), ou un entier positif, compris entre 0 et 1000


// message Error

// "Error: bad input => <ligne>" (format invalide)
// "Error: invalid date => <date>"
// "Error: not a positive number." (valeur négative)
// "Error: too large a number." (valeur > 1000)
// "Error: no exchange rate available for date <date>" (pas de taux antérieur disponible)
// "Error: could not open file." (fichier introuvable)