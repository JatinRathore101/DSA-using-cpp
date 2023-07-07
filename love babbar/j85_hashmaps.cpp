#include<bits/stdc++.h>
using namespace std;

/*
https://www.geeksforgeeks.org/traversing-a-map-or-unordered_map-in-cpp-stl/

We can traverse map and unordered_map using 4
different ways  which are as follows:

-Using a ranged based for loop
-Using begin() and end()
-Using Iterators
-Using std::for_each and lambda function
*/


/* //HASHMAPS//
bucket array, hash functions {hash code,compression function,
collision, uniform distribution},collision handling {open
hashing, closed adressing}
*/

void disp(unordered_map<string,int> &hMap)
{
    for(auto it:hMap){cout<<it.first<<"  "<<it.second<<endl;}
    cout<<endl<<endl;
}

int main()
{
    unordered_map<string,int> hMap;

    // insertion
    hMap.insert({"Jatin",21});
    hMap["Sagnik"]=42;
    // hMap.at("Dhruv")=11; // gives error
    hMap["Dhruv"]=11;
    hMap.insert({"Gokul",3});
    hMap.insert({"Dev",7});
    hMap.insert({"Dars",2});
    hMap.insert({"James",22});
    hMap.insert({"James",22});
    hMap.insert({"James",22});

    // displaying
    disp(hMap);

    // updation
    hMap["James"]=25;
    hMap.at("Jatin")=22;
    hMap.at("Dev")=11;
    disp(hMap);




    // cout<<hMap.at("Ram"); // this gives error (termination error) as entry with key "Ram" does not exist in map
    cout<<" [] and .at() "<<endl<<hMap["Ram"]<<endl; // but this statement creates an entry with key "Ram" and assigns value 0 to it
    cout<<hMap.at("Ram")<<endl<<endl;


    // count("key") // used to check presence of an entry with "key"
    cout<<" .count()"<<endl<<hMap.count("James")<<endl;
    cout<<hMap.count("Windsor")<<endl<<endl;


    // .erase("key") // used to delete an entry with "key"
    cout<<" .erase() "<<endl<<hMap.count("james")<<endl;
    hMap.erase("James");
    cout<<hMap.count("james")<<endl;

    return 0;
}

