//
// Created by Иван Ильин on 02.06.2021.
//

#include "../engine/ResourceManager.h"
#include "Ak47.h"

using namespace std;

Ak47::Ak47(int ammo, const std::string& weaponName) : Weapon(weaponName, "obj/ak47.obj", "obj/ak47_mat.txt", Vec3D{3, 3, 3}, Vec3D{-0.8, 1.3, 0.3}, Vec3D{0, Consts::PI, 0}) {
    fireSound.setBuffer(*ResourceManager::loadSoundBuffer("sound/weapons/ak47.ogg"));
    reloadSound.setBuffer(*ResourceManager::loadSoundBuffer("sound/weapons/reload_ak47.ogg"));


    _stockAmmo = ammo - _clipCapacity;
    _fireDelay = 0.1;
}
