/*
 * This file is part of OpenLambda Project
 *
 * Copyright (C) 2018-2019 BlackPhrase
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

#pragma once

#include "game/client/IClientGame.hpp"

class CClientGame /*final*/ : public IClientGame
{
public:
	bool Init(CreateInterfaceFn afnEngineFactory /*, cldll_func_t *pcl_funcs*/) override;
	void Shutdown() override;
	
	void Update(double afTime) override;
};