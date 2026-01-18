#include <iostream>
#include <string>
#include <cstring>
using namespace std;
#ifndef MOVIESAMPLE_H
#define MOVIESAMPLE_H

const int sizes = 10;

class Movie
{
    private:

    string name;
    string rating;
    int watched;

    public:
     
     Movie():name{""}, rating{""}, watched{0}{};
     Movie(string n, string r, int w):name{n}, rating{r}, watched{w}{};

    friend class Movies;

};

class Movies
{
    private:
    Movie Collection[sizes];

    public:

    Movies(){
        for(int i = 0; i < sizes ; i++)
        {
                Collection[i] = Movie();
        }
    };
    Movies(const Movie &N){
        Collection[0] = N;
          for(int i = 1; i < sizes ; i++)
        {
                Collection[i] = Movie();
             
        }
    };
    
    string getName(const Movie &m) const {return m.name;} ;
    string getRating(const Movie &m) const {return m.rating;};
    int getWatched(const Movie &m) const {return m.watched;};
    void setMovie(Movie &m, string newName, string newRating, int newWatched)
    {   m.name = newName;
        m.rating = newRating;
        m.watched = newWatched;
        }
    void incrementWatch(string movieName) 
    {   bool found = false;
        
        for(int i = 0; i < sizes; i++)
        {
            if(!Collection[i].name.empty() && Collection[i].name == movieName )
            {
                Collection[i].watched++;
                cout << " You have Watched " << movieName << " "<< Collection[i].watched << " times" << endl;
                found = true;
                break;
            }
             
        }
        if(!found) {
        cout << "Movie \"" << movieName << "\" not found in the collection." << endl;
    }
       
    }
    void AddMovie(const Movie& N){ 
        bool added = false;

        for(int i = 0; i < sizes; i++)
    {
        if(Collection[i].name == N.name)
        {
            cout << "Movie \"" << N.name << "\" is already in the collection." << endl;
            return; // exit, no duplicates allowed
        }
    }

        for(int i = 0; i < sizes; i++ )
        {
            if(Collection[i].name.empty())
            {
                Collection[i] = N;
                added = true;
            cout << "Movie \"" << N.name << "\" added to the collection." << endl;
               break;
            } 
            
        
    }
        if(!added) {
         cout << "Cannot add \"" << N.name << "\". Collection is full!" << endl; 
            }
        };
    
    void displayMovie() const
    { for(int i = 0; i < sizes; i++)
    {
        if(!Collection[i].name.empty())
        {
            cout << "Name: " << Collection[i].name << endl;
            cout << "Rating: " << Collection[i].rating << endl;
            cout << "Watch Count: " << Collection[i].watched << endl;
        }       
    }      
      };

};

#endif