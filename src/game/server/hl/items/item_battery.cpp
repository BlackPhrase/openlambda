/*
 * This file is part of OpenLambda Project
 *
 * Copyright (C) 2019-2020 BlackPhrase
 *
 * OpenLambda Project is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * OpenLambda Project is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with OpenLambda Project. If not, see <http://www.gnu.org/licenses/>.
*/

/// @file

#include "PickupItem.hpp"

class CItemBattery : public CPickupItem
{
public:
	void Spawn() override;
};

void CItemBattery::Spawn()
{
	gpEngine->pfnPrecacheModel("models/w_battery.mdl");
	
	SetModel("models/w_battery.mdl");
	
	CPickupItem::Spawn();
};

LINK_ENTITY_TO_CLASS(item_battery, CItemBattery);