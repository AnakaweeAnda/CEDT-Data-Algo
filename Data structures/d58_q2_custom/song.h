#ifndef __SONG_H__
#define __SONG_H__

#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include "priority_queue.h"

using namespace std;

class Song {
  public:
    std::string artist,title;
    int count;

    Song() { }
    Song(const Song &s) : artist(s.artist), title(s.title), count(s.count) { }
    Song(std::string artist,std::string title,int count) :  artist(artist), title(title), count(count) { }

    friend std::ostream& operator<<(std::ostream &out,const Song &s) {
      return out << "Artist: " << s.artist << " Title: " << s.title << " count: " << s.count;
    }

};


//  you have to write something below this line 
//  you *MIGHT* have to change the declaration of pq1 and pq2
class Comp1 {
  public :
  bool operator() (const Song &a , const Song &b) {
    if(a.artist != b.artist) return a.artist > b.artist;
    else if(a.title != b.title) return a.title > b.title;
    else return a.count > b.count;
  }
};

class Comp2 {
  public :
  bool operator() (const Song &a , const Song &b) {
    if(a.count != b.count) return a.count < b.count;
    else if(a.artist != b.artist) return a.artist > b.artist;
    else return a.title > b.title;
  }
};

CP::priority_queue<Song,Comp1> pq1;
CP::priority_queue<Song,Comp2> pq2;

#endif
