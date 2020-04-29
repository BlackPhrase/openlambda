/*
 * This file is part of OGSNext Engine
 *
 * Copyright (C) 2017-2018, 2020 BlackPhrase
 *
 * OGSNext Engine is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * OGSNext Engine is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with OGSNext Engine. If not, see <http://www.gnu.org/licenses/>.
*/

/// @file

#include "quakedef.h"
#include "BaseUI.h"
#include "gameui/IGameUI.hpp"
#include "gameui/IGameConsole.hpp"

extern IGameUI *gpGameUI;
extern IGameConsole *gpGameConsole;

void *gpGameUILib{nullptr};

CBaseUI gBaseUI;
IBaseUI *gpBaseUI{&gBaseUI};

EXPOSE_SINGLE_INTERFACE_GLOBALVAR(CBaseUI, IBaseUI, BASEUI_INTERFACE_VERSION, gBaseUI);

void UnloadGameUIModule()
{
	if(gpGameUILib)
	{
		Sys_UnloadModule(gpGameUILib);
		gpGameUILib = nullptr;
	};
};

void LoadGameUIModule()
{
	UnloadGameUIModule();

#ifdef OGS_EVOL
	gpGameUILib = Sys_LoadModule(va("%s/cl_dlls/gameui", com_gamedir));

	if(!gpGameUILib)
#endif
	{
		gpGameUILib = Sys_LoadModule("valve/cl_dlls/gameui");

		if(!gpGameUILib)
			return; // TODO: gpSystem->Error
	};

	auto fnGameUIFactory{ Sys_GetFactory(gpGameUILib) };

	if(!fnGameUIFactory)
		return;

	gpGameUI = (IGameUI*)fnGameUIFactory(MGT_GAMEUI_INTERFACE_VERSION, nullptr);
	gpGameConsole = (IGameConsole*)fnGameUIFactory(MGT_GAMECONSOLE_INTERFACE_VERSION, nullptr);
	//gpCareerUI = (ICareerUI*)fnGameUIFactory(CAREERUI_INTERFACE_VERSION, nullptr); // TODO

	if(!gpGameUI || !gpGameConsole) //|| !gpCareerUI)
		return;
	
	// TODO: hacky way to temporary support legacy menu code
	fnM_Keydown = (pfnM_Keydown)Sys_GetExport(gpGameUILib, "M_Keydown");
	fnM_Draw = (pfnM_Draw)Sys_GetExport(gpGameUILib, "M_Draw");
};

CBaseUI::CBaseUI() = default;
CBaseUI::~CBaseUI() = default;

void CBaseUI::Initialize(CreateInterfaceFn *factories, int count)
{
/*
	if (!gConfigs.bInitialied)
		Config_Init();

	g_hVGUI2 = (HINTERFACEMODULE)GetModuleHandle("vgui2.dll");

	if(g_hVGUI2)
	{
		auto fnVGUI2CreateInterface{Sys_GetFactory(g_hVGUI2)};
		auto fnEngineCreateInterface{Sys_GetFactoryThis()};

		IKeyValuesSystem *pKeyValuesSystem = reinterpret_cast<IKeyValuesSystem*>(fnVGUI2CreateInterface(KEYVALUESSYSTEM_INTERFACE_VERSION, NULL));

		vgui::IVGui *pVGui = (vgui::IVGui *)fnVGUI2CreateInterface(VGUI_IVGUI_INTERFACE_VERSION, NULL);
		vgui::ISurface *pSurface = (vgui::ISurface *)fnEngineCreateInterface(VGUI_SURFACE_INTERFACE_VERSION, NULL);
		vgui::ISchemeManager *pSchemeManager = (vgui::ISchemeManager *)fnVGUI2CreateInterface(VGUI_SCHEME_INTERFACE_VERSION, NULL);
		vgui::ILocalize *pLocalize = (vgui::ILocalize *)fnVGUI2CreateInterface(VGUI_LOCALIZE_INTERFACE_VERSION, NULL);
		vgui::IInputInternal *pInput = (vgui::IInputInternal *)fnVGUI2CreateInterface(VGUI_INPUT_INTERFACE_VERSION, NULL);
		vgui::IPanel *pPanel = (vgui::IPanel *)fnVGUI2CreateInterface(VGUI_PANEL_INTERFACE_VERSION, NULL);

		KeyCode_InitKeyTranslationTable();
		Panel_InstallHook(pPanel);
		Surface_InstallHook(pSurface);
		SchemeManager_InstallHook(pSchemeManager);
		Input_InstallHook(pInput);
		KeyValuesSystem_InstallHook(pKeyValuesSystem);

		vgui::VGui_LoadEngineInterfaces(fnVGUI2CreateInterface, fnEngineCreateInterface);
	};

	vgui_stencil_test = gEngfuncs.pfnRegisterVariable("vgui_stencil_test", "0", FCVAR_ARCHIVE);
	vgui_message_dialog_modal = engine->pfnRegisterVariable("vgui_message_dialog_modal", "1", FCVAR_ARCHIVE);
	vgui_emulatemouse = engine->pfnGetCvarPointer("vgui_emulatemouse");
*/

	LoadGameUIModule();
	
	if(gpGameUI)
		gpGameUI->Init(factories, count);
};

void CBaseUI::Start(struct cl_enginefuncs_s *engineFuncs, int interfaceVersion)
{
/*
	CreateInterfaceFn factories[2];
	factories[0] = gpMetaHookAPI->GetEngineFactory();
	factories[1] = Sys_GetFactory(ghVGUI2);

	vgui::gpInput->SetIMEWindow(g_hMainWnd);

	gpVGuiLocalize = reinterpret_cast<vgui::ILocalize*>(Sys_GetFactoryThis()(VGUI_LOCALIZE_INTERFACE_VERSION, nullptr));
	gpVGuiLocalize->AddFile("resource/valve_%language%.txt", "GAME");

	g_pFileSystem->CreateDirHierarchy("cfg", "DEFAULT_WRITE_PATH");

	//if(1)
	{
		engineFuncs->pfnAddCommand("_setlanguage", SetLanguage_f);
		engineFuncs->pfnAddCommand("_dump_fonttexture", DumpFontTexture_f);
	};
*/
};

void CBaseUI::Shutdown()
{
	if(gpGameUI)
	{
		gpGameUI->Shutdown();
		gpGameUI = nullptr;
	};
	
	UnloadGameUIModule();
};

int CBaseUI::Key_Event(int down, int keynum, const char *pszCurrentBinding)
{
	// TODO
	
	//ClientDLL_Key_Event(down, keynum, pszCurrentBinding); // TODO: ????????????????????
	
	return 0;
};

void CBaseUI::CallEngineSurfaceProc(void *hwnd, unsigned int msg, unsigned int wparam, long lparam)
{
	// TODO
};

void CBaseUI::Paint(int x, int y, int right, int bottom)
{
	// TODO
};

void CBaseUI::HideGameUI()
{
	gpGameUI->Hide();
};

void CBaseUI::ActivateGameUI()
{
	gpGameUI->SetActive(true);
};

bool CBaseUI::IsGameUIVisible()
{
	return gpGameUI->IsActive();
};

void CBaseUI::HideConsole()
{
	if(gpGameConsole)
		gpGameConsole->SetActive(false);
};

void CBaseUI::ShowConsole()
{
	if(gpGameConsole)
		gpGameConsole->SetActive(true);
	
	//gpGameUI->ActivateGameUI(); // to actually bring it to the screen
};