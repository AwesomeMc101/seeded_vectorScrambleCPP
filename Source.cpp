/*
i wrote this function for studySkills & Lunar Guard Technologies


By AwesomeMc101

notes:
- i haven't tested with types like std::vector<int> so i'm not sure if it works with that but probably does!!
*/

#include <iostream>
#include <vector>
#include <iostream>
#include <string>
#include <vector>


std::vector<std::string> scrambleVector(std::vector<std::string> vec1)
{
    /*if you want to use a seed arg in the function call use this code here:
    
    srand(SEED_VAR_NAME);
    
    */
    
    //set vector size (decided to take the long route because you can figure it out if you have 1/584390 of a brain in how to do with 1 line lol)
    std::vector<std::string> newVector;
    for (int i = 0; i < vec1.size(); i++)
    {
        newVector.push_back(vec1[i]);
    }
    if (newVector.size() != vec1.size())
    {
        std::cout << "Scramble Error [vector size mismatch]";
        std::cout << "\nnewVector.size(): " << newVector.size();
        std::cout << "\nvec1.size(): " << vec1.size();
       
        return vec1;
    }

    
    std::vector<int> magicNumberList; //define list of magicNumbers so that we don't have duplicate reoccurrences of the same item.
    for (int i = 0; i < vec1.size(); i++) //forloop of the vector size to get every single item
    {
        //this entire code block is just to ensure we don't have duplicate occurrences
        entry: //reentry point (self-explanatory)
        int magicNumber = rand() % vec1.size(); // generate a random number inside the vector size 
        for (int z = 0; z < magicNumberList.size(); z++) //loop through every past magicNumber to make sure there isnt a double
            //also if there is a double it means that there will be a double occurrence so we CAN'T HAVE (double occurrence = one item deleted)
        {
            if (magicNumberList[z] == magicNumber) //if [selected item from vector] == currentMagicNumber
            {
                goto entry; //loop back to entry and regenerate randomNumber infinite times until we get a correct one
            }

        }

        newVector[i] = vec1[magicNumber]; //set value of newVector[index] to originalVector[magicNumber]
        magicNumberList.push_back(magicNumber); //push_back the magic number to the old vector so we can find it again in the loop above
    }      
    return newVector; //if you're reading this grow brain
}

int main()
{
  std::vector<std::string> coolVector;
  
  coolVector.push_back("hi!");
  coolVector.push_back("you");
  coolVector.push_back("are");
  coolVector.push_back("awesome");
  
  unsigned int seed = 506953;
  srand(seed); //this makes it have the same results every time, if you don't want to use seeding, do srand(time(NULL));
  
  coolVector = scrambleVector(coolVector);
  
  for(std::string i : coolVector)
  {
  std::cout << i << std::endl;
  }
  

}
