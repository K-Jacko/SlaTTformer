//
// Created by Wake on 2/20/2023.
//

#ifndef SLATFORMER_FLOORTILE_H
#define SLATFORMER_FLOORTILE_H
#include "Entity.h"
class FloorTile : Entity
{
public:
    FloorTile();
    explicit FloorTile(SDL_Texture* _texture);
    void Init(SDL_Renderer *renderer, SDL_Texture *texture) override;
private:

};
#endif //SLATFORMER_FLOORTILE_H
