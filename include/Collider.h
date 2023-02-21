//
// Created by Wake on 2/20/2023.
//

#ifndef SLATFORMER_COLLIDER_H
#define SLATFORMER_COLLIDER_H
class Collider {
public:
    Collider();
    Collider(int x, int y, int w, int h);
    bool collidesWith(const Collider& other) const;
private:
    int _x, _y, _w, _h;
};
#endif //SLATFORMER_COLLIDER_H
