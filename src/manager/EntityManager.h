#ifndef _EntityManager_H_
    #define _EntityManager_H_

#include "../entity/Entity.h"
#include <map>
	
class EntityManager {
private:
	std::map<std::string, Entity*> m_entities;
	
public:
	EntityManager();
	
};
#endif