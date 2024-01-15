// Render food, player, score, and window border
        renderFood(renderer, food);
        renderPlayer(renderer, player, x, y, scale, tailX, tailY, tailLength);
        renderScore(tailLength);

        SDL_RenderDrawLine(renderer, 0, 0, 0, 24 * 24);
        SDL_RenderDrawLine(renderer, 0, 24 * 24, 24 * 24, 24 * 24);
        SDL_RenderDrawLine(renderer, 24 * 24, 24 * 24, 24 * 24, 0);
        SDL_RenderDrawLine(renderer, 24 * 24, 0, 0, 0);

        // Put everything on screen
        SDL_RenderPresent(renderer);

        // Choose a color to fill the window
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);