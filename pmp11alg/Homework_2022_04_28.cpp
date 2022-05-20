#include <iostream>
#include <algorithm>
#include <set>
#include <iterator>


template<typename T>
std::ostream& operator << (std::ostream& os, const std::set<T>& s);

int main(){
    std::set<size_t> first_set = { 1, 2, 3, 4, 5 };
    std::set<size_t> second_set = { 2, 4, 6, 7 };

    std::set<size_t> set_un;
    std::set<size_t> set_inter;

    set_union(begin(first_set), end(first_set), begin(second_set), end(second_set), inserter(set_un, end(set_un)));
    set_intersection(begin(first_set), end(first_set), begin(second_set), end(second_set), inserter(set_inter, end(set_inter)));

    std::cout << "sets for example\nX = { " << first_set << " }\nY = { " << second_set << " }" << std::endl;
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
