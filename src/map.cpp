#include "map.hpp"
map :: map (){
    font.loadFromFile("fonts/OpenSans-Bold.ttf");
    text.setFont(font);
}
sf::RectangleShape map :: board (float posx,float posy,std::string line){
    static sf::RectangleShape rect;
    int x;
    if (line != "tile"){
        if (line == "Level:"){x=level;}
        if (line == "Score:"){x=score;}
        if (line == "Power:"){x=power;}
        if (line == "Last Score:"){x=lastscore;}
        sf::Vector2f size(400.0f,50.0f);
        rect.setSize(size);
        rect.setOutlineThickness(5);
        rect.setOutlineColor(sf::Color::White);
        rect.setPosition(posx,posy);
        rect.setFillColor(sf::Color::Black);
        ss.str(std::string());
        ss << line << x ;
        text.setString(ss.str().c_str());
        text.setCharacterSize(40);
        text.setPosition(posx,posy);
        text.setFillColor(sf::Color::White);
    }
    if (line == "tile"){
        int y=posx/50,z=(posy-100)/50;
        if (grid[z][y] == 1){
            sf::Vector2f size(50.0f,50.0f);
            rect.setSize(size);
            rect.setPosition(posx,posy);
            rect.setFillColor(sf::Color::Cyan);
        }
        if (grid[z][y] == 0){
            sf::Vector2f size(50.0f,50.0f);
            rect.setSize(size);
            rect.setPosition(posx,posy);
            rect.setFillColor(sf::Color::Green);
        }
        if (grid[z][y] == 2){
            sf::Vector2f size(50.0f,50.0f);
            rect.setSize(size);
            rect.setPosition(posx,posy);
            rect.setFillColor(sf::Color::Red);
        }
    }
    return rect;
}
sf::Vector2i map :: snake (int movex,int movey){
    static int x=8,y=8;
    if (c == 99999999){
        c=power;
    }
    x=x+movex;y=y+movey;
    if (x>15){
        x=0;
    }
    if (y>15){
        y=0;
    }
    if (x<0){
        x=15;
    }
    if (y<0){
        y=15;
    }
    grid[y][x]=0;
    d1[c]={y};
    d2[c]={x};
    if (power <= c){
        grid[d1[c-power]][d2[c-power]]=1;
    }
    c++;
    std::cout << " Snake position  "<< x << "::" << y << std::endl;
    sf::Vector2i position(x,y);
    return position;
}
sf::Vector2i map :: randcheck(){
    random ran;
    int x= ran.randx();
    int y= ran.randy();
    sf::Vector2i random(x,y);
    for (int i=c;i>=(c-power);i--){
        if (d1[i]==y){
            if (d2[i]==x){
                random = randcheck();
                break;
            }
        }
        if (d1[i]==x){
            if (d2[i]==y){
                random = randcheck();
                break;
            }
        }
    }
    return random;
}
sf::Vector2i map :: food(){
    sf::Vector2i Food(randcheck());

    grid[Food.y][Food.x]=2;
    std::cout << "food loction  "<< Food.x << "::" << Food.y << "  path" <<c<<std::endl;
    
    return Food;
}
void map ::scoring(){
    power++;
    score=score+50*level;
}
random :: random(){
    std::cout << " constructor called " << std::endl;   
}
random :: ~random(){
    std::cout << " destructor called " << std::endl;
}
inline int random :: randx(){
    int x = rand()%16,flag=0;
    std::cout << "  random x generated  " << x;
    return x;
}
inline int random :: randy(){
    int y = rand()%16,flag=0;
    std::cout << "  random y generated  " << y; 
    return y;
}
