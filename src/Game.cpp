#include "../include/Game.h"
#include "../include/TextureManager.h"
#include "../include/Map.h"
#include "../include/Components.h"
#include "../include/Vector2D.h"
#include "../include/Collision.h"

namespace rock3r {

    Map* map;
    Manager manager;
    SDL_Event Game::event;
    auto& player(manager.addEntity());
    auto& wall(manager.addEntity());
    SDL_Renderer* Game::renderer = nullptr;
    vector<ColliderComponent*> Game::colliders;
    
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
           
            map = new Map();
            Map::loadMap("../assets/map.map", 16, 16);

            player.addComponent<TransformComponent>(2);
            player.addComponent<SpriteComponent>("../assets/individuals/adventurer-attack1-01.png");      
            player.addComponent<KeyboardController>();
            player.addComponent<ColliderComponent>("player");
        
            wall.addComponent<TransformComponent>(300.0f, 300.0f, 300, 20, 1);
            wall.addComponent<SpriteComponent>("../assets/dirt.png");
            wall.addComponent<ColliderComponent>("wall");

        } else {
            cout << "SDL does not have initialized ..." << ", " << SDL_GetError() << endl;
            isRunning = false;
        } 
    }

    void Game::update() {
        manager.refresh();
        manager.update();
        for(auto cc : colliders) {        
            Collision::AABB(player.getComponent<ColliderComponent>(), *cc);
        }
    }

    void Game::render() {
        SDL_RenderClear(renderer);
        manager.draw();
        SDL_RenderPresent(renderer);
    }

    void Game::clean() {
        SDL_DestroyWindow(window);   
        SDL_DestroyRenderer(renderer);
        SDL_Quit();
    }

    void Game::addTile(int id, int x, int y) {
        auto& tile(manager.addEntity());
        tile.addComponent<TileComponent>(x, y, 32, 32, id);
    }

    void Game::handleEvents() {

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
