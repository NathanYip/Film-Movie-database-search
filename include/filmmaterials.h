#ifndef FILMMATERIALS_H
#define FILMMATERIALS_H

//class to hold the materials for each film
/*to add a meterial to a film:
 * 1) create an instance of this class
 * 2) Then add to the variables all the info you want for the material
 * 3) then in the Film instance you want to add it to call the method 'newMaterial(Instance_Of_This_Class);'
 *
 * To remove
 * 1) retrieve the type string of the material you wish to remove
 * 2)in the Film class instence you want to remove it from call method 'removeMaterial(type_string)'
*/
#include "support.h"

#include <vector>
#include <string>
#include <sstream>

class FilmMaterials{
public:
    FilmMaterials();

    //variables for films Materials
    std::string type;//e.g.(Double-Sided-DVD, Single-Sided-DVD, VHS...)
	
    std::vector<std::string> audioFormat;
    std::string frame;
    std::vector<std::string> bonusFeatures;

    //functions to interact with the film class
    std::string toString(); //sends the info as a string to film class for storage
    void fromString(std::string data); //retrieves data to be stored for film class

private:
    //function to turn this classes vectors into strings for storage output
    std::string vecToString(std::vector<std::string>& v);

};

#endif // FILMMATERIALS_H
