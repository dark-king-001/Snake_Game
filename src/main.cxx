#include "map.cpp"
map *data = new map();
int main(){
    sf::Clock clock;
    sf::Vector2i Food,Head;
    sf::Time time,speed= sf::milliseconds(500-(50*data->Level()));
    bool pause=true,food=true;
    int movex=1,movey=0;
    sf::RenderWindow win(sf::VideoMode(800,900),"main window");
    win.setFramerateLimit(60);
    while (win.isOpen()){
        sf::Event event;
        while (win.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                win.close();
                break;
            }
            if (event.type == sf::Event::KeyPressed){
                if (event.key.code == sf::Keyboard::W){
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
                        if (movey != 1){
                            movex=0;
                            movey=-1;
                            pause=true;
                        }
                    }
                    break;
                }
            }
            if (event.type == sf::Event::KeyPressed){
                if (event.key.code == sf::Keyboard::S){
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
                        if (movey != -1){
                            movex=0;
                            movey=1;
                            pause=true;
                        }
                    }
                    break;
                }
            }if (event.type == sf::Event::KeyPressed){
                if (event.key.code == sf::Keyboard::A){
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
                        if (movex != 1){
                            movex=-1;
                            movey=0;
                            pause=true;
                        }
                    }
                    break;
                }
            }if (event.type == sf::Event::KeyPressed){
                if (event.key.code == sf::Keyboard::D){
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
                        if (movex != -1){
                            movex=1;
                            movey=0;
                            pause=true;
                        }
                    }
                    break;
                }
            }
        }
        //std::cout << movex << "::" << movey << std::endl;
        time =clock.getElapsedTime();
        if (speed <= time){
            Head = data->snake(movex,movey);
            clock.restart();
            pause = true;
        }
        if (food == true){
            Food = data->food();
            food = false;
        }
        if (Food == Head){
            food = true;
            data->scoring();
        }
        if (pause == true){
            win.clear();
            win.draw(data->board(0,0,"Level:"));
            win.draw(data->DrawText());
            win.draw(data->board(400,0,"Score:"));
            win.draw(data->DrawText());
            win.draw(data->board(0,50,"Power:"));
            win.draw(data->DrawText());
            win.draw(data->board(400,50,"Last Score:"));
            win.draw(data->DrawText());
            for (int y=100;y<=900;y+=50){
                for (int x=0;x<=800;x+=50){
                    win.draw(data->board(x,y,"tile"));
                }
            }
        win.display();
        }
        //pause = false;
    }
    return 0;
}