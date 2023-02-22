#ifndef SLATFORMER_CHARACTER_H
#define SLATFORMER_CHARACTER_H
#include "Entity.h"


class Character : public Entity {
public:
    Character();
    int characterSpeed;
    void Init(RenderWindow* renderer, SDL_Texture* texture) override;
    void UpdatePosition(SDL_Event event);
private:

};
#endif //SLATFORMER_CHARACTER_H
