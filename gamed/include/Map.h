#ifndef _MAP_H
#define _MAP_H

#include <map>
#include <vector>

#include "stdafx.h"
#include "Object.h"

class Game;

class Map {

protected:
   std::map<uint32, Object*> objects;
   std::vector<uint32> expToLevelUp;
   int waveNumber;
   const uint64 firstSpawnTime;
   const uint64 spawnInterval;
   uint64 gameTime;
   uint64 nextSpawnTime;
   Game* game;
   
public:
   Map(Game* game, uint64 firstSpawnTime, uint64 spawnInterval) : game(game), waveNumber(0), firstSpawnTime(firstSpawnTime), spawnInterval(spawnInterval), gameTime(0), nextSpawnTime(firstSpawnTime) { }
   
   virtual ~Map() { }
   virtual void update(long long diff);
   virtual float getGoldPerSecond() = 0;
   virtual bool spawn() = 0;
   
   Object* getObjectById(uint32 id);
   void addObject(Object* o);
   const std::vector<uint32>& getExpToLevelUp() { return expToLevelUp; }
   
   virtual const Target getRespawnLoc(int side) const = 0;
   virtual float getGoldFor(Unit* u) const = 0;
   
   Game* getGame() const { return game; }
   
   const std::map<uint32, Object*>& getObjects() { return objects; }
   void stopTargeting(Unit* target);
   
};

#endif