#ifndef FILM_H
#define FILM_H

#include <vector>
#include <string>
#include <sstream>
#include<iostream>
#include <QDate>
#include <ctime>

#include "support.h"
#include "infocontainer.h"
#include "filmmaterials.h"

using std::vector;
using std::string;
using std::pair;

class Film : public InfoContainer
{
    class RunTime
    {
    public:
        RunTime();

        double seconds;
        double minutes;
        double hours;
    };
public:

    Film();

    //method for returning the film data in class to a single string
    std::string toString();

    //take in a single string and unpack it to the class variables
    void fromString(std::string filmData);
	
	//function which will check the current date with the films release date to test if released or not
	bool isReleased();

    //function to add new material
    void newMaterial(FilmMaterials *newMaterial);
    //function to remove existing material
    void removeMaterial(string materialType);
	//function to change box office earnings
	void newBoxOfficeEarnings(double value);

    //film required variables
    //public as required to be easily accessible from other classes
    int filmID;
    string title;
    string summary;
    string genre;
    //TODO find a way to convert this to a regular date
    string releaseDate;
    RunTime runtime;
    vector<string> locations;
    vector<string> languages;
    vector<string> keywords;
    string imageFilePath;
	//left string crew job - right string crew members name
    vector<pair<string,string>> crew;

    //variables for the film materials
    string projectStatus;
    double boxOfficeEarnings;
    vector<FilmMaterials*> materials;

protected:
	void tokenize(std::string, std::vector<std::string>*);

private:

    //Class the handles basic time functions for the runtime of the movie


    //used to help the toStirng function put the vectors into the main string
    std::string addVectorsToString(std::vector<std::string>& name);

    //add the crew infromation into a string ready to be added to the main output string
    std::string addCrewToString();

    //creates the string to send to storage for the films materials
    std::string addMaterialsToString();

    //declare the instance of the runtime class for the film class to use
    RunTime run;
};

#endif // FILM_H
