#include "ballinhandstate.h"
#include <SDL.h>

BallInHandState::BallInHandState(Level* level)
{
    this->level = level;
    whiteBall = level->getWhiteBall();

    whiteBall->setPocketed(false);
}

void BallInHandState::handle_events()
{
    SDL_Event e;

    while (SDL_PollEvent(&e))
    {
        if (e.type == SDL_MOUSEMOTION)
        {
            whiteBall->setPos(
                e.motion.x,
                e.motion.y
            );

        }

        if (e.type == SDL_MOUSEBUTTONDOWN)
        {
            changeState(
                std::make_unique<Level>()
            );
        }
    }
}

void BallInHandState::logic()
{
}

void BallInHandState::render()
{
    level->render();
}
