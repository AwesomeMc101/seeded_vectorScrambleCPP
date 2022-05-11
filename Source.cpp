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

   
    std::vector<int> magicNumberList;
    for (int i = 0; i < vec1.size(); i++)
    {
        entry:
        int magicNumber = rand() % vec1.size();
        for (int z = 0; z < magicNumberList.size(); z++)
        {
            if (magicNumberList[z] == magicNumber)
            {
                goto entry;
            }

        }

        newVector[i] = vec1[magicNumber];
        magicNumberList.push_back(magicNumber);
    }      
    return newVector;
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
