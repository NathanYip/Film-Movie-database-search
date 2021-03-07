#include "filmmaterials.h"

FilmMaterials::FilmMaterials(){}


//creates the string to output to the ASCI test files
std::string FilmMaterials::toString(){
    std::string audioHolder,bonusHolder, outputHolder;

    audioHolder = vecToString(audioFormat);
    bonusHolder = vecToString(bonusFeatures);

    outputHolder = type;

    if(audioHolder != "")
        outputHolder += "*" + audioHolder;
    if(frame != "")
        outputHolder += "*" + frame;
    if(bonusHolder != "")
        outputHolder += "*" + bonusHolder;


    return outputHolder;
}

//creates the strings for the vectors in this class ready to be added to the main output string
std::string FilmMaterials::vecToString(std::vector<std::string>& v){
    std::string holder = "";

    for(unsigned int i = 0; i < v.size(); i++){
        holder += v[i];

        if(i != v.size() - 1)
            holder+=":";
    }

    return holder;
}

//takes in the string from a file at startup, then unpackages that string into the class variables
void FilmMaterials::fromString(std::string data){
    int counter = 0;
    std::istringstream stringSplt(data);
    std::string token;
    while(std::getline(stringSplt, token, '*')){
        //count changes each loop, which should change the variables getting info
        switch(counter){
        case 0:
            type = token;
            break;
        case 1:{
            //add to vector audio formatting
            std::istringstream vectorSplit(token);
            std::string vectorToken;
            //loop through all the different audio options provided
            while(std::getline(vectorSplit, vectorToken, ':')){
                audioFormat.push_back(vectorToken);
            }
            break;
            }
        case 3:
            frame = token;
            break;
        case 4:{
            //bonus features vector
            std::istringstream vectorSplit(token);
            std::string vectorToken;
            //loop through all different bonus features provided
            while(std::getline(vectorSplit, vectorToken, ':')){
                bonusFeatures.push_back(vectorToken);
            }
            break;
            }
        }
        counter++;
    }
}
