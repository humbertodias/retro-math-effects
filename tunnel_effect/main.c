#include <SDL.h>
#include <math.h>

#define W 320
#define H 200
#define SCALE 3

int main(void) {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* win = SDL_CreateWindow(
        "Tunnel Effect",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        W * SCALE, H * SCALE, 0
    );

    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

    int running = 1;
    float t = 0.0f;

    int cx = W / 2;
    int cy = H / 2;

    while (running) {
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) running = 0;
            if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE)
                running = 0;
        }

        for (int y = 0; y < H; ++y) {
            for (int x = 0; x < W; ++x) {
                float dx = x - cx;
                float dy = y - cy;

                float angle = atan2f(dy, dx);
                float dist = sqrtf(dx * dx + dy * dy);
                if (dist < 1.0f) dist = 1.0f;

                float u = angle * 8.0f;
                float v = 200.0f / dist + t;

                int c = (int)((sinf(u + v) * 0.5f + 0.5f) * 255);

                SDL_SetRenderDrawColor(ren, c, 100, 255 - c, 255);

                SDL_Rect r = {
                    x * SCALE,
                    y * SCALE,
                    SCALE,
                    SCALE
                };
                SDL_RenderFillRect(ren, &r);
            }
        }

        SDL_RenderPresent(ren);
        SDL_Delay(16);
        t += 0.05f;
    }

    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 0;
}
