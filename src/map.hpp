#include <iostream>
#include <String>
//#include "include/SFML/System.hpp"
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <sstream>

class map{
    private:
    int level=5,score=0,power=3,lastscore=0;
    sf::Font font;
    sf::Text text;
	int d1[100000000],c=1;
	int d2[100000000];
    int grid[16][16]={
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};
    std::stringstream ss;
    public:
    map();
    sf::Text DrawText(){return text;}
    sf::RectangleShape board(float pox,float posy,std::string line);
	sf::Vector2i snake(int movex,int movey);
	sf::Vector2i food();
	void scoring();
	sf::Vector2i randcheck();
	int Level(){return level;}
};
class random{
	public:
	random();
	~random();
	inline int randx();
	inline int randy();
};