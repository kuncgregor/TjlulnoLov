#include "Game.h"
#include "meni.h"
#include "TextureManager.h"
#include "Meni_texture.h"
#include "GameObject.h"
#include "Map.h"
#include "Tvector.h"
#include "Keyboard.h"
#include <iostream>
#include <ctime>
#include <cstdlib>


Game* lvl1 = nullptr;
Game* lvl2 = nullptr;
Game* lvl3 = nullptr;

meni* mejn = nullptr;

void riplej() {
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

    Uint32 frameStart;
    int frameTime;
    int timer = 0;
    timer = clock();

    lvl1 = new Game();
    lvl2 = new Game();
    lvl3 = new Game();

    lvl1->init("lvl1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false, 0, 1);


   
    while (lvl1->running()) {

        frameStart = SDL_GetTicks();

        lvl1->dela();
        lvl1->update(1,true);
        lvl1->lovljenje();
        lvl1->Dogajanje();

        frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime) {

            SDL_Delay(frameDelay - frameTime);
        }
        timer = clock();
        if (lvl1->level() == 3) {

            lvl2->init("lvl2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false, 0, 2);


            lvl1->okno();
            timer = 0;

            while (lvl2->running()) {

                frameStart = SDL_GetTicks();

                lvl2->dela();
                lvl2->update(2,true);
                lvl2->lovljenje();
                lvl2->Dogajanje();

                frameTime = SDL_GetTicks() - frameStart;

                if (frameDelay > frameTime) {

                    SDL_Delay(frameDelay - frameTime);
                }
                timer = clock();

                if (lvl2->level() == 3) {
                    lvl3->init("lvl3", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false, 0, 3);
                    lvl2->okno();
                    while (lvl3->running()) {
                        timer = 0;
                        frameStart = SDL_GetTicks();

                        lvl3->dela();
                        lvl3->update(3,true);
                        lvl3->lovljenje();
                        lvl3->Dogajanje();

                        frameTime = SDL_GetTicks() - frameStart;

                        if (frameDelay > frameTime) {

                            SDL_Delay(frameDelay - frameTime);
                        }

                        if (lvl3->level() == 3) {
                            std::cout << " __________   _____      _____     ________    _____    \n" << " \____    /  /     \    /  _  \   /  _____/   /  _  \   \n" <<
                                "   /     /  /  \ /  \  /  /_\  \ /   \  ___  /  /_\  \  \n" << "  /     /_ /    Y    \/    |    \\    \_\  \/    |    \ \n" <<
                                " /_______ \\____|__  /\____|__  / \______  /\____|__  / \n" << "         \/        \/         \/         \/         \/  \n";
                            lvl3->clean();
                            SDL_QUIT;
                            
                        }
                        else if ((timer / 1000) >= 60) {
                            lvl3->clean();
                            SDL_QUIT;
                            
                        }
                    }
                    lvl3->clean();
                    SDL_QUIT;
                }
                else if ((timer / 1000) >= 60) {
                    lvl2->clean();
                    SDL_QUIT;
                }
            }
            lvl2->clean();
            SDL_QUIT;
        }
        else if ((timer / 1000) >= 60) {
            lvl1->clean();
            SDL_QUIT;
            
        }
    }
    lvl1->clean();
    SDL_QUIT;


}


int main(int argc, char* args[]) {
    int tocke = 0;
    std::cout << "Vpisi ime :         (primer: Plejr 1)" << std::endl;
    char ime[10];
    gets_s(ime);

    //GameObject mama("slikce/Old_woman.png", 0, 0);
    //GameObject igralec("slikce/Woodcutter.png", 0.00, 0.00);
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

    Uint32 frameStart;
    int frameTime;
    int timer = 0;
    timer = clock();

    mejn = new meni();

    lvl1 = new Game();
    lvl2 = new Game();
    lvl3 = new Game(); 
    
    
    mejn->init("meni", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false, 0);


    do {
        frameStart = SDL_GetTicks();
        mejn->dela();
        mejn->update();
        mejn->Dogajanje();

        frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime) {

            SDL_Delay(frameDelay - frameTime);
        }

        if (mejn->stanje() == 2) {
            riplej();
        }

        if (mejn->stanje() == 3) {
            SDL_QUIT;
            return  0;
        }
        

    } while (mejn->stanje() != 1);
    mejn->clean();
    
 

    lvl1->init("lvl1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false, 0, 1);


    /*
    do {
        frameStart = SDL_GetTicks();

        lvl1->dela();
        lvl1->update(1);
        lvl1->lovljenje();
        lvl1->Dogajanje();

        frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime) {

            SDL_Delay(frameDelay - frameTime);
        }
        timer = clock();
        
    } while (lvl1->level() != 3 && lvl1->running());

    if (lvl1->level() == 3) {
        lvl2->init("lvl2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false, 0, 2);
        lvl1->okno();
        do {
            
            timer = 0;
            

                frameStart = SDL_GetTicks();

                lvl2->dela();
                lvl2->update(2);
                lvl2->lovljenje();
                lvl2->Dogajanje();

                frameTime = SDL_GetTicks() - frameStart;

                if (frameDelay > frameTime) {

                    SDL_Delay(frameDelay - frameTime);
                }
                timer = clock();


        } while (lvl2->level() == 3 && lvl2->running());
    }
    else if ((timer / 1000) >= 60) {
        lvl1->clean();
        SDL_QUIT;
        return 0;
    }

    if (lvl2->level() == 3) {
        lvl3->init("lvl3", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false, 0, 3);
        lvl2->okno();
        do {

            
            
                timer = 0;
                frameStart = SDL_GetTicks();

                lvl3->dela();
                lvl3->update(3);
                lvl3->lovljenje();
                lvl3->Dogajanje();

                frameTime = SDL_GetTicks() - frameStart;

                if (frameDelay > frameTime) {

                    SDL_Delay(frameDelay - frameTime);
                }

                if (lvl3->level() == 3) {
                    std::cout << " __________   _____      _____     ________    _____    \n" << " \____    /  /     \    /  _  \   /  _____/   /  _  \   \n" <<
                        "   /     /  /  \ /  \  /  /_\  \ /   \  ___  /  /_\  \  \n" << "  /     /_ /    Y    \/    |    \\    \_\  \/    |    \ \n" <<
                        " /_______ \\____|__  /\____|__  / \______  /\____|__  / \n" << "         \/        \/         \/         \/         \/  \n";
                    lvl3->clean();
                    SDL_QUIT;
                    return 0;
                }
                else if ((timer / 1000) >= 60) {
                    lvl3->clean();
                    SDL_QUIT;
                    return 0;
                }

        } while (lvl3->level() == 3 && lvl3->running());
    }
    else if ((timer / 1000) >= 60) {
        lvl2->clean();
        SDL_QUIT;
        return 0;
    }
    */
    while (lvl1->running()) {

        frameStart = SDL_GetTicks();

        lvl1->dela();
        lvl1->update(1,false);
        lvl1->lovljenje();
        lvl1->Dogajanje();

        frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime) {

            SDL_Delay(frameDelay - frameTime);
        }
        timer = clock();
        if (lvl1->level() == 3) {
            std::cout << "lvl1: " << std::endl;

            std::cout << " tocke = 3" << std::endl;
            
            lvl2->init("lvl2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false, 0, 2);
            
            
            lvl1->okno();
            timer = 0;
            
            while (lvl2->running()) {
                
                
                frameStart = SDL_GetTicks();

                lvl2->dela();
                lvl2->update(2,false);
                lvl2->lovljenje();
                lvl2->Dogajanje();

                frameTime = SDL_GetTicks() - frameStart;

                if (frameDelay > frameTime) {

                    SDL_Delay(frameDelay - frameTime);
                }
                timer = clock();
                
                if (lvl2->level() == 3) {
                    std::cout << "lvl2: " << std::endl;

                    std::cout << " tocke = 6" << std::endl;
                    
                    lvl3->init("lvl3", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false, 0, 3);
                    lvl2->okno();
                    while (lvl3->running()) {
                        
                        timer = 0;
                        frameStart = SDL_GetTicks();

                        lvl3->dela();
                        lvl3->update(3,false);
                        lvl3->lovljenje();
                        lvl3->Dogajanje();

                        frameTime = SDL_GetTicks() - frameStart;

                        if (frameDelay > frameTime) {

                            SDL_Delay(frameDelay - frameTime);
                        }
                     
                        if (lvl3->level() == 3) {
                            std::cout << "lvl3: " << std::endl;

                            std::cout << " tocke = 12" << std::endl;
                            std::cout << " __________   _____      _____     ________    _____    \n"<<" \____    /  /     \    /  _  \   /  _____/   /  _  \   \n"<<
                                           "   /     /  /  \ /  \  /  /_\  \ /   \  ___  /  /_\  \  \n"<< "  /     /_ /    Y    \/    |    \\    \_\  \/    |    \ \n"<<
                                " /_______ \\____|__  /\____|__  / \______  /\____|__  / \n"<<"         \/        \/         \/         \/         \/  \n";
                            lvl3->clean();
                            SDL_QUIT;
                            return 0;
                        }
                        else if ((timer / 1000) >= 60) {
                            lvl3->clean();
                            SDL_QUIT;
                            return 0;
                        }
                    }
                    lvl3->clean();
                    SDL_QUIT;
                }
                else if ((timer / 1000) >= 60) {
                    lvl2->clean();
                    SDL_QUIT;
                    return 0;
                }
            }
            lvl2->clean();
            SDL_QUIT;
        }
        else if ((timer / 1000) >= 60) {
            lvl1->clean();
            SDL_QUIT;
            return 0;
        }
    }
    lvl1->clean();
    SDL_QUIT;
    

    return 0;
}