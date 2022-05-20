#include <iostream>
#include <algorithm>
#include <set>
#include <iterator>


template<typename T>
std::ostream& operator << (std::ostream& os, const std::set<T>& s);

int main(){
    std::set<size_t> set1 = { 1, 2, 3, 4, 5 };
    std::set<size_t> set2 = { 2, 4, 6, 7 };

    std::set<size_t> set_un;
    std::set<size_t> set_inter;

    set_union(begin(set1), end(set1), begin(set2), end(set2), inserter(set_un, end(set_un)));
    set_intersection(begin(set1), end(set1), begin(set2), end(set2), inserter(set_inter, end(set_inter)));

    std::cout << "sets for example\nX = { " << set1 << " }\nY = { " << set2 << " }" << std::endl;
    std::cout << "Result of union of sets: " << set_un << std::endl;
    std::cout << "Resul of intersection of sets: " << set_inter << std::endl;

}

template<typename T>
std::ostream& operator << (std::ostream& os, const std::set<T>& s)
{
    for (auto value : s)
    {
        os << value << " ";
    }
    return os;
}
