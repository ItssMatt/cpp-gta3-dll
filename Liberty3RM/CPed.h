#pragma once

#include <Windows.h>

#include "CVector.h"

class CPed {
public: 
	static	CPed*			getLocalPlayer(void);
	static	void			setLocalPlayer(void);
			void			setHealth(float health);
			float			getHealth(void);
			void			setArmor(float armor);
			float			getArmor(void);
			CVector         getPosition(void);
			void			setPosition(CVector position);
			int				getModel(void);
			void			setModel(int model);
		
};