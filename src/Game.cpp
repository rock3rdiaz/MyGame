#include "../include/Game.h"
#include "../include/TextureManager.h"
#include "../include/Map.h"
#include "../include/Components.h"
#include "../include/Vector2D.h"

namespace rock3r {
    Map* map;
    Manager manager;
    auto& player(manager.addEntity());
    SDL_Renderer* Game::renderer = nullptr;
    
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
           
            map = new Map();        
            player.addComponent<TransformComponent>();
            player.addComponent<SpriteComponent>("../assets/individuals/adventurer-attack1-01.png");      
        } else {
            cout << "SDL does not hace initialized ..." << ", " << SDL_GetError() << endl;
            isRunning = false;
        } 
    }

    void Game::update() {
        manager.refresh();
        manager.update();
        player.getComponent<TransformComponent>().position.add(Vector2D(5, 0));
        if(player.getComponent<TransformComponent>().position.x > 100) {
            player.getComponent<SpriteComponent>().setText("../assets/individuals/adventurer-air-attack3-loop-01.png");
        }
    }

    void Game::render() {
        SDL_RenderClear(renderer);
        map->drawMap();
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
