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

#include "Game.hpp"

CGame gGame(nullptr); // TODO

#if OPENLAMBDA_TARGET_ENGINE == OPENLAMBDA_TARGET_ENGINE_NEXT
EXPOSE_SINGLE_INTERFACE_GLOBALVAR(CGame, IGame, OGS_GAME_INTERFACE_VERSION, gGame)
#endif

bool CGame::Init(CreateInterfaceFn afnEngineFactory)
{
	// TODO
	return true;
};

void CGame::Shutdown()
{
	// TODO
};

void CGame::Update()
{
	// TODO
};