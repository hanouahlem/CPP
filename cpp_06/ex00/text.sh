
fonction de convertion:
(std::stoi, std::stof, std::stod)


conversion chaine en int :

std::string str = "42";
try 
{
    int value = std::stoi(str);
    // Utilise value
}
catch (std::exception &e) 
{
    // La conversion a échoué 
}



conversion d une chaine en double :

std::string str = "4.2f";
try
{
    // Enlève le 'f' si présent
    if (str.back() == 'f')
        str.pop_back();
    float value = std::stof(str);
    // Utilise value
} catch (std::exception &e) {
    // La conversion a échoué
}


conversion d une chaine en char :

std::string str = "'a'";
if (str.length() == 3 && str.front() == '\'' && str.back() == '\''   ')
{
    char value = str[1];
    // Utilise value
} else 
{
    // Pas un littéral char valide
}


conversion des pseudo-litteraux ('nan', inf, etc.)
'nanf', "nan", "+inff", tu peux comparer la chaîne directement et utiliser :

Pour float : std::numeric_limits<float>::quiet_NaN(), INFINITY
Pour double : std::numeric_limits<double>::quiet_NaN(), INFINITY


if (str == "nan" || str == "nanf") {
    double d = std::numeric_limits<double>::quiet_NaN();
    float f = std::numeric_limits<float>::quiet_NaN();
    // Affiche nan
}
if (str == "+inf" || str == "+inff") {
    double d = INFINITY;
    float f = INFINITY;
    // Affiche +inf
}


void ScalarConverter::convert(const std::string &literal)
{

	for(int i = 0; (size_t)i < literal.length(); i++)
	{
		if (!std::isdigit(literal[i]) && literal[i] != '.' && literal[i] != 'f')
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
 			if (literal == "nan" || literal == "nanf")
 				std::cout << "float: nanf" << std::endl;
 			else if (literal == "-inf" || literal == "+inf"
 				|| literal == "-inff" || literal == "+inff")
 				std::cout << "float: " << literal[0] << "inff" << std::endl;
			else
 				std::cout << "float: impossible" << std::endl;
 			if (literal == "nan" || literal == "nanf")
				std::cout << "double: nan" << std::endl;
 			else if (literal == "-inf" || literal == "+inf"
 				|| literal == "-inff" || literal == "+inff")
 				std::cout << "double: " << literal[0] << "inf" << std::endl;
 			else
 				std::cout << "double: impossible" << std::endl;
 			return ;
 		}
 	}
 	// CHAR
 	try 
    {
 	 	char c = static_cast<char>(std::atoi(literal.c_str()));
 		if (std::isprint(c))
 			std::cout << "char: '" << c << "'" << std::endl;
 		else
 			std::cout << "char: Non displayable" << std::endl;
 	} catch (std::exception &e) {
 		std::cout << "char: impossible" << std::endl;
 	}
     // INT
     try {
         int i = std::atoi(literal.c_str());
         std::cout << "int: " << i << std::endl;
     } catch (std::exception &e) {
         std::cout << "int: impossible" << std::endl;
     }
     // FLOAT
     try {
         float f = std::atof(literal.c_str());
         std::cout << "float: " << f << "f" << std::endl;
     } catch (std::exception &e) {
         std::cout << "float: impossible" << std::endl;
     }
     // DOUBLE
     try {
         double d = std::atof(literal.c_str());
         std::cout << "double: " << d << std::endl;
     } catch (std::exception &e) {
         std::cout << "double: impossible" << std::endl;
     }
 }