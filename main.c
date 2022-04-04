#include <SDL.h>
#include <stdio.h>
#define screenWidth 800 
#define screenHeight 600 

void logError(const char errorReason[]); 


int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_VIDEO); 

    /*
        Initialisation and creation of all objects for this application 
    */ 

    // creation of the application window 
    SDL_Window* mainWindow = NULL; 
    mainWindow = SDL_CreateWindow("SDL project", 0, 0, screenWidth, screenHeight, 0); 
    if(mainWindow == NULL)
    {
        logError("Failed to initialise the window"); 
        goto quit; 
    }

    // creation of the renderer 
    SDL_Renderer* mainRenderer = NULL; 
    mainRenderer = SDL_CreateRenderer(mainWindow, -1, 0);
    if(mainRenderer == NULL)
    { 
        logError("Failed to initialise the renderer"); 
        goto quit; 
    }
    SDL_SetRenderDrawColor(mainRenderer, 0, 255, 0, 255); 
    SDL_RenderClear(mainRenderer); 
    SDL_RenderPresent(mainRenderer); 

    SDL_Delay(5000); 
    goto quit; 

quit:
    // free allocated memory by this application
    if(mainWindow != NULL) 
        SDL_DestroyWindow(mainWindow);

    if(mainRenderer != NULL)
        SDL_DestroyRenderer(mainRenderer);

    SDL_Quit(); 
    return 0; 
}


void logError(const char errorReason[])
{
    //  print the SDL error in the terminal 
    printf("%s [%s]", errorReason, SDL_GetError()); 
}