// https://github.com/XK9274/splash-miyoo

#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <image_file> [r] [g] [b]\n", argv[0]);
        return 1;
    }

    const char* image_path = argv[1];
    int red = (argc > 2) ? atoi(argv[2]) : 0;
    int green = (argc > 3) ? atoi(argv[3]) : 0;
    int blue = (argc > 4) ? atoi(argv[4]) : 0;

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        return 1;
    }

    // Initialize SDL_image
    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags)) {
        printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Surface* screen = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE);
    if (screen == NULL) {
        printf("Could not create screen! SDL Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Fill screen with specified background color
    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, red, green, blue));

    // Update the screen
    SDL_UpdateRect(screen, 0, 0, 0, 0);

    // Load image
    SDL_Surface* img = IMG_Load(image_path);
    if (img == NULL) {
        printf("Unable to load image %s! SDL_image Error: %s\n", image_path, IMG_GetError());
        SDL_Quit();
        return 1;
    }

    // Center image on screen
    SDL_Rect dstrect;
    dstrect.x = (screen->w - img->w) / 2;
    dstrect.y = (screen->h - img->h) / 2;

    // Draw image on screen
    SDL_BlitSurface(img, NULL, screen, &dstrect);
    SDL_Flip(screen);

    // Wait 5 seconds then quit
    SDL_Delay(5000);

    // Free surfaces
    SDL_FreeSurface(img);

    // Quit SDL
    SDL_Quit();

    return 0;
}
