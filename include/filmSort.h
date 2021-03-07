#ifndef FILMSORT_H
#define FILMSORT_H

#include<vector>
#include<string>
#include <utility>

using std::vector;
using std::pair;
using std::string;


class filmSort
{
    public:
    filmSort(vector<pair<string, int>> _films);

    vector<pair<string, int>> SortList();

private:
    //create the struct which will hold all the infotmation required for sorting the films
    struct film {
        int id;
        string filmName;
        film* link;

        ~film() {}
    };
    film *head; //create a head node for use throughout functions

    //function which runs the bubble sort
    void sort();

    //called from sort to test two strings with each other
    bool testStrings(string s1, string s2);

    //called from sort to swap two films if required
    void swap(film *index1, film *index2);


};

#endif // FILMSORT_H
