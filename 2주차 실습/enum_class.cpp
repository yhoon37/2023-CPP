#include <iostream>
#include <map>

enum class Genre{Action, Comedy, Drama, Romance, SciFi};
enum class Rating{OneStar, TwoStars, ThreeStars, FourStars, FiveStars};

int main() {
    std::map<std::string, int> genre;
    std::map<std::string, int> rating;
    std::map<std::string, float> avgRating;


    while(true){
        std::string name="";
        int movieGenre=0, rate=0;

        std::getline(std::cin, name);
        if(name == "q") break;


        std::cin >> movieGenre;
        std::cin.ignore();
        std::cin >> rate;
        std::cin.ignore();
        if(genre.find(name)== genre.end()){
            genre.insert({name, movieGenre});
        }

        if(rating.find(name)== rating.end()){
            rating.insert({name, 1});
        }

        if(avgRating.find(name)== avgRating.end()){
            avgRating.insert({name, rate});
        }
        else{
            float newAvg = (avgRating[name]*rating[name] + rate)/(rating[name] + 1);
            avgRating[name] = newAvg;
            rating[name] += 1;
        }

    }


    for(const auto& it : genre){
        std::cout << it.first << ": " << rating[it.first] << " ratings, average rating " << avgRating[it.first]
        << " stars, genre: " << it.second <<std::endl;
    }


    return 0;
}
