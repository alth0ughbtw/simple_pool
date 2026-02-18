#pragma once

#include "gamestate.h"
#include "level.h"

class BallInHandState : public GameState
{
private:

    Level* level;
    Ball* whiteBall;

public:

    BallInHandState(Level* level);

    void handle_events() override;

    void logic() override;

    void render() override;
};
