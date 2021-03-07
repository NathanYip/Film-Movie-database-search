#include "filmSort.h"


filmSort::filmSort(vector<pair<string, int>> holder)
{
   //build the linked list from the provided vector
    film *temp = NULL, *newFilm = NULL;

        int numOfFilms = holder.size();

        //if there isn't more than 1 then their is no point in sorting the array so don't generate linked list
        if (numOfFilms > 1) {

            for (int i = 0; i < numOfFilms; i++) {
                newFilm = new film;
                newFilm->filmName = holder[i].first;
                newFilm->id = holder[i].second;

                if (i == 0) {//first value added to the linked list should also be set to head
                    head = newFilm;
                    temp = newFilm;
                }
                else {//if not head node set link value
                    temp->link = newFilm;
                    temp = newFilm;
                }


            }
            //after for loop has ended newFilm will also be set to the trailing node so set its link to NULL
            newFilm->link = NULL;
        }
        //else list stays null meaning no sorting takes place
}

void filmSort::sort(){
    film *i = head, *j;

    for (i = head; i != NULL; i = i->link) {
        for (j = i->link; j != NULL; j = j->link) {
            if (testStrings(i->filmName, j->filmName) == true) {
                swap(i, j);
            }
        }
    }
}

bool filmSort::testStrings(string s1, string s2){
    bool swap = false;

    //convert s1 to lowercase
    for (unsigned int i = 0; i < s1.length(); i++) {
        s1[i] = tolower(s1[i]);
    }

    //convert s2 to lower case
    for (unsigned int i = 0; i < s2.length(); i++) {
        s2[i] = tolower(s2[i]);
    }

    //now both strings are all in the same case
    //test for alphabetical order - if not in swap
    if (s1.compare(s2) > 0) {
        swap = true;
    }

    return swap;
}

void filmSort::swap(film *index1, film *index2){
    string tempstring = index1->filmName;
    int tempint = index1->id;
    index1->filmName = index2->filmName;
    index1->id = index2->id;
    index2->filmName = tempstring;
    index2->id = tempint;
}


vector<pair<string, int>> filmSort::SortList(){
    vector<pair<string, int>> holder;
    film *temp = head;

    //loop through the linked list untill nothing is left
    while (temp != NULL) {
        //push back temp into the vector for each node
        holder.push_back(pair<string, int>(temp->filmName, temp->id));

        //move temp up another node
        temp = temp->link;
    }

    //return the filled vector
    return holder;
}
