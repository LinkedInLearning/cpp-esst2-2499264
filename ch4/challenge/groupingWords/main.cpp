#include <iostream>
#include <vector>
#include <map>
#include <set>

// Gegeben ist ein Vector aus Anagrammen. Ein Anagramm ist ein Wort, welches durch umsortieren der Buchstaben sich ein anderes Wort ergibt.
// Baue aus dem gegebenen Vector eine Gruppe von Anagrammen auf, bei welchem die Wörter zusammenpassen.
// Zeigen diese Gruppe von Vectors an (die Anzeige-Reihenfolge ist egal).

int main()
{
    std::vector<std::string> strs = {"eat","tea","tan","ate","nat","bat"};
    // Ergebnis soll ungefähr so aussehen: { {"bat"}, {"nat","tan"}, {"ate","eat","tea"} }

    /*
    for( const auto &group : groups )
    {
        std::cout << "Group " << group.first << ":" << std::endl;
        for( const auto &word : group.second )
        {
            std::cout << word << " ";
        }
        std::cout << std::endl;
    }
*/
    return 0;
}
