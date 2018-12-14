#include "Game.h"

namespace rock3r {

    Manager manager;
    auto& player(manager.addEntity());
    
    void Game::init(const char* title, int posX, int posY, int width, int height, bool fullScreen) {
        if(SDL_Init(SDL_INIT_EVERYTHING) == 0) {
            cout << "SDL initialized ..." << endl;
            int flags = 0;
            if(fullScreen) 
                flags = SDL_WINDOW_FULLSCREEN;
            window = SDL_CreateWindow(title, posX, posY, width, height, flags);
            if(window) {
                cout << "Window created ..." << endl;            
                renderer = SDL_CreateRenderer(window, -1, 0);
                if(renderer) {
                    cout << "Renderer created ..." << endl;
                    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                    isRunning = true;
                }
            }
           
            //cout << "path: " << filesystem::current_path() << endl;
           
            map = Map();        
            player.addComponent<PositionComponent>();
            player.addComponent<SpriteComponent>("../assets/individuals/adventurer-attack1-01.png");      
        } else {
            cout << "SDL does not hace initialized ..." << ", " << SDL_GetError() << endl;
            isRunning = false;
        } 
    }

    void Game::update() {
        manager.refresh();
        manager.update();
    }

    void Game::render() {
        SDL_RenderClear(renderer);
        map.drawMap();
        manager.draw();
        SDL_RenderPresent(renderer);
    }

    void Game::clean() {
        SDL_DestroyWindow(window);   
        SDL_DestroyRenderer(renderer);
        SDL_Quit();
    }

    void Game::handleEvents() {
        SDL_Event event;
        SDL_PollEvent(&event);
        switch(event.type) {
            case SDL_QUIT:
                isRunning = false;
                break;
            default:
                break;
        }
    }
}
