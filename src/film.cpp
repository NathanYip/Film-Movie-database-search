#include "film.h"

Film::Film(){}

Film::RunTime::RunTime(){}

//method for returning the film data in class to a single string
std::string Film::toString(){
    std::string locationHolder, keywordHolder, languageHolder, crewHolder, materialHolder, outputString;

    languageHolder = addVectorsToString(languages);
    locationHolder = addVectorsToString(locations);
    keywordHolder = addVectorsToString(keywords);
    materialHolder = addMaterialsToString();
    crewHolder = addCrewToString();

    outputString = Support::intToString( filmID ) + ";" + title + ";" + summary
            + ";" + genre + ";" + releaseDate + ";" + Support::doubleToString(run.hours)
            + "," + Support::doubleToString(run.minutes) + "," + Support::doubleToString(run.seconds) +
            + ";" + locationHolder + ";" + languageHolder
            + ";" + keywordHolder + ";" + imageFilePath 
			+ ";" + crewHolder + ";" + projectStatus + ";" 
			+ Support::doubleToString(boxOfficeEarnings) + materialHolder;

    return outputString;
}

//adds materials to the string for outputting
std::string Film::addMaterialsToString(){
    std::string holder = "";
    for(unsigned int i = 0; i < materials.size(); i++){
        holder += materials[i]->toString();
        if(i != materials.size() - 1)
            holder += ",";
    }
    return holder;
}

void Film::tokenize(std::string input, std::vector<std::string>* vector)
{
	char * characters = new char[input.length() + 1];
	strcpy(characters, input.c_str());
	char previousCharacter = '\t';
	string token = "";
	for (char* c = characters; *c; *c++ ) {

		if ( (*c == ';' && previousCharacter == '/') || *c != ';' ) {
			token += *c;
		}
		else{
			vector->push_back(token);
			token = "";
		}

		previousCharacter = *c;
	}
	vector->push_back(token);

}

//when passed a vector<stirng> will return one sting combining all the values
std::string Film::addVectorsToString(std::vector<std::string>& name){
    std::string holder = "";
    for(unsigned int i = 0; i < name.size(); i++){
        holder += name[i];
        if(i != name.size() - 1){
            holder += ",";
        }
    }
    return holder;
}

//when called will return the correctly formatted string for the output Film::toString()
std::string Film::addCrewToString(){
    string holder;

    for(unsigned int i = 0; i < crew.size(); i++){
        holder += crew[i].first;
        holder += ":";
        holder += crew[i].second;
        if(i != crew.size() -1){
            holder += ",";
        }
    }

    return holder;
}




//take in a single string and unpack it to the class variables
void Film::fromString(string filmData){

	//TEST ignore any semicolons that follows a forward slash (eg->  /; )
	std::vector<std::string> tokens;
	Film::tokenize(filmData,&tokens); //splits string into tokens ignoring /;
	//END TEST

    //count the num of times string has been split
	for (int count = 0; count < tokens.size(); count++) {
		string StringToken = tokens.at(count);
		if (count == 0) {
			filmID = std::stoi(StringToken);
		}
		else if (count == 1) {
			title = StringToken;
		}
		else if (count == 2) {
			summary = StringToken;
		}
		else if (count == 3) {
			genre = StringToken;
		}
		else if (count == 4) {
			releaseDate = StringToken;
		}
		else if (count == 5) {
			std::istringstream runTimeSplit(StringToken);
			string runTimeToken;
			int runCount = 0;
			while (std::getline(runTimeSplit, runTimeToken, ',')) {
				switch (runCount) {
				case 0:
					run.hours = std::stod(runTimeToken);
					break;
				case 1:
					run.minutes = std::stod(runTimeToken);
					break;
				case 2:
					run.seconds = std::stod(runTimeToken);
					break;
				}
				runCount++;
			}
		}
		else if (count == 6) {
			std::istringstream vectorSplit(StringToken);
			string vectorToken;
			while (std::getline(vectorSplit, vectorToken, ',')) {
				locations.push_back(vectorToken);
			}

		}
		else if (count == 7) {
			std::istringstream vectorSplit(StringToken);
			string vectorToken;
			while (std::getline(vectorSplit, vectorToken, ',')) {
				languages.push_back(vectorToken);
			}
		}
		else if (count == 8) {
			std::istringstream vectorSplit(StringToken);
			string vectorToken;
			while (std::getline(vectorSplit, vectorToken, ',')) {
				keywords.push_back(vectorToken);
			}
		}
		else if (count == 9)
			imageFilePath = StringToken;
		else if (count == 10) {
			istringstream vectorSplit(StringToken);
			string vectorToken;
			while (getline(vectorSplit, vectorToken, ',')) {
				istringstream pairSplit(vectorToken);
				string pairToken;
				pair<string, string> pairHolder;
				int pairCount = 0;
				while (getline(pairSplit, pairToken, ':')) {
					if (pairCount == 0) {
						pairHolder.first = pairToken;
					}
					else if (pairCount == 1) {
						pairHolder.second = pairToken;
					}
					pairCount++;
				}
				crew.push_back(pairHolder);
			}
		}
		else if (count == 11)
			projectStatus = StringToken;
		else if (count == 12)
			boxOfficeEarnings = std::stod(StringToken);
		else if (count == 13) {
			istringstream vectorSplit(StringToken);
			string vectorToken;
			while (getline(vectorSplit, vectorToken, ',')) {
                FilmMaterials *fMaterials = new FilmMaterials();
                materials.push_back(fMaterials);
				int numOfMaterials = materials.size() - 1;
                materials[numOfMaterials]->fromString(vectorToken);
			}
		}
	}
}

//tests if the film is released based on released date and current date
//true: released
//false: not released
bool Film::isReleased(){
	bool released = false; //initialize to false
	
	//retrieve current time
	time_t currentDate = time(0);
	
	//test films release date based on current date

	//HACK
	releaseDate = "Tue May 1 2018";

	if(Support::dateStringToEpochSeconds(releaseDate) - currentDate <= 0){
		released = true;
		projectStatus = "Released";
	}
	
	return released;
}

//when passed a FilmMaterial instance add it to this films materials 
void Film::newMaterial(FilmMaterials *newMaterial){
    materials.push_back(newMaterial);
}

//pass the function a value, this will then check the status to ensure that the film is in "Now Showing"
//if now showing will set provided value as the weekly box office figures
void Film::newBoxOfficeEarnings(double value){
	
	string holder = projectStatus;
	
	for(unsigned int i =0; i < holder.length(); i++)
		holder[i] = tolower(holder[i]);
	
	if(holder == "now showing")
		boxOfficeEarnings = value;
}

//allows a film to have a material removed
//type should always work as there should be two of the same types. e.g: 'VHS' or 'Single-Sided-DVD'
void Film::removeMaterial(string materialType){
    //loop materials till requested removal material is found
    for(unsigned int i = 0; i < materials.size(); i++){
        if(materials[i]->type == materialType){
            materials.erase(materials.begin() + i); //remove the material at i if it matches provided type
        }
    }
}
